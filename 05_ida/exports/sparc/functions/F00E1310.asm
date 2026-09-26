F00E1310: 9de3bf98                 save    %sp, -0x68, %sp
F00E1314: b2067fff                 inc     -1, %i1
F00E1318: 80a67fff                 cmp     %i1, -1
F00E131C: 02800008                 be      loc_F00E133C
F00E1320: b4102000                 mov     0, %i2
F00E1324: b2067fff                 inc     -1, %i1
F00E1328: c4160000                 lduh    [%i0], %g2
F00E132C: 80a67fff                 cmp     %i1, -1
F00E1330: b4068002                 add     %i2, %g2, %i2
F00E1334: 12bffffc                 bne     loc_F00E1324
F00E1338: b0062002                 inc     2, %i0
F00E133C: 8536a010                 srl     %i2, 16, %g2
F00E1340: 0700003fb010e3ff         set     0xFFFF, %i0
F00E1348: 860e8018                 and     %i2, %i0, %g3
F00E134C: 84008003                 add     %g2, %g3, %g2
F00E1350: 80a08018                 cmp     %g2, %i0
F00E1354: 34800002                 bg,a    loc_F00E135C
F00E1358: 84208018                 sub     %g2, %i0, %g2
F00E135C: b128a010                 sll     %g2, 16, %i0
F00E1360: b1362010                 srl     %i0, 16, %i0
F00E1364: 81c7e008                 ret
F00E1368: 81e80000                 restore
