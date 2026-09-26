F006FB60: 9de3bf98                 save    %sp, -0x68, %sp
F006FB64: c4064000                 ld      [%i1], %g2
F006FB68: 80a0a00b                 cmp     %g2, 0xB
F006FB6C: 18800004                 bgu     loc_F006FB7C
F006FB70: b6100018                 mov     %i0, %i3
F006FB74: 10800026                 ba      locret_F006FC0C
F006FB78: b0102000                 mov     0, %i0
F006FB7C: 073c04f1                 sethi   %hi(dword_F013C408), %g3
F006FB80: c400e008                 ld      [%g3+%lo(dword_F013C408)], %g2
F006FB84: 80a0a000                 cmp     %g2, 0
F006FB88: 02800009                 be      loc_F006FBAC
F006FB8C: b010e008                 or      %g3, %lo(dword_F013C408), %i0
F006FB90: c60ee001                 ldub    [%i3+1], %g3
F006FB94: c4063ffc                 ld      [%i0-4], %g2
F006FB98: 80a0c002                 cmp     %g3, %g2
F006FB9C: 0280000c                 be      loc_F006FBCC
F006FBA0: 84102001                 mov     1, %g2
F006FBA4: 1080000b                 ba      loc_F006FBD0
F006FBA8: c426e008                 st      %g2, [%i3+8]
F006FBAC: c416e008                 lduh    [%i3+8], %g2
F006FBB0: c4363ff8                 sth     %g2, [%i0-8]
F006FBB4: c416e00a                 lduh    [%i3+0xA], %g2
F006FBB8: c436200c                 sth     %g2, [%i0+0xC]
F006FBBC: 84102001                 mov     1, %g2
F006FBC0: c420e008                 st      %g2, [%g3+8]
F006FBC4: c40ee001                 ldub    [%i3+1], %g2
F006FBC8: c4263ffc                 st      %g2, [%i0-4]
F006FBCC: c026e008                 clr     [%i3+8]
F006FBD0: c406c000                 ld      [%i3], %g2
F006FBD4: 07004000                 sethi   0x1000000, %g3
F006FBD8: 84108003                 bset    %g3, %g2
F006FBDC: c426c000                 st      %g2, [%i3]
F006FBE0: 8410200c                 mov     0xC, %g2
F006FBE4: c436e002                 sth     %g2, [%i3+2]
F006FBE8: 053c04f1                 sethi   %hi(_kdp), %g2
F006FBEC: c410a000                 lduh    [%g2+%lo(_kdp)], %g2
F006FBF0: b0102001                 mov     1, %i0
F006FBF4: c4368000                 sth     %g2, [%i2]
F006FBF8: 0500003f                 sethi   0xFC00, %g2
F006FBFC: c606c000                 ld      [%i3], %g3
F006FC00: 8410a3ff                 bset    0x3FF, %g2
F006FC04: 8608c002                 and     %g3, %g2, %g3
F006FC08: c6264000                 st      %g3, [%i1]
F006FC0C: 81c7e008                 ret
F006FC10: 81e80000                 restore
