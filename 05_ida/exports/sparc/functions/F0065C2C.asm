F0065C2C: 9de3bf90                 save    %sp, -0x70, %sp
F0065C30: 90100018                 mov     %i0, %o0
F0065C34: d2022004                 ld      [%o0+4], %o1
F0065C38: 9607bff4                 add     %fp, var_C, %o3
F0065C3C: 94100009                 mov     %o1, %o2
F0065C40: 9202a003                 add     %o2, 3, %o1
F0065C44: 920a7ffc                 and     %o1, -4, %o1
F0065C48: 7fffbdc0                 call    _ipc_kmsg_get_from_kernel
F0065C4C: 94228009                 sub     %o2, %o1, %o2
F0065C50: b0920000                 orcc    %o0, %g0, %i0
F0065C54: 1280001c                 bne     loc_F0065CC4
F0065C58: 01000000                 nop
F0065C5C: 7fffc691                 call    _ipc_kmsg_copyin_compat_from_kernel
F0065C60: d007bff4                 ld      [%fp+var_C], %o0
F0065C64: 808e6002                 btst    2, %i1
F0065C68: 02800006                 be      loc_F0065C80
F0065C6C: 113c043e                 sethi   %hi(aMsgSendFromKer), %o0! "msg_send_from_kernel"
F0065C70: 7ffebd40                 call    _panic
F0065C74: 901221f0                 bset    %lo(aMsgSendFromKer), %o0! "msg_send_from_kernel"
F0065C78: 1080000e                 ba      loc_F0065CB0
F0065C7C: 80a62000                 cmp     %i0, 0
F0065C80: 808e6001                 btst    1, %i1
F0065C84: 02800005                 be      loc_F0065C98
F0065C88: d407bff4                 ld      [%fp+var_C], %o2
F0065C8C: 110000c0                 sethi   0x30000, %o0
F0065C90: 10800003                 ba      loc_F0065C9C
F0065C94: 92122010                 or      %o0, 0x10, %o1
F0065C98: 130000c0                 sethi   0x30000, %o1
F0065C9C: 9010000a                 mov     %o2, %o0
F0065CA0: 9410001a                 mov     %i2, %o2
F0065CA4: 7fffc9f6                 call    _ipc_mqueue_send
F0065CA8: 96102000                 mov     0, %o3
F0065CAC: b0920000                 orcc    %o0, %g0, %i0
F0065CB0: 02800005                 be      loc_F0065CC4
F0065CB4: 90100018                 mov     %i0, %o0
F0065CB8: 7fffbc5c                 call    _ipc_kmsg_destroy
F0065CBC: d007bff4                 ld      [%fp+var_C], %o0
F0065CC0: 90100018                 mov     %i0, %o0
F0065CC4: 7fffed67                 call    _msg_return_translate
F0065CC8: 01000000                 nop
F0065CCC: 81c7e008                 ret
F0065CD0: 91e80008                 restore %g0, %o0, %o0
