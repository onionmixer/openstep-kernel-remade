F0066938: 9de3bf98                 save    %sp, -0x68, %sp
F006693C: 4000c093                 call    _splusclock
F0066940: a006a020                 add     %i2, 0x20, %l0 ! ' '
F0066944: a2100008                 mov     %o0, %l1
F0066948: d0040000                 ld      [%l0], %o0
F006694C: 80a22000                 cmp     %o0, 0
F0066950: 12bffffe                 bne     loc_F0066948
F0066954: 01000000                 nop
F0066958: 4000c154                 call    _simple_lock_try
F006695C: 90100010                 mov     %l0, %o0
F0066960: 80a22000                 cmp     %o0, 0
F0066964: 02bffff9                 be      loc_F0066948
F0066968: 133c04f0                 sethi   %hi(_active_stacks), %o1
F006696C: d0062030                 ld      [%i0+0x30], %o0
F0066970: d2026058                 ld      [%o1+%lo(_active_stacks)], %o1
F0066974: 80a20009                 cmp     %o0, %o1
F0066978: 02800006                 be      loc_F0066990
F006697C: 01000000                 nop
F0066980: d006a04c                 ld      [%i2+0x4C], %o0
F0066984: 80a22101                 cmp     %o0, 0x101
F0066988: 2280000b                 be,a    loc_F00669B4
F006698C: d006a14c                 ld      [%i2+0x14C], %o0
F0066990: c026a020                 clr     [%i2+0x20]
F0066994: 4000c0e4                 call    _splx
F0066998: 90100011                 mov     %l1, %o0
F006699C: 133c043e                 sethi   %hi(_c_thread_handoff_misses), %o1
F00669A0: d00260b8                 ld      [%o1+%lo(_c_thread_handoff_misses)], %o0
F00669A4: b0102000                 mov     0, %i0
F00669A8: 90022001                 inc     %o0
F00669AC: 10800040                 ba      locret_F0066AAC
F00669B0: d02260b8                 st      %o0, [%o1+%lo(_c_thread_handoff_misses)]
F00669B4: 80a22000                 cmp     %o0, 0
F00669B8: 22800005                 be,a    loc_F00669CC
F00669BC: 90102004                 mov     4, %o0
F00669C0: 40000c25                 call    _reset_timeout
F00669C4: 9006a118                 add     %i2, 0x118, %o0
F00669C8: 90102004                 mov     4, %o0
F00669CC: d026a04c                 st      %o0, [%i2+0x4C]
F00669D0: c026a020                 clr     [%i2+0x20]
F00669D4: 133c04cf                 sethi   %hi(_need_ast), %o1
F00669D8: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F00669DC: d406a18c                 ld      [%i2+0x18C], %o2
F00669E0: 900a3ffc                 and     %o0, -4, %o0
F00669E4: 9012000a                 bset    %o2, %o0
F00669E8: d0226160                 st      %o0, [%o1+%lo(_need_ast)]
F00669EC: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F00669F0: 7ffe9d05                 call    _switch_unix_context
F00669F4: 9010001a                 mov     %i2, %o0
F00669F8: 90100018                 mov     %i0, %o0
F00669FC: 4000d52a                 call    _stack_handoff
F0066A00: 9210001a                 mov     %i2, %o1
F0066A04: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0066A08: d0040000                 ld      [%l0], %o0
F0066A0C: 80a22000                 cmp     %o0, 0
F0066A10: 12bffffe                 bne     loc_F0066A08
F0066A14: 01000000                 nop
F0066A18: 4000c124                 call    _simple_lock_try
F0066A1C: 90100010                 mov     %l0, %o0
F0066A20: 80a22000                 cmp     %o0, 0
F0066A24: 02bffff9                 be      loc_F0066A08
F0066A28: 01000000                 nop
F0066A2C: d006204c                 ld      [%i0+0x4C], %o0
F0066A30: 80a22004                 cmp     %o0, 4
F0066A34: 12800005                 bne     loc_F0066A48
F0066A38: f2262034                 st      %i1, [%i0+0x34]
F0066A3C: 90102101                 mov     0x101, %o0
F0066A40: 10800013                 ba      loc_F0066A8C
F0066A44: d026204c                 st      %o0, [%i0+0x4C]
F0066A48: 80a22006                 cmp     %o0, 6
F0066A4C: 1280000e                 bne     loc_F0066A84
F0066A50: 113c043e                 sethi   -0xFEF0800, %o0
F0066A54: 90102103                 mov     0x103, %o0
F0066A58: d2062048                 ld      [%i0+0x48], %o1
F0066A5C: 80a26000                 cmp     %o1, 0
F0066A60: 0280000b                 be      loc_F0066A8C
F0066A64: d026204c                 st      %o0, [%i0+0x4C]
F0066A68: c0262048                 clr     [%i0+0x48]
F0066A6C: c0262020                 clr     [%i0+0x20]
F0066A70: 90062048                 add     %i0, 0x48, %o0 ! 'H'! char *
F0066A74: 92102000                 mov     0, %o1
F0066A78: 40002961                 call    _thread_wakeup_prim
F0066A7C: 94102000                 mov     0, %o2
F0066A80: 30800004                 ba,a    loc_F0066A90
F0066A84: 7ffeb9bb                 call    _panic
F0066A88: 90122240                 bset    0x240, %o0
F0066A8C: c0262020                 clr     [%i0+0x20]
F0066A90: 4000c0a5                 call    _splx
F0066A94: 90100011                 mov     %l1, %o0
F0066A98: 133c043e                 sethi   %hi(_c_thread_handoff_hits), %o1
F0066A9C: d00260b4                 ld      [%o1+%lo(_c_thread_handoff_hits)], %o0
F0066AA0: b0102001                 mov     1, %i0
F0066AA4: 90022001                 inc     %o0
F0066AA8: d02260b4                 st      %o0, [%o1+%lo(_c_thread_handoff_hits)]
F0066AAC: 81c7e008                 ret
F0066AB0: 81e80000                 restore
