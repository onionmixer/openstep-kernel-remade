F009AFE4: 9de3bf98                 save    %sp, -0x68, %sp
F009AFE8: 113c0464                 sethi   %hi(_cache), %o0
F009AFEC: d0022330                 ld      [%o0+%lo(_cache)], %o0
F009AFF0: 80a22003                 cmp     %o0, 3
F009AFF4: 12800049                 bne     loc_F009B118
F009AFF8: a0102000                 mov     0, %l0
F009AFFC: 113c0464                 sethi   %hi(_use_cache), %o0
F009B000: d00222c4                 ld      [%o0+%lo(_use_cache)], %o0
F009B004: 80a22000                 cmp     %o0, 0
F009B008: 0280000a                 be      loc_F009B030
F009B00C: 113c0464                 sethi   %hi(_use_ec), %o0
F009B010: d00222e8                 ld      [%o0+%lo(_use_ec)], %o0
F009B014: 80a22000                 cmp     %o0, 0
F009B018: 02800006                 be      loc_F009B030
F009B01C: 133c045d                 sethi   %hi(dword_F01176E8), %o1
F009B020: d00262e8                 ld      [%o1+%lo(dword_F01176E8)], %o0
F009B024: a0102001                 mov     1, %l0
F009B028: 90122004                 bset    4, %o0
F009B02C: d02262e8                 st      %o0, [%o1+%lo(dword_F01176E8)]
F009B030: 113c0464                 sethi   %hi(_use_mxcc_prefetch), %o0
F009B034: d00222d4                 ld      [%o0+%lo(_use_mxcc_prefetch)], %o0
F009B038: 80a22000                 cmp     %o0, 0
F009B03C: 02800006                 be      loc_F009B054
F009B040: 133c045d                 sethi   %hi(dword_F01176E8), %o1
F009B044: d00262e8                 ld      [%o1+%lo(dword_F01176E8)], %o0
F009B048: 90122020                 bset    0x20, %o0 ! ' '
F009B04C: 10800006                 ba      loc_F009B064
F009B050: d02262e8                 st      %o0, [%o1+%lo(dword_F01176E8)]
F009B054: 133c045d                 sethi   %hi(dword_F01176EC), %o1
F009B058: d00262ec                 ld      [%o1+%lo(dword_F01176EC)], %o0
F009B05C: 90122020                 bset    0x20, %o0 ! ' '
F009B060: d02262ec                 st      %o0, [%o1+%lo(dword_F01176EC)]
F009B064: 153c0464                 sethi   %hi(_use_multiple_cmd), %o2
F009B068: d202a2f0                 ld      [%o2+%lo(_use_multiple_cmd)], %o1
F009B06C: 80a26000                 cmp     %o1, 0
F009B070: 02800010                 be      loc_F009B0B0
F009B074: 113c0464                 sethi   %hi(_nmod), %o0
F009B078: d002232c                 ld      [%o0+%lo(_nmod)], %o0
F009B07C: 80a22001                 cmp     %o0, 1
F009B080: 02800004                 be      loc_F009B090
F009B084: 80a26002                 cmp     %o1, 2
F009B088: 12800007                 bne     loc_F009B0A4
F009B08C: 133c045d                 sethi   -0xFEE8C00, %o1
F009B090: 133c045d                 sethi   %hi(dword_F01176E8), %o1
F009B094: d00262e8                 ld      [%o1+%lo(dword_F01176E8)], %o0
F009B098: 90122010                 bset    0x10, %o0
F009B09C: 10800009                 ba      loc_F009B0C0
F009B0A0: d02262e8                 st      %o0, [%o1+%lo(dword_F01176E8)]
F009B0A4: d00262ec                 ld      [%o1+0x2EC], %o0
F009B0A8: 10800004                 ba      loc_F009B0B8
F009B0AC: c022a2f0                 clr     [%o2+0x2F0]
F009B0B0: 133c045d                 sethi   %hi(dword_F01176EC), %o1
F009B0B4: d00262ec                 ld      [%o1+%lo(dword_F01176EC)], %o0
F009B0B8: 90122010                 bset    0x10, %o0
F009B0BC: d02262ec                 st      %o0, [%o1+0x2EC]
F009B0C0: 113c0464                 sethi   %hi(_use_rdref_only), %o0
F009B0C4: d00222f4                 ld      [%o0+%lo(_use_rdref_only)], %o0
F009B0C8: 80a22000                 cmp     %o0, 0
F009B0CC: 22800007                 be,a    loc_F009B0E8
F009B0D0: 133c045d                 sethi   -0xFEE8C00, %o1
F009B0D4: 133c045d                 sethi   %hi(dword_F01176E8), %o1
F009B0D8: d00262e8                 ld      [%o1+%lo(dword_F01176E8)], %o0
F009B0DC: 90122200                 bset    0x200, %o0
F009B0E0: 10800005                 ba      loc_F009B0F4
F009B0E4: d02262e8                 st      %o0, [%o1+%lo(dword_F01176E8)]
F009B0E8: d00262ec                 ld      [%o1+0x2EC], %o0
F009B0EC: 90122200                 bset    0x200, %o0
F009B0F0: d02262ec                 st      %o0, [%o1+0x2EC]
F009B0F4: 113c045d                 sethi   %hi(dword_F01176EC), %o0
F009B0F8: d00222ec                 ld      [%o0+%lo(dword_F01176EC)], %o0
F009B0FC: 133c045d                 sethi   %hi(dword_F01176E8), %o1
F009B100: 7fffec95                 call    _vik_mxcc_init_asm
F009B104: d20262e8                 ld      [%o1+%lo(dword_F01176E8)], %o1
F009B108: 133c04f7                 sethi   -0xFEC2400, %o1
F009B10C: 113c045d                 sethi   %hi(aSupersparcSupe), %o0! "SuperSPARC/SuperCache"
F009B110: 10800005                 ba      loc_F009B124
F009B114: 901222f0                 bset    %lo(aSupersparcSupe), %o0! "SuperSPARC/SuperCache"
F009B118: 133c04f7                 sethi   -0xFEC2400, %o1
F009B11C: 113c045d90122308         set     aSupersparc, %o0! "SuperSPARC"
F009B124: d02261f8                 st      %o0, [%o1+0x1F8]
F009B128: 113c045d                 sethi   %hi(dword_F01176EC), %o0
F009B12C: c02222ec                 clr     [%o0+%lo(dword_F01176EC)]
F009B130: 133c045d                 sethi   %hi(dword_F01176E8), %o1
F009B134: 15000010                 sethi   0x4000, %o2
F009B138: 113c0464                 sethi   %hi(_use_cache), %o0
F009B13C: d00222c4                 ld      [%o0+%lo(_use_cache)], %o0
F009B140: 80a22000                 cmp     %o0, 0
F009B144: 0280000f                 be      loc_F009B180
F009B148: d42262e8                 st      %o2, [%o1+%lo(dword_F01176E8)]
F009B14C: 113c0464                 sethi   %hi(_use_ic), %o0
F009B150: d00222e0                 ld      [%o0+%lo(_use_ic)], %o0
F009B154: 80a22000                 cmp     %o0, 0
F009B158: 02800003                 be      loc_F009B164
F009B15C: 9012a200                 or      %o2, 0x200, %o0
F009B160: d02262e8                 st      %o0, [%o1+%lo(dword_F01176E8)]
F009B164: 113c0464                 sethi   %hi(_use_dc), %o0
F009B168: d00222e4                 ld      [%o0+%lo(_use_dc)], %o0
F009B16C: 80a22000                 cmp     %o0, 0
F009B170: 02800004                 be      loc_F009B180
F009B174: d00262e8                 ld      [%o1+0x2E8], %o0
F009B178: 90122100                 bset    0x100, %o0
F009B17C: d02262e8                 st      %o0, [%o1+0x2E8]
F009B180: 153c045d                 sethi   %hi(dword_F01176EC), %o2
F009B184: d202a2ec                 ld      [%o2+%lo(dword_F01176EC)], %o1
F009B188: 11000100                 sethi   0x40000, %o0
F009B18C: 92124008                 bset    %o0, %o1
F009B190: 113c0464                 sethi   %hi(_use_table_walk), %o0
F009B194: d00222d8                 ld      [%o0+%lo(_use_table_walk)], %o0
F009B198: 80a22000                 cmp     %o0, 0
F009B19C: 02800011                 be      loc_F009B1E0
F009B1A0: d222a2ec                 st      %o1, [%o2+%lo(dword_F01176EC)]
F009B1A4: 113c0464                 sethi   %hi(_use_ec), %o0
F009B1A8: d00222e8                 ld      [%o0+%lo(_use_ec)], %o0
F009B1AC: 80a22000                 cmp     %o0, 0
F009B1B0: 0280000c                 be      loc_F009B1E0
F009B1B4: 113c0464                 sethi   %hi(_cache), %o0
F009B1B8: d0022330                 ld      [%o0+%lo(_cache)], %o0
F009B1BC: 80a22003                 cmp     %o0, 3
F009B1C0: 12800009                 bne     loc_F009B1E4
F009B1C4: 113c045d                 sethi   -0xFEE8C00, %o0
F009B1C8: 113c045d                 sethi   %hi(dword_F01176E8), %o0
F009B1CC: d20222e8                 ld      [%o0+%lo(dword_F01176E8)], %o1
F009B1D0: 15000040                 sethi   0x10000, %o2
F009B1D4: 9212400a                 bset    %o2, %o1
F009B1D8: 10800007                 ba      loc_F009B1F4
F009B1DC: d22222e8                 st      %o1, [%o0+%lo(dword_F01176E8)]
F009B1E0: 113c045d                 sethi   -0xFEE8C00, %o0
F009B1E4: d20222ec                 ld      [%o0+0x2EC], %o1
F009B1E8: 15000040                 sethi   0x10000, %o2
F009B1EC: 9212400a                 bset    %o2, %o1
F009B1F0: d22222ec                 st      %o1, [%o0+0x2EC]
F009B1F4: 113c0464                 sethi   %hi(_use_store_buffer), %o0
F009B1F8: d00222dc                 ld      [%o0+%lo(_use_store_buffer)], %o0
F009B1FC: 80a22000                 cmp     %o0, 0
F009B200: 22800007                 be,a    loc_F009B21C
F009B204: 133c045d                 sethi   -0xFEE8C00, %o1
F009B208: 133c045d                 sethi   %hi(dword_F01176E8), %o1
F009B20C: d00262e8                 ld      [%o1+%lo(dword_F01176E8)], %o0
F009B210: 90122400                 bset    0x400, %o0
F009B214: 10800005                 ba      loc_F009B228
F009B218: d02262e8                 st      %o0, [%o1+%lo(dword_F01176E8)]
F009B21C: d00262ec                 ld      [%o1+0x2EC], %o0
F009B220: 90122400                 bset    0x400, %o0
F009B224: d02262ec                 st      %o0, [%o1+0x2EC]
F009B228: 113c045d                 sethi   %hi(dword_F01176EC), %o0
F009B22C: d00222ec                 ld      [%o0+%lo(dword_F01176EC)], %o0
F009B230: 133c045d                 sethi   %hi(dword_F01176E8), %o1
F009B234: 7fffec41                 call    _vik_vac_init_asm
F009B238: d20262e8                 ld      [%o1+%lo(dword_F01176E8)], %o1
F009B23C: 113c045d                 sethi   %hi(_vik_rev_level), %o0
F009B240: d00222d8                 ld      [%o0+%lo(_vik_rev_level)], %o0
F009B244: 90023fff                 inc     -1, %o0
F009B248: 80a22001                 cmp     %o0, 1
F009B24C: 18800008                 bgu     loc_F009B26C
F009B250: 133c045d                 sethi   %hi(_do_work_arounds), %o1
F009B254: 90102001                 mov     1, %o0
F009B258: 80a42000                 cmp     %l0, 0
F009B25C: 12800004                 bne     loc_F009B26C
F009B260: d02262dc                 st      %o0, [%o1+%lo(_do_work_arounds)]
F009B264: 7ffff0a7                 call    _SMbuf_syncmode
F009B268: 01000000                 nop
F009B26C: 113c045d                 sethi   %hi(_vik_rev_level), %o0
F009B270: d00222d8                 ld      [%o0+%lo(_vik_rev_level)], %o0
F009B274: 80a22003                 cmp     %o0, 3
F009B278: 12800007                 bne     loc_F009B294
F009B27C: 113c045d                 sethi   -0xFEE8C00, %o0
F009B280: 113c045d                 sethi   %hi(_enable_sm_wa), %o0
F009B284: d00222e0                 ld      [%o0+%lo(_enable_sm_wa)], %o0
F009B288: 80a22000                 cmp     %o0, 0
F009B28C: 12800006                 bne     loc_F009B2A4
F009B290: 113c045d                 sethi   -0xFEE8C00, %o0
F009B294: d00222e4                 ld      [%o0+0x2E4], %o0
F009B298: 80a22000                 cmp     %o0, 0
F009B29C: 02800004                 be      locret_F009B2AC
F009B2A0: 01000000                 nop
F009B2A4: 7fffeca1                 call    _vik_1137125_wa
F009B2A8: 01000000                 nop
F009B2AC: 81c7e008                 ret
F009B2B0: 81e80000                 restore
