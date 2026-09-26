F0048710: 9de3bf90                 save    %sp, -0x70, %sp
F0048714: 80a62000                 cmp     %i0, 0
F0048718: 0280000e                 be      loc_F0048750
F004871C: 113c0438                 sethi   %hi(_spec_vnodeops), %o0
F0048720: d206201c                 ld      [%i0+0x1C], %o1
F0048724: 901223c8                 bset    %lo(_spec_vnodeops), %o0
F0048728: 80a24008                 cmp     %o1, %o0
F004872C: 02800006                 be      loc_F0048744
F0048730: 113c0438                 sethi   %hi(_fifo_vnodeops), %o0
F0048734: 90122180                 bset    %lo(_fifo_vnodeops), %o0
F0048738: 80a24008                 cmp     %o1, %o0
F004873C: 12800005                 bne     loc_F0048750
F0048740: 80a62000                 cmp     %i0, 0
F0048744: d0062030                 ld      [%i0+0x30], %o0
F0048748: f0022038                 ld      [%o0+0x38], %i0
F004874C: 80a62000                 cmp     %i0, 0
F0048750: 02800009                 be      loc_F0048774
F0048754: 90100018                 mov     %i0, %o0
F0048758: d206201c                 ld      [%i0+0x1C], %o1
F004875C: d4026070                 ld      [%o1+0x70], %o2
F0048760: 9fc28000                 call    %o2
F0048764: 9207bff4                 add     %fp, var_C, %o1
F0048768: 80a22000                 cmp     %o0, 0
F004876C: 22800002                 be,a    loc_F0048774
F0048770: f007bff4                 ld      [%fp+var_C], %i0
F0048774: f0264000                 st      %i0, [%i1]
F0048778: 81c7e008                 ret
F004877C: 91e82000                 restore %g0, 0, %o0
