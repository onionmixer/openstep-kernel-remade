F000B340: 9de3bf98                 save    %sp, -0x68, %sp
F000B344: b0102000                 mov     0, %i0
F000B348: 053c04cf                 sethi   %hi(_active_u), %g2
F000B34C: f400a1d8                 ld      [%g2+%lo(_active_u)], %i2
F000B350: b2102000                 mov     0, %i1
F000B354: f606a158                 ld      [%i2+0x158], %i3
F000B358: 80a6401b                 cmp     %i1, %i3
F000B35C: 36800009                 bge,a   loc_F000B380
F000B360: b2066001                 inc     %i1
F000B364: c406a14c                 ld      [%i2+0x14C], %g2
F000B368: 872e6002                 sll     %i1, 2, %g3
F000B36C: c4008003                 ld      [%g2+%g3], %g2
F000B370: 80a0a000                 cmp     %g2, 0
F000B374: 22800002                 be,a    loc_F000B37C
F000B378: b0062001                 inc     %i0
F000B37C: b2066001                 inc     %i1
F000B380: 80a660ff                 cmp     %i1, 0xFF
F000B384: 04bffff6                 ble     loc_F000B35C
F000B388: 80a6401b                 cmp     %i1, %i3
F000B38C: 81c7e008                 ret
F000B390: 81e80000                 restore
