F00634C4: 9de3bf90                 save    %sp, -0x70, %sp
F00634C8: 90960000                 orcc    %i0, %g0, %o0
F00634CC: 0280000c                 be      loc_F00634FC
F00634D0: 92100019                 mov     %i1, %o1
F00634D4: 7fffe04d                 call    _ipc_pset_alloc
F00634D8: 9407bff4                 add     %fp, var_C, %o2
F00634DC: b0920000                 orcc    %o0, %g0, %i0
F00634E0: 12800005                 bne     loc_F00634F4
F00634E4: 80a62006                 cmp     %i0, 6
F00634E8: d007bff4                 ld      [%fp+var_C], %o0
F00634EC: c0220000                 clr     [%o0]
F00634F0: 30800004                 ba,a    locret_F0063500
F00634F4: 02800003                 be      locret_F0063500
F00634F8: 01000000                 nop
F00634FC: b0102004                 mov     4, %i0
F0063500: 81c7e008                 ret
F0063504: 81e80000                 restore
