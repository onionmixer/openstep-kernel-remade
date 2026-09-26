F009F82C: 9de3bf88                 save    %sp, -0x78, %sp
F009F830: 7fffdd33                 call    _splvm
F009F834: 01000000                 nop
F009F838: ae100008                 mov     %o0, %l7
F009F83C: 113c04f790122270         set     _pmap_info, %o0
F009F844: d20220a8                 ld      [%o0+0xA8], %o1
F009F848: 153c04f8a012a004         set     unk_F013E004, %l0
F009F850: 92026001                 inc     %o1
F009F854: d22220a8                 st      %o1, [%o0+0xA8]
F009F858: d0040000                 ld      [%l0], %o0
F009F85C: 80a22000                 cmp     %o0, 0
F009F860: 12bffffe                 bne     loc_F009F858
F009F864: 01000000                 nop
F009F868: 7fffdd90                 call    _simple_lock_try
F009F86C: 90100010                 mov     %l0, %o0
F009F870: 80a22000                 cmp     %o0, 0
F009F874: 02bffff9                 be      loc_F009F858
F009F878: aa07bff4                 add     %fp, var_C, %l5
F009F87C: 90100015                 mov     %l5, %o0
F009F880: 96102007                 mov     7, %o3
F009F884: 98102001                 mov     1, %o4
F009F888: 153c04f7a612a3f4         set     unk_F013DFF4, %l3
F009F890: 9a102000                 mov     0, %o5
F009F894: 253c04d0                 sethi   %hi(_page_mask), %l2
F009F898: 230003ff                 sethi   0xFFC00, %l1
F009F89C: d204fffc                 ld      [%l3-4], %o1
F009F8A0: a21463ff                 bset    0x3FF, %l1
F009F8A4: ec02a3f4                 ld      [%o2+0x3F4], %l6
F009F8A8: d227bff4                 st      %o1, [%fp+var_C]
F009F8AC: d404a0d8                 ld      [%l2+%lo(_page_mask)], %o2
F009F8B0: c023a05c                 clr     [%sp+0x78+var_1C]
F009F8B4: e804e00c                 ld      [%l3+0xC], %l4
F009F8B8: 92100016                 mov     %l6, %o1
F009F8BC: e004e008                 ld      [%l3+8], %l0
F009F8C0: 942e000a                 andn    %i0, %o2, %o2
F009F8C4: 9532a00c                 srl     %o2, 12, %o2
F009F8C8: 400007d4                 call    _set_pte
F009F8CC: 940a8011                 and     %o2, %l1, %o2
F009F8D0: e027bff4                 st      %l0, [%fp+var_C]
F009F8D4: c023a05c                 clr     [%sp+0x78+var_1C]
F009F8D8: 90100015                 mov     %l5, %o0
F009F8DC: 92100014                 mov     %l4, %o1
F009F8E0: 96102007                 mov     7, %o3
F009F8E4: 98102001                 mov     1, %o4
F009F8E8: d404a0d8                 ld      [%l2+0xD8], %o2
F009F8EC: 9a102000                 mov     0, %o5
F009F8F0: 942e400a                 andn    %i1, %o2, %o2
F009F8F4: 9532a00c                 srl     %o2, 12, %o2
F009F8F8: 400007c8                 call    _set_pte
F009F8FC: 940a8011                 and     %o2, %l1, %o2
F009F900: 133c0447                 sethi   %hi(_page_size), %o1! void *
F009F904: d402613c                 ld      [%o1+%lo(_page_size)], %o2! size_t
F009F908: 90100016                 mov     %l6, %o0! void *
F009F90C: 7fffd481                 call    _bcopy
F009F910: 92100014                 mov     %l4, %o1
F009F914: d004a0d8                 ld      [%l2+0xD8], %o0
F009F918: 902e4008                 andn    %i1, %o0, %o0
F009F91C: 9132200c                 srl     %o0, 12, %o0
F009F920: 40000664                 call    _pmap_vacflush
F009F924: 900a0011                 and     %o0, %l1, %o0
F009F928: c024e010                 clr     [%l3+0x10]
F009F92C: 7fffdcfe                 call    _splx
F009F930: 90100017                 mov     %l7, %o0
F009F934: 81c7e008                 ret
F009F938: 81e80000                 restore
