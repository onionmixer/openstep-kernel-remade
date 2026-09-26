F00D25C8: 9de3bf88                 save    %sp, -0x78, %sp
F00D25CC: 113c0504                 sethi   %hi(paLock), %o0
F00D25D0: e0022000                 ld      [%o0+%lo(paLock)], %l0
F00D25D4: d0062110                 ld      [%i0+0x110], %o0! id
F00D25D8: 40007ca6                 call    _objc_msgSend
F00D25DC: 92100010                 mov     %l0, %o1
F00D25E0: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D25E4: 80a22000                 cmp     %o0, 0
F00D25E8: 12800004                 bne     loc_F00D25F8
F00D25EC: 9010201e                 mov     0x1E, %o0
F00D25F0: 10800030                 ba      loc_F00D26B0
F00D25F4: d0062110                 ld      [%i0+0x110], %o0
F00D25F8: d02621bc                 st      %o0, [%i0+0x1BC]
F00D25FC: 90102003                 mov     3, %o0
F00D2600: d03621b2                 sth     %o0, [%i0+0x1B2]
F00D2604: d03621b0                 sth     %o0, [%i0+0x1B0]
F00D2608: 90103fe2                 mov     -0x1E, %o0
F00D260C: d02621b8                 st      %o0, [%i0+0x1B8]
F00D2610: 90103ffd                 mov     -3, %o0
F00D2614: d03621ae                 sth     %o0, [%i0+0x1AE]
F00D2618: d03621ac                 sth     %o0, [%i0+0x1AC]
F00D261C: 133c0504                 sethi   %hi(paUnlock), %o1
F00D2620: 94102001                 mov     1, %o2
F00D2624: d0062110                 ld      [%i0+0x110], %o0! id
F00D2628: d42621b4                 st      %o2, [%i0+0x1B4]
F00D262C: d4062168                 ld      [%i0+0x168], %o2
F00D2630: 17000012                 sethi   0x4800, %o3
F00D2634: d402a010                 ld      [%o2+0x10], %o2
F00D2638: 9612e0a8                 bset    0xA8, %o3
F00D263C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D2640: 9402800b                 add     %o2, %o3, %o2
F00D2644: d42621a4                 st      %o2, [%i0+0x1A4]
F00D2648: d62621a0                 st      %o3, [%i0+0x1A0]
F00D264C: 94102010                 mov     0x10, %o2
F00D2650: 40007c88                 call    _objc_msgSend
F00D2654: d42621c8                 st      %o2, [%i0+0x1C8]
F00D2658: d0062170                 ld      [%i0+0x170], %o0! id
F00D265C: 40007c85                 call    _objc_msgSend
F00D2660: 92100010                 mov     %l0, %o1
F00D2664: e0062174                 ld      [%i0+0x174], %l0
F00D2668: 90062174                 add     %i0, 0x174, %o0
F00D266C: 80a20010                 cmp     %o0, %l0
F00D2670: 22800010                 be,a    loc_F00D26B0
F00D2674: d0062170                 ld      [%i0+0x170], %o0
F00D2678: 273c0504                 sethi   -0xFEBF000, %l3
F00D267C: 253c03ef                 sethi   -0xFF04400, %l2
F00D2680: a2100008                 mov     %o0, %l1
F00D2684: d0040000                 ld      [%l0], %o0! id
F00D2688: 9407bfec                 add     %fp, var_14, %o2
F00D268C: d204e280                 ld      [%l3+0x280], %o1! SEL
F00D2690: 9614a148                 or      %l2, 0x148, %o3
F00D2694: e0042004                 ld      [%l0+4], %l0
F00D2698: 40007c76                 call    _objc_msgSend
F00D269C: 98102001                 mov     1, %o4
F00D26A0: 80a44010                 cmp     %l1, %l0
F00D26A4: 32bffff9                 bne,a   loc_F00D2688
F00D26A8: d0040000                 ld      [%l0], %o0
F00D26AC: d0062170                 ld      [%i0+0x170], %o0! id
F00D26B0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D26B4: 40007c6f                 call    _objc_msgSend
F00D26B8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D26BC: 81c7e008                 ret
F00D26C0: 81e80000                 restore
