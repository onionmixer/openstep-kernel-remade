F00D26C4: 9de3bf88                 save    %sp, -0x78, %sp
F00D26C8: d0062170                 ld      [%i0+0x170], %o0! id
F00D26CC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D26D0: 40007c68                 call    _objc_msgSend
F00D26D4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D26D8: e0062174                 ld      [%i0+0x174], %l0
F00D26DC: 90062174                 add     %i0, 0x174, %o0
F00D26E0: 80a20010                 cmp     %o0, %l0
F00D26E4: 22800010                 be,a    loc_F00D2724
F00D26E8: d0062170                 ld      [%i0+0x170], %o0
F00D26EC: 273c0504                 sethi   -0xFEBF000, %l3
F00D26F0: 253c03ef                 sethi   -0xFF04400, %l2
F00D26F4: a2100008                 mov     %o0, %l1
F00D26F8: d0040000                 ld      [%l0], %o0! id
F00D26FC: 9407bfec                 add     %fp, var_14, %o2
F00D2700: d204e280                 ld      [%l3+0x280], %o1! SEL
F00D2704: 9614a158                 or      %l2, 0x158, %o3
F00D2708: e0042004                 ld      [%l0+4], %l0
F00D270C: 40007c59                 call    _objc_msgSend
F00D2710: 98102001                 mov     1, %o4
F00D2714: 80a44010                 cmp     %l1, %l0
F00D2718: 32bffff9                 bne,a   loc_F00D26FC
F00D271C: d0040000                 ld      [%l0], %o0
F00D2720: d0062170                 ld      [%i0+0x170], %o0! id
F00D2724: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D2728: 40007c52                 call    _objc_msgSend
F00D272C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D2730: 81c7e008                 ret
F00D2734: 81e80000                 restore
