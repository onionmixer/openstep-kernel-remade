F00CCE7C: 9de3bf90                 save    %sp, -0x70, %sp
F00CCE80: d0062138                 ld      [%i0+0x138], %o0
F00CCE84: 7ffd7ae3                 call    _nb_alloc
F00CCE88: 90022020                 inc     0x20, %o0 ! ' '
F00CCE8C: b0920000                 orcc    %o0, %g0, %i0
F00CCE90: 02800004                 be      locret_F00CCEA0
F00CCE94: 01000000                 nop
F00CCE98: 7ffd7b34                 call    _nb_shrink_top
F00CCE9C: 92102020                 mov     0x20, %o1 ! ' '
F00CCEA0: 81c7e008                 ret
F00CCEA4: 81e80000                 restore
