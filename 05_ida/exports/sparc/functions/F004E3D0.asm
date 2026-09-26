F004E3D0: 9de3bf98                 save    %sp, -0x68, %sp
F004E3D4: d0162044                 lduh    [%i0+0x44], %o0
F004E3D8: 900a2101                 and     %o0, 0x101, %o0
F004E3DC: 80a22100                 cmp     %o0, 0x100
F004E3E0: 1280000a                 bne     loc_F004E408
F004E3E4: 113c043b                 sethi   -0xFEF1400, %o0
F004E3E8: d0062060                 ld      [%i0+0x60], %o0
F004E3EC: 80a22000                 cmp     %o0, 0
F004E3F0: 12800006                 bne     loc_F004E408
F004E3F4: 113c043b                 sethi   -0xFEF1400, %o0
F004E3F8: d006205c                 ld      [%i0+0x5C], %o0
F004E3FC: 80a22000                 cmp     %o0, 0
F004E400: 02800004                 be      loc_F004E410
F004E404: 113c043b                 sethi   -0xFEF1400, %o0! char *
F004E408: 7fff1b5a                 call    _panic
F004E40C: 901220a0                 bset    0xA0, %o0
F004E410: d0062050                 ld      [%i0+0x50], %o0
F004E414: d04a20d2                 ldsb    [%o0+0xD2], %o0
F004E418: 80a22000                 cmp     %o0, 0
F004E41C: 12800038                 bne     loc_F004E4FC
F004E420: 133c04eb                 sethi   -0xFEC5400, %o1
F004E424: 10800007                 ba      loc_F004E440
F004E428: d0162044                 lduh    [%i0+0x44], %o0
F004E42C: d0362044                 sth     %o0, [%i0+0x44]
F004E430: 90100018                 mov     %i0, %o0! unsigned int
F004E434: 7fff1091                 call    _sleep
F004E438: 9210200a                 mov     0xA, %o1
F004E43C: d0162044                 lduh    [%i0+0x44], %o0
F004E440: 808a2001                 btst    1, %o0
F004E444: 12bffffa                 bne     loc_F004E42C
F004E448: 90122010                 bset    0x10, %o0
F004E44C: d0162044                 lduh    [%i0+0x44], %o0
F004E450: d2562066                 ldsh    [%i0+0x66], %o1
F004E454: 90122001                 bset    1, %o0
F004E458: 80a26000                 cmp     %o1, 0
F004E45C: 14800014                 bg      loc_F004E4AC
F004E460: d0362044                 sth     %o0, [%i0+0x44]
F004E464: 90100018                 mov     %i0, %o0
F004E468: d60620d0                 ld      [%i0+0xD0], %o3
F004E46C: 92102000                 mov     0, %o1
F004E470: d4162044                 lduh    [%i0+0x44], %o2
F004E474: 9602e001                 inc     %o3
F004E478: d62620d0                 st      %o3, [%i0+0xD0]
F004E47C: 9412a200                 bset    0x200, %o2
F004E480: 4000009f                 call    _itrunc
F004E484: d4362044                 sth     %o2, [%i0+0x44]
F004E488: d2062048                 ld      [%i0+0x48], %o1
F004E48C: c026208c                 clr     [%i0+0x8C]
F004E490: d4162064                 lduh    [%i0+0x64], %o2
F004E494: 90100018                 mov     %i0, %o0
F004E498: d6162044                 lduh    [%i0+0x44], %o3
F004E49C: c0362064                 clrh    [%i0+0x64]
F004E4A0: 9612e042                 bset    0x42, %o3 ! 'B'
F004E4A4: 7ffff074                 call    _ifree
F004E4A8: d6362044                 sth     %o3, [%i0+0x44]
F004E4AC: d0162044                 lduh    [%i0+0x44], %o0
F004E4B0: 808a204e                 btst    0x4E, %o0 ! 'N'
F004E4B4: 02800004                 be      loc_F004E4C4
F004E4B8: 90100018                 mov     %i0, %o0
F004E4BC: 40000022                 call    _iupdat
F004E4C0: 92102000                 mov     0, %o1
F004E4C4: d2162044                 lduh    [%i0+0x44], %o1
F004E4C8: 1100003f901223fe         set     0xFFFE, %o0
F004E4D0: 920a4008                 and     %o1, %o0, %o1
F004E4D4: 808a6010                 btst    0x10, %o1
F004E4D8: 02800008                 be      loc_F004E4F8
F004E4DC: d2362044                 sth     %o1, [%i0+0x44]
F004E4E0: 1100003f901223ef         set     0xFFEF, %o0
F004E4E8: 900a4008                 and     %o1, %o0, %o0
F004E4EC: d0362044                 sth     %o0, [%i0+0x44]
F004E4F0: 7fff123e                 call    _wakeup
F004E4F4: 90100018                 mov     %i0, %o0
F004E4F8: 133c04eb                 sethi   -0xFEC5400, %o1
F004E4FC: d00261a0                 ld      [%o1+0x1A0], %o0
F004E500: c0362044                 clrh    [%i0+0x44]
F004E504: 80a22000                 cmp     %o0, 0
F004E508: 02800007                 be      loc_F004E524
F004E50C: 901261a0                 or      %o1, 0x1A0, %o0
F004E510: 113c04eb                 sethi   %hi(_ifreet), %o0
F004E514: d20221a8                 ld      [%o0+%lo(_ifreet)], %o1
F004E518: f0224000                 st      %i0, [%o1]
F004E51C: 10800003                 ba      loc_F004E528
F004E520: d00221a8                 ld      [%o0+%lo(_ifreet)], %o0
F004E524: f02261a0                 st      %i0, [%o1+0x1A0]
F004E528: d0262060                 st      %o0, [%i0+0x60]
F004E52C: c026205c                 clr     [%i0+0x5C]
F004E530: 9206205c                 add     %i0, 0x5C, %o1 ! '\'
F004E534: 113c04eb                 sethi   %hi(_ifreet), %o0
F004E538: d22221a8                 st      %o1, [%o0+%lo(_ifreet)]
F004E53C: 81c7e008                 ret
F004E540: 81e80000                 restore
