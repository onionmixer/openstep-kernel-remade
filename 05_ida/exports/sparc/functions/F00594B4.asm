F00594B4: 9de3bf98                 save    %sp, -0x68, %sp
F00594B8: 40003aee                 call    _kalloc
F00594BC: 90102034                 mov     0x34, %o0 ! '4'
F00594C0: 94920000                 orcc    %o0, %g0, %o2
F00594C4: 1280000a                 bne     loc_F00594EC
F00594C8: 90102034                 mov     0x34, %o0 ! '4'
F00594CC: 113c043d90122188         set     aDroppedMsgAcce_0, %o0! "dropped msg-accepted-compat (0x%08x, 0x"...
F00594D4: 92100018                 mov     %i0, %o1
F00594D8: 7ffeec60                 call    _printf
F00594DC: 94100019                 mov     %i1, %o2
F00594E0: 4000070f                 call    _ipc_port_release_send
F00594E4: 90100018                 mov     %i0, %o0
F00594E8: 3080001f                 ba,a    locret_F0059564
F00594EC: d022a008                 st      %o0, [%o2+8]
F00594F0: c022a00c                 clr     [%o2+0xC]
F00594F4: c022a010                 clr     [%o2+0x10]
F00594F8: 113c04ef                 sethi   %hi(_ipc_notify_msg_accepted_template), %o0
F00594FC: d2022390                 ld      [%o0+%lo(_ipc_notify_msg_accepted_template)], %o1
F0059500: d222a014                 st      %o1, [%o2+0x14]
F0059504: 90122390                 bset    %lo(_ipc_notify_msg_accepted_template), %o0
F0059508: d2022004                 ld      [%o0+4], %o1
F005950C: d222a018                 st      %o1, [%o2+0x18]
F0059510: d2022008                 ld      [%o0+8], %o1
F0059514: d222a01c                 st      %o1, [%o2+0x1C]
F0059518: d202200c                 ld      [%o0+0xC], %o1
F005951C: d222a020                 st      %o1, [%o2+0x20]
F0059520: d2022010                 ld      [%o0+0x10], %o1
F0059524: d222a024                 st      %o1, [%o2+0x24]
F0059528: d2022014                 ld      [%o0+0x14], %o1
F005952C: d222a028                 st      %o1, [%o2+0x28]
F0059530: d2022018                 ld      [%o0+0x18], %o1
F0059534: d222a02c                 st      %o1, [%o2+0x2C]
F0059538: d002201c                 ld      [%o0+0x1C], %o0
F005953C: d022a030                 st      %o0, [%o2+0x30]
F0059540: 90102011                 mov     0x11, %o0
F0059544: d022a014                 st      %o0, [%o2+0x14]
F0059548: f022a01c                 st      %i0, [%o2+0x1C]
F005954C: f222a030                 st      %i1, [%o2+0x30]
F0059550: 9010000a                 mov     %o2, %o0
F0059554: 13000040                 sethi   0x10000, %o1
F0059558: 94102000                 mov     0, %o2
F005955C: 7ffffbc8                 call    _ipc_mqueue_send
F0059560: 96102000                 mov     0, %o3
F0059564: 81c7e008                 ret
F0059568: 81e80000                 restore
