F00DAD98: 9de3bf90                 save    %sp, -0x70, %sp
F00DAD9C: d0062050                 ld      [%i0+0x50], %o0
F00DADA0: 80a22000                 cmp     %o0, 0
F00DADA4: 2280000b                 be,a    loc_F00DADD0
F00DADA8: c026c000                 clr     [%i3]
F00DADAC: d0062058                 ld      [%i0+0x58], %o0
F00DADB0: 40001e2f                 call    _audio_max_peak
F00DADB4: d2062054                 ld      [%i0+0x54], %o1
F00DADB8: d0268000                 st      %o0, [%i2]
F00DADBC: d006205c                 ld      [%i0+0x5C], %o0
F00DADC0: 40001e2b                 call    _audio_max_peak
F00DADC4: d2062054                 ld      [%i0+0x54], %o1
F00DADC8: 10800003                 ba      locret_F00DADD4
F00DADCC: d026c000                 st      %o0, [%i3]
F00DADD0: c0268000                 clr     [%i2]
F00DADD4: 81c7e008                 ret
F00DADD8: 81e80000                 restore
