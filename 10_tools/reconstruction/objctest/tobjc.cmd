# T-ObjC: two ObjC objects + runtime stand-ins, linked by the target ld
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -c src/objc_a.m -o stage/objc_a.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -c src/objc_b.m -o stage/objc_b.o
RUN /bin/cc -arch i386 -static -c src/rt_stub.s -o stage/rt_stub.o
RUN /bin/ld -static -e _objc_msgSend -segaddr __TEXT 0x100000 -o stage/tobjc stage/objc_a.o stage/objc_b.o stage/rt_stub.o
EXPECT objc_a.o
EXPECT objc_b.o
EXPECT rt_stub.o
EXPECT tobjc
