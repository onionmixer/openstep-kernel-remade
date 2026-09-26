F0062488: 9de3bf90                 save    %sp, -0x70, %sp
F006248C: 80a62000                 cmp     %i0, 0
F0062490: 12800004                 bne     loc_F00624A0
F0062494: 90100018                 mov     %i0, %o0
F0062498: 1080000d                 ba      locret_F00624CC
F006249C: b0102010                 mov     0x10, %i0
F00624A0: 92100019                 mov     %i1, %o1
F00624A4: 7fffe576                 call    _ipc_right_lookup_write
F00624A8: 9407bff4                 add     %fp, var_C, %o2
F00624AC: 80a22000                 cmp     %o0, 0
F00624B0: 32800007                 bne,a   locret_F00624CC
F00624B4: b0100008                 mov     %o0, %i0
F00624B8: 90100018                 mov     %i0, %o0
F00624BC: d407bff4                 ld      [%fp+var_C], %o2
F00624C0: 7fffe7f4                 call    _ipc_right_dealloc
F00624C4: 92100019                 mov     %i1, %o1
F00624C8: b0100008                 mov     %o0, %i0
F00624CC: 81c7e008                 ret
F00624D0: 81e80000                 restore
