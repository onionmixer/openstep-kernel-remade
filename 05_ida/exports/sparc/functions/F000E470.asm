F000E470: 9de3bf98                 save    %sp, -0x68, %sp
F000E474: 053c04cf                 sethi   %hi(_active_u), %g2
F000E478: c400a1d8                 ld      [%g2+%lo(_active_u)], %g2
F000E47C: c4008000                 ld      [%g2], %g2
F000E480: 80a60002                 cmp     %i0, %g2
F000E484: 2280000d                 be,a    locret_F000E4B8
F000E488: b0102001                 mov     1, %i0
F000E48C: 86100002                 mov     %g2, %g3
F000E490: c4562032                 ldsh    [%i0+0x32], %g2
F000E494: 80a0a000                 cmp     %g2, 0
F000E498: 32800004                 bne,a   loc_F000E4A8
F000E49C: f0062044                 ld      [%i0+0x44], %i0
F000E4A0: 10800006                 ba      locret_F000E4B8
F000E4A4: b0102000                 mov     0, %i0
F000E4A8: 80a60003                 cmp     %i0, %g3
F000E4AC: 32bffffa                 bne,a   loc_F000E494
F000E4B0: c4562032                 ldsh    [%i0+0x32], %g2
F000E4B4: b0102001                 mov     1, %i0
F000E4B8: 81c7e008                 ret
F000E4BC: 81e80000                 restore
