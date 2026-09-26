F00623A4: 9de3bf90                 save    %sp, -0x70, %sp
F00623A8: 90960000                 orcc    %i0, %g0, %o0
F00623AC: 12800004                 bne     loc_F00623BC
F00623B0: 9210001a                 mov     %i2, %o1
F00623B4: 10800020                 ba      locret_F0062434
F00623B8: b0102010                 mov     0x10, %i0
F00623BC: 80a66003                 cmp     %i1, 3
F00623C0: 02800013                 be      loc_F006240C
F00623C4: 01000000                 nop
F00623C8: 18800005                 bgu     loc_F00623DC
F00623CC: 80a66001                 cmp     %i1, 1
F00623D0: 02800008                 be      loc_F00623F0
F00623D4: b0102012                 mov     0x12, %i0
F00623D8: 30800017                 ba,a    locret_F0062434
F00623DC: 80a66004                 cmp     %i1, 4
F00623E0: 02800012                 be      loc_F0062428
F00623E4: 01000000                 nop
F00623E8: 10800013                 ba      locret_F0062434
F00623EC: b0102012                 mov     0x12, %i0
F00623F0: 7fffe19d                 call    _ipc_port_alloc
F00623F4: 9407bff4                 add     %fp, var_C, %o2
F00623F8: b0920000                 orcc    %o0, %g0, %i0
F00623FC: 1280000e                 bne     locret_F0062434
F0062400: d007bff4                 ld      [%fp+var_C], %o0
F0062404: c0220000                 clr     [%o0]
F0062408: 3080000b                 ba,a    locret_F0062434
F006240C: 7fffe47f                 call    _ipc_pset_alloc
F0062410: 9407bff0                 add     %fp, var_10, %o2
F0062414: b0920000                 orcc    %o0, %g0, %i0
F0062418: 12800007                 bne     locret_F0062434
F006241C: d007bff0                 ld      [%fp+var_10], %o0
F0062420: c0220000                 clr     [%o0]
F0062424: 30800004                 ba,a    locret_F0062434
F0062428: 7fffdccf                 call    _ipc_object_alloc_dead
F006242C: 01000000                 nop
F0062430: b0100008                 mov     %o0, %i0
F0062434: 81c7e008                 ret
F0062438: 81e80000                 restore
