F00DE524: 9de3bf98                 save    %sp, -0x68, %sp
F00DE528: 80a62000                 cmp     %i0, 0
F00DE52C: 12800004                 bne     loc_F00DE53C
F00DE530: 94100019                 mov     %i1, %o2
F00DE534: 10800057                 ba      locret_F00DE690
F00DE538: b01020ca                 mov     0xCA, %i0
F00DE53C: 133c0505                 sethi   %hi(paCheckowner), %o1
F00DE540: d2026018                 ld      [%o1+%lo(paCheckowner)], %o1! SEL
F00DE544: 40004ccb                 call    _objc_msgSend
F00DE548: 90100018                 mov     %i0, %o0
F00DE54C: 912a2018                 sll     %o0, 24, %o0
F00DE550: 80a22000                 cmp     %o0, 0
F00DE554: 12800004                 bne     loc_F00DE564
F00DE558: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DE55C: 1080004d                 ba      locret_F00DE690
F00DE560: b01020c8                 mov     0xC8, %i0
F00DE564: d2022224                 ld      [%o0+0x224], %o1! SEL
F00DE568: 40004cc2                 call    _objc_msgSend
F00DE56C: 90100018                 mov     %i0, %o0
F00DE570: 808ea001                 btst    1, %i2
F00DE574: 02800007                 be      loc_F00DE590
F00DE578: b2100008                 mov     %o0, %i1
F00DE57C: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE580: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1
F00DE584: 94102005                 mov     5, %o2
F00DE588: 10800007                 ba      loc_F00DE5A4
F00DE58C: 96102001                 mov     1, %o3
F00DE590: 90100019                 mov     %i1, %o0! id
F00DE594: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE598: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1! SEL
F00DE59C: 94102005                 mov     5, %o2
F00DE5A0: 96102000                 mov     0, %o3
F00DE5A4: 40004cb3                 call    _objc_msgSend
F00DE5A8: 98100018                 mov     %i0, %o4
F00DE5AC: 808ea002                 btst    2, %i2
F00DE5B0: 02800007                 be      loc_F00DE5CC
F00DE5B4: 90100019                 mov     %i1, %o0! id
F00DE5B8: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE5BC: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1
F00DE5C0: 94102003                 mov     3, %o2
F00DE5C4: 10800006                 ba      loc_F00DE5DC
F00DE5C8: 96102001                 mov     1, %o3
F00DE5CC: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE5D0: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1! SEL
F00DE5D4: 94102003                 mov     3, %o2
F00DE5D8: 96102000                 mov     0, %o3
F00DE5DC: 40004ca5                 call    _objc_msgSend
F00DE5E0: 98100018                 mov     %i0, %o4
F00DE5E4: 808ea004                 btst    4, %i2
F00DE5E8: 02800007                 be      loc_F00DE604
F00DE5EC: 90100019                 mov     %i1, %o0! id
F00DE5F0: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE5F4: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1
F00DE5F8: 94102004                 mov     4, %o2
F00DE5FC: 10800006                 ba      loc_F00DE614
F00DE600: 96102001                 mov     1, %o3
F00DE604: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE608: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1! SEL
F00DE60C: 94102004                 mov     4, %o2
F00DE610: 96102000                 mov     0, %o3
F00DE614: 40004c97                 call    _objc_msgSend
F00DE618: 98100018                 mov     %i0, %o4
F00DE61C: 808ea008                 btst    8, %i2
F00DE620: 02800007                 be      loc_F00DE63C
F00DE624: 90100019                 mov     %i1, %o0! id
F00DE628: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE62C: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1
F00DE630: 94102006                 mov     6, %o2
F00DE634: 10800006                 ba      loc_F00DE64C
F00DE638: 96102001                 mov     1, %o3
F00DE63C: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE640: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1! SEL
F00DE644: 94102006                 mov     6, %o2
F00DE648: 96102000                 mov     0, %o3
F00DE64C: 40004c89                 call    _objc_msgSend
F00DE650: 98100018                 mov     %i0, %o4
F00DE654: 808ea010                 btst    0x10, %i2
F00DE658: 02800007                 be      loc_F00DE674
F00DE65C: 90100019                 mov     %i1, %o0! id
F00DE660: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE664: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1
F00DE668: 94102007                 mov     7, %o2
F00DE66C: 10800006                 ba      loc_F00DE684
F00DE670: 96102000                 mov     0, %o3
F00DE674: 133c0505                 sethi   %hi(paSetparameterTo), %o1
F00DE678: d20260fc                 ld      [%o1+%lo(paSetparameterTo)], %o1! SEL
F00DE67C: 94102007                 mov     7, %o2
F00DE680: 96102001                 mov     1, %o3
F00DE684: 40004c7b                 call    _objc_msgSend
F00DE688: 98100018                 mov     %i0, %o4
F00DE68C: b0102000                 mov     0, %i0
F00DE690: 81c7e008                 ret
F00DE694: 81e80000                 restore
