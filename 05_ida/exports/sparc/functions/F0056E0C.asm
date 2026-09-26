F0056E0C: 9de3bf90                 save    %sp, -0x70, %sp
F0056E10: b8100019                 mov     %i1, %i4
F0056E14: ba10001a                 mov     %i2, %i5
F0056E18: ae102000                 mov     0, %l7
F0056E1C: 80a6001c                 cmp     %i0, %i4
F0056E20: 1a800080                 bcc     locret_F0057020
F0056E24: a0100018                 mov     %i0, %l0
F0056E28: d0060000                 ld      [%i0], %o0
F0056E2C: b2100018                 mov     %i0, %i1
F0056E30: ab322003                 srl     %o0, 3, %l5
F0056E34: b5322002                 srl     %o0, 2, %i2
F0056E38: b48ea001                 andcc   %i2, 1, %i2
F0056E3C: 02800007                 be      loc_F0056E58
F0056E40: aa0d6001                 and     %l5, 1, %l5
F0056E44: ec162004                 lduh    [%i0+4], %l6
F0056E48: d2162006                 lduh    [%i0+6], %o1
F0056E4C: e6062008                 ld      [%i0+8], %l3
F0056E50: 10800008                 ba      loc_F0056E70
F0056E54: b006200c                 inc     0xC, %i0
F0056E58: ec0e0000                 ldub    [%i0], %l6
F0056E5C: 93322010                 srl     %o0, 16, %o1
F0056E60: 920a60ff                 and     %o1, 0xFF, %o1
F0056E64: a7322004                 srl     %o0, 4, %l3
F0056E68: a60cefff                 and     %l3, 0xFFF, %l3
F0056E6C: b0062004                 inc     4, %i0
F0056E70: 7ffebda4                 call    _umul
F0056E74: 90100013                 mov     %l3, %o0
F0056E78: a805bff0                 add     %l6, -0x10, %l4
F0056E7C: 80a52005                 cmp     %l4, 5
F0056E80: 28800003                 bleu,a  loc_F0056E8C
F0056E84: a8102001                 mov     1, %l4
F0056E88: a8102000                 mov     0, %l4
F0056E8C: 80a52000                 cmp     %l4, 0
F0056E90: 90022007                 inc     7, %o0
F0056E94: 02800026                 be      loc_F0056F2C
F0056E98: a5322003                 srl     %o0, 3, %l2
F0056E9C: 80a56000                 cmp     %l5, 0
F0056EA0: 12800014                 bne     loc_F0056EF0
F0056EA4: 96100018                 mov     %i0, %o3! flags
F0056EA8: 80a4a000                 cmp     %l2, 0
F0056EAC: 0280000d                 be      loc_F0056EE0
F0056EB0: 9010001b                 mov     %i3, %o0! target_task
F0056EB4: 9207bff4                 add     %fp, var_C, %o1! address
F0056EB8: 94100012                 mov     %l2, %o2! size
F0056EBC: 4000ce59                 call    _vm_allocate
F0056EC0: 96102001                 mov     1, %o3
F0056EC4: a2920000                 orcc    %o0, %g0, %l1
F0056EC8: 02800006                 be      loc_F0056EE0
F0056ECC: 90100010                 mov     %l0, %o0
F0056ED0: 7ffff7fc                 call    _ipc_kmsg_clean_body
F0056ED4: 92100018                 mov     %i0, %o1
F0056ED8: 10800040                 ba      loc_F0056FD8
F0056EDC: 80a6a000                 cmp     %i2, 0
F0056EE0: 80a56000                 cmp     %l5, 0
F0056EE4: 12800003                 bne     loc_F0056EF0
F0056EE8: 96100018                 mov     %i0, %o3
F0056EEC: d6060000                 ld      [%i0], %o3
F0056EF0: a2102000                 mov     0, %l1
F0056EF4: 80a44013                 cmp     %l1, %l3
F0056EF8: 1a80000e                 bcc     loc_F0056F30
F0056EFC: 80a56000                 cmp     %l5, 0
F0056F00: a010000b                 mov     %o3, %l0
F0056F04: 9010001d                 mov     %i5, %o0
F0056F08: d2040000                 ld      [%l0], %o1
F0056F0C: 94100016                 mov     %l6, %o2
F0056F10: 96100010                 mov     %l0, %o3
F0056F14: 7fffff5f                 call    _ipc_kmsg_copyout_object
F0056F18: a2046001                 inc     %l1
F0056F1C: ae15c008                 bset    %o0, %l7
F0056F20: 80a44013                 cmp     %l1, %l3
F0056F24: 0abffff8                 bcs     loc_F0056F04
F0056F28: a0042004                 inc     4, %l0
F0056F2C: 80a56000                 cmp     %l5, 0
F0056F30: 02800008                 be      loc_F0056F50
F0056F34: 9004a003                 add     %l2, 3, %o0
F0056F38: d2064000                 ld      [%i1], %o1
F0056F3C: 900a3ffc                 and     %o0, -4, %o0
F0056F40: b0060008                 add     %i0, %o0, %i0
F0056F44: 920a7ffd                 and     %o1, -3, %o1
F0056F48: 10bfffb5                 ba      loc_F0056E1C
F0056F4C: d2264000                 st      %o1, [%i1]
F0056F50: 80a4a000                 cmp     %l2, 0
F0056F54: 12800004                 bne     loc_F0056F64
F0056F58: e0060000                 ld      [%i0], %l0
F0056F5C: 1080002a                 ba      loc_F0057004
F0056F60: c027bff4                 clr     [%fp+var_C]
F0056F64: 80a52000                 cmp     %l4, 0
F0056F68: 0280000b                 be      loc_F0056F94
F0056F6C: 9010001b                 mov     %i3, %o0
F0056F70: 92100010                 mov     %l0, %o1
F0056F74: d407bff4                 ld      [%fp+var_C], %o2
F0056F78: 4000b2f8                 call    _copyoutmap
F0056F7C: 96100012                 mov     %l2, %o3
F0056F80: 90100010                 mov     %l0, %o0
F0056F84: 40004487                 call    _kfree
F0056F88: 92100012                 mov     %l2, %o1
F0056F8C: 1080001f                 ba      loc_F0057008
F0056F90: d0064000                 ld      [%i1], %o0
F0056F94: 92100010                 mov     %l0, %o1
F0056F98: 9410001b                 mov     %i3, %o2! size
F0056F9C: 96100012                 mov     %l2, %o3
F0056FA0: 053c04ef                 sethi   %hi(_ipc_soft_map), %g2
F0056FA4: 98102000                 mov     0, %o4
F0056FA8: d000a320                 ld      [%g2+%lo(_ipc_soft_map)], %o0
F0056FAC: 4000bcb3                 call    _vm_move
F0056FB0: 9a07bff4                 add     %fp, var_C, %o5
F0056FB4: a2100008                 mov     %o0, %l1
F0056FB8: 92100010                 mov     %l0, %o1! address
F0056FBC: 053c04ef                 sethi   %hi(_ipc_soft_map), %g2
F0056FC0: d000a320                 ld      [%g2+%lo(_ipc_soft_map)], %o0! target_task
F0056FC4: 4000ce37                 call    _vm_deallocate
F0056FC8: 94100012                 mov     %l2, %o2
F0056FCC: 80a46000                 cmp     %l1, 0
F0056FD0: 0280000d                 be      loc_F0057004
F0056FD4: 80a6a000                 cmp     %i2, 0
F0056FD8: 02800004                 be      loc_F0056FE8
F0056FDC: c027bff4                 clr     [%fp+var_C]
F0056FE0: 10800003                 ba      loc_F0056FEC
F0056FE4: c0366006                 clrh    [%i1+6]
F0056FE8: c02e6001                 clrb    [%i1+1]
F0056FEC: 80a46006                 cmp     %l1, 6
F0056FF0: 12800004                 bne     loc_F0057000
F0056FF4: 11000004                 sethi   0x1000, %o0
F0056FF8: 10800003                 ba      loc_F0057004
F0056FFC: ae15e400                 bset    0x400, %l7
F0057000: ae15c008                 bset    %o0, %l7
F0057004: d0064000                 ld      [%i1], %o0
F0057008: d207bff4                 ld      [%fp+var_C], %o1
F005700C: 90122002                 bset    2, %o0
F0057010: d0264000                 st      %o0, [%i1]
F0057014: d2260000                 st      %o1, [%i0]
F0057018: 10bfff81                 ba      loc_F0056E1C
F005701C: b0062004                 inc     4, %i0
F0057020: 81c7e008                 ret
F0057024: 91e80017                 restore %g0, %l7, %o0
