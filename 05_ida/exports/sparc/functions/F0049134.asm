F0049134: 9de3bf98                 save    %sp, -0x68, %sp
F0049138: a0100018                 mov     %i0, %l0
F004913C: e2042050                 ld      [%l0+0x50], %l1
F0049140: e404605c                 ld      [%l1+0x5C], %l2
F0049144: 9010001a                 mov     %i2, %o0
F0049148: 7ffef5d8                 call    _rem
F004914C: 92100012                 mov     %l2, %o1
F0049150: 80a22000                 cmp     %o0, 0
F0049154: 02800007                 be      loc_F0049170
F0049158: 912ea002                 sll     %i2, 2, %o0
F004915C: 9002001b                 add     %o0, %i3, %o0
F0049160: f0023ffc                 ld      [%o0-4], %i0
F0049164: 80a62000                 cmp     %i0, 0
F0049168: 32800058                 bne,a   loc_F00492C8
F004916C: d0046038                 ld      [%l1+0x38], %o0
F0049170: 80a6600b                 cmp     %i1, 0xB
F0049174: 1480000b                 bg      loc_F00491A0
F0049178: 80a6a000                 cmp     %i2, 0
F004917C: d0042048                 ld      [%l0+0x48], %o0
F0049180: 7ffef520                 call    _udiv
F0049184: d20460b8                 ld      [%l1+0xB8], %o1
F0049188: 94100008                 mov     %o0, %o2
F004918C: d00460bc                 ld      [%l1+0xBC], %o0
F0049190: 7ffef4dc                 call    _umul
F0049194: 9210000a                 mov     %o2, %o1
F0049198: 1080007a                 ba      loc_F0049380
F004919C: f0046038                 ld      [%l1+0x38], %i0
F00491A0: 02800007                 be      loc_F00491BC
F00491A4: 912ea002                 sll     %i2, 2, %o0
F00491A8: 9002001b                 add     %o0, %i3, %o0
F00491AC: d0023ffc                 ld      [%o0-4], %o0
F00491B0: 80a22000                 cmp     %o0, 0
F00491B4: 1280000b                 bne     loc_F00491E0
F00491B8: 01000000                 nop
F00491BC: d0042048                 ld      [%l0+0x48], %o0
F00491C0: 7ffef510                 call    _udiv
F00491C4: d20460b8                 ld      [%l1+0xB8], %o1! int
F00491C8: a0100008                 mov     %o0, %l0
F00491CC: 90100019                 mov     %i1, %o0! int
F00491D0: 7ffef50e                 call    _div
F00491D4: 92100012                 mov     %l2, %o1! int
F00491D8: 10800005                 ba      loc_F00491EC
F00491DC: a0040008                 add     %l0, %o0, %l0
F00491E0: 7ffef50a                 call    _div
F00491E4: d20460bc                 ld      [%l1+0xBC], %o1
F00491E8: a0022001                 add     %o0, 1, %l0
F00491EC: f004602c                 ld      [%l1+0x2C], %i0
F00491F0: 90100010                 mov     %l0, %o0
F00491F4: 7ffef5ad                 call    _rem
F00491F8: 92100018                 mov     %i0, %o1! int
F00491FC: a0100008                 mov     %o0, %l0
F0049200: d00460c4                 ld      [%l1+0xC4], %o0! int
F0049204: 7ffef501                 call    _div
F0049208: 92100018                 mov     %i0, %o1
F004920C: 94100010                 mov     %l0, %o2
F0049210: 80a28018                 cmp     %o2, %i0
F0049214: 16800015                 bge     loc_F0049268
F0049218: 96100008                 mov     %o0, %o3
F004921C: d004606c                 ld      [%l1+0x6C], %o0
F0049220: 84100018                 mov     %i0, %g2
F0049224: da046070                 ld      [%l1+0x70], %o5
F0049228: 98380008                 xnor    %g0, %o0, %o4
F004922C: 913a800d                 sra     %o2, %o5, %o0
F0049230: 912a2002                 sll     %o0, 2, %o0
F0049234: 90020011                 add     %o0, %l1, %o0
F0049238: 920a800c                 and     %o2, %o4, %o1
F004923C: d00222d8                 ld      [%o0+0x2D8], %o0
F0049240: 932a6004                 sll     %o1, 4, %o1
F0049244: 90020009                 add     %o0, %o1, %o0
F0049248: d0022004                 ld      [%o0+4], %o0
F004924C: 80a2000b                 cmp     %o0, %o3
F0049250: 3680002c                 bge,a   loc_F0049300
F0049254: d42462d4                 st      %o2, [%l1+0x2D4]
F0049258: 9402a001                 inc     %o2
F004925C: 80a28002                 cmp     %o2, %g2
F0049260: 06bffff4                 bl      loc_F0049230
F0049264: 913a800d                 sra     %o2, %o5, %o0
F0049268: 94102000                 mov     0, %o2
F004926C: 80a28010                 cmp     %o2, %l0
F0049270: 14800045                 bg      locret_F0049384
F0049274: b0102000                 mov     0, %i0
F0049278: d004606c                 ld      [%l1+0x6C], %o0
F004927C: da046070                 ld      [%l1+0x70], %o5
F0049280: 98380008                 xnor    %g0, %o0, %o4
F0049284: 913a800d                 sra     %o2, %o5, %o0
F0049288: 912a2002                 sll     %o0, 2, %o0
F004928C: 90020011                 add     %o0, %l1, %o0
F0049290: 920a800c                 and     %o2, %o4, %o1
F0049294: d00222d8                 ld      [%o0+0x2D8], %o0
F0049298: 932a6004                 sll     %o1, 4, %o1
F004929C: 90020009                 add     %o0, %o1, %o0
F00492A0: d0022004                 ld      [%o0+4], %o0
F00492A4: 80a2000b                 cmp     %o0, %o3
F00492A8: 3680001b                 bge,a   loc_F0049314
F00492AC: d42462d4                 st      %o2, [%l1+0x2D4]
F00492B0: 9402a001                 inc     %o2
F00492B4: 80a28010                 cmp     %o2, %l0
F00492B8: 04bffff4                 ble     loc_F0049288
F00492BC: 913a800d                 sra     %o2, %o5, %o0
F00492C0: 10800031                 ba      locret_F0049384
F00492C4: b0102000                 mov     0, %i0
F00492C8: d4046058                 ld      [%l1+0x58], %o2
F00492CC: 80a6800a                 cmp     %i2, %o2
F00492D0: 04800016                 ble     loc_F0049328
F00492D4: b0060008                 add     %i0, %o0, %i0
F00492D8: 9026800a                 sub     %i2, %o2, %o0
F00492DC: d2046060                 ld      [%l1+0x60], %o1
F00492E0: 912a2002                 sll     %o0, 2, %o0
F00492E4: d006c008                 ld      [%i3+%o0], %o0
F00492E8: 932a8009                 sll     %o2, %o1, %o1
F00492EC: 90020009                 add     %o0, %o1, %o0
F00492F0: 80a20018                 cmp     %o0, %i0
F00492F4: 2280000e                 be,a    loc_F004932C
F00492F8: d0046040                 ld      [%l1+0x40], %o0
F00492FC: 30800022                 ba,a    locret_F0049384
F0049300: d00460bc                 ld      [%l1+0xBC], %o0
F0049304: 7ffef47f                 call    _umul
F0049308: 9210000a                 mov     %o2, %o1
F004930C: 1080001d                 ba      loc_F0049380
F0049310: f0046038                 ld      [%l1+0x38], %i0
F0049314: d00460bc                 ld      [%l1+0xBC], %o0
F0049318: 7ffef47a                 call    _umul
F004931C: 9210000a                 mov     %o2, %o1
F0049320: 10800018                 ba      loc_F0049380
F0049324: f0046038                 ld      [%l1+0x38], %i0
F0049328: d0046040                 ld      [%l1+0x40], %o0! int
F004932C: 80a22000                 cmp     %o0, 0
F0049330: 02800015                 be      locret_F0049384
F0049334: 01000000                 nop
F0049338: 7ffef472                 call    _umul
F004933C: d2046044                 ld      [%l1+0x44], %o1
F0049340: 7ffef470                 call    _umul
F0049344: d20460a8                 ld      [%l1+0xA8], %o1
F0049348: d404607c                 ld      [%l1+0x7C], %o2
F004934C: 932aa005                 sll     %o2, 5, %o1
F0049350: 9222400a                 sub     %o1, %o2, %o1
F0049354: 932a6002                 sll     %o1, 2, %o1
F0049358: 9202400a                 add     %o1, %o2, %o1! int
F004935C: 7ffef4ab                 call    _div
F0049360: 932a6003                 sll     %o1, 3, %o1! int
F0049364: e0046038                 ld      [%l1+0x38], %l0
F0049368: 90023fff                 inc     -1, %o0
F004936C: 90020010                 add     %o0, %l0, %o0! int
F0049370: 7ffef4a6                 call    _div
F0049374: 92100010                 mov     %l0, %o1
F0049378: 7ffef462                 call    _umul
F004937C: 92100010                 mov     %l0, %o1
F0049380: b0060008                 add     %i0, %o0, %i0
F0049384: 81c7e008                 ret
F0049388: 81e80000                 restore
