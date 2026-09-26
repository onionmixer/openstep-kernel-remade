F0085630: 9de3bf70                 save    %sp, -0x90, %sp
F0085634: f627bfec                 st      %i3, [%fp+var_14]
F0085638: a610001c                 mov     %i4, %l3
F008563C: a410001a                 mov     %i2, %l2
F0085640: ae04801b                 add     %l2, %i3, %l7
F0085644: 80a5c012                 cmp     %l7, %l2
F0085648: c407a05c                 ld      [%fp+arg_5C], %g2
F008564C: ac07001b                 add     %i4, %i3, %l6
F0085650: 0a800005                 bcs     loc_F0085664
F0085654: c427bfdc                 st      %g2, [%fp+var_24]
F0085658: 80a5801c                 cmp     %l6, %i4
F008565C: 1a800004                 bcc     loc_F008566C
F0085660: 80a64018                 cmp     %i1, %i0
F0085664: 10800107                 ba      locret_F0085A80
F0085668: b0102003                 mov     3, %i0
F008566C: 02800009                 be      loc_F0085690
F0085670: 80a64018                 cmp     %i1, %i0
F0085674: 1680000d                 bge     loc_F00856A8
F0085678: 01000000                 nop
F008567C: 7fff8dd2                 call    _lock_write
F0085680: 90100019                 mov     %i1, %o0
F0085684: d006604c                 ld      [%i1+0x4C], %o0
F0085688: 90022001                 inc     %o0
F008568C: d026604c                 st      %o0, [%i1+0x4C]
F0085690: 7fff8dcd                 call    _lock_write
F0085694: 90100018                 mov     %i0, %o0
F0085698: d006204c                 ld      [%i0+0x4C], %o0
F008569C: 90022001                 inc     %o0
F00856A0: 1080000c                 ba      loc_F00856D0
F00856A4: d026204c                 st      %o0, [%i0+0x4C]
F00856A8: 7fff8dc7                 call    _lock_write
F00856AC: 90100018                 mov     %i0, %o0
F00856B0: d006204c                 ld      [%i0+0x4C], %o0
F00856B4: 90022001                 inc     %o0
F00856B8: d026204c                 st      %o0, [%i0+0x4C]
F00856BC: 7fff8dc2                 call    _lock_write
F00856C0: 90100019                 mov     %i1, %o0
F00856C4: d006604c                 ld      [%i1+0x4C], %o0
F00856C8: 90022001                 inc     %o0
F00856CC: d026604c                 st      %o0, [%i1+0x4C]
F00856D0: d006602c                 ld      [%i1+0x2C], %o0
F00856D4: 80a22000                 cmp     %o0, 0
F00856D8: 02800021                 be      loc_F008575C
F00856DC: c027bfe4                 clr     [%fp+var_1C]
F00856E0: d006202c                 ld      [%i0+0x2C], %o0
F00856E4: 80a22000                 cmp     %o0, 0
F00856E8: 0280001d                 be      loc_F008575C
F00856EC: 90100019                 mov     %i1, %o0
F00856F0: 92100013                 mov     %l3, %o1
F00856F4: 94100016                 mov     %l6, %o2
F00856F8: 7fffff2d                 call    _vm_map_check_protection
F00856FC: 96102001                 mov     1, %o3
F0085700: 80a22000                 cmp     %o0, 0
F0085704: 0280000b                 be      loc_F0085730
F0085708: 80a76000                 cmp     %i5, 0
F008570C: 1280000c                 bne     loc_F008573C
F0085710: 90100018                 mov     %i0, %o0
F0085714: 92100012                 mov     %l2, %o1
F0085718: 94100017                 mov     %l7, %o2
F008571C: 7fffff24                 call    _vm_map_check_protection
F0085720: 96102002                 mov     2, %o3
F0085724: 80a22000                 cmp     %o0, 0
F0085728: 1280000e                 bne     loc_F0085760
F008572C: 90100019                 mov     %i1, %o0
F0085730: 84102002                 mov     2, %g2
F0085734: 108000c3                 ba      loc_F0085A40
F0085738: c427bfe4                 st      %g2, [%fp+var_1C]
F008573C: 92102000                 mov     0, %o1
F0085740: 94102000                 mov     0, %o2
F0085744: 96100012                 mov     %l2, %o3
F0085748: 7ffffad5                 call    _vm_map_insert
F008574C: 98100017                 mov     %l7, %o4
F0085750: 80a22000                 cmp     %o0, 0
F0085754: 128000bb                 bne     loc_F0085A40
F0085758: d027bfe4                 st      %o0, [%fp+var_1C]
F008575C: 90100019                 mov     %i1, %o0
F0085760: 9210001c                 mov     %i4, %o1
F0085764: a207bff4                 add     %fp, var_C, %l1
F0085768: 7ffffb50                 call    _vm_map_lookup_entry
F008576C: 94100011                 mov     %l1, %o2
F0085770: e007bff4                 ld      [%fp+var_C], %l0
F0085774: d0042008                 ld      [%l0+8], %o0
F0085778: 80a4c008                 cmp     %l3, %o0
F008577C: 08800005                 bleu    loc_F0085790
F0085780: 9006600c                 add     %i1, 0xC, %o0
F0085784: 92100010                 mov     %l0, %o1
F0085788: 7ffffbe2                 call    __vm_map_clip_start
F008578C: 94100013                 mov     %l3, %o2
F0085790: 90100018                 mov     %i0, %o0
F0085794: 9210001a                 mov     %i2, %o1
F0085798: 7ffffb44                 call    _vm_map_lookup_entry
F008579C: 94100011                 mov     %l1, %o2
F00857A0: fa07bff4                 ld      [%fp+var_C], %i5
F00857A4: d0076008                 ld      [%i5+8], %o0
F00857A8: 80a48008                 cmp     %l2, %o0
F00857AC: 08800005                 bleu    loc_F00857C0
F00857B0: 9006200c                 add     %i0, 0xC, %o0
F00857B4: 9210001d                 mov     %i5, %o1
F00857B8: 7ffffbd6                 call    __vm_map_clip_start
F00857BC: 94100012                 mov     %l2, %o2
F00857C0: 80a4001d                 cmp     %l0, %i5
F00857C4: 12800007                 bne     loc_F00857E0
F00857C8: 90100019                 mov     %i1, %o0
F00857CC: 9210001c                 mov     %i4, %o1
F00857D0: 7ffffb36                 call    _vm_map_lookup_entry
F00857D4: 94100011                 mov     %l1, %o2
F00857D8: e007bff4                 ld      [%fp+var_C], %l0
F00857DC: 80a4001d                 cmp     %l0, %i5
F00857E0: 02800098                 be      loc_F0085A40
F00857E4: 80a4c016                 cmp     %l3, %l6
F00857E8: 3a800088                 bcc,a   loc_F0085A08
F00857EC: d006602c                 ld      [%i1+0x2C], %o0
F00857F0: 37200000                 sethi   0x80000000, %i3
F00857F4: d004200c                 ld      [%l0+0xC], %o0
F00857F8: 80a58008                 cmp     %l6, %o0
F00857FC: 1a800005                 bcc     loc_F0085810
F0085800: 9006600c                 add     %i1, 0xC, %o0
F0085804: 92100010                 mov     %l0, %o1
F0085808: 7ffffbfa                 call    __vm_map_clip_end
F008580C: 94100016                 mov     %l6, %o2
F0085810: d007600c                 ld      [%i5+0xC], %o0
F0085814: 80a5c008                 cmp     %l7, %o0
F0085818: 1a800005                 bcc     loc_F008582C
F008581C: 9006200c                 add     %i0, 0xC, %o0
F0085820: 9210001d                 mov     %i5, %o1
F0085824: 7ffffbf3                 call    __vm_map_clip_end
F0085828: 94100017                 mov     %l7, %o2
F008582C: d007600c                 ld      [%i5+0xC], %o0
F0085830: d2076008                 ld      [%i5+8], %o1
F0085834: d4042008                 ld      [%l0+8], %o2
F0085838: 90220009                 sub     %o0, %o1, %o0
F008583C: 94028008                 add     %o2, %o0, %o2
F0085840: d004200c                 ld      [%l0+0xC], %o0
F0085844: 80a28008                 cmp     %o2, %o0
F0085848: 1a800004                 bcc     loc_F0085858
F008584C: 9006600c                 add     %i1, 0xC, %o0
F0085850: 7ffffbe8                 call    __vm_map_clip_end
F0085854: 92100010                 mov     %l0, %o1
F0085858: d004200c                 ld      [%l0+0xC], %o0
F008585C: d2042008                 ld      [%l0+8], %o1
F0085860: d4076008                 ld      [%i5+8], %o2
F0085864: 90220009                 sub     %o0, %o1, %o0
F0085868: 94028008                 add     %o2, %o0, %o2
F008586C: d007600c                 ld      [%i5+0xC], %o0
F0085870: 80a28008                 cmp     %o2, %o0
F0085874: 1a800004                 bcc     loc_F0085884
F0085878: 9006200c                 add     %i0, 0xC, %o0
F008587C: 7ffffbdd                 call    __vm_map_clip_end
F0085880: 9210001d                 mov     %i5, %o1
F0085884: d0042018                 ld      [%l0+0x18], %o0
F0085888: 808a001b                 btst    %i3, %o0
F008588C: 3280000d                 bne,a   loc_F00858C0
F0085890: d007600c                 ld      [%i5+0xC], %o0
F0085894: d0076018                 ld      [%i5+0x18], %o0
F0085898: 808a001b                 btst    %i3, %o0
F008589C: 32800009                 bne,a   loc_F00858C0
F00858A0: d007600c                 ld      [%i5+0xC], %o0
F00858A4: 90100019                 mov     %i1, %o0
F00858A8: 92100018                 mov     %i0, %o1
F00858AC: 94100010                 mov     %l0, %o2
F00858B0: 7ffffedf                 call    _vm_map_copy_entry
F00858B4: 9610001d                 mov     %i5, %o3
F00858B8: 10800040                 ba      loc_F00859B8
F00858BC: e604200c                 ld      [%l0+0xC], %l3
F00858C0: d2042018                 ld      [%l0+0x18], %o1
F00858C4: d4076008                 ld      [%i5+8], %o2
F00858C8: 808a401b                 btst    %i3, %o1
F00858CC: 02800005                 be      loc_F00858E0
F00858D0: aa22000a                 sub     %o0, %o2, %l5
F00858D4: e6042010                 ld      [%l0+0x10], %l3
F00858D8: 10800006                 ba      loc_F00858F0
F00858DC: e8042014                 ld      [%l0+0x14], %l4
F00858E0: a6100019                 mov     %i1, %l3
F00858E4: e8042008                 ld      [%l0+8], %l4
F00858E8: 7fff8f82                 call    _lock_set_recursive
F00858EC: 90100019                 mov     %i1, %o0
F00858F0: d0076018                 ld      [%i5+0x18], %o0
F00858F4: 808a001b                 btst    %i3, %o0
F00858F8: 0280001a                 be      loc_F0085960
F00858FC: b4100018                 mov     %i0, %i2
F0085900: f4076010                 ld      [%i5+0x10], %i2
F0085904: e2076014                 ld      [%i5+0x14], %l1
F0085908: 80a68013                 cmp     %i2, %l3
F008590C: 02800018                 be      loc_F008596C
F0085910: a4044015                 add     %l1, %l5, %l2
F0085914: 7fff8d2c                 call    _lock_write
F0085918: 9010001a                 mov     %i2, %o0
F008591C: d006a04c                 ld      [%i2+0x4C], %o0
F0085920: 90022001                 inc     %o0
F0085924: d026a04c                 st      %o0, [%i2+0x4C]
F0085928: 9010001a                 mov     %i2, %o0
F008592C: 92100011                 mov     %l1, %o1
F0085930: 7ffffe25                 call    _vm_map_delete
F0085934: 94100012                 mov     %l2, %o2
F0085938: 9010001a                 mov     %i2, %o0
F008593C: 92102000                 mov     0, %o1
F0085940: 94102000                 mov     0, %o2
F0085944: 96100011                 mov     %l1, %o3
F0085948: 7ffffa55                 call    _vm_map_insert
F008594C: 98100012                 mov     %l2, %o4
F0085950: 7fff8db9                 call    _lock_done
F0085954: 9010001a                 mov     %i2, %o0
F0085958: 10800006                 ba      loc_F0085970
F008595C: c023a05c                 clr     [%sp+0x90+var_34]
F0085960: e2076008                 ld      [%i5+8], %l1
F0085964: 7fff8f63                 call    _lock_set_recursive
F0085968: 90100018                 mov     %i0, %o0
F008596C: c023a05c                 clr     [%sp+0x90+var_34]
F0085970: 9010001a                 mov     %i2, %o0
F0085974: 92100013                 mov     %l3, %o1
F0085978: 94100011                 mov     %l1, %o2
F008597C: 96100015                 mov     %l5, %o3
F0085980: 98100014                 mov     %l4, %o4
F0085984: 7fffff2b                 call    _vm_map_copy
F0085988: 9a102000                 mov     0, %o5
F008598C: 80a6001a                 cmp     %i0, %i2
F0085990: 12800005                 bne     loc_F00859A4
F0085994: 80a64013                 cmp     %i1, %l3
F0085998: 7fff8f6e                 call    _lock_clear_recursive
F008599C: 90100018                 mov     %i0, %o0
F00859A0: 80a64013                 cmp     %i1, %l3
F00859A4: 32800005                 bne,a   loc_F00859B8
F00859A8: e604200c                 ld      [%l0+0xC], %l3
F00859AC: 7fff8f69                 call    _lock_clear_recursive
F00859B0: 90100019                 mov     %i1, %o0
F00859B4: e604200c                 ld      [%l0+0xC], %l3
F00859B8: fa076004                 ld      [%i5+4], %i5
F00859BC: 84102000                 mov     0, %g2
F00859C0: 80a0a000                 cmp     %g2, 0
F00859C4: 0280000d                 be      loc_F00859F8
F00859C8: e0042004                 ld      [%l0+4], %l0
F00859CC: d006602c                 ld      [%i1+0x2C], %o0
F00859D0: 80a22000                 cmp     %o0, 0
F00859D4: 0280000a                 be      loc_F00859FC
F00859D8: 80a4c016                 cmp     %l3, %l6
F00859DC: d006202c                 ld      [%i0+0x2C], %o0
F00859E0: 80a22000                 cmp     %o0, 0
F00859E4: 02800006                 be      loc_F00859FC
F00859E8: 80a4c016                 cmp     %l3, %l6
F00859EC: d2040000                 ld      [%l0], %o1
F00859F0: 7ffffdcf                 call    _vm_map_entry_delete
F00859F4: 90100019                 mov     %i1, %o0
F00859F8: 80a4c016                 cmp     %l3, %l6
F00859FC: 2abfff7f                 bcs,a   loc_F00857F8
F0085A00: d004200c                 ld      [%l0+0xC], %o0
F0085A04: d006602c                 ld      [%i1+0x2C], %o0
F0085A08: 80a22000                 cmp     %o0, 0
F0085A0C: 0280000e                 be      loc_F0085A44
F0085A10: c407bfdc                 ld      [%fp+var_24], %g2
F0085A14: d006202c                 ld      [%i0+0x2C], %o0
F0085A18: 80a22000                 cmp     %o0, 0
F0085A1C: 02800009                 be      loc_F0085A40
F0085A20: 84102000                 mov     0, %g2
F0085A24: 80a0a000                 cmp     %g2, 0
F0085A28: 02800006                 be      loc_F0085A40
F0085A2C: c407bfec                 ld      [%fp+var_14], %g2
F0085A30: 9210001c                 mov     %i4, %o1
F0085A34: d0066024                 ld      [%i1+0x24], %o0
F0085A38: 40005dd1                 call    _pmap_remove
F0085A3C: 94070002                 add     %i4, %g2, %o2
F0085A40: c407bfdc                 ld      [%fp+var_24], %g2
F0085A44: 80a0a000                 cmp     %g2, 0
F0085A48: 02800006                 be      loc_F0085A60
F0085A4C: 90100019                 mov     %i1, %o0
F0085A50: c407bfec                 ld      [%fp+var_14], %g2
F0085A54: 9210001c                 mov     %i4, %o1
F0085A58: 7ffffddb                 call    _vm_map_delete
F0085A5C: 94024002                 add     %o1, %g2, %o2
F0085A60: 7fff8d75                 call    _lock_done
F0085A64: 90100019                 mov     %i1, %o0
F0085A68: 80a64018                 cmp     %i1, %i0
F0085A6C: 22800005                 be,a    locret_F0085A80
F0085A70: f007bfe4                 ld      [%fp+var_1C], %i0
F0085A74: 7fff8d70                 call    _lock_done
F0085A78: 90100018                 mov     %i0, %o0
F0085A7C: f007bfe4                 ld      [%fp+var_1C], %i0
F0085A80: 81c7e008                 ret
F0085A84: 81e80000                 restore
