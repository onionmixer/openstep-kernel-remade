# option acceptance probe for S1-C
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -O4 -c src/t.c -o stage/t0.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -O2 -fomit-frame-pointer -c src/t.c -o stage/t1.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -O2 -m486 -c src/t.c -o stage/t2.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -O2 -mno-486 -c src/t.c -o stage/t3.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -O4 -funroll-all-loops -c src/t.c -o stage/t4.o
EXPECT t0.o
EXPECT t1.o
EXPECT t2.o
EXPECT t3.o
EXPECT t4.o
