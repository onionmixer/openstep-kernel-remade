F000A06C: 9de3bf90                 save    %sp, -0x70, %sp
F000A070: 400023c7                 call    _getthetime
F000A074: 9007bff0                 add     %fp, var_10, %o0
F000A078: d2060000                 ld      [%i0], %o1
F000A07C: d007bff0                 ld      [%fp+var_10], %o0
F000A080: a2224008                 sub     %o1, %o0, %l1
F000A084: 11000830901220b3         set     0x20C0B3, %o0
F000A08C: 80a44008                 cmp     %l1, %o0
F000A090: 34800017                 bg,a    loc_F000A0EC
F000A094: 113c043e                 sethi   -0xFEF0800, %o0
F000A098: 921023e8                 mov     0x3E8, %o1! int
F000A09C: a12c6005                 sll     %l1, 5, %l0
F000A0A0: a0240011                 sub     %l0, %l1, %l0
F000A0A4: a12c2002                 sll     %l0, 2, %l0
F000A0A8: d0062004                 ld      [%i0+4], %o0! int
F000A0AC: a0040011                 add     %l0, %l1, %l0
F000A0B0: d407bff4                 ld      [%fp+var_C], %o2
F000A0B4: a12c2003                 sll     %l0, 3, %l0
F000A0B8: 7ffff154                 call    _div
F000A0BC: 9022000a                 sub     %o0, %o2, %o0! int
F000A0C0: 921023e8                 mov     0x3E8, %o1! int
F000A0C4: 153c043e                 sethi   %hi(_tick), %o2
F000A0C8: 96100008                 mov     %o0, %o3
F000A0CC: d402a3e4                 ld      [%o2+%lo(_tick)], %o2
F000A0D0: a004000b                 add     %l0, %o3, %l0
F000A0D4: 7ffff14d                 call    _div
F000A0D8: 9010000a                 mov     %o2, %o0! int
F000A0DC: 92100008                 mov     %o0, %o1! int
F000A0E0: 7ffff14a                 call    _div
F000A0E4: 90100010                 mov     %l0, %o0
F000A0E8: 3080000c                 ba,a    locret_F000A118
F000A0EC: e00223e0                 ld      [%o0+0x3E0], %l0
F000A0F0: 311fffff901623ff         set     0x7FFFFFFF, %o0! int
F000A0F8: 7ffff144                 call    _div
F000A0FC: 92100010                 mov     %l0, %o1
F000A100: 80a44008                 cmp     %l1, %o0
F000A104: 14800005                 bg      locret_F000A118
F000A108: 901623ff                 or      %i0, 0x3FF, %o0
F000A10C: 90100011                 mov     %l1, %o0
F000A110: 7ffff0fc                 call    _umul
F000A114: 92100010                 mov     %l0, %o1
F000A118: 81c7e008                 ret
F000A11C: 91e80008                 restore %g0, %o0, %o0
