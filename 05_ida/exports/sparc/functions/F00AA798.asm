F00AA798: 9de3bf98                 save    %sp, -0x68, %sp! int
F00AA79C: 113c04d0                 sethi   %hi(_active_threads), %o0
F00AA7A0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00AA7A4: e4022028                 ld      [%o0+0x28], %l2
F00AA7A8: 113bffff                 sethi   -0x10000400, %o0
F00AA7AC: e204a260                 ld      [%l2+0x260], %l1
F00AA7B0: 901223ff                 bset    0x3FF, %o0
F00AA7B4: 80a44008                 cmp     %l1, %o0
F00AA7B8: 18800052                 bgu     locret_F00AA900
F00AA7BC: 808c6003                 btst    3, %l1
F00AA7C0: 12800050                 bne     locret_F00AA900
F00AA7C4: 01000000                 nop
F00AA7C8: d004600c                 ld      [%l1+0xC], %o0
F00AA7CC: 808a2003                 btst    3, %o0
F00AA7D0: 1280004c                 bne     locret_F00AA900
F00AA7D4: 01000000                 nop
F00AA7D8: d0046010                 ld      [%l1+0x10], %o0
F00AA7DC: 808a2003                 btst    3, %o0
F00AA7E0: 12800048                 bne     locret_F00AA900
F00AA7E4: 01000000                 nop
F00AA7E8: 7ffd69c5                 call    _flush_user_windows
F00AA7EC: 01000000                 nop
F00AA7F0: d0044000                 ld      [%l1], %o0
F00AA7F4: 153c04cf                 sethi   %hi(_active_u), %o2
F00AA7F8: d202a1d8                 ld      [%o2+%lo(_active_u)], %o1
F00AA7FC: 900a2001                 and     %o0, 1, %o0
F00AA800: d0226148                 st      %o0, [%o1+0x148]
F00AA804: d402a1d8                 ld      [%o2+%lo(_active_u)], %o2
F00AA808: 113fffbf                 sethi   -0x10400, %o0
F00AA80C: d2046004                 ld      [%l1+4], %o1
F00AA810: 901222ff                 bset    0x2FF, %o0
F00AA814: d4028000                 ld      [%o2], %o2
F00AA818: 920a4008                 and     %o1, %o0, %o1
F00AA81C: d222a01c                 st      %o1, [%o2+0x1C]
F00AA820: d0046008                 ld      [%l1+8], %o0
F00AA824: d024a278                 st      %o0, [%l2+0x278]
F00AA828: d004600c                 ld      [%l1+0xC], %o0
F00AA82C: d024a238                 st      %o0, [%l2+0x238]
F00AA830: d0046010                 ld      [%l1+0x10], %o0
F00AA834: d024a23c                 st      %o0, [%l2+0x23C]
F00AA838: d004a234                 ld      [%l2+0x234], %o0
F00AA83C: 13003c00                 sethi   0xF00000, %o1
F00AA840: 922a0009                 andn    %o0, %o1, %o1
F00AA844: d0046014                 ld      [%l1+0x14], %o0
F00AA848: 15003c00                 sethi   0xF00000, %o2
F00AA84C: 900a000a                 and     %o0, %o2, %o0
F00AA850: 92124008                 bset    %o0, %o1
F00AA854: d224a234                 st      %o1, [%l2+0x234]
F00AA858: d0046018                 ld      [%l1+0x18], %o0
F00AA85C: d024a244                 st      %o0, [%l2+0x244]
F00AA860: d004601c                 ld      [%l1+0x1C], %o0
F00AA864: d024a260                 st      %o0, [%l2+0x260]
F00AA868: d2046020                 ld      [%l1+0x20], %o1
F00AA86C: 113c000c                 sethi   %hi(_nwindows), %o0
F00AA870: d002203c                 ld      [%o0+%lo(_nwindows)], %o0
F00AA874: 80a24008                 cmp     %o1, %o0
F00AA878: 1a80001d                 bcc     loc_F00AA8EC
F00AA87C: a0102000                 mov     0, %l0
F00AA880: 80a40009                 cmp     %l0, %o1
F00AA884: 16800015                 bge     loc_F00AA8D8
F00AA888: ea04a230                 ld      [%l2+0x230], %l5
F00AA88C: a81020a0                 mov     0xA0, %l4
F00AA890: a6100011                 mov     %l1, %l3
F00AA894: 90044014                 add     %l1, %l4, %o0! int
F00AA898: a8052040                 inc     0x40, %l4 ! '@'
F00AA89C: 92054010                 add     %l5, %l0, %o1
F00AA8A0: a0042001                 inc     %l0
F00AA8A4: 952a6002                 sll     %o1, 2, %o2
F00AA8A8: 94028012                 add     %o2, %l2, %o2! int
F00AA8AC: 932a6006                 sll     %o1, 6, %o1
F00AA8B0: 92026010                 inc     0x10, %o1
F00AA8B4: d604e024                 ld      [%l3+0x24], %o3! int
F00AA8B8: 92048009                 add     %l2, %o1, %o1! int
F00AA8BC: d622a210                 st      %o3, [%o2+0x210]
F00AA8C0: 7fffb5e6                 call    _copyin
F00AA8C4: 94102040                 mov     0x40, %o2 ! '@'
F00AA8C8: d0046020                 ld      [%l1+0x20], %o0
F00AA8CC: 80a40008                 cmp     %l0, %o0
F00AA8D0: 06bffff1                 bl      loc_F00AA894
F00AA8D4: a604e004                 inc     4, %l3
F00AA8D8: d004a230                 ld      [%l2+0x230], %o0
F00AA8DC: d2046020                 ld      [%l1+0x20], %o1
F00AA8E0: 90020009                 add     %o0, %o1, %o0
F00AA8E4: 10800003                 ba      loc_F00AA8F0
F00AA8E8: d024a230                 st      %o0, [%l2+0x230]
F00AA8EC: c024a230                 clr     [%l2+0x230]
F00AA8F0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00AA8F4: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00AA8F8: 90102001                 mov     1, %o0
F00AA8FC: d02a6039                 stb     %o0, [%o1+0x39]
F00AA900: 81c7e008                 ret
F00AA904: 81e80000                 restore
