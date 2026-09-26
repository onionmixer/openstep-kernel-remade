F009A0C4: 9de3bf90                 save    %sp, -0x70, %sp
F009A0C8: a2100018                 mov     %i0, %l1
F009A0CC: d4066020                 ld      [%i1+0x20], %o2
F009A0D0: 90100019                 mov     %i1, %o0
F009A0D4: d2066014                 ld      [%i1+0x14], %o1
F009A0D8: aa0aafff                 and     %o2, 0xFFF, %l5
F009A0DC: 92024015                 add     %o1, %l5, %o1
F009A0E0: 92026fff                 inc     0xFFF, %o1
F009A0E4: 7ffffc66                 call    _buscheck
F009A0E8: a732600c                 srl     %o1, 12, %l3
F009A0EC: a0920000                 orcc    %o0, %g0, %l0
F009A0F0: 16800006                 bge     loc_F009A108
F009A0F4: 01000000                 nop
F009A0F8: 113c045c                 sethi   %hi(aMbMapallocBusc), %o0! "mb_mapalloc buscheck fail"
F009A0FC: 7ffdec1d                 call    _panic
F009A100: 90122200                 bset    %lo(aMbMapallocBusc), %o0! "mb_mapalloc buscheck fail"
F009A104: 80a42000                 cmp     %l0, 0
F009A108: 04800019                 ble     loc_F009A16C
F009A10C: 113c04f6                 sethi   -0xFEC2800, %o0
F009A110: 40005b1d                 call    _bustype
F009A114: 90100010                 mov     %l0, %o0
F009A118: 80a22003                 cmp     %o0, 3
F009A11C: 0280004f                 be      locret_F009A258
F009A120: b0102000                 mov     0, %i0
F009A124: 14800006                 bg      loc_F009A13C
F009A128: 80a22004                 cmp     %o0, 4
F009A12C: 80a22001                 cmp     %o0, 1
F009A130: 0280004a                 be      locret_F009A258
F009A134: 113c04f6                 sethi   -0xFEC2800, %o0
F009A138: 3080000d                 ba,a    loc_F009A16C
F009A13C: 0280000b                 be      loc_F009A168
F009A140: 80a22005                 cmp     %o0, 5
F009A144: 1280000a                 bne     loc_F009A16C
F009A148: 113c04f6                 sethi   -0xFEC2800, %o0
F009A14C: 113c04f6                 sethi   %hi(_mbutlmap), %o0
F009A150: d0022310                 ld      [%o0+%lo(_mbutlmap)], %o0
F009A154: 80a44008                 cmp     %l1, %o0
F009A158: 12800005                 bne     loc_F009A16C
F009A15C: 113c04f6                 sethi   -0xFEC2800, %o0
F009A160: 1080003e                 ba      locret_F009A258
F009A164: b0102000                 mov     0, %i0
F009A168: 113c04f6                 sethi   -0xFEC2800, %o0
F009A16C: d00222f8                 ld      [%o0+0x2F8], %o0
F009A170: 80a44008                 cmp     %l1, %o0
F009A174: 12800005                 bne     loc_F009A188
F009A178: 808ea040                 btst    0x40, %i2 ! '@'
F009A17C: 02800003                 be      loc_F009A188
F009A180: 113c04f6                 sethi   %hi(_bigsbusmap), %o0
F009A184: e20222f0                 ld      [%o0+%lo(_bigsbusmap)], %l1
F009A188: 7ffff2dd                 call    _splvm
F009A18C: 01000000                 nop
F009A190: a0100008                 mov     %o0, %l0
F009A194: a93c2008                 sra     %l0, 8, %l4
F009A198: 113c04c5a412213c         set     dword_F013153C, %l2
F009A1A0: 90100011                 mov     %l1, %o0
F009A1A4: 92100019                 mov     %i1, %o1
F009A1A8: 7ffffc7b                 call    _bp_alloc
F009A1AC: 9404e001                 add     %l3, 1, %o2
F009A1B0: b0920000                 orcc    %o0, %g0, %i0
F009A1B4: 1280001b                 bne     loc_F009A220
F009A1B8: 808ea001                 btst    1, %i2
F009A1BC: 02800011                 be      loc_F009A200
F009A1C0: 80a6e000                 cmp     %i3, 0
F009A1C4: 0280000b                 be      loc_F009A1F0
F009A1C8: 9010001b                 mov     %i3, %o0
F009A1CC: 9210001c                 mov     %i4, %o1
F009A1D0: 4000006e                 call    sub_F009A388
F009A1D4: 940d200f                 and     %l4, 0xF, %o2
F009A1D8: d004a008                 ld      [%l2+8], %o0
F009A1DC: 932ce00c                 sll     %l3, 12, %o1
F009A1E0: 80a24008                 cmp     %o1, %o0
F009A1E4: 26800002                 bl,a    loc_F009A1EC
F009A1E8: 92100008                 mov     %o0, %o1
F009A1EC: d224a008                 st      %o1, [%l2+8]
F009A1F0: 7ffff2cd                 call    _splx
F009A1F4: 90100010                 mov     %l0, %o0
F009A1F8: 10800018                 ba      locret_F009A258
F009A1FC: b0102000                 mov     0, %i0
F009A200: 90100011                 mov     %l1, %o0! unsigned int
F009A204: d4046004                 ld      [%l1+4], %o2
F009A208: 92102000                 mov     0, %o1
F009A20C: 9402a001                 inc     %o2
F009A210: 7ffde11a                 call    _sleep
F009A214: d4246004                 st      %o2, [%l1+4]
F009A218: 10bfffe3                 ba      loc_F009A1A4
F009A21C: 90100011                 mov     %l1, %o0
F009A220: 7ffff2c1                 call    _splx
F009A224: 90100010                 mov     %l0, %o0
F009A228: 113c0464                 sethi   %hi(_iom), %o0
F009A22C: d0022338                 ld      [%o0+%lo(_iom)], %o0
F009A230: 80a22000                 cmp     %o0, 0
F009A234: 02800006                 be      loc_F009A24C
F009A238: 90100019                 mov     %i1, %o0
F009A23C: 92100018                 mov     %i0, %o1
F009A240: 9410001a                 mov     %i2, %o2
F009A244: 7ffffca0                 call    _bp_iom_map
F009A248: 96100011                 mov     %l1, %o3
F009A24C: b12e200c                 sll     %i0, 12, %i0
F009A250: b0160015                 bset    %l5, %i0
F009A254: f027bff4                 st      %i0, [%fp+var_C]
F009A258: 81c7e008                 ret
F009A25C: 81e80000                 restore
