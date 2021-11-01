printf "building..."
cd lib
for f in *.c; do gcc -c $f -o $f.o; done
mv *.o ../transpiler
cd ../transpiler
for f in *.c; do gcc -I../lib -c $f -o $f.o; done
gcc *.o -o ../jsfuck
rm *.o
cd ..
printf " done\n"