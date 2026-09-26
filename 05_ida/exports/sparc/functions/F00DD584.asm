F00DD584: 9de3bf90                 save    %sp, -0x70, %sp
F00DD588: d04e2094                 ldsb    [%i0+0x94], %o0
F00DD58C: 80a22000                 cmp     %o0, 0
F00DD590: 2280000b                 be,a    loc_F00DD5BC
F00DD594: c026c000                 clr     [%i3]
F00DD598: d006209c                 ld      [%i0+0x9C], %o0
F00DD59C: 40001434                 call    _audio_max_peak
F00DD5A0: d2062098                 ld      [%i0+0x98], %o1
F00DD5A4: d0268000                 st      %o0, [%i2]
F00DD5A8: d00620a0                 ld      [%i0+0xA0], %o0
F00DD5AC: 40001430                 call    _audio_max_peak
F00DD5B0: d2062098                 ld      [%i0+0x98], %o1
F00DD5B4: 10800003                 ba      locret_F00DD5C0
F00DD5B8: d026c000                 st      %o0, [%i3]
F00DD5BC: c0268000                 clr     [%i2]
F00DD5C0: 81c7e008                 ret
F00DD5C4: 81e80000                 restore
