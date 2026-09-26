F0022E68: 9de3bf98                 save    %sp, -0x68, %sp
F0022E6C: d0062004                 ld      [%i0+4], %o0
F0022E70: d2562008                 ldsh    [%i0+8], %o1
F0022E74: b0060008                 add     %i0, %o0, %i0
F0022E78: 7fffa132                 call    _ufavail
F0022E7C: a5326002                 srl     %o1, 2, %l2
F0022E80: 80a48008                 cmp     %l2, %o0
F0022E84: 0480000e                 ble     loc_F0022EBC
F0022E88: a0102000                 mov     0, %l0
F0022E8C: 80a40012                 cmp     %l0, %l2
F0022E90: 36800029                 bge,a   locret_F0022F34
F0022E94: b0102028                 mov     0x28, %i0 ! '('
F0022E98: d0060000                 ld      [%i0], %o0
F0022E9C: 4000010f                 call    _unp_discard
F0022EA0: a0042001                 inc     %l0
F0022EA4: c0260000                 clr     [%i0]
F0022EA8: 80a40012                 cmp     %l0, %l2
F0022EAC: 06bffffb                 bl      loc_F0022E98
F0022EB0: b0062004                 inc     4, %i0
F0022EB4: 10800020                 ba      locret_F0022F34
F0022EB8: b0102028                 mov     0x28, %i0 ! '('
F0022EBC: 80a40012                 cmp     %l0, %l2
F0022EC0: 3680001d                 bge,a   locret_F0022F34
F0022EC4: b0102000                 mov     0, %i0
F0022EC8: 2b3c042f                 sethi   -0xFEF4400, %l5
F0022ECC: 293c04cf                 sethi   -0xFECC400, %l4
F0022ED0: 273c04d4                 sethi   -0xFECB000, %l3
F0022ED4: 7fffa0ef                 call    _ufalloc
F0022ED8: 90102000                 mov     0, %o0! char *
F0022EDC: a2920000                 orcc    %o0, %g0, %l1
F0022EE0: 36800005                 bge,a   loc_F0022EF4
F0022EE4: d6060000                 ld      [%i0], %o3
F0022EE8: 7fffc8a2                 call    _panic
F0022EEC: 90156178                 or      %l5, 0x178, %o0
F0022EF0: d6060000                 ld      [%i0], %o3
F0022EF4: d00521d8                 ld      [%l4+0x1D8], %o0
F0022EF8: a0042001                 inc     %l0
F0022EFC: d204e2d0                 ld      [%l3+0x2D0], %o1
F0022F00: 80a40012                 cmp     %l0, %l2
F0022F04: d402214c                 ld      [%o0+0x14C], %o2
F0022F08: 92027fff                 inc     -1, %o1
F0022F0C: 912c6002                 sll     %l1, 2, %o0
F0022F10: d6228008                 st      %o3, [%o2+%o0]
F0022F14: d012e010                 lduh    [%o3+0x10], %o0
F0022F18: d224e2d0                 st      %o1, [%l3+0x2D0]
F0022F1C: 90023fff                 inc     -1, %o0
F0022F20: d032e010                 sth     %o0, [%o3+0x10]
F0022F24: e2260000                 st      %l1, [%i0]
F0022F28: 06bfffeb                 bl      loc_F0022ED4
F0022F2C: b0062004                 inc     4, %i0
F0022F30: b0102000                 mov     0, %i0
F0022F34: 81c7e008                 ret
F0022F38: 81e80000                 restore
