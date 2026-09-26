F005F7BC: 9de3bf90                 save    %sp, -0x70, %sp
F005F7C0: 113c04d0                 sethi   %hi(_active_threads), %o0
F005F7C4: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F005F7C8: d602600c                 ld      [%o1+0xC], %o3
F005F7CC: a2100018                 mov     %i0, %l1
F005F7D0: 9210001a                 mov     %i2, %o1
F005F7D4: f402e088                 ld      [%o3+0x88], %i2
F005F7D8: 94102000                 mov     0, %o2
F005F7DC: e002e00c                 ld      [%o3+0xC], %l0
F005F7E0: 90100011                 mov     %l1, %o0
F005F7E4: 7fffd69a                 call    _ipc_kmsg_get
F005F7E8: 9607bff4                 add     %fp, var_C, %o3
F005F7EC: b0920000                 orcc    %o0, %g0, %i0
F005F7F0: 12800057                 bne     locret_F005F94C
F005F7F4: 808e6080                 btst    0x80, %i1
F005F7F8: 0280000d                 be      loc_F005F82C
F005F7FC: 80a72000                 cmp     %i4, 0
F005F800: 12800005                 bne     loc_F005F814
F005F804: d007bff4                 ld      [%fp+var_C], %o0
F005F808: 11040000                 sethi   0x10000000, %o0
F005F80C: 1080000f                 ba      loc_F005F848
F005F810: b012200b                 or      %o0, 0xB, %i0
F005F814: 9210001a                 mov     %i2, %o1
F005F818: 94100010                 mov     %l0, %o2
F005F81C: 10800008                 ba      loc_F005F83C
F005F820: 9610001c                 mov     %i4, %o3
F005F824: 4000225f                 call    _kfree
F005F828: 9e03e120                 inc     0x120, %o7
F005F82C: d007bff4                 ld      [%fp+var_C], %o0
F005F830: 9210001a                 mov     %i2, %o1
F005F834: 94100010                 mov     %l0, %o2
F005F838: 96102000                 mov     0, %o3
F005F83C: 7fffd985                 call    _ipc_kmsg_copyin
F005F840: 01000000                 nop
F005F844: b0100008                 mov     %o0, %i0
F005F848: 80a62000                 cmp     %i0, 0
F005F84C: 02800008                 be      loc_F005F86C
F005F850: d007bff4                 ld      [%fp+var_C], %o0
F005F854: d2022008                 ld      [%o0+8], %o1
F005F858: 80a26000                 cmp     %o1, 0
F005F85C: 14bffff2                 bg      loc_F005F824
F005F860: 01000000                 nop
F005F864: 7fffd667                 call    _ipc_kmsg_free
F005F868: 9e03e0e0                 inc     0xE0, %o7
F005F86C: 808e6020                 btst    0x20, %i1 ! ' '
F005F870: 02800025                 be      loc_F005F904
F005F874: 900e6010                 and     %i1, 0x10, %o0
F005F878: 80a00008                 cmp     %g0, %o0
F005F87C: d007bff4                 ld      [%fp+var_C], %o0
F005F880: 92102010                 mov     0x10, %o1
F005F884: 94602000                 subc    %g0, 0, %o2
F005F888: 940ec00a                 and     %i3, %o2, %o2
F005F88C: 7fffe2fc                 call    _ipc_mqueue_send
F005F890: 96102000                 mov     0, %o3
F005F894: b0100008                 mov     %o0, %i0
F005F898: 1104000090122004         set     0x10000004, %o0
F005F8A0: 80a60008                 cmp     %i0, %o0
F005F8A4: 1280001e                 bne     loc_F005F91C
F005F8A8: 80a62000                 cmp     %i0, 0
F005F8AC: d607bff4                 ld      [%fp+var_C], %o3
F005F8B0: 80a72000                 cmp     %i4, 0
F005F8B4: 12800005                 bne     loc_F005F8C8
F005F8B8: d202e01c                 ld      [%o3+0x1C], %o1
F005F8BC: 11040000                 sethi   0x10000000, %o0
F005F8C0: 10800007                 ba      loc_F005F8DC
F005F8C4: b012200b                 or      %o0, 0xB, %i0
F005F8C8: 9010001a                 mov     %i2, %o0
F005F8CC: 9410001c                 mov     %i4, %o2
F005F8D0: 7fffe135                 call    _ipc_marequest_create
F005F8D4: 9602e00c                 inc     0xC, %o3
F005F8D8: b0100008                 mov     %o0, %i0
F005F8DC: 80a62000                 cmp     %i0, 0
F005F8E0: 1280000f                 bne     loc_F005F91C
F005F8E4: d007bff4                 ld      [%fp+var_C], %o0
F005F8E8: 13000040                 sethi   0x10000, %o1
F005F8EC: 94102000                 mov     0, %o2
F005F8F0: 7fffe2e3                 call    _ipc_mqueue_send
F005F8F4: 96102000                 mov     0, %o3
F005F8F8: 31040000                 sethi   0x10000000, %i0
F005F8FC: 10800014                 ba      locret_F005F94C
F005F900: b0162005                 bset    5, %i0
F005F904: d007bff4                 ld      [%fp+var_C], %o0
F005F908: 920e6010                 and     %i1, 0x10, %o1
F005F90C: 9410001b                 mov     %i3, %o2
F005F910: 7fffe2db                 call    _ipc_mqueue_send
F005F914: 96102000                 mov     0, %o3
F005F918: b0920000                 orcc    %o0, %g0, %i0
F005F91C: 0280000c                 be      locret_F005F94C
F005F920: 9210001a                 mov     %i2, %o1
F005F924: d007bff4                 ld      [%fp+var_C], %o0
F005F928: 7fffddd9                 call    _ipc_kmsg_copyout_pseudo
F005F92C: 94100010                 mov     %l0, %o2
F005F930: d207bff4                 ld      [%fp+var_C], %o1
F005F934: d6026018                 ld      [%o1+0x18], %o3
F005F938: b0160008                 bset    %o0, %i0
F005F93C: d4026010                 ld      [%o1+0x10], %o2
F005F940: 90100011                 mov     %l1, %o0
F005F944: 7fffd697                 call    _ipc_kmsg_put
F005F948: 9402c00a                 add     %o3, %o2, %o2
F005F94C: 81c7e008                 ret
F005F950: 81e80000                 restore
