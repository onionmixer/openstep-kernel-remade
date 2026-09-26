F005F954: 9de3bf78                 save    %sp, -0x88, %sp! int
F005F958: 113c04d0                 sethi   %hi(_active_threads), %o0
F005F95C: e0022260                 ld      [%o0+%lo(_active_threads)], %l0
F005F960: a2100018                 mov     %i0, %l1
F005F964: d004200c                 ld      [%l0+0xC], %o0
F005F968: 9210001b                 mov     %i3, %o1
F005F96C: f6022088                 ld      [%o0+0x88], %i3
F005F970: 9407bff4                 add     %fp, var_10+4, %o2
F005F974: e402200c                 ld      [%o0+0xC], %l2
F005F978: 9607bff0                 add     %fp, var_10, %o3
F005F97C: 7fffe3e0                 call    _ipc_mqueue_copyin
F005F980: 9010001b                 mov     %i3, %o0
F005F984: b0920000                 orcc    %o0, %g0, %i0
F005F988: 1280007c                 bne     locret_F005FB78
F005F98C: 808e6800                 btst    0x800, %i1
F005F990: e22420c4                 st      %l1, [%l0+0xC4]
F005F994: f22420c8                 st      %i1, [%l0+0xC8]
F005F998: f42420cc                 st      %i2, [%l0+0xCC]
F005F99C: f82420d0                 st      %i4, [%l0+0xD0]
F005F9A0: fa2420d4                 st      %i5, [%l0+0xD4]
F005F9A4: d01fbff0                 ldd     [%fp+var_10], %o0
F005F9A8: d02420d8                 st      %o0, [%l0+0xD8]
F005F9AC: 02800021                 be      loc_F005FA30
F005F9B0: d22420dc                 st      %o1, [%l0+0xDC]
F005F9B4: 9007bfec                 add     %fp, var_18+4, %o0
F005F9B8: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F005F9BC: 9007bfe8                 add     %fp, var_18, %o0
F005F9C0: d023a060                 st      %o0, [%sp+0x88+var_28]
F005F9C4: 90100009                 mov     %o1, %o0
F005F9C8: 920e6100                 and     %i1, 0x100, %o1
F005F9CC: 9410001a                 mov     %i2, %o2
F005F9D0: 9610001c                 mov     %i4, %o3
F005F9D4: 98102000                 mov     0, %o4! int
F005F9D8: 1b3c017e                 sethi   %hi(_mach_msg_receive_continue), %o5
F005F9DC: 7fffe437                 call    _ipc_mqueue_receive
F005F9E0: 9a136380                 bset    %lo(_mach_msg_receive_continue), %o5! int
F005F9E4: b0100008                 mov     %o0, %i0
F005F9E8: 7fffe722                 call    _ipc_object_release
F005F9EC: d007bff0                 ld      [%fp+var_10], %o0
F005F9F0: 80a62000                 cmp     %i0, 0
F005F9F4: 0280000c                 be      loc_F005FA24
F005F9F8: 11040010                 sethi   0x10004000, %o0
F005F9FC: 90122004                 bset    4, %o0
F005FA00: 80a60008                 cmp     %i0, %o0
F005FA04: 1280005d                 bne     locret_F005FB78
F005FA08: 9007bfe4                 add     %fp, var_1C, %o0! int
F005FA0C: 92046004                 add     %l1, 4, %o1! int
F005FA10: d607bfec                 ld      [%fp+var_18+4], %o3! int
F005FA14: 94102004                 mov     4, %o2! int
F005FA18: 4000e1ad                 call    _copyout
F005FA1C: d627bfe4                 st      %o3, [%fp+var_1C]
F005FA20: 30800056                 ba,a    locret_F005FB78
F005FA24: d01fbfe8                 ldd     [%fp+var_18], %o0
F005FA28: 10800023                 ba      loc_F005FAB4
F005FA2C: d0226024                 st      %o0, [%o1+0x24]
F005FA30: 9007bfec                 add     %fp, var_18+4, %o0
F005FA34: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F005FA38: 9007bfe8                 add     %fp, var_18, %o0
F005FA3C: d023a060                 st      %o0, [%sp+0x88+var_28]
F005FA40: 90100009                 mov     %o1, %o0
F005FA44: 920e6100                 and     %i1, 0x100, %o1
F005FA48: 94103fff                 mov     -1, %o2
F005FA4C: 9610001c                 mov     %i4, %o3
F005FA50: 98102000                 mov     0, %o4
F005FA54: 1b3c017e                 sethi   %hi(_mach_msg_receive_continue), %o5
F005FA58: 7fffe418                 call    _ipc_mqueue_receive
F005FA5C: 9a136380                 bset    %lo(_mach_msg_receive_continue), %o5
F005FA60: b0100008                 mov     %o0, %i0
F005FA64: 7fffe703                 call    _ipc_object_release
F005FA68: d007bff0                 ld      [%fp+var_10], %o0
F005FA6C: 80a62000                 cmp     %i0, 0
F005FA70: 12800042                 bne     locret_F005FB78
F005FA74: d407bfec                 ld      [%fp+var_18+4], %o2
F005FA78: d007bfe8                 ld      [%fp+var_18], %o0
F005FA7C: d202a018                 ld      [%o2+0x18], %o1
F005FA80: 80a2401a                 cmp     %o1, %i2
F005FA84: 0880000c                 bleu    loc_F005FAB4
F005FA88: d022a024                 st      %o0, [%o2+0x24]
F005FA8C: 9010000a                 mov     %o2, %o0
F005FA90: 7fffdda5                 call    _ipc_kmsg_copyout_dest
F005FA94: 9210001b                 mov     %i3, %o1
F005FA98: 90100011                 mov     %l1, %o0
F005FA9C: d207bfec                 ld      [%fp+var_18+4], %o1
F005FAA0: 7fffd640                 call    _ipc_kmsg_put
F005FAA4: 94102018                 mov     0x18, %o2
F005FAA8: 31040010                 sethi   0x10004000, %i0
F005FAAC: 10800033                 ba      locret_F005FB78
F005FAB0: b0162004                 bset    4, %i0
F005FAB4: 808e6200                 btst    0x200, %i1
F005FAB8: 0280000b                 be      loc_F005FAE4
F005FABC: 80a76000                 cmp     %i5, 0
F005FAC0: 12800005                 bne     loc_F005FAD4
F005FAC4: d007bfec                 ld      [%fp+var_18+4], %o0
F005FAC8: 11040010                 sethi   0x10004000, %o0
F005FACC: 1080000d                 ba      loc_F005FB00
F005FAD0: b0122007                 or      %o0, 7, %i0
F005FAD4: 9210001b                 mov     %i3, %o1
F005FAD8: 94100012                 mov     %l2, %o2
F005FADC: 10800006                 ba      loc_F005FAF4
F005FAE0: 9610001d                 mov     %i5, %o3
F005FAE4: d007bfec                 ld      [%fp+var_18+4], %o0
F005FAE8: 9210001b                 mov     %i3, %o1
F005FAEC: 94100012                 mov     %l2, %o2
F005FAF0: 96102000                 mov     0, %o3
F005FAF4: 7fffdd4d                 call    _ipc_kmsg_copyout
F005FAF8: 01000000                 nop
F005FAFC: b0100008                 mov     %o0, %i0
F005FB00: 80a62000                 cmp     %i0, 0
F005FB04: 02800016                 be      loc_F005FB5C
F005FB08: 1300000f                 sethi   0x3C00, %o1
F005FB0C: 922e0009                 andn    %i0, %o1, %o1
F005FB10: 110400109012200c         set     0x1000400C, %o0
F005FB18: 80a24008                 cmp     %o1, %o0
F005FB1C: 12800009                 bne     loc_F005FB40
F005FB20: d007bfec                 ld      [%fp+var_18+4], %o0
F005FB24: d207bfec                 ld      [%fp+var_18+4], %o1
F005FB28: d6026018                 ld      [%o1+0x18], %o3
F005FB2C: d4026010                 ld      [%o1+0x10], %o2
F005FB30: 90100011                 mov     %l1, %o0
F005FB34: 7fffd61b                 call    _ipc_kmsg_put
F005FB38: 9402c00a                 add     %o3, %o2, %o2
F005FB3C: 3080000f                 ba,a    locret_F005FB78
F005FB40: 7fffdd79                 call    _ipc_kmsg_copyout_dest
F005FB44: 9210001b                 mov     %i3, %o1
F005FB48: 90100011                 mov     %l1, %o0
F005FB4C: d207bfec                 ld      [%fp+var_18+4], %o1
F005FB50: 7fffd614                 call    _ipc_kmsg_put
F005FB54: 94102018                 mov     0x18, %o2
F005FB58: 30800008                 ba,a    locret_F005FB78
F005FB5C: d207bfec                 ld      [%fp+var_18+4], %o1
F005FB60: d6026018                 ld      [%o1+0x18], %o3
F005FB64: d4026010                 ld      [%o1+0x10], %o2
F005FB68: 90100011                 mov     %l1, %o0
F005FB6C: 7fffd60d                 call    _ipc_kmsg_put
F005FB70: 9402c00a                 add     %o3, %o2, %o2
F005FB74: b0100008                 mov     %o0, %i0
F005FB78: 81c7e008                 ret
F005FB7C: 81e80000                 restore
