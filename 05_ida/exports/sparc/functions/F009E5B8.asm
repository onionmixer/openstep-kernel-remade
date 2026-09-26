F009E5B8: 9de3bf90                 save    %sp, -0x70, %sp
F009E5BC: 113c0464                 sethi   %hi(_physmax), %o0
F009E5C0: d0022388                 ld      [%o0+%lo(_physmax)], %o0
F009E5C4: 80a60008                 cmp     %i0, %o0
F009E5C8: 1a800062                 bcc     locret_F009E750
F009E5CC: 01000000                 nop
F009E5D0: 7fff9f80                 call    _vm_valid_page
F009E5D4: 90100018                 mov     %i0, %o0
F009E5D8: 80a22000                 cmp     %o0, 0
F009E5DC: 0280005d                 be      locret_F009E750
F009E5E0: 133c04f7                 sethi   %hi(_pmap_info), %o1
F009E5E4: 92126270                 bset    %lo(_pmap_info), %o1
F009E5E8: d002606c                 ld      [%o1+0x6C], %o0
F009E5EC: 90022001                 inc     %o0
F009E5F0: 7fffe1c3                 call    _splvm
F009E5F4: d022606c                 st      %o0, [%o1+0x6C]
F009E5F8: a6100008                 mov     %o0, %l3
F009E5FC: 7fff9f4f                 call    _vm_mem_ppi
F009E600: 90100018                 mov     %i0, %o0
F009E604: 153c04f7                 sethi   %hi(_pg_desc_tbl), %o2
F009E608: 932a2002                 sll     %o0, 2, %o1
F009E60C: 92024008                 add     %o1, %o0, %o1
F009E610: d002a260                 ld      [%o2+%lo(_pg_desc_tbl)], %o0
F009E614: 932a6002                 sll     %o1, 2, %o1
F009E618: a0020009                 add     %o0, %o1, %l0
F009E61C: d0042004                 ld      [%l0+4], %o0
F009E620: 80a22000                 cmp     %o0, 0
F009E624: 02800049                 be      loc_F009E748
F009E628: 80a42000                 cmp     %l0, 0
F009E62C: 30800045                 ba,a    loc_F009E740
F009E630: e2042004                 ld      [%l0+4], %l1
F009E634: 91322008                 srl     %o0, 8, %o0
F009E638: 912a200c                 sll     %o0, 12, %o0
F009E63C: d027bff4                 st      %o0, [%fp+var_C]
F009E640: b0046018                 add     %l1, 0x18, %i0
F009E644: d0060000                 ld      [%i0], %o0
F009E648: 80a22000                 cmp     %o0, 0
F009E64C: 12bffffe                 bne     loc_F009E644
F009E650: 01000000                 nop
F009E654: 7fffe215                 call    _simple_lock_try
F009E658: 90100018                 mov     %i0, %o0
F009E65C: 80a22000                 cmp     %o0, 0
F009E660: 02bffff9                 be      loc_F009E644
F009E664: 90100011                 mov     %l1, %o0
F009E668: d207bff4                 ld      [%fp+var_C], %o1
F009E66C: 7ffff8d3                 call    _pmap_page_table_entry
F009E670: 94102000                 mov     0, %o2
F009E674: b0920000                 orcc    %o0, %g0, %i0
F009E678: 02800019                 be      loc_F009E6DC
F009E67C: 113c045f                 sethi   -0xFEE8400, %o0
F009E680: d00e200d                 ldub    [%i0+0xD], %o0
F009E684: 80a22003                 cmp     %o0, 3
F009E688: 12800007                 bne     loc_F009E6A4
F009E68C: 80a22002                 cmp     %o0, 2
F009E690: d007bff4                 ld      [%fp+var_C], %o0
F009E694: d2060000                 ld      [%i0], %o1
F009E698: 9132200a                 srl     %o0, 10, %o0
F009E69C: 1080000a                 ba      loc_F009E6C4
F009E6A0: 900a20fc                 and     %o0, 0xFC, %o0
F009E6A4: 32800006                 bne,a   loc_F009E6BC
F009E6A8: d00fbff4                 ldub    [%fp+var_C], %o0
F009E6AC: d017bff4                 lduh    [%fp+var_C], %o0
F009E6B0: d2060000                 ld      [%i0], %o1
F009E6B4: 10800004                 ba      loc_F009E6C4
F009E6B8: 900a20fc                 and     %o0, 0xFC, %o0
F009E6BC: d2060000                 ld      [%i0], %o1
F009E6C0: 912a2002                 sll     %o0, 2, %o0
F009E6C4: a4024008                 add     %o1, %o0, %l2
F009E6C8: d0048000                 ld      [%l2], %o0
F009E6CC: 900a2003                 and     %o0, 3, %o0
F009E6D0: 80a22002                 cmp     %o0, 2
F009E6D4: 02800004                 be      loc_F009E6E4
F009E6D8: 113c045f                 sethi   -0xFEE8400, %o0! char *
F009E6DC: 7ffddaa5                 call    _panic
F009E6E0: 90122370                 bset    0x370, %o0
F009E6E4: d0048000                 ld      [%l2], %o0
F009E6E8: 900a201c                 and     %o0, 0x1C, %o0
F009E6EC: 80a22004                 cmp     %o0, 4
F009E6F0: 02800006                 be      loc_F009E708
F009E6F4: 80a2200c                 cmp     %o0, 0xC
F009E6F8: 02800004                 be      loc_F009E708
F009E6FC: 80a2201c                 cmp     %o0, 0x1C
F009E700: 1280000d                 bne     loc_F009E734
F009E704: 01000000                 nop
F009E708: 90100011                 mov     %l1, %o0
F009E70C: 40000b67                 call    _vm_to_srmmu_prot
F009E710: 92102001                 mov     1, %o1
F009E714: f027bff0                 st      %i0, [%fp+var_10]
F009E718: 94100008                 mov     %o0, %o2
F009E71C: d6048000                 ld      [%l2], %o3
F009E720: 9007bff0                 add     %fp, var_10, %o0
F009E724: d207bff4                 ld      [%fp+var_C], %o1
F009E728: 9732e007                 srl     %o3, 7, %o3
F009E72C: 40000bef                 call    _update_pte
F009E730: 960ae001                 and     %o3, 1, %o3
F009E734: c0246018                 clr     [%l1+0x18]
F009E738: e0040000                 ld      [%l0], %l0
F009E73C: 80a42000                 cmp     %l0, 0
F009E740: 32bfffbc                 bne,a   loc_F009E630
F009E744: d0042008                 ld      [%l0+8], %o0
F009E748: 7fffe177                 call    _splx
F009E74C: 90100013                 mov     %l3, %o0
F009E750: 81c7e008                 ret
F009E754: 81e80000                 restore
