F0065E5C: 9de3bf80                 save    %sp, -0x80, %sp
F0065E60: 113c04d0                 sethi   %hi(_active_threads), %o0
F0065E64: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0065E68: ec06200c                 ld      [%i0+0xC], %l6
F0065E6C: d202200c                 ld      [%o0+0xC], %o1
F0065E70: aa0e6100                 and     %i1, 0x100, %l5
F0065E74: e6062004                 ld      [%i0+4], %l3
F0065E78: 11040010                 sethi   0x10004000, %o0
F0065E7C: e4026088                 ld      [%o1+0x88], %l2
F0065E80: a8122005                 or      %o0, 5, %l4
F0065E84: ee02600c                 ld      [%o1+0xC], %l7
F0065E88: 90100012                 mov     %l2, %o0
F0065E8C: 92100016                 mov     %l6, %o1
F0065E90: 9407bff4                 add     %fp, var_C, %o2
F0065E94: 7fffca9a                 call    _ipc_mqueue_copyin
F0065E98: 9607bff0                 add     %fp, var_10, %o3
F0065E9C: a0920000                 orcc    %o0, %g0, %l0
F0065EA0: 12800045                 bne     loc_F0065FB4
F0065EA4: 11000004                 sethi   0x1000, %o0
F0065EA8: 808e4008                 btst    %o0, %i1
F0065EAC: d207bff4                 ld      [%fp+var_C], %o1
F0065EB0: 02800003                 be      loc_F0065EBC
F0065EB4: 94103fff                 mov     -1, %o2
F0065EB8: 94100013                 mov     %l3, %o2
F0065EBC: 9007bfec                 add     %fp, var_14, %o0
F0065EC0: d023a05c                 st      %o0, [%sp+0x80+var_24]
F0065EC4: 9007bfe8                 add     %fp, var_18, %o0
F0065EC8: d023a060                 st      %o0, [%sp+0x80+var_20]
F0065ECC: 90100009                 mov     %o1, %o0
F0065ED0: 92100015                 mov     %l5, %o1
F0065ED4: 9610001a                 mov     %i2, %o3
F0065ED8: 98102000                 mov     0, %o4
F0065EDC: 7fffcaf7                 call    _ipc_mqueue_receive
F0065EE0: 9a102000                 mov     0, %o5
F0065EE4: a0100008                 mov     %o0, %l0
F0065EE8: 7fffcde2                 call    _ipc_object_release
F0065EEC: d007bff0                 ld      [%fp+var_10], %o0
F0065EF0: 80a40014                 cmp     %l0, %l4
F0065EF4: 12800011                 bne     loc_F0065F38
F0065EF8: 133c04d0                 sethi   %hi(_active_threads), %o1
F0065EFC: d0026260                 ld      [%o1+%lo(_active_threads)], %o0
F0065F00: d002218c                 ld      [%o0+0x18C], %o0
F0065F04: 808a2003                 btst    3, %o0
F0065F08: 0280000a                 be      loc_F0065F30
F0065F0C: 808e6400                 btst    0x400, %i1
F0065F10: a2100009                 mov     %o1, %l1
F0065F14: 40003c2b                 call    _thread_halt_self_with_continuation
F0065F18: 90102000                 mov     0, %o0
F0065F1C: d0046260                 ld      [%l1+0x260], %o0
F0065F20: d002218c                 ld      [%o0+0x18C], %o0
F0065F24: 808a2003                 btst    3, %o0
F0065F28: 12bffffb                 bne     loc_F0065F14
F0065F2C: 808e6400                 btst    0x400, %i1
F0065F30: 12800004                 bne     loc_F0065F40
F0065F34: 80a40014                 cmp     %l0, %l4
F0065F38: 02bfffd5                 be      loc_F0065E8C
F0065F3C: 90100012                 mov     %l2, %o0
F0065F40: 80a42000                 cmp     %l0, 0
F0065F44: 0280000a                 be      loc_F0065F6C
F0065F48: 11040010                 sethi   0x10004000, %o0
F0065F4C: 90122004                 bset    4, %o0
F0065F50: 80a40008                 cmp     %l0, %o0
F0065F54: 3280001e                 bne,a   loc_F0065FCC
F0065F58: 90100010                 mov     %l0, %o0
F0065F5C: d007bfec                 ld      [%fp+var_14], %o0
F0065F60: d0262004                 st      %o0, [%i0+4]
F0065F64: 1080001a                 ba      loc_F0065FCC
F0065F68: 90100010                 mov     %l0, %o0
F0065F6C: d207bfec                 ld      [%fp+var_14], %o1
F0065F70: d0026018                 ld      [%o1+0x18], %o0
F0065F74: 80a20013                 cmp     %o0, %l3
F0065F78: 18800011                 bgu     loc_F0065FBC
F0065F7C: 90100009                 mov     %o1, %o0
F0065F80: 92100012                 mov     %l2, %o1
F0065F84: 7fffc662                 call    _ipc_kmsg_copyout_compat
F0065F88: 94100017                 mov     %l7, %o2
F0065F8C: d207bfec                 ld      [%fp+var_14], %o1
F0065F90: d4026018                 ld      [%o1+0x18], %o2
F0065F94: a0100008                 mov     %o0, %l0
F0065F98: d6026010                 ld      [%o1+0x10], %o3
F0065F9C: 90100018                 mov     %i0, %o0
F0065FA0: 9402800b                 add     %o2, %o3, %o2
F0065FA4: 7fffbd20                 call    _ipc_kmsg_put_to_kernel
F0065FA8: d4226018                 st      %o2, [%o1+0x18]
F0065FAC: 10800008                 ba      loc_F0065FCC
F0065FB0: 90100010                 mov     %l0, %o0
F0065FB4: 10800006                 ba      loc_F0065FCC
F0065FB8: 90100010                 mov     %l0, %o0
F0065FBC: 7fffbb9b                 call    _ipc_kmsg_destroy
F0065FC0: 90100009                 mov     %o1, %o0
F0065FC4: 1104001090122004         set     0x10004004, %o0
F0065FCC: 7fffeca5                 call    _msg_return_translate
F0065FD0: 01000000                 nop
F0065FD4: 81c7e008                 ret
F0065FD8: 91e80008                 restore %g0, %o0, %o0
