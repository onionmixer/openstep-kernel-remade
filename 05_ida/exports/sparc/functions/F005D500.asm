F005D500: 9de3bf98                 save    %sp, -0x68, %sp
F005D504: 94100019                 mov     %i1, %o2
F005D508: 80a6e011                 cmp     %i3, 0x11
F005D50C: 02800012                 be      loc_F005D554
F005D510: e0068000                 ld      [%i2], %l0
F005D514: 80a6e011                 cmp     %i3, 0x11
F005D518: 18800006                 bgu     loc_F005D530
F005D51C: 80a6e010                 cmp     %i3, 0x10
F005D520: 2280003d                 be,a    loc_F005D614
F005D524: d4276010                 st      %o2, [%i5+0x10]
F005D528: 10800054                 ba      loc_F005D678
F005D52C: 113c043d                 sethi   -0xFEF0C00, %o0
F005D530: 80a6e012                 cmp     %i3, 0x12
F005D534: 12800051                 bne     loc_F005D678
F005D538: 113c043d                 sethi   -0xFEF0C00, %o0
F005D53C: c0274000                 clr     [%i5]
F005D540: 1100010090122001         set     0x40001, %o0
F005D548: 90140008                 bset    %l0, %o0
F005D54C: 1080004d                 ba      loc_F005D680
F005D550: d0268000                 st      %o0, [%i2]
F005D554: 11000040                 sethi   0x10000, %o0
F005D558: 808c0008                 btst    %o0, %l0
F005D55C: 0280001a                 be      loc_F005D5C4
F005D560: 1300003f                 sethi   0xFC00, %o1
F005D564: 921263ff                 bset    0x3FF, %o1
F005D568: 900c0009                 and     %l0, %o1, %o0
F005D56C: 90022001                 inc     %o0
F005D570: 80a20009                 cmp     %o0, %o1
F005D574: 32800011                 bne,a   loc_F005D5B8
F005D578: d007601c                 ld      [%i5+0x1C], %o0
F005D57C: 80a72000                 cmp     %i4, 0
F005D580: 0280000b                 be      loc_F005D5AC
F005D584: 01000000                 nop
F005D588: d007601c                 ld      [%i5+0x1C], %o0
F005D58C: 90023fff                 inc     -1, %o0
F005D590: d027601c                 st      %o0, [%i5+0x1C]
F005D594: d0076004                 ld      [%i5+4], %o0
F005D598: 90023fff                 inc     -1, %o0
F005D59C: d0276004                 st      %o0, [%i5+4]
F005D5A0: c0274000                 clr     [%i5]
F005D5A4: 10800038                 ba      locret_F005D684
F005D5A8: b0102000                 mov     0, %i0
F005D5AC: c0274000                 clr     [%i5]
F005D5B0: 10800035                 ba      locret_F005D684
F005D5B4: b0102013                 mov     0x13, %i0
F005D5B8: 90023fff                 inc     -1, %o0
F005D5BC: 10800006                 ba      loc_F005D5D4
F005D5C0: d027601c                 st      %o0, [%i5+0x1C]
F005D5C4: 11000080                 sethi   0x20000, %o0
F005D5C8: 808c0008                 btst    %o0, %l0
F005D5CC: 02800008                 be      loc_F005D5EC
F005D5D0: 01000000                 nop
F005D5D4: d0076004                 ld      [%i5+4], %o0
F005D5D8: 90023fff                 inc     -1, %o0
F005D5DC: d0276004                 st      %o0, [%i5+4]
F005D5E0: c0274000                 clr     [%i5]
F005D5E4: 10800008                 ba      loc_F005D604
F005D5E8: 11000040                 sethi   0x10000, %o0
F005D5EC: c0274000                 clr     [%i5]
F005D5F0: 90100018                 mov     %i0, %o0
F005D5F4: 9210001d                 mov     %i5, %o1
F005D5F8: 7fffdbd9                 call    _ipc_hash_insert
F005D5FC: 9610001a                 mov     %i2, %o3
F005D600: 11000040                 sethi   0x10000, %o0
F005D604: 90140008                 bset    %l0, %o0
F005D608: 90022001                 inc     %o0
F005D60C: 1080001d                 ba      loc_F005D680
F005D610: d0268000                 st      %o0, [%i2]
F005D614: f207600c                 ld      [%i5+0xC], %i1
F005D618: 11000040                 sethi   0x10000, %o0
F005D61C: 808c0008                 btst    %o0, %l0
F005D620: 0280000c                 be      loc_F005D650
F005D624: f027600c                 st      %i0, [%i5+0xC]
F005D628: d0076004                 ld      [%i5+4], %o0
F005D62C: 90023fff                 inc     -1, %o0
F005D630: d0276004                 st      %o0, [%i5+4]
F005D634: c0274000                 clr     [%i5]
F005D638: 90100018                 mov     %i0, %o0
F005D63C: 9210001d                 mov     %i5, %o1
F005D640: 7fffdbdc                 call    _ipc_hash_delete
F005D644: 9610001a                 mov     %i2, %o3
F005D648: 10800004                 ba      loc_F005D658
F005D64C: 11000080                 sethi   0x20000, %o0
F005D650: c0274000                 clr     [%i5]
F005D654: 11000080                 sethi   0x20000, %o0
F005D658: 90140008                 bset    %l0, %o0
F005D65C: 80a66000                 cmp     %i1, 0
F005D660: 02800008                 be      loc_F005D680
F005D664: d0268000                 st      %o0, [%i2]
F005D668: 7ffff002                 call    _ipc_object_release
F005D66C: 90100019                 mov     %i1, %o0! char *
F005D670: 10800005                 ba      locret_F005D684
F005D674: b0102000                 mov     0, %i0
F005D678: 7ffedebe                 call    _panic
F005D67C: 90122348                 bset    0x348, %o0
F005D680: b0102000                 mov     0, %i0
F005D684: 81c7e008                 ret
F005D688: 81e80000                 restore
