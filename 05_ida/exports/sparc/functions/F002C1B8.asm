F002C1B8: 9de3bf98                 save    %sp, -0x68, %sp
F002C1BC: 113c04d0                 sethi   %hi(_ifnet), %o0
F002C1C0: e00220b8                 ld      [%o0+%lo(_ifnet)], %l0
F002C1C4: 80a42000                 cmp     %l0, 0
F002C1C8: 02800017                 be      loc_F002C224
F002C1CC: 01000000                 nop
F002C1D0: d804203c                 ld      [%l0+0x3C], %o4
F002C1D4: 80a32000                 cmp     %o4, 0
F002C1D8: 22800010                 be,a    loc_F002C218
F002C1DC: e004205c                 ld      [%l0+0x5C], %l0
F002C1E0: d0042014                 ld      [%l0+0x14], %o0
F002C1E4: 80a22000                 cmp     %o0, 0
F002C1E8: 2280000c                 be,a    loc_F002C218
F002C1EC: e004205c                 ld      [%l0+0x5C], %l0
F002C1F0: 90100010                 mov     %l0, %o0
F002C1F4: 92100018                 mov     %i0, %o1
F002C1F8: 94100019                 mov     %i1, %o2
F002C1FC: 9fc30000                 call    %o4
F002C200: 9610001a                 mov     %i2, %o3
F002C204: 80a22000                 cmp     %o0, 0
F002C208: 32800004                 bne,a   loc_F002C218
F002C20C: e004205c                 ld      [%l0+0x5C], %l0
F002C210: 10800008                 ba      locret_F002C230
F002C214: b0102000                 mov     0, %i0
F002C218: 80a42000                 cmp     %l0, 0
F002C21C: 32bfffee                 bne,a   loc_F002C1D4
F002C220: d804203c                 ld      [%l0+0x3C], %o4
F002C224: 7ffffe20                 call    _nb_free
F002C228: 90100019                 mov     %i1, %o0
F002C22C: b010202f                 mov     0x2F, %i0 ! '/'
F002C230: 81c7e008                 ret
F002C234: 81e80000                 restore
