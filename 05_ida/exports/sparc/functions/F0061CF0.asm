F0061CF0: 9de3bf80                 save    %sp, -0x80, %sp! int
F0061CF4: 113c04d0                 sethi   %hi(_active_threads), %o0
F0061CF8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0061CFC: e60220c4                 ld      [%o0+0xC4], %l3
F0061D00: d40220c8                 ld      [%o0+0xC8], %o2
F0061D04: e40220cc                 ld      [%o0+0xCC], %l2
F0061D08: d60220d0                 ld      [%o0+0xD0], %o3
F0061D0C: 9a103fff                 mov     -1, %o5
F0061D10: e20220d8                 ld      [%o0+0xD8], %l1
F0061D14: 13000004                 sethi   0x1000, %o1
F0061D18: d80220dc                 ld      [%o0+0xDC], %o4
F0061D1C: 808a8009                 btst    %o1, %o2
F0061D20: 02800003                 be      loc_F0061D2C
F0061D24: 920aa100                 and     %o2, 0x100, %o1
F0061D28: 9a100012                 mov     %l2, %o5
F0061D2C: 9007bff4                 add     %fp, var_C, %o0
F0061D30: d023a05c                 st      %o0, [%sp+0x80+var_24]
F0061D34: 9007bff0                 add     %fp, var_10, %o0
F0061D38: d023a060                 st      %o0, [%sp+0x80+var_20]
F0061D3C: 9010000c                 mov     %o4, %o0
F0061D40: 9410000d                 mov     %o5, %o2
F0061D44: 1b3c0187                 sethi   %hi(_msg_receive_continue), %o5
F0061D48: 98102001                 mov     1, %o4! int
F0061D4C: 7fffdb5b                 call    _ipc_mqueue_receive
F0061D50: 9a1360f0                 bset    %lo(_msg_receive_continue), %o5! int
F0061D54: a0100008                 mov     %o0, %l0
F0061D58: 7fffde46                 call    _ipc_object_release
F0061D5C: 90100011                 mov     %l1, %o0
F0061D60: 80a42000                 cmp     %l0, 0
F0061D64: 0280000f                 be      loc_F0061DA0
F0061D68: 11040010                 sethi   0x10004000, %o0
F0061D6C: 90122004                 bset    4, %o0
F0061D70: 80a40008                 cmp     %l0, %o0
F0061D74: 12800007                 bne     loc_F0061D90
F0061D78: 9007bfec                 add     %fp, var_14, %o0! int
F0061D7C: 9204e004                 add     %l3, 4, %o1! int
F0061D80: d607bff4                 ld      [%fp+var_C], %o3! int
F0061D84: 94102004                 mov     4, %o2! int
F0061D88: 4000d8d1                 call    _copyout
F0061D8C: d627bfec                 st      %o3, [%fp+var_14]
F0061D90: 7ffffd34                 call    _msg_return_translate
F0061D94: 90100010                 mov     %l0, %o0
F0061D98: 4000e89d                 call    _thread_syscall_return
F0061D9C: 01000000                 nop
F0061DA0: d207bff4                 ld      [%fp+var_C], %o1
F0061DA4: d0026018                 ld      [%o1+0x18], %o0
F0061DA8: 80a20012                 cmp     %o0, %l2
F0061DAC: 28800007                 bleu,a  loc_F0061DC8
F0061DB0: 133c04d0                 sethi   -0xFECC000, %o1
F0061DB4: 7fffcc1d                 call    _ipc_kmsg_destroy
F0061DB8: 90100009                 mov     %o1, %o0
F0061DBC: 4000e894                 call    _thread_syscall_return
F0061DC0: 90103f34                 mov     -0xCC, %o0
F0061DC4: 133c04d0                 sethi   -0xFECC000, %o1
F0061DC8: d2026260                 ld      [%o1+0x260], %o1
F0061DCC: d007bff4                 ld      [%fp+var_C], %o0
F0061DD0: d402600c                 ld      [%o1+0xC], %o2
F0061DD4: d202a088                 ld      [%o2+0x88], %o1
F0061DD8: 7fffd6cd                 call    _ipc_kmsg_copyout_compat
F0061DDC: d402a00c                 ld      [%o2+0xC], %o2
F0061DE0: d207bff4                 ld      [%fp+var_C], %o1
F0061DE4: d4026018                 ld      [%o1+0x18], %o2
F0061DE8: d6026010                 ld      [%o1+0x10], %o3
F0061DEC: 90100013                 mov     %l3, %o0
F0061DF0: 9402800b                 add     %o2, %o3, %o2
F0061DF4: 7fffcd6b                 call    _ipc_kmsg_put
F0061DF8: d4226018                 st      %o2, [%o1+0x18]
F0061DFC: 7ffffd19                 call    _msg_return_translate
F0061E00: 01000000                 nop
F0061E04: 4000e882                 call    _thread_syscall_return
F0061E08: 01000000                 nop
F0061E0C: 81c7e008                 ret
F0061E10: 81e80000                 restore
