F0054EC0: 9de3bf98                 save    %sp, -0x68, %sp
F0054EC4: 80a60019                 cmp     %i0, %i1
F0054EC8: 1a800053                 bcc     locret_F0055014
F0054ECC: 01000000                 nop
F0054ED0: d0060000                 ld      [%i0], %o0
F0054ED4: ab322003                 srl     %o0, 3, %l5
F0054ED8: 808a2004                 btst    4, %o0
F0054EDC: 02800007                 be      loc_F0054EF8
F0054EE0: aa0d6001                 and     %l5, 1, %l5
F0054EE4: ec162004                 lduh    [%i0+4], %l6
F0054EE8: d2162006                 lduh    [%i0+6], %o1
F0054EEC: e4062008                 ld      [%i0+8], %l2
F0054EF0: 10800008                 ba      loc_F0054F10
F0054EF4: b006200c                 inc     0xC, %i0
F0054EF8: ec0e0000                 ldub    [%i0], %l6
F0054EFC: 93322010                 srl     %o0, 16, %o1
F0054F00: 920a60ff                 and     %o1, 0xFF, %o1
F0054F04: a5322004                 srl     %o0, 4, %l2
F0054F08: a40cafff                 and     %l2, 0xFFF, %l2
F0054F0C: b0062004                 inc     4, %i0
F0054F10: 7ffec57c                 call    _umul
F0054F14: 90100012                 mov     %l2, %o0
F0054F18: a605bff0                 add     %l6, -0x10, %l3
F0054F1C: 80a4e005                 cmp     %l3, 5
F0054F20: 28800003                 bleu,a  loc_F0054F2C
F0054F24: a6102001                 mov     1, %l3
F0054F28: a6102000                 mov     0, %l3
F0054F2C: 80a4e000                 cmp     %l3, 0
F0054F30: 90022007                 inc     7, %o0
F0054F34: 02800022                 be      loc_F0054FBC
F0054F38: a9322003                 srl     %o0, 3, %l4
F0054F3C: 80a56000                 cmp     %l5, 0
F0054F40: 0280000c                 be      loc_F0054F70
F0054F44: 912ca002                 sll     %l2, 2, %o0
F0054F48: 90060008                 add     %i0, %o0, %o0
F0054F4C: 80a64008                 cmp     %i1, %o0
F0054F50: 1a800009                 bcc     loc_F0054F74
F0054F54: ae100018                 mov     %i0, %l7
F0054F58: 90023ffc                 inc     -4, %o0
F0054F5C: 80a64008                 cmp     %i1, %o0
F0054F60: 0abffffe                 bcs     loc_F0054F58
F0054F64: a404bfff                 inc     -1, %l2
F0054F68: 10800004                 ba      loc_F0054F78
F0054F6C: a2102000                 mov     0, %l1
F0054F70: ee060000                 ld      [%i0], %l7
F0054F74: a2102000                 mov     0, %l1
F0054F78: 80a44012                 cmp     %l1, %l2
F0054F7C: 1a800011                 bcc     loc_F0054FC0
F0054F80: 80a56000                 cmp     %l5, 0
F0054F84: a0102000                 mov     0, %l0
F0054F88: d0040017                 ld      [%l0+%l7], %o0
F0054F8C: 80a22000                 cmp     %o0, 0
F0054F90: 22800008                 be,a    loc_F0054FB0
F0054F94: a2046001                 inc     %l1
F0054F98: 80a23fff                 cmp     %o0, -1
F0054F9C: 22800005                 be,a    loc_F0054FB0
F0054FA0: a2046001                 inc     %l1
F0054FA4: 4000133e                 call    _ipc_object_destroy
F0054FA8: 92100016                 mov     %l6, %o1
F0054FAC: a2046001                 inc     %l1
F0054FB0: 80a44012                 cmp     %l1, %l2
F0054FB4: 0abffff5                 bcs     loc_F0054F88
F0054FB8: a0042004                 inc     4, %l0
F0054FBC: 80a56000                 cmp     %l5, 0
F0054FC0: 02800005                 be      loc_F0054FD4
F0054FC4: 90052003                 add     %l4, 3, %o0
F0054FC8: 900a3ffc                 and     %o0, -4, %o0
F0054FCC: 10bfffbe                 ba      loc_F0054EC4
F0054FD0: b0060008                 add     %i0, %o0, %i0
F0054FD4: 80a52000                 cmp     %l4, 0
F0054FD8: 0280000d                 be      loc_F005500C
F0054FDC: d2060000                 ld      [%i0], %o1
F0054FE0: 80a4e000                 cmp     %l3, 0
F0054FE4: 02800006                 be      loc_F0054FFC
F0054FE8: 90100009                 mov     %o1, %o0
F0054FEC: 40004c6d                 call    _kfree
F0054FF0: 92100014                 mov     %l4, %o1! address
F0054FF4: 10bfffb4                 ba      loc_F0054EC4
F0054FF8: b0062004                 inc     4, %i0
F0054FFC: 113c04ef                 sethi   %hi(_ipc_soft_map), %o0
F0055000: d0022320                 ld      [%o0+%lo(_ipc_soft_map)], %o0! target_task
F0055004: 4000d627                 call    _vm_deallocate
F0055008: 94100014                 mov     %l4, %o2
F005500C: 10bfffae                 ba      loc_F0054EC4
F0055010: b0062004                 inc     4, %i0
F0055014: 81c7e008                 ret
F0055018: 81e80000                 restore
