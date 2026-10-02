# S1-A probes, kernel candidate options: Darwin 0.1 conf/Makefile.i386 + MASTER.i386 -O3, minus -fpascal-strings (cc-744.13 cc1obj rejects it). A candidate only.
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -nostdinc -c src/c_layout.c -o stage/c_layout.o
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -nostdinc -c src/c_codegen.c -o stage/c_codegen.o
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -c src/objc_probe.m -o stage/objc_probe.o
RUN /bin/cc -arch i386 -static -c src/asm_probe.s -o stage/asm_probe.o
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -E src/objc_probe.m -o stage/objc_probe.i
RUN /usr/bin/mig -arch i386 -user stage/krprobeUser.c -server stage/krprobeServer.c -header stage/krprobe.h src/mig_probe.defs
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -c stage/krprobeUser.c -o stage/krprobeUser.o
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -c stage/krprobeServer.c -o stage/krprobeServer.o
EXPECT c_layout.o
EXPECT c_codegen.o
EXPECT objc_probe.o
EXPECT asm_probe.o
EXPECT objc_probe.i
EXPECT krprobe.h
EXPECT krprobeUser.o
EXPECT krprobeServer.o
