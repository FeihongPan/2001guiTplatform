#include "zoomselector.h"

#include <QComboBox>
#include <QLineEdit>
#include <QToolButton>
#include <QHBoxLayout>

const qreal c_zoomMultiplier = sqrt(2.0);
const qreal c_minZoomFactor = 0.1;
const qreal c_maxZoomFactor = 5.0;

ZoomSelector::ZoomSelector(QWidget *parent)
    : QWidget(parent)
    , m_nItemCount(0)
    , m_pComboBox(new QComboBox)
    , m_pZoomInBtn(new QToolButton)
    , m_pZoomOutBtn(new QToolButton)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    QFont font = QFont("HarmonyOS Sans",12);

    m_pComboBox->setEditable(true);
    m_pComboBox->setMinimumSize(100,30);
    m_pComboBox->addItem(QLatin1String("Fit Width"));
    m_pComboBox->addItem(QLatin1String("Fit Page"));
    m_pComboBox->addItem(QLatin1String("12%"));
    m_pComboBox->addItem(QLatin1String("25%"));
    m_pComboBox->addItem(QLatin1String("33%"));
    m_pComboBox->addItem(QLatin1String("50%"));
    m_pComboBox->addItem(QLatin1String("66%"));
    m_pComboBox->addItem(QLatin1String("75%"));
    m_pComboBox->addItem(QLatin1String("100%"));
    m_pComboBox->addItem(QLatin1String("125%"));
    m_pComboBox->addItem(QLatin1String("150%"));
    m_pComboBox->addItem(QLatin1String("200%"));
    m_pComboBox->addItem(QLatin1String("400%"));
    m_nItemCount = m_pComboBox->count();
    m_pComboBox->setFont(font);

    m_pZoomInBtn = new QToolButton(this);
    m_pZoomInBtn->setText("-");
    m_pZoomInBtn->setMinimumSize(30,30);
    m_pZoomInBtn->setFont(font);

    m_pZoomOutBtn = new QToolButton(this);
    m_pZoomOutBtn->setText("+");
    m_pZoomOutBtn->setMinimumSize(30,30);
    m_pZoomOutBtn->setFont(font);

    layout->addWidget(m_pZoomInBtn);
    layout->addWidget(m_pComboBox);
    layout->addWidget(m_pZoomOutBtn);

    connect(m_pComboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentTextChanged), this, &ZoomSelector::onCurrentTextChanged);

    connect(m_pZoomInBtn, &QToolButton::clicked, this, [this]()
    {
        onCurrentTextChanged(QString::number(string2zoomFactor(m_pComboBox->currentText()) / c_zoomMultiplier * 100));
    });

    connect(m_pZoomOutBtn, &QToolButton::clicked, this, [this]()
    {
        onCurrentTextChanged(QString::number(string2zoomFactor(m_pComboBox->currentText()) * c_zoomMultiplier * 100));
    });
}

void ZoomSelector::reset()
{
    onCurrentTextChanged("100%");
}

void ZoomSelector::onCurrentTextChanged(const QString &text)
{
    m_pComboBox->blockSignals(true);
    if (text == QLatin1String("Fit Width"))
    {
        emit zoomModeChanged(QPdfView::FitToWidth);
    }
    else if (text == QLatin1String("Fit Page"))
    {
        emit zoomModeChanged(QPdfView::FitInView);
    }
    else
    {
        while(m_nItemCount < m_pComboBox->count())
        {
            m_pComboBox->removeItem(m_nItemCount);
        }
        auto zoomFactor = string2zoomFactor(text);
        m_pZoomInBtn->setEnabled(zoomFactor > c_minZoomFactor);
        m_pZoomOutBtn->setEnabled(zoomFactor < c_maxZoomFactor);
        m_pComboBox->setCurrentText(QString::number(ceil(zoomFactor * 100)) + QLatin1String("%"));
        emit zoomModeChanged(QPdfView::CustomZoom);
        emit zoomFactorChanged(zoomFactor);
    }
    m_pComboBox->blockSignals(false);
}

qreal ZoomSelector::string2zoomFactor(const QString &str)
{
    qreal factor = 1.0;

    QString withoutPercent(str);
    withoutPercent.remove(QLatin1Char('%'));

    bool ok = false;
    const int zoomLevel = withoutPercent.toDouble(&ok);
    if (ok)
    {
        factor = zoomLevel / 100.0;
    }

    return qBound(c_minZoomFactor, factor, c_maxZoomFactor);
}
