F00434A0: 9de3bf98                 save    %sp, -0x68, %sp
F00434A4: e0062008                 ld      [%i0+8], %l0
F00434A8: 7fff6ce7                 call    _soclose
F00434AC: d0042014                 ld      [%l0+0x14], %o0
F00434B0: 13000008                 sethi   0x2000, %o1
F00434B4: d0042068                 ld      [%l0+0x68], %o0
F00434B8: 4000933a                 call    _kfree
F00434BC: 92126260                 bset    0x260, %o1
F00434C0: 90100010                 mov     %l0, %o0
F00434C4: 40009337                 call    _kfree
F00434C8: 92102078                 mov     0x78, %o1 ! 'x'
F00434CC: 81c7e008                 ret
F00434D0: 81e80000                 restore
