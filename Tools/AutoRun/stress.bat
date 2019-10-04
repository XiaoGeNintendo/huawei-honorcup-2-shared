%1 %2
if %ERRORLEVEL% NEQ 0 goto shit
echo [STRESS TEST]Successfully Ran %1 with parameter %2
goto eof

:shit
echo [STRESS TEST]Unexpected Error Code: %ERRORLEVEL%
pause
exit

:eof