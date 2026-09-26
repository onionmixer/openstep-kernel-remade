F009A9F4: 9de3bf90                 save    %sp, -0x70, %sp
F009A9F8: 7fffece3                 call    _swift_vac_init_asm
F009A9FC: 01000000                 nop
F009AA00: 153c04f7                 sethi   %hi(_vac_mode), %o2
F009AA04: 113c045d90122170         set     aWritethru, %o0! "WRITETHRU"
F009AA0C: 133c045d                 sethi   %hi(_swift_kdnx), %o1
F009AA10: d2026164                 ld      [%o1+%lo(_swift_kdnx)], %o1
F009AA14: 80a26001                 cmp     %o1, 1
F009AA18: 12800039                 bne     locret_F009AAFC
F009AA1C: d022a1f8                 st      %o0, [%o2+%lo(_vac_mode)]
F009AA20: 133fbf80                 sethi   -0x1020000, %o1
F009AA24: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F009AA28: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F009AA2C: 400007e3                 call    _pmap_page_table_entry
F009AA30: 94102000                 mov     0, %o2
F009AA34: 92100008                 mov     %o0, %o1
F009AA38: 113fbf80                 sethi   -0x1020000, %o0
F009AA3C: d027bff4                 st      %o0, [%fp+var_C]
F009AA40: d00a600d                 ldub    [%o1+0xD], %o0
F009AA44: 80a22003                 cmp     %o0, 3
F009AA48: 12800005                 bne     loc_F009AA5C
F009AA4C: 80a22002                 cmp     %o0, 2
F009AA50: d0024000                 ld      [%o1], %o0
F009AA54: 1080000a                 ba      loc_F009AA7C
F009AA58: 98022080                 add     %o0, 0x80, %o4
F009AA5C: 12800005                 bne     loc_F009AA70
F009AA60: d00fbff4                 ldub    [%fp+var_C], %o0
F009AA64: d0024000                 ld      [%o1], %o0
F009AA68: 10800005                 ba      loc_F009AA7C
F009AA6C: 980220fc                 add     %o0, 0xFC, %o4
F009AA70: d2024000                 ld      [%o1], %o1
F009AA74: 912a2002                 sll     %o0, 2, %o0
F009AA78: 98024008                 add     %o1, %o0, %o4
F009AA7C: 133fbfa8                 sethi   -0x1016000, %o1
F009AA80: 94102000                 mov     0, %o2
F009AA84: d6030000                 ld      [%o4], %o3
F009AA88: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F009AA8C: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F009AA90: 960affe3                 and     %o3, -0x1D, %o3
F009AA94: 9612e014                 bset    0x14, %o3
F009AA98: 400007c8                 call    _pmap_page_table_entry
F009AA9C: d6230000                 st      %o3, [%o4]
F009AAA0: 92100008                 mov     %o0, %o1
F009AAA4: 113fbfa8                 sethi   -0x1016000, %o0
F009AAA8: d027bff4                 st      %o0, [%fp+var_C]
F009AAAC: d00a600d                 ldub    [%o1+0xD], %o0
F009AAB0: 80a22003                 cmp     %o0, 3
F009AAB4: 12800005                 bne     loc_F009AAC8
F009AAB8: 80a22002                 cmp     %o0, 2
F009AABC: d0024000                 ld      [%o1], %o0
F009AAC0: 1080000a                 ba      loc_F009AAE8
F009AAC4: 980220a8                 add     %o0, 0xA8, %o4
F009AAC8: 12800005                 bne     loc_F009AADC
F009AACC: d00fbff4                 ldub    [%fp+var_C], %o0
F009AAD0: d0024000                 ld      [%o1], %o0
F009AAD4: 10800005                 ba      loc_F009AAE8
F009AAD8: 980220fc                 add     %o0, 0xFC, %o4
F009AADC: d2024000                 ld      [%o1], %o1
F009AAE0: 912a2002                 sll     %o0, 2, %o0
F009AAE4: 98024008                 add     %o1, %o0, %o4
F009AAE8: d0030000                 ld      [%o4], %o0
F009AAEC: 900a3fe3                 and     %o0, -0x1D, %o0
F009AAF0: 90122014                 bset    0x14, %o0
F009AAF4: 7fffead6                 call    _mmu_flushall
F009AAF8: d0230000                 st      %o0, [%o4]
F009AAFC: 81c7e008                 ret
F009AB00: 81e80000                 restore
