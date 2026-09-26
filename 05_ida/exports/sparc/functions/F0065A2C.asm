F0065A2C: 9de3bf80                 save    %sp, -0x80, %sp
F0065A30: 113c04d0                 sethi   %hi(_active_threads), %o0
F0065A34: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0065A38: d002200c                 ld      [%o0+0xC], %o0
F0065A3C: a2100018                 mov     %i0, %l1
F0065A40: e0022088                 ld      [%o0+0x88], %l0
F0065A44: 9210001a                 mov     %i2, %o1
F0065A48: 808e6001                 btst    1, %i1
F0065A4C: 02800025                 be      loc_F0065AE0
F0065A50: e602200c                 ld      [%o0+0xC], %l3
F0065A54: 90100011                 mov     %l1, %o0
F0065A58: 94102000                 mov     0, %o2
F0065A5C: 7fffbe3b                 call    _ipc_kmsg_get_from_kernel
F0065A60: 9607bff4                 add     %fp, var_C, %o3
F0065A64: 80a22000                 cmp     %o0, 0
F0065A68: 02800004                 be      loc_F0065A78
F0065A6C: 113c043e                 sethi   %hi(aMachMsg), %o0! "mach_msg"
F0065A70: 7ffebdc0                 call    _panic
F0065A74: 901221e0                 bset    %lo(aMachMsg), %o0! "mach_msg"
F0065A78: d007bff4                 ld      [%fp+var_C], %o0
F0065A7C: 92100010                 mov     %l0, %o1
F0065A80: 94100013                 mov     %l3, %o2
F0065A84: 7fffc0f3                 call    _ipc_kmsg_copyin
F0065A88: 96102000                 mov     0, %o3
F0065A8C: b0920000                 orcc    %o0, %g0, %i0
F0065A90: 0280000a                 be      loc_F0065AB8
F0065A94: d007bff4                 ld      [%fp+var_C], %o0
F0065A98: d2022008                 ld      [%o0+8], %o1
F0065A9C: 80a26000                 cmp     %o1, 0
F0065AA0: 14800004                 bg      loc_F0065AB0
F0065AA4: 01000000                 nop
F0065AA8: 7fffbdd6                 call    _ipc_kmsg_free
F0065AAC: 9e03e174                 inc     0x174, %o7
F0065AB0: 400009bc                 call    _kfree
F0065AB4: 9e03e16c                 inc     0x16C, %o7
F0065AB8: 11040000b4122007         set     0x10000007, %i2
F0065AC0: d007bff4                 ld      [%fp+var_C], %o0
F0065AC4: 92102000                 mov     0, %o1
F0065AC8: 94102000                 mov     0, %o2
F0065ACC: 7fffca6c                 call    _ipc_mqueue_send
F0065AD0: 96102000                 mov     0, %o3
F0065AD4: 80a2001a                 cmp     %o0, %i2
F0065AD8: 02bffffb                 be      loc_F0065AC4
F0065ADC: d007bff4                 ld      [%fp+var_C], %o0
F0065AE0: 808e6002                 btst    2, %i1
F0065AE4: 0280004f                 be      loc_F0065C20
F0065AE8: b407bff4                 add     %fp, var_C, %i2
F0065AEC: b207bfe8                 add     %fp, var_18, %i1
F0065AF0: 11040010a4122005         set     0x10004005, %l2
F0065AF8: 90100010                 mov     %l0, %o0
F0065AFC: 9210001c                 mov     %i4, %o1
F0065B00: 9407bff0                 add     %fp, var_10, %o2
F0065B04: 7fffcb7e                 call    _ipc_mqueue_copyin
F0065B08: 9607bfec                 add     %fp, var_14, %o3
F0065B0C: b0920000                 orcc    %o0, %g0, %i0
F0065B10: 12800045                 bne     locret_F0065C24
F0065B14: 92102000                 mov     0, %o1
F0065B18: 94103fff                 mov     -1, %o2
F0065B1C: 96102000                 mov     0, %o3
F0065B20: 98102000                 mov     0, %o4
F0065B24: d007bff0                 ld      [%fp+var_10], %o0
F0065B28: 9a102000                 mov     0, %o5
F0065B2C: f423a05c                 st      %i2, [%sp+0x80+var_24]
F0065B30: 7fffcbe2                 call    _ipc_mqueue_receive
F0065B34: f223a060                 st      %i1, [%sp+0x80+var_20]
F0065B38: b0100008                 mov     %o0, %i0
F0065B3C: 7fffcecd                 call    _ipc_object_release
F0065B40: d007bfec                 ld      [%fp+var_14], %o0
F0065B44: 80a60012                 cmp     %i0, %l2
F0065B48: 22bfffed                 be,a    loc_F0065AFC
F0065B4C: 90100010                 mov     %l0, %o0
F0065B50: 80a62000                 cmp     %i0, 0
F0065B54: 12800034                 bne     locret_F0065C24
F0065B58: d407bff4                 ld      [%fp+var_C], %o2
F0065B5C: d007bfe8                 ld      [%fp+var_18], %o0
F0065B60: d202a018                 ld      [%o2+0x18], %o1
F0065B64: 80a6c009                 cmp     %i3, %o1
F0065B68: 1a80000c                 bcc     loc_F0065B98
F0065B6C: d022a024                 st      %o0, [%o2+0x24]
F0065B70: 9010000a                 mov     %o2, %o0
F0065B74: 7fffc56c                 call    _ipc_kmsg_copyout_dest
F0065B78: 92100010                 mov     %l0, %o1
F0065B7C: 90100011                 mov     %l1, %o0
F0065B80: d207bff4                 ld      [%fp+var_C], %o1
F0065B84: 7fffbe28                 call    _ipc_kmsg_put_to_kernel
F0065B88: 94102018                 mov     0x18, %o2
F0065B8C: 31040010                 sethi   0x10004000, %i0
F0065B90: 10800025                 ba      locret_F0065C24
F0065B94: b0162004                 bset    4, %i0
F0065B98: 9010000a                 mov     %o2, %o0
F0065B9C: 92100010                 mov     %l0, %o1
F0065BA0: 94100013                 mov     %l3, %o2
F0065BA4: 7fffc521                 call    _ipc_kmsg_copyout
F0065BA8: 96102000                 mov     0, %o3
F0065BAC: b0920000                 orcc    %o0, %g0, %i0
F0065BB0: 02800016                 be      loc_F0065C08
F0065BB4: 1300000f                 sethi   0x3C00, %o1
F0065BB8: 922e0009                 andn    %i0, %o1, %o1
F0065BBC: 110400109012200c         set     0x1000400C, %o0
F0065BC4: 80a24008                 cmp     %o1, %o0
F0065BC8: 12800009                 bne     loc_F0065BEC
F0065BCC: d007bff4                 ld      [%fp+var_C], %o0
F0065BD0: d207bff4                 ld      [%fp+var_C], %o1
F0065BD4: d6026018                 ld      [%o1+0x18], %o3
F0065BD8: d4026010                 ld      [%o1+0x10], %o2
F0065BDC: 90100011                 mov     %l1, %o0
F0065BE0: 7fffbe11                 call    _ipc_kmsg_put_to_kernel
F0065BE4: 9402c00a                 add     %o3, %o2, %o2
F0065BE8: 3080000f                 ba,a    locret_F0065C24
F0065BEC: 7fffc54e                 call    _ipc_kmsg_copyout_dest
F0065BF0: 92100010                 mov     %l0, %o1
F0065BF4: 90100011                 mov     %l1, %o0
F0065BF8: d207bff4                 ld      [%fp+var_C], %o1
F0065BFC: 7fffbe0a                 call    _ipc_kmsg_put_to_kernel
F0065C00: 94102018                 mov     0x18, %o2
F0065C04: 30800008                 ba,a    locret_F0065C24
F0065C08: d207bff4                 ld      [%fp+var_C], %o1
F0065C0C: d6026018                 ld      [%o1+0x18], %o3
F0065C10: d4026010                 ld      [%o1+0x10], %o2
F0065C14: 90100011                 mov     %l1, %o0
F0065C18: 7fffbe03                 call    _ipc_kmsg_put_to_kernel
F0065C1C: 9402c00a                 add     %o3, %o2, %o2
F0065C20: b0102000                 mov     0, %i0
F0065C24: 81c7e008                 ret
F0065C28: 81e80000                 restore
