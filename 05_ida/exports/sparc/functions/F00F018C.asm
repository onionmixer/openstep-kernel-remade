F00F018C: 9de3bf98                 save    %sp, -0x68, %sp
F00F0190: e6062020                 ld      [%i0+0x20], %l3
F00F0194: 113c03e890122354         set     _emptyCache, %o0
F00F019C: 80a4c008                 cmp     %l3, %o0
F00F01A0: 02800024                 be      locret_F00F0230
F00F01A4: a2102000                 mov     0, %l1
F00F01A8: d004c000                 ld      [%l3], %o0
F00F01AC: 80a44008                 cmp     %l1, %o0
F00F01B0: 1880001c                 bgu     loc_F00F0220
F00F01B4: 113c03c6                 sethi   %hi(__objc_msgForward), %o0
F00F01B8: a81222b0                 or      %o0, %lo(__objc_msgForward), %l4
F00F01BC: 912c6002                 sll     %l1, 2, %o0
F00F01C0: a4020013                 add     %o0, %l3, %l2
F00F01C4: d004a008                 ld      [%l2+8], %o0
F00F01C8: 80a22000                 cmp     %o0, 0
F00F01CC: 2280000e                 be,a    loc_F00F0204
F00F01D0: 912c6002                 sll     %l1, 2, %o0
F00F01D4: d0022008                 ld      [%o0+8], %o0
F00F01D8: 80a20014                 cmp     %o0, %l4
F00F01DC: 1280000a                 bne     loc_F00F0204
F00F01E0: 912c6002                 sll     %l1, 2, %o0
F00F01E4: 4000025a                 call    _NXDefaultMallocZone
F00F01E8: 01000000                 nop
F00F01EC: 40000258                 call    _NXDefaultMallocZone
F00F01F0: a0100008                 mov     %o0, %l0
F00F01F4: d4042008                 ld      [%l0+8], %o2
F00F01F8: 9fc28000                 call    %o2
F00F01FC: d204a008                 ld      [%l2+8], %o1
F00F0200: 912c6002                 sll     %l1, 2, %o0
F00F0204: 90020013                 add     %o0, %l3, %o0
F00F0208: c0222008                 clr     [%o0+8]
F00F020C: a2046001                 inc     %l1
F00F0210: d004c000                 ld      [%l3], %o0
F00F0214: 80a44008                 cmp     %l1, %o0
F00F0218: 08bfffea                 bleu    loc_F00F01C0
F00F021C: 912c6002                 sll     %l1, 2, %o0
F00F0220: c024e004                 clr     [%l3+4]
F00F0224: d0062010                 ld      [%i0+0x10], %o0
F00F0228: 900a3fdf                 and     %o0, -0x21, %o0
F00F022C: d0262010                 st      %o0, [%i0+0x10]
F00F0230: 81c7e008                 ret
F00F0234: 81e80000                 restore
