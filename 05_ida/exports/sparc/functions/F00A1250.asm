F00A1250: 9de3bf98                 save    %sp, -0x68, %sp
F00A1254: c6062014                 ld      [%i0+0x14], %g3
F00A1258: 80a0e000                 cmp     %g3, 0
F00A125C: 22800013                 be,a    locret_F00A12A8
F00A1260: b0103fff                 mov     -1, %i0
F00A1264: c400e008                 ld      [%g3+8], %g2
F00A1268: 80a08018                 cmp     %g2, %i0
F00A126C: 3280000f                 bne,a   locret_F00A12A8
F00A1270: b0103fff                 mov     -1, %i0
F00A1274: 053c04f7                 sethi   %hi(_context_table), %g2
F00A1278: c400a210                 ld      [%g2+%lo(_context_table)], %g2
F00A127C: 8420c002                 sub     %g3, %g2, %g2
F00A1280: b128a002                 sll     %g2, 2, %i0
F00A1284: b0060002                 add     %i0, %g2, %i0
F00A1288: 852e2004                 sll     %i0, 4, %g2
F00A128C: b0060002                 add     %i0, %g2, %i0
F00A1290: 852e2008                 sll     %i0, 8, %g2
F00A1294: b0060002                 add     %i0, %g2, %i0
F00A1298: 852e2010                 sll     %i0, 16, %g2
F00A129C: b0060002                 add     %i0, %g2, %i0
F00A12A0: b0200018                 neg     %i0
F00A12A4: b13e2002                 sra     %i0, 2, %i0
F00A12A8: 81c7e008                 ret
F00A12AC: 81e80000                 restore
