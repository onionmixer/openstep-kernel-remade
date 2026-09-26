F00A9EE4: 9de3bf90                 save    %sp, -0x70, %sp
F00A9EE8: d4062004                 ld      [%i0+4], %o2
F00A9EEC: 113c0000                 sethi   -0x10000000, %o0
F00A9EF0: 80a2000a                 cmp     %o0, %o2
F00A9EF4: a2402000                 addc    %g0, 0, %l1
F00A9EF8: 80a46000                 cmp     %l1, 0
F00A9EFC: 02800006                 be      loc_F00A9F14
F00A9F00: 01000000                 nop
F00A9F04: 7ffd6be5                 call    _flush_windows
F00A9F08: e0028000                 ld      [%o2], %l0
F00A9F0C: 1080000b                 ba      loc_F00A9F38
F00A9F10: 9134201e                 srl     %l0, 30, %o0
F00A9F14: 7fff8038                 call    _fuword
F00A9F18: 9010000a                 mov     %o2, %o0
F00A9F1C: a0100008                 mov     %o0, %l0
F00A9F20: 80a43fff                 cmp     %l0, -1
F00A9F24: 2280002c                 be,a    locret_F00A9FD4
F00A9F28: b0103fff                 mov     -1, %i0
F00A9F2C: 7fffef43                 call    _flush_user_windows_to_stack
F00A9F30: 01000000                 nop
F00A9F34: 9134201e                 srl     %l0, 30, %o0
F00A9F38: 80a22003                 cmp     %o0, 3
F00A9F3C: 32800026                 bne,a   locret_F00A9FD4
F00A9F40: b0103fff                 mov     -1, %i0
F00A9F44: 91342017                 srl     %l0, 23, %o0
F00A9F48: 900a2003                 and     %o0, 3, %o0
F00A9F4C: 80a22003                 cmp     %o0, 3
F00A9F50: 0280001d                 be      loc_F00A9FC4
F00A9F54: a406200c                 add     %i0, 0xC, %l2
F00A9F58: 90100012                 mov     %l2, %o0
F00A9F5C: 9534200e                 srl     %l0, 14, %o2
F00A9F60: 940aa01f                 and     %o2, 0x1F, %o2
F00A9F64: 9607bff4                 add     %fp, var_C, %o3
F00A9F68: f0062044                 ld      [%i0+0x44], %i0
F00A9F6C: 98100011                 mov     %l1, %o4
F00A9F70: 4000001b                 call    sub_F00A9FDC
F00A9F74: 92100018                 mov     %i0, %o1
F00A9F78: 80a22000                 cmp     %o0, 0
F00A9F7C: 32800016                 bne,a   locret_F00A9FD4
F00A9F80: b0103fff                 mov     -1, %i0
F00A9F84: 9134200d                 srl     %l0, 13, %o0
F00A9F88: 808a2001                 btst    1, %o0
F00A9F8C: 02800005                 be      loc_F00A9FA0
F00A9F90: 932c2013                 sll     %l0, 19, %o1
F00A9F94: d007bff4                 ld      [%fp+var_C], %o0
F00A9F98: 1080000e                 ba      loc_F00A9FD0
F00A9F9C: 933a6013                 sra     %o1, 19, %o1
F00A9FA0: 90100012                 mov     %l2, %o0
F00A9FA4: 92100018                 mov     %i0, %o1
F00A9FA8: 940c201f                 and     %l0, 0x1F, %o2
F00A9FAC: 9607bff0                 add     %fp, var_10, %o3
F00A9FB0: 4000000b                 call    sub_F00A9FDC
F00A9FB4: 98100011                 mov     %l1, %o4
F00A9FB8: 80a22000                 cmp     %o0, 0
F00A9FBC: 02800004                 be      loc_F00A9FCC
F00A9FC0: d207bff4                 ld      [%fp+var_C], %o1
F00A9FC4: 10800004                 ba      locret_F00A9FD4
F00A9FC8: b0103fff                 mov     -1, %i0
F00A9FCC: d007bff0                 ld      [%fp+var_10], %o0
F00A9FD0: b0024008                 add     %o1, %o0, %i0
F00A9FD4: 81c7e008                 ret
F00A9FD8: 81e80000                 restore
