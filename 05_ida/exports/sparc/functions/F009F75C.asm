F009F75C: 9de3bf88                 save    %sp, -0x78, %sp
F009F760: 7fffdd67                 call    _splvm
F009F764: 01000000                 nop
F009F768: a8100008                 mov     %o0, %l4
F009F76C: 113c04f790122270         set     _pmap_info, %o0
F009F774: d20220a4                 ld      [%o0+0xA4], %o1
F009F778: 153c04f8a012a010         set     unk_F013E010, %l0
F009F780: 92026001                 inc     %o1
F009F784: d22220a4                 st      %o1, [%o0+0xA4]
F009F788: d0040000                 ld      [%l0], %o0
F009F78C: 80a22000                 cmp     %o0, 0
F009F790: 12bffffe                 bne     loc_F009F788
F009F794: 01000000                 nop
F009F798: 7fffddc4                 call    _simple_lock_try
F009F79C: 90100010                 mov     %l0, %o0
F009F7A0: 80a22000                 cmp     %o0, 0
F009F7A4: 02bffff9                 be      loc_F009F788
F009F7A8: 153c04f8                 sethi   %hi(dword_F013E00C), %o2
F009F7AC: a612a00c                 or      %o2, %lo(dword_F013E00C), %l3
F009F7B0: 9007bff4                 add     %fp, var_C, %o0
F009F7B4: 253c04d0                 sethi   %hi(_page_mask), %l2
F009F7B8: 210003ffa01423ff         set     0xFFFFF, %l0
F009F7C0: 96102007                 mov     7, %o3
F009F7C4: 98102001                 mov     1, %o4
F009F7C8: d204fffc                 ld      [%l3-4], %o1
F009F7CC: 9a102000                 mov     0, %o5
F009F7D0: e202a00c                 ld      [%o2+%lo(dword_F013E00C)], %l1
F009F7D4: d227bff4                 st      %o1, [%fp+var_C]
F009F7D8: c023a05c                 clr     [%sp+0x78+var_1C]
F009F7DC: d404a0d8                 ld      [%l2+%lo(_page_mask)], %o2
F009F7E0: 92100011                 mov     %l1, %o1
F009F7E4: 942e000a                 andn    %i0, %o2, %o2
F009F7E8: 9532a00c                 srl     %o2, 12, %o2
F009F7EC: 4000080b                 call    _set_pte
F009F7F0: 940a8010                 and     %o2, %l0, %o2
F009F7F4: 113c0447                 sethi   %hi(_page_size), %o0! void *
F009F7F8: d202213c                 ld      [%o0+%lo(_page_size)], %o1! size_t
F009F7FC: 7fffd597                 call    _bzero
F009F800: 90100011                 mov     %l1, %o0
F009F804: d004a0d8                 ld      [%l2+0xD8], %o0
F009F808: 902e0008                 andn    %i0, %o0, %o0
F009F80C: 9132200c                 srl     %o0, 12, %o0
F009F810: 400006a8                 call    _pmap_vacflush
F009F814: 900a0010                 and     %o0, %l0, %o0
F009F818: c024e004                 clr     [%l3+4]
F009F81C: 7fffdd42                 call    _splx
F009F820: 90100014                 mov     %l4, %o0
F009F824: 81c7e008                 ret
F009F828: 81e80000                 restore
