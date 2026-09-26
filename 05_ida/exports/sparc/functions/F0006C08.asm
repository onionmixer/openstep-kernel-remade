F0006C08: 9de3bfa0                 save    %sp, -0x60, %sp
F0006C0C: 90100018                 mov     %i0, %o0
F0006C10: 7ffffe3c                 call    _umul
F0006C14: 92100019                 mov     %i1, %o1
F0006C18: d0268000                 st      %o0, [%i2]
F0006C1C: d226a004                 st      %o1, [%i2+4]
F0006C20: a0102000                 mov     0, %l0
F0006C24: a4102000                 mov     0, %l2
F0006C28: a332201f                 srl     %o0, 31, %l1
F0006C2C: a12c6003                 sll     %l1, 3, %l0
F0006C30: a0148010                 bset    %l2, %l0
F0006C34: 80920000                 tst     %o0
F0006C38: 22800002                 be,a    loc_F0006C40
F0006C3C: a0142004                 bset    4, %l0
F0006C40: 10800011                 ba      loc_F0006C84
F0006C44: a12c2014                 sll     %l0, 20, %l0
