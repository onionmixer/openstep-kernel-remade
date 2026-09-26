F001A3F4: 9de3bf98                 save    %sp, -0x68, %sp
F001A3F8: e0064000                 ld      [%i1], %l0
F001A3FC: d2042040                 ld      [%l0+0x40], %o1
F001A400: 11000800                 sethi   0x200000, %o0
F001A404: 808a4008                 btst    %o0, %o1
F001A408: 32800007                 bne,a   loc_F001A424
F001A40C: d404203c                 ld      [%l0+0x3C], %o2
F001A410: d204203c                 ld      [%l0+0x3C], %o1
F001A414: 11002000                 sethi   0x800000, %o0
F001A418: 902a4008                 andn    %o1, %o0, %o0
F001A41C: d024203c                 st      %o0, [%l0+0x3C]
F001A420: d404203c                 ld      [%l0+0x3C], %o2
F001A424: 808aa008                 btst    8, %o2
F001A428: 32800009                 bne,a   loc_F001A44C
F001A42C: d2042040                 ld      [%l0+0x40], %o1
F001A430: d0066010                 ld      [%i1+0x10], %o0
F001A434: 808a2002                 btst    2, %o0
F001A438: 0280003b                 be      locret_F001A524
F001A43C: 80a6200a                 cmp     %i0, 0xA
F001A440: 12800039                 bne     locret_F001A524
F001A444: 01000000                 nop
F001A448: d2042040                 ld      [%l0+0x40], %o1
F001A44C: 11001000                 sethi   0x400000, %o0
F001A450: 808a4008                 btst    %o0, %o1
F001A454: 12800034                 bne     locret_F001A524
F001A458: 11040000                 sethi   0x10000000, %o0
F001A45C: 808a8008                 btst    %o0, %o2
F001A460: 02800018                 be      loc_F001A4C0
F001A464: 920e20ff                 and     %i0, 0xFF, %o1
F001A468: 80a2601f                 cmp     %o1, 0x1F
F001A46C: 14800006                 bg      loc_F001A484
F001A470: 80a2607f                 cmp     %o1, 0x7F
F001A474: 90063ff7                 add     %i0, -9, %o0
F001A478: 80a22001                 cmp     %o0, 1
F001A47C: 18800004                 bgu     loc_F001A48C
F001A480: 80a2607f                 cmp     %o1, 0x7F
F001A484: 32800010                 bne,a   loc_F001A4C4
F001A488: b00e20ff                 and     %i0, 0xFF, %i0
F001A48C: 9010205e                 mov     0x5E, %o0 ! '^'
F001A490: 7ffffac0                 call    _ttyoutput
F001A494: 92100010                 mov     %l0, %o1
F001A498: b00e20ff                 and     %i0, 0xFF, %i0
F001A49C: 80a6207f                 cmp     %i0, 0x7F
F001A4A0: 32800004                 bne,a   loc_F001A4B0
F001A4A4: d004203c                 ld      [%l0+0x3C], %o0
F001A4A8: 10800006                 ba      loc_F001A4C0
F001A4AC: b010203f                 mov     0x3F, %i0 ! '?'
F001A4B0: 808a2004                 btst    4, %o0
F001A4B4: 22800003                 be,a    loc_F001A4C0
F001A4B8: b0062040                 inc     0x40, %i0 ! '@'
F001A4BC: b0062060                 inc     0x60, %i0 ! '`'
F001A4C0: b00e20ff                 and     %i0, 0xFF, %i0
F001A4C4: 80a6201f                 cmp     %i0, 0x1F
F001A4C8: 0480000e                 ble     loc_F001A500
F001A4CC: 11020000                 sethi   0x8000000, %o0
F001A4D0: d204203c                 ld      [%l0+0x3C], %o1
F001A4D4: 808a4008                 btst    %o0, %o1
F001A4D8: 12800011                 bne     loc_F001A51C
F001A4DC: 90100018                 mov     %i0, %o0
F001A4E0: d2066010                 ld      [%i1+0x10], %o1
F001A4E4: 11001000                 sethi   0x400000, %o0
F001A4E8: 808a4008                 btst    %o0, %o1
F001A4EC: 1280000c                 bne     loc_F001A51C
F001A4F0: 90100018                 mov     %i0, %o0
F001A4F4: 80a6207e                 cmp     %i0, 0x7E ! '~'
F001A4F8: 04800009                 ble     loc_F001A51C
F001A4FC: 01000000                 nop
F001A500: 90063ff9                 add     %i0, -7, %o0
F001A504: 80a22003                 cmp     %o0, 3
F001A508: 08800004                 bleu    loc_F001A518
F001A50C: 80a6200d                 cmp     %i0, 0xD
F001A510: 12800005                 bne     locret_F001A524
F001A514: 01000000                 nop
F001A518: 90100018                 mov     %i0, %o0
F001A51C: 7ffffa9d                 call    _ttyoutput
F001A520: 92100010                 mov     %l0, %o1
F001A524: 81c7e008                 ret
F001A528: 81e80000                 restore
