F0055E50: 9de3bf80                 save    %sp, -0x80, %sp
F0055E54: f227bfec                 st      %i1, [%fp+var_14]
F0055E58: ba10001a                 mov     %i2, %i5
F0055E5C: 90062014                 add     %i0, 0x14, %o0
F0055E60: d207bfec                 ld      [%fp+var_14], %o1
F0055E64: 7ffffd80                 call    _ipc_kmsg_copyin_header
F0055E68: 9410001b                 mov     %i3, %o2
F0055E6C: 80a22000                 cmp     %o0, 0
F0055E70: 22800004                 be,a    loc_F0055E80
F0055E74: d0062014                 ld      [%i0+0x14], %o0
F0055E78: 108000e1                 ba      locret_F00561FC
F0055E7C: b0100008                 mov     %o0, %i0
F0055E80: 80a22000                 cmp     %o0, 0
F0055E84: 06800012                 bl      loc_F0055ECC
F0055E88: a4102000                 mov     0, %l2
F0055E8C: 108000dc                 ba      locret_F00561FC
F0055E90: b0102000                 mov     0, %i0
F0055E94: 90100018                 mov     %i0, %o0
F0055E98: 10800023                 ba      loc_F0055F24
F0055E9C: 9210001c                 mov     %i4, %o1
F0055EA0: 90100018                 mov     %i0, %o0
F0055EA4: 10800020                 ba      loc_F0055F24
F0055EA8: 9210001c                 mov     %i4, %o1
F0055EAC: 90100018                 mov     %i0, %o0
F0055EB0: 9210001c                 mov     %i4, %o1
F0055EB4: 94102001                 mov     1, %o2
F0055EB8: 7ffffc7c                 call    _ipc_kmsg_clean_partial
F0055EBC: 9610001b                 mov     %i3, %o3
F0055EC0: 31040000                 sethi   0x10000000, %i0
F0055EC4: 108000ce                 ba      locret_F00561FC
F0055EC8: b016200a                 bset    0xA, %i0
F0055ECC: c406201c                 ld      [%i0+0x1C], %g2
F0055ED0: c427bfe4                 st      %g2, [%fp+var_1C]
F0055ED4: d0062018                 ld      [%i0+0x18], %o0
F0055ED8: a206202c                 add     %i0, 0x2C, %l1 ! ','
F0055EDC: 90022014                 inc     0x14, %o0
F0055EE0: b4060008                 add     %i0, %o0, %i2
F0055EE4: 80a4401a                 cmp     %l1, %i2
F0055EE8: 1a8000bd                 bcc     loc_F00561DC
F0055EEC: 92268011                 sub     %i2, %l1, %o1
F0055EF0: 80a26003                 cmp     %o1, 3
F0055EF4: b8100011                 mov     %l1, %i4
F0055EF8: 08800009                 bleu    loc_F0055F1C
F0055EFC: a6100011                 mov     %l1, %l3
F0055F00: d0044000                 ld      [%l1], %o0
F0055F04: ad322002                 srl     %o0, 2, %l6
F0055F08: ac8da001                 andcc   %l6, 1, %l6
F0055F0C: 0280000c                 be      loc_F0055F3C
F0055F10: 80a2600b                 cmp     %o1, 0xB
F0055F14: 3880000b                 bgu,a   loc_F0055F40
F0055F18: d004c000                 ld      [%l3], %o0
F0055F1C: 90100018                 mov     %i0, %o0
F0055F20: 92100011                 mov     %l1, %o1
F0055F24: 94102000                 mov     0, %o2
F0055F28: 7ffffc60                 call    _ipc_kmsg_clean_partial
F0055F2C: 96102000                 mov     0, %o3
F0055F30: 31040000                 sethi   0x10000000, %i0
F0055F34: 108000b2                 ba      locret_F00561FC
F0055F38: b0162008                 bset    8, %i0
F0055F3C: d004c000                 ld      [%l3], %o0
F0055F40: 80a5a000                 cmp     %l6, 0
F0055F44: a1322003                 srl     %o0, 3, %l0
F0055F48: a00c2001                 and     %l0, 1, %l0
F0055F4C: a9322001                 srl     %o0, 1, %l4
F0055F50: 02800007                 be      loc_F0055F6C
F0055F54: a80d2001                 and     %l4, 1, %l4
F0055F58: f214e004                 lduh    [%l3+4], %i1
F0055F5C: d214e006                 lduh    [%l3+6], %o1
F0055F60: ee04e008                 ld      [%l3+8], %l7
F0055F64: 10800008                 ba      loc_F0055F84
F0055F68: a204600c                 inc     0xC, %l1
F0055F6C: f20cc000                 ldub    [%l3], %i1
F0055F70: 93322010                 srl     %o0, 16, %o1
F0055F74: 920a60ff                 and     %o1, 0xFF, %o1
F0055F78: af322004                 srl     %o0, 4, %l7
F0055F7C: ae0defff                 and     %l7, 0xFFF, %l7
F0055F80: a2046004                 inc     4, %l1
F0055F84: aa067ff0                 add     %i1, -0x10, %l5
F0055F88: 80a56005                 cmp     %l5, 5
F0055F8C: 28800003                 bleu,a  loc_F0055F98
F0055F90: aa102001                 mov     1, %l5
F0055F94: aa102000                 mov     0, %l5
F0055F98: 80a56000                 cmp     %l5, 0
F0055F9C: 02800004                 be      loc_F0055FAC
F0055FA0: 80a26020                 cmp     %o1, 0x20 ! ' '
F0055FA4: 12800011                 bne     loc_F0055FE8
F0055FA8: 90100018                 mov     %i0, %o0
F0055FAC: 80a5a000                 cmp     %l6, 0
F0055FB0: 02800006                 be      loc_F0055FC8
F0055FB4: d004c000                 ld      [%l3], %o0
F0055FB8: 808a3ff0                 btst    -0x10, %o0
F0055FBC: 1280000b                 bne     loc_F0055FE8
F0055FC0: 90100018                 mov     %i0, %o0
F0055FC4: d004c000                 ld      [%l3], %o0
F0055FC8: 808a2001                 btst    1, %o0
F0055FCC: 32800007                 bne,a   loc_F0055FE8
F0055FD0: 90100018                 mov     %i0, %o0
F0055FD4: 80a52000                 cmp     %l4, 0
F0055FD8: 0280000b                 be      loc_F0056004
F0055FDC: 80a42000                 cmp     %l0, 0
F0055FE0: 02800009                 be      loc_F0056004
F0055FE4: 90100018                 mov     %i0, %o0
F0055FE8: 9210001c                 mov     %i4, %o1
F0055FEC: 94102000                 mov     0, %o2
F0055FF0: 7ffffc2e                 call    _ipc_kmsg_clean_partial
F0055FF4: 96102000                 mov     0, %o3
F0055FF8: 31040000                 sethi   0x10000000, %i0
F0055FFC: 10800080                 ba      locret_F00561FC
F0056000: b016200f                 bset    0xF, %i0
F0056004: 7ffec13f                 call    _umul
F0056008: 90100017                 mov     %l7, %o0
F005600C: 80a42000                 cmp     %l0, 0
F0056010: 90022007                 inc     7, %o0
F0056014: 0280000a                 be      loc_F005603C
F0056018: a1322003                 srl     %o0, 3, %l0
F005601C: 90042003                 add     %l0, 3, %o0
F0056020: 920a3ffc                 and     %o0, -4, %o1
F0056024: 90268011                 sub     %i2, %l1, %o0
F0056028: 80a20009                 cmp     %o0, %o1
F005602C: 0abfff9a                 bcs     loc_F0055E94
F0056030: b6100011                 mov     %l1, %i3
F0056034: 1080003b                 ba      loc_F0056120
F0056038: a2044009                 add     %l1, %o1, %l1
F005603C: 90268011                 sub     %i2, %l1, %o0
F0056040: 80a22003                 cmp     %o0, 3
F0056044: 08bfff97                 bleu    loc_F0055EA0
F0056048: 80a42000                 cmp     %l0, 0
F005604C: 12800004                 bne     loc_F005605C
F0056050: e4044000                 ld      [%l1], %l2
F0056054: 10800030                 ba      loc_F0056114
F0056058: b6102000                 mov     0, %i3
F005605C: 80a56000                 cmp     %l5, 0
F0056060: 0280001b                 be      loc_F00560CC
F0056064: 9010001d                 mov     %i5, %o0
F0056068: 40004802                 call    _kalloc
F005606C: 90100010                 mov     %l0, %o0
F0056070: b6920000                 orcc    %o0, %g0, %i3
F0056074: 02800020                 be      loc_F00560F4
F0056078: 9010001d                 mov     %i5, %o0
F005607C: 92100012                 mov     %l2, %o1
F0056080: 9410001b                 mov     %i3, %o2! size
F0056084: 4000b69c                 call    _copyinmap
F0056088: 96100010                 mov     %l0, %o3
F005608C: 80a22000                 cmp     %o0, 0
F0056090: 3280000b                 bne,a   loc_F00560BC
F0056094: 9010001b                 mov     %i3, %o0
F0056098: 80a52000                 cmp     %l4, 0
F005609C: 0280001e                 be      loc_F0056114
F00560A0: 9010001d                 mov     %i5, %o0! target_task
F00560A4: 92100012                 mov     %l2, %o1! address
F00560A8: 4000d1fe                 call    _vm_deallocate
F00560AC: 94100010                 mov     %l0, %o2
F00560B0: 80a22000                 cmp     %o0, 0
F00560B4: 02800018                 be      loc_F0056114
F00560B8: 9010001b                 mov     %i3, %o0
F00560BC: 40004839                 call    _kfree
F00560C0: 92100010                 mov     %l0, %o1
F00560C4: 1080000d                 ba      loc_F00560F8
F00560C8: 90100018                 mov     %i0, %o0
F00560CC: 92100012                 mov     %l2, %o1
F00560D0: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F00560D4: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F00560D8: 96100010                 mov     %l0, %o3
F00560DC: 98100014                 mov     %l4, %o4
F00560E0: 4000c066                 call    _vm_move
F00560E4: 9a07bff4                 add     %fp, var_C, %o5
F00560E8: 80a22000                 cmp     %o0, 0
F00560EC: 0280000a                 be      loc_F0056114
F00560F0: f607bff4                 ld      [%fp+var_C], %i3
F00560F4: 90100018                 mov     %i0, %o0
F00560F8: 9210001c                 mov     %i4, %o1
F00560FC: 94102000                 mov     0, %o2
F0056100: 7ffffbea                 call    _ipc_kmsg_clean_partial
F0056104: 96102000                 mov     0, %o3
F0056108: 31040000                 sethi   0x10000000, %i0
F005610C: 1080003c                 ba      locret_F00561FC
F0056110: b016200c                 bset    0xC, %i0
F0056114: f6244000                 st      %i3, [%l1]
F0056118: a2046004                 inc     4, %l1
F005611C: a4102001                 mov     1, %l2
F0056120: 80a56000                 cmp     %l5, 0
F0056124: 02bfff71                 be      loc_F0055EE8
F0056128: 80a4401a                 cmp     %l1, %i2
F005612C: 40000e24                 call    _ipc_object_copyin_type
F0056130: 90100019                 mov     %i1, %o0
F0056134: 80a5a000                 cmp     %l6, 0
F0056138: a4100008                 mov     %o0, %l2
F005613C: 02800004                 be      loc_F005614C
F0056140: 9010001b                 mov     %i3, %o0
F0056144: 10800003                 ba      loc_F0056150
F0056148: e434e004                 sth     %l2, [%l3+4]
F005614C: e42cc000                 stb     %l2, [%l3]
F0056150: b6102000                 mov     0, %i3
F0056154: 80a6c017                 cmp     %i3, %l7
F0056158: 1a80001f                 bcc     loc_F00561D4
F005615C: a0100008                 mov     %o0, %l0
F0056160: d2040000                 ld      [%l0], %o1
F0056164: 80a26000                 cmp     %o1, 0
F0056168: 02800017                 be      loc_F00561C4
F005616C: 80a27fff                 cmp     %o1, -1
F0056170: 02800015                 be      loc_F00561C4
F0056174: d007bfec                 ld      [%fp+var_14], %o0
F0056178: 94100019                 mov     %i1, %o2
F005617C: 40000e3b                 call    _ipc_object_copyin
F0056180: 9607bff0                 add     %fp, var_10, %o3
F0056184: 80a22000                 cmp     %o0, 0
F0056188: 12bfff49                 bne     loc_F0055EAC
F005618C: 80a4a010                 cmp     %l2, 0x10
F0056190: 1280000c                 bne     loc_F00561C0
F0056194: d007bff0                 ld      [%fp+var_10], %o0
F0056198: 4000130b                 call    _ipc_port_check_circularity
F005619C: d207bfe4                 ld      [%fp+var_1C], %o1
F00561A0: 80a22000                 cmp     %o0, 0
F00561A4: 02800007                 be      loc_F00561C0
F00561A8: d007bff0                 ld      [%fp+var_10], %o0
F00561AC: d0062014                 ld      [%i0+0x14], %o0
F00561B0: 05100000                 sethi   0x40000000, %g2
F00561B4: 90120002                 bset    %g2, %o0
F00561B8: d0262014                 st      %o0, [%i0+0x14]
F00561BC: d007bff0                 ld      [%fp+var_10], %o0
F00561C0: d0240000                 st      %o0, [%l0]
F00561C4: b606e001                 inc     %i3
F00561C8: 80a6c017                 cmp     %i3, %l7
F00561CC: 0abfffe5                 bcs     loc_F0056160
F00561D0: a0042004                 inc     4, %l0
F00561D4: 10bfff44                 ba      loc_F0055EE4
F00561D8: a4102001                 mov     1, %l2
F00561DC: 80a4a000                 cmp     %l2, 0
F00561E0: 32800007                 bne,a   locret_F00561FC
F00561E4: b0102000                 mov     0, %i0
F00561E8: d2062014                 ld      [%i0+0x14], %o1
F00561EC: 11200000                 sethi   0x80000000, %o0
F00561F0: 902a4008                 andn    %o1, %o0, %o0
F00561F4: d0262014                 st      %o0, [%i0+0x14]
F00561F8: b0102000                 mov     0, %i0
F00561FC: 81c7e008                 ret
F0056200: 81e80000                 restore
