F00D60AC: 9de3bf90                 save    %sp, -0x70, %sp
F00D60B0: 80a6a000                 cmp     %i2, 0
F00D60B4: 22800005                 be,a    locret_F00D60C8
F00D60B8: f00624ec                 ld      [%i0+0x4EC], %i0
F00D60BC: c40624f0                 ld      [%i0+0x4F0], %g2
F00D60C0: c4268000                 st      %g2, [%i2]
F00D60C4: f00624ec                 ld      [%i0+0x4EC], %i0
F00D60C8: 81c7e008                 ret
F00D60CC: 81e80000                 restore
