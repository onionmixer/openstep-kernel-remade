F00622F8: 9de3bf90                 save    %sp, -0x70, %sp
F00622FC: 90960000                 orcc    %i0, %g0, %o0
F0062300: 12800004                 bne     loc_F0062310
F0062304: 9210001a                 mov     %i2, %o1
F0062308: 10800025                 ba      locret_F006239C
F006230C: b0102010                 mov     0x10, %i0
F0062310: 80a26000                 cmp     %o1, 0
F0062314: 02800021                 be      loc_F0062398
F0062318: 80a27fff                 cmp     %o1, -1
F006231C: 0280001f                 be      loc_F0062398
F0062320: 80a66003                 cmp     %i1, 3
F0062324: 02800012                 be      loc_F006236C
F0062328: 01000000                 nop
F006232C: 18800005                 bgu     loc_F0062340
F0062330: 80a66001                 cmp     %i1, 1
F0062334: 02800007                 be      loc_F0062350
F0062338: b0102012                 mov     0x12, %i0
F006233C: 30800018                 ba,a    locret_F006239C
F0062340: 80a66004                 cmp     %i1, 4
F0062344: 02800011                 be      loc_F0062388
F0062348: b0102012                 mov     0x12, %i0
F006234C: 30800014                 ba,a    locret_F006239C
F0062350: 7fffe1db                 call    _ipc_port_alloc_name
F0062354: 9407bff4                 add     %fp, var_C, %o2
F0062358: b0920000                 orcc    %o0, %g0, %i0
F006235C: 12800010                 bne     locret_F006239C
F0062360: d007bff4                 ld      [%fp+var_C], %o0
F0062364: c0220000                 clr     [%o0]
F0062368: 3080000d                 ba,a    locret_F006239C
F006236C: 7fffe4bd                 call    _ipc_pset_alloc_name
F0062370: 9407bff0                 add     %fp, var_10, %o2
F0062374: b0920000                 orcc    %o0, %g0, %i0
F0062378: 12800009                 bne     locret_F006239C
F006237C: d007bff0                 ld      [%fp+var_10], %o0
F0062380: c0220000                 clr     [%o0]
F0062384: 30800006                 ba,a    locret_F006239C
F0062388: 7fffdd0a                 call    _ipc_object_alloc_dead_name
F006238C: 01000000                 nop
F0062390: 10800003                 ba      locret_F006239C
F0062394: b0100008                 mov     %o0, %i0
F0062398: b0102012                 mov     0x12, %i0
F006239C: 81c7e008                 ret
F00623A0: 81e80000                 restore
