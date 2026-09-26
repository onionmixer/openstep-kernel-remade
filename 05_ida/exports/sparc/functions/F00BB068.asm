F00BB068: 9de3bf98                 save    %sp, -0x68, %sp
F00BB06C: 113c04fd                 sethi   %hi(_zscurr), %o0
F00BB070: e00221f0                 ld      [%o0+%lo(_zscurr)], %l0
F00BB074: a2102000                 mov     0, %l1
F00BB078: 273c04fd                 sethi   -0xFEC0C00, %l3
F00BB07C: 253c04fd                 sethi   -0xFEC0C00, %l2
F00BB080: d0042010                 ld      [%l0+0x10], %o0
F00BB084: 80a22000                 cmp     %o0, 0
F00BB088: 02800007                 be      loc_F00BB0A4
F00BB08C: 90122004                 bset    4, %o0
F00BB090: 40000132                 call    _zszread
F00BB094: 92102003                 mov     3, %o1
F00BB098: 80a22000                 cmp     %o0, 0
F00BB09C: 32800011                 bne,a   loc_F00BB0E0
F00BB0A0: 233c04fd                 sethi   -0xFEC0C00, %l1
F00BB0A4: d004e200                 ld      [%l3+0x200], %o0
F00BB0A8: a0042080                 inc     0x80, %l0
F00BB0AC: 80a40008                 cmp     %l0, %o0
F00BB0B0: 08800003                 bleu    loc_F00BB0BC
F00BB0B4: d004a1e8                 ld      [%l2+0x1E8], %o0
F00BB0B8: a0022040                 add     %o0, 0x40, %l0 ! '@'
F00BB0BC: 90046001                 add     %l1, 1, %o0
F00BB0C0: a2100008                 mov     %o0, %l1
F00BB0C4: 912a2010                 sll     %o0, 16, %o0
F00BB0C8: 913a2010                 sra     %o0, 16, %o0
F00BB0CC: 80a22001                 cmp     %o0, 1
F00BB0D0: 1480002c                 bg      locret_F00BB180
F00BB0D4: 01000000                 nop
F00BB0D8: 10bfffeb                 ba      loc_F00BB084
F00BB0DC: d0042010                 ld      [%l0+0x10], %o0
F00BB0E0: e02461f0                 st      %l0, [%l1+0x1F0]
F00BB0E4: d0042010                 ld      [%l0+0x10], %o0
F00BB0E8: 4000011c                 call    _zszread
F00BB0EC: 92102002                 mov     2, %o1
F00BB0F0: 808a2008                 btst    8, %o0
F00BB0F4: 02800005                 be      loc_F00BB108
F00BB0F8: 92100008                 mov     %o0, %o1
F00BB0FC: d00461f0                 ld      [%l1+0x1F0], %o0
F00BB100: 10800003                 ba      loc_F00BB10C
F00BB104: a0023fc0                 add     %o0, -0x40, %l0
F00BB108: e00461f0                 ld      [%l1+0x1F0], %l0
F00BB10C: 900a6006                 and     %o1, 6, %o0
F00BB110: 80a22002                 cmp     %o0, 2
F00BB114: 22800011                 be,a    loc_F00BB158
F00BB118: d004201c                 ld      [%l0+0x1C], %o0
F00BB11C: 14800007                 bg      loc_F00BB138
F00BB120: 80a22004                 cmp     %o0, 4
F00BB124: 80a22000                 cmp     %o0, 0
F00BB128: 2280000a                 be,a    loc_F00BB150
F00BB12C: d004201c                 ld      [%l0+0x1C], %o0
F00BB130: 10800013                 ba      loc_F00BB17C
F00BB134: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BB138: 0280000a                 be      loc_F00BB160
F00BB13C: 80a22006                 cmp     %o0, 6
F00BB140: 2280000b                 be,a    loc_F00BB16C
F00BB144: d004201c                 ld      [%l0+0x1C], %o0
F00BB148: 1080000d                 ba      loc_F00BB17C
F00BB14C: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BB150: 10800008                 ba      loc_F00BB170
F00BB154: d2022004                 ld      [%o0+4], %o1
F00BB158: 10800006                 ba      loc_F00BB170
F00BB15C: d2022008                 ld      [%o0+8], %o1
F00BB160: d004201c                 ld      [%l0+0x1C], %o0
F00BB164: 10800003                 ba      loc_F00BB170
F00BB168: d202200c                 ld      [%o0+0xC], %o1
F00BB16C: d2022010                 ld      [%o0+0x10], %o1
F00BB170: 9fc24000                 call    %o1
F00BB174: 90100010                 mov     %l0, %o0
F00BB178: 113c04fd                 sethi   -0xFEC0C00, %o0
F00BB17C: e02221e0                 st      %l0, [%o0+0x1E0]
F00BB180: 81c7e008                 ret
F00BB184: 81e80000                 restore
