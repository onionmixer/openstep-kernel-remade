F0056C90: 9de3bf90                 save    %sp, -0x70, %sp
F0056C94: 80a66000                 cmp     %i1, 0
F0056C98: 02800004                 be      loc_F0056CA8
F0056C9C: 80a67fff                 cmp     %i1, -1
F0056CA0: 12800004                 bne     loc_F0056CB0
F0056CA4: 80a6a011                 cmp     %i2, 0x11
F0056CA8: 10800056                 ba      loc_F0056E00
F0056CAC: f226c000                 st      %i1, [%i3]
F0056CB0: 12800040                 bne     loc_F0056DB0
F0056CB4: 90100018                 mov     %i0, %o0
F0056CB8: a2100019                 mov     %i1, %l1
F0056CBC: a0062008                 add     %i0, 8, %l0
F0056CC0: d0040000                 ld      [%l0], %o0
F0056CC4: 80a22000                 cmp     %o0, 0
F0056CC8: 12bffffe                 bne     loc_F0056CC0
F0056CCC: 01000000                 nop
F0056CD0: 40010076                 call    _simple_lock_try
F0056CD4: 90100010                 mov     %l0, %o0
F0056CD8: 80a22000                 cmp     %o0, 0
F0056CDC: 02bffff9                 be      loc_F0056CC0
F0056CE0: 01000000                 nop
F0056CE4: d006200c                 ld      [%i0+0xC], %o0
F0056CE8: 80a22000                 cmp     %o0, 0
F0056CEC: 12800005                 bne     loc_F0056D00
F0056CF0: 01000000                 nop
F0056CF4: c0262008                 clr     [%i0+8]
F0056CF8: 1080002e                 ba      loc_F0056DB0
F0056CFC: 90100018                 mov     %i0, %o0
F0056D00: d0044000                 ld      [%l1], %o0
F0056D04: 80a22000                 cmp     %o0, 0
F0056D08: 12bffffe                 bne     loc_F0056D00
F0056D0C: 01000000                 nop
F0056D10: 40010066                 call    _simple_lock_try
F0056D14: 90100011                 mov     %l1, %o0
F0056D18: 80a22000                 cmp     %o0, 0
F0056D1C: 02bffff9                 be      loc_F0056D00
F0056D20: 01000000                 nop
F0056D24: d0046008                 ld      [%l1+8], %o0
F0056D28: 80a22000                 cmp     %o0, 0
F0056D2C: 16800009                 bge     loc_F0056D50
F0056D30: 90100018                 mov     %i0, %o0
F0056D34: 92100011                 mov     %l1, %o1
F0056D38: 9410001b                 mov     %i3, %o2
F0056D3C: 7ffff6b2                 call    _ipc_hash_local_lookup
F0056D40: 9607bff4                 add     %fp, var_C, %o3
F0056D44: 80a22000                 cmp     %o0, 0
F0056D48: 32800006                 bne,a   loc_F0056D60
F0056D4C: d004601c                 ld      [%l1+0x1C], %o0
F0056D50: c0244000                 clr     [%l1]
F0056D54: c0262008                 clr     [%i0+8]
F0056D58: 10800016                 ba      loc_F0056DB0
F0056D5C: 90100018                 mov     %i0, %o0
F0056D60: 90023fff                 inc     -1, %o0
F0056D64: d024601c                 st      %o0, [%l1+0x1C]
F0056D68: d0046004                 ld      [%l1+4], %o0
F0056D6C: 90023fff                 inc     -1, %o0
F0056D70: d0246004                 st      %o0, [%l1+4]
F0056D74: c0244000                 clr     [%l1]
F0056D78: d607bff4                 ld      [%fp+var_C], %o3
F0056D7C: 1300003f                 sethi   0xFC00, %o1
F0056D80: d002c000                 ld      [%o3], %o0
F0056D84: 921263ff                 bset    0x3FF, %o1
F0056D88: 94022001                 add     %o0, 1, %o2
F0056D8C: 920a8009                 and     %o2, %o1, %o1
F0056D90: 1100003f901223fe         set     0xFFFE, %o0
F0056D98: 80a24008                 cmp     %o1, %o0
F0056D9C: 28800002                 bleu,a  loc_F0056DA4
F0056DA0: d422c000                 st      %o2, [%o3]
F0056DA4: c0262008                 clr     [%i0+8]
F0056DA8: 10800017                 ba      locret_F0056E04
F0056DAC: b0102000                 mov     0, %i0
F0056DB0: 92100019                 mov     %i1, %o1
F0056DB4: 9410001a                 mov     %i2, %o2
F0056DB8: 96102001                 mov     1, %o3
F0056DBC: 40000bce                 call    _ipc_object_copyout
F0056DC0: 9810001b                 mov     %i3, %o4
F0056DC4: a0920000                 orcc    %o0, %g0, %l0
F0056DC8: 0280000e                 be      loc_F0056E00
F0056DCC: 90100019                 mov     %i1, %o0
F0056DD0: 40000bb3                 call    _ipc_object_destroy
F0056DD4: 9210001a                 mov     %i2, %o1
F0056DD8: 80a42014                 cmp     %l0, 0x14
F0056DDC: 02800007                 be      loc_F0056DF8
F0056DE0: 80a42006                 cmp     %l0, 6
F0056DE4: c026c000                 clr     [%i3]
F0056DE8: 12800007                 bne     locret_F0056E04
F0056DEC: 31000008                 sethi   0x2000, %i0
F0056DF0: 10800005                 ba      locret_F0056E04
F0056DF4: b0102800                 mov     0x800, %i0
F0056DF8: 90103fff                 mov     -1, %o0
F0056DFC: d026c000                 st      %o0, [%i3]
F0056E00: b0102000                 mov     0, %i0
F0056E04: 81c7e008                 ret
F0056E08: 81e80000                 restore
