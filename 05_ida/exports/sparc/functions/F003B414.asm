F003B414: 9de3bf98                 save    %sp, -0x68, %sp
F003B418: d0062040                 ld      [%i0+0x40], %o0
F003B41C: 80a22000                 cmp     %o0, 0
F003B420: 22800007                 be,a    loc_F003B43C
F003B424: 9010200d                 mov     0xD, %o0
F003B428: d04a0000                 ldsb    [%o0], %o0
F003B42C: 80a22000                 cmp     %o0, 0
F003B430: 12800005                 bne     loc_F003B444
F003B434: 90100018                 mov     %i0, %o0
F003B438: 9010200d                 mov     0xD, %o0
F003B43C: 1080003f                 ba      locret_F003B538
F003B440: d0264000                 st      %o0, [%i1]
F003B444: 400002f7                 call    sub_F003C020
F003B448: 9210001a                 mov     %i2, %o1
F003B44C: a2920000                 orcc    %o0, %g0, %l1
F003B450: 12800005                 bne     loc_F003B464
F003B454: 90062020                 add     %i0, 0x20, %o0 ! ' '
F003B458: 90102046                 mov     0x46, %o0 ! 'F'
F003B45C: 10800037                 ba      locret_F003B538
F003B460: d0264000                 st      %o0, [%i1]
F003B464: 400002ef                 call    sub_F003C020
F003B468: 9210001a                 mov     %i2, %o1
F003B46C: a0920000                 orcc    %o0, %g0, %l0
F003B470: 32800006                 bne,a   loc_F003B488
F003B474: d0068000                 ld      [%i2], %o0
F003B478: 90102046                 mov     0x46, %o0 ! 'F'
F003B47C: d0264000                 st      %o0, [%i1]
F003B480: 1080002c                 ba      loc_F003B530
F003B484: 90100011                 mov     %l1, %o0
F003B488: 808a2001                 btst    1, %o0
F003B48C: 32800025                 bne,a   loc_F003B520
F003B490: b010201e                 mov     0x1E, %i0
F003B494: 808a2002                 btst    2, %o0
F003B498: 2280000b                 be,a    loc_F003B4C4
F003B49C: d204201c                 ld      [%l0+0x1C], %o1
F003B4A0: d006e01c                 ld      [%i3+0x1C], %o0
F003B4A4: 9206a018                 add     %i2, 0x18, %o1
F003B4A8: 40000305                 call    sub_F003C0BC
F003B4AC: 90022010                 inc     0x10, %o0
F003B4B0: 80a22000                 cmp     %o0, 0
F003B4B4: 32800004                 bne,a   loc_F003B4C4
F003B4B8: d204201c                 ld      [%l0+0x1C], %o1
F003B4BC: 10800019                 ba      loc_F003B520
F003B4C0: b010201e                 mov     0x1E, %i0
F003B4C4: 113c04cf                 sethi   %hi(_active_u), %o0
F003B4C8: d60221d8                 ld      [%o0+%lo(_active_u)], %o3
F003B4CC: d4062040                 ld      [%i0+0x40], %o2
F003B4D0: d802602c                 ld      [%o1+0x2C], %o4
F003B4D4: 90100011                 mov     %l1, %o0
F003B4D8: d602e01c                 ld      [%o3+0x1C], %o3
F003B4DC: 9fc30000                 call    %o4
F003B4E0: 92100010                 mov     %l0, %o1
F003B4E4: b0100008                 mov     %o0, %i0
F003B4E8: 80a62011                 cmp     %i0, 0x11
F003B4EC: 12800009                 bne     loc_F003B510
F003B4F0: 80a62000                 cmp     %i0, 0
F003B4F4: 4000277f                 call    _svckudp_dup
F003B4F8: 9010001b                 mov     %i3, %o0
F003B4FC: 80a22000                 cmp     %o0, 0
F003B500: 32800008                 bne,a   loc_F003B520
F003B504: b0102000                 mov     0, %i0
F003B508: 10800007                 ba      loc_F003B524
F003B50C: f0264000                 st      %i0, [%i1]
F003B510: 32800005                 bne,a   loc_F003B524
F003B514: f0264000                 st      %i0, [%i1]
F003B518: 40002739                 call    _svckudp_dupsave
F003B51C: 9010001b                 mov     %i3, %o0
F003B520: f0264000                 st      %i0, [%i1]
F003B524: 7fffb590                 call    _vn_rele
F003B528: 90100011                 mov     %l1, %o0
F003B52C: 90100010                 mov     %l0, %o0
F003B530: 7fffb58d                 call    _vn_rele
F003B534: 01000000                 nop
F003B538: 81c7e008                 ret
F003B53C: 81e80000                 restore
