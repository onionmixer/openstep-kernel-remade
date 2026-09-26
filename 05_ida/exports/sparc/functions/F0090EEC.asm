F0090EEC: 9de3bf88                 save    %sp, -0x78, %sp
F0090EF0: 80a62000                 cmp     %i0, 0
F0090EF4: 12800004                 bne     loc_F0090F04
F0090EF8: 9a10001d                 mov     %i5, %o5
F0090EFC: 1080002f                 ba      locret_F0090FB8
F0090F00: b0103d3f                 mov     -0x2C1, %i0
F0090F04: 912f6018                 sll     %i5, 24, %o0
F0090F08: 80a22000                 cmp     %o0, 0
F0090F0C: 02800004                 be      loc_F0090F1C
F0090F10: f206600c                 ld      [%i1+0xC], %i1
F0090F14: 10800006                 ba      loc_F0090F2C
F0090F18: d0066014                 ld      [%i1+0x14], %o0
F0090F1C: 113c04d0                 sethi   %hi(_page_mask), %o0
F0090F20: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F0090F24: d2070000                 ld      [%i4], %o1
F0090F28: 902a4008                 andn    %o1, %o0, %o0
F0090F2C: d0270000                 st      %o0, [%i4]
F0090F30: 90100019                 mov     %i1, %o0
F0090F34: 92102000                 mov     0, %o1
F0090F38: 94102000                 mov     0, %o2
F0090F3C: 9610001c                 mov     %i4, %o3
F0090F40: 9810001b                 mov     %i3, %o4
F0090F44: 9b2b6018                 sll     %o5, 24, %o5
F0090F48: 7fffcda2                 call    _vm_map_find
F0090F4C: 9b3b6018                 sra     %o5, 24, %o5
F0090F50: 80a22000                 cmp     %o0, 0
F0090F54: 12800019                 bne     locret_F0090FB8
F0090F58: b0103d25                 mov     -0x2DB, %i0
F0090F5C: 90100019                 mov     %i1, %o0
F0090F60: 133c04d0                 sethi   %hi(_page_mask), %o1
F0090F64: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F0090F68: 96102002                 mov     2, %o3
F0090F6C: e0070000                 ld      [%i4], %l0
F0090F70: 94380009                 xnor    %g0, %o1, %o2
F0090F74: a00c000a                 and     %l0, %o2, %l0
F0090F78: 9206c009                 add     %i3, %o1, %o1
F0090F7C: b60a400a                 and     %o1, %o2, %i3
F0090F80: 92100010                 mov     %l0, %o1
F0090F84: 7fffcf55                 call    _vm_map_inherit
F0090F88: 9404001b                 add     %l0, %i3, %o2
F0090F8C: 92100010                 mov     %l0, %o1
F0090F90: 940ebf00                 and     %i2, -0x100, %o2
F0090F94: 960ea00f                 and     %i2, 0xF, %o3
F0090F98: 9810001b                 mov     %i3, %o4
F0090F9C: 9a102003                 mov     3, %o5
F0090FA0: d0066024                 ld      [%i1+0x24], %o0
F0090FA4: 84102001                 mov     1, %g2
F0090FA8: c023a05c                 clr     [%sp+0x78+var_1C]
F0090FAC: 4000352a                 call    _pmap_enter_range
F0090FB0: c423a060                 st      %g2, [%sp+0x78+var_18]
F0090FB4: b0102000                 mov     0, %i0
F0090FB8: 81c7e008                 ret
F0090FBC: 81e80000                 restore
