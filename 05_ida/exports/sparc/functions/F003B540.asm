F003B540: 9de3bf58                 save    %sp, -0xA8, %sp
F003B544: d0062020                 ld      [%i0+0x20], %o0
F003B548: 80a22000                 cmp     %o0, 0
F003B54C: 22800007                 be,a    loc_F003B568
F003B550: 9010200d                 mov     0xD, %o0
F003B554: d04a0000                 ldsb    [%o0], %o0
F003B558: 80a22000                 cmp     %o0, 0
F003B55C: 12800005                 bne     loc_F003B570
F003B560: 90062028                 add     %i0, 0x28, %o0 ! '('
F003B564: 9010200d                 mov     0xD, %o0
F003B568: 10800039                 ba      locret_F003B64C
F003B56C: d0264000                 st      %o0, [%i1]
F003B570: 40000297                 call    sub_F003BFCC
F003B574: 9207bfb8                 add     %fp, var_48, %o1
F003B578: 90102005                 mov     5, %o0
F003B57C: d027bfb8                 st      %o0, [%fp+var_48]
F003B580: 90100018                 mov     %i0, %o0
F003B584: 400002a7                 call    sub_F003C020
F003B588: 9210001a                 mov     %i2, %o1
F003B58C: a0920000                 orcc    %o0, %g0, %l0
F003B590: 32800005                 bne,a   loc_F003B5A4
F003B594: d0068000                 ld      [%i2], %o0
F003B598: 90102046                 mov     0x46, %o0 ! 'F'
F003B59C: 1080002c                 ba      locret_F003B64C
F003B5A0: d0264000                 st      %o0, [%i1]
F003B5A4: 808a2001                 btst    1, %o0
F003B5A8: 32800026                 bne,a   loc_F003B640
F003B5AC: b010201e                 mov     0x1E, %i0
F003B5B0: 808a2002                 btst    2, %o0
F003B5B4: 0280000a                 be      loc_F003B5DC
F003B5B8: 9206a018                 add     %i2, 0x18, %o1
F003B5BC: d006e01c                 ld      [%i3+0x1C], %o0
F003B5C0: 400002bf                 call    sub_F003C0BC
F003B5C4: 90022010                 inc     0x10, %o0
F003B5C8: 80a22000                 cmp     %o0, 0
F003B5CC: 32800005                 bne,a   loc_F003B5E0
F003B5D0: d2062020                 ld      [%i0+0x20], %o1
F003B5D4: 1080001b                 ba      loc_F003B640
F003B5D8: b010201e                 mov     0x1E, %i0
F003B5DC: d2062020                 ld      [%i0+0x20], %o1
F003B5E0: d404201c                 ld      [%l0+0x1C], %o2
F003B5E4: 113c04cf                 sethi   %hi(_active_u), %o0
F003B5E8: d80221d8                 ld      [%o0+%lo(_active_u)], %o4
F003B5EC: d6062024                 ld      [%i0+0x24], %o3
F003B5F0: da02a040                 ld      [%o2+0x40], %o5
F003B5F4: 90100010                 mov     %l0, %o0
F003B5F8: d803201c                 ld      [%o4+0x1C], %o4
F003B5FC: 9fc34000                 call    %o5
F003B600: 9407bfb8                 add     %fp, var_48, %o2
F003B604: b0100008                 mov     %o0, %i0
F003B608: 80a62011                 cmp     %i0, 0x11
F003B60C: 12800009                 bne     loc_F003B630
F003B610: 80a62000                 cmp     %i0, 0
F003B614: 40002737                 call    _svckudp_dup
F003B618: 9010001b                 mov     %i3, %o0
F003B61C: 80a22000                 cmp     %o0, 0
F003B620: 32800008                 bne,a   loc_F003B640
F003B624: b0102000                 mov     0, %i0
F003B628: 10800007                 ba      loc_F003B644
F003B62C: f0264000                 st      %i0, [%i1]
F003B630: 32800005                 bne,a   loc_F003B644
F003B634: f0264000                 st      %i0, [%i1]
F003B638: 400026f1                 call    _svckudp_dupsave
F003B63C: 9010001b                 mov     %i3, %o0
F003B640: f0264000                 st      %i0, [%i1]
F003B644: 7fffb548                 call    _vn_rele
F003B648: 90100010                 mov     %l0, %o0
F003B64C: 81c7e008                 ret
F003B650: 81e80000                 restore
