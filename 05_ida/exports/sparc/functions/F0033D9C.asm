F0033D9C: 9de3bf98                 save    %sp, -0x68, %sp
F0033DA0: a4062014                 add     %i0, 0x14, %l2
F0033DA4: d00e0000                 ldub    [%i0], %o0
F0033DA8: 900a200f                 and     %o0, 0xF, %o0
F0033DAC: 912a2002                 sll     %o0, 2, %o0
F0033DB0: a0023fec                 add     %o0, -0x14, %l0
F0033DB4: 80a42000                 cmp     %l0, 0
F0033DB8: 04800018                 ble     loc_F0033E18
F0033DBC: a2066014                 add     %i1, 0x14, %l1
F0033DC0: d00c8000                 ldub    [%l2], %o0
F0033DC4: 80a22000                 cmp     %o0, 0
F0033DC8: 02800014                 be      loc_F0033E18
F0033DCC: 80a22001                 cmp     %o0, 1
F0033DD0: 32800003                 bne,a   loc_F0033DDC
F0033DD4: f00ca001                 ldub    [%l2+1], %i0
F0033DD8: b0102001                 mov     1, %i0
F0033DDC: 80a60010                 cmp     %i0, %l0
F0033DE0: 34800002                 bg,a    loc_F0033DE8
F0033DE4: b0100010                 mov     %l0, %i0
F0033DE8: 808a2080                 btst    0x80, %o0
F0033DEC: 22800008                 be,a    loc_F0033E0C
F0033DF0: a0240018                 sub     %l0, %i0, %l0
F0033DF4: 90100012                 mov     %l2, %o0! void *
F0033DF8: 92100011                 mov     %l1, %o1! void *
F0033DFC: 40018345                 call    _bcopy
F0033E00: 94100018                 mov     %i0, %o2
F0033E04: a2044018                 add     %l1, %i0, %l1
F0033E08: a0240018                 sub     %l0, %i0, %l0
F0033E0C: 80a42000                 cmp     %l0, 0
F0033E10: 14bfffec                 bg      loc_F0033DC0
F0033E14: a4048018                 add     %l2, %i0, %l2
F0033E18: 90047fec                 add     %l1, -0x14, %o0
F0033E1C: b0220019                 sub     %o0, %i1, %i0
F0033E20: 808e2003                 btst    3, %i0
F0033E24: 02800007                 be      locret_F0033E40
F0033E28: 01000000                 nop
F0033E2C: c02c4000                 clrb    [%l1]
F0033E30: b0062001                 inc     %i0
F0033E34: 808e2003                 btst    3, %i0
F0033E38: 12bffffd                 bne     loc_F0033E2C
F0033E3C: a2046001                 inc     %l1
F0033E40: 81c7e008                 ret
F0033E44: 81e80000                 restore
