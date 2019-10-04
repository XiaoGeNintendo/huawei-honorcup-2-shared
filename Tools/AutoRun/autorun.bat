@echo off

call stress.bat layer0.exe 1200.txt
call layer.bat 1
call layer.bat 2
call layer.bat 3
call layer.bat 4
call layer.bat 5
call layer.bat 6

call stress.bat ExtraLayer.exe 1200.png

echo [AUTO RUN]All done! Task success!