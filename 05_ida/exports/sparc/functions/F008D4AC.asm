F008D4AC: 9de3bf90                 save    %sp, -0x70, %sp
F008D4B0: c44e2018                 ldsb    [%i0+0x18], %g2
F008D4B4: 80a0a000                 cmp     %g2, 0
F008D4B8: 22800005                 be,a    locret_F008D4CC
F008D4BC: b0102000                 mov     0, %i0
F008D4C0: c4062014                 ld      [%i0+0x14], %g2
F008D4C4: 8400a001                 inc     %g2
F008D4C8: c4262014                 st      %g2, [%i0+0x14]
F008D4CC: 81c7e008                 ret
F008D4D0: 81e80000                 restore
