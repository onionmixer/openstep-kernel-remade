F000F144: 9de3bf98                 save    %sp, -0x68, %sp
F000F148: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F000F14C: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F000F150: e2022024                 ld      [%o0+0x24], %l1
F000F154: d0044000                 ld      [%l1], %o0
F000F158: 80a22000                 cmp     %o0, 0
F000F15C: 12800006                 bne     loc_F000F174
F000F160: a614a1dc                 or      %l2, %lo(dword_F0133DDC), %l3
F000F164: d004fffc                 ld      [%l3-4], %o0
F000F168: d0020000                 ld      [%o0], %o0
F000F16C: d0522030                 ldsh    [%o0+0x30], %o0
F000F170: d0244000                 st      %o0, [%l1]
F000F174: 7ffffcd3                 call    _pfind
F000F178: d0044000                 ld      [%l1], %o0
F000F17C: a0920000                 orcc    %o0, %g0, %l0
F000F180: 32800006                 bne,a   loc_F000F198
F000F184: d004fffc                 ld      [%l3-4], %o0
F000F188: d204a1dc                 ld      [%l2+0x1DC], %o1
F000F18C: 90102003                 mov     3, %o0
F000F190: 10800017                 ba      locret_F000F1EC
F000F194: d02a6038                 stb     %o0, [%o1+0x38]
F000F198: d254202c                 ldsh    [%l0+0x2C], %o1
F000F19C: d002201c                 ld      [%o0+0x1C], %o0
F000F1A0: d0522002                 ldsh    [%o0+2], %o0
F000F1A4: 80a24008                 cmp     %o1, %o0
F000F1A8: 0280000d                 be      loc_F000F1DC
F000F1AC: 80a22000                 cmp     %o0, 0
F000F1B0: 0280000c                 be      loc_F000F1E0
F000F1B4: 90100010                 mov     %l0, %o0
F000F1B8: 7ffffcae                 call    _inferior
F000F1BC: 90100010                 mov     %l0, %o0
F000F1C0: 80a22000                 cmp     %o0, 0
F000F1C4: 12800007                 bne     loc_F000F1E0
F000F1C8: 90100010                 mov     %l0, %o0
F000F1CC: d204a1dc                 ld      [%l2+0x1DC], %o1
F000F1D0: 90102001                 mov     1, %o0
F000F1D4: 10800006                 ba      locret_F000F1EC
F000F1D8: d02a6038                 stb     %o0, [%o1+0x38]
F000F1DC: 90100010                 mov     %l0, %o0
F000F1E0: d2046004                 ld      [%l1+4], %o1
F000F1E4: 7ffffd34                 call    _enterpgrp
F000F1E8: 94102000                 mov     0, %o2
F000F1EC: 81c7e008                 ret
F000F1F0: 81e80000                 restore
