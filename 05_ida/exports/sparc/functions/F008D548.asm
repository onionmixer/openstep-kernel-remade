F008D548: 9de3bf80                 save    %sp, -0x80, %sp
F008D54C: 80a6a000                 cmp     %i2, 0
F008D550: 0280002b                 be      loc_F008D5FC
F008D554: 133c0506                 sethi   %hi(stru_F0141B4C.super_class), %o1
F008D558: f027bff0                 st      %i0, [%fp+var_10]
F008D55C: d4026350                 ld      [%o1+%lo(stru_F0141B4C.super_class)], %o2
F008D560: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008D564: 133c0504                 sethi   %hi(paInit), %o1
F008D568: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F008D56C: 40019104                 call    _objc_msgSendSuper
F008D570: d427bff4                 st      %o2, [%fp+var_C]
F008D574: d206c000                 ld      [%i3], %o1
F008D578: d227bfe0                 st      %o1, [%fp+var_20]
F008D57C: d006e004                 ld      [%i3+4], %o0
F008D580: d027bfe4                 st      %o0, [%fp+var_1C]
F008D584: 90824008                 addcc   %o1, %o0, %o0
F008D588: 02800004                 be      loc_F008D598
F008D58C: 80a20009                 cmp     %o0, %o1
F008D590: 08800003                 bleu    loc_F008D59C
F008D594: 90102000                 mov     0, %o0
F008D598: 90102001                 mov     1, %o0
F008D59C: 80a22000                 cmp     %o0, 0
F008D5A0: 02800017                 be      loc_F008D5FC
F008D5A4: 9007bfe8                 add     %fp, var_18, %o0
F008D5A8: d023a040                 st      %o0, [%sp+0x80+var_40]
F008D5AC: 113c0504                 sethi   %hi(paRange_0), %o0
F008D5B0: d2022058                 ld      [%o0+%lo(paRange_0)], %o1! SEL
F008D5B4: 9010001a                 mov     %i2, %o0! id
F008D5B8: 400190ae                 call    _objc_msgSend
F008D5BC: 01000000                 nop
F008D5C0: 00000008                 illtrap
F008D5C4: d207bfe8                 ld      [%fp+var_18], %o1
F008D5C8: d006c000                 ld      [%i3], %o0
F008D5CC: d407bfec                 ld      [%fp+var_14], %o2
F008D5D0: 96024008                 add     %o1, %o0, %o3
F008D5D4: 80a2c009                 cmp     %o3, %o1
F008D5D8: d006e004                 ld      [%i3+4], %o0
F008D5DC: 9202400a                 add     %o1, %o2, %o1
F008D5E0: 0a800007                 bcs     loc_F008D5FC
F008D5E4: 9002c008                 add     %o3, %o0, %o0
F008D5E8: 80a26000                 cmp     %o1, 0
F008D5EC: 0280000a                 be      loc_F008D614
F008D5F0: 80a20009                 cmp     %o0, %o1
F008D5F4: 28800009                 bleu,a  loc_F008D618
F008D5F8: f4262004                 st      %i2, [%i0+4]
F008D5FC: 113c0503                 sethi   %hi(paFree), %o0! id
F008D600: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008D604: 4001909b                 call    _objc_msgSend
F008D608: 90100018                 mov     %i0, %o0
F008D60C: 1080000a                 ba      locret_F008D634
F008D610: b0100008                 mov     %o0, %i0
F008D614: f4262004                 st      %i2, [%i0+4]
F008D618: d6262008                 st      %o3, [%i0+8]
F008D61C: 9010001a                 mov     %i2, %o0! id
F008D620: d406e004                 ld      [%i3+4], %o2
F008D624: 133c0504                 sethi   %hi(paAddmapping), %o1
F008D628: d202605c                 ld      [%o1+%lo(paAddmapping)], %o1! SEL
F008D62C: 40019091                 call    _objc_msgSend
F008D630: d426200c                 st      %o2, [%i0+0xC]
F008D634: 81c7e008                 ret
F008D638: 81e80000                 restore
