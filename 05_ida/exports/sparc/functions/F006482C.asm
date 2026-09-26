F006482C: 9de3bf98                 save    %sp, -0x68, %sp
F0064830: d0062014                 ld      [%i0+0x14], %o0
F0064834: 80a22012                 cmp     %o0, 0x12
F0064838: 32800011                 bne,a   loc_F006487C
F006483C: c026201c                 clr     [%i0+0x1C]
F0064840: d0062018                 ld      [%i0+0x18], %o0
F0064844: 80a22020                 cmp     %o0, 0x20 ! ' '
F0064848: 3280000d                 bne,a   loc_F006487C
F006484C: c026201c                 clr     [%i0+0x1C]
F0064850: d0062028                 ld      [%i0+0x28], %o0
F0064854: 80a229c4                 cmp     %o0, 0x9C4
F0064858: 32800009                 bne,a   loc_F006487C
F006485C: c026201c                 clr     [%i0+0x1C]
F0064860: d006202c                 ld      [%i0+0x2C], %o0
F0064864: 133c043e                 sethi   %hi(_exc_code_proto), %o1
F0064868: d20260d0                 ld      [%o1+%lo(_exc_code_proto)], %o1
F006486C: 80a20009                 cmp     %o0, %o1
F0064870: 22800007                 be,a    loc_F006488C
F0064874: d0062008                 ld      [%i0+8], %o0
F0064878: c026201c                 clr     [%i0+0x1C]
F006487C: 7fffc16b                 call    _ipc_kmsg_destroy
F0064880: 90100018                 mov     %i0, %o0
F0064884: 10800017                 ba      locret_F00648E0
F0064888: b0103ed3                 mov     -0x12D, %i0
F006488C: 80a22100                 cmp     %o0, 0x100
F0064890: 1280000d                 bne     loc_F00648C4
F0064894: e0062030                 ld      [%i0+0x30], %l0
F0064898: 133c04ef                 sethi   %hi(_ipc_kmsg_cache), %o1
F006489C: d0026348                 ld      [%o1+%lo(_ipc_kmsg_cache)], %o0
F00648A0: 80a22000                 cmp     %o0, 0
F00648A4: 32800009                 bne,a   loc_F00648C8
F00648A8: d2062008                 ld      [%i0+8], %o1
F00648AC: 1080000c                 ba      loc_F00648DC
F00648B0: f0226348                 st      %i0, [%o1+%lo(_ipc_kmsg_cache)]
F00648B4: 40000e3b                 call    _kfree
F00648B8: 90100018                 mov     %i0, %o0
F00648BC: 10800009                 ba      locret_F00648E0
F00648C0: b0100010                 mov     %l0, %i0
F00648C4: d2062008                 ld      [%i0+8], %o1
F00648C8: 80a26000                 cmp     %o1, 0
F00648CC: 14bffffa                 bg      loc_F00648B4
F00648D0: 01000000                 nop
F00648D4: 7fffc24b                 call    _ipc_kmsg_free
F00648D8: 90100018                 mov     %i0, %o0
F00648DC: b0100010                 mov     %l0, %i0
F00648E0: 81c7e008                 ret
F00648E4: 81e80000                 restore
