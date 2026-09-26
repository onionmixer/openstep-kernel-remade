F008C728: 9de3bf98                 save    %sp, -0x68, %sp
F008C72C: 113c04b9                 sethi   %hi(_pseudoDevList), %o0! name
F008C730: d20221b4                 ld      [%o0+%lo(_pseudoDevList)], %o1
F008C734: 80a26000                 cmp     %o1, 0
F008C738: 02800017                 be      locret_F008C794
F008C73C: a01221b4                 or      %o0, %lo(_pseudoDevList), %l0
F008C740: 273c0448                 sethi   -0xFEEE000, %l3
F008C744: 253c0506                 sethi   -0xFEBE800, %l2
F008C748: 233c0504                 sethi   -0xFEBF000, %l1
F008C74C: 4001956e                 call    _objc_getClass
F008C750: d0040000                 ld      [%l0], %o0
F008C754: 94920000                 orcc    %o0, %g0, %o2
F008C758: 12800007                 bne     loc_F008C774
F008C75C: d004a270                 ld      [%l2+0x270], %o0
F008C760: d2040000                 ld      [%l0], %o1
F008C764: 4000e664                 call    _IOLog
F008C768: 9014e010                 or      %l3, 0x10, %o0! id
F008C76C: 10800006                 ba      loc_F008C784
F008C770: a0042004                 inc     4, %l0
F008C774: d204600c                 ld      [%l1+0xC], %o1! SEL
F008C778: 4001943e                 call    _objc_msgSend
F008C77C: 96102000                 mov     0, %o3
F008C780: a0042004                 inc     4, %l0
F008C784: d0040000                 ld      [%l0], %o0
F008C788: 80a22000                 cmp     %o0, 0
F008C78C: 12bffff0                 bne     loc_F008C74C
F008C790: 01000000                 nop
F008C794: 81c7e008                 ret
F008C798: 81e80000                 restore
