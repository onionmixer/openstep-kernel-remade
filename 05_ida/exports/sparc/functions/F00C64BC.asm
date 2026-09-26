F00C64BC: 9de3bf90                 save    %sp, -0x70, %sp
F00C64C0: fa27a058                 st      %i5, [%fp+arg_58]
F00C64C4: 9010001b                 mov     %i3, %o0
F00C64C8: 9210001c                 mov     %i4, %o1
F00C64CC: d8062154                 ld      [%i0+0x154], %o4
F00C64D0: 170003d0                 sethi   0xF4000, %o3
F00C64D4: 94102000                 mov     0, %o2
F00C64D8: da062158                 ld      [%i0+0x158], %o5
F00C64DC: 9612e240                 bset    0x240, %o3
F00C64E0: e01fa058                 ldd     [%fp+arg_58], %l0
F00C64E4: 98032001                 inc     %o4
F00C64E8: d8262154                 st      %o4, [%i0+0x154]
F00C64EC: 9a03401a                 add     %o5, %i2, %o5
F00C64F0: 7ffcfe40                 call    __udivdi3
F00C64F4: da262158                 st      %o5, [%i0+0x158]
F00C64F8: 84100008                 mov     %o0, %g2
F00C64FC: 86100009                 mov     %o1, %g3
F00C6500: 90100010                 mov     %l0, %o0
F00C6504: 92100011                 mov     %l1, %o1
F00C6508: 170003d0                 sethi   0xF4000, %o3
F00C650C: 94102000                 mov     0, %o2
F00C6510: d806215c                 ld      [%i0+0x15C], %o4
F00C6514: 9612e240                 bset    0x240, %o3
F00C6518: 98030003                 add     %o4, %g3, %o4
F00C651C: 7ffcfe35                 call    __udivdi3
F00C6520: d826215c                 st      %o4, [%i0+0x15C]
F00C6524: d4062160                 ld      [%i0+0x160], %o2
F00C6528: 94028009                 add     %o2, %o1, %o2
F00C652C: d4262160                 st      %o2, [%i0+0x160]
F00C6530: 81c7e008                 ret
F00C6534: 81e80000                 restore
