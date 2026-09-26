F002F2C0: 9de3bf98                 save    %sp, -0x68, %sp
F002F2C4: 86100018                 mov     %i0, %g3
F002F2C8: 053c04d9                 sethi   %hi(_in_ifaddr), %g2
F002F2CC: f000a070                 ld      [%g2+%lo(_in_ifaddr)], %i0
F002F2D0: 80a62000                 cmp     %i0, 0
F002F2D4: 2280000b                 be,a    locret_F002F300
F002F2D8: b0102000                 mov     0, %i0
F002F2DC: c4062030                 ld      [%i0+0x30], %g2
F002F2E0: 80a08003                 cmp     %g2, %g3
F002F2E4: 02800007                 be      locret_F002F300
F002F2E8: 01000000                 nop
F002F2EC: f0062040                 ld      [%i0+0x40], %i0
F002F2F0: 80a62000                 cmp     %i0, 0
F002F2F4: 32bffffb                 bne,a   loc_F002F2E0
F002F2F8: c4062030                 ld      [%i0+0x30], %g2
F002F2FC: b0102000                 mov     0, %i0
F002F300: 81c7e008                 ret
F002F304: 81e80000                 restore
