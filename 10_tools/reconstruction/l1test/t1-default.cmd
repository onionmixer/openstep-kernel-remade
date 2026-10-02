# T1b: default-option (-dynamic -fPIC, SECTDIFF/PAIR) objects linked statically by the target ld
RUN /bin/cc -arch i386 -c src/c_codegen.c -o stage/c_codegen.o
RUN /bin/cc -arch i386 -c src/ext.c -o stage/ext.o
RUN /bin/ld -static -e _kr_leaf -segaddr __TEXT 0x100000 -o stage/t1img stage/c_codegen.o stage/ext.o
EXPECT c_codegen.o
EXPECT ext.o
EXPECT t1img
