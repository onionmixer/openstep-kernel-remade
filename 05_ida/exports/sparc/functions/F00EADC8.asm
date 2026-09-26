F00EADC8: 9de3bf98                 save    %sp, -0x68, %sp
F00EADCC: d04e4000                 ldsb    [%i1], %o0
F00EADD0: 80a22040                 cmp     %o0, 0x40 ! '@'
F00EADD4: 0280000f                 be      loc_F00EAE10
F00EADD8: 133c0504                 sethi   -0xFEBF000, %o1
F00EADDC: 14800009                 bg      loc_F00EAE00
F00EADE0: 80a22069                 cmp     %o0, 0x69 ! 'i'
F00EADE4: 80a22025                 cmp     %o0, 0x25 ! '%'
F00EADE8: 02800018                 be      loc_F00EAE48
F00EADEC: 80a2202a                 cmp     %o0, 0x2A ! '*'
F00EADF0: 02800017                 be      loc_F00EAE4C
F00EADF4: 90100018                 mov     %i0, %o0
F00EADF8: 10800018                 ba      loc_F00EAE58
F00EADFC: 133c03f3                 sethi   -0xFF03400, %o1
F00EAE00: 0280000c                 be      loc_F00EAE30
F00EAE04: 90100018                 mov     %i0, %o0
F00EAE08: 10800014                 ba      loc_F00EAE58
F00EAE0C: 133c03f3                 sethi   -0xFF03400, %o1! SEL
F00EAE10: 9010001a                 mov     %i2, %o0! id
F00EAE14: 40001a97                 call    _objc_msgSend
F00EAE18: d2026008                 ld      [%o1+8], %o1
F00EAE1C: 94100008                 mov     %o0, %o2
F00EAE20: 90100018                 mov     %i0, %o0
F00EAE24: 133c03f3                 sethi   %hi(aS0xX), %o1! "%s[0x%x]"
F00EAE28: 10800005                 ba      loc_F00EAE3C
F00EAE2C: 92126120                 bset    %lo(aS0xX), %o1! "%s[0x%x]"
F00EAE30: 133c03f392126130         set     aD0xX, %o1! "%d[0x%x]"
F00EAE38: 9410001a                 mov     %i2, %o2
F00EAE3C: 7ffe853e                 call    _NXPrintf
F00EAE40: 9610001a                 mov     %i2, %o3
F00EAE44: 30800008                 ba,a    locret_F00EAE64
F00EAE48: 90100018                 mov     %i0, %o0
F00EAE4C: 133c03f3                 sethi   %hi(aS), %o1! "\"%s\""
F00EAE50: 10800003                 ba      loc_F00EAE5C
F00EAE54: 92126140                 bset    %lo(aS), %o1! "\"%s\""
F00EAE58: 92126148                 bset    0x148, %o1
F00EAE5C: 7ffe8536                 call    _NXPrintf
F00EAE60: 9410001a                 mov     %i2, %o2
F00EAE64: 81c7e008                 ret
F00EAE68: 81e80000                 restore
