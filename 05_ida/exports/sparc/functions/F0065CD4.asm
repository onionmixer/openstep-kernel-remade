F0065CD4: 9de3bf90                 save    %sp, -0x70, %sp
F0065CD8: d4062004                 ld      [%i0+4], %o2
F0065CDC: 113c04d0                 sethi   %hi(_active_threads), %o0
F0065CE0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0065CE4: 9202a003                 add     %o2, 3, %o1
F0065CE8: 960a7ffc                 and     %o1, -4, %o3
F0065CEC: d202200c                 ld      [%o0+0xC], %o1
F0065CF0: 9422800b                 sub     %o2, %o3, %o2
F0065CF4: e2026088                 ld      [%o1+0x88], %l1
F0065CF8: 11000008                 sethi   0x2000, %o0
F0065CFC: 80a2c008                 cmp     %o3, %o0
F0065D00: 08800004                 bleu    loc_F0065D10
F0065D04: e002600c                 ld      [%o1+0xC], %l0
F0065D08: 10800053                 ba      locret_F0065E54
F0065D0C: b0103f93                 mov     -0x6D, %i0
F0065D10: 90100018                 mov     %i0, %o0
F0065D14: 9210000b                 mov     %o3, %o1
F0065D18: 7fffbd8c                 call    _ipc_kmsg_get_from_kernel
F0065D1C: 9607bff4                 add     %fp, var_C, %o3
F0065D20: b0920000                 orcc    %o0, %g0, %i0
F0065D24: 22800007                 be,a    loc_F0065D40
F0065D28: d007bff4                 ld      [%fp+var_C], %o0
F0065D2C: 30800047                 ba,a    loc_F0065E48
F0065D30: 4000091c                 call    _kfree
F0065D34: 01000000                 nop
F0065D38: 10800044                 ba      loc_F0065E48
F0065D3C: 90100018                 mov     %i0, %o0
F0065D40: 92100011                 mov     %l1, %o1
F0065D44: 7fffc542                 call    _ipc_kmsg_copyin_compat
F0065D48: 94100010                 mov     %l0, %o2
F0065D4C: b0920000                 orcc    %o0, %g0, %i0
F0065D50: 0280000a                 be      loc_F0065D78
F0065D54: d007bff4                 ld      [%fp+var_C], %o0
F0065D58: d2022008                 ld      [%o0+8], %o1
F0065D5C: 80a26000                 cmp     %o1, 0
F0065D60: 14bffff4                 bg      loc_F0065D30
F0065D64: 01000000                 nop
F0065D68: 7fffbd26                 call    _ipc_kmsg_free
F0065D6C: 01000000                 nop
F0065D70: 10800036                 ba      loc_F0065E48
F0065D74: 90100018                 mov     %i0, %o0
F0065D78: 808e6002                 btst    2, %i1
F0065D7C: 02800006                 be      loc_F0065D94
F0065D80: 113c043e                 sethi   %hi(aMsgSendNotify), %o0! "msg_send notify"
F0065D84: 7ffebcfb                 call    _panic
F0065D88: 90122208                 bset    %lo(aMsgSendNotify), %o0! "msg_send notify"
F0065D8C: 1080002a                 ba      loc_F0065E34
F0065D90: 80a62000                 cmp     %i0, 0
F0065D94: 27000080                 sethi   0x20000, %l3
F0065D98: 900e6001                 and     %i1, 1, %o0
F0065D9C: a4200008                 neg     %o0, %l2
F0065DA0: 11040000a2122007         set     0x10000007, %l1
F0065DA8: 808e6020                 btst    0x20, %i1 ! ' '
F0065DAC: 02800007                 be      loc_F0065DC8
F0065DB0: 808e6001                 btst    1, %i1
F0065DB4: d007bff4                 ld      [%fp+var_C], %o0
F0065DB8: 02800006                 be      loc_F0065DD0
F0065DBC: 13000080                 sethi   0x20000, %o1
F0065DC0: 10800004                 ba      loc_F0065DD0
F0065DC4: 9214e010                 or      %l3, 0x10, %o1
F0065DC8: d007bff4                 ld      [%fp+var_C], %o0
F0065DCC: 920ca010                 and     %l2, 0x10, %o1
F0065DD0: 9410001a                 mov     %i2, %o2
F0065DD4: 7fffc9aa                 call    _ipc_mqueue_send
F0065DD8: 96102000                 mov     0, %o3
F0065DDC: b0100008                 mov     %o0, %i0
F0065DE0: 80a60011                 cmp     %i0, %l1
F0065DE4: 12800011                 bne     loc_F0065E28
F0065DE8: 133c04d0                 sethi   %hi(_active_threads), %o1
F0065DEC: d0026260                 ld      [%o1+%lo(_active_threads)], %o0
F0065DF0: d002218c                 ld      [%o0+0x18C], %o0
F0065DF4: 808a2003                 btst    3, %o0
F0065DF8: 0280000a                 be      loc_F0065E20
F0065DFC: 808e6004                 btst    4, %i1
F0065E00: a0100009                 mov     %o1, %l0
F0065E04: 40003c6f                 call    _thread_halt_self_with_continuation
F0065E08: 90102000                 mov     0, %o0
F0065E0C: d0042260                 ld      [%l0+0x260], %o0
F0065E10: d002218c                 ld      [%o0+0x18C], %o0
F0065E14: 808a2003                 btst    3, %o0
F0065E18: 12bffffb                 bne     loc_F0065E04
F0065E1C: 808e6004                 btst    4, %i1
F0065E20: 12800004                 bne     loc_F0065E30
F0065E24: 80a60011                 cmp     %i0, %l1
F0065E28: 02bfffe1                 be      loc_F0065DAC
F0065E2C: 808e6020                 btst    0x20, %i1 ! ' '
F0065E30: 80a62000                 cmp     %i0, 0
F0065E34: 02800005                 be      loc_F0065E48
F0065E38: 90100018                 mov     %i0, %o0
F0065E3C: 7fffbbfb                 call    _ipc_kmsg_destroy
F0065E40: d007bff4                 ld      [%fp+var_C], %o0
F0065E44: 90100018                 mov     %i0, %o0
F0065E48: 7fffed06                 call    _msg_return_translate
F0065E4C: 01000000                 nop
F0065E50: b0100008                 mov     %o0, %i0
F0065E54: 81c7e008                 ret
F0065E58: 81e80000                 restore
