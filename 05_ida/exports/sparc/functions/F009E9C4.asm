F009E9C4: 9de3bf90                 save    %sp, -0x70, %sp
F009E9C8: 80a62000                 cmp     %i0, 0
F009E9CC: 0280007c                 be      locret_F009EBBC
F009E9D0: 133c04f7                 sethi   %hi(_pmap_info), %o1
F009E9D4: 92126270                 bset    %lo(_pmap_info), %o1
F009E9D8: d0026074                 ld      [%o1+0x74], %o0
F009E9DC: 80a6e000                 cmp     %i3, 0
F009E9E0: 90022001                 inc     %o0
F009E9E4: 12800007                 bne     loc_F009EA00
F009E9E8: d0226074                 st      %o0, [%o1+0x74]
F009E9EC: 90100018                 mov     %i0, %o0
F009E9F0: 92100019                 mov     %i1, %o1
F009E9F4: 7ffff9e2                 call    _pmap_remove
F009E9F8: 9410001a                 mov     %i2, %o2
F009E9FC: 30800070                 ba,a    locret_F009EBBC
F009EA00: 7fffe0bf                 call    _splvm
F009EA04: b6062018                 add     %i0, 0x18, %i3
F009EA08: aa100008                 mov     %o0, %l5
F009EA0C: d006c000                 ld      [%i3], %o0
F009EA10: 80a22000                 cmp     %o0, 0
F009EA14: 12bffffe                 bne     loc_F009EA0C
F009EA18: 01000000                 nop
F009EA1C: 7fffe123                 call    _simple_lock_try
F009EA20: 9010001b                 mov     %i3, %o0
F009EA24: 80a22000                 cmp     %o0, 0
F009EA28: 02bffff9                 be      loc_F009EA0C
F009EA2C: 80a6401a                 cmp     %i1, %i2
F009EA30: 1a800060                 bcc     loc_F009EBB0
F009EA34: f227bff4                 st      %i1, [%fp+var_C]
F009EA38: 25000100                 sethi   0x40000, %l2
F009EA3C: 233fff00                 sethi   -0x40000, %l1
F009EA40: 29004000                 sethi   0x1000000, %l4
F009EA44: 273fc000                 sethi   -0x1000000, %l3
F009EA48: 90100018                 mov     %i0, %o0
F009EA4C: d207bff4                 ld      [%fp+var_C], %o1
F009EA50: 7ffff7da                 call    _pmap_page_table_entry
F009EA54: 94102000                 mov     0, %o2
F009EA58: b6920000                 orcc    %o0, %g0, %i3
F009EA5C: 32800007                 bne,a   loc_F009EA78
F009EA60: d00ee00d                 ldub    [%i3+0xD], %o0
F009EA64: d007bff4                 ld      [%fp+var_C], %o0
F009EA68: 90020012                 add     %o0, %l2, %o0
F009EA6C: 900a0011                 and     %o0, %l1, %o0
F009EA70: 1080004c                 ba      loc_F009EBA0
F009EA74: d027bff4                 st      %o0, [%fp+var_C]
F009EA78: 80a22003                 cmp     %o0, 3
F009EA7C: 12800006                 bne     loc_F009EA94
F009EA80: 80a22002                 cmp     %o0, 2
F009EA84: d007bff4                 ld      [%fp+var_C], %o0
F009EA88: 90020012                 add     %o0, %l2, %o0
F009EA8C: 10800007                 ba      loc_F009EAA8
F009EA90: a00a0011                 and     %o0, %l1, %l0
F009EA94: 12800005                 bne     loc_F009EAA8
F009EA98: 213ffff8                 sethi   -0x2000, %l0
F009EA9C: d007bff4                 ld      [%fp+var_C], %o0
F009EAA0: 90020014                 add     %o0, %l4, %o0
F009EAA4: a00a0013                 and     %o0, %l3, %l0
F009EAA8: 80a4001a                 cmp     %l0, %i2
F009EAAC: 38800002                 bgu,a   loc_F009EAB4
F009EAB0: a010001a                 mov     %i2, %l0
F009EAB4: d007bff4                 ld      [%fp+var_C], %o0
F009EAB8: 80a20010                 cmp     %o0, %l0
F009EABC: 1a80003b                 bcc     loc_F009EBA8
F009EAC0: 80a2001a                 cmp     %o0, %i2
F009EAC4: d40ee00d                 ldub    [%i3+0xD], %o2
F009EAC8: 80a2a003                 cmp     %o2, 3
F009EACC: 12800006                 bne     loc_F009EAE4
F009EAD0: 80a2a002                 cmp     %o2, 2
F009EAD4: 9132200a                 srl     %o0, 10, %o0
F009EAD8: d206c000                 ld      [%i3], %o1
F009EADC: 1080000a                 ba      loc_F009EB04
F009EAE0: 900a20fc                 and     %o0, 0xFC, %o0
F009EAE4: 32800006                 bne,a   loc_F009EAFC
F009EAE8: d00fbff4                 ldub    [%fp+var_C], %o0
F009EAEC: d017bff4                 lduh    [%fp+var_C], %o0
F009EAF0: d206c000                 ld      [%i3], %o1
F009EAF4: 10800004                 ba      loc_F009EB04
F009EAF8: 900a20fc                 and     %o0, 0xFC, %o0
F009EAFC: d206c000                 ld      [%i3], %o1
F009EB00: 912a2002                 sll     %o0, 2, %o0
F009EB04: b2024008                 add     %o1, %o0, %i1
F009EB08: d0064000                 ld      [%i1], %o0
F009EB0C: 900a2003                 and     %o0, 3, %o0
F009EB10: 80a22002                 cmp     %o0, 2
F009EB14: 3280000e                 bne,a   loc_F009EB4C
F009EB18: d00ee00d                 ldub    [%i3+0xD], %o0
F009EB1C: 90100018                 mov     %i0, %o0
F009EB20: 40000a62                 call    _vm_to_srmmu_prot
F009EB24: 92102001                 mov     1, %o1
F009EB28: f627bff0                 st      %i3, [%fp+var_10]
F009EB2C: 94100008                 mov     %o0, %o2
F009EB30: d6064000                 ld      [%i1], %o3
F009EB34: 9007bff0                 add     %fp, var_10, %o0
F009EB38: d207bff4                 ld      [%fp+var_C], %o1
F009EB3C: 9732e007                 srl     %o3, 7, %o3
F009EB40: 40000aea                 call    _update_pte
F009EB44: 960ae001                 and     %o3, 1, %o3
F009EB48: d00ee00d                 ldub    [%i3+0xD], %o0
F009EB4C: 80a22003                 cmp     %o0, 3
F009EB50: 1280000a                 bne     loc_F009EB78
F009EB54: 80a22002                 cmp     %o0, 2
F009EB58: 113c04d0                 sethi   %hi(_page_mask), %o0
F009EB5C: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F009EB60: d407bff4                 ld      [%fp+var_C], %o2
F009EB64: 113c0447                 sethi   %hi(_page_size), %o0
F009EB68: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F009EB6C: 922a8009                 andn    %o2, %o1, %o1
F009EB70: 10800009                 ba      loc_F009EB94
F009EB74: 90024008                 add     %o1, %o0, %o0
F009EB78: 12800005                 bne     loc_F009EB8C
F009EB7C: d007bff4                 ld      [%fp+var_C], %o0
F009EB80: 900a0011                 and     %o0, %l1, %o0
F009EB84: 10800004                 ba      loc_F009EB94
F009EB88: 90020012                 add     %o0, %l2, %o0
F009EB8C: 900a0013                 and     %o0, %l3, %o0
F009EB90: 90020014                 add     %o0, %l4, %o0
F009EB94: 80a20010                 cmp     %o0, %l0
F009EB98: 0abfffcb                 bcs     loc_F009EAC4
F009EB9C: d027bff4                 st      %o0, [%fp+var_C]
F009EBA0: d007bff4                 ld      [%fp+var_C], %o0
F009EBA4: 80a2001a                 cmp     %o0, %i2
F009EBA8: 0abfffa9                 bcs     loc_F009EA4C
F009EBAC: 90100018                 mov     %i0, %o0
F009EBB0: c0262018                 clr     [%i0+0x18]
F009EBB4: 7fffe05c                 call    _splx
F009EBB8: 90100015                 mov     %l5, %o0
F009EBBC: 81c7e008                 ret
F009EBC0: 81e80000                 restore
