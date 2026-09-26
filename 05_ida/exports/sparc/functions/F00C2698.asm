F00C2698: 9de3bf98                 save    %sp, -0x68, %sp
F00C269C: 7fff5147                 call    _spltty
F00C26A0: 01000000                 nop
F00C26A4: c0362008                 clrh    [%i0+8]
F00C26A8: c036200a                 clrh    [%i0+0xA]
F00C26AC: d2060000                 ld      [%i0], %o1
F00C26B0: a0100008                 mov     %o0, %l0
F00C26B4: c0326002                 clrh    [%o1+2]
F00C26B8: c0362010                 clrh    [%i0+0x10]
F00C26BC: c0362012                 clrh    [%i0+0x12]
F00C26C0: 92102007                 mov     7, %o1
F00C26C4: d22e2014                 stb     %o1, [%i0+0x14]
F00C26C8: d22e201e                 stb     %o1, [%i0+0x1E]
F00C26CC: d0062018                 ld      [%i0+0x18], %o0
F00C26D0: 7ffd50d8                 call    _ttyflush
F00C26D4: 92102001                 mov     1, %o1
F00C26D8: 7fff5193                 call    _splx
F00C26DC: 90100010                 mov     %l0, %o0
F00C26E0: 81c7e008                 ret
F00C26E4: 81e80000                 restore
