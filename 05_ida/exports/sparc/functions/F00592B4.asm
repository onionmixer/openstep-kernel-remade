F00592B4: 9de3bf98                 save    %sp, -0x68, %sp
F00592B8: 40003b6e                 call    _kalloc
F00592BC: 9010202c                 mov     0x2C, %o0 ! ','
F00592C0: 94920000                 orcc    %o0, %g0, %o2
F00592C4: 12800009                 bne     loc_F00592E8
F00592C8: 9010202c                 mov     0x2C, %o0 ! ','
F00592CC: 113c043d90122110         set     aDroppedSendOnc, %o0! "dropped send-once (0x%08x)\n"
F00592D4: 7ffeece1                 call    _printf
F00592D8: 92100018                 mov     %i0, %o1
F00592DC: 400007d5                 call    _ipc_port_release_sonce
F00592E0: 90100018                 mov     %i0, %o0
F00592E4: 30800018                 ba,a    locret_F0059344
F00592E8: d022a008                 st      %o0, [%o2+8]
F00592EC: c022a00c                 clr     [%o2+0xC]
F00592F0: c022a010                 clr     [%o2+0x10]
F00592F4: 113c04f0                 sethi   %hi(_ipc_notify_send_once_template), %o0
F00592F8: d2022010                 ld      [%o0+%lo(_ipc_notify_send_once_template)], %o1
F00592FC: d222a014                 st      %o1, [%o2+0x14]
F0059300: 90122010                 bset    %lo(_ipc_notify_send_once_template), %o0
F0059304: d2022004                 ld      [%o0+4], %o1
F0059308: d222a018                 st      %o1, [%o2+0x18]
F005930C: d2022008                 ld      [%o0+8], %o1
F0059310: d222a01c                 st      %o1, [%o2+0x1C]
F0059314: d202200c                 ld      [%o0+0xC], %o1
F0059318: d222a020                 st      %o1, [%o2+0x20]
F005931C: d2022010                 ld      [%o0+0x10], %o1
F0059320: d222a024                 st      %o1, [%o2+0x24]
F0059324: d0022014                 ld      [%o0+0x14], %o0
F0059328: d022a028                 st      %o0, [%o2+0x28]
F005932C: f022a01c                 st      %i0, [%o2+0x1C]
F0059330: 9010000a                 mov     %o2, %o0
F0059334: 13000040                 sethi   0x10000, %o1
F0059338: 94102000                 mov     0, %o2
F005933C: 7ffffc50                 call    _ipc_mqueue_send
F0059340: 96102000                 mov     0, %o3
F0059344: 81c7e008                 ret
F0059348: 81e80000                 restore
