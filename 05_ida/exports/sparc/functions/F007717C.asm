F007717C: 9de3bf98                 save    %sp, -0x68, %sp
F0077180: 40007e82                 call    _splusclock
F0077184: 01000000                 nop
F0077188: a2100008                 mov     %o0, %l1
F007718C: 113c04c3a0122320         set     dword_F0130F20, %l0
F0077194: d0040000                 ld      [%l0], %o0
F0077198: 80a22000                 cmp     %o0, 0
F007719C: 12bffffe                 bne     loc_F0077194
F00771A0: 01000000                 nop
F00771A4: 40007f41                 call    _simple_lock_try
F00771A8: 90100010                 mov     %l0, %o0
F00771AC: 80a22000                 cmp     %o0, 0
F00771B0: 02bffff9                 be      loc_F0077194
F00771B4: 01000000                 nop
F00771B8: d0062020                 ld      [%i0+0x20], %o0
F00771BC: 80a22000                 cmp     %o0, 0
F00771C0: 12800033                 bne     loc_F007728C
F00771C4: 113c04c3                 sethi   -0xFECF400, %o0
F00771C8: f226200c                 st      %i1, [%i0+0xC]
F00771CC: f43e2018                 std     %i2, [%i0+0x18]
F00771D0: 113c04c3                 sethi   %hi(dword_F0130F34), %o0
F00771D4: d4022334                 ld      [%o0+%lo(dword_F0130F34)], %o2
F00771D8: 96122334                 or      %o0, %lo(dword_F0130F34), %o3
F00771DC: 80a2800b                 cmp     %o2, %o3
F00771E0: 2280001b                 be,a    loc_F007724C
F00771E4: d402a004                 ld      [%o2+4], %o2
F00771E8: d202a018                 ld      [%o2+0x18], %o1
F00771EC: d0062018                 ld      [%i0+0x18], %o0
F00771F0: 80a24008                 cmp     %o1, %o0
F00771F4: 38800016                 bgu,a   loc_F007724C
F00771F8: d402a004                 ld      [%o2+4], %o2
F00771FC: 32800009                 bne,a   loc_F0077220
F0077200: d2062018                 ld      [%i0+0x18], %o1
F0077204: d202a01c                 ld      [%o2+0x1C], %o1
F0077208: d006201c                 ld      [%i0+0x1C], %o0
F007720C: 80a24008                 cmp     %o1, %o0
F0077210: 28800004                 bleu,a  loc_F0077220
F0077214: d2062018                 ld      [%i0+0x18], %o1
F0077218: 1080000d                 ba      loc_F007724C
F007721C: d402a004                 ld      [%o2+4], %o2
F0077220: d002a018                 ld      [%o2+0x18], %o0
F0077224: 80a24008                 cmp     %o1, %o0
F0077228: 32bfffed                 bne,a   loc_F00771DC
F007722C: d4028000                 ld      [%o2], %o2
F0077230: d206201c                 ld      [%i0+0x1C], %o1
F0077234: d002a01c                 ld      [%o2+0x1C], %o0
F0077238: 80a24008                 cmp     %o1, %o0
F007723C: 22800005                 be,a    loc_F0077250
F0077240: d0028000                 ld      [%o2], %o0
F0077244: 10bfffe6                 ba      loc_F00771DC
F0077248: d4028000                 ld      [%o2], %o2
F007724C: d0028000                 ld      [%o2], %o0
F0077250: d0260000                 st      %o0, [%i0]
F0077254: d4262004                 st      %o2, [%i0+4]
F0077258: d0028000                 ld      [%o2], %o0
F007725C: f0222004                 st      %i0, [%o0+4]
F0077260: f0228000                 st      %i0, [%o2]
F0077264: 90102002                 mov     2, %o0
F0077268: d0262020                 st      %o0, [%i0+0x20]
F007726C: 113c04c3                 sethi   %hi(dword_F0130F34), %o0
F0077270: d0022334                 ld      [%o0+%lo(dword_F0130F34)], %o0
F0077274: 80a20018                 cmp     %o0, %i0
F0077278: 32800005                 bne,a   loc_F007728C
F007727C: 113c04c3                 sethi   -0xFECF400, %o0
F0077280: 7ffffd2f                 call    sub_F007673C
F0077284: 90100018                 mov     %i0, %o0
F0077288: 113c04c3                 sethi   -0xFECF400, %o0
F007728C: c0222320                 clr     [%o0+0x320]
F0077290: 40007ea5                 call    _splx
F0077294: 90100011                 mov     %l1, %o0
F0077298: 81c7e008                 ret
F007729C: 81e80000                 restore
