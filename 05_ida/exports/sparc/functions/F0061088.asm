F0061088: 9de3bf88                 save    %sp, -0x78, %sp
F006108C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0061090: d8022260                 ld      [%o0+%lo(_active_threads)], %o4
F0061094: d003200c                 ld      [%o4+0xC], %o0
F0061098: e60320c4                 ld      [%o4+0xC4], %l3
F006109C: e80320cc                 ld      [%o4+0xCC], %l4
F00610A0: 92102000                 mov     0, %o1
F00610A4: e00320d8                 ld      [%o4+0xD8], %l0
F00610A8: 94103fff                 mov     -1, %o2
F00610AC: e4022088                 ld      [%o0+0x88], %l2
F00610B0: 96102000                 mov     0, %o3
F00610B4: ea02200c                 ld      [%o0+0xC], %l5
F00610B8: 1b3c0184                 sethi   %hi(_mach_msg_continue), %o5
F00610BC: d00320dc                 ld      [%o4+0xDC], %o0
F00610C0: 9a136088                 bset    %lo(_mach_msg_continue), %o5
F00610C4: 9807bff4                 add     %fp, var_C, %o4
F00610C8: d823a05c                 st      %o4, [%sp+0x78+var_1C]
F00610CC: 9807bff0                 add     %fp, var_10, %o4
F00610D0: d823a060                 st      %o4, [%sp+0x78+var_18]
F00610D4: 7fffde79                 call    _ipc_mqueue_receive
F00610D8: 98102001                 mov     1, %o4
F00610DC: a2100008                 mov     %o0, %l1
F00610E0: 7fffe164                 call    _ipc_object_release
F00610E4: 90100010                 mov     %l0, %o0
F00610E8: 80a46000                 cmp     %l1, 0
F00610EC: 02800005                 be      loc_F0061100
F00610F0: d407bff4                 ld      [%fp+var_C], %o2
F00610F4: 4000ebc6                 call    _thread_syscall_return
F00610F8: 90100011                 mov     %l1, %o0
F00610FC: d407bff4                 ld      [%fp+var_C], %o2
F0061100: d007bff0                 ld      [%fp+var_10], %o0
F0061104: d202a018                 ld      [%o2+0x18], %o1
F0061108: 80a24014                 cmp     %o1, %l4
F006110C: 0880000c                 bleu    loc_F006113C
F0061110: d022a024                 st      %o0, [%o2+0x24]
F0061114: 9010000a                 mov     %o2, %o0
F0061118: 7fffd803                 call    _ipc_kmsg_copyout_dest
F006111C: 92100012                 mov     %l2, %o1
F0061120: 90100013                 mov     %l3, %o0
F0061124: d207bff4                 ld      [%fp+var_C], %o1
F0061128: 7fffd09e                 call    _ipc_kmsg_put
F006112C: 94102018                 mov     0x18, %o2
F0061130: 11040010                 sethi   0x10004000, %o0
F0061134: 4000ebb6                 call    _thread_syscall_return
F0061138: 90122004                 bset    4, %o0
F006113C: d007bff4                 ld      [%fp+var_C], %o0
F0061140: 92100012                 mov     %l2, %o1
F0061144: 94100015                 mov     %l5, %o2
F0061148: 7fffd7b8                 call    _ipc_kmsg_copyout
F006114C: 96102000                 mov     0, %o3
F0061150: a2920000                 orcc    %o0, %g0, %l1
F0061154: 02800017                 be      loc_F00611B0
F0061158: 1300000f                 sethi   0x3C00, %o1
F006115C: 922c4009                 andn    %l1, %o1, %o1
F0061160: 110400109012200c         set     0x1000400C, %o0
F0061168: 80a24008                 cmp     %o1, %o0
F006116C: 32800008                 bne,a   loc_F006118C
F0061170: d007bff4                 ld      [%fp+var_C], %o0
F0061174: d207bff4                 ld      [%fp+var_C], %o1
F0061178: d6026018                 ld      [%o1+0x18], %o3
F006117C: d4026010                 ld      [%o1+0x10], %o2
F0061180: 90100013                 mov     %l3, %o0
F0061184: 10800007                 ba      loc_F00611A0
F0061188: 9402c00a                 add     %o3, %o2, %o2
F006118C: 7fffd7e6                 call    _ipc_kmsg_copyout_dest
F0061190: 92100012                 mov     %l2, %o1
F0061194: 90100013                 mov     %l3, %o0
F0061198: d207bff4                 ld      [%fp+var_C], %o1
F006119C: 94102018                 mov     0x18, %o2
F00611A0: 7fffd080                 call    _ipc_kmsg_put
F00611A4: 01000000                 nop
F00611A8: 4000eb99                 call    _thread_syscall_return
F00611AC: 90100011                 mov     %l1, %o0
F00611B0: d207bff4                 ld      [%fp+var_C], %o1
F00611B4: d6026018                 ld      [%o1+0x18], %o3
F00611B8: d4026010                 ld      [%o1+0x10], %o2
F00611BC: 90100013                 mov     %l3, %o0
F00611C0: 7fffd078                 call    _ipc_kmsg_put
F00611C4: 9402c00a                 add     %o3, %o2, %o2
F00611C8: 4000eb91                 call    _thread_syscall_return
F00611CC: 01000000                 nop
F00611D0: 81c7e008                 ret
F00611D4: 81e80000                 restore
