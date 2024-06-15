#ifndef UTILS_H
#define UTILS_H

#include "CommonLib_global.h"

#include <QMutex>
#include <QTimer>
#include <QObject>
#include <QEventLoop>

#define WAIT(asender, signal, ms, result)      do { \
        static QEventLoop eventloop; \
        static QTimer timer; \
        timer.setInterval(ms); \
        \
        QObject::connect(asender, signal, &eventloop, &QEventLoop::quit); \
        QObject::connect(&timer, &QTimer::timeout, &eventloop, [=](){ \
            timer.stop();\
            eventloop.quit(); \
        }); \
        \
        timer.start(); \
        eventloop.exec(); \
        \
        result = false; \
        if (timer.isActive() == true){ \
            timer.stop(); \
            result = true; \
        } \
        QObject::disconnect(asender, signal, &eventloop, &QEventLoop::quit); \
    } while(0);


class COMMONLIB_EXPORT Utils
{
public:
    template <class T>
    static T *getInstance(T **self)
    {
        if(*self == NULL)
        {
            static QMutex mutex;
            QMutexLocker locker(&mutex);
            if(*self == NULL)
            {
                *self = new T;
            }
        }
        return *self;
    }

    static uint16_t getCrc(const QByteArray &data)
    {
        uint16_t crc = 0xffff;
        for(int i = 0; i < data.length(); i++)
        {
            // step 1
            crc = crc ^ (unsigned char)data.at(i);
            // step 2
            for(int j = 0; j < 8; j++)
            {
                // step 3
                uint16_t temp = crc & 0x01;
                crc = crc >> 1;
                if(temp == 1)
                {
                    crc = crc ^ 0xA001;
                }
            }
        }
        return  crc;
    }

    static uint16_t toHex(QByteArray d)
    {
        uint16_t num = 0;
        uint16_t acc = 16 * 16 * 16;

        for (int i = 0; i < 4; i++)
        {
            uint16_t m = 0;

            if (d[i] >= 'a' && d[i] <= 'f')
            {
                m = d[i] - 'a' + 10;
            }
            else if (d[i] >= 'A' && d[i] <= 'F')
            {
                m = d[i] - 'A' + 10;
            }
            else if (d[i] >= '0' && d[i] <= '9')
            {
                m = d[i] - '0';
            }

            num += acc * m;
            acc /= 16;
        }

        return num;
    }

    static bool Wait(QObject *obj, const char *asignal, uint32_t ms)
    {
        // Use EventLoop to wait for the data to be sent
        static QEventLoop eventloop;
        static QTimer timer;
        timer.setInterval(ms);

        QObject::connect(obj, asignal, &eventloop, SLOT(quit()));
        QObject::connect(&timer, &QTimer::timeout, &eventloop, [ = ]()
        {
            timer.stop();
            eventloop.quit();
        });
        // Starting the Timeout Timer
        timer.start();
        eventloop.exec();

        bool result = false;
        if (timer.isActive() == true)
        {
            timer.stop();
            result = true;
        }
        QObject::disconnect(obj, asignal, &eventloop, SLOT(quit()));

        return result;
    }
};

#endif
