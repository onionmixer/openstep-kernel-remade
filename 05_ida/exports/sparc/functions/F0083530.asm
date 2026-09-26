F0083530: 9de3bf90                 save    %sp, -0x70, %sp
F0083534: 80a6e000                 cmp     %i3, 0
F0083538: 02800004                 be      loc_F0083548
F008353C: a2102000                 mov     0, %l1
F0083540: 10800003                 ba      loc_F008354C
F0083544: d0062014                 ld      [%i0+0x14], %o0
F0083548: d0064000                 ld      [%i1], %o0
F008354C: d027bff4                 st      %o0, [%fp+var_C]
F0083550: 90100018                 mov     %i0, %o0
F0083554: 94100011                 mov     %l1, %o2
F0083558: 133c04d0                 sethi   %hi(_page_mask), %o1
F008355C: 9607bff4                 add     %fp, var_C, %o3
F0083560: da0260d8                 ld      [%o1+%lo(_page_mask)], %o5
F0083564: 213c04f4                 sethi   %hi(_kernel_object), %l0
F0083568: 9806800d                 add     %i2, %o5, %o4
F008356C: b42b000d                 andn    %o4, %o5, %i2
F0083570: 9810001a                 mov     %i2, %o4
F0083574: d2042340                 ld      [%l0+%lo(_kernel_object)], %o1
F0083578: 9a10001b                 mov     %i3, %o5
F008357C: 921f0009                 btog    %i4, %o1
F0083580: 80a00009                 cmp     %g0, %o1
F0083584: 92602000                 subc    %g0, 0, %o1
F0083588: 40000412                 call    _vm_map_find
F008358C: 920f0009                 and     %i4, %o1, %o1
F0083590: 80a00008                 cmp     %g0, %o0
F0083594: b6402000                 addc    %g0, 0, %i3
F0083598: 80a6e000                 cmp     %i3, 0
F008359C: 02800009                 be      loc_F00835C0
F00835A0: d0042340                 ld      [%l0+%lo(_kernel_object)], %o0
F00835A4: 80a70008                 cmp     %i4, %o0
F00835A8: 0280003a                 be      locret_F0083690
F00835AC: b010001b                 mov     %i3, %i0
F00835B0: 40000cc2                 call    _vm_object_deallocate
F00835B4: 9010001c                 mov     %i4, %o0
F00835B8: 10800036                 ba      locret_F0083690
F00835BC: b010001b                 mov     %i3, %i0
F00835C0: 80a70008                 cmp     %i4, %o0
F00835C4: 12800018                 bne     loc_F0083624
F00835C8: 9010001c                 mov     %i4, %o0
F00835CC: d407bff4                 ld      [%fp+var_C], %o2
F00835D0: 13040000                 sethi   0x10000000, %o1
F00835D4: 40000ca6                 call    _vm_object_reference
F00835D8: a2028009                 add     %o2, %o1, %l1
F00835DC: 7fff95fa                 call    _lock_write
F00835E0: 90100018                 mov     %i0, %o0
F00835E4: d006204c                 ld      [%i0+0x4C], %o0
F00835E8: 90022001                 inc     %o0
F00835EC: d026204c                 st      %o0, [%i0+0x4C]
F00835F0: d207bff4                 ld      [%fp+var_C], %o1
F00835F4: 90100018                 mov     %i0, %o0
F00835F8: 400006f3                 call    _vm_map_delete
F00835FC: 9402401a                 add     %o1, %i2, %o2
F0083600: 90100018                 mov     %i0, %o0
F0083604: 9210001c                 mov     %i4, %o1
F0083608: d607bff4                 ld      [%fp+var_C], %o3
F008360C: 94100011                 mov     %l1, %o2
F0083610: 40000323                 call    _vm_map_insert
F0083614: 9802c01a                 add     %o3, %i2, %o4
F0083618: 7fff9687                 call    _lock_done
F008361C: 90100018                 mov     %i0, %o0
F0083620: 9010001c                 mov     %i4, %o0
F0083624: 92100011                 mov     %l1, %o1
F0083628: 9410001a                 mov     %i2, %o2
F008362C: 400000a2                 call    sub_F00838B4
F0083630: 9610001d                 mov     %i5, %o3
F0083634: 80a22000                 cmp     %o0, 0
F0083638: 0280000a                 be      loc_F0083660
F008363C: d207bff4                 ld      [%fp+var_C], %o1
F0083640: 90100018                 mov     %i0, %o0
F0083644: 96102000                 mov     0, %o3
F0083648: 400005e9                 call    _vm_map_pageable
F008364C: 9402401a                 add     %o1, %i2, %o2
F0083650: d007bff4                 ld      [%fp+var_C], %o0
F0083654: b0102000                 mov     0, %i0
F0083658: 1080000e                 ba      locret_F0083690
F008365C: d0264000                 st      %o0, [%i1]
F0083660: 7fff95d9                 call    _lock_write
F0083664: 90100018                 mov     %i0, %o0
F0083668: d406204c                 ld      [%i0+0x4C], %o2
F008366C: 90100018                 mov     %i0, %o0
F0083670: d207bff4                 ld      [%fp+var_C], %o1
F0083674: 9402a001                 inc     %o2
F0083678: d426204c                 st      %o2, [%i0+0x4C]
F008367C: 400006d2                 call    _vm_map_delete
F0083680: 9402401a                 add     %o1, %i2, %o2
F0083684: 7fff966c                 call    _lock_done
F0083688: 90100018                 mov     %i0, %o0
F008368C: b0102006                 mov     6, %i0
F0083690: 81c7e008                 ret
F0083694: 81e80000                 restore
