F00E2890: 9de3bf98                 save    %sp, -0x68, %sp
F00E2894: c4060000                 ld      [%i0], %g2
F00E2898: c6064000                 ld      [%i1], %g3
F00E289C: c450a002                 ldsh    [%g2+2], %g2
F00E28A0: c650e002                 ldsh    [%g3+2], %g3
F00E28A4: 80a08003                 cmp     %g2, %g3
F00E28A8: 14800005                 bg      locret_F00E28BC
F00E28AC: b0102001                 mov     1, %i0
F00E28B0: 84188003                 btog    %g3, %g2
F00E28B4: 80a00002                 cmp     %g0, %g2
F00E28B8: b0602000                 subc    %g0, 0, %i0
F00E28BC: 81c7e008                 ret
F00E28C0: 81e80000                 restore
