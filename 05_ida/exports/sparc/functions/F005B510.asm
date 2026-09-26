F005B510: 9de3bf90                 save    %sp, -0x70, %sp
F005B514: 80a62000                 cmp     %i0, 0
F005B518: 0280000f                 be      loc_F005B554
F005B51C: 90100019                 mov     %i1, %o0
F005B520: 80a63fff                 cmp     %i0, -1
F005B524: 0280000c                 be      loc_F005B554
F005B528: 92100018                 mov     %i0, %o1
F005B52C: 94102011                 mov     0x11, %o2
F005B530: 7ffffb16                 call    _ipc_object_copyout_compat
F005B534: 9607bff4                 add     %fp, var_C, %o3
F005B538: 80a22000                 cmp     %o0, 0
F005B53C: 22800008                 be,a    locret_F005B55C
F005B540: f007bff4                 ld      [%fp+var_C], %i0
F005B544: 7ffffef6                 call    _ipc_port_release_send
F005B548: 90100018                 mov     %i0, %o0
F005B54C: 10800003                 ba      loc_F005B558
F005B550: c027bff4                 clr     [%fp+var_C]
F005B554: f027bff4                 st      %i0, [%fp+var_C]
F005B558: f007bff4                 ld      [%fp+var_C], %i0
F005B55C: 81c7e008                 ret
F005B560: 81e80000                 restore
