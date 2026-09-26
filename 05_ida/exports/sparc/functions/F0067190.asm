F0067190: 9de3bf90                 save    %sp, -0x70, %sp
F0067194: 113c04d0                 sethi   %hi(_active_threads), %o0
F0067198: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F006719C: d002200c                 ld      [%o0+0xC], %o0
F00671A0: 9207bff4                 add     %fp, var_C, %o1
F00671A4: d0022088                 ld      [%o0+0x88], %o0
F00671A8: 7fffce2f                 call    _ipc_port_alloc
F00671AC: 9407bff0                 add     %fp, var_10, %o2
F00671B0: 80a22000                 cmp     %o0, 0
F00671B4: 32800006                 bne,a   loc_F00671CC
F00671B8: c027bff4                 clr     [%fp+var_C]
F00671BC: d007bff0                 ld      [%fp+var_10], %o0
F00671C0: c0220000                 clr     [%o0]
F00671C4: 10800003                 ba      locret_F00671D0
F00671C8: f007bff4                 ld      [%fp+var_C], %i0
F00671CC: f007bff4                 ld      [%fp+var_C], %i0
F00671D0: 81c7e008                 ret
F00671D4: 81e80000                 restore
