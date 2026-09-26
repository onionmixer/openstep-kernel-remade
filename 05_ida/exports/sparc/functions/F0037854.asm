F0037854: 9de3bf98                 save    %sp, -0x68, %sp
F0037858: 40017d0f                 call    _splnet
F003785C: 01000000                 nop
F0037860: 133c0432                 sethi   %hi(_tcp_keepintvl), %o1
F0037864: 173c04d9                 sethi   %hi(_tcb), %o3
F0037868: d4026120                 ld      [%o1+%lo(_tcp_keepintvl)], %o2
F003786C: aa100008                 mov     %o0, %l5
F0037870: e602e340                 ld      [%o3+%lo(_tcb)], %l3
F0037874: 952aa003                 sll     %o2, 3, %o2
F0037878: 133c04ea                 sethi   %hi(_tcp_maxidle), %o1
F003787C: d4226058                 st      %o2, [%o1+%lo(_tcp_maxidle)]
F0037880: 80a4e000                 cmp     %l3, 0
F0037884: 02800039                 be      loc_F0037968
F0037888: 9612e340                 bset    %lo(_tcb), %o3
F003788C: 80a4c00b                 cmp     %l3, %o3
F0037890: 22800030                 be,a    loc_F0037950
F0037894: 90100015                 mov     %l5, %o0
F0037898: ac10000b                 mov     %o3, %l6
F003789C: e004e020                 ld      [%l3+0x20], %l0
F00378A0: 80a42000                 cmp     %l0, 0
F00378A4: 02800026                 be      loc_F003793C
F00378A8: e804c000                 ld      [%l3], %l4
F00378AC: a4102000                 mov     0, %l2
F00378B0: a2100010                 mov     %l0, %l1
F00378B4: d054600a                 ldsh    [%l1+0xA], %o0
F00378B8: 80a22000                 cmp     %o0, 0
F00378BC: 22800014                 be,a    loc_F003790C
F00378C0: a404a001                 inc     %l2
F00378C4: 90023fff                 inc     -1, %o0
F00378C8: d034600a                 sth     %o0, [%l1+0xA]
F00378CC: 912a2010                 sll     %o0, 16, %o0
F00378D0: 80a22000                 cmp     %o0, 0
F00378D4: 3280000e                 bne,a   loc_F003790C
F00378D8: a404a001                 inc     %l2
F00378DC: 92102013                 mov     0x13, %o1
F00378E0: 94102000                 mov     0, %o2
F00378E4: d0042020                 ld      [%l0+0x20], %o0
F00378E8: 96100012                 mov     %l2, %o3
F00378EC: d002201c                 ld      [%o0+0x1C], %o0
F00378F0: 400000dd                 call    _tcp_usrreq
F00378F4: 98102000                 mov     0, %o4
F00378F8: d0052004                 ld      [%l4+4], %o0
F00378FC: 80a20013                 cmp     %o0, %l3
F0037900: 32800010                 bne,a   loc_F0037940
F0037904: a6100014                 mov     %l4, %l3
F0037908: a404a001                 inc     %l2
F003790C: 80a4a003                 cmp     %l2, 3
F0037910: 04bfffe9                 ble     loc_F00378B4
F0037914: a2046002                 inc     2, %l1
F0037918: d0142058                 lduh    [%l0+0x58], %o0
F003791C: 90022001                 inc     %o0
F0037920: d254205a                 ldsh    [%l0+0x5A], %o1
F0037924: d0342058                 sth     %o0, [%l0+0x58]
F0037928: 80a26000                 cmp     %o1, 0
F003792C: 02800004                 be      loc_F003793C
F0037930: 90100009                 mov     %o1, %o0
F0037934: 90022001                 inc     %o0
F0037938: d034205a                 sth     %o0, [%l0+0x5A]
F003793C: a6100014                 mov     %l4, %l3
F0037940: 80a4c016                 cmp     %l3, %l6
F0037944: 32bfffd7                 bne,a   loc_F00378A0
F0037948: e004e020                 ld      [%l3+0x20], %l0
F003794C: 90100015                 mov     %l5, %o0
F0037950: 173c04e9                 sethi   %hi(_tcp_iss), %o3
F0037954: d402e398                 ld      [%o3+%lo(_tcp_iss)], %o2
F0037958: 1300003e92126200         set     0xFA00, %o1
F0037960: 94028009                 add     %o2, %o1, %o2
F0037964: d422e398                 st      %o2, [%o3+%lo(_tcp_iss)]
F0037968: 40017cef                 call    _splx
F003796C: 01000000                 nop
F0037970: 81c7e008                 ret
F0037974: 81e80000                 restore
