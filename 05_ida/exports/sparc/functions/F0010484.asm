F0010484: 9de3bf98                 save    %sp, -0x68, %sp
F0010488: 90100018                 mov     %i0, %o0
F001048C: 92100019                 mov     %i1, %o1
F0010490: 400226da                 call    _md_prepare_for_shutdown
F0010494: 9410001a                 mov     %i2, %o2
F0010498: 808e6004                 btst    4, %i1
F001049C: 12800045                 bne     loc_F00105B0
F00104A0: 90100018                 mov     %i0, %o0
F00104A4: 153c042c                 sethi   %hi(_waittime), %o2
F00104A8: d002a1d0                 ld      [%o2+%lo(_waittime)], %o0
F00104AC: 80a22000                 cmp     %o0, 0
F00104B0: 16800040                 bge     loc_F00105B0
F00104B4: 90100018                 mov     %i0, %o0
F00104B8: 113c04cf                 sethi   %hi(dword_F0133DE4), %o0
F00104BC: d00221e4                 ld      [%o0+%lo(dword_F0133DE4)], %o0
F00104C0: 80a22000                 cmp     %o0, 0
F00104C4: 0280003a                 be      loc_F00105AC
F00104C8: 133c04d2                 sethi   %hi(_acctp), %o1
F00104CC: d0026218                 ld      [%o1+%lo(_acctp)], %o0
F00104D0: 80a22000                 cmp     %o0, 0
F00104D4: 02800004                 be      loc_F00104E4
F00104D8: c022a1d0                 clr     [%o2+%lo(_waittime)]
F00104DC: 400061a2                 call    _vn_rele
F00104E0: c0226218                 clr     [%o1+%lo(_acctp)]
F00104E4: 40004d4d                 call    _sync
F00104E8: a4102000                 mov     0, %l2
F00104EC: 4000003a                 call    _unmount_all
F00104F0: a2102000                 mov     0, %l1
F00104F4: 40006593                 call    _if_down_all
F00104F8: 2b3c04cf                 sethi   -0xFECC400, %l5
F00104FC: 293c0470                 sethi   %hi(_nbuf), %l4
F0010500: 273c042c                 sethi   -0xFEF5000, %l3
F0010504: d0052058                 ld      [%l4+%lo(_nbuf)], %o0
F0010508: 932a2004                 sll     %o0, 4, %o1
F001050C: 92024008                 add     %o1, %o0, %o1
F0010510: d00562f0                 ld      [%l5+0x2F0], %o0
F0010514: 932a6002                 sll     %o1, 2, %o1
F0010518: 92020009                 add     %o0, %o1, %o1
F001051C: 92027fbc                 inc     -0x44, %o1
F0010520: 80a24008                 cmp     %o1, %o0
F0010524: 0a80000d                 bcs     loc_F0010558
F0010528: a0102000                 mov     0, %l0
F001052C: 113c04cf                 sethi   %hi(_buf), %o0
F0010530: d40222f0                 ld      [%o0+%lo(_buf)], %o2
F0010534: d0024000                 ld      [%o1], %o0
F0010538: 900a200a                 and     %o0, 0xA, %o0
F001053C: 80a22008                 cmp     %o0, 8
F0010540: 22800002                 be,a    loc_F0010548
F0010544: a0042001                 inc     %l0
F0010548: 92027fbc                 inc     -0x44, %o1
F001054C: 80a2400a                 cmp     %o1, %o2
F0010550: 3abffffa                 bcc,a   loc_F0010538
F0010554: d0024000                 ld      [%o1], %o0
F0010558: 80a42000                 cmp     %l0, 0
F001055C: 02800014                 be      loc_F00105AC
F0010560: 9014e1d8                 or      %l3, 0x1D8, %o0! char *
F0010564: 4000103d                 call    _printf
F0010568: 92100010                 mov     %l0, %o1
F001056C: 80a40012                 cmp     %l0, %l2
F0010570: 32800002                 bne,a   loc_F0010578
F0010574: a2102000                 mov     0, %l1
F0010578: a4100010                 mov     %l0, %l2
F001057C: 912c6002                 sll     %l1, 2, %o0
F0010580: 90020011                 add     %o0, %l1, %o0
F0010584: 912a2003                 sll     %o0, 3, %o0
F0010588: 90220011                 sub     %o0, %l1, %o0
F001058C: 912a2004                 sll     %o0, 4, %o0
F0010590: 90020011                 add     %o0, %l1, %o0
F0010594: 40021cb3                 call    _us_spin
F0010598: 912a2006                 sll     %o0, 6, %o0
F001059C: a2046001                 inc     %l1
F00105A0: 80a46013                 cmp     %l1, 0x13
F00105A4: 04bfffd9                 ble     loc_F0010508
F00105A8: d0052058                 ld      [%l4+0x58], %o0
F00105AC: 90100018                 mov     %i0, %o0
F00105B0: 92100019                 mov     %i1, %o1
F00105B4: 4002269a                 call    _md_shutdown_devices
F00105B8: 9410001a                 mov     %i2, %o2
F00105BC: 90100018                 mov     %i0, %o0
F00105C0: 92100019                 mov     %i1, %o1
F00105C4: 400226a0                 call    _md_do_shutdown
F00105C8: 9410001a                 mov     %i2, %o2
F00105CC: 81c7e008                 ret
F00105D0: 81e80000                 restore
