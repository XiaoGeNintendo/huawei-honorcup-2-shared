@echo off
if "%1"=="" goto sure

echo [AUTO RUN]Start running on picture #%1

call stress.bat layer0.exe %1.txt
call layer.bat 1 %1
call layer.bat 2 %1
call layer.bat 3 %1
call layer.bat 4 %1
call layer.bat 5 %1
call layer.bat 6 %1
call layer.bat 7 %1
call layer.bat 8 %1
call layer.bat 9 %1

call stress.bat ExtraLayer.exe %1.png

echo [AUTO RUN]All done! Task success!

pause
exit

:sure
echo [AUTO RUN]Hey, man! Are you sure you entered the picture No??
pause
exit