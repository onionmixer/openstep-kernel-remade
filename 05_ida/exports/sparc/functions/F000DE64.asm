F000DE64: 9de3bf80                 save    %sp, -0x80, %sp
F000DE68: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000DE6C: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F000DE70: ea022024                 ld      [%o0+0x24], %l5
F000DE74: e4056004                 ld      [%l5+4], %l2
F000DE78: d0056010                 ld      [%l5+0x10], %o0
F000DE7C: d4054000                 ld      [%l5], %o2
F000DE80: ee056014                 ld      [%l5+0x14], %l7
F000DE84: 9207bff4                 add     %fp, var_C, %o1
F000DE88: f0056008                 ld      [%l5+8], %i0
F000DE8C: 40006ae3                 call    _getvnodefp
F000DE90: d427bff0                 st      %o2, [%fp+address]
F000DE94: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F000DE98: d02a6038                 stb     %o0, [%o1+0x38]
F000DE9C: d80421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o4
F000DEA0: d04b2038                 ldsb    [%o4+0x38], %o0
F000DEA4: 80a22000                 cmp     %o0, 0
F000DEA8: 128000ed                 bne     locret_F000E25C
F000DEAC: d607bff4                 ld      [%fp+var_C], %o3
F000DEB0: d052e00c                 ldsh    [%o3+0xC], %o0
F000DEB4: 80a22001                 cmp     %o0, 1
F000DEB8: 12800012                 bne     loc_F000DF00
F000DEBC: 90102016                 mov     0x16, %o0
F000DEC0: 113c04d0                 sethi   %hi(_page_mask), %o0
F000DEC4: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F000DEC8: 808e2002                 btst    2, %i0
F000DECC: e002e018                 ld      [%o3+0x18], %l0
F000DED0: 94380009                 xnor    %g0, %o1, %o2
F000DED4: 92048009                 add     %l2, %o1, %o1
F000DED8: d007bff0                 ld      [%fp+address], %o0
F000DEDC: a40a400a                 and     %o1, %o2, %l2
F000DEE0: 900a000a                 and     %o0, %o2, %o0
F000DEE4: 02800009                 be      loc_F000DF08
F000DEE8: d027bff0                 st      %o0, [%fp+address]
F000DEEC: d002e008                 ld      [%o3+8], %o0
F000DEF0: 808a2002                 btst    2, %o0
F000DEF4: 12800006                 bne     loc_F000DF0C
F000DEF8: 808e2001                 btst    1, %i0
F000DEFC: 90102016                 mov     0x16, %o0
F000DF00: 108000d7                 ba      locret_F000E25C
F000DF04: d02b2038                 stb     %o0, [%o4+0x38]
F000DF08: 808e2001                 btst    1, %i0
F000DF0C: 02800007                 be      loc_F000DF28
F000DF10: 113c04d0                 sethi   -0xFECC000, %o0
F000DF14: d007bff4                 ld      [%fp+var_C], %o0
F000DF18: d0022008                 ld      [%o0+8], %o0
F000DF1C: 808a2001                 btst    1, %o0
F000DF20: 028000c3                 be      loc_F000E22C
F000DF24: 113c04d0                 sethi   -0xFECC000, %o0
F000DF28: d0022260                 ld      [%o0+0x260], %o0
F000DF2C: d207bff0                 ld      [%fp+address], %o1
F000DF30: d002200c                 ld      [%o0+0xC], %o0
F000DF34: 96102003                 mov     3, %o3
F000DF38: e802200c                 ld      [%o0+0xC], %l4
F000DF3C: 94024012                 add     %o1, %l2, %o2
F000DF40: 4001dd1b                 call    _vm_map_check_protection
F000DF44: 90100014                 mov     %l4, %o0
F000DF48: 80a22000                 cmp     %o0, 0
F000DF4C: 028000b9                 be      loc_F000E230
F000DF50: 113c04cf                 sethi   -0xFECC400, %o0
F000DF54: d0042028                 ld      [%l0+0x28], %o0
F000DF58: 80a22004                 cmp     %o0, 4
F000DF5C: 02800004                 be      loc_F000DF6C
F000DF60: 80a22009                 cmp     %o0, 9
F000DF64: 1280004d                 bne     loc_F000E098
F000DF68: 80a22001                 cmp     %o0, 1
F000DF6C: d0042030                 ld      [%l0+0x30], %o0
F000DF70: f2122042                 lduh    [%o0+0x42], %i1
F000DF74: 952e6010                 sll     %i1, 16, %o2
F000DF78: 9332a018                 srl     %o2, 24, %o1
F000DF7C: 912a6001                 sll     %o1, 1, %o0
F000DF80: 90020009                 add     %o0, %o1, %o0
F000DF84: 912a2002                 sll     %o0, 2, %o0
F000DF88: 90220009                 sub     %o0, %o1, %o0
F000DF8C: 912a2002                 sll     %o0, 2, %o0
F000DF90: 133c0472921261f0         set     _cdevsw, %o1
F000DF98: 90020009                 add     %o0, %o1, %o0
F000DF9C: 133c0055                 sethi   %hi(_nulldev), %o1
F000DFA0: e2022020                 ld      [%o0+0x20], %l1
F000DFA4: 9212604c                 bset    %lo(_nulldev), %o1
F000DFA8: 80a44009                 cmp     %l1, %o1
F000DFAC: 028000a0                 be      loc_F000E22C
F000DFB0: 113c0055                 sethi   %hi(_nodev), %o0
F000DFB4: 90122040                 bset    %lo(_nodev), %o0
F000DFB8: 80a44008                 cmp     %l1, %o0
F000DFBC: 0280009c                 be      loc_F000E22C
F000DFC0: 80a46000                 cmp     %l1, 0
F000DFC4: 0280009a                 be      loc_F000E22C
F000DFC8: a0102000                 mov     0, %l0
F000DFCC: d0056004                 ld      [%l5+4], %o0
F000DFD0: 80a40008                 cmp     %l0, %o0
F000DFD4: 36800011                 bge,a   loc_F000E018
F000DFD8: d005600c                 ld      [%l5+0xC], %o0
F000DFDC: a610000a                 mov     %o2, %l3
F000DFE0: 2d3c0447                 sethi   -0xFEEE400, %l6
F000DFE4: 913ce010                 sra     %l3, 16, %o0
F000DFE8: 9205c010                 add     %l7, %l0, %o1
F000DFEC: 9fc44000                 call    %l1
F000DFF0: 94100018                 mov     %i0, %o2! size
F000DFF4: 80a23fff                 cmp     %o0, -1
F000DFF8: 0280008d                 be      loc_F000E22C
F000DFFC: d005a13c                 ld      [%l6+0x13C], %o0
F000E000: d2056004                 ld      [%l5+4], %o1
F000E004: a0040008                 add     %l0, %o0, %l0
F000E008: 80a40009                 cmp     %l0, %o1
F000E00C: 06bffff7                 bl      loc_F000DFE8
F000E010: 913ce010                 sra     %l3, 16, %o0
F000E014: d005600c                 ld      [%l5+0xC], %o0
F000E018: 80a22001                 cmp     %o0, 1
F000E01C: 12800085                 bne     loc_F000E230
F000E020: 113c04cf                 sethi   -0xFECC400, %o0
F000E024: 90100014                 mov     %l4, %o0! target_task
F000E028: d207bff0                 ld      [%fp+address], %o1! address
F000E02C: 4001f21d                 call    _vm_deallocate
F000E030: 94100012                 mov     %l2, %o2
F000E034: 80a22000                 cmp     %o0, 0
F000E038: 1280007e                 bne     loc_F000E230
F000E03C: 113c04cf                 sethi   -0xFECC400, %o0
F000E040: 912e6010                 sll     %i1, 16, %o0
F000E044: 913a2010                 sra     %o0, 16, %o0
F000E048: 92100011                 mov     %l1, %o1
F000E04C: 94100018                 mov     %i0, %o2
F000E050: 96100017                 mov     %l7, %o3
F000E054: 4001f0d3                 call    _vm_object_special
F000E058: 98100012                 mov     %l2, %o4
F000E05C: a0100008                 mov     %o0, %l0
F000E060: 90100014                 mov     %l4, %o0
F000E064: 92100010                 mov     %l0, %o1
F000E068: 94102000                 mov     0, %o2
F000E06C: 9607bff0                 add     %fp, address, %o3
F000E070: 98100012                 mov     %l2, %o4
F000E074: 4001d957                 call    _vm_map_find
F000E078: 9a102000                 mov     0, %o5
F000E07C: 80a22000                 cmp     %o0, 0
F000E080: 02800051                 be      loc_F000E1C4
F000E084: 808e2002                 btst    2, %i0
F000E088: 4001e20c                 call    _vm_object_deallocate
F000E08C: 90100010                 mov     %l0, %o0
F000E090: 10800068                 ba      loc_F000E230
F000E094: 113c04cf                 sethi   -0xFECC400, %o0
F000E098: 12800066                 bne     loc_F000E230
F000E09C: 113c04cf                 sethi   -0xFECC400, %o0
F000E0A0: 90100010                 mov     %l0, %o0
F000E0A4: 92102000                 mov     0, %o1
F000E0A8: 4001f525                 call    _vnode_pager_setup
F000E0AC: 94102000                 mov     0, %o2
F000E0B0: d6040000                 ld      [%l0], %o3
F000E0B4: d202e030                 ld      [%o3+0x30], %o1
F000E0B8: 80a26000                 cmp     %o1, 0
F000E0BC: 1280000b                 bne     loc_F000E0E8
F000E0C0: a0100008                 mov     %o0, %l0
F000E0C4: 153c04cf                 sethi   %hi(_active_u), %o2! size
F000E0C8: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F000E0CC: d202201c                 ld      [%o0+0x1C], %o1
F000E0D0: d0124000                 lduh    [%o1], %o0
F000E0D4: 90022001                 inc     %o0
F000E0D8: d0324000                 sth     %o0, [%o1]
F000E0DC: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F000E0E0: d002201c                 ld      [%o0+0x1C], %o0
F000E0E4: d022e030                 st      %o0, [%o3+0x30]
F000E0E8: d005600c                 ld      [%l5+0xC], %o0
F000E0EC: 80a22001                 cmp     %o0, 1
F000E0F0: 12800011                 bne     loc_F000E134
F000E0F4: 90100014                 mov     %l4, %o0! target_task
F000E0F8: d207bff0                 ld      [%fp+address], %o1! address
F000E0FC: 4001f1e9                 call    _vm_deallocate
F000E100: 94100012                 mov     %l2, %o2
F000E104: 90100014                 mov     %l4, %o0
F000E108: 9207bff0                 add     %fp, address, %o1
F000E10C: 94100012                 mov     %l2, %o2
F000E110: 96102000                 mov     0, %o3
F000E114: 98100010                 mov     %l0, %o4
F000E118: 4001f183                 call    _vm_allocate_with_pager
F000E11C: 9a100017                 mov     %l7, %o5
F000E120: a0920000                 orcc    %o0, %g0, %l0
F000E124: 02800028                 be      loc_F000E1C4
F000E128: 808e2002                 btst    2, %i0
F000E12C: 10800020                 ba      loc_F000E1AC
F000E130: 113c04cf                 sethi   -0xFECC400, %o0
F000E134: 400239a3                 call    _pmap_create
F000E138: 90100012                 mov     %l2, %o0
F000E13C: 92102000                 mov     0, %o1
F000E140: 94100012                 mov     %l2, %o2
F000E144: 4001d7db                 call    _vm_map_create
F000E148: 96102001                 mov     1, %o3
F000E14C: c027bfec                 clr     [%fp+var_14]
F000E150: a2100008                 mov     %o0, %l1
F000E154: 9207bfec                 add     %fp, var_14, %o1
F000E158: 94100012                 mov     %l2, %o2
F000E15C: 96102000                 mov     0, %o3
F000E160: 98100010                 mov     %l0, %o4
F000E164: 4001f170                 call    _vm_allocate_with_pager
F000E168: 9a100017                 mov     %l7, %o5
F000E16C: a0920000                 orcc    %o0, %g0, %l0
F000E170: 1280000c                 bne     loc_F000E1A0
F000E174: 90100014                 mov     %l4, %o0
F000E178: 92100011                 mov     %l1, %o1
F000E17C: 96100012                 mov     %l2, %o3
F000E180: 98102000                 mov     0, %o4! new_protection
F000E184: d407bff0                 ld      [%fp+address], %o2
F000E188: 9a102000                 mov     0, %o5
F000E18C: 4001dd29                 call    _vm_map_copy
F000E190: c023a05c                 clr     [%sp+0x80+var_24]
F000E194: a0920000                 orcc    %o0, %g0, %l0
F000E198: 02800008                 be      loc_F000E1B8
F000E19C: 01000000                 nop
F000E1A0: 4001d81b                 call    _vm_map_deallocate
F000E1A4: 90100011                 mov     %l1, %o0
F000E1A8: 113c04cf                 sethi   -0xFECC400, %o0
F000E1AC: d00221dc                 ld      [%o0+0x1DC], %o0
F000E1B0: 1080002b                 ba      locret_F000E25C
F000E1B4: e02a2038                 stb     %l0, [%o0+0x38]
F000E1B8: 4001d815                 call    _vm_map_deallocate
F000E1BC: 90100011                 mov     %l1, %o0
F000E1C0: 808e2002                 btst    2, %i0
F000E1C4: 3280000c                 bne,a   loc_F000E1F4
F000E1C8: d005600c                 ld      [%l5+0xC], %o0
F000E1CC: 90100014                 mov     %l4, %o0! target_task
F000E1D0: d207bff0                 ld      [%fp+address], %o1! address
F000E1D4: 94100012                 mov     %l2, %o2! size
F000E1D8: 96102000                 mov     0, %o3! set_maximum
F000E1DC: 4001f1d8                 call    _vm_protect
F000E1E0: 98102001                 mov     1, %o4
F000E1E4: 80a22000                 cmp     %o0, 0
F000E1E8: 1280000e                 bne     loc_F000E220
F000E1EC: 90100014                 mov     %l4, %o0
F000E1F0: d005600c                 ld      [%l5+0xC], %o0
F000E1F4: 80a22001                 cmp     %o0, 1
F000E1F8: 12800013                 bne     loc_F000E244
F000E1FC: 113c04cf                 sethi   -0xFECC400, %o0
F000E200: 90100014                 mov     %l4, %o0! target_task
F000E204: d207bff0                 ld      [%fp+address], %o1! address
F000E208: 94100012                 mov     %l2, %o2! size
F000E20C: 4001f1ba                 call    _vm_inherit
F000E210: 96102000                 mov     0, %o3
F000E214: 80a22000                 cmp     %o0, 0
F000E218: 0280000a                 be      loc_F000E240
F000E21C: 90100014                 mov     %l4, %o0! target_task
F000E220: d207bff0                 ld      [%fp+address], %o1! address
F000E224: 4001f19f                 call    _vm_deallocate
F000E228: 94100012                 mov     %l2, %o2
F000E22C: 113c04cf                 sethi   -0xFECC400, %o0
F000E230: d20221dc                 ld      [%o0+0x1DC], %o1
F000E234: 90102016                 mov     0x16, %o0
F000E238: 10800009                 ba      locret_F000E25C
F000E23C: d02a6038                 stb     %o0, [%o1+0x38]
F000E240: 113c04cf                 sethi   -0xFECC400, %o0
F000E244: d00221d8                 ld      [%o0+0x1D8], %o0
F000E248: d2056010                 ld      [%l5+0x10], %o1
F000E24C: d4022150                 ld      [%o0+0x150], %o2
F000E250: d00a8009                 ldub    [%o2+%o1], %o0
F000E254: 90122002                 bset    2, %o0
F000E258: d02a8009                 stb     %o0, [%o2+%o1]
F000E25C: 81c7e008                 ret
F000E260: 81e80000                 restore
