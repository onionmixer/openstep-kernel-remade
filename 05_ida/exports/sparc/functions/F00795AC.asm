F00795AC: 9de3bf30                 save    %sp, -0xD0, %sp
F00795B0: ba100019                 mov     %i1, %i5
F00795B4: f427bfa4                 st      %i2, [%fp+var_5C]
F00795B8: f627bf9c                 st      %i3, [%fp+var_64]
F00795BC: f827bf94                 st      %i4, [%fp+var_6C]
F00795C0: aa102000                 mov     0, %l5
F00795C4: 80a62000                 cmp     %i0, 0
F00795C8: 12800004                 bne     loc_F00795D8
F00795CC: b4102000                 mov     0, %i2
F00795D0: 108000d7                 ba      locret_F007992C
F00795D4: b0102016                 mov     0x16, %i0
F00795D8: 113c04f2a0122380         set     _all_zones_lock, %l0
F00795E0: d0040000                 ld      [%l0], %o0
F00795E4: 80a22000                 cmp     %o0, 0
F00795E8: 12bffffe                 bne     loc_F00795E0
F00795EC: 01000000                 nop
F00795F0: 4000762e                 call    _simple_lock_try
F00795F4: 90100010                 mov     %l0, %o0
F00795F8: 80a22000                 cmp     %o0, 0
F00795FC: 02bffff9                 be      loc_F00795E0
F0079600: 113c04f2                 sethi   %hi(_num_zones), %o0
F0079604: e4022398                 ld      [%o0+%lo(_num_zones)], %l2
F0079608: 133c04f2                 sethi   %hi(_all_zones_lock), %o1
F007960C: c407bfa4                 ld      [%fp+var_5C], %g2
F0079610: c0226380                 clr     [%o1+%lo(_all_zones_lock)]
F0079614: d2008000                 ld      [%g2], %o1
F0079618: 113c04f2                 sethi   %hi(_first_zone), %o0
F007961C: 80a48009                 cmp     %l2, %o1
F0079620: 18800004                 bgu     loc_F0079630
F0079624: e0022388                 ld      [%o0+%lo(_first_zone)], %l0
F0079628: 10800011                 ba      loc_F007966C
F007962C: ec074000                 ld      [%i5], %l6
F0079630: 9207bff4                 add     %fp, var_C, %o1
F0079634: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F0079638: 952ca002                 sll     %l2, 2, %o2
F007963C: 94028012                 add     %o2, %l2, %o2
F0079640: 173c04d0                 sethi   %hi(_page_mask), %o3
F0079644: d602e0d8                 ld      [%o3+%lo(_page_mask)], %o3
F0079648: 952aa004                 sll     %o2, 4, %o2
F007964C: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F0079650: 9402800b                 add     %o2, %o3, %o2
F0079654: aa2a800b                 andn    %o2, %o3, %l5
F0079658: 40002876                 call    _kmem_alloc_pageable
F007965C: 94100015                 mov     %l5, %o2
F0079660: b0920000                 orcc    %o0, %g0, %i0
F0079664: 128000b2                 bne     locret_F007992C
F0079668: ec07bff4                 ld      [%fp+var_C], %l6
F007966C: c407bf94                 ld      [%fp+var_6C], %g2
F0079670: d0008000                 ld      [%g2], %o0
F0079674: 80a48008                 cmp     %l2, %o0
F0079678: 18800004                 bgu     loc_F0079688
F007967C: c407bf9c                 ld      [%fp+var_64], %g2
F0079680: 10800019                 ba      loc_F00796E4
F0079684: f2008000                 ld      [%g2], %i1
F0079688: 9207bff0                 add     %fp, var_10, %o1
F007968C: 233c04ef                 sethi   %hi(_ipc_kernel_map), %l1
F0079690: 952ca003                 sll     %l2, 3, %o2
F0079694: 94028012                 add     %o2, %l2, %o2
F0079698: 173c04d0                 sethi   %hi(_page_mask), %o3
F007969C: d602e0d8                 ld      [%o3+%lo(_page_mask)], %o3
F00796A0: 952aa002                 sll     %o2, 2, %o2
F00796A4: d00462f8                 ld      [%l1+%lo(_ipc_kernel_map)], %o0
F00796A8: 9402800b                 add     %o2, %o3, %o2
F00796AC: b42a800b                 andn    %o2, %o3, %i2
F00796B0: 40002860                 call    _kmem_alloc_pageable
F00796B4: 9410001a                 mov     %i2, %o2
F00796B8: b0920000                 orcc    %o0, %g0, %i0
F00796BC: 0280000a                 be      loc_F00796E4
F00796C0: f207bff0                 ld      [%fp+var_10], %i1
F00796C4: d0074000                 ld      [%i5], %o0
F00796C8: 80a58008                 cmp     %l6, %o0
F00796CC: 02800098                 be      locret_F007992C
F00796D0: d00462f8                 ld      [%l1+0x2F8], %o0
F00796D4: d207bff4                 ld      [%fp+var_C], %o1
F00796D8: 4000286b                 call    _kmem_free
F00796DC: 94100015                 mov     %l5, %o2! __n
F00796E0: 30800093                 ba,a    locret_F007992C
F00796E4: a6102000                 mov     0, %l3
F00796E8: 80a4c012                 cmp     %l3, %l2
F00796EC: 1a80005b                 bcc     loc_F0079858
F00796F0: 113c04f2                 sethi   %hi(__zone_default_space), %o0
F00796F4: 2f200000                 sethi   0x80000000, %l7
F00796F8: 373c04f2                 sethi   -0xFEC3800, %i3
F00796FC: b8122350                 or      %o0, %lo(__zone_default_space), %i4
F0079700: a2100019                 mov     %i1, %l1
F0079704: a8100016                 mov     %l6, %l4
F0079708: d004202c                 ld      [%l0+0x2C], %o0
F007970C: 808a0017                 btst    %l7, %o0
F0079710: 02800006                 be      loc_F0079728
F0079714: 01000000                 nop
F0079718: 7fffbdab                 call    _lock_write
F007971C: 90042030                 add     %l0, 0x30, %o0 ! '0'
F0079720: 1080000f                 ba      loc_F007975C
F0079724: 9007bfa8                 add     %fp, var_58, %o0
F0079728: 40007518                 call    _splusclock
F007972C: 01000000                 nop
F0079730: b0100008                 mov     %o0, %i0
F0079734: d0040000                 ld      [%l0], %o0
F0079738: 80a22000                 cmp     %o0, 0
F007973C: 12bffffe                 bne     loc_F0079734
F0079740: 01000000                 nop
F0079744: 400075d9                 call    _simple_lock_try
F0079748: 90100010                 mov     %l0, %o0
F007974C: 80a22000                 cmp     %o0, 0
F0079750: 02bffff9                 be      loc_F0079734
F0079754: 9007bfa8                 add     %fp, var_58, %o0! __dst
F0079758: f0242004                 st      %i0, [%l0+4]
F007975C: 92100010                 mov     %l0, %o1! __src
F0079760: 7ffe36d0                 call    _memcpy
F0079764: 94102044                 mov     0x44, %o2 ! 'D'
F0079768: d004202c                 ld      [%l0+0x2C], %o0
F007976C: 808a0017                 btst    %l7, %o0
F0079770: 22800006                 be,a    loc_F0079788
F0079774: d0042004                 ld      [%l0+4], %o0
F0079778: 7fffbe2f                 call    _lock_done
F007977C: 90042030                 add     %l0, 0x30, %o0 ! '0'
F0079780: 10800005                 ba      loc_F0079794
F0079784: b016e380                 or      %i3, 0x380, %i0
F0079788: c0240000                 clr     [%l0]
F007978C: 40007566                 call    _splx
F0079790: b016e380                 or      %i3, 0x380, %i0
F0079794: d0060000                 ld      [%i0], %o0
F0079798: 80a22000                 cmp     %o0, 0
F007979C: 12bffffe                 bne     loc_F0079794
F00797A0: 01000000                 nop
F00797A4: 400075c1                 call    _simple_lock_try
F00797A8: 90100018                 mov     %i0, %o0
F00797AC: 80a22000                 cmp     %o0, 0
F00797B0: 02bffff9                 be      loc_F0079794
F00797B4: 90100014                 mov     %l4, %o0! __dst
F00797B8: e0042040                 ld      [%l0+0x40], %l0
F00797BC: 94102050                 mov     0x50, %o2 ! 'P'! __n
F00797C0: d207bfd0                 ld      [%fp+__src], %o1! __src
F00797C4: c026e380                 clr     [%i3+0x380]
F00797C8: 7ffe3855                 call    _strncpy
F00797CC: 01000000                 nop
F00797D0: d007bfb0                 ld      [%fp+var_50], %o0
F00797D4: d0244000                 st      %o0, [%l1]
F00797D8: d007bfbc                 ld      [%fp+var_44], %o0
F00797DC: d0246004                 st      %o0, [%l1+4]
F00797E0: d007bfc0                 ld      [%fp+var_40], %o0
F00797E4: d0246008                 st      %o0, [%l1+8]
F00797E8: d007bfc4                 ld      [%fp+var_3C], %o0
F00797EC: d024600c                 st      %o0, [%l1+0xC]
F00797F0: d007bfc8                 ld      [%fp+var_38], %o0
F00797F4: d0246010                 st      %o0, [%l1+0x10]
F00797F8: d007bfd4                 ld      [%fp+var_2C], %o0
F00797FC: 9132201f                 srl     %o0, 31, %o0
F0079800: d0246014                 st      %o0, [%l1+0x14]
F0079804: d007bfd4                 ld      [%fp+var_2C], %o0
F0079808: 9132201e                 srl     %o0, 30, %o0
F007980C: 900a2001                 and     %o0, 1, %o0
F0079810: d0246018                 st      %o0, [%l1+0x18]
F0079814: d007bfd4                 ld      [%fp+var_2C], %o0
F0079818: 9132201d                 srl     %o0, 29, %o0
F007981C: 900a2001                 and     %o0, 1, %o0
F0079820: d024601c                 st      %o0, [%l1+0x1C]
F0079824: d007bfe4                 ld      [%fp+var_1C], %o0
F0079828: 80a22000                 cmp     %o0, 0
F007982C: 02800005                 be      loc_F0079840
F0079830: 92102000                 mov     0, %o1
F0079834: 901a001c                 btog    %i4, %o0
F0079838: 80a00008                 cmp     %g0, %o0
F007983C: 92402000                 addc    %g0, 0, %o1
F0079840: d2246020                 st      %o1, [%l1+0x20]
F0079844: a2046024                 inc     0x24, %l1 ! '$'
F0079848: a604e001                 inc     %l3
F007984C: 80a4c012                 cmp     %l3, %l2
F0079850: 0abfffae                 bcs     loc_F0079708
F0079854: a8052050                 inc     0x50, %l4 ! 'P'
F0079858: d0074000                 ld      [%i5], %o0
F007985C: 80a58008                 cmp     %l6, %o0
F0079860: 02800015                 be      loc_F00798B4
F0079864: 912ca002                 sll     %l2, 2, %o0
F0079868: 90020012                 add     %o0, %l2, %o0
F007986C: 952a2004                 sll     %o0, 4, %o2
F0079870: 80a28015                 cmp     %o2, %l5
F0079874: 02800005                 be      loc_F0079888
F0079878: d007bff4                 ld      [%fp+var_C], %o0! void *
F007987C: 9225400a                 sub     %l5, %o2, %o1! size_t
F0079880: 40006d76                 call    _bzero
F0079884: 9002000a                 add     %o0, %o2, %o0
F0079888: 96100015                 mov     %l5, %o3
F007988C: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F0079890: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F0079894: 98102001                 mov     1, %o4
F0079898: d207bff4                 ld      [%fp+var_C], %o1
F007989C: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F00798A0: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F00798A4: 40003275                 call    _vm_move
F00798A8: 9a07bff4                 add     %fp, var_C, %o5
F00798AC: d007bff4                 ld      [%fp+var_C], %o0
F00798B0: d0274000                 st      %o0, [%i5]
F00798B4: c407bfa4                 ld      [%fp+var_5C], %g2
F00798B8: e4208000                 st      %l2, [%g2]
F00798BC: c407bf9c                 ld      [%fp+var_64], %g2
F00798C0: d0008000                 ld      [%g2], %o0
F00798C4: 80a64008                 cmp     %i1, %o0
F00798C8: 02800016                 be      loc_F0079920
F00798CC: 912ca003                 sll     %l2, 3, %o0
F00798D0: 90020012                 add     %o0, %l2, %o0
F00798D4: 952a2002                 sll     %o0, 2, %o2
F00798D8: 80a2801a                 cmp     %o2, %i2
F00798DC: 02800005                 be      loc_F00798F0
F00798E0: d007bff0                 ld      [%fp+var_10], %o0! void *
F00798E4: 9226800a                 sub     %i2, %o2, %o1! size_t
F00798E8: 40006d5c                 call    _bzero
F00798EC: 9002000a                 add     %o0, %o2, %o0
F00798F0: 9610001a                 mov     %i2, %o3
F00798F4: 113c04ef                 sethi   %hi(_ipc_kernel_map), %o0
F00798F8: d00222f8                 ld      [%o0+%lo(_ipc_kernel_map)], %o0
F00798FC: 98102001                 mov     1, %o4
F0079900: d207bff0                 ld      [%fp+var_10], %o1
F0079904: 153c04ef                 sethi   %hi(_ipc_soft_map), %o2
F0079908: d402a320                 ld      [%o2+%lo(_ipc_soft_map)], %o2
F007990C: 4000325b                 call    _vm_move
F0079910: 9a07bff0                 add     %fp, var_10, %o5
F0079914: d007bff0                 ld      [%fp+var_10], %o0
F0079918: c407bf9c                 ld      [%fp+var_64], %g2
F007991C: d0208000                 st      %o0, [%g2]
F0079920: c407bf94                 ld      [%fp+var_6C], %g2
F0079924: b0102000                 mov     0, %i0
F0079928: e4208000                 st      %l2, [%g2]
F007992C: 81c7e008                 ret
F0079930: 81e80000                 restore
