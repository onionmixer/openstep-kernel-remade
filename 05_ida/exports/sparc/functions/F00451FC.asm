F00451FC: 9de3bf98                 save    %sp, -0x68, %sp
F0045200: 113c04eb                 sethi   %hi(_ndupreqs), %o0
F0045204: d0022108                 ld      [%o0+%lo(_ndupreqs)], %o0
F0045208: 80a2218f                 cmp     %o0, 0x18F
F004520C: 14800013                 bg      loc_F0045258
F0045210: 113c04eb                 sethi   -0xFEC5400, %o0
F0045214: 40008b97                 call    _kalloc
F0045218: 90102028                 mov     0x28, %o0 ! '('
F004521C: 133c04eb                 sethi   %hi(_drmru), %o1
F0045220: d20260f0                 ld      [%o1+%lo(_drmru)], %o1
F0045224: 80a26000                 cmp     %o1, 0
F0045228: 02800006                 be      loc_F0045240
F004522C: a0100008                 mov     %o0, %l0
F0045230: d0026020                 ld      [%o1+0x20], %o0
F0045234: d0242020                 st      %o0, [%l0+0x20]
F0045238: 10800003                 ba      loc_F0045244
F004523C: e0226020                 st      %l0, [%o1+0x20]
F0045240: e0242020                 st      %l0, [%l0+0x20]
F0045244: 133c04eb                 sethi   %hi(_ndupreqs), %o1
F0045248: d0026108                 ld      [%o1+%lo(_ndupreqs)], %o0
F004524C: 90022001                 inc     %o0
F0045250: 10800006                 ba      loc_F0045268
F0045254: d0226108                 st      %o0, [%o1+%lo(_ndupreqs)]
F0045258: d00220f0                 ld      [%o0+0xF0], %o0
F004525C: e0022020                 ld      [%o0+0x20], %l0
F0045260: 4000005b                 call    sub_F00453CC
F0045264: 90100010                 mov     %l0, %o0
F0045268: d006201c                 ld      [%i0+0x1C], %o0
F004526C: d0022030                 ld      [%o0+0x30], %o0
F0045270: d0022004                 ld      [%o0+4], %o0
F0045274: d0240000                 st      %o0, [%l0]
F0045278: d0060000                 ld      [%i0], %o0
F004527C: d024201c                 st      %o0, [%l0+0x1C]
F0045280: d0062004                 ld      [%i0+4], %o0
F0045284: d0242018                 st      %o0, [%l0+0x18]
F0045288: d0062008                 ld      [%i0+8], %o0
F004528C: d0242014                 st      %o0, [%l0+0x14]
F0045290: d206201c                 ld      [%i0+0x1C], %o1
F0045294: d0026010                 ld      [%o1+0x10], %o0
F0045298: d0242004                 st      %o0, [%l0+4]
F004529C: d0026014                 ld      [%o1+0x14], %o0
F00452A0: d0242008                 st      %o0, [%l0+8]
F00452A4: d0026018                 ld      [%o1+0x18], %o0
F00452A8: d024200c                 st      %o0, [%l0+0xC]
F00452AC: d002601c                 ld      [%o1+0x1C], %o0
F00452B0: 173c04eb                 sethi   %hi(_drmru), %o3
F00452B4: d0242010                 st      %o0, [%l0+0x10]
F00452B8: 133c04eb                 sethi   %hi(_drhashtbl), %o1
F00452BC: d0040000                 ld      [%l0], %o0
F00452C0: 92126070                 bset    %lo(_drhashtbl), %o1
F00452C4: 900a201f                 and     %o0, 0x1F, %o0
F00452C8: 912a2002                 sll     %o0, 2, %o0
F00452CC: d4020009                 ld      [%o0+%o1], %o2
F00452D0: e022e0f0                 st      %l0, [%o3+%lo(_drmru)]
F00452D4: d0040000                 ld      [%l0], %o0
F00452D8: d4242024                 st      %o2, [%l0+0x24]
F00452DC: 900a201f                 and     %o0, 0x1F, %o0
F00452E0: 912a2002                 sll     %o0, 2, %o0
F00452E4: e0220009                 st      %l0, [%o0+%o1]
F00452E8: 81c7e008                 ret
F00452EC: 81e80000                 restore
