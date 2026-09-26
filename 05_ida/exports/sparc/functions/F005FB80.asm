F005FB80: 9de3bf80                 save    %sp, -0x80, %sp! int
F005FB84: 113c04d0                 sethi   %hi(_active_threads), %o0
F005FB88: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F005FB8C: d202200c                 ld      [%o0+0xC], %o1
F005FB90: e40220c4                 ld      [%o0+0xC4], %l2
F005FB94: e20220c8                 ld      [%o0+0xC8], %l1
F005FB98: ea0220cc                 ld      [%o0+0xCC], %l5
F005FB9C: d60220d0                 ld      [%o0+0xD0], %o3
F005FBA0: ec0220d4                 ld      [%o0+0xD4], %l6
F005FBA4: e60220d8                 ld      [%o0+0xD8], %l3
F005FBA8: e8026088                 ld      [%o1+0x88], %l4
F005FBAC: ee02600c                 ld      [%o1+0xC], %l7
F005FBB0: 808c6800                 btst    0x800, %l1
F005FBB4: 02800021                 be      loc_F005FC38
F005FBB8: d20220dc                 ld      [%o0+0xDC], %o1
F005FBBC: 9007bff4                 add     %fp, var_10+4, %o0
F005FBC0: d023a05c                 st      %o0, [%sp+0x80+var_24]
F005FBC4: 9007bff0                 add     %fp, var_10, %o0
F005FBC8: d023a060                 st      %o0, [%sp+0x80+var_20]
F005FBCC: 90100009                 mov     %o1, %o0
F005FBD0: 920c6100                 and     %l1, 0x100, %o1
F005FBD4: 94100015                 mov     %l5, %o2
F005FBD8: 98102001                 mov     1, %o4! int
F005FBDC: 1b3c017e                 sethi   %hi(_mach_msg_receive_continue), %o5
F005FBE0: 7fffe3b6                 call    _ipc_mqueue_receive
F005FBE4: 9a136380                 bset    %lo(_mach_msg_receive_continue), %o5! int
F005FBE8: a0100008                 mov     %o0, %l0
F005FBEC: 7fffe6a1                 call    _ipc_object_release
F005FBF0: 90100013                 mov     %l3, %o0
F005FBF4: 80a42000                 cmp     %l0, 0
F005FBF8: 0280000d                 be      loc_F005FC2C
F005FBFC: 11040010                 sethi   0x10004000, %o0
F005FC00: 90122004                 bset    4, %o0
F005FC04: 80a40008                 cmp     %l0, %o0
F005FC08: 12800007                 bne     loc_F005FC24
F005FC0C: 9007bfec                 add     %fp, var_14, %o0! int
F005FC10: 9204a004                 add     %l2, 4, %o1! int
F005FC14: d607bff4                 ld      [%fp+var_10+4], %o3! int
F005FC18: 94102004                 mov     4, %o2! int
F005FC1C: 4000e12c                 call    _copyout
F005FC20: d627bfec                 st      %o3, [%fp+var_14]
F005FC24: 4000f0fa                 call    _thread_syscall_return
F005FC28: 90100010                 mov     %l0, %o0
F005FC2C: d01fbff0                 ldd     [%fp+var_10], %o0
F005FC30: 10800025                 ba      loc_F005FCC4
F005FC34: d0226024                 st      %o0, [%o1+0x24]
F005FC38: 9007bff4                 add     %fp, var_10+4, %o0
F005FC3C: d023a05c                 st      %o0, [%sp+0x80+var_24]
F005FC40: 9007bff0                 add     %fp, var_10, %o0
F005FC44: d023a060                 st      %o0, [%sp+0x80+var_20]
F005FC48: 90100009                 mov     %o1, %o0
F005FC4C: 920c6100                 and     %l1, 0x100, %o1
F005FC50: 94103fff                 mov     -1, %o2
F005FC54: 98102001                 mov     1, %o4
F005FC58: 1b3c017e                 sethi   %hi(_mach_msg_receive_continue), %o5
F005FC5C: 7fffe397                 call    _ipc_mqueue_receive
F005FC60: 9a136380                 bset    %lo(_mach_msg_receive_continue), %o5
F005FC64: a0100008                 mov     %o0, %l0
F005FC68: 7fffe682                 call    _ipc_object_release
F005FC6C: 90100013                 mov     %l3, %o0
F005FC70: 80a42000                 cmp     %l0, 0
F005FC74: 02800005                 be      loc_F005FC88
F005FC78: d407bff4                 ld      [%fp+var_10+4], %o2
F005FC7C: 4000f0e4                 call    _thread_syscall_return
F005FC80: 90100010                 mov     %l0, %o0
F005FC84: d407bff4                 ld      [%fp+var_10+4], %o2
F005FC88: d007bff0                 ld      [%fp+var_10], %o0
F005FC8C: d202a018                 ld      [%o2+0x18], %o1
F005FC90: 80a24015                 cmp     %o1, %l5
F005FC94: 0880000c                 bleu    loc_F005FCC4
F005FC98: d022a024                 st      %o0, [%o2+0x24]
F005FC9C: 9010000a                 mov     %o2, %o0
F005FCA0: 7fffdd21                 call    _ipc_kmsg_copyout_dest
F005FCA4: 92100014                 mov     %l4, %o1
F005FCA8: 90100012                 mov     %l2, %o0
F005FCAC: d207bff4                 ld      [%fp+var_10+4], %o1
F005FCB0: 7fffd5bc                 call    _ipc_kmsg_put
F005FCB4: 94102018                 mov     0x18, %o2
F005FCB8: 11040010                 sethi   0x10004000, %o0
F005FCBC: 4000f0d4                 call    _thread_syscall_return
F005FCC0: 90122004                 bset    4, %o0
F005FCC4: 808c6200                 btst    0x200, %l1
F005FCC8: 0280000b                 be      loc_F005FCF4
F005FCCC: 80a5a000                 cmp     %l6, 0
F005FCD0: 12800005                 bne     loc_F005FCE4
F005FCD4: d007bff4                 ld      [%fp+var_10+4], %o0
F005FCD8: 11040010                 sethi   0x10004000, %o0
F005FCDC: 1080000d                 ba      loc_F005FD10
F005FCE0: a0122007                 or      %o0, 7, %l0
F005FCE4: 92100014                 mov     %l4, %o1
F005FCE8: 94100017                 mov     %l7, %o2
F005FCEC: 10800006                 ba      loc_F005FD04
F005FCF0: 96100016                 mov     %l6, %o3
F005FCF4: d007bff4                 ld      [%fp+var_10+4], %o0
F005FCF8: 92100014                 mov     %l4, %o1
F005FCFC: 94100017                 mov     %l7, %o2
F005FD00: 96102000                 mov     0, %o3
F005FD04: 7fffdcc9                 call    _ipc_kmsg_copyout
F005FD08: 01000000                 nop
F005FD0C: a0100008                 mov     %o0, %l0
F005FD10: 80a42000                 cmp     %l0, 0
F005FD14: 02800017                 be      loc_F005FD70
F005FD18: 1300000f                 sethi   0x3C00, %o1
F005FD1C: 922c0009                 andn    %l0, %o1, %o1
F005FD20: 110400109012200c         set     0x1000400C, %o0
F005FD28: 80a24008                 cmp     %o1, %o0
F005FD2C: 32800008                 bne,a   loc_F005FD4C
F005FD30: d007bff4                 ld      [%fp+var_10+4], %o0
F005FD34: d207bff4                 ld      [%fp+var_10+4], %o1
F005FD38: d6026018                 ld      [%o1+0x18], %o3
F005FD3C: d4026010                 ld      [%o1+0x10], %o2
F005FD40: 90100012                 mov     %l2, %o0
F005FD44: 10800007                 ba      loc_F005FD60
F005FD48: 9402c00a                 add     %o3, %o2, %o2
F005FD4C: 7fffdcf6                 call    _ipc_kmsg_copyout_dest
F005FD50: 92100014                 mov     %l4, %o1
F005FD54: 90100012                 mov     %l2, %o0
F005FD58: d207bff4                 ld      [%fp+var_10+4], %o1
F005FD5C: 94102018                 mov     0x18, %o2
F005FD60: 7fffd590                 call    _ipc_kmsg_put
F005FD64: 01000000                 nop
F005FD68: 4000f0a9                 call    _thread_syscall_return
F005FD6C: 90100010                 mov     %l0, %o0
F005FD70: d207bff4                 ld      [%fp+var_10+4], %o1
F005FD74: d6026018                 ld      [%o1+0x18], %o3
F005FD78: d4026010                 ld      [%o1+0x10], %o2
F005FD7C: 90100012                 mov     %l2, %o0
F005FD80: 7fffd588                 call    _ipc_kmsg_put
F005FD84: 9402c00a                 add     %o3, %o2, %o2
F005FD88: 4000f0a1                 call    _thread_syscall_return
F005FD8C: 01000000                 nop
F005FD90: 81c7e008                 ret
F005FD94: 81e80000                 restore
