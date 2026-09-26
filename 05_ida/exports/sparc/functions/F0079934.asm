F0079934: 9de3bf88                 save    %sp, -0x78, %sp
F0079938: 80a62000                 cmp     %i0, 0
F007993C: 12800004                 bne     loc_F007994C
F0079940: ba10001b                 mov     %i3, %i5
F0079944: 108000f8                 ba      locret_F0079D24
F0079948: b0102016                 mov     0x16, %i0
F007994C: a6102000                 mov     0, %l3
F0079950: a2102000                 mov     0, %l1
F0079954: 373c04f2ac16e3a8         set     _zget_space_lock, %l6
F007995C: 113c04f2ae1223b0         set     _zone_free_space, %l7
F0079964: 2b3c04ef                 sethi   -0xFEC4400, %l5
F0079968: a8102000                 mov     0, %l4
F007996C: a0102000                 mov     0, %l0
F0079970: d0058000                 ld      [%l6], %o0
F0079974: 80a22000                 cmp     %o0, 0
F0079978: 12bffffe                 bne     loc_F0079970
F007997C: 01000000                 nop
F0079980: 4000754a                 call    _simple_lock_try
F0079984: 90100016                 mov     %l6, %o0
F0079988: 80a22000                 cmp     %o0, 0
F007998C: 02bffff9                 be      loc_F0079970
F0079990: a4102000                 mov     0, %l2
F0079994: 113c04f2                 sethi   %hi(_zone_free_space_count), %o0
F0079998: d00223d0                 ld      [%o0+%lo(_zone_free_space_count)], %o0
F007999C: 80a48008                 cmp     %l2, %o0
F00799A0: 1a80000b                 bcc     loc_F00799CC
F00799A4: b0100012                 mov     %l2, %i0
F00799A8: 94100008                 mov     %o0, %o2
F00799AC: 92102000                 mov     0, %o1
F00799B0: b0062001                 inc     %i0
F00799B4: d0024017                 ld      [%o1+%l7], %o0
F00799B8: 80a6000a                 cmp     %i0, %o2
F00799BC: d002200c                 ld      [%o0+0xC], %o0
F00799C0: 92026004                 inc     4, %o1
F00799C4: 0abffffb                 bcs     loc_F00799B0
F00799C8: a4048008                 add     %l2, %o0, %l2
F00799CC: d0068000                 ld      [%i2], %o0
F00799D0: 80a60008                 cmp     %i0, %o0
F00799D4: 1a800008                 bcc     loc_F00799F4
F00799D8: 912e2001                 sll     %i0, 1, %o0
F00799DC: 90020018                 add     %o0, %i0, %o0
F00799E0: 133c04d0                 sethi   %hi(_page_mask), %o1
F00799E4: d20260d8                 ld      [%o1+%lo(_page_mask)], %o1
F00799E8: 912a2002                 sll     %o0, 2, %o0
F00799EC: 90020009                 add     %o0, %o1, %o0
F00799F0: a02a0009                 andn    %o0, %o1, %l0
F00799F4: d0070000                 ld      [%i4], %o0
F00799F8: 80a48008                 cmp     %l2, %o0
F00799FC: 08800006                 bleu    loc_F0079A14
F0079A00: 113c04d0                 sethi   %hi(_page_mask), %o0
F0079A04: d20220d8                 ld      [%o0+%lo(_page_mask)], %o1
F0079A08: 912ca003                 sll     %l2, 3, %o0
F0079A0C: 90020009                 add     %o0, %o1, %o0
F0079A10: a82a0009                 andn    %o0, %o1, %l4
F0079A14: 80a40011                 cmp     %l0, %l1
F0079A18: 18800004                 bgu     loc_F0079A28
F0079A1C: 80a50013                 cmp     %l4, %l3
F0079A20: 0880003d                 bleu    loc_F0079B14
F0079A24: 80a46000                 cmp     %l1, 0
F0079A28: c026e3a8                 clr     [%i3+0x3A8]
F0079A2C: 80a44010                 cmp     %l1, %l0
F0079A30: 1a800019                 bcc     loc_F0079A94
F0079A34: 80a46000                 cmp     %l1, 0
F0079A38: 02800005                 be      loc_F0079A4C
F0079A3C: d00562f8                 ld      [%l5+0x2F8], %o0
F0079A40: d207bff4                 ld      [%fp+var_C], %o1
F0079A44: 40002790                 call    _kmem_free
F0079A48: 94100011                 mov     %l1, %o2
F0079A4C: a2100010                 mov     %l0, %l1
F0079A50: d00562f8                 ld      [%l5+0x2F8], %o0
F0079A54: 9207bff4                 add     %fp, var_C, %o1
F0079A58: 40002776                 call    _kmem_alloc_pageable
F0079A5C: 94100011                 mov     %l1, %o2
F0079A60: 80a22000                 cmp     %o0, 0
F0079A64: 02800007                 be      loc_F0079A80
F0079A68: 80a4e000                 cmp     %l3, 0
F0079A6C: 02800021                 be      loc_F0079AF0
F0079A70: d00562f8                 ld      [%l5+0x2F8], %o0
F0079A74: d207bff0                 ld      [%fp+var_10], %o1
F0079A78: 1080001c                 ba      loc_F0079AE8
F0079A7C: 94100013                 mov     %l3, %o2
F0079A80: d207bff4                 ld      [%fp+var_C], %o1
F0079A84: 96102000                 mov     0, %o3
F0079A88: d00562f8                 ld      [%l5+0x2F8], %o0
F0079A8C: 40002cd8                 call    _vm_map_pageable
F0079A90: 94024011                 add     %o1, %l1, %o2
F0079A94: 80a4c014                 cmp     %l3, %l4
F0079A98: 3abfffb5                 bcc,a   loc_F007996C
F0079A9C: a8102000                 mov     0, %l4
F0079AA0: 80a4e000                 cmp     %l3, 0
F0079AA4: 02800005                 be      loc_F0079AB8
F0079AA8: d00562f8                 ld      [%l5+0x2F8], %o0
F0079AAC: d207bff0                 ld      [%fp+var_10], %o1
F0079AB0: 40002775                 call    _kmem_free
F0079AB4: 94100013                 mov     %l3, %o2
F0079AB8: a6100014                 mov     %l4, %l3
F0079ABC: d00562f8                 ld      [%l5+0x2F8], %o0
F0079AC0: 9207bff0                 add     %fp, var_10, %o1
F0079AC4: 4000275b                 call    _kmem_alloc_pageable
F0079AC8: 94100013                 mov     %l3, %o2
F0079ACC: 80a22000                 cmp     %o0, 0
F0079AD0: 0280000a                 be      loc_F0079AF8
F0079AD4: 80a46000                 cmp     %l1, 0
F0079AD8: 02800006                 be      loc_F0079AF0
F0079ADC: d00562f8                 ld      [%l5+0x2F8], %o0
F0079AE0: d207bff4                 ld      [%fp+var_C], %o1
F0079AE4: 94100011                 mov     %l1, %o2
F0079AE8: 40002767                 call    _kmem_free
F0079AEC: 01000000                 nop
F0079AF0: 1080008d                 ba      locret_F0079D24
F0079AF4: b0102006                 mov     6, %i0
F0079AF8: d207bff0                 ld      [%fp+var_10], %o1
F0079AFC: 96102000                 mov     0, %o3
F0079B00: d00562f8                 ld      [%l5+0x2F8], %o0
F0079B04: 40002cba                 call    _vm_map_pageable
F0079B08: 94024013                 add     %o1, %l3, %o2
F0079B0C: 10bfff98                 ba      loc_F007996C
F0079B10: a8102000                 mov     0, %l4
F0079B14: 12800003                 bne     loc_F0079B20
F0079B18: da07bff4                 ld      [%fp+var_C], %o5
F0079B1C: da064000                 ld      [%i1], %o5
F0079B20: 80a4e000                 cmp     %l3, 0
F0079B24: 12800003                 bne     loc_F0079B30
F0079B28: d407bff0                 ld      [%fp+var_10], %o2
F0079B2C: d4074000                 ld      [%i5], %o2
F0079B30: 98102000                 mov     0, %o4
F0079B34: 80a30018                 cmp     %o4, %i0
F0079B38: 1a80001c                 bcc     loc_F0079BA8
F0079B3C: 113c04f2                 sethi   %hi(_zone_free_space), %o0
F0079B40: 861223b0                 or      %o0, %lo(_zone_free_space), %g3
F0079B44: 84102000                 mov     0, %g2
F0079B48: 96036008                 add     %o5, 8, %o3
F0079B4C: d2008003                 ld      [%g2+%g3], %o1
F0079B50: d0024000                 ld      [%o1], %o0
F0079B54: d0234000                 st      %o0, [%o5]
F0079B58: d0026004                 ld      [%o1+4], %o0
F0079B5C: d022fffc                 st      %o0, [%o3-4]
F0079B60: d002600c                 ld      [%o1+0xC], %o0
F0079B64: 9a03600c                 inc     0xC, %o5
F0079B68: d022c000                 st      %o0, [%o3]
F0079B6C: d2026008                 ld      [%o1+8], %o1
F0079B70: 80a26000                 cmp     %o1, 0
F0079B74: 02800009                 be      loc_F0079B98
F0079B78: 9602e00c                 inc     0xC, %o3
F0079B7C: d2228000                 st      %o1, [%o2]
F0079B80: d0026004                 ld      [%o1+4], %o0
F0079B84: d022a004                 st      %o0, [%o2+4]
F0079B88: d2024000                 ld      [%o1], %o1
F0079B8C: 80a26000                 cmp     %o1, 0
F0079B90: 12bffffb                 bne     loc_F0079B7C
F0079B94: 9402a008                 inc     8, %o2
F0079B98: 98032001                 inc     %o4
F0079B9C: 80a30018                 cmp     %o4, %i0
F0079BA0: 0abfffeb                 bcs     loc_F0079B4C
F0079BA4: 8400a004                 inc     4, %g2
F0079BA8: 113c04f2                 sethi   %hi(_zget_space_lock), %o0
F0079BAC: c02223a8                 clr     [%o0+%lo(_zget_space_lock)]
F0079BB0: 80a62000                 cmp     %i0, 0
F0079BB4: 02800022                 be      loc_F0079C3C
F0079BB8: 80a46000                 cmp     %l1, 0
F0079BBC: 02800020                 be      loc_F0079C3C
F0079BC0: 96102001                 mov     1, %o3
F0079BC4: 293c04ef                 sethi   %hi(_ipc_kernel_map), %l4
F0079BC8: 952e2001                 sll     %i0, 1, %o2
F0079BCC: 94028018                 add     %o2, %i0, %o2
F0079BD0: d207bff4                 ld      [%fp+var_C], %o1
F0079BD4: 193c04d0                 sethi   %hi(_page_mask), %o4
F0079BD8: d80320d8                 ld      [%o4+%lo(_page_mask)], %o4
F0079BDC: 952aa002                 sll     %o2, 2, %o2
F0079BE0: d00522f8                 ld      [%l4+%lo(_ipc_kernel_map)], %o0
F0079BE4: 9402800c                 add     %o2, %o4, %o2
F0079BE8: a02a800c                 andn    %o2, %o4, %l0
F0079BEC: 40002c80                 call    _vm_map_pageable
F0079BF0: 94024010                 add     %o1, %l0, %o2
F0079BF4: 96100010                 mov     %l0, %o3
F0079BF8: d00522f8                 ld      [%l4+%lo(_ipc_kernel_map)], %o0
F0079BFC: 98102001                 mov     1, %o4
F0079C00: d207bff4                 ld      [%fp+var_C], %o1
F0079C04: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F0079C08: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F0079C0C: 4000319b                 call    _vm_move
F0079C10: 9a07bfec                 add     %fp, var_14, %o5
F0079C14: 80a40011                 cmp     %l0, %l1
F0079C18: 02800006                 be      loc_F0079C30
F0079C1C: d207bff4                 ld      [%fp+var_C], %o1
F0079C20: 94244010                 sub     %l1, %l0, %o2
F0079C24: d00522f8                 ld      [%l4+0x2F8], %o0
F0079C28: 40002717                 call    _kmem_free
F0079C2C: 92024010                 add     %o1, %l0, %o1
F0079C30: d007bfec                 ld      [%fp+var_14], %o0
F0079C34: 1080000d                 ba      loc_F0079C68
F0079C38: d0264000                 st      %o0, [%i1]
F0079C3C: 80a62000                 cmp     %i0, 0
F0079C40: 1280000b                 bne     loc_F0079C6C
F0079C44: 80a4a000                 cmp     %l2, 0
F0079C48: 80a46000                 cmp     %l1, 0
F0079C4C: 02800007                 be      loc_F0079C68
F0079C50: c0264000                 clr     [%i1]
F0079C54: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F0079C58: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F0079C5C: d207bff4                 ld      [%fp+var_C], %o1
F0079C60: 40002709                 call    _kmem_free
F0079C64: 94100011                 mov     %l1, %o2
F0079C68: 80a4a000                 cmp     %l2, 0
F0079C6C: 02800021                 be      loc_F0079CF0
F0079C70: f0268000                 st      %i0, [%i2]
F0079C74: 80a4e000                 cmp     %l3, 0
F0079C78: 0280001e                 be      loc_F0079CF0
F0079C7C: 96102001                 mov     1, %o3
F0079C80: d207bff0                 ld      [%fp+var_10], %o1
F0079C84: 153c04d0                 sethi   %hi(_page_mask), %o2
F0079C88: d802a0d8                 ld      [%o2+%lo(_page_mask)], %o4
F0079C8C: 233c04ef                 sethi   %hi(_ipc_kernel_map), %l1
F0079C90: d00462f8                 ld      [%l1+%lo(_ipc_kernel_map)], %o0
F0079C94: 952ca003                 sll     %l2, 3, %o2
F0079C98: 9402800c                 add     %o2, %o4, %o2
F0079C9C: a02a800c                 andn    %o2, %o4, %l0
F0079CA0: 40002c53                 call    _vm_map_pageable
F0079CA4: 94024010                 add     %o1, %l0, %o2
F0079CA8: 96100010                 mov     %l0, %o3
F0079CAC: d00462f8                 ld      [%l1+%lo(_ipc_kernel_map)], %o0
F0079CB0: 98102001                 mov     1, %o4
F0079CB4: d207bff0                 ld      [%fp+var_10], %o1
F0079CB8: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F0079CBC: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F0079CC0: 4000316e                 call    _vm_move
F0079CC4: 9a07bfe8                 add     %fp, var_18, %o5
F0079CC8: 80a40013                 cmp     %l0, %l3
F0079CCC: 02800006                 be      loc_F0079CE4
F0079CD0: d207bff0                 ld      [%fp+var_10], %o1
F0079CD4: 9424c010                 sub     %l3, %l0, %o2
F0079CD8: d00462f8                 ld      [%l1+0x2F8], %o0
F0079CDC: 400026ea                 call    _kmem_free
F0079CE0: 92024010                 add     %o1, %l0, %o1
F0079CE4: d007bfe8                 ld      [%fp+var_18], %o0
F0079CE8: 1080000d                 ba      loc_F0079D1C
F0079CEC: d0274000                 st      %o0, [%i5]
F0079CF0: 80a4a000                 cmp     %l2, 0
F0079CF4: 3280000b                 bne,a   loc_F0079D20
F0079CF8: e4270000                 st      %l2, [%i4]
F0079CFC: 80a4e000                 cmp     %l3, 0
F0079D00: 02800007                 be      loc_F0079D1C
F0079D04: c0274000                 clr     [%i5]
F0079D08: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F0079D0C: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F0079D10: d207bff0                 ld      [%fp+var_10], %o1
F0079D14: 400026dc                 call    _kmem_free
F0079D18: 94100013                 mov     %l3, %o2
F0079D1C: e4270000                 st      %l2, [%i4]
F0079D20: b0102000                 mov     0, %i0
F0079D24: 81c7e008                 ret
F0079D28: 81e80000                 restore
