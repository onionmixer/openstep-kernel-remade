F00671D8: 9de3bf98                 save    %sp, -0x68, %sp
F00671DC: e0062088                 ld      [%i0+0x88], %l0
F00671E0: b0042008                 add     %l0, 8, %i0
F00671E4: d0060000                 ld      [%i0], %o0
F00671E8: 80a22000                 cmp     %o0, 0
F00671EC: 12bffffe                 bne     loc_F00671E4
F00671F0: 01000000                 nop
F00671F4: 4000bf2d                 call    _simple_lock_try
F00671F8: 90100018                 mov     %i0, %o0
F00671FC: 80a22000                 cmp     %o0, 0
F0067200: 02bffff9                 be      loc_F00671E4
F0067204: 01000000                 nop
F0067208: d004200c                 ld      [%l0+0xC], %o0
F006720C: 80a22000                 cmp     %o0, 0
F0067210: 0280000a                 be      loc_F0067238
F0067214: b0102000                 mov     0, %i0
F0067218: f0042044                 ld      [%l0+0x44], %i0
F006721C: 80a62000                 cmp     %i0, 0
F0067220: 02800006                 be      loc_F0067238
F0067224: 80a63fff                 cmp     %i0, -1
F0067228: 02800004                 be      loc_F0067238
F006722C: 01000000                 nop
F0067230: 7fffc900                 call    _ipc_object_reference
F0067234: 90100018                 mov     %i0, %o0
F0067238: c0242008                 clr     [%l0+8]
F006723C: 81c7e008                 ret
F0067240: 81e80000                 restore
