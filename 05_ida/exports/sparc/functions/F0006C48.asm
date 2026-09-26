F0006C48: 9de3bfa0                 save    %sp, -0x60, %sp
F0006C4C: 90100018                 mov     %i0, %o0
F0006C50: 7ffffde5                 call    _mul
F0006C54: 92100019                 mov     %i1, %o1
F0006C58: d0268000                 st      %o0, [%i2]
F0006C5C: d226a004                 st      %o1, [%i2+4]
F0006C60: a0102000                 mov     0, %l0
F0006C64: a4102000                 mov     0, %l2
F0006C68: a332201f                 srl     %o0, 31, %l1
F0006C6C: a12c6003                 sll     %l1, 3, %l0
F0006C70: a0148010                 bset    %l2, %l0
F0006C74: 80920000                 tst     %o0
F0006C78: 22800002                 be,a    loc_F0006C80
F0006C7C: a0142004                 bset    4, %l0
F0006C80: a12c2014                 sll     %l0, 20, %l0
F0006C84: e2070000                 ld      [%i4], %l1
F0006C88: 25003c00                 sethi   0xF00000, %l2
F0006C8C: a22c4012                 bclr    %l2, %l1
F0006C90: a2144010                 bset    %l0, %l1
F0006C94: e2270000                 st      %l1, [%i4]
F0006C98: b0102001                 mov     1, %i0
F0006C9C: 81c7e008                 ret
F0006CA0: 81e80000                 restore
