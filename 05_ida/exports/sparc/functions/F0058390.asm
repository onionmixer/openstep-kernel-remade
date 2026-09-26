F0058390: 9de3bf98                 save    %sp, -0x68, %sp
F0058394: e2066004                 ld      [%i1+4], %l1
F0058398: a8062004                 add     %i0, 4, %l4
F005839C: b0062008                 inc     8, %i0
F00583A0: 80a46000                 cmp     %l1, 0
F00583A4: 02800029                 be      locret_F0058448
F00583A8: b2066004                 inc     4, %i1
F00583AC: 11040010a6122004         set     0x10004004, %l3
F00583B4: 90100019                 mov     %i1, %o0
F00583B8: 7ffff294                 call    _ipc_kmsg_queue_next
F00583BC: 92100011                 mov     %l1, %o1
F00583C0: d204601c                 ld      [%l1+0x1C], %o1
F00583C4: 80a2401a                 cmp     %o1, %i2
F00583C8: 1280001d                 bne     loc_F005843C
F00583CC: a4100008                 mov     %o0, %l2
F00583D0: 90100019                 mov     %i1, %o0
F00583D4: 7ffff27e                 call    _ipc_kmsg_rmqueue
F00583D8: 92100011                 mov     %l1, %o1
F00583DC: 40001a7a                 call    _ipc_thread_dequeue
F00583E0: 90100018                 mov     %i0, %o0
F00583E4: a0920000                 orcc    %o0, %g0, %l0
F00583E8: 22800013                 be,a    loc_F0058434
F00583EC: 90100014                 mov     %l4, %o0
F00583F0: 40003889                 call    _thread_go
F00583F4: 01000000                 nop
F00583F8: d2046018                 ld      [%l1+0x18], %o1
F00583FC: d004209c                 ld      [%l0+0x9C], %o0
F0058400: 80a24008                 cmp     %o1, %o0
F0058404: 38800009                 bgu,a   loc_F0058428
F0058408: e6242098                 st      %l3, [%l0+0x98]
F005840C: c0242098                 clr     [%l0+0x98]
F0058410: e224209c                 st      %l1, [%l0+0x9C]
F0058414: d206a034                 ld      [%i2+0x34], %o1
F0058418: 90026001                 add     %o1, 1, %o0
F005841C: d026a034                 st      %o0, [%i2+0x34]
F0058420: 10800007                 ba      loc_F005843C
F0058424: d22420a0                 st      %o1, [%l0+0xA0]
F0058428: d0046018                 ld      [%l1+0x18], %o0
F005842C: 10bfffec                 ba      loc_F00583DC
F0058430: d024209c                 st      %o0, [%l0+0x9C]
F0058434: 7ffff246                 call    _ipc_kmsg_enqueue
F0058438: 92100011                 mov     %l1, %o1
F005843C: a2948000                 orcc    %l2, %g0, %l1
F0058440: 12bfffde                 bne     loc_F00583B8
F0058444: 90100019                 mov     %i1, %o0
F0058448: 81c7e008                 ret
F005844C: 81e80000                 restore
