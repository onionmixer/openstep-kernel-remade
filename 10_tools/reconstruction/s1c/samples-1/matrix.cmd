# S1-C option matrix: 19 sets x 13 sample files (plan 13/13.1)
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/yeartoday.c -o stage/s00__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/hexdectodec.c -o stage/s00__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/dectohexdec.c -o stage/s00__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/locc.c -o stage/s00__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/skpc.c -o stage/s00__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/strcpy.c -o stage/s00__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/strcmp.c -o stage/s00__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/timevaladd.c -o stage/s00__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/timevalsub.c -o stage/s00__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/timevalfix.c -o stage/s00__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc -c src/kern_time_group.c -o stage/s00__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -c src/byte_swap_shorts.c -o stage/s00__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -c src/byte_swap_ints.c -o stage/s00__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/yeartoday.c -o stage/s01__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/hexdectodec.c -o stage/s01__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/dectohexdec.c -o stage/s01__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/locc.c -o stage/s01__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/skpc.c -o stage/s01__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/strcpy.c -o stage/s01__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/strcmp.c -o stage/s01__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/timevaladd.c -o stage/s01__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/timevalsub.c -o stage/s01__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/timevalfix.c -o stage/s01__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -nostdinc -c src/kern_time_group.c -o stage/s01__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -c src/byte_swap_shorts.c -o stage/s01__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -c src/byte_swap_ints.c -o stage/s01__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/yeartoday.c -o stage/s02__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/hexdectodec.c -o stage/s02__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/dectohexdec.c -o stage/s02__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/locc.c -o stage/s02__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/skpc.c -o stage/s02__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/strcpy.c -o stage/s02__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/strcmp.c -o stage/s02__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/timevaladd.c -o stage/s02__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/timevalsub.c -o stage/s02__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/timevalfix.c -o stage/s02__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -nostdinc -c src/kern_time_group.c -o stage/s02__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -c src/byte_swap_shorts.c -o stage/s02__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -mno-486 -c src/byte_swap_ints.c -o stage/s02__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/yeartoday.c -o stage/s03__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/hexdectodec.c -o stage/s03__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/dectohexdec.c -o stage/s03__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/locc.c -o stage/s03__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/skpc.c -o stage/s03__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/strcpy.c -o stage/s03__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/strcmp.c -o stage/s03__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/timevaladd.c -o stage/s03__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/timevalsub.c -o stage/s03__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/timevalfix.c -o stage/s03__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -nostdinc -c src/kern_time_group.c -o stage/s03__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -c src/byte_swap_shorts.c -o stage/s03__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -c src/byte_swap_ints.c -o stage/s03__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/yeartoday.c -o stage/s04__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/hexdectodec.c -o stage/s04__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/dectohexdec.c -o stage/s04__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/locc.c -o stage/s04__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/skpc.c -o stage/s04__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/strcpy.c -o stage/s04__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/strcmp.c -o stage/s04__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/timevaladd.c -o stage/s04__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/timevalsub.c -o stage/s04__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/timevalfix.c -o stage/s04__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -nostdinc -c src/kern_time_group.c -o stage/s04__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -c src/byte_swap_shorts.c -o stage/s04__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O -fomit-frame-pointer -mno-486 -c src/byte_swap_ints.c -o stage/s04__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/yeartoday.c -o stage/s05__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/hexdectodec.c -o stage/s05__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/dectohexdec.c -o stage/s05__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/locc.c -o stage/s05__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/skpc.c -o stage/s05__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/strcpy.c -o stage/s05__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/strcmp.c -o stage/s05__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/timevaladd.c -o stage/s05__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/timevalsub.c -o stage/s05__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/timevalfix.c -o stage/s05__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -c src/kern_time_group.c -o stage/s05__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -c src/byte_swap_shorts.c -o stage/s05__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -c src/byte_swap_ints.c -o stage/s05__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/yeartoday.c -o stage/s06__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/hexdectodec.c -o stage/s06__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/dectohexdec.c -o stage/s06__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/locc.c -o stage/s06__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/skpc.c -o stage/s06__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/strcpy.c -o stage/s06__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/strcmp.c -o stage/s06__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/timevaladd.c -o stage/s06__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/timevalsub.c -o stage/s06__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/timevalfix.c -o stage/s06__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -nostdinc -c src/kern_time_group.c -o stage/s06__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -c src/byte_swap_shorts.c -o stage/s06__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -mno-486 -c src/byte_swap_ints.c -o stage/s06__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/yeartoday.c -o stage/s07__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/hexdectodec.c -o stage/s07__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/dectohexdec.c -o stage/s07__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/locc.c -o stage/s07__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/skpc.c -o stage/s07__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/strcpy.c -o stage/s07__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/strcmp.c -o stage/s07__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/timevaladd.c -o stage/s07__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/timevalsub.c -o stage/s07__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/timevalfix.c -o stage/s07__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -nostdinc -c src/kern_time_group.c -o stage/s07__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -c src/byte_swap_shorts.c -o stage/s07__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -c src/byte_swap_ints.c -o stage/s07__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/yeartoday.c -o stage/s08__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/hexdectodec.c -o stage/s08__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/dectohexdec.c -o stage/s08__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/locc.c -o stage/s08__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/skpc.c -o stage/s08__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/strcpy.c -o stage/s08__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/strcmp.c -o stage/s08__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevaladd.c -o stage/s08__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevalsub.c -o stage/s08__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevalfix.c -o stage/s08__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -nostdinc -c src/kern_time_group.c -o stage/s08__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -c src/byte_swap_shorts.c -o stage/s08__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -fomit-frame-pointer -mno-486 -c src/byte_swap_ints.c -o stage/s08__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/yeartoday.c -o stage/s09__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/hexdectodec.c -o stage/s09__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/dectohexdec.c -o stage/s09__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/locc.c -o stage/s09__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/skpc.c -o stage/s09__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/strcpy.c -o stage/s09__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/strcmp.c -o stage/s09__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/timevaladd.c -o stage/s09__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/timevalsub.c -o stage/s09__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/timevalfix.c -o stage/s09__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -nostdinc -c src/kern_time_group.c -o stage/s09__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -c src/byte_swap_shorts.c -o stage/s09__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -c src/byte_swap_ints.c -o stage/s09__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/yeartoday.c -o stage/s10__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/hexdectodec.c -o stage/s10__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/dectohexdec.c -o stage/s10__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/locc.c -o stage/s10__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/skpc.c -o stage/s10__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/strcpy.c -o stage/s10__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/strcmp.c -o stage/s10__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/timevaladd.c -o stage/s10__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/timevalsub.c -o stage/s10__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/timevalfix.c -o stage/s10__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -nostdinc -c src/kern_time_group.c -o stage/s10__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -c src/byte_swap_shorts.c -o stage/s10__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -mno-486 -c src/byte_swap_ints.c -o stage/s10__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/yeartoday.c -o stage/s11__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/hexdectodec.c -o stage/s11__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/dectohexdec.c -o stage/s11__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/locc.c -o stage/s11__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/skpc.c -o stage/s11__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/strcpy.c -o stage/s11__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/strcmp.c -o stage/s11__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/timevaladd.c -o stage/s11__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/timevalsub.c -o stage/s11__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/timevalfix.c -o stage/s11__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -nostdinc -c src/kern_time_group.c -o stage/s11__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -c src/byte_swap_shorts.c -o stage/s11__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -c src/byte_swap_ints.c -o stage/s11__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/yeartoday.c -o stage/s12__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/hexdectodec.c -o stage/s12__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/dectohexdec.c -o stage/s12__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/locc.c -o stage/s12__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/skpc.c -o stage/s12__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/strcpy.c -o stage/s12__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/strcmp.c -o stage/s12__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevaladd.c -o stage/s12__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevalsub.c -o stage/s12__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevalfix.c -o stage/s12__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -nostdinc -c src/kern_time_group.c -o stage/s12__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -c src/byte_swap_shorts.c -o stage/s12__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O3 -fomit-frame-pointer -mno-486 -c src/byte_swap_ints.c -o stage/s12__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/yeartoday.c -o stage/s13__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/hexdectodec.c -o stage/s13__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/dectohexdec.c -o stage/s13__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/locc.c -o stage/s13__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/skpc.c -o stage/s13__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/strcpy.c -o stage/s13__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/strcmp.c -o stage/s13__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/timevaladd.c -o stage/s13__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/timevalsub.c -o stage/s13__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/timevalfix.c -o stage/s13__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -nostdinc -c src/kern_time_group.c -o stage/s13__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -c src/byte_swap_shorts.c -o stage/s13__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -c src/byte_swap_ints.c -o stage/s13__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/yeartoday.c -o stage/s14__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/hexdectodec.c -o stage/s14__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/dectohexdec.c -o stage/s14__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/locc.c -o stage/s14__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/skpc.c -o stage/s14__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/strcpy.c -o stage/s14__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/strcmp.c -o stage/s14__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/timevaladd.c -o stage/s14__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/timevalsub.c -o stage/s14__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/timevalfix.c -o stage/s14__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -nostdinc -c src/kern_time_group.c -o stage/s14__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -c src/byte_swap_shorts.c -o stage/s14__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -mno-486 -c src/byte_swap_ints.c -o stage/s14__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/yeartoday.c -o stage/s15__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/hexdectodec.c -o stage/s15__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/dectohexdec.c -o stage/s15__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/locc.c -o stage/s15__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/skpc.c -o stage/s15__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/strcpy.c -o stage/s15__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/strcmp.c -o stage/s15__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/timevaladd.c -o stage/s15__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/timevalsub.c -o stage/s15__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/timevalfix.c -o stage/s15__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -nostdinc -c src/kern_time_group.c -o stage/s15__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -c src/byte_swap_shorts.c -o stage/s15__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -c src/byte_swap_ints.c -o stage/s15__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/yeartoday.c -o stage/s16__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/hexdectodec.c -o stage/s16__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/dectohexdec.c -o stage/s16__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/locc.c -o stage/s16__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/skpc.c -o stage/s16__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/strcpy.c -o stage/s16__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/strcmp.c -o stage/s16__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevaladd.c -o stage/s16__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevalsub.c -o stage/s16__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/timevalfix.c -o stage/s16__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -nostdinc -c src/kern_time_group.c -o stage/s16__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -c src/byte_swap_shorts.c -o stage/s16__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -fomit-frame-pointer -mno-486 -c src/byte_swap_ints.c -o stage/s16__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/yeartoday.c -o stage/s17__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/hexdectodec.c -o stage/s17__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/dectohexdec.c -o stage/s17__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/locc.c -o stage/s17__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/skpc.c -o stage/s17__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/strcpy.c -o stage/s17__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/strcmp.c -o stage/s17__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/timevaladd.c -o stage/s17__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/timevalsub.c -o stage/s17__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/timevalfix.c -o stage/s17__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -nostdinc -c src/kern_time_group.c -o stage/s17__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -c src/byte_swap_shorts.c -o stage/s17__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -c src/byte_swap_ints.c -o stage/s17__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/yeartoday.c -o stage/s18__yeartoday.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/hexdectodec.c -o stage/s18__hexdectodec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/dectohexdec.c -o stage/s18__dectohexdec.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/locc.c -o stage/s18__locc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/skpc.c -o stage/s18__skpc.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/strcpy.c -o stage/s18__strcpy.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/strcmp.c -o stage/s18__strcmp.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/timevaladd.c -o stage/s18__timevaladd.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/timevalsub.c -o stage/s18__timevalsub.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/timevalfix.c -o stage/s18__timevalfix.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -nostdinc -c src/kern_time_group.c -o stage/s18__kern_time_group.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -c src/byte_swap_shorts.c -o stage/s18__byte_swap_shorts.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O4 -funroll-all-loops -fomit-frame-pointer -c src/byte_swap_ints.c -o stage/s18__byte_swap_ints.o
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/yeartoday.c -o stage/E__yeartoday.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/hexdectodec.c -o stage/E__hexdectodec.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/dectohexdec.c -o stage/E__dectohexdec.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/locc.c -o stage/E__locc.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/skpc.c -o stage/E__skpc.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/strcpy.c -o stage/E__strcpy.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/strcmp.c -o stage/E__strcmp.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/timevaladd.c -o stage/E__timevaladd.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/timevalsub.c -o stage/E__timevalsub.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/timevalfix.c -o stage/E__timevalfix.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -nostdinc -E src/kern_time_group.c -o stage/E__kern_time_group.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -E src/byte_swap_shorts.c -o stage/E__byte_swap_shorts.i
RUN /bin/cc -arch i386 -static -fno-common -fwritable-strings -traditional-cpp -O2 -E src/byte_swap_ints.c -o stage/E__byte_swap_ints.i
EXPECT s00__yeartoday.o
EXPECT s00__hexdectodec.o
EXPECT s00__dectohexdec.o
EXPECT s00__locc.o
EXPECT s00__skpc.o
EXPECT s00__strcpy.o
EXPECT s00__strcmp.o
EXPECT s00__timevaladd.o
EXPECT s00__timevalsub.o
EXPECT s00__timevalfix.o
EXPECT s00__kern_time_group.o
EXPECT s00__byte_swap_shorts.o
EXPECT s00__byte_swap_ints.o
EXPECT s01__yeartoday.o
EXPECT s01__hexdectodec.o
EXPECT s01__dectohexdec.o
EXPECT s01__locc.o
EXPECT s01__skpc.o
EXPECT s01__strcpy.o
EXPECT s01__strcmp.o
EXPECT s01__timevaladd.o
EXPECT s01__timevalsub.o
EXPECT s01__timevalfix.o
EXPECT s01__kern_time_group.o
EXPECT s01__byte_swap_shorts.o
EXPECT s01__byte_swap_ints.o
EXPECT s02__yeartoday.o
EXPECT s02__hexdectodec.o
EXPECT s02__dectohexdec.o
EXPECT s02__locc.o
EXPECT s02__skpc.o
EXPECT s02__strcpy.o
EXPECT s02__strcmp.o
EXPECT s02__timevaladd.o
EXPECT s02__timevalsub.o
EXPECT s02__timevalfix.o
EXPECT s02__kern_time_group.o
EXPECT s02__byte_swap_shorts.o
EXPECT s02__byte_swap_ints.o
EXPECT s03__yeartoday.o
EXPECT s03__hexdectodec.o
EXPECT s03__dectohexdec.o
EXPECT s03__locc.o
EXPECT s03__skpc.o
EXPECT s03__strcpy.o
EXPECT s03__strcmp.o
EXPECT s03__timevaladd.o
EXPECT s03__timevalsub.o
EXPECT s03__timevalfix.o
EXPECT s03__kern_time_group.o
EXPECT s03__byte_swap_shorts.o
EXPECT s03__byte_swap_ints.o
EXPECT s04__yeartoday.o
EXPECT s04__hexdectodec.o
EXPECT s04__dectohexdec.o
EXPECT s04__locc.o
EXPECT s04__skpc.o
EXPECT s04__strcpy.o
EXPECT s04__strcmp.o
EXPECT s04__timevaladd.o
EXPECT s04__timevalsub.o
EXPECT s04__timevalfix.o
EXPECT s04__kern_time_group.o
EXPECT s04__byte_swap_shorts.o
EXPECT s04__byte_swap_ints.o
EXPECT s05__yeartoday.o
EXPECT s05__hexdectodec.o
EXPECT s05__dectohexdec.o
EXPECT s05__locc.o
EXPECT s05__skpc.o
EXPECT s05__strcpy.o
EXPECT s05__strcmp.o
EXPECT s05__timevaladd.o
EXPECT s05__timevalsub.o
EXPECT s05__timevalfix.o
EXPECT s05__kern_time_group.o
EXPECT s05__byte_swap_shorts.o
EXPECT s05__byte_swap_ints.o
EXPECT s06__yeartoday.o
EXPECT s06__hexdectodec.o
EXPECT s06__dectohexdec.o
EXPECT s06__locc.o
EXPECT s06__skpc.o
EXPECT s06__strcpy.o
EXPECT s06__strcmp.o
EXPECT s06__timevaladd.o
EXPECT s06__timevalsub.o
EXPECT s06__timevalfix.o
EXPECT s06__kern_time_group.o
EXPECT s06__byte_swap_shorts.o
EXPECT s06__byte_swap_ints.o
EXPECT s07__yeartoday.o
EXPECT s07__hexdectodec.o
EXPECT s07__dectohexdec.o
EXPECT s07__locc.o
EXPECT s07__skpc.o
EXPECT s07__strcpy.o
EXPECT s07__strcmp.o
EXPECT s07__timevaladd.o
EXPECT s07__timevalsub.o
EXPECT s07__timevalfix.o
EXPECT s07__kern_time_group.o
EXPECT s07__byte_swap_shorts.o
EXPECT s07__byte_swap_ints.o
EXPECT s08__yeartoday.o
EXPECT s08__hexdectodec.o
EXPECT s08__dectohexdec.o
EXPECT s08__locc.o
EXPECT s08__skpc.o
EXPECT s08__strcpy.o
EXPECT s08__strcmp.o
EXPECT s08__timevaladd.o
EXPECT s08__timevalsub.o
EXPECT s08__timevalfix.o
EXPECT s08__kern_time_group.o
EXPECT s08__byte_swap_shorts.o
EXPECT s08__byte_swap_ints.o
EXPECT s09__yeartoday.o
EXPECT s09__hexdectodec.o
EXPECT s09__dectohexdec.o
EXPECT s09__locc.o
EXPECT s09__skpc.o
EXPECT s09__strcpy.o
EXPECT s09__strcmp.o
EXPECT s09__timevaladd.o
EXPECT s09__timevalsub.o
EXPECT s09__timevalfix.o
EXPECT s09__kern_time_group.o
EXPECT s09__byte_swap_shorts.o
EXPECT s09__byte_swap_ints.o
EXPECT s10__yeartoday.o
EXPECT s10__hexdectodec.o
EXPECT s10__dectohexdec.o
EXPECT s10__locc.o
EXPECT s10__skpc.o
EXPECT s10__strcpy.o
EXPECT s10__strcmp.o
EXPECT s10__timevaladd.o
EXPECT s10__timevalsub.o
EXPECT s10__timevalfix.o
EXPECT s10__kern_time_group.o
EXPECT s10__byte_swap_shorts.o
EXPECT s10__byte_swap_ints.o
EXPECT s11__yeartoday.o
EXPECT s11__hexdectodec.o
EXPECT s11__dectohexdec.o
EXPECT s11__locc.o
EXPECT s11__skpc.o
EXPECT s11__strcpy.o
EXPECT s11__strcmp.o
EXPECT s11__timevaladd.o
EXPECT s11__timevalsub.o
EXPECT s11__timevalfix.o
EXPECT s11__kern_time_group.o
EXPECT s11__byte_swap_shorts.o
EXPECT s11__byte_swap_ints.o
EXPECT s12__yeartoday.o
EXPECT s12__hexdectodec.o
EXPECT s12__dectohexdec.o
EXPECT s12__locc.o
EXPECT s12__skpc.o
EXPECT s12__strcpy.o
EXPECT s12__strcmp.o
EXPECT s12__timevaladd.o
EXPECT s12__timevalsub.o
EXPECT s12__timevalfix.o
EXPECT s12__kern_time_group.o
EXPECT s12__byte_swap_shorts.o
EXPECT s12__byte_swap_ints.o
EXPECT s13__yeartoday.o
EXPECT s13__hexdectodec.o
EXPECT s13__dectohexdec.o
EXPECT s13__locc.o
EXPECT s13__skpc.o
EXPECT s13__strcpy.o
EXPECT s13__strcmp.o
EXPECT s13__timevaladd.o
EXPECT s13__timevalsub.o
EXPECT s13__timevalfix.o
EXPECT s13__kern_time_group.o
EXPECT s13__byte_swap_shorts.o
EXPECT s13__byte_swap_ints.o
EXPECT s14__yeartoday.o
EXPECT s14__hexdectodec.o
EXPECT s14__dectohexdec.o
EXPECT s14__locc.o
EXPECT s14__skpc.o
EXPECT s14__strcpy.o
EXPECT s14__strcmp.o
EXPECT s14__timevaladd.o
EXPECT s14__timevalsub.o
EXPECT s14__timevalfix.o
EXPECT s14__kern_time_group.o
EXPECT s14__byte_swap_shorts.o
EXPECT s14__byte_swap_ints.o
EXPECT s15__yeartoday.o
EXPECT s15__hexdectodec.o
EXPECT s15__dectohexdec.o
EXPECT s15__locc.o
EXPECT s15__skpc.o
EXPECT s15__strcpy.o
EXPECT s15__strcmp.o
EXPECT s15__timevaladd.o
EXPECT s15__timevalsub.o
EXPECT s15__timevalfix.o
EXPECT s15__kern_time_group.o
EXPECT s15__byte_swap_shorts.o
EXPECT s15__byte_swap_ints.o
EXPECT s16__yeartoday.o
EXPECT s16__hexdectodec.o
EXPECT s16__dectohexdec.o
EXPECT s16__locc.o
EXPECT s16__skpc.o
EXPECT s16__strcpy.o
EXPECT s16__strcmp.o
EXPECT s16__timevaladd.o
EXPECT s16__timevalsub.o
EXPECT s16__timevalfix.o
EXPECT s16__kern_time_group.o
EXPECT s16__byte_swap_shorts.o
EXPECT s16__byte_swap_ints.o
EXPECT s17__yeartoday.o
EXPECT s17__hexdectodec.o
EXPECT s17__dectohexdec.o
EXPECT s17__locc.o
EXPECT s17__skpc.o
EXPECT s17__strcpy.o
EXPECT s17__strcmp.o
EXPECT s17__timevaladd.o
EXPECT s17__timevalsub.o
EXPECT s17__timevalfix.o
EXPECT s17__kern_time_group.o
EXPECT s17__byte_swap_shorts.o
EXPECT s17__byte_swap_ints.o
EXPECT s18__yeartoday.o
EXPECT s18__hexdectodec.o
EXPECT s18__dectohexdec.o
EXPECT s18__locc.o
EXPECT s18__skpc.o
EXPECT s18__strcpy.o
EXPECT s18__strcmp.o
EXPECT s18__timevaladd.o
EXPECT s18__timevalsub.o
EXPECT s18__timevalfix.o
EXPECT s18__kern_time_group.o
EXPECT s18__byte_swap_shorts.o
EXPECT s18__byte_swap_ints.o
EXPECT E__yeartoday.i
EXPECT E__hexdectodec.i
EXPECT E__dectohexdec.i
EXPECT E__locc.i
EXPECT E__skpc.i
EXPECT E__strcpy.i
EXPECT E__strcmp.i
EXPECT E__timevaladd.i
EXPECT E__timevalsub.i
EXPECT E__timevalfix.i
EXPECT E__kern_time_group.i
EXPECT E__byte_swap_shorts.i
EXPECT E__byte_swap_ints.i
