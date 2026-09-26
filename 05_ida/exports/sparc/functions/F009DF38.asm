F009DF38: 9de3bf88                 save    %sp, -0x78, %sp
F009DF3C: f227a048                 st      %i1, [%fp+arg_48]
F009DF40: 80a62000                 cmp     %i0, 0
F009DF44: 02800142                 be      locret_F009E44C
F009DF48: e407a05c                 ld      [%fp+arg_5C], %l2
F009DF4C: 133c04f792126270         set     _pmap_info, %o1
F009DF54: d0026060                 ld      [%o1+0x60], %o0
F009DF58: 80a72000                 cmp     %i4, 0
F009DF5C: 90022001                 inc     %o0
F009DF60: 12800009                 bne     loc_F009DF84
F009DF64: d0226060                 st      %o0, [%o1+0x60]
F009DF68: 133c0447                 sethi   %hi(_page_size), %o1
F009DF6C: d402613c                 ld      [%o1+%lo(_page_size)], %o2
F009DF70: 90100018                 mov     %i0, %o0
F009DF74: 92100019                 mov     %i1, %o1
F009DF78: 7ffffc81                 call    _pmap_remove
F009DF7C: 9402400a                 add     %o1, %o2, %o2
F009DF80: 30800133                 ba,a    locret_F009E44C
F009DF84: 113c0447                 sethi   %hi(_page_size), %o0
F009DF88: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F009DF8C: 90023fff                 inc     -1, %o0
F009DF90: 808e4008                 btst    %o0, %i1
F009DF94: 02800004                 be      loc_F009DFA4
F009DF98: 113c045f                 sethi   %hi(aPmapEnterDevVi), %o0! "pmap_enter_dev: virtual address not ali"...
F009DF9C: 7ffddc75                 call    _panic
F009DFA0: 90122318                 bset    %lo(aPmapEnterDevVi), %o0! "pmap_enter_dev: virtual address not ali"...
F009DFA4: a0102000                 mov     0, %l0
F009DFA8: 900ee00f                 and     %i3, 0xF, %o0
F009DFAC: 912a2014                 sll     %o0, 20, %o0
F009DFB0: 9336a00c                 srl     %i2, 12, %o1
F009DFB4: a6120009                 or      %o0, %o1, %l3
F009DFB8: 7fffe351                 call    _splvm
F009DFBC: 01000000                 nop
F009DFC0: a2100008                 mov     %o0, %l1
F009DFC4: 90100018                 mov     %i0, %o0
F009DFC8: d207a048                 ld      [%fp+arg_48], %o1
F009DFCC: 7ffffa7b                 call    _pmap_page_table_entry
F009DFD0: 94102000                 mov     0, %o2
F009DFD4: b2920000                 orcc    %o0, %g0, %i1
F009DFD8: 32800009                 bne,a   loc_F009DFFC
F009DFDC: d00e600d                 ldub    [%i1+0xD], %o0
F009DFE0: 7fffe351                 call    _splx
F009DFE4: 90100011                 mov     %l1, %o0
F009DFE8: 90100018                 mov     %i0, %o0
F009DFEC: d207a048                 ld      [%fp+arg_48], %o1
F009DFF0: 7fffff22                 call    _pmap_expand
F009DFF4: 94102003                 mov     3, %o2
F009DFF8: 30bffff0                 ba,a    loc_F009DFB8
F009DFFC: 80a22003                 cmp     %o0, 3
F009E000: 12800007                 bne     loc_F009E01C
F009E004: 80a22002                 cmp     %o0, 2
F009E008: d007a048                 ld      [%fp+arg_48], %o0
F009E00C: d2064000                 ld      [%i1], %o1
F009E010: 9132200a                 srl     %o0, 10, %o0
F009E014: 1080000a                 ba      loc_F009E03C
F009E018: 900a20fc                 and     %o0, 0xFC, %o0
F009E01C: 32800006                 bne,a   loc_F009E034
F009E020: d00fa048                 ldub    [%fp+arg_48], %o0
F009E024: d017a048                 lduh    [%fp+arg_48], %o0
F009E028: d2064000                 ld      [%i1], %o1
F009E02C: 10800004                 ba      loc_F009E03C
F009E030: 900a20fc                 and     %o0, 0xFC, %o0
F009E034: d2064000                 ld      [%i1], %o1
F009E038: 912a2002                 sll     %o0, 2, %o0
F009E03C: 94024008                 add     %o1, %o0, %o2
F009E040: d2028000                 ld      [%o2], %o1
F009E044: 900a6003                 and     %o1, 3, %o0
F009E048: 80a22002                 cmp     %o0, 2
F009E04C: 12800055                 bne     loc_F009E1A0
F009E050: 93326008                 srl     %o1, 8, %o1
F009E054: d00e600d                 ldub    [%i1+0xD], %o0
F009E058: 80a22003                 cmp     %o0, 3
F009E05C: 32800052                 bne,a   loc_F009E1A4
F009E060: d0028000                 ld      [%o2], %o0
F009E064: 80a24013                 cmp     %o1, %l3
F009E068: 3280004f                 bne,a   loc_F009E1A4
F009E06C: d0028000                 ld      [%o2], %o0
F009E070: d007a048                 ld      [%fp+arg_48], %o0
F009E074: 80a4a000                 cmp     %l2, 0
F009E078: 9132200c                 srl     %o0, 12, %o0
F009E07C: 93322003                 srl     %o0, 3, %o1
F009E080: 920a6004                 and     %o1, 4, %o1
F009E084: 96024019                 add     %o1, %i1, %o3
F009E088: 900a201e                 and     %o0, 0x1E, %o0
F009E08C: 92102001                 mov     1, %o1
F009E090: d402e010                 ld      [%o3+0x10], %o2
F009E094: 932a4008                 sll     %o1, %o0, %o1
F009E098: 0280000c                 be      loc_F009E0C8
F009E09C: 900a8009                 and     %o2, %o1, %o0
F009E0A0: 80a22000                 cmp     %o0, 0
F009E0A4: 12800009                 bne     loc_F009E0C8
F009E0A8: 80a4a000                 cmp     %l2, 0
F009E0AC: 90128009                 or      %o2, %o1, %o0
F009E0B0: d022e010                 st      %o0, [%o3+0x10]
F009E0B4: d207a048                 ld      [%fp+arg_48], %o1
F009E0B8: 7ffff819                 call    _pmap_wire_mapping
F009E0BC: 90100018                 mov     %i0, %o0
F009E0C0: 1080002e                 ba      loc_F009E178
F009E0C4: 90100018                 mov     %i0, %o0
F009E0C8: 3280002c                 bne,a   loc_F009E178
F009E0CC: 90100018                 mov     %i0, %o0
F009E0D0: 80a22000                 cmp     %o0, 0
F009E0D4: 02800029                 be      loc_F009E178
F009E0D8: 90100018                 mov     %i0, %o0
F009E0DC: d00e600d                 ldub    [%i1+0xD], %o0
F009E0E0: 80a22003                 cmp     %o0, 3
F009E0E4: 1280000a                 bne     loc_F009E10C
F009E0E8: 80a22002                 cmp     %o0, 2
F009E0EC: d207a048                 ld      [%fp+arg_48], %o1
F009E0F0: 90102001                 mov     1, %o0
F009E0F4: 9332600c                 srl     %o1, 12, %o1
F009E0F8: 95326003                 srl     %o1, 3, %o2
F009E0FC: 940aa004                 and     %o2, 4, %o2
F009E100: 94028019                 add     %o2, %i1, %o2
F009E104: 1080000b                 ba      loc_F009E130
F009E108: 920a601e                 and     %o1, 0x1E, %o1
F009E10C: 1280000e                 bne     loc_F009E144
F009E110: d40fa048                 ldub    [%fp+arg_48], %o2
F009E114: d207a048                 ld      [%fp+arg_48], %o1
F009E118: 90102001                 mov     1, %o0
F009E11C: 93326012                 srl     %o1, 18, %o1
F009E120: 95326003                 srl     %o1, 3, %o2
F009E124: 940aa004                 and     %o2, 4, %o2
F009E128: 94028019                 add     %o2, %i1, %o2
F009E12C: 920a601f                 and     %o1, 0x1F, %o1
F009E130: d602a010                 ld      [%o2+0x10], %o3
F009E134: 912a0009                 sll     %o0, %o1, %o0
F009E138: 902ac008                 andn    %o3, %o0, %o0
F009E13C: 1080000b                 ba      loc_F009E168
F009E140: d022a010                 st      %o0, [%o2+0x10]
F009E144: 90102001                 mov     1, %o0
F009E148: 9332a005                 srl     %o2, 5, %o1
F009E14C: 932a6002                 sll     %o1, 2, %o1
F009E150: 92024019                 add     %o1, %i1, %o1
F009E154: 940aa01f                 and     %o2, 0x1F, %o2
F009E158: d6026010                 ld      [%o1+0x10], %o3
F009E15C: 912a000a                 sll     %o0, %o2, %o0
F009E160: 902ac008                 andn    %o3, %o0, %o0
F009E164: d0226010                 st      %o0, [%o1+0x10]
F009E168: d207a048                 ld      [%fp+arg_48], %o1
F009E16C: 7ffff7f2                 call    _pmap_unwire_mapping
F009E170: 90100018                 mov     %i0, %o0
F009E174: 90100018                 mov     %i0, %o0
F009E178: 40000ccc                 call    _vm_to_srmmu_prot
F009E17C: 9210001c                 mov     %i4, %o1
F009E180: f227bff4                 st      %i1, [%fp+var_C]
F009E184: 94100008                 mov     %o0, %o2
F009E188: 9007bff4                 add     %fp, var_C, %o0
F009E18C: d207a048                 ld      [%fp+arg_48], %o1
F009E190: 40000d56                 call    _update_pte
F009E194: 9610001d                 mov     %i5, %o3
F009E198: 1080009d                 ba      loc_F009E40C
F009E19C: 113c045e                 sethi   -0xFEE8800, %o0
F009E1A0: d0028000                 ld      [%o2], %o0
F009E1A4: 900a2003                 and     %o0, 3, %o0
F009E1A8: 80a22002                 cmp     %o0, 2
F009E1AC: 12800014                 bne     loc_F009E1FC
F009E1B0: 80a6e000                 cmp     %i3, 0
F009E1B4: 7fffe2dc                 call    _splx
F009E1B8: 90100011                 mov     %l1, %o0
F009E1BC: d00e600d                 ldub    [%i1+0xD], %o0
F009E1C0: 80a22003                 cmp     %o0, 3
F009E1C4: 02800006                 be      loc_F009E1DC
F009E1C8: 90100018                 mov     %i0, %o0
F009E1CC: f227bff4                 st      %i1, [%fp+var_C]
F009E1D0: d407a048                 ld      [%fp+arg_48], %o2
F009E1D4: 7ffffa85                 call    _pmap_scatter_pte
F009E1D8: 9207bff4                 add     %fp, var_C, %o1
F009E1DC: d207a048                 ld      [%fp+arg_48], %o1
F009E1E0: 153c0447                 sethi   %hi(_page_size), %o2
F009E1E4: d402a13c                 ld      [%o2+%lo(_page_size)], %o2
F009E1E8: 90100018                 mov     %i0, %o0
F009E1EC: 7ffffbe4                 call    _pmap_remove
F009E1F0: 9402400a                 add     %o1, %o2, %o2
F009E1F4: 10bfff6e                 ba      loc_F009DFAC
F009E1F8: 900ee00f                 and     %i3, 0xF, %o0
F009E1FC: 1280004e                 bne     loc_F009E334
F009E200: 90100018                 mov     %i0, %o0
F009E204: 113c0464                 sethi   %hi(_physmax), %o0
F009E208: d0022388                 ld      [%o0+%lo(_physmax)], %o0
F009E20C: 80a68008                 cmp     %i2, %o0
F009E210: 1a800049                 bcc     loc_F009E334
F009E214: 90100018                 mov     %i0, %o0
F009E218: 7fffa06e                 call    _vm_valid_page
F009E21C: 9010001a                 mov     %i2, %o0
F009E220: 80a22000                 cmp     %o0, 0
F009E224: 02800044                 be      loc_F009E334
F009E228: 90100018                 mov     %i0, %o0
F009E22C: 7fffa043                 call    _vm_mem_ppi
F009E230: 9010001a                 mov     %i2, %o0
F009E234: 133c04f7                 sethi   %hi(_pg_desc_tbl), %o1
F009E238: 952a2002                 sll     %o0, 2, %o2
F009E23C: 94028008                 add     %o2, %o0, %o2
F009E240: d8026260                 ld      [%o1+%lo(_pg_desc_tbl)], %o4
F009E244: 952aa002                 sll     %o2, 2, %o2
F009E248: 9603000a                 add     %o4, %o2, %o3
F009E24C: d002e004                 ld      [%o3+4], %o0
F009E250: 80a22000                 cmp     %o0, 0
F009E254: 1280000b                 bne     loc_F009E280
F009E258: 80a42000                 cmp     %l0, 0
F009E25C: d007a048                 ld      [%fp+arg_48], %o0
F009E260: f022e004                 st      %i0, [%o3+4]
F009E264: d20ae00b                 ldub    [%o3+0xB], %o1
F009E268: 9132200c                 srl     %o0, 12, %o0
F009E26C: 912a2008                 sll     %o0, 8, %o0
F009E270: 92124008                 bset    %o0, %o1
F009E274: d222e008                 st      %o1, [%o3+8]
F009E278: 10800015                 ba      loc_F009E2CC
F009E27C: c023000a                 clr     [%o4+%o2]
F009E280: 12800009                 bne     loc_F009E2A4
F009E284: d007a048                 ld      [%fp+arg_48], %o0
F009E288: 7fffe2a7                 call    _splx
F009E28C: 90100011                 mov     %l1, %o0
F009E290: 113c04f7                 sethi   %hi(_pv_entry_zone), %o0
F009E294: 7fff6b8e                 call    _zalloc
F009E298: d0022388                 ld      [%o0+%lo(_pv_entry_zone)], %o0
F009E29C: 10bfff43                 ba      loc_F009DFA8
F009E2A0: a0100008                 mov     %o0, %l0
F009E2A4: f0242004                 st      %i0, [%l0+4]
F009E2A8: d20c200b                 ldub    [%l0+0xB], %o1
F009E2AC: 9132200c                 srl     %o0, 12, %o0
F009E2B0: 912a2008                 sll     %o0, 8, %o0
F009E2B4: 92124008                 bset    %o0, %o1
F009E2B8: d2242008                 st      %o1, [%l0+8]
F009E2BC: d003000a                 ld      [%o4+%o2], %o0
F009E2C0: d0240000                 st      %o0, [%l0]
F009E2C4: e023000a                 st      %l0, [%o4+%o2]
F009E2C8: a0102000                 mov     0, %l0
F009E2CC: d002e004                 ld      [%o3+4], %o0
F009E2D0: 80a20018                 cmp     %o0, %i0
F009E2D4: 3280000a                 bne,a   loc_F009E2FC
F009E2D8: d202c000                 ld      [%o3], %o1
F009E2DC: d002e008                 ld      [%o3+8], %o0
F009E2E0: d207a048                 ld      [%fp+arg_48], %o1
F009E2E4: 91322008                 srl     %o0, 8, %o0
F009E2E8: 912a200c                 sll     %o0, 12, %o0
F009E2EC: 80a20009                 cmp     %o0, %o1
F009E2F0: 02800012                 be      loc_F009E338
F009E2F4: 90100018                 mov     %i0, %o0
F009E2F8: d202c000                 ld      [%o3], %o1
F009E2FC: d0026004                 ld      [%o1+4], %o0
F009E300: 80a20018                 cmp     %o0, %i0
F009E304: 12800009                 bne     loc_F009E328
F009E308: 113c045f                 sethi   -0xFEE8400, %o0
F009E30C: d0026008                 ld      [%o1+8], %o0
F009E310: 91322008                 srl     %o0, 8, %o0
F009E314: d207a048                 ld      [%fp+arg_48], %o1
F009E318: 912a200c                 sll     %o0, 12, %o0
F009E31C: 80a20009                 cmp     %o0, %o1
F009E320: 02800004                 be      loc_F009E330
F009E324: 113c045f                 sethi   -0xFEE8400, %o0! char *
F009E328: 7ffddb92                 call    _panic
F009E32C: 90122348                 bset    0x348, %o0
F009E330: 90100018                 mov     %i0, %o0
F009E334: d207a048                 ld      [%fp+arg_48], %o1
F009E338: 7ffff75c                 call    _pmap_allocate_mapping
F009E33C: 94100012                 mov     %l2, %o2
F009E340: f227bff4                 st      %i1, [%fp+var_C]
F009E344: 90100018                 mov     %i0, %o0
F009E348: 40000c58                 call    _vm_to_srmmu_prot
F009E34C: 9210001c                 mov     %i4, %o1
F009E350: 96100008                 mov     %o0, %o3
F009E354: 9007bff4                 add     %fp, var_C, %o0
F009E358: 94100013                 mov     %l3, %o2
F009E35C: 9810001d                 mov     %i5, %o4
F009E360: d207a048                 ld      [%fp+arg_48], %o1
F009E364: 9a102000                 mov     0, %o5
F009E368: 40000d2c                 call    _set_pte
F009E36C: c023a05c                 clr     [%sp+0x78+var_1C]
F009E370: 80a4a000                 cmp     %l2, 0
F009E374: 02800026                 be      loc_F009E40C
F009E378: 113c045e                 sethi   -0xFEE8800, %o0
F009E37C: d00e600d                 ldub    [%i1+0xD], %o0
F009E380: 80a22003                 cmp     %o0, 3
F009E384: 1280000a                 bne     loc_F009E3AC
F009E388: 80a22002                 cmp     %o0, 2
F009E38C: d407a048                 ld      [%fp+arg_48], %o2
F009E390: 90102001                 mov     1, %o0
F009E394: 9532a00c                 srl     %o2, 12, %o2
F009E398: 9732a003                 srl     %o2, 3, %o3
F009E39C: 960ae004                 and     %o3, 4, %o3
F009E3A0: 9602c019                 add     %o3, %i1, %o3
F009E3A4: 1080000b                 ba      loc_F009E3D0
F009E3A8: 940aa01e                 and     %o2, 0x1E, %o2
F009E3AC: 1280000e                 bne     loc_F009E3E4
F009E3B0: d60fa048                 ldub    [%fp+arg_48], %o3
F009E3B4: d407a048                 ld      [%fp+arg_48], %o2
F009E3B8: 90102001                 mov     1, %o0
F009E3BC: 9532a012                 srl     %o2, 18, %o2
F009E3C0: 9732a003                 srl     %o2, 3, %o3
F009E3C4: 960ae004                 and     %o3, 4, %o3
F009E3C8: 9602c019                 add     %o3, %i1, %o3
F009E3CC: 940aa01f                 and     %o2, 0x1F, %o2
F009E3D0: d202e010                 ld      [%o3+0x10], %o1
F009E3D4: 912a000a                 sll     %o0, %o2, %o0
F009E3D8: 92124008                 bset    %o0, %o1
F009E3DC: 1080000b                 ba      loc_F009E408
F009E3E0: d222e010                 st      %o1, [%o3+0x10]
F009E3E4: 90102001                 mov     1, %o0
F009E3E8: 9532e005                 srl     %o3, 5, %o2
F009E3EC: 952aa002                 sll     %o2, 2, %o2
F009E3F0: 94028019                 add     %o2, %i1, %o2
F009E3F4: 960ae01f                 and     %o3, 0x1F, %o3
F009E3F8: d202a010                 ld      [%o2+0x10], %o1
F009E3FC: 912a000b                 sll     %o0, %o3, %o0
F009E400: 92124008                 bset    %o0, %o1
F009E404: d222a010                 st      %o1, [%o2+0x10]
F009E408: 113c045e                 sethi   -0xFEE8800, %o0
F009E40C: d0022308                 ld      [%o0+0x308], %o0
F009E410: 80a22000                 cmp     %o0, 0
F009E414: 12800006                 bne     loc_F009E42C
F009E418: 90100018                 mov     %i0, %o0
F009E41C: f227bff4                 st      %i1, [%fp+var_C]
F009E420: d407a048                 ld      [%fp+arg_48], %o2
F009E424: 7ffffac0                 call    _pmap_gather_pte
F009E428: 9207bff4                 add     %fp, var_C, %o1
F009E42C: 7fffe23e                 call    _splx
F009E430: 90100011                 mov     %l1, %o0
F009E434: 80a42000                 cmp     %l0, 0
F009E438: 02800005                 be      locret_F009E44C
F009E43C: 113c04f7                 sethi   %hi(_pv_entry_zone), %o0
F009E440: d0022388                 ld      [%o0+%lo(_pv_entry_zone)], %o0
F009E444: 7fff6b63                 call    _zfree
F009E448: 92100010                 mov     %l0, %o1
F009E44C: 81c7e008                 ret
F009E450: 81e80000                 restore
