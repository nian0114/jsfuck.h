printf "building..."
cd lib/
for f in *.c; do gcc -c -O3 $f -o $f.o; done
ar rcs *.o -o ../libjsfuck.a
rm *.o
cd ..
printf " done\n"
