F006FC14: 9de3bf98                 save    %sp, -0x68, %sp
F006FC18: c4064000                 ld      [%i1], %g2
F006FC1C: 80a0a007                 cmp     %g2, 7
F006FC20: 0880001c                 bleu    loc_F006FC90
F006FC24: b6100018                 mov     %i0, %i3
F006FC28: 393c04f1                 sethi   %hi(dword_F013C408), %i4
F006FC2C: c4072008                 ld      [%i4+%lo(dword_F013C408)], %g2
F006FC30: 80a0a000                 cmp     %g2, 0
F006FC34: 02800017                 be      loc_F006FC90
F006FC38: 86172008                 or      %i4, %lo(dword_F013C408), %g3
F006FC3C: c410fff8                 lduh    [%g3-8], %g2
F006FC40: b0102001                 mov     1, %i0
F006FC44: c4368000                 sth     %g2, [%i2]
F006FC48: c030e00c                 clrh    [%g3+0xC]
F006FC4C: c030fff8                 clrh    [%g3-8]
F006FC50: c0272008                 clr     [%i4+%lo(dword_F013C408)]
F006FC54: c020e008                 clr     [%g3+8]
F006FC58: c020fffc                 clr     [%g3-4]
F006FC5C: c028e00e                 clrb    [%g3+0xE]
F006FC60: c406c000                 ld      [%i3], %g2
F006FC64: 07004000                 sethi   0x1000000, %g3
F006FC68: 84108003                 bset    %g3, %g2
F006FC6C: c426c000                 st      %g2, [%i3]
F006FC70: 84102008                 mov     8, %g2
F006FC74: c436e002                 sth     %g2, [%i3+2]
F006FC78: 0500003f                 sethi   0xFC00, %g2
F006FC7C: c606c000                 ld      [%i3], %g3
F006FC80: 8410a3ff                 bset    0x3FF, %g2
F006FC84: 8608c002                 and     %g3, %g2, %g3
F006FC88: 10800003                 ba      locret_F006FC94
F006FC8C: c6264000                 st      %g3, [%i1]
F006FC90: b0102000                 mov     0, %i0
F006FC94: 81c7e008                 ret
F006FC98: 81e80000                 restore
