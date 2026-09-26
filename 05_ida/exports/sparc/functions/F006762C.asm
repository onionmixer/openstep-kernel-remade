F006762C: 9de3bf98                 save    %sp, -0x68, %sp
F0067630: 80a62000                 cmp     %i0, 0
F0067634: 12800004                 bne     loc_F0067644
F0067638: 80a66002                 cmp     %i1, 2
F006763C: 1080002b                 ba      locret_F00676E8
F0067640: b0102004                 mov     4, %i0
F0067644: 0280000d                 be      loc_F0067678
F0067648: 80a66002                 cmp     %i1, 2
F006764C: 14800007                 bg      loc_F0067668
F0067650: 80a66003                 cmp     %i1, 3
F0067654: 80a66001                 cmp     %i1, 1
F0067658: 02800009                 be      loc_F006767C
F006765C: a00620b0                 add     %i0, 0xB0, %l0
F0067660: 10800022                 ba      locret_F00676E8
F0067664: b0102004                 mov     4, %i0
F0067668: 02800005                 be      loc_F006767C
F006766C: a00620b4                 add     %i0, 0xB4, %l0
F0067670: 1080001e                 ba      locret_F00676E8
F0067674: b0102004                 mov     4, %i0
F0067678: a00620b8                 add     %i0, 0xB8, %l0
F006767C: b20620a8                 add     %i0, 0xA8, %i1
F0067680: d0064000                 ld      [%i1], %o0
F0067684: 80a22000                 cmp     %o0, 0
F0067688: 12bffffe                 bne     loc_F0067680
F006768C: 01000000                 nop
F0067690: 4000be06                 call    _simple_lock_try
F0067694: 90100019                 mov     %i1, %o0
F0067698: 80a22000                 cmp     %o0, 0
F006769C: 02bffff9                 be      loc_F0067680
F00676A0: 01000000                 nop
F00676A4: d00620ac                 ld      [%i0+0xAC], %o0
F00676A8: 80a22000                 cmp     %o0, 0
F00676AC: 32800005                 bne,a   loc_F00676C0
F00676B0: d0040000                 ld      [%l0], %o0
F00676B4: c02620a8                 clr     [%i0+0xA8]
F00676B8: 1080000c                 ba      locret_F00676E8
F00676BC: b0102005                 mov     5, %i0
F00676C0: f4240000                 st      %i2, [%l0]
F00676C4: c02620a8                 clr     [%i0+0xA8]
F00676C8: 80a22000                 cmp     %o0, 0
F00676CC: 02800006                 be      loc_F00676E4
F00676D0: 80a23fff                 cmp     %o0, -1
F00676D4: 02800005                 be      locret_F00676E8
F00676D8: b0102000                 mov     0, %i0
F00676DC: 7fffce90                 call    _ipc_port_release_send
F00676E0: 01000000                 nop
F00676E4: b0102000                 mov     0, %i0
F00676E8: 81c7e008                 ret
F00676EC: 81e80000                 restore
