F006243C: 9de3bf90                 save    %sp, -0x70, %sp
F0062440: 80a62000                 cmp     %i0, 0
F0062444: 12800004                 bne     loc_F0062454
F0062448: 90100018                 mov     %i0, %o0
F006244C: 1080000d                 ba      locret_F0062480
F0062450: b0102010                 mov     0x10, %i0
F0062454: 92100019                 mov     %i1, %o1
F0062458: 7fffe589                 call    _ipc_right_lookup_write
F006245C: 9407bff4                 add     %fp, var_C, %o2
F0062460: 80a22000                 cmp     %o0, 0
F0062464: 32800007                 bne,a   locret_F0062480
F0062468: b0100008                 mov     %o0, %i0
F006246C: 90100018                 mov     %i0, %o0
F0062470: d407bff4                 ld      [%fp+var_C], %o2
F0062474: 7fffe751                 call    _ipc_right_destroy
F0062478: 92100019                 mov     %i1, %o1
F006247C: b0100008                 mov     %o0, %i0
F0062480: 81c7e008                 ret
F0062484: 81e80000                 restore
