F002F308: 9de3bf98                 save    %sp, -0x68, %sp
F002F30C: 053c04d9                 sethi   %hi(_in_ifaddr), %g2
F002F310: c600a070                 ld      [%g2+%lo(_in_ifaddr)], %g3
F002F314: 80a0e000                 cmp     %g3, 0
F002F318: 02800017                 be      loc_F002F374
F002F31C: f0060000                 ld      [%i0], %i0
F002F320: c400e020                 ld      [%g3+0x20], %g2
F002F324: c410a00c                 lduh    [%g2+0xC], %g2
F002F328: 8088a002                 btst    2, %g2
F002F32C: 2280000f                 be,a    loc_F002F368
F002F330: c600e040                 ld      [%g3+0x40], %g3
F002F334: c400e014                 ld      [%g3+0x14], %g2
F002F338: 80a08018                 cmp     %g2, %i0
F002F33C: 22800014                 be,a    locret_F002F38C
F002F340: b0102001                 mov     1, %i0
F002F344: c400e030                 ld      [%g3+0x30], %g2
F002F348: 80a60002                 cmp     %i0, %g2
F002F34C: 22800010                 be,a    locret_F002F38C
F002F350: b0102001                 mov     1, %i0
F002F354: c400e028                 ld      [%g3+0x28], %g2
F002F358: 80a60002                 cmp     %i0, %g2
F002F35C: 2280000c                 be,a    locret_F002F38C
F002F360: b0102001                 mov     1, %i0
F002F364: c600e040                 ld      [%g3+0x40], %g3
F002F368: 80a0e000                 cmp     %g3, 0
F002F36C: 32bfffee                 bne,a   loc_F002F324
F002F370: c400e020                 ld      [%g3+0x20], %g2
F002F374: 80a63fff                 cmp     %i0, -1
F002F378: 02800004                 be      loc_F002F388
F002F37C: 80a62000                 cmp     %i0, 0
F002F380: 12800003                 bne     locret_F002F38C
F002F384: b0102000                 mov     0, %i0
F002F388: b0102001                 mov     1, %i0
F002F38C: 81c7e008                 ret
F002F390: 81e80000                 restore
