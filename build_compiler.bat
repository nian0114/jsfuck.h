@echo off
echo building...
cd lib
for /f %%I in ('dir /s /b *.c') do gcc -c "%%~nxI" -o "%%~nxI.o"
move *.o ..\compiler > nul
cd ..\compiler
for /f %%I in ('dir /s /b *.c') do gcc -I..\lib -c "%%~nxI" -o "%%~nxI.o"
gcc *.o -o ..\jsfuck.exe
del /s /q *.o > nul
cd ..
echo done