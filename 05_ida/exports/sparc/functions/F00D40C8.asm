F00D40C8: 9de3bf90                 save    %sp, -0x70, %sp
F00D40CC: c44e21d3                 ldsb    [%i0+0x1D3], %g2
F00D40D0: 80a0a001                 cmp     %g2, 1
F00D40D4: 32800008                 bne,a   locret_F00D40F4
F00D40D8: f00621cc                 ld      [%i0+0x1CC], %i0
F00D40DC: c60621c8                 ld      [%i0+0x1C8], %g3
F00D40E0: c40621cc                 ld      [%i0+0x1CC], %g2
F00D40E4: 80a0c002                 cmp     %g3, %g2
F00D40E8: 36800003                 bge,a   locret_F00D40F4
F00D40EC: f00621cc                 ld      [%i0+0x1CC], %i0
F00D40F0: b0100003                 mov     %g3, %i0
F00D40F4: 81c7e008                 ret
F00D40F8: 81e80000                 restore
