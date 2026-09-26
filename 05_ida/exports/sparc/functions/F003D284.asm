F003D284: 9de3bf98                 save    %sp, -0x68, %sp
F003D288: d0062070                 ld      [%i0+0x70], %o0
F003D28C: 80a22000                 cmp     %o0, 0
F003D290: 02800005                 be      locret_F003D2A4
F003D294: 01000000                 nop
F003D298: 7fff49e0                 call    _crfree
F003D29C: 01000000                 nop
F003D2A0: c0262070                 clr     [%i0+0x70]
F003D2A4: 81c7e008                 ret
F003D2A8: 81e80000                 restore
