F009EC28: 9de3bf90                 save    %sp, -0x70, %sp
F009EC2C: 133c04f792126270         set     _pmap_info, %o1
F009EC34: d002607c                 ld      [%o1+0x7C], %o0
F009EC38: f227a048                 st      %i1, [%fp+arg_48]
F009EC3C: 90022001                 inc     %o0
F009EC40: 7fffe02f                 call    _splvm
F009EC44: d022607c                 st      %o0, [%o1+0x7C]
F009EC48: a0100008                 mov     %o0, %l0
F009EC4C: 90100018                 mov     %i0, %o0
F009EC50: d207a048                 ld      [%fp+arg_48], %o1
F009EC54: 7ffff759                 call    _pmap_page_table_entry
F009EC58: 94102000                 mov     0, %o2
F009EC5C: b2920000                 orcc    %o0, %g0, %i1
F009EC60: 32800006                 bne,a   loc_F009EC78
F009EC64: d00e600d                 ldub    [%i1+0xD], %o0
F009EC68: 113c0460                 sethi   %hi(aPmapChangeWiri), %o0! "pmap_change_wiring: null pte"
F009EC6C: 7ffdd941                 call    _panic
F009EC70: 90122010                 bset    %lo(aPmapChangeWiri), %o0! "pmap_change_wiring: null pte"
F009EC74: d00e600d                 ldub    [%i1+0xD], %o0
F009EC78: 80a22003                 cmp     %o0, 3
F009EC7C: 2280000d                 be,a    loc_F009ECB0
F009EC80: d00e600d                 ldub    [%i1+0xD], %o0
F009EC84: 7fffe028                 call    _splx
F009EC88: 90100010                 mov     %l0, %o0
F009EC8C: f227bff4                 st      %i1, [%fp+var_C]
F009EC90: 90100018                 mov     %i0, %o0
F009EC94: d407a048                 ld      [%fp+arg_48], %o2
F009EC98: 7ffff7d4                 call    _pmap_scatter_pte
F009EC9C: 9207bff4                 add     %fp, var_C, %o1
F009ECA0: 7fffe017                 call    _splvm
F009ECA4: b2100008                 mov     %o0, %i1
F009ECA8: a0100008                 mov     %o0, %l0
F009ECAC: d00e600d                 ldub    [%i1+0xD], %o0
F009ECB0: 80a22003                 cmp     %o0, 3
F009ECB4: 1280000a                 bne     loc_F009ECDC
F009ECB8: 80a22002                 cmp     %o0, 2
F009ECBC: d407a048                 ld      [%fp+arg_48], %o2
F009ECC0: 90102001                 mov     1, %o0
F009ECC4: 9532a00c                 srl     %o2, 12, %o2
F009ECC8: 9332a003                 srl     %o2, 3, %o1
F009ECCC: 920a6004                 and     %o1, 4, %o1
F009ECD0: 92024019                 add     %o1, %i1, %o1
F009ECD4: 1080000f                 ba      loc_F009ED10
F009ECD8: 940aa01e                 and     %o2, 0x1E, %o2
F009ECDC: 12800008                 bne     loc_F009ECFC
F009ECE0: d40fa048                 ldub    [%fp+arg_48], %o2
F009ECE4: d407a048                 ld      [%fp+arg_48], %o2
F009ECE8: 90102001                 mov     1, %o0
F009ECEC: 9532a012                 srl     %o2, 18, %o2
F009ECF0: 9332a003                 srl     %o2, 3, %o1
F009ECF4: 10800005                 ba      loc_F009ED08
F009ECF8: 920a6004                 and     %o1, 4, %o1
F009ECFC: 90102001                 mov     1, %o0
F009ED00: 9332a005                 srl     %o2, 5, %o1
F009ED04: 932a6002                 sll     %o1, 2, %o1
F009ED08: 92024019                 add     %o1, %i1, %o1
F009ED0C: 940aa01f                 and     %o2, 0x1F, %o2
F009ED10: d2026010                 ld      [%o1+0x10], %o1
F009ED14: 912a000a                 sll     %o0, %o2, %o0
F009ED18: 80a6a000                 cmp     %i2, 0
F009ED1C: 0280002c                 be      loc_F009EDCC
F009ED20: 920a4008                 and     %o1, %o0, %o1
F009ED24: 80a26000                 cmp     %o1, 0
F009ED28: 12800029                 bne     loc_F009EDCC
F009ED2C: 80a6a000                 cmp     %i2, 0
F009ED30: d00e600d                 ldub    [%i1+0xD], %o0
F009ED34: 80a22003                 cmp     %o0, 3
F009ED38: 1280000a                 bne     loc_F009ED60
F009ED3C: 80a22002                 cmp     %o0, 2
F009ED40: d407a048                 ld      [%fp+arg_48], %o2
F009ED44: 90102001                 mov     1, %o0
F009ED48: 9532a00c                 srl     %o2, 12, %o2
F009ED4C: 9732a003                 srl     %o2, 3, %o3
F009ED50: 960ae004                 and     %o3, 4, %o3
F009ED54: 9602c019                 add     %o3, %i1, %o3
F009ED58: 1080000b                 ba      loc_F009ED84
F009ED5C: 940aa01e                 and     %o2, 0x1E, %o2
F009ED60: 1280000e                 bne     loc_F009ED98
F009ED64: d60fa048                 ldub    [%fp+arg_48], %o3
F009ED68: d407a048                 ld      [%fp+arg_48], %o2
F009ED6C: 90102001                 mov     1, %o0
F009ED70: 9532a012                 srl     %o2, 18, %o2
F009ED74: 9732a003                 srl     %o2, 3, %o3
F009ED78: 960ae004                 and     %o3, 4, %o3
F009ED7C: 9602c019                 add     %o3, %i1, %o3
F009ED80: 940aa01f                 and     %o2, 0x1F, %o2
F009ED84: d202e010                 ld      [%o3+0x10], %o1
F009ED88: 912a000a                 sll     %o0, %o2, %o0
F009ED8C: 92124008                 bset    %o0, %o1
F009ED90: 1080000b                 ba      loc_F009EDBC
F009ED94: d222e010                 st      %o1, [%o3+0x10]
F009ED98: 90102001                 mov     1, %o0
F009ED9C: 9532e005                 srl     %o3, 5, %o2
F009EDA0: 952aa002                 sll     %o2, 2, %o2
F009EDA4: 94028019                 add     %o2, %i1, %o2
F009EDA8: 960ae01f                 and     %o3, 0x1F, %o3
F009EDAC: d202a010                 ld      [%o2+0x10], %o1
F009EDB0: 912a000b                 sll     %o0, %o3, %o0
F009EDB4: 92124008                 bset    %o0, %o1
F009EDB8: d222a010                 st      %o1, [%o2+0x10]
F009EDBC: d207a048                 ld      [%fp+arg_48], %o1
F009EDC0: 7ffff4d7                 call    _pmap_wire_mapping
F009EDC4: 90100018                 mov     %i0, %o0
F009EDC8: 3080002b                 ba,a    loc_F009EE74
F009EDCC: 1280002a                 bne     loc_F009EE74
F009EDD0: 80a26000                 cmp     %o1, 0
F009EDD4: 02800028                 be      loc_F009EE74
F009EDD8: 01000000                 nop
F009EDDC: d00e600d                 ldub    [%i1+0xD], %o0
F009EDE0: 80a22003                 cmp     %o0, 3
F009EDE4: 1280000a                 bne     loc_F009EE0C
F009EDE8: 80a22002                 cmp     %o0, 2
F009EDEC: d207a048                 ld      [%fp+arg_48], %o1
F009EDF0: 90102001                 mov     1, %o0
F009EDF4: 9332600c                 srl     %o1, 12, %o1
F009EDF8: 95326003                 srl     %o1, 3, %o2
F009EDFC: 940aa004                 and     %o2, 4, %o2
F009EE00: 94028019                 add     %o2, %i1, %o2
F009EE04: 1080000b                 ba      loc_F009EE30
F009EE08: 920a601e                 and     %o1, 0x1E, %o1
F009EE0C: 1280000e                 bne     loc_F009EE44
F009EE10: d40fa048                 ldub    [%fp+arg_48], %o2
F009EE14: d207a048                 ld      [%fp+arg_48], %o1
F009EE18: 90102001                 mov     1, %o0
F009EE1C: 93326012                 srl     %o1, 18, %o1
F009EE20: 95326003                 srl     %o1, 3, %o2
F009EE24: 940aa004                 and     %o2, 4, %o2
F009EE28: 94028019                 add     %o2, %i1, %o2
F009EE2C: 920a601f                 and     %o1, 0x1F, %o1
F009EE30: d602a010                 ld      [%o2+0x10], %o3
F009EE34: 912a0009                 sll     %o0, %o1, %o0
F009EE38: 902ac008                 andn    %o3, %o0, %o0
F009EE3C: 1080000b                 ba      loc_F009EE68
F009EE40: d022a010                 st      %o0, [%o2+0x10]
F009EE44: 90102001                 mov     1, %o0
F009EE48: 9332a005                 srl     %o2, 5, %o1
F009EE4C: 932a6002                 sll     %o1, 2, %o1
F009EE50: 92024019                 add     %o1, %i1, %o1
F009EE54: 940aa01f                 and     %o2, 0x1F, %o2
F009EE58: d6026010                 ld      [%o1+0x10], %o3
F009EE5C: 912a000a                 sll     %o0, %o2, %o0
F009EE60: 902ac008                 andn    %o3, %o0, %o0
F009EE64: d0226010                 st      %o0, [%o1+0x10]
F009EE68: d207a048                 ld      [%fp+arg_48], %o1
F009EE6C: 7ffff4b2                 call    _pmap_unwire_mapping
F009EE70: 90100018                 mov     %i0, %o0
F009EE74: 7fffdfac                 call    _splx
F009EE78: 90100010                 mov     %l0, %o0
F009EE7C: 81c7e008                 ret
F009EE80: 81e80000                 restore
