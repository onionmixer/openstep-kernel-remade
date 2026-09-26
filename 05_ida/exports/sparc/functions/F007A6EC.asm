F007A6EC: 9de3bf98                 save    %sp, -0x68, %sp
F007A6F0: f0060000                 ld      [%i0], %i0
F007A6F4: d00624ac                 ld      [%i0+0x4AC], %o0
F007A6F8: 80a20019                 cmp     %o0, %i1
F007A6FC: 22800002                 be,a    loc_F007A704
F007A700: c02624ac                 clr     [%i0+0x4AC]
F007A704: a0102000                 mov     0, %l0
F007A708: 92100018                 mov     %i0, %o1
F007A70C: d002618c                 ld      [%o1+0x18C], %o0
F007A710: 80a20019                 cmp     %o0, %i1
F007A714: 22800002                 be,a    loc_F007A71C
F007A718: c022618c                 clr     [%o1+0x18C]
F007A71C: a0042001                 inc     %l0
F007A720: 80a42031                 cmp     %l0, 0x31 ! '1'
F007A724: 04bffffa                 ble     loc_F007A70C
F007A728: 92026010                 inc     0x10, %o1
F007A72C: a0102000                 mov     0, %l0
F007A730: 92100018                 mov     %i0, %o1
F007A734: d002618c                 ld      [%o1+0x18C], %o0
F007A738: 80a22000                 cmp     %o0, 0
F007A73C: 02800007                 be      loc_F007A758
F007A740: 80a42032                 cmp     %l0, 0x32 ! '2'
F007A744: a0042001                 inc     %l0
F007A748: 80a42031                 cmp     %l0, 0x31 ! '1'
F007A74C: 04bffffa                 ble     loc_F007A734
F007A750: 92026010                 inc     0x10, %o1
F007A754: 80a42032                 cmp     %l0, 0x32 ! '2'
F007A758: 02800009                 be      loc_F007A77C
F007A75C: 90102006                 mov     6, %o0
F007A760: d0062008                 ld      [%i0+8], %o0
F007A764: d2062020                 ld      [%i0+0x20], %o1
F007A768: 4001e580                 call    _port_set_add_EXTERNAL
F007A76C: 94100019                 mov     %i1, %o2
F007A770: 80a22000                 cmp     %o0, 0
F007A774: 22800004                 be,a    loc_F007A784
F007A778: 912c2004                 sll     %l0, 4, %o0
F007A77C: 10800008                 ba      locret_F007A79C
F007A780: b0100008                 mov     %o0, %i0
F007A784: 90060008                 add     %i0, %o0, %o0
F007A788: f222218c                 st      %i1, [%o0+0x18C]
F007A78C: f4222190                 st      %i2, [%o0+0x190]
F007A790: f6222194                 st      %i3, [%o0+0x194]
F007A794: c0222198                 clr     [%o0+0x198]
F007A798: b0102000                 mov     0, %i0
F007A79C: 81c7e008                 ret
F007A7A0: 81e80000                 restore
