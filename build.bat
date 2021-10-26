@echo off
echo building...

for /f %%I in ('dir /s /b *.c') do gcc -c "%%~nxI" -o "%%~nxI.o"

ar rcs -o libjsfuck.a *.o
del /s /q *.o > nul
echo done