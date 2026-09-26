F004E274: 9de3bf98                 save    %sp, -0x68, %sp
F004E278: d0162044                 lduh    [%i0+0x44], %o0
F004E27C: 808a2001                 btst    1, %o0
F004E280: 02800004                 be      loc_F004E290
F004E284: 113c043b                 sethi   %hi(aIrele), %o0! "irele"
F004E288: 7fff1bba                 call    _panic
F004E28C: 90122090                 bset    %lo(aIrele), %o0! "irele"
F004E290: d0162044                 lduh    [%i0+0x44], %o0
F004E294: 808a2046                 btst    0x46, %o0 ! 'F'
F004E298: 0280001c                 be      loc_F004E308
F004E29C: 90122008                 bset    8, %o0
F004E2A0: d0362044                 sth     %o0, [%i0+0x44]
F004E2A4: 213c04d4                 sethi   %hi(_iuniqtime), %l0
F004E2A8: 400080ca                 call    _microtime
F004E2AC: 90142148                 or      %l0, %lo(_iuniqtime), %o0
F004E2B0: d0162044                 lduh    [%i0+0x44], %o0
F004E2B4: 808a2004                 btst    4, %o0
F004E2B8: 02800003                 be      loc_F004E2C4
F004E2BC: d0042148                 ld      [%l0+%lo(_iuniqtime)], %o0
F004E2C0: d0262074                 st      %o0, [%i0+0x74]
F004E2C4: d0162044                 lduh    [%i0+0x44], %o0
F004E2C8: 808a2002                 btst    2, %o0
F004E2CC: 02800003                 be      loc_F004E2D8
F004E2D0: d0042148                 ld      [%l0+0x148], %o0
F004E2D4: d026207c                 st      %o0, [%i0+0x7C]
F004E2D8: d0162044                 lduh    [%i0+0x44], %o0
F004E2DC: 808a2040                 btst    0x40, %o0 ! '@'
F004E2E0: 22800006                 be,a    loc_F004E2F8
F004E2E4: d2162044                 lduh    [%i0+0x44], %o1
F004E2E8: c026204c                 clr     [%i0+0x4C]
F004E2EC: d0042148                 ld      [%l0+0x148], %o0
F004E2F0: d0262084                 st      %o0, [%i0+0x84]
F004E2F4: d2162044                 lduh    [%i0+0x44], %o1
F004E2F8: 1100003f901223b9         set     0xFFB9, %o0
F004E300: 920a4008                 and     %o1, %o0, %o1
F004E304: d2362044                 sth     %o1, [%i0+0x44]
F004E308: 7fff6a17                 call    _vn_rele
F004E30C: 9006200c                 add     %i0, 0xC, %o0
F004E310: 81c7e008                 ret
F004E314: 81e80000                 restore
