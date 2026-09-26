F00D053C: 9de3bf88                 save    %sp, -0x78, %sp
F00D0540: a0100018                 mov     %i0, %l0
F00D0544: d0042128                 ld      [%l0+0x128], %o0! id
F00D0548: 133c0504                 sethi   %hi(paNumberoftarget), %o1! SEL
F00D054C: 400084c9                 call    _objc_msgSend
F00D0550: d20261f0                 ld      [%o1+%lo(paNumberoftarget)], %o1
F00D0554: a20ea0ff                 and     %i2, 0xFF, %l1
F00D0558: 80a44008                 cmp     %l1, %o0
F00D055C: 16800029                 bge     locret_F00D0600
F00D0560: b0103d3e                 mov     -0x2C2, %i0
F00D0564: b00ee0ff                 and     %i3, 0xFF, %i0
F00D0568: 80a62008                 cmp     %i0, 8
F00D056C: 08800004                 bleu    loc_F00D057C
F00D0570: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D0574: 10800023                 ba      locret_F00D0600
F00D0578: b0103d3e                 mov     -0x2C2, %i0
F00D057C: d2022368                 ld      [%o0+0x368], %o1! SEL
F00D0580: 400084bc                 call    _objc_msgSend
F00D0584: 90100010                 mov     %l0, %o0
F00D0588: 96100011                 mov     %l1, %o3
F00D058C: 94102000                 mov     0, %o2
F00D0590: 9a100018                 mov     %i0, %o5
F00D0594: 98102000                 mov     0, %o4
F00D0598: d0042128                 ld      [%l0+0x128], %o0! id
F00D059C: 133c0506                 sethi   %hi(paReservescsi3ta), %o1
F00D05A0: d2026008                 ld      [%o1+%lo(paReservescsi3ta)], %o1! SEL
F00D05A4: 400084b3                 call    _objc_msgSend
F00D05A8: e023a05c                 st      %l0, [%sp+0x78+var_1C]
F00D05AC: 80a22000                 cmp     %o0, 0
F00D05B0: 02800007                 be      loc_F00D05CC
F00D05B4: 912f2018                 sll     %i4, 24, %o0
F00D05B8: 80a22000                 cmp     %o0, 0
F00D05BC: 12800007                 bne     loc_F00D05D8
F00D05C0: 920ea0ff                 and     %i2, 0xFF, %o1
F00D05C4: 1080000f                 ba      locret_F00D0600
F00D05C8: b0103d2b                 mov     -0x2D5, %i0
F00D05CC: 90102001                 mov     1, %o0
F00D05D0: d0242120                 st      %o0, [%l0+0x120]
F00D05D4: 920ea0ff                 and     %i2, 0xFF, %o1
F00D05D8: 90102000                 mov     0, %o0
F00D05DC: d03c2108                 std     %o0, [%l0+0x108]
F00D05E0: 920ee0ff                 and     %i3, 0xFF, %o1
F00D05E4: 90102000                 mov     0, %o0
F00D05E8: d03c2110                 std     %o0, [%l0+0x110]
F00D05EC: b0102000                 mov     0, %i0
F00D05F0: d0042124                 ld      [%l0+0x124], %o0
F00D05F4: 13200000                 sethi   0x80000000, %o1
F00D05F8: 90120009                 bset    %o1, %o0
F00D05FC: d0242124                 st      %o0, [%l0+0x124]
F00D0600: 81c7e008                 ret
F00D0604: 81e80000                 restore
