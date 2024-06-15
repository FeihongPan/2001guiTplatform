@echo off & color 0E 
title Log Deleter Script

setlocal enabledelayedexpansion

set sentry=%1
echo !sentry!
echo "Log Deleter Script Start ......" > !sentry!

set folderToDelete=%~dp1
echo Log files greater than 100MB in !folderToDelete! being deleted periodically.
@echo.

set counter=0
set TIMER=60

:START
set INTERVAL=1
timeout /T !INTERVAL! /NOBREAK 

if not exist !sentry! (
	goto END
)

set /a counter+=1
if !timer! gtr !counter! (
    goto START
) else (
	set /a counter*=0
	goto DELETER
)

:DELETER
set /a Threshold=100*1024*1024
set factor=2 

cd /d !folderToDelete!
for /d %%f in (*) do (
    set logname=%%f
	echo Current Log=!logname!
	cd /d !folderToDelete!/!logname!
	set size=0, count=0
	for /r %%i in (*.) do (
	    set /a file=%%~zi
		set /a size+=file
		set /a count+=1
	)
	set d=Byte
	set total=!size!
    if !size! gtr 1024 set /a size/=1024&set d=KB
    if !size! gtr 1024 set /a size/=1024&set d=MB	
	echo Size of !folderToDelete!/%%f:!size!!d!  Total Files:!count!
    
	if !total! gtr !Threshold! (
	    rem Delete Alarm Logs
		if !logname!==Alarm (
		    echo Start to Delete Logs in !logname!
		    set /a tmp=logdir-2
			set /a cnt=tmp/factor
			echo alarm=!cnt!
			for /d %%i in (*.) do (
			    echo %%i will be deleted!
				rd /s /q %%i
				set /a cnt-=1
				if !cnt!==0 goto Released
			)
			
			:Released 
			echo Start to Delete Logs in !logname!/Released
			cd /d !folderToDelete!/!logname!/Released
			set alarmRelease=0
			for /d %%i in (*.) do (
				set /a alarmRelease+=1
			)
			set /a cntRelease=alarmRelease/factor
			for /d %%i in (*.) do (
			    echo %%i will be deleted!
				rd /s /q %%i
				set /a cntRelease-=1
				if !cntRelease!==0 goto Reported
			)
			
			:Reported
			echo Start to Delete Logs in !logname!/Reported
			cd /d !folderToDelete!/!logname!/Reported
			set alarmReport=0
			for /d %%i in (*.) do (
				rem echo %%i
				set /a alarmReport+=1
			)
			set /a cntReport=alarmReport/factor
			for /d %%i in (*.) do (
				rd /s /q %%i
				echo %%i deleted!
				set /a cntReport-=1
				if !cntReport!==0 goto Alarm
			)
			
			:Alarm 
			@echo. 
			
		) else (
			@echo.
		)
	
		rem Delete Communication Logs
		if !logname!==Communication (
			echo Start to Delete Logs in !logname!/Publish
			@echo.
			echo Start to Delete Logs in !logname!/Publish/AlarmManager
			cd /d !folderToDelete!/!logname!/Publish/AlarmManager
			set pubAlarmMgr=0
			for /d %%i in (*.) do (
				set /a pubAlarmMgr+=1
			)
			set /a cntPubAlarmMgr=pubAlarmMgr/factor
			for /d %%i in (*.) do (
				rd /s /q %%i
				echo %%i deleted!
				set /a cntPubAlarmMgr-=1
				if !cntPubAlarmMgr!==0 goto MachineStateController
			)
			
			:MachineStateController
			echo Start to Delete Logs in !logname!/Publish/MachineStateController
			cd /d !folderToDelete!/!logname!/Publish/MachineStateController
			set pubMSCtrl=0
			for /d %%i in (*.) do (
				set /a pubMSCtrl+=1
			)
			set /a cntPubMSCtrl=pubMSCtrl/factor
			for /d %%i in (*.) do (
				rd /s /q %%i
				echo %%i deleted!
				set /a cntPubMSCtrl-=1
				if !cntPubMSCtrl!==0 goto SGTCtrl
			)
			
			:SGTCtrl
			echo Start to Delete Logs in !logname!/Publish/SGTCtrl
			cd /d !folderToDelete!/!logname!/Publish/SGTCtrl
			set pubSGTCtrl=0
			for /d %%i in (*.) do (
				rem echo %%i
				set /a pubSGTCtrl+=1
			)
			set /a cntPubSGTCtrl=pubSGTCtrl/factor
			for /d %%i in (*.) do (
				rd /s /q %%i
				echo %%i deleted!
				set /a cntPubSGTCtrl-=1
				if !cntPubSGTCtrl!==0 goto Subscribe
			)
			
			:Subscribe
			echo Start to Delete Logs in !logname!/Subscribe
			cd  /d !folderToDelete!/!logname!/Subscribe
			for /d %%i in (*.) do (
				cd /d !folderToDelete!/!logname!/Subscribe/%%i
				set curSub=%%i
				set Subscribe=0
				for /d %%j in (*.) do (
					set /a Subscribe+=1
				)
				set /a cntSubscribe=Subscribe/factor
				for /d %%k in (*.) do (
				    if !cntSubscribe! gtr 0 (  
						rd /s /q %%k
						echo %%k deleted!
						set /a cntSubscribe-=1
					)
				)
				
				echo Delete Outdated Logs in !curSub! Completed!
				@echo.
			)
		) else (
			@echo.
		)
		
		rem Delete Debug Logs
		if !logname!==Debug (
			echo Start to Delete Logs in !logname!
			@echo.
			cd /d !folderToDelete!/!logname!
			set debug=0
			for /d %%i in (*.) do (
				set /a debug+=1
			)
			set /a cntDebug=debug/factor
			for /d %%i in (*.) do (
				if !cntDebug! gtr 0 (
					rd /s /q %%i
					echo %%i deleted!
					set /a cntDebug-=1
				)
			)
		) else (
			@echo.
		)
		
		rem Delete Exception Logs
		if !logname!==Exception (
			echo Start to Delete Logs in !logname!
			@echo.
			cd /d !folderToDelete!/!logname!
			set exception=0
			for /d %%i in (*.) do (
				set /a exception+=1
			)
			set /a cntException=exception/factor
			for /d %%i in (*.) do (
				if !cntException! gtr 0 (
					rd /s /q %%i
					echo %%i deleted!
					set /a cntException-=1
				)
			)
		) else (
			@echo.
		)
		
		rem Delete Process Logs
		if !logname!==Process (
			echo Start to Delete Logs in !logname!
			cd  /d !folderToDelete!/!logname!
			for /d %%i in (*.) do (
				cd /d !folderToDelete!/!logname!/%%i
				set Process=0
				for /d %%j in (*.) do (
					set /a Process+=1
				)
				set /a cntProcess=Process/factor
				for /d %%k in (*.) do (
					if !cntProcess! gtr 0 (
						rd /s /q %%k
						echo %%k deleted!
						set /a cntProcess-=1
					)
				)
			)
		) else (
			@echo.
		)
		set /a deleteFiles=count/factor
		echo !deleteFiles! Outdated Logs in !logname!/* Has been Deleted! 
	) else (
		@echo.
	)
)

goto START

:END
@echo.
echo End task and logdeleter.txt Deleted!
del /f !sentry!
exit
