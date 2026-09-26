F0098E88: 9de3bf90                 save    %sp, -0x70, %sp
F0098E8C: d0562008                 ldsh    [%i0+8], %o0
F0098E90: 80a64008                 cmp     %i1, %o0
F0098E94: 1480000d                 bg      loc_F0098EC8
F0098E98: a4102000                 mov     0, %l2
F0098E9C: 808e6001                 btst    1, %i1
F0098EA0: 1280000b                 bne     loc_F0098ECC
F0098EA4: a6102000                 mov     0, %l3
F0098EA8: d0062004                 ld      [%i0+4], %o0
F0098EAC: 933e6001                 sra     %i1, 1, %o1
F0098EB0: 7ffff613                 call    _ocsum
F0098EB4: 90060008                 add     %i0, %o0, %o0
F0098EB8: 3100003fb01623ff         set     0xFFFF, %i0
F0098EC0: 10800056                 ba      locret_F0099018
F0098EC4: b02e0008                 bclr    %o0, %i0
F0098EC8: a6102000                 mov     0, %l3
F0098ECC: a807bff6                 add     %fp, var_A, %l4
F0098ED0: d0062004                 ld      [%i0+4], %o0
F0098ED4: 80a4ffff                 cmp     %l3, -1
F0098ED8: 12800009                 bne     loc_F0098EFC
F0098EDC: a2060008                 add     %i0, %o0, %l1
F0098EE0: a2046001                 inc     %l1
F0098EE4: d20e0008                 ldub    [%i0+%o0], %o1
F0098EE8: b2067fff                 inc     -1, %i1
F0098EEC: d0562008                 ldsh    [%i0+8], %o0
F0098EF0: a4048009                 add     %l2, %o1, %l2
F0098EF4: 10800003                 ba      loc_F0098F00
F0098EF8: a6023fff                 add     %o0, -1, %l3
F0098EFC: e6562008                 ldsh    [%i0+8], %l3
F0098F00: 80a64013                 cmp     %i1, %l3
F0098F04: 16800003                 bge     loc_F0098F10
F0098F08: f0060000                 ld      [%i0], %i0
F0098F0C: a6100019                 mov     %i1, %l3
F0098F10: 80a4e000                 cmp     %l3, 0
F0098F14: 0480002a                 ble     loc_F0098FBC
F0098F18: b2264013                 sub     %i1, %l3, %i1
F0098F1C: 808c6001                 btst    1, %l1
F0098F20: 32800010                 bne,a   loc_F0098F60
F0098F24: a604ffff                 inc     -1, %l3
F0098F28: 90100011                 mov     %l1, %o0
F0098F2C: a13ce001                 sra     %l3, 1, %l0
F0098F30: 7ffff5f3                 call    _ocsum
F0098F34: 92100010                 mov     %l0, %o1
F0098F38: a4048008                 add     %l2, %o0, %l2
F0098F3C: a12c2001                 sll     %l0, 1, %l0
F0098F40: 808ce001                 btst    1, %l3
F0098F44: 0280001e                 be      loc_F0098FBC
F0098F48: a2044010                 add     %l1, %l0, %l1
F0098F4C: d00c4000                 ldub    [%l1], %o0
F0098F50: a6103fff                 mov     -1, %l3
F0098F54: 912a2008                 sll     %o0, 8, %o0
F0098F58: 10800019                 ba      loc_F0098FBC
F0098F5C: a4048008                 add     %l2, %o0, %l2
F0098F60: a13ce001                 sra     %l3, 1, %l0
F0098F64: d00c4000                 ldub    [%l1], %o0
F0098F68: 92100010                 mov     %l0, %o1
F0098F6C: 912a2008                 sll     %o0, 8, %o0
F0098F70: a4048008                 add     %l2, %o0, %l2
F0098F74: a2046001                 inc     %l1
F0098F78: 7ffff5e1                 call    _ocsum
F0098F7C: 90100011                 mov     %l1, %o0
F0098F80: d037bff6                 sth     %o0, [%fp+var_A]
F0098F84: 90100014                 mov     %l4, %o0! void *
F0098F88: 92100014                 mov     %l4, %o1! void *
F0098F8C: 4000059b                 call    _swab
F0098F90: 94102002                 mov     2, %o2
F0098F94: a12c2001                 sll     %l0, 1, %l0
F0098F98: a2044010                 add     %l1, %l0, %l1
F0098F9C: d017bff6                 lduh    [%fp+var_A], %o0
F0098FA0: 808ce001                 btst    1, %l3
F0098FA4: 02800005                 be      loc_F0098FB8
F0098FA8: a4048008                 add     %l2, %o0, %l2
F0098FAC: d00c4000                 ldub    [%l1], %o0
F0098FB0: 10800003                 ba      loc_F0098FBC
F0098FB4: a4048008                 add     %l2, %o0, %l2
F0098FB8: a6103fff                 mov     -1, %l3
F0098FBC: 80a66000                 cmp     %i1, 0
F0098FC0: 2280000e                 be,a    loc_F0098FF8
F0098FC4: 3100003f                 sethi   0xFC00, %i0
F0098FC8: 80a62000                 cmp     %i0, 0
F0098FCC: 02800008                 be      loc_F0098FEC
F0098FD0: 113c044d                 sethi   -0xFEECC00, %o0
F0098FD4: d0562008                 ldsh    [%i0+8], %o0
F0098FD8: 80a22000                 cmp     %o0, 0
F0098FDC: 32bfffbe                 bne,a   loc_F0098ED4
F0098FE0: d0062004                 ld      [%i0+4], %o0! char *
F0098FE4: 10bffff9                 ba      loc_F0098FC8
F0098FE8: f0060000                 ld      [%i0], %i0
F0098FEC: 7ffded9b                 call    _printf
F0098FF0: 90122120                 bset    0x120, %o0
F0098FF4: 3100003f                 sethi   0xFC00, %i0
F0098FF8: b01623ff                 bset    0x3FF, %i0
F0098FFC: 920c8018                 and     %l2, %i0, %o1
F0099000: 913ca010                 sra     %l2, 16, %o0
F0099004: a4024008                 add     %o1, %o0, %l2
F0099008: 920c8018                 and     %l2, %i0, %o1
F009900C: 913ca010                 sra     %l2, 16, %o0
F0099010: a4024008                 add     %o1, %o0, %l2
F0099014: b02e0012                 bclr    %l2, %i0
F0099018: 81c7e008                 ret
F009901C: 81e80000                 restore
