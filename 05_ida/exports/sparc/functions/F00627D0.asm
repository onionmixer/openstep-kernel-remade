F00627D0: 9de3bf88                 save    %sp, -0x78, %sp
F00627D4: a4960000                 orcc    %i0, %g0, %l2
F00627D8: 12800004                 bne     loc_F00627E8
F00627DC: b8100019                 mov     %i1, %i4
F00627E0: 10800095                 ba      locret_F0062A34
F00627E4: b0102010                 mov     0x10, %i0
F00627E8: 113c0447                 sethi   %hi(_page_size), %o0
F00627EC: ec02213c                 ld      [%o0+%lo(_page_size)], %l6
F00627F0: 2f3c04ef                 sethi   -0xFEC4400, %l7
F00627F4: 33000080                 sethi   0x20000, %i1
F00627F8: d005e2f8                 ld      [%l7+0x2F8], %o0! target_task
F00627FC: 9207bff4                 add     %fp, var_C, %o1! address
F0062800: 94100016                 mov     %l6, %o2! size
F0062804: 4000a007                 call    _vm_allocate
F0062808: 96102001                 mov     1, %o3
F006280C: 80a22000                 cmp     %o0, 0
F0062810: 1280005c                 bne     loc_F0062980
F0062814: d207bff4                 ld      [%fp+var_C], %o1
F0062818: 96102000                 mov     0, %o3
F006281C: d005e2f8                 ld      [%l7+0x2F8], %o0
F0062820: 40008973                 call    _vm_map_pageable
F0062824: 94024016                 add     %o1, %l6, %o2
F0062828: 90100012                 mov     %l2, %o0
F006282C: 9210001c                 mov     %i4, %o1
F0062830: 7fffe493                 call    _ipc_right_lookup_write
F0062834: 9407bff0                 add     %fp, var_10, %o2
F0062838: b0920000                 orcc    %o0, %g0, %i0
F006283C: 12800053                 bne     loc_F0062988
F0062840: d407bff0                 ld      [%fp+var_10], %o2
F0062844: d0028000                 ld      [%o2], %o0
F0062848: 130007c0                 sethi   0x1F0000, %o1
F006284C: 900a0009                 and     %o0, %o1, %o0
F0062850: 13000200                 sethi   0x80000, %o1
F0062854: 80a20009                 cmp     %o0, %o1
F0062858: 12800051                 bne     loc_F006299C
F006285C: a2102000                 mov     0, %l1
F0062860: ea02a004                 ld      [%o2+4], %l5
F0062864: e604a018                 ld      [%l2+0x18], %l3
F0062868: c027bfec                 clr     [%fp+var_14]
F006286C: e807bff4                 ld      [%fp+var_C], %l4
F0062870: d004a014                 ld      [%l2+0x14], %o0
F0062874: 80a60013                 cmp     %i0, %l3
F0062878: 1a800011                 bcc     loc_F00628BC
F006287C: b135a002                 srl     %l6, 2, %i0
F0062880: a0100008                 mov     %o0, %l0
F0062884: d0040000                 ld      [%l0], %o0
F0062888: 808a0019                 btst    %i1, %o0
F006288C: 22800009                 be,a    loc_F00628B0
F0062890: a2046001                 inc     %l1
F0062894: 90100015                 mov     %l5, %o0
F0062898: d2042004                 ld      [%l0+4], %o1
F006289C: 94100018                 mov     %i0, %o2
F00628A0: 96100014                 mov     %l4, %o3
F00628A4: 7fffffb3                 call    _mach_port_gst_helper
F00628A8: 9807bfec                 add     %fp, var_14, %o4
F00628AC: a2046001                 inc     %l1
F00628B0: 80a44013                 cmp     %l1, %l3
F00628B4: 0abffff4                 bcs     loc_F0062884
F00628B8: a0042010                 inc     0x10, %l0
F00628BC: 7ffff005                 call    _ipc_splay_traverse_start
F00628C0: 9004a020                 add     %l2, 0x20, %o0 ! ' '
F00628C4: 1080000e                 ba      loc_F00628FC
F00628C8: 92100008                 mov     %o0, %o1
F00628CC: 808a0019                 btst    %i1, %o0
F00628D0: 02800007                 be      loc_F00628EC
F00628D4: 90100015                 mov     %l5, %o0
F00628D8: d2026004                 ld      [%o1+4], %o1
F00628DC: 94100018                 mov     %i0, %o2
F00628E0: 96100014                 mov     %l4, %o3
F00628E4: 7fffffa3                 call    _mach_port_gst_helper
F00628E8: 9807bfec                 add     %fp, var_14, %o4
F00628EC: 9004a020                 add     %l2, 0x20, %o0 ! ' '
F00628F0: 7ffff013                 call    _ipc_splay_traverse_next
F00628F4: 92102000                 mov     0, %o1
F00628F8: 92100008                 mov     %o0, %o1
F00628FC: 80a26000                 cmp     %o1, 0
F0062900: 32bffff3                 bne,a   loc_F00628CC
F0062904: d0024000                 ld      [%o1], %o0
F0062908: 7ffff08b                 call    _ipc_splay_traverse_finish
F006290C: 9004a020                 add     %l2, 0x20, %o0 ! ' '
F0062910: d007bfec                 ld      [%fp+var_14], %o0
F0062914: c024a008                 clr     [%l2+8]
F0062918: 80a20018                 cmp     %o0, %i0
F006291C: 0880000f                 bleu    loc_F0062958
F0062920: d005e2f8                 ld      [%l7+0x2F8], %o0
F0062924: d207bff4                 ld      [%fp+var_C], %o1
F0062928: 400083d7                 call    _kmem_free
F006292C: 94100016                 mov     %l6, %o2
F0062930: d207bfec                 ld      [%fp+var_14], %o1
F0062934: 113c04d0                 sethi   %hi(_page_mask), %o0
F0062938: d40220d8                 ld      [%o0+%lo(_page_mask)], %o2
F006293C: 932a6002                 sll     %o1, 2, %o1
F0062940: 9202400a                 add     %o1, %o2, %o1
F0062944: 113c0447                 sethi   %hi(_page_size), %o0
F0062948: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F006294C: 942a400a                 andn    %o1, %o2, %o2
F0062950: 10bfffaa                 ba      loc_F00627F8
F0062954: ac028008                 add     %o2, %o0, %l6
F0062958: da07bfec                 ld      [%fp+var_14], %o5
F006295C: 80a36000                 cmp     %o5, 0
F0062960: 12800016                 bne     loc_F00629B8
F0062964: 96102001                 mov     1, %o3
F0062968: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F006296C: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F0062970: c027bfe8                 clr     [%fp+var_18]
F0062974: d207bff4                 ld      [%fp+var_C], %o1
F0062978: 10800028                 ba      loc_F0062A18
F006297C: 94100016                 mov     %l6, %o2
F0062980: 1080002d                 ba      locret_F0062A34
F0062984: b0102006                 mov     6, %i0
F0062988: d005e2f8                 ld      [%l7+0x2F8], %o0
F006298C: d207bff4                 ld      [%fp+var_C], %o1
F0062990: 400083bd                 call    _kmem_free
F0062994: 94100016                 mov     %l6, %o2
F0062998: 30800027                 ba,a    locret_F0062A34
F006299C: d005e2f8                 ld      [%l7+0x2F8], %o0
F00629A0: c024a008                 clr     [%l2+8]
F00629A4: d207bff4                 ld      [%fp+var_C], %o1
F00629A8: 400083b7                 call    _kmem_free
F00629AC: 94100016                 mov     %l6, %o2
F00629B0: 10800021                 ba      locret_F0062A34
F00629B4: b0102011                 mov     0x11, %i0
F00629B8: d207bff4                 ld      [%fp+var_C], %o1
F00629BC: 153c04d0                 sethi   %hi(_page_mask), %o2
F00629C0: d802a0d8                 ld      [%o2+%lo(_page_mask)], %o4
F00629C4: 233c04ef                 sethi   %hi(_ipc_kernel_map), %l1
F00629C8: d00462f8                 ld      [%l1+%lo(_ipc_kernel_map)], %o0
F00629CC: 952b6002                 sll     %o5, 2, %o2
F00629D0: 9402800c                 add     %o2, %o4, %o2
F00629D4: a02a800c                 andn    %o2, %o4, %l0
F00629D8: 40008905                 call    _vm_map_pageable
F00629DC: 94024010                 add     %o1, %l0, %o2
F00629E0: 96100010                 mov     %l0, %o3
F00629E4: d00462f8                 ld      [%l1+%lo(_ipc_kernel_map)], %o0
F00629E8: 98102001                 mov     1, %o4
F00629EC: d207bff4                 ld      [%fp+var_C], %o1
F00629F0: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F00629F4: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F00629F8: 40008e20                 call    _vm_move
F00629FC: 9a07bfe8                 add     %fp, var_18, %o5
F0062A00: 80a40016                 cmp     %l0, %l6
F0062A04: 02800007                 be      loc_F0062A20
F0062A08: d207bff4                 ld      [%fp+var_C], %o1
F0062A0C: 94258010                 sub     %l6, %l0, %o2
F0062A10: d00462f8                 ld      [%l1+0x2F8], %o0
F0062A14: 92024010                 add     %o1, %l0, %o1
F0062A18: 4000839b                 call    _kmem_free
F0062A1C: 01000000                 nop
F0062A20: d007bfe8                 ld      [%fp+var_18], %o0
F0062A24: d0268000                 st      %o0, [%i2]
F0062A28: d007bfec                 ld      [%fp+var_14], %o0
F0062A2C: b0102000                 mov     0, %i0
F0062A30: d026c000                 st      %o0, [%i3]
F0062A34: 81c7e008                 ret
F0062A38: 81e80000                 restore
