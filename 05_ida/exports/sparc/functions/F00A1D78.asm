F00A1D78: 9de3bf68                 save    %sp, -0x98, %sp
F00A1D7C: 133c04f790126230         set     _kseg_active, %o0
F00A1D84: d0222004                 st      %o0, [%o0+4]
F00A1D88: d0226230                 st      %o0, [%o1+0x230]
F00A1D8C: c0222008                 clr     [%o0+8]
F00A1D90: 133c04f790126240         set     _kseg_semi_active, %o0
F00A1D98: d0222004                 st      %o0, [%o0+4]
F00A1D9C: d0226240                 st      %o0, [%o1+0x240]
F00A1DA0: c0222008                 clr     [%o0+8]
F00A1DA4: 113c04f8                 sethi   %hi(_kernel_seg_pools), %o0
F00A1DA8: ea0220e8                 ld      [%o0+%lo(_kernel_seg_pools)], %l5
F00A1DAC: 113c04f8                 sethi   %hi(_kernel_seg_entries), %o0
F00A1DB0: e40220d8                 ld      [%o0+%lo(_kernel_seg_entries)], %l2
F00A1DB4: b4100018                 mov     %i0, %i2
F00A1DB8: 113c04f8                 sethi   %hi(_kernel_seg_tables), %o0
F00A1DBC: e80220f0                 ld      [%o0+%lo(_kernel_seg_tables)], %l4
F00A1DC0: b0102000                 mov     0, %i0
F00A1DC4: 113c04f8                 sethi   %hi(_kernel_seg_tables_phys), %o0! void *
F00A1DC8: 80a6001a                 cmp     %i0, %i2
F00A1DCC: 16800031                 bge     loc_F00A1E90
F00A1DD0: ec022100                 ld      [%o0+%lo(_kernel_seg_tables_phys)], %l6
F00A1DD4: 393c0447                 sethi   -0xFEEE400, %i4
F00A1DD8: 333c04f7                 sethi   -0xFEC2400, %i1
F00A1DDC: b6100009                 mov     %o1, %i3
F00A1DE0: a6056018                 add     %l5, 0x18, %l3
F00A1DE4: d207213c                 ld      [%i4+0x13C], %o1! size_t
F00A1DE8: 7fffcc1c                 call    _bzero
F00A1DEC: 90100014                 mov     %l4, %o0
F00A1DF0: 90100015                 mov     %l5, %o0! void *
F00A1DF4: 7fffcc19                 call    _bzero
F00A1DF8: 92102020                 mov     0x20, %o1 ! ' '! size_t
F00A1DFC: e824fff0                 st      %l4, [%l3-0x10]
F00A1E00: ec24ffec                 st      %l6, [%l3-0x14]
F00A1E04: d0166274                 lduh    [%i1+0x274], %o0
F00A1E08: d034e004                 sth     %o0, [%l3+4]
F00A1E0C: d0166274                 lduh    [%i1+0x274], %o0
F00A1E10: d034e006                 sth     %o0, [%l3+6]
F00A1E14: e424c000                 st      %l2, [%l3]
F00A1E18: d0166274                 lduh    [%i1+0x274], %o0
F00A1E1C: a2102000                 mov     0, %l1
F00A1E20: 80a44008                 cmp     %l1, %o0
F00A1E24: 16800014                 bge     loc_F00A1E74
F00A1E28: 9016e240                 or      %i3, 0x240, %o0
F00A1E2C: 2f3c04f7                 sethi   -0xFEC2400, %l7
F00A1E30: a004a00e                 add     %l2, 0xE, %l0
F00A1E34: 90100012                 mov     %l2, %o0! void *
F00A1E38: 7fffcc08                 call    _bzero
F00A1E3C: 92102028                 mov     0x28, %o1 ! '('
F00A1E40: ea243ff6                 st      %l5, [%l0-0xA]
F00A1E44: c02c3fff                 clrb    [%l0-1]
F00A1E48: e22c0000                 stb     %l1, [%l0]
F00A1E4C: e8248000                 st      %l4, [%l2]
F00A1E50: a8052100                 inc     0x100, %l4
F00A1E54: ac05a100                 inc     0x100, %l6
F00A1E58: a0042028                 inc     0x28, %l0 ! '('
F00A1E5C: d015e274                 lduh    [%l7+0x274], %o0
F00A1E60: a2046001                 inc     %l1
F00A1E64: 80a44008                 cmp     %l1, %o0
F00A1E68: 06bffff3                 bl      loc_F00A1E34
F00A1E6C: a404a028                 inc     0x28, %l2 ! '('
F00A1E70: 9016e240                 or      %i3, 0x240, %o0
F00A1E74: 7ffffd52                 call    _add_pool
F00A1E78: 92100015                 mov     %l5, %o1! size_t
F00A1E7C: b0062001                 inc     %i0
F00A1E80: a604e020                 inc     0x20, %l3 ! ' '
F00A1E84: 80a6001a                 cmp     %i0, %i2
F00A1E88: 06bfffd7                 bl      loc_F00A1DE4
F00A1E8C: aa056020                 inc     0x20, %l5 ! ' '
F00A1E90: 233c04f8a0146070         set     _kernel_reg_entry, %l0
F00A1E98: 90100010                 mov     %l0, %o0! void *
F00A1E9C: 7fffcbef                 call    _bzero
F00A1EA0: 92102054                 mov     0x54, %o1 ! 'T'
F00A1EA4: 90102001                 mov     1, %o0
F00A1EA8: d02c200d                 stb     %o0, [%l0+0xD]
F00A1EAC: 153c04f0                 sethi   %hi(_kernel_pmap), %o2
F00A1EB0: 113c04f892122040         set     _kernel_pmap_store, %o1
F00A1EB8: d222a100                 st      %o1, [%o2+%lo(_kernel_pmap)]
F00A1EBC: e0222040                 st      %l0, [%o0+0x40]
F00A1EC0: d2242008                 st      %o1, [%l0+8]
F00A1EC4: 113c04f7                 sethi   %hi(_active_pmap), %o0
F00A1EC8: d2222208                 st      %o1, [%o0+%lo(_active_pmap)]
F00A1ECC: 9607bfd0                 add     %fp, var_30, %o3
F00A1ED0: c027bfcc                 clr     [%fp+var_34]
F00A1ED4: b0102000                 mov     0, %i0
F00A1ED8: 98102001                 mov     1, %o4
F00A1EDC: 113c04f8                 sethi   %hi(_kernel_region), %o0
F00A1EE0: d40220c8                 ld      [%o0+%lo(_kernel_region)], %o2
F00A1EE4: 1b000004                 sethi   0x1000, %o5
F00A1EE8: 113c04f7                 sethi   %hi(_context_table), %o0
F00A1EEC: d0022210                 ld      [%o0+%lo(_context_table)], %o0
F00A1EF0: d4246070                 st      %o2, [%l1+0x70]
F00A1EF4: d0226014                 st      %o0, [%o1+0x14]
F00A1EF8: d2222008                 st      %o1, [%o0+8]
F00A1EFC: 90102001                 mov     1, %o0
F00A1F00: d022601c                 st      %o0, [%o1+0x1C]
F00A1F04: d0226024                 st      %o0, [%o1+0x24]
F00A1F08: d0226020                 st      %o0, [%o1+0x20]
F00A1F0C: c0226018                 clr     [%o1+0x18]
F00A1F10: 90102003                 mov     3, %o0
F00A1F14: d02fbfdd                 stb     %o0, [%fp+var_23]
F00A1F18: c027bfe0                 clr     [%fp+var_20]
F00A1F1C: c027bfe4                 clr     [%fp+var_1C]
F00A1F20: c027bfe8                 clr     [%fp+var_18]
F00A1F24: c027bfec                 clr     [%fp+var_14]
F00A1F28: d00ae00d                 ldub    [%o3+0xD], %o0
F00A1F2C: 80a22003                 cmp     %o0, 3
F00A1F30: 12800009                 bne     loc_F00A1F54
F00A1F34: 80a22002                 cmp     %o0, 2
F00A1F38: d007bfcc                 ld      [%fp+var_34], %o0
F00A1F3C: 9132200c                 srl     %o0, 12, %o0
F00A1F40: 95322003                 srl     %o0, 3, %o2
F00A1F44: 940aa004                 and     %o2, 4, %o2
F00A1F48: 9402800b                 add     %o2, %o3, %o2
F00A1F4C: 1080000d                 ba      loc_F00A1F80
F00A1F50: 900a201e                 and     %o0, 0x1E, %o0
F00A1F54: 12800007                 bne     loc_F00A1F70
F00A1F58: d00fbfcc                 ldub    [%fp+var_34], %o0
F00A1F5C: d007bfcc                 ld      [%fp+var_34], %o0
F00A1F60: 91322012                 srl     %o0, 18, %o0
F00A1F64: 95322003                 srl     %o0, 3, %o2
F00A1F68: 10800004                 ba      loc_F00A1F78
F00A1F6C: 940aa004                 and     %o2, 4, %o2
F00A1F70: 95322005                 srl     %o0, 5, %o2
F00A1F74: 952aa002                 sll     %o2, 2, %o2
F00A1F78: 9402800b                 add     %o2, %o3, %o2
F00A1F7C: 900a201f                 and     %o0, 0x1F, %o0
F00A1F80: d202a010                 ld      [%o2+0x10], %o1
F00A1F84: 912b0008                 sll     %o4, %o0, %o0
F00A1F88: 92124008                 bset    %o0, %o1
F00A1F8C: d222a010                 st      %o1, [%o2+0x10]
F00A1F90: d00ae00d                 ldub    [%o3+0xD], %o0
F00A1F94: 80a22003                 cmp     %o0, 3
F00A1F98: 12800009                 bne     loc_F00A1FBC
F00A1F9C: 80a22002                 cmp     %o0, 2
F00A1FA0: d007bfcc                 ld      [%fp+var_34], %o0
F00A1FA4: 9132200c                 srl     %o0, 12, %o0
F00A1FA8: 95322003                 srl     %o0, 3, %o2
F00A1FAC: 940aa004                 and     %o2, 4, %o2
F00A1FB0: 9402800b                 add     %o2, %o3, %o2
F00A1FB4: 1080000a                 ba      loc_F00A1FDC
F00A1FB8: 900a201e                 and     %o0, 0x1E, %o0
F00A1FBC: 1280000d                 bne     loc_F00A1FF0
F00A1FC0: d00fbfcc                 ldub    [%fp+var_34], %o0
F00A1FC4: d007bfcc                 ld      [%fp+var_34], %o0
F00A1FC8: 91322012                 srl     %o0, 18, %o0
F00A1FCC: 95322003                 srl     %o0, 3, %o2
F00A1FD0: 940aa004                 and     %o2, 4, %o2
F00A1FD4: 9402800b                 add     %o2, %o3, %o2
F00A1FD8: 900a201f                 and     %o0, 0x1F, %o0
F00A1FDC: d202a018                 ld      [%o2+0x18], %o1
F00A1FE0: 912b0008                 sll     %o4, %o0, %o0
F00A1FE4: 92124008                 bset    %o0, %o1
F00A1FE8: 1080000a                 ba      loc_F00A2010
F00A1FEC: d222a018                 st      %o1, [%o2+0x18]
F00A1FF0: 95322005                 srl     %o0, 5, %o2
F00A1FF4: 952aa002                 sll     %o2, 2, %o2
F00A1FF8: 9402800b                 add     %o2, %o3, %o2
F00A1FFC: 900a201f                 and     %o0, 0x1F, %o0
F00A2000: d202a030                 ld      [%o2+0x30], %o1
F00A2004: 912b0008                 sll     %o4, %o0, %o0
F00A2008: 92124008                 bset    %o0, %o1
F00A200C: d222a030                 st      %o1, [%o2+0x30]
F00A2010: b0062001                 inc     %i0
F00A2014: d007bfcc                 ld      [%fp+var_34], %o0
F00A2018: 80a6203f                 cmp     %i0, 0x3F ! '?'
F00A201C: 9002000d                 add     %o0, %o5, %o0
F00A2020: 04bfffc2                 ble     loc_F00A1F28
F00A2024: d027bfcc                 st      %o0, [%fp+var_34]
F00A2028: d207bfe0                 ld      [%fp+var_20], %o1
F00A202C: 113c04f8                 sethi   %hi(_wmap0), %o0
F00A2030: d2222030                 st      %o1, [%o0+%lo(_wmap0)]
F00A2034: d207bfe4                 ld      [%fp+var_1C], %o1
F00A2038: 113c04f8                 sethi   %hi(_wmap1), %o0
F00A203C: d2222038                 st      %o1, [%o0+%lo(_wmap1)]
F00A2040: d207bfe8                 ld      [%fp+var_18], %o1
F00A2044: 113c04f7                 sethi   %hi(_mmap0), %o0
F00A2048: d2222250                 st      %o1, [%o0+%lo(_mmap0)]
F00A204C: d207bfec                 ld      [%fp+var_14], %o1
F00A2050: 113c04f7                 sethi   %hi(_mmap1), %o0
F00A2054: d2222258                 st      %o1, [%o0+%lo(_mmap1)]
F00A2058: 81c7e008                 ret
F00A205C: 81e80000                 restore
