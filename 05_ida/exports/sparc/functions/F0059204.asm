F0059204: 9de3bf98                 save    %sp, -0x68, %sp
F0059208: 40003b9a                 call    _kalloc
F005920C: 90102034                 mov     0x34, %o0 ! '4'
F0059210: 94920000                 orcc    %o0, %g0, %o2
F0059214: 1280000a                 bne     loc_F005923C
F0059218: 90102034                 mov     0x34, %o0 ! '4'
F005921C: 113c043d901220e8         set     aDroppedNoSende, %o0! "dropped no-senders (0x%08x, %u)\n"
F0059224: 92100018                 mov     %i0, %o1
F0059228: 7ffeed0c                 call    _printf
F005922C: 94100019                 mov     %i1, %o2
F0059230: 40000800                 call    _ipc_port_release_sonce
F0059234: 90100018                 mov     %i0, %o0
F0059238: 3080001d                 ba,a    locret_F00592AC
F005923C: d022a008                 st      %o0, [%o2+8]
F0059240: c022a00c                 clr     [%o2+0xC]
F0059244: c022a010                 clr     [%o2+0x10]
F0059248: 113c04ef                 sethi   %hi(_ipc_notify_no_senders_template), %o0
F005924C: d20223b0                 ld      [%o0+%lo(_ipc_notify_no_senders_template)], %o1
F0059250: d222a014                 st      %o1, [%o2+0x14]
F0059254: 901223b0                 bset    %lo(_ipc_notify_no_senders_template), %o0
F0059258: d2022004                 ld      [%o0+4], %o1
F005925C: d222a018                 st      %o1, [%o2+0x18]
F0059260: d2022008                 ld      [%o0+8], %o1
F0059264: d222a01c                 st      %o1, [%o2+0x1C]
F0059268: d202200c                 ld      [%o0+0xC], %o1
F005926C: d222a020                 st      %o1, [%o2+0x20]
F0059270: d2022010                 ld      [%o0+0x10], %o1
F0059274: d222a024                 st      %o1, [%o2+0x24]
F0059278: d2022014                 ld      [%o0+0x14], %o1
F005927C: d222a028                 st      %o1, [%o2+0x28]
F0059280: d2022018                 ld      [%o0+0x18], %o1
F0059284: d222a02c                 st      %o1, [%o2+0x2C]
F0059288: d002201c                 ld      [%o0+0x1C], %o0
F005928C: d022a030                 st      %o0, [%o2+0x30]
F0059290: f022a01c                 st      %i0, [%o2+0x1C]
F0059294: f222a030                 st      %i1, [%o2+0x30]
F0059298: 9010000a                 mov     %o2, %o0
F005929C: 13000040                 sethi   0x10000, %o1
F00592A0: 94102000                 mov     0, %o2
F00592A4: 7ffffc76                 call    _ipc_mqueue_send
F00592A8: 96102000                 mov     0, %o3
F00592AC: 81c7e008                 ret
F00592B0: 81e80000                 restore
