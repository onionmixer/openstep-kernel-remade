# S1-A probes, default driver options (-dynamic -fPIC by default on this cc)
RUN /bin/cc -arch i386 -c src/c_layout.c -o stage/c_layout.o
RUN /bin/cc -arch i386 -c src/c_codegen.c -o stage/c_codegen.o
RUN /bin/cc -arch i386 -c src/objc_probe.m -o stage/objc_probe.o
RUN /bin/cc -arch i386 -c src/asm_probe.s -o stage/asm_probe.o
RUN /bin/cc -arch i386 -M src/c_layout.c
RUN /bin/cc -arch i386 -M src/objc_probe.m
EXPECT c_layout.o
EXPECT c_codegen.o
EXPECT objc_probe.o
EXPECT asm_probe.o
