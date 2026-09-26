F008CE7C: 9de3bf90                 save    %sp, -0x70, %sp
F008CE80: c44e2010                 ldsb    [%i0+0x10], %g2
F008CE84: 80a0a000                 cmp     %g2, 0
F008CE88: 22800005                 be,a    locret_F008CE9C
F008CE8C: b0102000                 mov     0, %i0
F008CE90: c406200c                 ld      [%i0+0xC], %g2
F008CE94: 8400a001                 inc     %g2
F008CE98: c426200c                 st      %g2, [%i0+0xC]
F008CE9C: 81c7e008                 ret
F008CEA0: 81e80000                 restore
