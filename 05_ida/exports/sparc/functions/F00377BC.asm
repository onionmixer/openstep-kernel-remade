F00377BC: 9de3bf98                 save    %sp, -0x68, %sp
F00377C0: 40017d35                 call    _splnet
F00377C4: 01000000                 nop
F00377C8: 133c04d9                 sethi   %hi(_tcb), %o1
F00377CC: e0026340                 ld      [%o1+%lo(_tcb)], %l0
F00377D0: a6100008                 mov     %o0, %l3
F00377D4: 80a42000                 cmp     %l0, 0
F00377D8: 0280001b                 be      loc_F0037844
F00377DC: 92126340                 bset    %lo(_tcb), %o1
F00377E0: 80a40009                 cmp     %l0, %o1
F00377E4: 02800018                 be      loc_F0037844
F00377E8: 113c04e9                 sethi   %hi(_tcpstat), %o0
F00377EC: a21223a0                 or      %o0, %lo(_tcpstat), %l1
F00377F0: a4100009                 mov     %o1, %l2
F00377F4: d4042020                 ld      [%l0+0x20], %o2
F00377F8: 80a2a000                 cmp     %o2, 0
F00377FC: 2280000f                 be,a    loc_F0037838
F0037800: e0040000                 ld      [%l0], %l0
F0037804: d00aa01b                 ldub    [%o2+0x1B], %o0
F0037808: 808a2002                 btst    2, %o0
F003780C: 2280000b                 be,a    loc_F0037838
F0037810: e0040000                 ld      [%l0], %l0
F0037814: 900a20fd                 and     %o0, 0xFD, %o0
F0037818: 90122001                 bset    1, %o0
F003781C: d02aa01b                 stb     %o0, [%o2+0x1B]
F0037820: d2046020                 ld      [%l1+0x20], %o1
F0037824: 9010000a                 mov     %o2, %o0
F0037828: 92026001                 inc     %o1
F003782C: 7ffffc55                 call    _tcp_output
F0037830: d2246020                 st      %o1, [%l1+0x20]
F0037834: e0040000                 ld      [%l0], %l0
F0037838: 80a40012                 cmp     %l0, %l2
F003783C: 32bfffef                 bne,a   loc_F00377F8
F0037840: d4042020                 ld      [%l0+0x20], %o2
F0037844: 40017d38                 call    _splx
F0037848: 90100013                 mov     %l3, %o0
F003784C: 81c7e008                 ret
F0037850: 81e80000                 restore
