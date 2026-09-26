F005A928: 9de3bf98                 save    %sp, -0x68, %sp
F005A92C: e0062030                 ld      [%i0+0x30], %l0
F005A930: 80a42000                 cmp     %l0, 0
F005A934: 2280001d                 be,a    loc_F005A9A8
F005A938: a0062040                 add     %i0, 0x40, %l0 ! '@'
F005A93C: d0040000                 ld      [%l0], %o0
F005A940: 80a22000                 cmp     %o0, 0
F005A944: 12bffffe                 bne     loc_F005A93C
F005A948: 01000000                 nop
F005A94C: 4000f157                 call    _simple_lock_try
F005A950: 90100010                 mov     %l0, %o0
F005A954: 80a22000                 cmp     %o0, 0
F005A958: 02bffff9                 be      loc_F005A93C
F005A95C: 90100010                 mov     %l0, %o0
F005A960: 40000379                 call    _ipc_pset_remove
F005A964: 92100018                 mov     %i0, %o1
F005A968: d0042004                 ld      [%l0+4], %o0
F005A96C: c0240000                 clr     [%l0]
F005A970: 80a22000                 cmp     %o0, 0
F005A974: 3280001b                 bne,a   loc_F005A9E0
F005A978: c0262018                 clr     [%i0+0x18]
F005A97C: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005A980: d0042008                 ld      [%l0+8], %o0
F005A984: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005A988: 912a2001                 sll     %o0, 1, %o0
F005A98C: 91322011                 srl     %o0, 17, %o0
F005A990: 912a2002                 sll     %o0, 2, %o0
F005A994: d0020009                 ld      [%o0+%o1], %o0
F005A998: 40007a0e                 call    _zfree
F005A99C: 92100010                 mov     %l0, %o1
F005A9A0: 10800010                 ba      loc_F005A9E0
F005A9A4: c0262018                 clr     [%i0+0x18]
F005A9A8: d0040000                 ld      [%l0], %o0
F005A9AC: 80a22000                 cmp     %o0, 0
F005A9B0: 12bffffe                 bne     loc_F005A9A8
F005A9B4: 01000000                 nop
F005A9B8: 4000f13c                 call    _simple_lock_try
F005A9BC: 90100010                 mov     %l0, %o0
F005A9C0: 80a22000                 cmp     %o0, 0
F005A9C4: 02bffff9                 be      loc_F005A9A8
F005A9C8: 90062040                 add     %i0, 0x40, %o0 ! '@'
F005A9CC: 13040010                 sethi   0x10004000, %o1
F005A9D0: 7ffff6a0                 call    _ipc_mqueue_changed
F005A9D4: 92126009                 bset    9, %o1
F005A9D8: c0262040                 clr     [%i0+0x40]
F005A9DC: c0262018                 clr     [%i0+0x18]
F005A9E0: a0062040                 add     %i0, 0x40, %l0 ! '@'
F005A9E4: d0040000                 ld      [%l0], %o0
F005A9E8: 80a22000                 cmp     %o0, 0
F005A9EC: 12bffffe                 bne     loc_F005A9E4
F005A9F0: 01000000                 nop
F005A9F4: 4000f12d                 call    _simple_lock_try
F005A9F8: 90100010                 mov     %l0, %o0
F005A9FC: 80a22000                 cmp     %o0, 0
F005AA00: 02bffff9                 be      loc_F005A9E4
F005AA04: 01000000                 nop
F005AA08: c0262034                 clr     [%i0+0x34]
F005AA0C: c0262040                 clr     [%i0+0x40]
F005AA10: 81c7e008                 ret
F005AA14: 81e80000                 restore
