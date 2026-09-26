F000B058: 9de3bf98                 save    %sp, -0x68, %sp
F000B05C: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000B060: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F000B064: d0022024                 ld      [%o0+0x24], %o0
F000B068: a41261dc                 or      %o1, %lo(dword_F0133DDC), %l2
F000B06C: d204bffc                 ld      [%l2-4], %o1
F000B070: e0020000                 ld      [%o0], %l0
F000B074: d0026158                 ld      [%o1+0x158], %o0
F000B078: 80a40008                 cmp     %l0, %o0
F000B07C: 1a80000a                 bcc     loc_F000B0A4
F000B080: a72c2002                 sll     %l0, 2, %l3
F000B084: d002614c                 ld      [%o1+0x14C], %o0
F000B088: e2020013                 ld      [%o0+%l3], %l1
F000B08C: 80a46000                 cmp     %l1, 0
F000B090: 02800005                 be      loc_F000B0A4
F000B094: 113fffc0                 sethi   -0x10000, %o0
F000B098: 80a44008                 cmp     %l1, %o0
F000B09C: 12800007                 bne     loc_F000B0B8
F000B0A0: 01000000                 nop
F000B0A4: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000B0A8: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000B0AC: 90102009                 mov     9, %o0
F000B0B0: 1080003d                 ba      locret_F000B1A4
F000B0B4: d02a6038                 stb     %o0, [%o1+0x38]
F000B0B8: 40006d2f                 call    _vno_lockrelease
F000B0BC: 90100011                 mov     %l1, %o0
F000B0C0: d004bffc                 ld      [%l2-4], %o0
F000B0C4: d2022150                 ld      [%o0+0x150], %o1
F000B0C8: d00a4010                 ldub    [%o1+%l0], %o0
F000B0CC: 808a2002                 btst    2, %o0
F000B0D0: 02800004                 be      loc_F000B0E0
F000B0D4: a8024010                 add     %o1, %l0, %l4
F000B0D8: 40000c82                 call    _munmapfd
F000B0DC: 90100010                 mov     %l0, %o0
F000B0E0: d004bffc                 ld      [%l2-4], %o0
F000B0E4: d002214c                 ld      [%o0+0x14C], %o0
F000B0E8: c0220013                 clr     [%o0+%l3]
F000B0EC: d204bffc                 ld      [%l2-4], %o1
F000B0F0: d4026154                 ld      [%o1+0x154], %o2
F000B0F4: 80a2a000                 cmp     %o2, 0
F000B0F8: 26800018                 bl,a    loc_F000B158
F000B0FC: c02d0000                 clrb    [%l4]
F000B100: d002614c                 ld      [%o1+0x14C], %o0
F000B104: 932aa002                 sll     %o2, 2, %o1
F000B108: d0020009                 ld      [%o0+%o1], %o0
F000B10C: 80a22000                 cmp     %o0, 0
F000B110: 32800012                 bne,a   loc_F000B158
F000B114: c02d0000                 clrb    [%l4]
F000B118: 153c04cf                 sethi   %hi(_active_u), %o2
F000B11C: d202a1d8                 ld      [%o2+%lo(_active_u)], %o1
F000B120: d0026154                 ld      [%o1+0x154], %o0
F000B124: 90023fff                 inc     -1, %o0
F000B128: d0226154                 st      %o0, [%o1+0x154]
F000B12C: d002a1d8                 ld      [%o2+0x1D8], %o0
F000B130: d2022154                 ld      [%o0+0x154], %o1
F000B134: 80a26000                 cmp     %o1, 0
F000B138: 06800007                 bl      loc_F000B154
F000B13C: 932a6002                 sll     %o1, 2, %o1
F000B140: d002214c                 ld      [%o0+0x14C], %o0
F000B144: d0020009                 ld      [%o0+%o1], %o0
F000B148: 80a22000                 cmp     %o0, 0
F000B14C: 02bffff5                 be      loc_F000B120
F000B150: d202a1d8                 ld      [%o2+0x1D8], %o1
F000B154: c02d0000                 clrb    [%l4]
F000B158: 400000e2                 call    _closef
F000B15C: 90100011                 mov     %l1, %o0
F000B160: 153c04cf                 sethi   %hi(_active_u), %o2
F000B164: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F000B168: d0020000                 ld      [%o0], %o0
F000B16C: d2022014                 ld      [%o0+0x14], %o1
F000B170: 11000010                 sethi   0x4000, %o0
F000B174: 808a4008                 btst    %o0, %o1
F000B178: 0280000b                 be      locret_F000B1A4
F000B17C: 9412a1d8                 bset    %lo(_active_u), %o2
F000B180: d402a004                 ld      [%o2+4], %o2
F000B184: d04aa038                 ldsb    [%o2+0x38], %o0
F000B188: 80a2201c                 cmp     %o0, 0x1C
F000B18C: 12800006                 bne     locret_F000B1A4
F000B190: 11000004                 sethi   0x1000, %o0
F000B194: d2046008                 ld      [%l1+8], %o1
F000B198: 808a4008                 btst    %o0, %o1
F000B19C: 32800002                 bne,a   locret_F000B1A4
F000B1A0: c02aa038                 clrb    [%o2+0x38]
F000B1A4: 81c7e008                 ret
F000B1A8: 81e80000                 restore
