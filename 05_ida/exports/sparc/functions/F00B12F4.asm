F00B12F4: 9de3bf98                 save    %sp, -0x68, %sp
F00B12F8: 80a66000                 cmp     %i1, 0
F00B12FC: 22800024                 be,a    locret_F00B138C
F00B1300: b0103fff                 mov     -1, %i0
F00B1304: c4066020                 ld      [%i1+0x20], %g2
F00B1308: 80a0a000                 cmp     %g2, 0
F00B130C: 22800020                 be,a    locret_F00B138C
F00B1310: b0103fff                 mov     -1, %i0
F00B1314: f400a00c                 ld      [%g2+0xC], %i2
F00B1318: 80a6a000                 cmp     %i2, 0
F00B131C: 12800009                 bne     loc_F00B1340
F00B1320: 80a62062                 cmp     %i0, 0x62 ! 'b'
F00B1324: 1080001a                 ba      locret_F00B138C
F00B1328: b0103fff                 mov     -1, %i0
F00B132C: b12e2008                 sll     %i0, 8, %i0
F00B1330: b0160002                 bset    %g2, %i0
F00B1334: b12e2010                 sll     %i0, 16, %i0
F00B1338: 10800015                 ba      locret_F00B138C
F00B133C: b13e2010                 sra     %i0, 16, %i0
F00B1340: 02800012                 be      loc_F00B1388
F00B1344: 053c0472                 sethi   %hi(_cdevsw), %g2
F00B1348: 8610a1f0                 or      %g2, %lo(_cdevsw), %g3
F00B134C: 053c0474                 sethi   %hi(_nchrdev), %g2
F00B1350: c400a154                 ld      [%g2+%lo(_nchrdev)], %g2
F00B1354: b0102000                 mov     0, %i0
F00B1358: 80a60002                 cmp     %i0, %g2
F00B135C: 3680000c                 bge,a   locret_F00B138C
F00B1360: b0103fff                 mov     -1, %i0
F00B1364: b6100002                 mov     %g2, %i3
F00B1368: c400c000                 ld      [%g3], %g2
F00B136C: 80a0801a                 cmp     %g2, %i2
F00B1370: 22bfffef                 be,a    loc_F00B132C
F00B1374: c406602c                 ld      [%i1+0x2C], %g2
F00B1378: b0062001                 inc     %i0
F00B137C: 80a6001b                 cmp     %i0, %i3
F00B1380: 06bffffa                 bl      loc_F00B1368
F00B1384: 8600e02c                 inc     0x2C, %g3 ! ','
F00B1388: b0103fff                 mov     -1, %i0
F00B138C: 81c7e008                 ret
F00B1390: 81e80000                 restore
