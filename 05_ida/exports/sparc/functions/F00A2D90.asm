F00A2D90: 9de3bf98                 save    %sp, -0x68, %sp
F00A2D94: 133c04f792126270         set     _pmap_info, %o1
F00A2D9C: d00260f8                 ld      [%o1+0xF8], %o0
F00A2DA0: 90022001                 inc     %o0
F00A2DA4: d02260f8                 st      %o0, [%o1+0xF8]
F00A2DA8: d2062008                 ld      [%i0+8], %o1
F00A2DAC: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00A2DB0: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00A2DB4: 80a24008                 cmp     %o1, %o0
F00A2DB8: 0280000a                 be      loc_F00A2DE0
F00A2DBC: 113c04f8                 sethi   %hi(_kernel_seg_entries), %o0
F00A2DC0: d00220d8                 ld      [%o0+%lo(_kernel_seg_entries)], %o0
F00A2DC4: 80a60008                 cmp     %i0, %o0
F00A2DC8: 0a800009                 bcs     loc_F00A2DEC
F00A2DCC: 113c04f8                 sethi   %hi(_kernel_seg_entries_end), %o0
F00A2DD0: d00220e0                 ld      [%o0+%lo(_kernel_seg_entries_end)], %o0
F00A2DD4: 80a60008                 cmp     %i0, %o0
F00A2DD8: 18800005                 bgu     loc_F00A2DEC
F00A2DDC: 01000000                 nop
F00A2DE0: 7ffffe7d                 call    _pmap_dealloc_kseg_entry
F00A2DE4: 90100018                 mov     %i0, %o0
F00A2DE8: 3080008d                 ba,a    locret_F00A301C
F00A2DEC: 7fffeb86                 call    _check_ptbl
F00A2DF0: 90100018                 mov     %i0, %o0
F00A2DF4: 80a22000                 cmp     %o0, 0
F00A2DF8: 02800004                 be      loc_F00A2E08
F00A2DFC: 113c0464                 sethi   %hi(aPmapDeallocSeg_1), %o0! "pmap_dealloc_seg_entry: page_table non-"...
F00A2E00: 7ffdc8dc                 call    _panic
F00A2E04: 901221c8                 bset    %lo(aPmapDeallocSeg_1), %o0! "pmap_dealloc_seg_entry: page_table non-"...
F00A2E08: d00e200f                 ldub    [%i0+0xF], %o0
F00A2E0C: 80a22000                 cmp     %o0, 0
F00A2E10: 02800004                 be      loc_F00A2E20
F00A2E14: 113c0464                 sethi   %hi(aPmapDeallocSeg_2), %o0! "pmap_dealloc_seg_entry(valid)"
F00A2E18: 7ffdc8d6                 call    _panic
F00A2E1C: 901221f8                 bset    %lo(aPmapDeallocSeg_2), %o0! "pmap_dealloc_seg_entry(valid)"
F00A2E20: d0062010                 ld      [%i0+0x10], %o0
F00A2E24: 80a22000                 cmp     %o0, 0
F00A2E28: 12800006                 bne     loc_F00A2E40
F00A2E2C: 113c0464                 sethi   -0xFEE7000, %o0
F00A2E30: d0062014                 ld      [%i0+0x14], %o0
F00A2E34: 80a22000                 cmp     %o0, 0
F00A2E38: 02800004                 be      loc_F00A2E48
F00A2E3C: 113c0464                 sethi   -0xFEE7000, %o0! char *
F00A2E40: 7ffdc8cc                 call    _panic
F00A2E44: 90122218                 bset    0x218, %o0
F00A2E48: d00e200d                 ldub    [%i0+0xD], %o0
F00A2E4C: 80a22003                 cmp     %o0, 3
F00A2E50: 12800017                 bne     loc_F00A2EAC
F00A2E54: 80a22002                 cmp     %o0, 2
F00A2E58: d0062008                 ld      [%i0+8], %o0
F00A2E5C: 92102fff                 mov     0xFFF, %o1
F00A2E60: d2222010                 st      %o1, [%o0+0x10]
F00A2E64: d0062008                 ld      [%i0+8], %o0
F00A2E68: c0222008                 clr     [%o0+8]
F00A2E6C: e0062020                 ld      [%i0+0x20], %l0
F00A2E70: 80a42000                 cmp     %l0, 0
F00A2E74: 0280001c                 be      loc_F00A2EE4
F00A2E78: 90100010                 mov     %l0, %o0
F00A2E7C: d4062024                 ld      [%i0+0x24], %o2
F00A2E80: 133fff00                 sethi   -0x40000, %o1
F00A2E84: 7ffffb5c                 call    _set_invalidptp
F00A2E88: 920a8009                 and     %o2, %o1, %o1
F00A2E8C: d00c200f                 ldub    [%l0+0xF], %o0
F00A2E90: 80a22000                 cmp     %o0, 0
F00A2E94: 32800015                 bne,a   loc_F00A2EE8
F00A2E98: c0262008                 clr     [%i0+8]
F00A2E9C: 7fffffbd                 call    _pmap_dealloc_seg_entry
F00A2EA0: 90100010                 mov     %l0, %o0
F00A2EA4: 10800011                 ba      loc_F00A2EE8
F00A2EA8: c0262008                 clr     [%i0+8]
F00A2EAC: 3280000f                 bne,a   loc_F00A2EE8
F00A2EB0: c0262008                 clr     [%i0+8]
F00A2EB4: d0062008                 ld      [%i0+8], %o0
F00A2EB8: 92102fff                 mov     0xFFF, %o1
F00A2EBC: d222200c                 st      %o1, [%o0+0xC]
F00A2EC0: d0062008                 ld      [%i0+8], %o0
F00A2EC4: c0222004                 clr     [%o0+4]
F00A2EC8: d0062020                 ld      [%i0+0x20], %o0
F00A2ECC: 80a22000                 cmp     %o0, 0
F00A2ED0: 02800005                 be      loc_F00A2EE4
F00A2ED4: 133fc000                 sethi   -0x1000000, %o1
F00A2ED8: d4062024                 ld      [%i0+0x24], %o2
F00A2EDC: 7ffffb46                 call    _set_invalidptp
F00A2EE0: 920a8009                 and     %o2, %o1, %o1
F00A2EE4: c0262008                 clr     [%i0+8]
F00A2EE8: 133c04f792126270         set     _pmap_info, %o1
F00A2EF0: d0026018                 ld      [%o1+0x18], %o0
F00A2EF4: 90023fff                 inc     -1, %o0
F00A2EF8: d0226018                 st      %o0, [%o1+0x18]
F00A2EFC: f0062004                 ld      [%i0+4], %i0
F00A2F00: d016201e                 lduh    [%i0+0x1E], %o0
F00A2F04: 80a22000                 cmp     %o0, 0
F00A2F08: 1280000d                 bne     loc_F00A2F3C
F00A2F0C: 90022001                 inc     %o0
F00A2F10: d036201e                 sth     %o0, [%i0+0x1E]
F00A2F14: 113c04f7901223c0         set     _seg_active, %o0
F00A2F1C: 7ffff94d                 call    _del_any_pool
F00A2F20: 92100018                 mov     %i0, %o1
F00A2F24: 113c04f7901223e0         set     _seg_semi_active, %o0
F00A2F2C: 7ffff924                 call    _add_pool
F00A2F30: 92100018                 mov     %i0, %o1
F00A2F34: 10800004                 ba      loc_F00A2F44
F00A2F38: d216201e                 lduh    [%i0+0x1E], %o1
F00A2F3C: d036201e                 sth     %o0, [%i0+0x1E]
F00A2F40: d216201e                 lduh    [%i0+0x1E], %o1
F00A2F44: d016201c                 lduh    [%i0+0x1C], %o0
F00A2F48: 80a24008                 cmp     %o1, %o0
F00A2F4C: 12800034                 bne     locret_F00A301C
F00A2F50: 133c04f7                 sethi   %hi(dword_F013DFE8), %o1
F00A2F54: d00263e8                 ld      [%o1+%lo(dword_F013DFE8)], %o0
F00A2F58: 80a22064                 cmp     %o0, 0x64 ! 'd'
F00A2F5C: 04800030                 ble     locret_F00A301C
F00A2F60: 901263e8                 or      %o1, %lo(dword_F013DFE8), %o0
F00A2F64: 90023ff8                 inc     -8, %o0
F00A2F68: 7ffff93a                 call    _del_any_pool
F00A2F6C: 92100018                 mov     %i0, %o1
F00A2F70: 7fff8cf2                 call    _vm_mem_ppi
F00A2F74: d0062004                 ld      [%i0+4], %o0
F00A2F78: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F00A2F7C: 932a2002                 sll     %o0, 2, %o1
F00A2F80: 92024008                 add     %o1, %o0, %o1
F00A2F84: d602a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o3
F00A2F88: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F00A2F8C: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F00A2F90: 952a6002                 sll     %o1, 2, %o2
F00A2F94: a002c00a                 add     %o3, %o2, %l0
F00A2F98: d2042004                 ld      [%l0+4], %o1
F00A2F9C: 80a24008                 cmp     %o1, %o0
F00A2FA0: 1280000d                 bne     loc_F00A2FD4
F00A2FA4: 113c0464                 sethi   -0xFEE7000, %o0
F00A2FA8: d0042008                 ld      [%l0+8], %o0
F00A2FAC: d2062008                 ld      [%i0+8], %o1
F00A2FB0: 91322008                 srl     %o0, 8, %o0
F00A2FB4: 912a200c                 sll     %o0, 12, %o0
F00A2FB8: 80a20009                 cmp     %o0, %o1
F00A2FBC: 12800006                 bne     loc_F00A2FD4
F00A2FC0: 113c0464                 sethi   -0xFEE7000, %o0
F00A2FC4: d002c00a                 ld      [%o3+%o2], %o0
F00A2FC8: 80a22000                 cmp     %o0, 0
F00A2FCC: 02800004                 be      loc_F00A2FDC
F00A2FD0: 113c0464                 sethi   -0xFEE7000, %o0! char *
F00A2FD4: 7ffdc867                 call    _panic
F00A2FD8: 90122238                 bset    0x238, %o0
F00A2FDC: c024200c                 clr     [%l0+0xC]
F00A2FE0: d0062008                 ld      [%i0+8], %o0
F00A2FE4: 7fff8228                 call    _kmem_free
F00A2FE8: c0260000                 clr     [%i0]
F00A2FEC: 173c04f79612e270         set     _pmap_info, %o3
F00A2FF4: 113c04f7                 sethi   %hi(_seg_free), %o0
F00A2FF8: d812e004                 lduh    [%o3+4], %o4
F00A2FFC: 901223d0                 bset    %lo(_seg_free), %o0
F00A3000: d402e01c                 ld      [%o3+0x1C], %o2
F00A3004: 92100018                 mov     %i0, %o1
F00A3008: 9422800c                 sub     %o2, %o4, %o2
F00A300C: d422e01c                 st      %o2, [%o3+0x1C]
F00A3010: c0226008                 clr     [%o1+8]
F00A3014: 7ffff8ea                 call    _add_pool
F00A3018: c0226004                 clr     [%o1+4]
F00A301C: 81c7e008                 ret
F00A3020: 81e80000                 restore
