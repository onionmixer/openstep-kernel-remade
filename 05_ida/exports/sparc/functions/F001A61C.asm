F001A61C: 9de3bf98                 save    %sp, -0x68, %sp
F001A620: e407a05c                 ld      [%fp+arg_5C], %l2
F001A624: e607a060                 ld      [%fp+arg_60], %l3
F001A628: e807a064                 ld      [%fp+arg_64], %l4
F001A62C: ea07a068                 ld      [%fp+arg_68], %l5
F001A630: ec07a06c                 ld      [%fp+arg_6C], %l6
F001A634: 80a62000                 cmp     %i0, 0
F001A638: 06800037                 bl      loc_F001A714
F001A63C: ee07a070                 ld      [%fp+arg_70], %l7
F001A640: 113c042e                 sethi   %hi(_nldisp), %o0
F001A644: d00222ac                 ld      [%o0+%lo(_nldisp)], %o0
F001A648: 80a60008                 cmp     %i0, %o0
F001A64C: 36800043                 bge,a   locret_F001A758
F001A650: b0103fff                 mov     -1, %i0
F001A654: 912e2001                 sll     %i0, 1, %o0
F001A658: 90020018                 add     %o0, %i0, %o0
F001A65C: a12a2004                 sll     %o0, 4, %l0
F001A660: 113c042ea21220cc         set     _linesw, %l1
F001A668: d2040011                 ld      [%l0+%l1], %o1
F001A66C: 113c005590122040         set     _nodev, %o0
F001A674: 80a24008                 cmp     %o1, %o0
F001A678: 12800038                 bne     locret_F001A758
F001A67C: b0103fff                 mov     -1, %i0
F001A680: b0040011                 add     %l0, %l1, %i0
F001A684: d0062004                 ld      [%i0+4], %o0
F001A688: 80a20009                 cmp     %o0, %o1
F001A68C: 32800033                 bne,a   locret_F001A758
F001A690: b0103fff                 mov     -1, %i0
F001A694: d2062008                 ld      [%i0+8], %o1
F001A698: 80a24008                 cmp     %o1, %o0
F001A69C: 3280002f                 bne,a   locret_F001A758
F001A6A0: b0103fff                 mov     -1, %i0
F001A6A4: d006200c                 ld      [%i0+0xC], %o0
F001A6A8: 80a20009                 cmp     %o0, %o1
F001A6AC: 3280002b                 bne,a   locret_F001A758
F001A6B0: b0103fff                 mov     -1, %i0
F001A6B4: d2062010                 ld      [%i0+0x10], %o1
F001A6B8: 80a24008                 cmp     %o1, %o0
F001A6BC: 32800027                 bne,a   locret_F001A758
F001A6C0: b0103fff                 mov     -1, %i0
F001A6C4: d0062014                 ld      [%i0+0x14], %o0
F001A6C8: 80a20009                 cmp     %o0, %o1
F001A6CC: 32800023                 bne,a   locret_F001A758
F001A6D0: b0103fff                 mov     -1, %i0
F001A6D4: d2062018                 ld      [%i0+0x18], %o1
F001A6D8: 80a24008                 cmp     %o1, %o0
F001A6DC: 3280001f                 bne,a   locret_F001A758
F001A6E0: b0103fff                 mov     -1, %i0
F001A6E4: d0062020                 ld      [%i0+0x20], %o0
F001A6E8: 80a20009                 cmp     %o0, %o1
F001A6EC: 3280001b                 bne,a   locret_F001A758
F001A6F0: b0103fff                 mov     -1, %i0
F001A6F4: d2062024                 ld      [%i0+0x24], %o1
F001A6F8: 80a24008                 cmp     %o1, %o0
F001A6FC: 32800017                 bne,a   locret_F001A758
F001A700: b0103fff                 mov     -1, %i0
F001A704: d0062028                 ld      [%i0+0x28], %o0
F001A708: 80a20009                 cmp     %o0, %o1
F001A70C: 02800004                 be      loc_F001A71C
F001A710: 01000000                 nop
F001A714: 10800011                 ba      locret_F001A758
F001A718: b0103fff                 mov     -1, %i0
F001A71C: 4001f127                 call    _spltty
F001A720: 01000000                 nop
F001A724: f226202c                 st      %i1, [%i0+0x2C]
F001A728: f4240011                 st      %i2, [%l0+%l1]
F001A72C: f6262004                 st      %i3, [%i0+4]
F001A730: f8262008                 st      %i4, [%i0+8]
F001A734: fa26200c                 st      %i5, [%i0+0xC]
F001A738: e4262010                 st      %l2, [%i0+0x10]
F001A73C: e6262014                 st      %l3, [%i0+0x14]
F001A740: e8262018                 st      %l4, [%i0+0x18]
F001A744: ea262020                 st      %l5, [%i0+0x20]
F001A748: ec262024                 st      %l6, [%i0+0x24]
F001A74C: 4001f176                 call    _splx
F001A750: ee262028                 st      %l7, [%i0+0x28]
F001A754: b0102000                 mov     0, %i0
F001A758: 81c7e008                 ret
F001A75C: 81e80000                 restore
