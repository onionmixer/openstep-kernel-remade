F007A7A4: 9de3bf98                 save    %sp, -0x68, %sp
F007A7A8: f0060000                 ld      [%i0], %i0
F007A7AC: d00624ac                 ld      [%i0+0x4AC], %o0
F007A7B0: 80a20019                 cmp     %o0, %i1
F007A7B4: 22800002                 be,a    loc_F007A7BC
F007A7B8: c02624ac                 clr     [%i0+0x4AC]
F007A7BC: a0102000                 mov     0, %l0
F007A7C0: 92100018                 mov     %i0, %o1
F007A7C4: d002618c                 ld      [%o1+0x18C], %o0
F007A7C8: 80a20019                 cmp     %o0, %i1
F007A7CC: 22800002                 be,a    loc_F007A7D4
F007A7D0: c022618c                 clr     [%o1+0x18C]
F007A7D4: a0042001                 inc     %l0
F007A7D8: 80a42031                 cmp     %l0, 0x31 ! '1'
F007A7DC: 04bffffa                 ble     loc_F007A7C4
F007A7E0: 92026010                 inc     0x10, %o1
F007A7E4: a0102000                 mov     0, %l0
F007A7E8: 92100018                 mov     %i0, %o1
F007A7EC: d002618c                 ld      [%o1+0x18C], %o0
F007A7F0: 80a22000                 cmp     %o0, 0
F007A7F4: 02800007                 be      loc_F007A810
F007A7F8: 80a42032                 cmp     %l0, 0x32 ! '2'
F007A7FC: a0042001                 inc     %l0
F007A800: 80a42031                 cmp     %l0, 0x31 ! '1'
F007A804: 04bffffa                 ble     loc_F007A7EC
F007A808: 92026010                 inc     0x10, %o1
F007A80C: 80a42032                 cmp     %l0, 0x32 ! '2'
F007A810: 02800009                 be      loc_F007A834
F007A814: 90102006                 mov     6, %o0
F007A818: d0062008                 ld      [%i0+8], %o0
F007A81C: d2062020                 ld      [%i0+0x20], %o1
F007A820: 4001e552                 call    _port_set_add_EXTERNAL
F007A824: 94100019                 mov     %i1, %o2
F007A828: 80a22000                 cmp     %o0, 0
F007A82C: 22800004                 be,a    loc_F007A83C
F007A830: 912c2004                 sll     %l0, 4, %o0
F007A834: 10800009                 ba      locret_F007A858
F007A838: b0100008                 mov     %o0, %i0
F007A83C: 90060008                 add     %i0, %o0, %o0
F007A840: f222218c                 st      %i1, [%o0+0x18C]
F007A844: f4222190                 st      %i2, [%o0+0x190]
F007A848: f6222194                 st      %i3, [%o0+0x194]
F007A84C: 92102001                 mov     1, %o1
F007A850: d2222198                 st      %o1, [%o0+0x198]
F007A854: b0102000                 mov     0, %i0
F007A858: 81c7e008                 ret
F007A85C: 81e80000                 restore
