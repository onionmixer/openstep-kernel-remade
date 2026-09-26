F004947C: 9de3bf90                 save    %sp, -0x70, %sp
F0049480: e4062050                 ld      [%i0+0x50], %l2
F0049484: d004a070                 ld      [%l2+0x70], %o0
F0049488: d204a06c                 ld      [%l2+0x6C], %o1
F004948C: 9610001c                 mov     %i4, %o3
F0049490: f804a054                 ld      [%l2+0x54], %i4
F0049494: 913e4008                 sra     %i1, %o0, %o0
F0049498: 912a2002                 sll     %o0, 2, %o0
F004949C: 90020012                 add     %o0, %l2, %o0
F00494A0: 922e4009                 andn    %i1, %o1, %o1
F00494A4: d40222d8                 ld      [%o0+0x2D8], %o2
F00494A8: 932a6004                 sll     %o1, 4, %o1
F00494AC: 94028009                 add     %o2, %o1, %o2
F00494B0: 9022c01b                 sub     %o3, %i3, %o0
F00494B4: d202a00c                 ld      [%o2+0xC], %o1
F00494B8: 913a001c                 sra     %o0, %i4, %o0
F00494BC: 80a24008                 cmp     %o1, %o0
F00494C0: 0680002b                 bl      loc_F004956C
F00494C4: b93ac01c                 sra     %o3, %i4, %i4
F00494C8: d204a038                 ld      [%l2+0x38], %o1
F00494CC: 9006801c                 add     %i2, %i4, %o0
F00494D0: 90023fff                 inc     -1, %o0
F00494D4: 92027fff                 inc     -1, %o1
F00494D8: a60e8009                 and     %i2, %o1, %l3
F00494DC: 900a0009                 and     %o0, %o1, %o0
F00494E0: 80a4c008                 cmp     %l3, %o0
F00494E4: 34800097                 bg,a    locret_F0049740
F00494E8: b0102000                 mov     0, %i0
F00494EC: d004a0bc                 ld      [%l2+0xBC], %o0
F00494F0: e2062040                 ld      [%i0+0x40], %l1
F00494F4: 7ffef403                 call    _umul
F00494F8: 92100019                 mov     %i1, %o1
F00494FC: d404a018                 ld      [%l2+0x18], %o2
F0049500: a0100008                 mov     %o0, %l0
F0049504: d204a01c                 ld      [%l2+0x1C], %o1
F0049508: 9010000a                 mov     %o2, %o0
F004950C: 7ffef3fd                 call    _umul
F0049510: 922e4009                 andn    %i1, %o1, %o1
F0049514: 92100008                 mov     %o0, %o1
F0049518: 90100011                 mov     %l1, %o0
F004951C: d404a00c                 ld      [%l2+0xC], %o2
F0049520: a0040009                 add     %l0, %o1, %l0
F0049524: d204a064                 ld      [%l2+0x64], %o1
F0049528: a004000a                 add     %l0, %o2, %l0
F004952C: d404a0a0                 ld      [%l2+0xA0], %o2
F0049530: 7fff6bfc                 call    _bread
F0049534: 932c0009                 sll     %l0, %o1, %o1
F0049538: a2100008                 mov     %o0, %l1
F004953C: d0044000                 ld      [%l1], %o0
F0049540: 808a2004                 btst    4, %o0
F0049544: 12800008                 bne     loc_F0049564
F0049548: e0046020                 ld      [%l1+0x20], %l0
F004954C: d20423d4                 ld      [%l0+0x3D4], %o1
F0049550: 1100024090122255         set     0x90255, %o0
F0049558: 80a24008                 cmp     %o1, %o0
F004955C: 02800006                 be      loc_F0049574
F0049560: 01000000                 nop
F0049564: 7fff6cc1                 call    _brelse
F0049568: 90100011                 mov     %l1, %o0
F004956C: 10800075                 ba      locret_F0049740
F0049570: b0102000                 mov     0, %i0
F0049574: 7fff2686                 call    _getthetime
F0049578: 9007bff0                 add     %fp, var_10, %o0
F004957C: d007bff0                 ld      [%fp+var_10], %o0
F0049580: d0242008                 st      %o0, [%l0+8]
F0049584: d204a0bc                 ld      [%l2+0xBC], %o1
F0049588: 7ffef4c8                 call    _rem
F004958C: 9010001a                 mov     %i2, %o0
F0049590: d204a054                 ld      [%l2+0x54], %o1
F0049594: 973ec009                 sra     %i3, %o1, %o3
F0049598: 80a2c01c                 cmp     %o3, %i4
F004959C: 16800013                 bge     loc_F00495E8
F00495A0: 9a100008                 mov     %o0, %o5
F00495A4: 9403400b                 add     %o5, %o3, %o2
F00495A8: 80a2a000                 cmp     %o2, 0
F00495AC: 16800003                 bge     loc_F00495B8
F00495B0: 9010000a                 mov     %o2, %o0
F00495B4: 9002a007                 add     %o2, 7, %o0
F00495B8: 913a2003                 sra     %o0, 3, %o0
F00495BC: 92020010                 add     %o0, %l0, %o1
F00495C0: d24a63d8                 ldsb    [%o1+0x3D8], %o1
F00495C4: 912a2003                 sll     %o0, 3, %o0
F00495C8: 90228008                 sub     %o2, %o0, %o0
F00495CC: 933a4008                 sra     %o1, %o0, %o1
F00495D0: 808a6001                 btst    1, %o1
F00495D4: 02bfffe4                 be      loc_F0049564
F00495D8: 9602e001                 inc     %o3
F00495DC: 80a2c01c                 cmp     %o3, %i4
F00495E0: 06bffff2                 bl      loc_F00495A8
F00495E4: 9403400b                 add     %o5, %o3, %o2
F00495E8: d004a038                 ld      [%l2+0x38], %o0
F00495EC: 90220013                 sub     %o0, %l3, %o0
F00495F0: 80a70008                 cmp     %i4, %o0
F00495F4: 16800015                 bge     loc_F0049648
F00495F8: 9610001c                 mov     %i4, %o3
F00495FC: 98100008                 mov     %o0, %o4
F0049600: 9403400b                 add     %o5, %o3, %o2
F0049604: 80a2a000                 cmp     %o2, 0
F0049608: 16800003                 bge     loc_F0049614
F004960C: 9010000a                 mov     %o2, %o0
F0049610: 9002a007                 add     %o2, 7, %o0
F0049614: 913a2003                 sra     %o0, 3, %o0
F0049618: 92020010                 add     %o0, %l0, %o1
F004961C: d24a63d8                 ldsb    [%o1+0x3D8], %o1
F0049620: 912a2003                 sll     %o0, 3, %o0
F0049624: 90228008                 sub     %o2, %o0, %o0
F0049628: 933a4008                 sra     %o1, %o0, %o1
F004962C: 808a6001                 btst    1, %o1
F0049630: 22800007                 be,a    loc_F004964C
F0049634: d004a054                 ld      [%l2+0x54], %o0
F0049638: 9602e001                 inc     %o3
F004963C: 80a2c00c                 cmp     %o3, %o4
F0049640: 06bffff1                 bl      loc_F0049604
F0049644: 9403400b                 add     %o5, %o3, %o2
F0049648: d004a054                 ld      [%l2+0x54], %o0
F004964C: 913ec008                 sra     %i3, %o0, %o0
F0049650: 9022c008                 sub     %o3, %o0, %o0
F0049654: 912a2002                 sll     %o0, 2, %o0
F0049658: 90020010                 add     %o0, %l0, %o0
F004965C: d2022034                 ld      [%o0+0x34], %o1
F0049660: 80a2c01c                 cmp     %o3, %i4
F0049664: 92027fff                 inc     -1, %o1
F0049668: 02800008                 be      loc_F0049688
F004966C: d2222034                 st      %o1, [%o0+0x34]
F0049670: 9222c01c                 sub     %o3, %i4, %o1
F0049674: 932a6002                 sll     %o1, 2, %o1
F0049678: 92024010                 add     %o1, %l0, %o1
F004967C: d0026034                 ld      [%o1+0x34], %o0
F0049680: 90022001                 inc     %o0
F0049684: d0226034                 st      %o0, [%o1+0x34]
F0049688: d004a054                 ld      [%l2+0x54], %o0
F004968C: 973ec008                 sra     %i3, %o0, %o3
F0049690: 80a2c01c                 cmp     %o3, %i4
F0049694: 36800026                 bge,a   loc_F004972C
F0049698: d20ca0d0                 ldub    [%l2+0xD0], %o1
F004969C: 98102001                 mov     1, %o4
F00496A0: 9203400b                 add     %o5, %o3, %o1
F00496A4: 80a26000                 cmp     %o1, 0
F00496A8: 16800003                 bge     loc_F00496B4
F00496AC: 90100009                 mov     %o1, %o0
F00496B0: 90026007                 add     %o1, 7, %o0
F00496B4: 913a2003                 sra     %o0, 3, %o0
F00496B8: 94020010                 add     %o0, %l0, %o2
F00496BC: 912a2003                 sll     %o0, 3, %o0
F00496C0: 90224008                 sub     %o1, %o0, %o0
F00496C4: d20aa3d8                 ldub    [%o2+0x3D8], %o1
F00496C8: 912b0008                 sll     %o4, %o0, %o0
F00496CC: 902a4008                 andn    %o1, %o0, %o0
F00496D0: d02aa3d8                 stb     %o0, [%o2+0x3D8]
F00496D4: d0042024                 ld      [%l0+0x24], %o0
F00496D8: 90023fff                 inc     -1, %o0
F00496DC: d0242024                 st      %o0, [%l0+0x24]
F00496E0: d204a0cc                 ld      [%l2+0xCC], %o1
F00496E4: 9602e001                 inc     %o3
F00496E8: d004a070                 ld      [%l2+0x70], %o0
F00496EC: 92027fff                 inc     -1, %o1
F00496F0: d224a0cc                 st      %o1, [%l2+0xCC]
F00496F4: 913e4008                 sra     %i1, %o0, %o0
F00496F8: 912a2002                 sll     %o0, 2, %o0
F00496FC: d204a06c                 ld      [%l2+0x6C], %o1
F0049700: 90020012                 add     %o0, %l2, %o0
F0049704: d40222d8                 ld      [%o0+0x2D8], %o2
F0049708: 922e4009                 andn    %i1, %o1, %o1
F004970C: 932a6004                 sll     %o1, 4, %o1
F0049710: 94028009                 add     %o2, %o1, %o2
F0049714: d002a00c                 ld      [%o2+0xC], %o0
F0049718: 80a2c01c                 cmp     %o3, %i4
F004971C: 90023fff                 inc     -1, %o0
F0049720: 06bfffe0                 bl      loc_F00496A0
F0049724: d022a00c                 st      %o0, [%o2+0xC]
F0049728: d20ca0d0                 ldub    [%l2+0xD0], %o1
F004972C: 90100011                 mov     %l1, %o0
F0049730: 92026001                 inc     %o1
F0049734: 7fff6c34                 call    _bdwrite
F0049738: d22ca0d0                 stb     %o1, [%l2+0xD0]
F004973C: b010001a                 mov     %i2, %i0
F0049740: 81c7e008                 ret
F0049744: 81e80000                 restore
