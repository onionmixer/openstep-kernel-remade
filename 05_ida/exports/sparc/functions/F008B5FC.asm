F008B5FC: 9de3bf90                 save    %sp, -0x70, %sp
F008B600: d0062014                 ld      [%i0+0x14], %o0
F008B604: e6022028                 ld      [%o0+0x28], %l3
F008B608: 7ffffd9b                 call    _vnode_pager_vget
F008B60C: 90100013                 mov     %l3, %o0
F008B610: d4062014                 ld      [%i0+0x14], %o2
F008B614: d6062018                 ld      [%i0+0x18], %o3
F008B618: a4102000                 mov     0, %l2
F008B61C: d204e00c                 ld      [%l3+0xC], %o1
F008B620: a2100008                 mov     %o0, %l1
F008B624: d002a02c                 ld      [%o2+0x2C], %o0
F008B628: 80a26000                 cmp     %o1, 0
F008B62C: 16800017                 bge     loc_F008B688
F008B630: a002c008                 add     %o3, %o0, %l0
F008B634: 90100013                 mov     %l3, %o0
F008B638: 92100010                 mov     %l0, %o1
F008B63C: 94102001                 mov     1, %o2
F008B640: 7ffffebe                 call    sub_F008B138
F008B644: 9607bff4                 add     %fp, var_C, %o3
F008B648: 80a22005                 cmp     %o0, 5
F008B64C: 12800004                 bne     loc_F008B65C
F008B650: 153fc000                 sethi   -0x1000000, %o2
F008B654: 1080000d                 ba      loc_F008B688
F008B658: a4102001                 mov     1, %l2
F008B65C: 173c04f4                 sethi   %hi(_page_shift), %o3
F008B660: d007bff4                 ld      [%fp+var_C], %o0
F008B664: 133c04c3                 sethi   %hi(unk_F0130F70), %o1
F008B668: 942a000a                 andn    %o0, %o2, %o2
F008B66C: d00fbff4                 ldub    [%fp+var_C], %o0
F008B670: 92126370                 bset    %lo(unk_F0130F70), %o1
F008B674: d602e348                 ld      [%o3+%lo(_page_shift)], %o3
F008B678: 912a2002                 sll     %o0, 2, %o0
F008B67C: d0020009                 ld      [%o0+%o1], %o0
F008B680: a12a800b                 sll     %o2, %o3, %l0
F008B684: e2022008                 ld      [%o0+8], %l1
F008B688: 80a4a001                 cmp     %l2, 1
F008B68C: 0280000d                 be      loc_F008B6C0
F008B690: 90100011                 mov     %l1, %o0
F008B694: d404601c                 ld      [%l1+0x1C], %o2
F008B698: d602a074                 ld      [%o2+0x74], %o3
F008B69C: 92100018                 mov     %i0, %o1
F008B6A0: 9fc2c000                 call    %o3
F008B6A4: 94100010                 mov     %l0, %o2
F008B6A8: 80a66000                 cmp     %i1, 0
F008B6AC: 02800005                 be      loc_F008B6C0
F008B6B0: a4100008                 mov     %o0, %l2
F008B6B4: d0044000                 ld      [%l1], %o0
F008B6B8: d0022034                 ld      [%o0+0x34], %o0
F008B6BC: d0264000                 st      %o0, [%i1]
F008B6C0: 7ffffd5a                 call    _vnode_pager_vput
F008B6C4: 90100013                 mov     %l3, %o0
F008B6C8: 81c7e008                 ret
F008B6CC: 91e80012                 restore %g0, %l2, %o0
