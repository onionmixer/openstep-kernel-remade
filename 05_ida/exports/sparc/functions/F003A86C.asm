F003A86C: 9de3bf50                 save    %sp, -0xB0, %sp
F003A870: d0062020                 ld      [%i0+0x20], %o0
F003A874: 80a22000                 cmp     %o0, 0
F003A878: 22800007                 be,a    loc_F003A894
F003A87C: 9010200d                 mov     0xD, %o0
F003A880: d04a0000                 ldsb    [%o0], %o0
F003A884: 80a22000                 cmp     %o0, 0
F003A888: 12800005                 bne     loc_F003A89C
F003A88C: 90100018                 mov     %i0, %o0
F003A890: 9010200d                 mov     0xD, %o0
F003A894: 10800032                 ba      locret_F003A95C
F003A898: d0264000                 st      %o0, [%i1]
F003A89C: 400005e1                 call    sub_F003C020
F003A8A0: 9210001a                 mov     %i2, %o1
F003A8A4: a0920000                 orcc    %o0, %g0, %l0
F003A8A8: 32800005                 bne,a   loc_F003A8BC
F003A8AC: d2062020                 ld      [%i0+0x20], %o1
F003A8B0: 90102046                 mov     0x46, %o0 ! 'F'
F003A8B4: 1080002a                 ba      locret_F003A95C
F003A8B8: d0264000                 st      %o0, [%i1]
F003A8BC: d604201c                 ld      [%l0+0x1C], %o3
F003A8C0: 313c04cf                 sethi   %hi(_active_u), %i0
F003A8C4: da0621d8                 ld      [%i0+%lo(_active_u)], %o5
F003A8C8: 90100010                 mov     %l0, %o0
F003A8CC: c402e020                 ld      [%o3+0x20], %g2
F003A8D0: 9407bfb4                 add     %fp, var_4C, %o2
F003A8D4: d603601c                 ld      [%o5+0x1C], %o3
F003A8D8: 98102000                 mov     0, %o4
F003A8DC: 9fc08000                 call    %g2
F003A8E0: 9a102000                 mov     0, %o5
F003A8E4: 80a22000                 cmp     %o0, 0
F003A8E8: 22800004                 be,a    loc_F003A8F8
F003A8EC: d00621d8                 ld      [%i0+%lo(_active_u)], %o0
F003A8F0: 10800013                 ba      loc_F003A93C
F003A8F4: c027bfb4                 clr     [%fp+var_4C]
F003A8F8: d402201c                 ld      [%o0+0x1C], %o2
F003A8FC: d007bfb4                 ld      [%fp+var_4C], %o0
F003A900: d602201c                 ld      [%o0+0x1C], %o3
F003A904: b007bfb8                 add     %fp, var_48, %i0
F003A908: d602e014                 ld      [%o3+0x14], %o3
F003A90C: 9fc2c000                 call    %o3
F003A910: 92100018                 mov     %i0, %o1
F003A914: 80a22000                 cmp     %o0, 0
F003A918: 1280000a                 bne     loc_F003A940
F003A91C: d207bfb4                 ld      [%fp+var_4C], %o1
F003A920: 90100018                 mov     %i0, %o0
F003A924: 7ffffca9                 call    _vattr_to_nattr
F003A928: 92066024                 add     %i1, 0x24, %o1 ! '$'
F003A92C: 90066004                 add     %i1, 4, %o0
F003A930: d207bfb4                 ld      [%fp+var_4C], %o1
F003A934: 7ffffe52                 call    _makefh
F003A938: 9410001a                 mov     %i2, %o2
F003A93C: d207bfb4                 ld      [%fp+var_4C], %o1
F003A940: 80a26000                 cmp     %o1, 0
F003A944: 02800004                 be      loc_F003A954
F003A948: d0264000                 st      %o0, [%i1]
F003A94C: 7fffb886                 call    _vn_rele
F003A950: 90100009                 mov     %o1, %o0
F003A954: 7fffb884                 call    _vn_rele
F003A958: 90100010                 mov     %l0, %o0
F003A95C: 81c7e008                 ret
F003A960: 81e80000                 restore
