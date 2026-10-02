# T1: kernel-candidate objects linked by the target ld at __TEXT 0x100000
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -nostdinc -c src/c_codegen.c -o stage/c_codegen.o
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -nostdinc -c src/c_layout.c -o stage/c_layout.o
RUN /bin/cc -arch i386 -static -traditional-cpp -fwritable-strings -fno-common -O3 -nostdinc -c src/ext.c -o stage/ext.o
RUN /bin/cc -arch i386 -static -c src/asm_probe.s -o stage/asm_probe.o
RUN /bin/cc -arch i386 -c src/asm_reloc.s -o stage/asm_reloc.o
RUN /bin/ld -static -e _kr_leaf -segaddr __TEXT 0x100000 -o stage/t1img stage/c_codegen.o stage/c_layout.o stage/ext.o stage/asm_probe.o stage/asm_reloc.o
EXPECT c_codegen.o
EXPECT c_layout.o
EXPECT ext.o
EXPECT asm_probe.o
EXPECT asm_reloc.o
EXPECT t1img
