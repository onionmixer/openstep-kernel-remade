F00319A8: 9de3bf98                 save    %sp, -0x68, %sp
F00319AC: 86100018                 mov     %i0, %g3
F00319B0: 053c04d9                 sethi   %hi(_in_ifaddr), %g2
F00319B4: f000a070                 ld      [%g2+%lo(_in_ifaddr)], %i0
F00319B8: 80a62000                 cmp     %i0, 0
F00319BC: 2280000b                 be,a    locret_F00319E8
F00319C0: b0102000                 mov     0, %i0
F00319C4: c4062020                 ld      [%i0+0x20], %g2
F00319C8: 80a08003                 cmp     %g2, %g3
F00319CC: 02800007                 be      locret_F00319E8
F00319D0: 01000000                 nop
F00319D4: f0062040                 ld      [%i0+0x40], %i0
F00319D8: 80a62000                 cmp     %i0, 0
F00319DC: 32bffffb                 bne,a   loc_F00319C8
F00319E0: c4062020                 ld      [%i0+0x20], %g2
F00319E4: b0102000                 mov     0, %i0
F00319E8: 81c7e008                 ret
F00319EC: 81e80000                 restore
