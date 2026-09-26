F006B8D4: 9de3bf98                 save    %sp, -0x68, %sp
F006B8D8: 113c04cf                 sethi   %hi(_active_u), %o0
F006B8DC: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F006B8E0: d002201c                 ld      [%o0+0x1C], %o0
F006B8E4: d0522002                 ldsh    [%o0+2], %o0
F006B8E8: 80a22000                 cmp     %o0, 0
F006B8EC: 02800004                 be      loc_F006B8FC
F006B8F0: e207a05c                 ld      [%fp+arg_5C], %l1
F006B8F4: 1080002c                 ba      locret_F006B9A4
F006B8F8: b0102008                 mov     8, %i0
F006B8FC: 80a46000                 cmp     %l1, 0
F006B900: 12800004                 bne     loc_F006B910
F006B904: 113c04f0                 sethi   -0xFEC4000, %o0
F006B908: 10800027                 ba      locret_F006B9A4
F006B90C: b0102004                 mov     4, %i0
F006B910: 400035ef                 call    _zalloc
F006B914: d0022118                 ld      [%o0+0x118], %o0
F006B918: a0100008                 mov     %o0, %l0
F006B91C: f2242004                 st      %i1, [%l0+4]
F006B920: f634200c                 sth     %i3, [%l0+0xC]
F006B924: f4242008                 st      %i2, [%l0+8]
F006B928: f834200e                 sth     %i4, [%l0+0xE]
F006B92C: e2242010                 st      %l1, [%l0+0x10]
F006B930: 7fffb740                 call    _ipc_object_reference
F006B934: 90100011                 mov     %l1, %o0
F006B938: 920f600f                 and     %i5, 0xF, %o1
F006B93C: 932a6003                 sll     %o1, 3, %o1
F006B940: 113c04f090122120         set     _listeners, %o0
F006B948: 4000acd3                 call    _splnet
F006B94C: b0024008                 add     %o1, %o0, %i0
F006B950: b2100008                 mov     %o0, %i1
F006B954: d0060000                 ld      [%i0], %o0
F006B958: 80a22000                 cmp     %o0, 0
F006B95C: 12bffffe                 bne     loc_F006B954
F006B960: 01000000                 nop
F006B964: 4000ad51                 call    _simple_lock_try
F006B968: 90100018                 mov     %i0, %o0
F006B96C: 80a22000                 cmp     %o0, 0
F006B970: 02bffff9                 be      loc_F006B954
F006B974: 01000000                 nop
F006B978: d2062004                 ld      [%i0+4], %o1
F006B97C: d2240000                 st      %o1, [%l0]
F006B980: e0262004                 st      %l0, [%i0+4]
F006B984: c0260000                 clr     [%i0]
F006B988: 4000ace7                 call    _splx
F006B98C: 90100019                 mov     %i1, %o0
F006B990: 90100011                 mov     %l1, %o0
F006B994: 92102000                 mov     0, %o1
F006B998: 7fffe7a2                 call    _ipc_kobject_set
F006B99C: 94102011                 mov     0x11, %o2
F006B9A0: b0102000                 mov     0, %i0
F006B9A4: 81c7e008                 ret
F006B9A8: 81e80000                 restore
