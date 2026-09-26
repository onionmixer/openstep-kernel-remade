F00BB480: 9de3bf98                 save    %sp, -0x68, %sp
F00BB484: 113c04fd                 sethi   %hi(_zscom), %o0
F00BB488: d20221e8                 ld      [%o0+%lo(_zscom)], %o1
F00BB48C: e0026090                 ld      [%o1+0x90], %l0
F00BB490: 90102002                 mov     2, %o0
F00BB494: 92102028                 mov     0x28, %o1 ! '('
F00BB498: d22c0000                 stb     %o1, [%l0]
F00BB49C: 7fff70f1                 call    _us_spin
F00BB4A0: 01000000                 nop
F00BB4A4: 90102010                 mov     0x10, %o0
F00BB4A8: d02c0000                 stb     %o0, [%l0]
F00BB4AC: 7fff70ed                 call    _us_spin
F00BB4B0: 90102002                 mov     2, %o0
F00BB4B4: f00c2002                 ldub    [%l0+2], %i0
F00BB4B8: 7fff70ea                 call    _us_spin
F00BB4BC: 90102002                 mov     2, %o0
F00BB4C0: 90102030                 mov     0x30, %o0 ! '0'
F00BB4C4: d02c0000                 stb     %o0, [%l0]
F00BB4C8: 81c7e008                 ret
F00BB4CC: 81e80000                 restore
