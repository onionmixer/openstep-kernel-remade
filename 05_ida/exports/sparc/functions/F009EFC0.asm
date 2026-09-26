F009EFC0: 9de3bf90                 save    %sp, -0x70, %sp
F009EFC4: 153c04f79412a270         set     _pmap_info, %o2
F009EFCC: d202a088                 ld      [%o2+0x88], %o1
F009EFD0: 90100018                 mov     %i0, %o0
F009EFD4: 92026001                 inc     %o1
F009EFD8: 7fff9cd8                 call    _vm_mem_ppi
F009EFDC: d222a088                 st      %o1, [%o2+0x88]
F009EFE0: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F009EFE4: 932a2002                 sll     %o0, 2, %o1
F009EFE8: 92024008                 add     %o1, %o0, %o1
F009EFEC: e002a260                 ld      [%o2+%lo(_pg_desc_tbl)], %l0
F009EFF0: 932a6002                 sll     %o1, 2, %o1
F009EFF4: 7fffdf42                 call    _splvm
F009EFF8: a0040009                 add     %l0, %o1, %l0
F009EFFC: d20c2010                 ldub    [%l0+0x10], %o1
F009F000: 922a4019                 bclr    %i1, %o1
F009F004: d22c2010                 stb     %o1, [%l0+0x10]
F009F008: e2042004                 ld      [%l0+4], %l1
F009F00C: 80a46000                 cmp     %l1, 0
F009F010: 02800084                 be      loc_F009F220
F009F014: a6100008                 mov     %o0, %l3
F009F018: a4102001                 mov     1, %l2
F009F01C: d0042008                 ld      [%l0+8], %o0
F009F020: b0046018                 add     %l1, 0x18, %i0
F009F024: 91322008                 srl     %o0, 8, %o0
F009F028: 912a200c                 sll     %o0, 12, %o0
F009F02C: d027bff4                 st      %o0, [%fp+var_C]
F009F030: d0060000                 ld      [%i0], %o0
F009F034: 80a22000                 cmp     %o0, 0
F009F038: 12bffffe                 bne     loc_F009F030
F009F03C: 01000000                 nop
F009F040: 7fffdf9a                 call    _simple_lock_try
F009F044: 90100018                 mov     %i0, %o0
F009F048: 80a22000                 cmp     %o0, 0
F009F04C: 02bffff9                 be      loc_F009F030
F009F050: 90100011                 mov     %l1, %o0
F009F054: d207bff4                 ld      [%fp+var_C], %o1
F009F058: 7ffff658                 call    _pmap_page_table_entry
F009F05C: 94102000                 mov     0, %o2
F009F060: b0920000                 orcc    %o0, %g0, %i0
F009F064: 02800066                 be      loc_F009F1FC
F009F068: 01000000                 nop
F009F06C: d00e200d                 ldub    [%i0+0xD], %o0
F009F070: 80a22003                 cmp     %o0, 3
F009F074: 12800007                 bne     loc_F009F090
F009F078: 80a22002                 cmp     %o0, 2
F009F07C: d007bff4                 ld      [%fp+var_C], %o0
F009F080: d2060000                 ld      [%i0], %o1
F009F084: 9132200a                 srl     %o0, 10, %o0
F009F088: 1080000a                 ba      loc_F009F0B0
F009F08C: 900a20fc                 and     %o0, 0xFC, %o0
F009F090: 32800006                 bne,a   loc_F009F0A8
F009F094: d00fbff4                 ldub    [%fp+var_C], %o0
F009F098: d017bff4                 lduh    [%fp+var_C], %o0
F009F09C: d2060000                 ld      [%i0], %o1
F009F0A0: 10800004                 ba      loc_F009F0B0
F009F0A4: 900a20fc                 and     %o0, 0xFC, %o0
F009F0A8: d2060000                 ld      [%i0], %o1
F009F0AC: 912a2002                 sll     %o0, 2, %o0
F009F0B0: 90024008                 add     %o1, %o0, %o0
F009F0B4: d0020000                 ld      [%o0], %o0
F009F0B8: 900a2003                 and     %o0, 3, %o0
F009F0BC: 80a22002                 cmp     %o0, 2
F009F0C0: 1280004f                 bne     loc_F009F1FC
F009F0C4: 9007bff0                 add     %fp, var_10, %o0
F009F0C8: f027bff0                 st      %i0, [%fp+var_10]
F009F0CC: d207bff4                 ld      [%fp+var_C], %o1
F009F0D0: 940e6001                 and     %i1, 1, %o2
F009F0D4: 40000a2d                 call    _set_pte_modref
F009F0D8: 960e6002                 and     %i1, 2, %o3
F009F0DC: 96920000                 orcc    %o0, %g0, %o3
F009F0E0: 02800047                 be      loc_F009F1FC
F009F0E4: 80a2e002                 cmp     %o3, 2
F009F0E8: 12800023                 bne     loc_F009F174
F009F0EC: 80a2e001                 cmp     %o3, 1
F009F0F0: d00e200d                 ldub    [%i0+0xD], %o0
F009F0F4: 80a22003                 cmp     %o0, 3
F009F0F8: 12800009                 bne     loc_F009F11C
F009F0FC: 80a22002                 cmp     %o0, 2
F009F100: d007bff4                 ld      [%fp+var_C], %o0
F009F104: 9132200c                 srl     %o0, 12, %o0
F009F108: 95322003                 srl     %o0, 3, %o2
F009F10C: 940aa004                 and     %o2, 4, %o2
F009F110: 94028018                 add     %o2, %i0, %o2
F009F114: 1080000a                 ba      loc_F009F13C
F009F118: 900a201e                 and     %o0, 0x1E, %o0
F009F11C: 1280000d                 bne     loc_F009F150
F009F120: d00fbff4                 ldub    [%fp+var_C], %o0
F009F124: d007bff4                 ld      [%fp+var_C], %o0
F009F128: 91322012                 srl     %o0, 18, %o0
F009F12C: 95322003                 srl     %o0, 3, %o2
F009F130: 940aa004                 and     %o2, 4, %o2
F009F134: 94028018                 add     %o2, %i0, %o2
F009F138: 900a201f                 and     %o0, 0x1F, %o0
F009F13C: d202a018                 ld      [%o2+0x18], %o1
F009F140: 912c8008                 sll     %l2, %o0, %o0
F009F144: 92124008                 bset    %o0, %o1
F009F148: 1080000a                 ba      loc_F009F170
F009F14C: d222a018                 st      %o1, [%o2+0x18]
F009F150: 95322005                 srl     %o0, 5, %o2
F009F154: 952aa002                 sll     %o2, 2, %o2
F009F158: 94028018                 add     %o2, %i0, %o2
F009F15C: 900a201f                 and     %o0, 0x1F, %o0
F009F160: d202a030                 ld      [%o2+0x30], %o1
F009F164: 912c8008                 sll     %l2, %o0, %o0
F009F168: 92124008                 bset    %o0, %o1
F009F16C: d222a030                 st      %o1, [%o2+0x30]
F009F170: 80a2e001                 cmp     %o3, 1
F009F174: 12800022                 bne     loc_F009F1FC
F009F178: 01000000                 nop
F009F17C: d00e200d                 ldub    [%i0+0xD], %o0
F009F180: 80a22003                 cmp     %o0, 3
F009F184: 12800009                 bne     loc_F009F1A8
F009F188: 80a22002                 cmp     %o0, 2
F009F18C: d007bff4                 ld      [%fp+var_C], %o0
F009F190: 9132200c                 srl     %o0, 12, %o0
F009F194: 93322003                 srl     %o0, 3, %o1
F009F198: 920a6004                 and     %o1, 4, %o1
F009F19C: 92024018                 add     %o1, %i0, %o1
F009F1A0: 1080000a                 ba      loc_F009F1C8
F009F1A4: 900a201e                 and     %o0, 0x1E, %o0
F009F1A8: 1280000d                 bne     loc_F009F1DC
F009F1AC: d00fbff4                 ldub    [%fp+var_C], %o0
F009F1B0: d007bff4                 ld      [%fp+var_C], %o0
F009F1B4: 91322012                 srl     %o0, 18, %o0
F009F1B8: 93322003                 srl     %o0, 3, %o1
F009F1BC: 920a6004                 and     %o1, 4, %o1
F009F1C0: 92024018                 add     %o1, %i0, %o1
F009F1C4: 900a201f                 and     %o0, 0x1F, %o0
F009F1C8: d4026018                 ld      [%o1+0x18], %o2
F009F1CC: 912ac008                 sll     %o3, %o0, %o0
F009F1D0: 902a8008                 andn    %o2, %o0, %o0
F009F1D4: 1080000a                 ba      loc_F009F1FC
F009F1D8: d0226018                 st      %o0, [%o1+0x18]
F009F1DC: 93322005                 srl     %o0, 5, %o1
F009F1E0: 932a6002                 sll     %o1, 2, %o1
F009F1E4: 92024018                 add     %o1, %i0, %o1
F009F1E8: 900a201f                 and     %o0, 0x1F, %o0
F009F1EC: d4026030                 ld      [%o1+0x30], %o2
F009F1F0: 912ac008                 sll     %o3, %o0, %o0
F009F1F4: 902a8008                 andn    %o2, %o0, %o0
F009F1F8: d0226030                 st      %o0, [%o1+0x30]
F009F1FC: c0246018                 clr     [%l1+0x18]
F009F200: e0040000                 ld      [%l0], %l0
F009F204: 80a42000                 cmp     %l0, 0
F009F208: 02800006                 be      loc_F009F220
F009F20C: 01000000                 nop
F009F210: e2042004                 ld      [%l0+4], %l1
F009F214: 80a46000                 cmp     %l1, 0
F009F218: 32bfff82                 bne,a   loc_F009F020
F009F21C: d0042008                 ld      [%l0+8], %o0
F009F220: 7fffdec1                 call    _splx
F009F224: 90100013                 mov     %l3, %o0
F009F228: 81c7e008                 ret
F009F22C: 81e80000                 restore
