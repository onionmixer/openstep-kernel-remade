F00A6D94: 9de3bf98                 save    %sp, -0x68, %sp
F00A6D98: a2100018                 mov     %i0, %l1
F00A6D9C: 7fffc0ee                 call    _memerr_disable
F00A6DA0: b0102000                 mov     0, %i0
F00A6DA4: 113c046c                 sethi   %hi(dword_F011B044), %o0
F00A6DA8: d2022044                 ld      [%o0+%lo(dword_F011B044)], %o1
F00A6DAC: 80a26000                 cmp     %o1, 0
F00A6DB0: 02800015                 be      loc_F00A6E04
F00A6DB4: a0122044                 or      %o0, %lo(dword_F011B044), %l0
F00A6DB8: 253c046c                 sethi   -0xFEE5000, %l2
F00A6DBC: d2040000                 ld      [%l0], %o1
F00A6DC0: 7fffc07d                 call    _stphys
F00A6DC4: 90100011                 mov     %l1, %o0
F00A6DC8: 7fffc064                 call    _ldphys
F00A6DCC: 90100011                 mov     %l1, %o0
F00A6DD0: d4040000                 ld      [%l0], %o2
F00A6DD4: 80a2000a                 cmp     %o0, %o2
F00A6DD8: 22800007                 be,a    loc_F00A6DF4
F00A6DDC: a0042004                 inc     4, %l0
F00A6DE0: 9014a098                 or      %l2, 0x98, %o0! char *
F00A6DE4: 7ffdb61d                 call    _printf
F00A6DE8: 92100011                 mov     %l1, %o1
F00A6DEC: b0062001                 inc     %i0
F00A6DF0: a0042004                 inc     4, %l0
F00A6DF4: d0040000                 ld      [%l0], %o0
F00A6DF8: 80a22000                 cmp     %o0, 0
F00A6DFC: 32bffff1                 bne,a   loc_F00A6DC0
F00A6E00: d2040000                 ld      [%l0], %o1
F00A6E04: 7fffc0d0                 call    _memerr_init
F00A6E08: 01000000                 nop
F00A6E0C: 80a62000                 cmp     %i0, 0
F00A6E10: 32800002                 bne,a   loc_F00A6E18
F00A6E14: b0103fff                 mov     -1, %i0
F00A6E18: 80a62000                 cmp     %i0, 0
F00A6E1C: 113c046c                 sethi   %hi(aParityErrorAtX), %o0! "Parity error at %x is %s.\n"
F00A6E20: 02800005                 be      loc_F00A6E34
F00A6E24: 921220c0                 or      %o0, %lo(aParityErrorAtX), %o1! "Parity error at %x is %s.\n"
F00A6E28: 113c046c                 sethi   %hi(aPermanent), %o0! "permanent"
F00A6E2C: 10800004                 ba      loc_F00A6E3C
F00A6E30: 941220e0                 or      %o0, %lo(aPermanent), %o2! "permanent"
F00A6E34: 113c046c941220f0         set     aTransient, %o2! "transient"
F00A6E3C: 90100009                 mov     %o1, %o0! char *
F00A6E40: 7ffdb606                 call    _printf
F00A6E44: 92100011                 mov     %l1, %o1
F00A6E48: 81c7e008                 ret
F00A6E4C: 81e80000                 restore
