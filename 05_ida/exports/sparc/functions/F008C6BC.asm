F008C6BC: 9de3bf98                 save    %sp, -0x68, %sp
F008C6C0: 113c04b9                 sethi   %hi(_indirectDevList), %o0! name
F008C6C4: d2022178                 ld      [%o0+%lo(_indirectDevList)], %o1
F008C6C8: 80a26000                 cmp     %o1, 0
F008C6CC: 02800015                 be      locret_F008C720
F008C6D0: a0122178                 or      %o0, %lo(_indirectDevList), %l0
F008C6D4: 253c0447                 sethi   -0xFEEE400, %l2
F008C6D8: 233c0504                 sethi   -0xFEBF000, %l1
F008C6DC: 4001958a                 call    _objc_getClass
F008C6E0: d0040000                 ld      [%l0], %o0
F008C6E4: 80a22000                 cmp     %o0, 0
F008C6E8: 12800007                 bne     loc_F008C704
F008C6EC: 01000000                 nop
F008C6F0: d2040000                 ld      [%l0], %o1! SEL
F008C6F4: 4000e680                 call    _IOLog
F008C6F8: 9014a3d8                 or      %l2, 0x3D8, %o0! id
F008C6FC: 10800005                 ba      loc_F008C710
F008C700: a0042004                 inc     4, %l0
F008C704: 4001945b                 call    _objc_msgSend
F008C708: d2046008                 ld      [%l1+8], %o1
F008C70C: a0042004                 inc     4, %l0
F008C710: d0040000                 ld      [%l0], %o0
F008C714: 80a22000                 cmp     %o0, 0
F008C718: 12bffff1                 bne     loc_F008C6DC
F008C71C: 01000000                 nop
F008C720: 81c7e008                 ret
F008C724: 81e80000                 restore
