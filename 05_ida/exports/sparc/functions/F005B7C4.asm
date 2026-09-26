F005B7C4: 9de3bf98                 save    %sp, -0x68, %sp
F005B7C8: d0064000                 ld      [%i1], %o0
F005B7CC: 80a22000                 cmp     %o0, 0
F005B7D0: 12bffffe                 bne     loc_F005B7C8
F005B7D4: 01000000                 nop
F005B7D8: 4000edb4                 call    _simple_lock_try
F005B7DC: 90100019                 mov     %i1, %o0
F005B7E0: 80a22000                 cmp     %o0, 0
F005B7E4: 02bffff9                 be      loc_F005B7C8
F005B7E8: 01000000                 nop
F005B7EC: e0066030                 ld      [%i1+0x30], %l0
F005B7F0: 80a4001a                 cmp     %l0, %i2
F005B7F4: 12800004                 bne     loc_F005B804
F005B7F8: 80a42000                 cmp     %l0, 0
F005B7FC: c0262008                 clr     [%i0+8]
F005B800: 30800072                 ba,a    loc_F005B9C8
F005B804: 12800011                 bne     loc_F005B848
F005B808: 80a6a000                 cmp     %i2, 0
F005B80C: d0068000                 ld      [%i2], %o0
F005B810: 80a22000                 cmp     %o0, 0
F005B814: 12bffffe                 bne     loc_F005B80C
F005B818: 01000000                 nop
F005B81C: 4000eda3                 call    _simple_lock_try
F005B820: 9010001a                 mov     %i2, %o0
F005B824: 80a22000                 cmp     %o0, 0
F005B828: 02bffff9                 be      loc_F005B80C
F005B82C: 01000000                 nop
F005B830: c0262008                 clr     [%i0+8]
F005B834: 9010001a                 mov     %i2, %o0
F005B838: 7fffff9e                 call    _ipc_pset_add
F005B83C: 92100019                 mov     %i1, %o1
F005B840: c0268000                 clr     [%i2]
F005B844: 30800061                 ba,a    loc_F005B9C8
F005B848: 12800023                 bne     loc_F005B8D4
F005B84C: 80a4001a                 cmp     %l0, %i2
F005B850: c0262008                 clr     [%i0+8]
F005B854: d0040000                 ld      [%l0], %o0
F005B858: 80a22000                 cmp     %o0, 0
F005B85C: 12bffffe                 bne     loc_F005B854
F005B860: 01000000                 nop
F005B864: 4000ed91                 call    _simple_lock_try
F005B868: 90100010                 mov     %l0, %o0
F005B86C: 80a22000                 cmp     %o0, 0
F005B870: 02bffff9                 be      loc_F005B854
F005B874: 90100010                 mov     %l0, %o0
F005B878: 7fffffb3                 call    _ipc_pset_remove
F005B87C: 92100019                 mov     %i1, %o1
F005B880: d0042008                 ld      [%l0+8], %o0
F005B884: 80a22000                 cmp     %o0, 0
F005B888: 36800004                 bge,a   loc_F005B898
F005B88C: d0042004                 ld      [%l0+4], %o0
F005B890: c0240000                 clr     [%l0]
F005B894: 3080004d                 ba,a    loc_F005B9C8
F005B898: c0240000                 clr     [%l0]
F005B89C: 80a22000                 cmp     %o0, 0
F005B8A0: 3280004a                 bne,a   loc_F005B9C8
F005B8A4: a0102000                 mov     0, %l0
F005B8A8: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005B8AC: d0042008                 ld      [%l0+8], %o0
F005B8B0: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005B8B4: 912a2001                 sll     %o0, 1, %o0
F005B8B8: 91322011                 srl     %o0, 17, %o0
F005B8BC: 912a2002                 sll     %o0, 2, %o0
F005B8C0: d0020009                 ld      [%o0+%o1], %o0
F005B8C4: 40007643                 call    _zfree
F005B8C8: 92100010                 mov     %l0, %o1
F005B8CC: 1080003f                 ba      loc_F005B9C8
F005B8D0: a0102000                 mov     0, %l0
F005B8D4: 1a800015                 bcc     loc_F005B928
F005B8D8: 01000000                 nop
F005B8DC: d0040000                 ld      [%l0], %o0
F005B8E0: 80a22000                 cmp     %o0, 0
F005B8E4: 12bffffe                 bne     loc_F005B8DC
F005B8E8: 01000000                 nop
F005B8EC: 4000ed6f                 call    _simple_lock_try
F005B8F0: 90100010                 mov     %l0, %o0
F005B8F4: 80a22000                 cmp     %o0, 0
F005B8F8: 02bffff9                 be      loc_F005B8DC
F005B8FC: 01000000                 nop
F005B900: d0068000                 ld      [%i2], %o0
F005B904: 80a22000                 cmp     %o0, 0
F005B908: 12bffffe                 bne     loc_F005B900
F005B90C: 01000000                 nop
F005B910: 4000ed66                 call    _simple_lock_try
F005B914: 9010001a                 mov     %i2, %o0
F005B918: 80a22000                 cmp     %o0, 0
F005B91C: 02bffff9                 be      loc_F005B900
F005B920: 01000000                 nop
F005B924: 30800013                 ba,a    loc_F005B970
F005B928: d0068000                 ld      [%i2], %o0
F005B92C: 80a22000                 cmp     %o0, 0
F005B930: 12bffffe                 bne     loc_F005B928
F005B934: 01000000                 nop
F005B938: 4000ed5c                 call    _simple_lock_try
F005B93C: 9010001a                 mov     %i2, %o0
F005B940: 80a22000                 cmp     %o0, 0
F005B944: 02bffff9                 be      loc_F005B928
F005B948: 01000000                 nop
F005B94C: d0040000                 ld      [%l0], %o0
F005B950: 80a22000                 cmp     %o0, 0
F005B954: 12bffffe                 bne     loc_F005B94C
F005B958: 01000000                 nop
F005B95C: 4000ed53                 call    _simple_lock_try
F005B960: 90100010                 mov     %l0, %o0
F005B964: 80a22000                 cmp     %o0, 0
F005B968: 02bffff9                 be      loc_F005B94C
F005B96C: 01000000                 nop
F005B970: c0262008                 clr     [%i0+8]
F005B974: 90100010                 mov     %l0, %o0
F005B978: 7fffff73                 call    _ipc_pset_remove
F005B97C: 92100019                 mov     %i1, %o1
F005B980: 9010001a                 mov     %i2, %o0
F005B984: 7fffff4b                 call    _ipc_pset_add
F005B988: 92100019                 mov     %i1, %o1
F005B98C: c0268000                 clr     [%i2]
F005B990: d0042004                 ld      [%l0+4], %o0
F005B994: c0240000                 clr     [%l0]
F005B998: 80a22000                 cmp     %o0, 0
F005B99C: 1280000b                 bne     loc_F005B9C8
F005B9A0: 01000000                 nop
F005B9A4: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005B9A8: d0042008                 ld      [%l0+8], %o0
F005B9AC: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005B9B0: 912a2001                 sll     %o0, 1, %o0
F005B9B4: 91322011                 srl     %o0, 17, %o0
F005B9B8: 912a2002                 sll     %o0, 2, %o0
F005B9BC: d0020009                 ld      [%o0+%o1], %o0
F005B9C0: 40007604                 call    _zfree
F005B9C4: 92100010                 mov     %l0, %o1
F005B9C8: c0264000                 clr     [%i1]
F005B9CC: 80a6a000                 cmp     %i2, 0
F005B9D0: 12800005                 bne     locret_F005B9E4
F005B9D4: b0102000                 mov     0, %i0
F005B9D8: 80a00010                 cmp     %g0, %l0
F005B9DC: 90403fff                 addc    %g0, -1, %o0
F005B9E0: b00a200c                 and     %o0, 0xC, %i0
F005B9E4: 81c7e008                 ret
F005B9E8: 81e80000                 restore
