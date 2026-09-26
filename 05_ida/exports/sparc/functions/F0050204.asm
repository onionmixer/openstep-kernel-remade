F0050204: 9de3bf98                 save    %sp, -0x68, %sp
F0050208: d4062038                 ld      [%i0+0x38], %o2
F005020C: 80a2a002                 cmp     %o2, 2
F0050210: 22800015                 be,a    loc_F0050264
F0050214: 940ea003                 and     %i2, 3, %o2
F0050218: 14800007                 bg      loc_F0050234
F005021C: 80a2a004                 cmp     %o2, 4
F0050220: 80a2a001                 cmp     %o2, 1
F0050224: 2280001a                 be,a    loc_F005028C
F0050228: 900ea007                 and     %i2, 7, %o0
F005022C: 10800020                 ba      loc_F00502AC
F0050230: 113c043b                 sethi   -0xFEF1400, %o0
F0050234: 02800007                 be      loc_F0050250
F0050238: 80a2a008                 cmp     %o2, 8
F005023C: 3280001c                 bne,a   loc_F00502AC
F0050240: 113c043b                 sethi   -0xFEF1400, %o0
F0050244: d00e401a                 ldub    [%i1+%i2], %o0
F0050248: 1080000e                 ba      loc_F0050280
F005024C: 901a20ff                 btog    0xFF, %o0
F0050250: 940ea001                 and     %i2, 1, %o2
F0050254: 952aa002                 sll     %o2, 2, %o2
F0050258: 9210200f                 mov     0xF, %o1
F005025C: 10800005                 ba      loc_F0050270
F0050260: 913ea001                 sra     %i2, 1, %o0
F0050264: 952aa001                 sll     %o2, 1, %o2
F0050268: 92102003                 mov     3, %o1
F005026C: 913ea002                 sra     %i2, 2, %o0
F0050270: d00e4008                 ldub    [%i1+%o0], %o0
F0050274: 932a400a                 sll     %o1, %o2, %o1
F0050278: 901a20ff                 btog    0xFF, %o0
F005027C: 900a0009                 and     %o0, %o1, %o0
F0050280: 80a00008                 cmp     %g0, %o0
F0050284: 1080000d                 ba      locret_F00502B8
F0050288: b0603fff                 subc    %g0, -1, %i0
F005028C: 933ea003                 sra     %i2, 3, %o1
F0050290: d20e4009                 ldub    [%i1+%o1], %o1
F0050294: 912a8008                 sll     %o2, %o0, %o0! char *
F0050298: 921a60ff                 btog    0xFF, %o1
F005029C: 920a4008                 and     %o1, %o0, %o1
F00502A0: 80a00009                 cmp     %g0, %o1
F00502A4: 10800005                 ba      locret_F00502B8
F00502A8: b0603fff                 subc    %g0, -1, %i0
F00502AC: 7fff13b1                 call    _panic
F00502B0: 90122178                 bset    0x178, %o0
F00502B4: b0102000                 mov     0, %i0
F00502B8: 81c7e008                 ret
F00502BC: 81e80000                 restore
