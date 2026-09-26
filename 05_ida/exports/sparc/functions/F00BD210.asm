F00BD210: 9de3bf90                 save    %sp, -0x70, %sp
F00BD214: d0062110                 ld      [%i0+0x110], %o0
F00BD218: 80a22000                 cmp     %o0, 0
F00BD21C: 22800007                 be,a    loc_F00BD238
F00BD220: 90102004                 mov     4, %o0
F00BD224: d2020000                 ld      [%o0], %o1
F00BD228: 9fc24000                 call    %o1
F00BD22C: 01000000                 nop
F00BD230: c0262110                 clr     [%i0+0x110]
F00BD234: 90102004                 mov     4, %o0
F00BD238: d0262114                 st      %o0, [%i0+0x114]
F00BD23C: 81c7e008                 ret
F00BD240: 91e82000                 restore %g0, 0, %o0
