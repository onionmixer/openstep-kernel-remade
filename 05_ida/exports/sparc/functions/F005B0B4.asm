F005B0B4: 9de3bf90                 save    %sp, -0x70, %sp
F005B0B8: 80a62000                 cmp     %i0, 0
F005B0BC: 02800014                 be      loc_F005B10C
F005B0C0: 90100019                 mov     %i1, %o0
F005B0C4: 80a63fff                 cmp     %i0, -1
F005B0C8: 02800011                 be      loc_F005B10C
F005B0CC: 92100018                 mov     %i0, %o1
F005B0D0: 94102011                 mov     0x11, %o2
F005B0D4: 96102001                 mov     1, %o3
F005B0D8: 7ffffb07                 call    _ipc_object_copyout
F005B0DC: 9807bff4                 add     %fp, var_C, %o4
F005B0E0: b2920000                 orcc    %o0, %g0, %i1
F005B0E4: 2280000c                 be,a    locret_F005B114
F005B0E8: f007bff4                 ld      [%fp+var_C], %i0
F005B0EC: 4000000c                 call    _ipc_port_release_send
F005B0F0: 90100018                 mov     %i0, %o0
F005B0F4: 80a66014                 cmp     %i1, 0x14
F005B0F8: 32800006                 bne,a   loc_F005B110
F005B0FC: c027bff4                 clr     [%fp+var_C]
F005B100: 90103fff                 mov     -1, %o0
F005B104: 10800003                 ba      loc_F005B110
F005B108: d027bff4                 st      %o0, [%fp+var_C]
F005B10C: f027bff4                 st      %i0, [%fp+var_C]
F005B110: f007bff4                 ld      [%fp+var_C], %i0
F005B114: 81c7e008                 ret
F005B118: 81e80000                 restore
