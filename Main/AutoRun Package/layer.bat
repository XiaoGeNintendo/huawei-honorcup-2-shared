call stress.bat layer%1.exe
checkadj.exe value%1.out %2.png 
if %ERRORLEVEL% EQU 0 goto shit
echo [LAYER TEST]Successfully ran Layer %1
goto eof

:shit

echo [LAYER TEST]Layer%1 returned 0, break as intended
pause
exit

:eof