F005909C: 9de3bf98                 save    %sp, -0x68, %sp
F00590A0: 40003bf4                 call    _kalloc
F00590A4: 90102034                 mov     0x34, %o0 ! '4'
F00590A8: 94920000                 orcc    %o0, %g0, %o2
F00590AC: 1280000a                 bne     loc_F00590D4
F00590B0: 90102034                 mov     0x34, %o0 ! '4'
F00590B4: 113c043d90122090         set     aDroppedMsgAcce, %o0! "dropped msg-accepted (0x%08x, 0x%x)\n"
F00590BC: 92100018                 mov     %i0, %o1
F00590C0: 7ffeed66                 call    _printf
F00590C4: 94100019                 mov     %i1, %o2
F00590C8: 4000085a                 call    _ipc_port_release_sonce
F00590CC: 90100018                 mov     %i0, %o0
F00590D0: 3080001d                 ba,a    locret_F0059144
F00590D4: d022a008                 st      %o0, [%o2+8]
F00590D8: c022a00c                 clr     [%o2+0xC]
F00590DC: c022a010                 clr     [%o2+0x10]
F00590E0: 113c04ef                 sethi   %hi(_ipc_notify_msg_accepted_template), %o0
F00590E4: d2022390                 ld      [%o0+%lo(_ipc_notify_msg_accepted_template)], %o1
F00590E8: d222a014                 st      %o1, [%o2+0x14]
F00590EC: 90122390                 bset    %lo(_ipc_notify_msg_accepted_template), %o0
F00590F0: d2022004                 ld      [%o0+4], %o1
F00590F4: d222a018                 st      %o1, [%o2+0x18]
F00590F8: d2022008                 ld      [%o0+8], %o1
F00590FC: d222a01c                 st      %o1, [%o2+0x1C]
F0059100: d202200c                 ld      [%o0+0xC], %o1
F0059104: d222a020                 st      %o1, [%o2+0x20]
F0059108: d2022010                 ld      [%o0+0x10], %o1
F005910C: d222a024                 st      %o1, [%o2+0x24]
F0059110: d2022014                 ld      [%o0+0x14], %o1
F0059114: d222a028                 st      %o1, [%o2+0x28]
F0059118: d2022018                 ld      [%o0+0x18], %o1
F005911C: d222a02c                 st      %o1, [%o2+0x2C]
F0059120: d002201c                 ld      [%o0+0x1C], %o0
F0059124: d022a030                 st      %o0, [%o2+0x30]
F0059128: f022a01c                 st      %i0, [%o2+0x1C]
F005912C: f222a030                 st      %i1, [%o2+0x30]
F0059130: 9010000a                 mov     %o2, %o0
F0059134: 13000040                 sethi   0x10000, %o1
F0059138: 94102000                 mov     0, %o2
F005913C: 7ffffcd0                 call    _ipc_mqueue_send
F0059140: 96102000                 mov     0, %o3
F0059144: 81c7e008                 ret
F0059148: 81e80000                 restore
