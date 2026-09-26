F009CF24: 9de3bf80                 save    %sp, -0x80, %sp
F009CF28: f427a04c                 st      %i2, [%fp+arg_4C]
F009CF2C: 9007bfec                 add     %fp, var_14, %o0
F009CF30: 9207bff4                 add     %fp, var_C, %o1
F009CF34: f2064000                 ld      [%i1], %i1
F009CF38: 9407bff0                 add     %fp, var_10, %o2
F009CF3C: 7fffffae                 call    _is_ptes_contiguous
F009CF40: f227bfec                 st      %i1, [%fp+var_14]
F009CF44: 80a22000                 cmp     %o0, 0
F009CF48: 02800052                 be      locret_F009D090
F009CF4C: 01000000                 nop
F009CF50: f4066020                 ld      [%i1+0x20], %i2
F009CF54: d00ea00d                 ldub    [%i2+0xD], %o0
F009CF58: 80a22003                 cmp     %o0, 3
F009CF5C: 12800007                 bne     loc_F009CF78
F009CF60: 80a22002                 cmp     %o0, 2
F009CF64: 113c04d0                 sethi   %hi(_page_mask), %o0
F009CF68: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F009CF6C: d207a04c                 ld      [%fp+arg_4C], %o1
F009CF70: 10800008                 ba      loc_F009CF90
F009CF74: 902a4008                 andn    %o1, %o0, %o0
F009CF78: 12800004                 bne     loc_F009CF88
F009CF7C: d007a04c                 ld      [%fp+arg_4C], %o0
F009CF80: 10800003                 ba      loc_F009CF8C
F009CF84: 133fff00                 sethi   -0x40000, %o1
F009CF88: 133fc000                 sethi   -0x1000000, %o1
F009CF8C: 900a0009                 and     %o0, %o1, %o0
F009CF90: d027a04c                 st      %o0, [%fp+arg_4C]
F009CF94: e0064000                 ld      [%i1], %l0
F009CF98: da07bff4                 ld      [%fp+var_C], %o5
F009CF9C: d207bff0                 ld      [%fp+var_10], %o1
F009CFA0: f427bfec                 st      %i2, [%fp+var_14]
F009CFA4: d8040000                 ld      [%l0], %o4
F009CFA8: 9007bfec                 add     %fp, var_14, %o0
F009CFAC: d223a05c                 st      %o1, [%sp+0x80+var_24]
F009CFB0: 95332008                 srl     %o4, 8, %o2
F009CFB4: 97332002                 srl     %o4, 2, %o3
F009CFB8: 99332007                 srl     %o4, 7, %o4
F009CFBC: 960ae007                 and     %o3, 7, %o3
F009CFC0: d207a04c                 ld      [%fp+arg_4C], %o1
F009CFC4: 40001215                 call    _set_pte
F009CFC8: 980b2001                 and     %o4, 1, %o4
F009CFCC: d00ea00f                 ldub    [%i2+0xF], %o0
F009CFD0: d20ea00d                 ldub    [%i2+0xD], %o1
F009CFD4: 90023fff                 inc     -1, %o0
F009CFD8: 80a26003                 cmp     %o1, 3
F009CFDC: 1280000a                 bne     loc_F009D004
F009CFE0: d02ea00f                 stb     %o0, [%i2+0xF]
F009CFE4: d407a04c                 ld      [%fp+arg_4C], %o2
F009CFE8: 90102001                 mov     1, %o0
F009CFEC: 9532a00c                 srl     %o2, 12, %o2
F009CFF0: 9732a003                 srl     %o2, 3, %o3
F009CFF4: 960ae004                 and     %o3, 4, %o3
F009CFF8: 9602c01a                 add     %o3, %i2, %o3
F009CFFC: 1080000c                 ba      loc_F009D02C
F009D000: 940aa01e                 and     %o2, 0x1E, %o2
F009D004: 80a26002                 cmp     %o1, 2
F009D008: 1280000e                 bne     loc_F009D040
F009D00C: d60fa04c                 ldub    [%fp+arg_4C], %o3
F009D010: d407a04c                 ld      [%fp+arg_4C], %o2
F009D014: 90102001                 mov     1, %o0
F009D018: 9532a012                 srl     %o2, 18, %o2
F009D01C: 9732a003                 srl     %o2, 3, %o3
F009D020: 960ae004                 and     %o3, 4, %o3
F009D024: 9602c01a                 add     %o3, %i2, %o3
F009D028: 940aa01f                 and     %o2, 0x1F, %o2
F009D02C: d202e010                 ld      [%o3+0x10], %o1
F009D030: 912a000a                 sll     %o0, %o2, %o0
F009D034: 92124008                 bset    %o0, %o1
F009D038: 1080000b                 ba      loc_F009D064
F009D03C: d222e010                 st      %o1, [%o3+0x10]
F009D040: 90102001                 mov     1, %o0
F009D044: 9532e005                 srl     %o3, 5, %o2
F009D048: 952aa002                 sll     %o2, 2, %o2
F009D04C: 9402801a                 add     %o2, %i2, %o2
F009D050: 960ae01f                 and     %o3, 0x1F, %o3
F009D054: d202a010                 ld      [%o2+0x10], %o1
F009D058: 912a000b                 sll     %o0, %o3, %o0
F009D05C: 92124008                 bset    %o0, %o1! size_t
F009D060: d222a010                 st      %o1, [%o2+0x10]
F009D064: 90100010                 mov     %l0, %o0! void *
F009D068: 7fffdf7c                 call    _bzero
F009D06C: 92102100                 mov     0x100, %o1
F009D070: c02e600f                 clrb    [%i1+0xF]
F009D074: c0266010                 clr     [%i1+0x10]
F009D078: c0266014                 clr     [%i1+0x14]
F009D07C: c0266018                 clr     [%i1+0x18]
F009D080: c026601c                 clr     [%i1+0x1C]
F009D084: c0266020                 clr     [%i1+0x20]
F009D088: 40001742                 call    _pmap_dealloc_seg_entry
F009D08C: 90100019                 mov     %i1, %o0
F009D090: 81c7e008                 ret
F009D094: 81e80000                 restore
