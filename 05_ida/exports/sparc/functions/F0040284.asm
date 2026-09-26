F0040284: 9de3bf40                 save    %sp, -0xC0, %sp
F0040288: a2100018                 mov     %i0, %l1
F004028C: d204601c                 ld      [%l1+0x1C], %o1
F0040290: d4026070                 ld      [%o1+0x70], %o2
F0040294: 90100011                 mov     %l1, %o0
F0040298: 9fc28000                 call    %o2
F004029C: 9207bfac                 add     %fp, var_54, %o1
F00402A0: 80a22000                 cmp     %o0, 0
F00402A4: 22800002                 be,a    loc_F00402AC
F00402A8: e207bfac                 ld      [%fp+var_54], %l1
F00402AC: d4046030                 ld      [%l1+0x30], %o2
F00402B0: d002a040                 ld      [%o2+0x40], %o0
F00402B4: d027bfb0                 st      %o0, [%fp+var_50]
F00402B8: d002a044                 ld      [%o2+0x44], %o0
F00402BC: d027bfb4                 st      %o0, [%fp+var_4C]
F00402C0: d002a048                 ld      [%o2+0x48], %o0
F00402C4: d027bfb8                 st      %o0, [%fp+var_48]
F00402C8: d002a04c                 ld      [%o2+0x4C], %o0
F00402CC: d027bfbc                 st      %o0, [%fp+var_44]
F00402D0: d002a050                 ld      [%o2+0x50], %o0
F00402D4: d027bfc0                 st      %o0, [%fp+var_40]
F00402D8: d202a054                 ld      [%o2+0x54], %o1
F00402DC: a007bfb0                 add     %fp, var_50, %l0
F00402E0: d227bfc4                 st      %o1, [%fp+var_3C]
F00402E4: d602a058                 ld      [%o2+0x58], %o3
F00402E8: 9007bfd0                 add     %fp, var_30, %o0
F00402EC: d627bfc8                 st      %o3, [%fp+var_38]
F00402F0: d602a05c                 ld      [%o2+0x5C], %o3
F00402F4: 9210001a                 mov     %i2, %o1
F00402F8: 94100019                 mov     %i1, %o2
F00402FC: 7ffff23a                 call    _setdiropargs
F0040300: d627bfcc                 st      %o3, [%fp+var_34]
F0040304: 7ffff4c8                 call    _rlock
F0040308: d0066030                 ld      [%i1+0x30], %o0
F004030C: 9210200c                 mov     0xC, %o1
F0040310: 153c01089412a36c         set     _xdr_linkargs, %o2
F0040318: 193c0115                 sethi   %hi(_xdr_enum), %o4
F004031C: 96100010                 mov     %l0, %o3
F0040320: d0046024                 ld      [%l1+0x24], %o0
F0040324: 98132348                 bset    %lo(_xdr_enum), %o4
F0040328: d0022128                 ld      [%o0+0x128], %o0
F004032C: 9a07bfa8                 add     %fp, var_58, %o5
F0040330: 7ffff111                 call    _rfscall
F0040334: f623a05c                 st      %i3, [%sp+0xC0+var_64]
F0040338: d2066030                 ld      [%i1+0x30], %o1
F004033C: c02260c0                 clr     [%o1+0xC0]
F0040340: d2046030                 ld      [%l1+0x30], %o1
F0040344: b0100008                 mov     %o0, %i0
F0040348: c02260c0                 clr     [%o1+0xC0]
F004034C: 7ffff4d4                 call    _runlock
F0040350: d0066030                 ld      [%i1+0x30], %o0
F0040354: 80a62000                 cmp     %i0, 0
F0040358: 12800011                 bne     locret_F004039C
F004035C: 01000000                 nop
F0040360: f007bfa8                 ld      [%fp+var_58], %i0
F0040364: 80a62046                 cmp     %i0, 0x46 ! 'F'
F0040368: 12800007                 bne     loc_F0040384
F004036C: 01000000                 nop
F0040370: 7fff9463                 call    _btrash
F0040374: 90100011                 mov     %l1, %o0
F0040378: 7fffe4ac                 call    _nfs_invalidate_caches
F004037C: 90100011                 mov     %l1, %o0
F0040380: 80a62046                 cmp     %i0, 0x46 ! 'F'
F0040384: 12800006                 bne     locret_F004039C
F0040388: 01000000                 nop
F004038C: 7fff945c                 call    _btrash
F0040390: 90100019                 mov     %i1, %o0
F0040394: 7fffe4a5                 call    _nfs_invalidate_caches
F0040398: 90100019                 mov     %i1, %o0
F004039C: 81c7e008                 ret
F00403A0: 81e80000                 restore
