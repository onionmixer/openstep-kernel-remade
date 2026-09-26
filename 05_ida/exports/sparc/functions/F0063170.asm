F0063170: 9de3bf90                 save    %sp, -0x70, %sp
F0063174: 90960000                 orcc    %i0, %g0, %o0
F0063178: 0280000c                 be      loc_F00631A8
F006317C: 92100019                 mov     %i1, %o1
F0063180: 7fffe089                 call    _ipc_port_alloc_compat
F0063184: 9407bff4                 add     %fp, var_C, %o2
F0063188: b0920000                 orcc    %o0, %g0, %i0
F006318C: 12800005                 bne     loc_F00631A0
F0063190: 80a62006                 cmp     %i0, 6
F0063194: d007bff4                 ld      [%fp+var_C], %o0
F0063198: c0220000                 clr     [%o0]
F006319C: 30800004                 ba,a    locret_F00631AC
F00631A0: 02800003                 be      locret_F00631AC
F00631A4: 01000000                 nop
F00631A8: b0102004                 mov     4, %i0
F00631AC: 81c7e008                 ret
F00631B0: 81e80000                 restore
