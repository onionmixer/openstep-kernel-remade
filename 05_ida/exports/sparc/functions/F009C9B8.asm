F009C9B8: 9de3bf98                 save    %sp, -0x68, %sp
F009C9BC: 113c04f794122270         set     _pmap_info, %o2
F009C9C4: d002a048                 ld      [%o2+0x48], %o0
F009C9C8: f227a048                 st      %i1, [%fp+arg_48]
F009C9CC: 90022001                 inc     %o0
F009C9D0: d022a048                 st      %o0, [%o2+0x48]
F009C9D4: 113fff00                 sethi   -0x40000, %o0
F009C9D8: d2062010                 ld      [%i0+0x10], %o1
F009C9DC: b20e4008                 and     %i1, %o0, %i1
F009C9E0: 80a64009                 cmp     %i1, %o1
F009C9E4: 32800004                 bne,a   loc_F009C9F4
F009C9E8: d002a04c                 ld      [%o2+0x4C], %o0
F009C9EC: 1080007d                 ba      locret_F009CBE0
F009C9F0: f0062008                 ld      [%i0+8], %i0
F009C9F4: 90022001                 inc     %o0
F009C9F8: d022a04c                 st      %o0, [%o2+0x4C]
F009C9FC: f2060000                 ld      [%i0], %i1
F009CA00: d00fa048                 ldub    [%fp+arg_48], %o0
F009CA04: e4064000                 ld      [%i1], %l2
F009CA08: a12a2002                 sll     %o0, 2, %l0
F009CA0C: d0048010                 ld      [%l2+%l0], %o0
F009CA10: 900a2003                 and     %o0, 3, %o0
F009CA14: 80a22001                 cmp     %o0, 1
F009CA18: 2280000d                 be,a    loc_F009CA4C
F009CA1C: 80a6a001                 cmp     %i2, 1
F009CA20: 14800007                 bg      loc_F009CA3C
F009CA24: 80a22002                 cmp     %o0, 2
F009CA28: 80a22000                 cmp     %o0, 0
F009CA2C: 22800026                 be,a    loc_F009CAC4
F009CA30: 901ea001                 xor     %i2, 1, %o0
F009CA34: 10800028                 ba      loc_F009CAD4
F009CA38: 113c045f                 sethi   -0xFEE8400, %o0
F009CA3C: 0280001b                 be      loc_F009CAA8
F009CA40: 80a6a001                 cmp     %i2, 1
F009CA44: 10800024                 ba      loc_F009CAD4
F009CA48: 113c045f                 sethi   -0xFEE8400, %o0
F009CA4C: 32800006                 bne,a   loc_F009CA64
F009CA50: d007a048                 ld      [%fp+arg_48], %o0
F009CA54: 113c045e                 sethi   %hi(aPmapPageTableE), %o0! "pmap_page_table_entry: pte expected in "...
F009CA58: 7ffde1c6                 call    _panic
F009CA5C: 901223c0                 bset    %lo(aPmapPageTableE), %o0! "pmap_page_table_entry: pte expected in "...
F009CA60: d007a048                 ld      [%fp+arg_48], %o0
F009CA64: 333fc000                 sethi   -0x1000000, %i1
F009CA68: d206200c                 ld      [%i0+0xC], %o1
F009CA6C: 900a0019                 and     %o0, %i1, %o0
F009CA70: 80a20009                 cmp     %o0, %o1
F009CA74: 32800004                 bne,a   loc_F009CA84
F009CA78: d0048010                 ld      [%l2+%l0], %o0
F009CA7C: 10800018                 ba      loc_F009CADC
F009CA80: e2062004                 ld      [%i0+4], %l1
F009CA84: 91322002                 srl     %o0, 2, %o0
F009CA88: 400016cf                 call    _pmap_seg_entry
F009CA8C: 912a2006                 sll     %o0, 6, %o0
F009CA90: a2100008                 mov     %o0, %l1
F009CA94: d007a048                 ld      [%fp+arg_48], %o0
F009CA98: e2262004                 st      %l1, [%i0+4]
F009CA9C: 900a0019                 and     %o0, %i1, %o0
F009CAA0: 1080000f                 ba      loc_F009CADC
F009CAA4: d026200c                 st      %o0, [%i0+0xC]
F009CAA8: 18800004                 bgu     loc_F009CAB8
F009CAAC: 113c045e                 sethi   -0xFEE8800, %o0! char *
F009CAB0: 1080004c                 ba      locret_F009CBE0
F009CAB4: b0100019                 mov     %i1, %i0
F009CAB8: 7ffde1ae                 call    _panic
F009CABC: 901223f8                 bset    0x3F8, %o0
F009CAC0: 901ea001                 xor     %i2, 1, %o0! char *
F009CAC4: 80a00008                 cmp     %g0, %o0
F009CAC8: b0403fff                 addc    %g0, -1, %i0
F009CACC: 10800045                 ba      locret_F009CBE0
F009CAD0: b00e4018                 and     %i1, %i0, %i0
F009CAD4: 7ffde1a7                 call    _panic
F009CAD8: 90122020                 bset    0x20, %o0 ! ' '
F009CADC: d0044000                 ld      [%l1], %o0
F009CAE0: 80a22000                 cmp     %o0, 0
F009CAE4: 32800006                 bne,a   loc_F009CAFC
F009CAE8: d017a048                 lduh    [%fp+arg_48], %o0
F009CAEC: 113c045f                 sethi   %hi(aPmapPageTableE_0), %o0! "pmap_page_table_entry: seg_entry_t with"...
F009CAF0: 7ffde1a0                 call    _panic
F009CAF4: 90122048                 bset    %lo(aPmapPageTableE_0), %o0! "pmap_page_table_entry: seg_entry_t with"...
F009CAF8: d017a048                 lduh    [%fp+arg_48], %o0
F009CAFC: e0044000                 ld      [%l1], %l0
F009CB00: b20a20fc                 and     %o0, 0xFC, %i1
F009CB04: d0040019                 ld      [%l0+%i1], %o0
F009CB08: 900a2003                 and     %o0, 3, %o0
F009CB0C: 80a22001                 cmp     %o0, 1
F009CB10: 2280000d                 be,a    loc_F009CB44
F009CB14: 80a6a002                 cmp     %i2, 2
F009CB18: 14800007                 bg      loc_F009CB34
F009CB1C: 80a22002                 cmp     %o0, 2
F009CB20: 80a22000                 cmp     %o0, 0
F009CB24: 22800021                 be,a    loc_F009CBA8
F009CB28: 901ea002                 xor     %i2, 2, %o0
F009CB2C: 10800023                 ba      loc_F009CBB8
F009CB30: 113c045f                 sethi   -0xFEE8400, %o0
F009CB34: 02800014                 be      loc_F009CB84
F009CB38: 80a6a002                 cmp     %i2, 2
F009CB3C: 1080001f                 ba      loc_F009CBB8
F009CB40: 113c045f                 sethi   -0xFEE8400, %o0
F009CB44: 32800006                 bne,a   loc_F009CB5C
F009CB48: d0040019                 ld      [%l0+%i1], %o0
F009CB4C: 113c045f                 sethi   %hi(aPmapPageTableE_1), %o0! "pmap_page_table_entry: pte expected in "...
F009CB50: 7ffde188                 call    _panic
F009CB54: 90122078                 bset    %lo(aPmapPageTableE_1), %o0! "pmap_page_table_entry: pte expected in "...
F009CB58: d0040019                 ld      [%l0+%i1], %o0
F009CB5C: 91322002                 srl     %o0, 2, %o0
F009CB60: 40001699                 call    _pmap_seg_entry
F009CB64: 912a2006                 sll     %o0, 6, %o0
F009CB68: a6100008                 mov     %o0, %l3
F009CB6C: e6262008                 st      %l3, [%i0+8]
F009CB70: d007a048                 ld      [%fp+arg_48], %o0
F009CB74: 133fff00                 sethi   -0x40000, %o1
F009CB78: 900a0009                 and     %o0, %o1, %o0
F009CB7C: 10800011                 ba      loc_F009CBC0
F009CB80: d0262010                 st      %o0, [%i0+0x10]
F009CB84: 02800004                 be      loc_F009CB94
F009CB88: 80a6a000                 cmp     %i2, 0
F009CB8C: 12800004                 bne     loc_F009CB9C
F009CB90: 113c045f                 sethi   -0xFEE8400, %o0! char *
F009CB94: 10800013                 ba      locret_F009CBE0
F009CB98: b0100011                 mov     %l1, %i0
F009CB9C: 7ffde175                 call    _panic
F009CBA0: 901220b0                 bset    0xB0, %o0
F009CBA4: 901ea002                 xor     %i2, 2, %o0! char *
F009CBA8: 80a00008                 cmp     %g0, %o0
F009CBAC: b0403fff                 addc    %g0, -1, %i0
F009CBB0: 1080000c                 ba      locret_F009CBE0
F009CBB4: b00c4018                 and     %l1, %i0, %i0
F009CBB8: 7ffde16e                 call    _panic
F009CBBC: 901220d8                 bset    0xD8, %o0
F009CBC0: d004c000                 ld      [%l3], %o0
F009CBC4: 80a22000                 cmp     %o0, 0
F009CBC8: 12800006                 bne     locret_F009CBE0
F009CBCC: b0100013                 mov     %l3, %i0
F009CBD0: 113c045f                 sethi   %hi(aPmapPageTableE_2), %o0! "pmap_page_table_entry: page_entry_t wit"...
F009CBD4: 7ffde167                 call    _panic
F009CBD8: 90122100                 bset    %lo(aPmapPageTableE_2), %o0! "pmap_page_table_entry: page_entry_t wit"...
F009CBDC: b0100013                 mov     %l3, %i0
F009CBE0: 81c7e008                 ret
F009CBE4: 81e80000                 restore
