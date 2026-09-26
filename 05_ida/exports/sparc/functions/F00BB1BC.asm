F00BB1BC: 9de3bf98                 save    %sp, -0x68, %sp
F00BB1C0: 400000e3                 call    _clrzssoft
F00BB1C4: 01000000                 nop
F00BB1C8: 80a22000                 cmp     %o0, 0
F00BB1CC: 0280001e                 be      locret_F00BB244
F00BB1D0: 113c04fd                 sethi   %hi(_zscom), %o0
F00BB1D4: 133c04fd                 sethi   %hi(_zssoftpend), %o1
F00BB1D8: e20221e8                 ld      [%o0+%lo(_zscom)], %l1
F00BB1DC: 153c04fd                 sethi   %hi(_zslast), %o2
F00BB1E0: d002a200                 ld      [%o2+%lo(_zslast)], %o0
F00BB1E4: 80a44008                 cmp     %l1, %o0
F00BB1E8: 18800017                 bgu     locret_F00BB244
F00BB1EC: c02261d8                 clr     [%o1+%lo(_zssoftpend)]
F00BB1F0: a410000a                 mov     %o2, %l2
F00BB1F4: a004601c                 add     %l1, 0x1C, %l0
F00BB1F8: d00c2014                 ldub    [%l0+0x14], %o0
F00BB1FC: 808a2001                 btst    1, %o0
F00BB200: 2280000d                 be,a    loc_F00BB234
F00BB204: d004a200                 ld      [%l2+0x200], %o0
F00BB208: f0242018                 st      %i0, [%l0+0x18]
F00BB20C: f224201c                 st      %i1, [%l0+0x1C]
F00BB210: d00c2014                 ldub    [%l0+0x14], %o0
F00BB214: f4242020                 st      %i2, [%l0+0x20]
F00BB218: d2040000                 ld      [%l0], %o1
F00BB21C: 900a3ffe                 and     %o0, -2, %o0
F00BB220: d02c2014                 stb     %o0, [%l0+0x14]
F00BB224: d2026014                 ld      [%o1+0x14], %o1
F00BB228: 9fc24000                 call    %o1
F00BB22C: 90100011                 mov     %l1, %o0
F00BB230: d004a200                 ld      [%l2+0x200], %o0
F00BB234: a2046040                 inc     0x40, %l1 ! '@'
F00BB238: 80a44008                 cmp     %l1, %o0
F00BB23C: 08bfffef                 bleu    loc_F00BB1F8
F00BB240: a0042040                 inc     0x40, %l0 ! '@'
F00BB244: 81c7e008                 ret
F00BB248: 91e82000                 restore %g0, 0, %o0
