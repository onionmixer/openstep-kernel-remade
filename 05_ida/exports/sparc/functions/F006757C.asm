F006757C: 9de3bf98                 save    %sp, -0x68, %sp
F0067580: 80a62000                 cmp     %i0, 0
F0067584: 12800004                 bne     loc_F0067594
F0067588: 80a66002                 cmp     %i1, 2
F006758C: 10800026                 ba      locret_F0067624
F0067590: b0102004                 mov     4, %i0
F0067594: 0280000d                 be      loc_F00675C8
F0067598: 80a66002                 cmp     %i1, 2
F006759C: 14800007                 bg      loc_F00675B8
F00675A0: 80a66003                 cmp     %i1, 3
F00675A4: 80a66001                 cmp     %i1, 1
F00675A8: 02800009                 be      loc_F00675CC
F00675AC: a00620b0                 add     %i0, 0xB0, %l0
F00675B0: 1080001d                 ba      locret_F0067624
F00675B4: b0102004                 mov     4, %i0
F00675B8: 02800005                 be      loc_F00675CC
F00675BC: a00620b4                 add     %i0, 0xB4, %l0
F00675C0: 10800019                 ba      locret_F0067624
F00675C4: b0102004                 mov     4, %i0
F00675C8: a00620b8                 add     %i0, 0xB8, %l0
F00675CC: b20620a8                 add     %i0, 0xA8, %i1
F00675D0: d0064000                 ld      [%i1], %o0
F00675D4: 80a22000                 cmp     %o0, 0
F00675D8: 12bffffe                 bne     loc_F00675D0
F00675DC: 01000000                 nop
F00675E0: 4000be32                 call    _simple_lock_try
F00675E4: 90100019                 mov     %i1, %o0
F00675E8: 80a22000                 cmp     %o0, 0
F00675EC: 02bffff9                 be      loc_F00675D0
F00675F0: 01000000                 nop
F00675F4: d00620ac                 ld      [%i0+0xAC], %o0
F00675F8: 80a22000                 cmp     %o0, 0
F00675FC: 02800008                 be      loc_F006761C
F0067600: 01000000                 nop
F0067604: 7fffce8e                 call    _ipc_port_copy_send
F0067608: d0040000                 ld      [%l0], %o0
F006760C: c02620a8                 clr     [%i0+0xA8]
F0067610: d0268000                 st      %o0, [%i2]
F0067614: 10800004                 ba      locret_F0067624
F0067618: b0102000                 mov     0, %i0
F006761C: c02620a8                 clr     [%i0+0xA8]
F0067620: b0102005                 mov     5, %i0
F0067624: 81c7e008                 ret
F0067628: 81e80000                 restore
