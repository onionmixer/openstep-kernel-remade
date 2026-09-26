F005A55C: 9de3bf98                 save    %sp, -0x68, %sp
F005A560: e606202c                 ld      [%i0+0x2C], %l3
F005A564: 80a4e000                 cmp     %l3, 0
F005A568: 32800005                 bne,a   loc_F005A57C
F005A56C: d004e004                 ld      [%l3+4], %o0
F005A570: 113c04f0                 sethi   %hi(_ipc_table_dnrequests), %o0
F005A574: 10800003                 ba      loc_F005A580
F005A578: ea022028                 ld      [%o0+%lo(_ipc_table_dnrequests)], %l5
F005A57C: aa022004                 add     %o0, 4, %l5
F005A580: d0062004                 ld      [%i0+4], %o0
F005A584: 90022001                 inc     %o0
F005A588: d0262004                 st      %o0, [%i0+4]
F005A58C: c0260000                 clr     [%i0]
F005A590: d0054000                 ld      [%l5], %o0
F005A594: 80a22000                 cmp     %o0, 0
F005A598: 02800007                 be      loc_F005A5B4
F005A59C: 01000000                 nop
F005A5A0: 400011ca                 call    _ipc_table_alloc
F005A5A4: 912a2003                 sll     %o0, 3, %o0
F005A5A8: a4920000                 orcc    %o0, %g0, %l2
F005A5AC: 12800006                 bne     loc_F005A5C4
F005A5B0: 01000000                 nop
F005A5B4: 7ffffc2f                 call    _ipc_object_release
F005A5B8: 90100018                 mov     %i0, %o0
F005A5BC: 10800054                 ba      locret_F005A70C
F005A5C0: b0102006                 mov     6, %i0
F005A5C4: d0060000                 ld      [%i0], %o0
F005A5C8: 80a22000                 cmp     %o0, 0
F005A5CC: 12bffffe                 bne     loc_F005A5C4
F005A5D0: 01000000                 nop
F005A5D4: 4000f235                 call    _simple_lock_try
F005A5D8: 90100018                 mov     %i0, %o0
F005A5DC: 80a22000                 cmp     %o0, 0
F005A5E0: 02bffff9                 be      loc_F005A5C4
F005A5E4: 01000000                 nop
F005A5E8: d0062004                 ld      [%i0+4], %o0
F005A5EC: 90023fff                 inc     -1, %o0
F005A5F0: d0262004                 st      %o0, [%i0+4]
F005A5F4: d0062008                 ld      [%i0+8], %o0
F005A5F8: 80a22000                 cmp     %o0, 0
F005A5FC: 36800033                 bge,a   loc_F005A6C8
F005A600: d0062004                 ld      [%i0+4], %o0
F005A604: d006202c                 ld      [%i0+0x2C], %o0
F005A608: 80a20013                 cmp     %o0, %l3
F005A60C: 3280002f                 bne,a   loc_F005A6C8
F005A610: d0062004                 ld      [%i0+4], %o0
F005A614: 80a4e000                 cmp     %l3, 0
F005A618: 02800013                 be      loc_F005A664
F005A61C: a8102000                 mov     0, %l4
F005A620: d004e004                 ld      [%l3+4], %o0
F005A624: 90022004                 inc     4, %o0
F005A628: 80a20015                 cmp     %o0, %l5
F005A62C: 32800027                 bne,a   loc_F005A6C8
F005A630: d0062004                 ld      [%i0+4], %o0
F005A634: 80a4e000                 cmp     %l3, 0
F005A638: 0280000b                 be      loc_F005A664
F005A63C: 9004e008                 add     %l3, 8, %o0! void *
F005A640: e804e004                 ld      [%l3+4], %l4
F005A644: e2050000                 ld      [%l4], %l1
F005A648: 9204a008                 add     %l2, 8, %o1! void *
F005A64C: e004c000                 ld      [%l3], %l0
F005A650: 94047fff                 add     %l1, -1, %o2! size_t
F005A654: 4000e92f                 call    _bcopy
F005A658: 952aa003                 sll     %o2, 3, %o2
F005A65C: 10800005                 ba      loc_F005A670
F005A660: d6054000                 ld      [%l5], %o3
F005A664: a2102001                 mov     1, %l1
F005A668: a0102000                 mov     0, %l0
F005A66C: d6054000                 ld      [%l5], %o3
F005A670: 94100011                 mov     %l1, %o2
F005A674: 80a2800b                 cmp     %o2, %o3
F005A678: 3a80000c                 bcc,a   loc_F005A6A8
F005A67C: e0248000                 st      %l0, [%l2]
F005A680: 932aa003                 sll     %o2, 3, %o1
F005A684: 90048009                 add     %l2, %o1, %o0
F005A688: c0222004                 clr     [%o0+4]
F005A68C: e0248009                 st      %l0, [%l2+%o1]
F005A690: a010000a                 mov     %o2, %l0
F005A694: 94042001                 add     %l0, 1, %o2
F005A698: 80a2800b                 cmp     %o2, %o3
F005A69C: 0abffffa                 bcs     loc_F005A684
F005A6A0: 932aa003                 sll     %o2, 3, %o1
F005A6A4: e0248000                 st      %l0, [%l2]
F005A6A8: ea24a004                 st      %l5, [%l2+4]
F005A6AC: e426202c                 st      %l2, [%i0+0x2C]
F005A6B0: c0260000                 clr     [%i0]
F005A6B4: 80a4e000                 cmp     %l3, 0
F005A6B8: 02800014                 be      loc_F005A708
F005A6BC: 92100013                 mov     %l3, %o1
F005A6C0: 10800010                 ba      loc_F005A700
F005A6C4: d0050000                 ld      [%l4], %o0
F005A6C8: c0260000                 clr     [%i0]
F005A6CC: 80a22000                 cmp     %o0, 0
F005A6D0: 1280000a                 bne     loc_F005A6F8
F005A6D4: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F005A6D8: d0062008                 ld      [%i0+8], %o0
F005A6DC: 92126300                 bset    %lo(_ipc_object_zones), %o1
F005A6E0: 912a2001                 sll     %o0, 1, %o0
F005A6E4: 91322011                 srl     %o0, 17, %o0
F005A6E8: 912a2002                 sll     %o0, 2, %o0
F005A6EC: d0020009                 ld      [%o0+%o1], %o0
F005A6F0: 40007ab8                 call    _zfree
F005A6F4: 92100018                 mov     %i0, %o1
F005A6F8: d0054000                 ld      [%l5], %o0
F005A6FC: 92100012                 mov     %l2, %o1
F005A700: 40001194                 call    _ipc_table_free
F005A704: 912a2003                 sll     %o0, 3, %o0
F005A708: b0102000                 mov     0, %i0
F005A70C: 81c7e008                 ret
F005A710: 81e80000                 restore
