F006493C: 9de3bf90                 save    %sp, -0x70, %sp
F0064940: f227a048                 st      %i1, [%fp+arg_48]
F0064944: 113c04d0                 sethi   %hi(_active_threads), %o0
F0064948: e0022260                 ld      [%o0+%lo(_active_threads)], %l0
F006494C: f427a04c                 st      %i2, [%fp+arg_4C]
F0064950: 1104001090122005         set     0x10004005, %o0
F0064958: f20420c4                 ld      [%l0+0xC4], %i1
F006495C: 80a60008                 cmp     %i0, %o0
F0064960: 12800059                 bne     loc_F0064AC4
F0064964: b4066040                 add     %i1, 0x40, %i2 ! '@'
F0064968: a2100018                 mov     %i0, %l1
F006496C: d004218c                 ld      [%l0+0x18C], %o0
F0064970: 808a2003                 btst    3, %o0
F0064974: 02800024                 be      loc_F0064A04
F0064978: 80a66000                 cmp     %i1, 0
F006497C: 02800006                 be      loc_F0064994
F0064980: 80a67fff                 cmp     %i1, -1
F0064984: 22800005                 be,a    loc_F0064998
F0064988: c02420c4                 clr     [%l0+0xC4]
F006498C: 7fffd339                 call    _ipc_object_release
F0064990: 90100019                 mov     %i1, %o0
F0064994: c02420c4                 clr     [%l0+0xC4]
F0064998: b4102000                 mov     0, %i2
F006499C: 40004189                 call    _thread_halt_self_with_continuation
F00649A0: 90102000                 mov     0, %o0
F00649A4: b00420a8                 add     %l0, 0xA8, %i0
F00649A8: d0060000                 ld      [%i0], %o0
F00649AC: 80a22000                 cmp     %o0, 0
F00649B0: 12bffffe                 bne     loc_F00649A8
F00649B4: 01000000                 nop
F00649B8: 4000c93c                 call    _simple_lock_try
F00649BC: 90100018                 mov     %i0, %o0
F00649C0: 80a22000                 cmp     %o0, 0
F00649C4: 02bffff9                 be      loc_F00649A8
F00649C8: 01000000                 nop
F00649CC: d00420c0                 ld      [%l0+0xC0], %o0
F00649D0: b2920000                 orcc    %o0, %g0, %i1
F00649D4: 02800007                 be      loc_F00649F0
F00649D8: d02420c4                 st      %o0, [%l0+0xC4]
F00649DC: 80a67fff                 cmp     %i1, -1
F00649E0: 22800005                 be,a    loc_F00649F4
F00649E4: d004218c                 ld      [%l0+0x18C], %o0
F00649E8: 7fffd312                 call    _ipc_object_reference
F00649EC: b4066040                 add     %i1, 0x40, %i2 ! '@'
F00649F0: d004218c                 ld      [%l0+0x18C], %o0
F00649F4: c02420a8                 clr     [%l0+0xA8]
F00649F8: 808a2003                 btst    3, %o0
F00649FC: 12bfffe0                 bne     loc_F006497C
F0064A00: 80a66000                 cmp     %i1, 0
F0064A04: 02800054                 be      loc_F0064B54
F0064A08: 80a67fff                 cmp     %i1, -1
F0064A0C: 02800053                 be      loc_F0064B58
F0064A10: 11040010                 sethi   0x10004000, %o0
F0064A14: d0064000                 ld      [%i1], %o0
F0064A18: 80a22000                 cmp     %o0, 0
F0064A1C: 12bffffe                 bne     loc_F0064A14
F0064A20: 01000000                 nop
F0064A24: 4000c921                 call    _simple_lock_try
F0064A28: 90100019                 mov     %i1, %o0
F0064A2C: 80a22000                 cmp     %o0, 0
F0064A30: 02bffff9                 be      loc_F0064A14
F0064A34: 01000000                 nop
F0064A38: d0066008                 ld      [%i1+8], %o0
F0064A3C: 80a22000                 cmp     %o0, 0
F0064A40: 16800044                 bge     loc_F0064B50
F0064A44: 01000000                 nop
F0064A48: d0068000                 ld      [%i2], %o0
F0064A4C: 80a22000                 cmp     %o0, 0
F0064A50: 12bffffe                 bne     loc_F0064A48
F0064A54: 01000000                 nop
F0064A58: 4000c914                 call    _simple_lock_try
F0064A5C: 9010001a                 mov     %i2, %o0
F0064A60: 80a22000                 cmp     %o0, 0
F0064A64: 02bffff9                 be      loc_F0064A48
F0064A68: 01000000                 nop
F0064A6C: c0264000                 clr     [%i1]
F0064A70: d0042038                 ld      [%l0+0x38], %o0
F0064A74: 80a22000                 cmp     %o0, 0
F0064A78: 02800004                 be      loc_F0064A88
F0064A7C: 113c0192                 sethi   %hi(_exception_raise_continue), %o0
F0064A80: 10800003                 ba      loc_F0064A8C
F0064A84: 9a1220e8                 or      %o0, %lo(_exception_raise_continue), %o5
F0064A88: 9a102000                 mov     0, %o5
F0064A8C: 9007a048                 add     %fp, arg_48, %o0
F0064A90: d023a05c                 st      %o0, [%sp+0x70+var_14]
F0064A94: 9007a04c                 add     %fp, arg_4C, %o0
F0064A98: d023a060                 st      %o0, [%sp+0x70+var_10]
F0064A9C: 9010001a                 mov     %i2, %o0
F0064AA0: 92102000                 mov     0, %o1
F0064AA4: 94103fff                 mov     -1, %o2
F0064AA8: 96102000                 mov     0, %o3
F0064AAC: 7fffd003                 call    _ipc_mqueue_receive
F0064AB0: 98102000                 mov     0, %o4
F0064AB4: b0100008                 mov     %o0, %i0
F0064AB8: 80a60011                 cmp     %i0, %l1
F0064ABC: 22bfffad                 be,a    loc_F0064970
F0064AC0: d004218c                 ld      [%l0+0x18C], %o0
F0064AC4: 80a66000                 cmp     %i1, 0
F0064AC8: 02800006                 be      loc_F0064AE0
F0064ACC: 80a67fff                 cmp     %i1, -1
F0064AD0: 02800005                 be      loc_F0064AE4
F0064AD4: 80a62000                 cmp     %i0, 0
F0064AD8: 7fffd2e6                 call    _ipc_object_release
F0064ADC: 90100019                 mov     %i1, %o0
F0064AE0: 80a62000                 cmp     %i0, 0
F0064AE4: 12800007                 bne     loc_F0064B00
F0064AE8: 80a62000                 cmp     %i0, 0
F0064AEC: 7fffd9d1                 call    _ipc_port_release_sonce
F0064AF0: 90100019                 mov     %i1, %o0
F0064AF4: 7fffff4e                 call    _exception_parse_reply
F0064AF8: d007a048                 ld      [%fp+arg_48], %o0
F0064AFC: b0920000                 orcc    %o0, %g0, %i0
F0064B00: 02800006                 be      loc_F0064B18
F0064B04: 11040010                 sethi   0x10004000, %o0
F0064B08: 90122009                 bset    9, %o0
F0064B0C: 80a60008                 cmp     %i0, %o0
F0064B10: 32800009                 bne,a   loc_F0064B34
F0064B14: d00420c8                 ld      [%l0+0xC8], %o0
F0064B18: d0042038                 ld      [%l0+0x38], %o0
F0064B1C: 80a22000                 cmp     %o0, 0
F0064B20: 02800012                 be      locret_F0064B68
F0064B24: 01000000                 nop
F0064B28: 4000bfef                 call    _call_continuation
F0064B2C: 01000000                 nop
F0064B30: d00420c8                 ld      [%l0+0xC8], %o0
F0064B34: 80a22000                 cmp     %o0, 0
F0064B38: 0280000a                 be      loc_F0064B60
F0064B3C: 01000000                 nop
F0064B40: d20420cc                 ld      [%l0+0xCC], %o1
F0064B44: 7ffffd07                 call    _exception_try_task
F0064B48: d40420d0                 ld      [%l0+0xD0], %o2
F0064B4C: 30800007                 ba,a    locret_F0064B68
F0064B50: c0264000                 clr     [%i1]
F0064B54: 11040010                 sethi   0x10004000, %o0
F0064B58: 10bfffdb                 ba      loc_F0064AC4
F0064B5C: b0122009                 or      %o0, 9, %i0
F0064B60: 7ffffd3d                 call    _exception_no_server
F0064B64: 01000000                 nop
F0064B68: 81c7e008                 ret
F0064B6C: 81e80000                 restore
