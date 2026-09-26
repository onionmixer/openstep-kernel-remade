F00DEE38: 9de3bf98                 save    %sp, -0x68, %sp
F00DEE3C: 80a62000                 cmp     %i0, 0
F00DEE40: 02800013                 be      loc_F00DEE8C
F00DEE44: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DEE48: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DEE4C: 133c0505                 sethi   %hi(paInstance_0), %o1! SEL
F00DEE50: 40004a88                 call    _objc_msgSend
F00DEE54: d20260e0                 ld      [%o1+%lo(paInstance_0)], %o1
F00DEE58: 133c0504                 sethi   %hi(paName), %o1! SEL
F00DEE5C: 40004a85                 call    _objc_msgSend
F00DEE60: d2026008                 ld      [%o1+%lo(paName)], %o1
F00DEE64: 92100008                 mov     %o0, %o1! __src
F00DEE68: 90100019                 mov     %i1, %o0! __s
F00DEE6C: 7ffca2ac                 call    _strncpy
F00DEE70: 941020ff                 mov     0xFF, %o2
F00DEE74: c02e60ff                 clrb    [%i1+0xFF]
F00DEE78: 7ffca170                 call    _strlen
F00DEE7C: 90100019                 mov     %i1, %o0
F00DEE80: d0268000                 st      %o0, [%i2]
F00DEE84: 10800003                 ba      locret_F00DEE90
F00DEE88: b0102000                 mov     0, %i0
F00DEE8C: b01020ca                 mov     0xCA, %i0
F00DEE90: 81c7e008                 ret
F00DEE94: 81e80000                 restore
