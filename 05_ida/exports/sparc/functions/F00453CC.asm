F00453CC: 9de3bf98                 save    %sp, -0x68, %sp
F00453D0: 073c04eb                 sethi   %hi(_drhashtbl), %g3
F00453D4: c4060000                 ld      [%i0], %g2
F00453D8: 8610e070                 bset    %lo(_drhashtbl), %g3
F00453DC: 8408a01f                 and     %g2, 0x1F, %g2
F00453E0: 8528a002                 sll     %g2, 2, %g2
F00453E4: f2008003                 ld      [%g2+%g3], %i1
F00453E8: 80a66000                 cmp     %i1, 0
F00453EC: 02800015                 be      locret_F0045440
F00453F0: b4102000                 mov     0, %i2
F00453F4: b6100003                 mov     %g3, %i3
F00453F8: 80a64018                 cmp     %i1, %i0
F00453FC: 3280000d                 bne,a   loc_F0045430
F0045400: b4100019                 mov     %i1, %i2
F0045404: 80a6a000                 cmp     %i2, 0
F0045408: 32800008                 bne,a   loc_F0045428
F004540C: c4066024                 ld      [%i1+0x24], %g2
F0045410: c4064000                 ld      [%i1], %g2
F0045414: c6066024                 ld      [%i1+0x24], %g3
F0045418: 8408a01f                 and     %g2, 0x1F, %g2
F004541C: 8528a002                 sll     %g2, 2, %g2
F0045420: 10800008                 ba      locret_F0045440
F0045424: c620801b                 st      %g3, [%g2+%i3]
F0045428: 10800006                 ba      locret_F0045440
F004542C: c426a024                 st      %g2, [%i2+0x24]
F0045430: f2066024                 ld      [%i1+0x24], %i1
F0045434: 80a66000                 cmp     %i1, 0
F0045438: 12bffff1                 bne     loc_F00453FC
F004543C: 80a64018                 cmp     %i1, %i0
F0045440: 81c7e008                 ret
F0045444: 81e80000                 restore
