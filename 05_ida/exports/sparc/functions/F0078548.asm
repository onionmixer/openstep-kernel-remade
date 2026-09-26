F0078548: 9de3bf98                 save    %sp, -0x68, %sp
F007854C: 113c04f2a41223b0         set     _zone_free_space, %l2
F0078554: 113c04f2                 sethi   %hi(_zone_free_space_count), %o0
F0078558: d00223d0                 ld      [%o0+%lo(_zone_free_space_count)], %o0
F007855C: ac102001                 mov     1, %l6
F0078560: 80a58008                 cmp     %l6, %o0
F0078564: 16800091                 bge     loc_F00787A8
F0078568: aa102000                 mov     0, %l5
F007856C: a404a004                 inc     4, %l2
F0078570: d0048000                 ld      [%l2], %o0
F0078574: e0022008                 ld      [%o0+8], %l0
F0078578: 80a42000                 cmp     %l0, 0
F007857C: 02800085                 be      loc_F0078790
F0078580: a8022008                 add     %o0, 8, %l4
F0078584: d4042004                 ld      [%l0+4], %o2
F0078588: 113c0447                 sethi   %hi(_page_size), %o0
F007858C: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F0078590: 80a28008                 cmp     %o2, %o0
F0078594: 0a80007a                 bcs     loc_F007877C
F0078598: 113c04d0                 sethi   %hi(_page_mask), %o0
F007859C: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F00785A0: 92040008                 add     %l0, %o0, %o1
F00785A4: 90380008                 xnor    %g0, %o0, %o0
F00785A8: a20a4008                 and     %o1, %o0, %l1
F00785AC: 9204000a                 add     %l0, %o2, %o1
F00785B0: a60a4008                 and     %o1, %o0, %l3
F00785B4: 80a44013                 cmp     %l1, %l3
F00785B8: 1a800071                 bcc     loc_F007877C
F00785BC: 113c04f2                 sethi   %hi(_zone_min), %o0
F00785C0: d00223e0                 ld      [%o0+%lo(_zone_min)], %o0
F00785C4: 80a44008                 cmp     %l1, %o0
F00785C8: 0a80006d                 bcs     loc_F007877C
F00785CC: 113c04f2                 sethi   %hi(_zone_max), %o0
F00785D0: d00223d8                 ld      [%o0+%lo(_zone_max)], %o0
F00785D4: 80a4c008                 cmp     %l3, %o0
F00785D8: 3880006a                 bgu,a   loc_F0078780
F00785DC: a8100010                 mov     %l0, %l4
F00785E0: d0048000                 ld      [%l2], %o0
F00785E4: 7ffffd48                 call    sub_F0077B04
F00785E8: 92100010                 mov     %l0, %o1
F00785EC: d0042004                 ld      [%l0+4], %o0
F00785F0: 90040008                 add     %l0, %o0, %o0
F00785F4: 80a20013                 cmp     %o0, %l3
F00785F8: 0280003b                 be      loc_F00786E4
F00785FC: 96100013                 mov     %l3, %o3
F0078600: 9022000b                 sub     %o0, %o3, %o0
F0078604: d022e004                 st      %o0, [%o3+4]
F0078608: d0040000                 ld      [%l0], %o0
F007860C: 80a22000                 cmp     %o0, 0
F0078610: 02800003                 be      loc_F007861C
F0078614: d022c000                 st      %o0, [%o3]
F0078618: d6222008                 st      %o3, [%o0+8]
F007861C: 80a40011                 cmp     %l0, %l1
F0078620: 12800005                 bne     loc_F0078634
F0078624: 90244010                 sub     %l1, %l0, %o0
F0078628: d6250000                 st      %o3, [%l4]
F007862C: 1080001b                 ba      loc_F0078698
F0078630: e822e008                 st      %l4, [%o3+8]
F0078634: d0242004                 st      %o0, [%l0+4]
F0078638: d6240000                 st      %o3, [%l0]
F007863C: e022e008                 st      %l0, [%o3+8]
F0078640: d2048000                 ld      [%l2], %o1
F0078644: d002600c                 ld      [%o1+0xC], %o0
F0078648: 90022001                 inc     %o0
F007864C: d022600c                 st      %o0, [%o1+0xC]
F0078650: d8048000                 ld      [%l2], %o4
F0078654: d0042004                 ld      [%l0+4], %o0
F0078658: d2032010                 ld      [%o4+0x10], %o1
F007865C: d4032018                 ld      [%o4+0x18], %o2
F0078660: 91320009                 srl     %o0, %o1, %o0
F0078664: 80a2000a                 cmp     %o0, %o2
F0078668: 34800002                 bg,a    loc_F0078670
F007866C: 9010000a                 mov     %o2, %o0
F0078670: d2032014                 ld      [%o4+0x14], %o1
F0078674: 912a2004                 sll     %o0, 4, %o0
F0078678: 92024008                 add     %o1, %o0, %o1
F007867C: d0027ff0                 ld      [%o1-0x10], %o0
F0078680: 80a22000                 cmp     %o0, 0
F0078684: 02800004                 be      loc_F0078694
F0078688: 80a40008                 cmp     %l0, %o0
F007868C: 3a800004                 bcc,a   loc_F007869C
F0078690: d8048000                 ld      [%l2], %o4
F0078694: e0227ff0                 st      %l0, [%o1-0x10]
F0078698: d8048000                 ld      [%l2], %o4
F007869C: d002e004                 ld      [%o3+4], %o0
F00786A0: d2032010                 ld      [%o4+0x10], %o1
F00786A4: d4032018                 ld      [%o4+0x18], %o2
F00786A8: 91320009                 srl     %o0, %o1, %o0
F00786AC: 80a2000a                 cmp     %o0, %o2
F00786B0: 34800002                 bg,a    loc_F00786B8
F00786B4: 9010000a                 mov     %o2, %o0
F00786B8: d2032014                 ld      [%o4+0x14], %o1
F00786BC: 912a2004                 sll     %o0, 4, %o0
F00786C0: 92024008                 add     %o1, %o0, %o1
F00786C4: d0027ff0                 ld      [%o1-0x10], %o0
F00786C8: 80a22000                 cmp     %o0, 0
F00786CC: 02800004                 be      loc_F00786DC
F00786D0: 80a2c008                 cmp     %o3, %o0
F00786D4: 3a800025                 bcc,a   loc_F0078768
F00786D8: 96100011                 mov     %l1, %o3
F00786DC: 10800022                 ba      loc_F0078764
F00786E0: d6227ff0                 st      %o3, [%o1-0x10]
F00786E4: 80a40011                 cmp     %l0, %l1
F00786E8: 02800015                 be      loc_F007873C
F00786EC: 90244010                 sub     %l1, %l0, %o0
F00786F0: d0242004                 st      %o0, [%l0+4]
F00786F4: d6048000                 ld      [%l2], %o3
F00786F8: d202e010                 ld      [%o3+0x10], %o1
F00786FC: d402e018                 ld      [%o3+0x18], %o2
F0078700: 91320009                 srl     %o0, %o1, %o0
F0078704: 80a2000a                 cmp     %o0, %o2
F0078708: 34800002                 bg,a    loc_F0078710
F007870C: 9010000a                 mov     %o2, %o0
F0078710: d202e014                 ld      [%o3+0x14], %o1
F0078714: 912a2004                 sll     %o0, 4, %o0
F0078718: 92024008                 add     %o1, %o0, %o1
F007871C: d0027ff0                 ld      [%o1-0x10], %o0
F0078720: 80a22000                 cmp     %o0, 0
F0078724: 02800004                 be      loc_F0078734
F0078728: 80a40008                 cmp     %l0, %o0
F007872C: 1a80000f                 bcc     loc_F0078768
F0078730: 96100011                 mov     %l1, %o3
F0078734: 1080000c                 ba      loc_F0078764
F0078738: e0227ff0                 st      %l0, [%o1-0x10]
F007873C: d0040000                 ld      [%l0], %o0
F0078740: 80a22000                 cmp     %o0, 0
F0078744: 02800004                 be      loc_F0078754
F0078748: d0250000                 st      %o0, [%l4]
F007874C: d0040000                 ld      [%l0], %o0
F0078750: e8222008                 st      %l4, [%o0+8]
F0078754: d2048000                 ld      [%l2], %o1
F0078758: d002600c                 ld      [%o1+0xC], %o0
F007875C: 90023fff                 inc     -1, %o0
F0078760: d022600c                 st      %o0, [%o1+0xC]
F0078764: 96100011                 mov     %l1, %o3
F0078768: 9024c00b                 sub     %l3, %o3, %o0
F007876C: d022e004                 st      %o0, [%o3+4]
F0078770: ea22c000                 st      %l5, [%o3]
F0078774: 10800003                 ba      loc_F0078780
F0078778: aa10000b                 mov     %o3, %l5
F007877C: a8100010                 mov     %l0, %l4
F0078780: e0050000                 ld      [%l4], %l0
F0078784: 80a42000                 cmp     %l0, 0
F0078788: 32bfff80                 bne,a   loc_F0078588
F007878C: d4042004                 ld      [%l0+4], %o2
F0078790: 113c04f2                 sethi   %hi(_zone_free_space_count), %o0
F0078794: d00223d0                 ld      [%o0+%lo(_zone_free_space_count)], %o0
F0078798: ac05a001                 inc     %l6
F007879C: 80a58008                 cmp     %l6, %o0
F00787A0: 26bfff74                 bl,a    loc_F0078570
F00787A4: a404a004                 inc     4, %l2
F00787A8: 113c04f2                 sethi   %hi(_zget_space_lock), %o0
F00787AC: c02223a8                 clr     [%o0+%lo(_zget_space_lock)]
F00787B0: a0954000                 orcc    %l5, %g0, %l0
F00787B4: 0280000a                 be      locret_F00787DC
F00787B8: 233c0442                 sethi   -0xFEEF800, %l1
F00787BC: ea040000                 ld      [%l0], %l5
F00787C0: d00463ec                 ld      [%l1+0x3EC], %o0
F00787C4: d4042004                 ld      [%l0+4], %o2
F00787C8: 40002c2f                 call    _kmem_free
F00787CC: 92100010                 mov     %l0, %o1
F00787D0: a0954000                 orcc    %l5, %g0, %l0
F00787D4: 32bffffb                 bne,a   loc_F00787C0
F00787D8: ea040000                 ld      [%l0], %l5
F00787DC: 81c7e008                 ret
F00787E0: 81e80000                 restore
