F0022D58: 9de3bf98                 save    %sp, -0x68, %sp
F0022D5C: e006200c                 ld      [%i0+0xC], %l0
F0022D60: 80a42000                 cmp     %l0, 0
F0022D64: 02800029                 be      locret_F0022E08
F0022D68: 01000000                 nop
F0022D6C: d0060000                 ld      [%i0], %o0
F0022D70: c026200c                 clr     [%i0+0xC]
F0022D74: d2520000                 ldsh    [%o0], %o1
F0022D78: 80a26001                 cmp     %o1, 1
F0022D7C: 0280001e                 be      loc_F0022DF4
F0022D80: 80a26002                 cmp     %o1, 2
F0022D84: 12800021                 bne     locret_F0022E08
F0022D88: 01000000                 nop
F0022D8C: d0042010                 ld      [%l0+0x10], %o0
F0022D90: 80a20018                 cmp     %o0, %i0
F0022D94: 32800005                 bne,a   loc_F0022DA8
F0022D98: a0100008                 mov     %o0, %l0
F0022D9C: d0062014                 ld      [%i0+0x14], %o0
F0022DA0: 1080000f                 ba      loc_F0022DDC
F0022DA4: d0242010                 st      %o0, [%l0+0x10]
F0022DA8: 233c042f                 sethi   -0xFEF4400, %l1
F0022DAC: 80a42000                 cmp     %l0, 0
F0022DB0: 32800005                 bne,a   loc_F0022DC4
F0022DB4: d0042014                 ld      [%l0+0x14], %o0! char *
F0022DB8: 7fffc8ee                 call    _panic
F0022DBC: 90146168                 or      %l1, 0x168, %o0
F0022DC0: d0042014                 ld      [%l0+0x14], %o0
F0022DC4: 80a20018                 cmp     %o0, %i0
F0022DC8: 22800004                 be,a    loc_F0022DD8
F0022DCC: d0062014                 ld      [%i0+0x14], %o0
F0022DD0: 10bffff7                 ba      loc_F0022DAC
F0022DD4: a0100008                 mov     %o0, %l0
F0022DD8: d0242014                 st      %o0, [%l0+0x14]
F0022DDC: d2060000                 ld      [%i0], %o1
F0022DE0: c0262014                 clr     [%i0+0x14]
F0022DE4: d0126006                 lduh    [%o1+6], %o0
F0022DE8: 900a3ffd                 and     %o0, -3, %o0
F0022DEC: 10800007                 ba      locret_F0022E08
F0022DF0: d0326006                 sth     %o0, [%o1+6]
F0022DF4: 7ffff4a9                 call    _soisdisconnected
F0022DF8: 01000000                 nop
F0022DFC: d0040000                 ld      [%l0], %o0
F0022E00: 7ffff4a6                 call    _soisdisconnected
F0022E04: c024200c                 clr     [%l0+0xC]
F0022E08: 81c7e008                 ret
F0022E0C: 81e80000                 restore
