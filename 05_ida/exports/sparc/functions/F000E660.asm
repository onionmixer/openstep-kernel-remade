F000E660: 9de3bf98                 save    %sp, -0x68, %sp
F000E664: b2100018                 mov     %i0, %i1
F000E668: 860e603f                 and     %i1, 0x3F, %g3
F000E66C: 053c04d18410a3b0         set     _pgrphash, %g2
F000E674: 8728e002                 sll     %g3, 2, %g3
F000E678: f000c002                 ld      [%g3+%g2], %i0
F000E67C: 80a62000                 cmp     %i0, 0
F000E680: 2280000b                 be,a    locret_F000E6AC
F000E684: b0102000                 mov     0, %i0
F000E688: c406200c                 ld      [%i0+0xC], %g2
F000E68C: 80a08019                 cmp     %g2, %i1
F000E690: 02800007                 be      locret_F000E6AC
F000E694: 01000000                 nop
F000E698: f0060000                 ld      [%i0], %i0
F000E69C: 80a62000                 cmp     %i0, 0
F000E6A0: 32bffffb                 bne,a   loc_F000E68C
F000E6A4: c406200c                 ld      [%i0+0xC], %g2
F000E6A8: b0102000                 mov     0, %i0
F000E6AC: 81c7e008                 ret
F000E6B0: 81e80000                 restore
