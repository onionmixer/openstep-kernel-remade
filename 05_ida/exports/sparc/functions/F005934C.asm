F005934C: 9de3bf98                 save    %sp, -0x68, %sp
F0059350: 40003b48                 call    _kalloc
F0059354: 90102034                 mov     0x34, %o0 ! '4'
F0059358: 94920000                 orcc    %o0, %g0, %o2
F005935C: 1280000a                 bne     loc_F0059384
F0059360: 90102034                 mov     0x34, %o0 ! '4'
F0059364: 113c043d90122130         set     aDroppedDeadNam, %o0! "dropped dead-name (0x%08x, 0x%x)\n"
F005936C: 92100018                 mov     %i0, %o1
F0059370: 7ffeecba                 call    _printf
F0059374: 94100019                 mov     %i1, %o2
F0059378: 400007ae                 call    _ipc_port_release_sonce
F005937C: 90100018                 mov     %i0, %o0
F0059380: 3080001d                 ba,a    locret_F00593F4
F0059384: d022a008                 st      %o0, [%o2+8]
F0059388: c022a00c                 clr     [%o2+0xC]
F005938C: c022a010                 clr     [%o2+0x10]
F0059390: 113c04ef                 sethi   %hi(_ipc_notify_dead_name_template), %o0
F0059394: d2022370                 ld      [%o0+%lo(_ipc_notify_dead_name_template)], %o1
F0059398: d222a014                 st      %o1, [%o2+0x14]
F005939C: 90122370                 bset    %lo(_ipc_notify_dead_name_template), %o0
F00593A0: d2022004                 ld      [%o0+4], %o1
F00593A4: d222a018                 st      %o1, [%o2+0x18]
F00593A8: d2022008                 ld      [%o0+8], %o1
F00593AC: d222a01c                 st      %o1, [%o2+0x1C]
F00593B0: d202200c                 ld      [%o0+0xC], %o1
F00593B4: d222a020                 st      %o1, [%o2+0x20]
F00593B8: d2022010                 ld      [%o0+0x10], %o1
F00593BC: d222a024                 st      %o1, [%o2+0x24]
F00593C0: d2022014                 ld      [%o0+0x14], %o1
F00593C4: d222a028                 st      %o1, [%o2+0x28]
F00593C8: d2022018                 ld      [%o0+0x18], %o1
F00593CC: d222a02c                 st      %o1, [%o2+0x2C]
F00593D0: d002201c                 ld      [%o0+0x1C], %o0
F00593D4: d022a030                 st      %o0, [%o2+0x30]
F00593D8: f022a01c                 st      %i0, [%o2+0x1C]
F00593DC: f222a030                 st      %i1, [%o2+0x30]
F00593E0: 9010000a                 mov     %o2, %o0
F00593E4: 13000040                 sethi   0x10000, %o1
F00593E8: 94102000                 mov     0, %o2
F00593EC: 7ffffc24                 call    _ipc_mqueue_send
F00593F0: 96102000                 mov     0, %o3
F00593F4: 81c7e008                 ret
F00593F8: 81e80000                 restore
