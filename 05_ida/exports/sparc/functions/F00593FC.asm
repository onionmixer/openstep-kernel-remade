F00593FC: 9de3bf98                 save    %sp, -0x68, %sp
F0059400: 40003b1c                 call    _kalloc
F0059404: 90102034                 mov     0x34, %o0 ! '4'
F0059408: 94920000                 orcc    %o0, %g0, %o2
F005940C: 1280000a                 bne     loc_F0059434
F0059410: 90102034                 mov     0x34, %o0 ! '4'
F0059414: 113c043d90122158         set     aDroppedPortDel_0, %o0! "dropped port-deleted-compat (0x%08x, 0x"...
F005941C: 92100018                 mov     %i0, %o1
F0059420: 7ffeec8e                 call    _printf
F0059424: 94100019                 mov     %i1, %o2
F0059428: 4000073d                 call    _ipc_port_release_send
F005942C: 90100018                 mov     %i0, %o0
F0059430: 3080001f                 ba,a    locret_F00594AC
F0059434: d022a008                 st      %o0, [%o2+8]
F0059438: c022a00c                 clr     [%o2+0xC]
F005943C: c022a010                 clr     [%o2+0x10]
F0059440: 113c04ef                 sethi   %hi(_ipc_notify_port_deleted_template), %o0
F0059444: d20223d0                 ld      [%o0+%lo(_ipc_notify_port_deleted_template)], %o1
F0059448: d222a014                 st      %o1, [%o2+0x14]
F005944C: 901223d0                 bset    %lo(_ipc_notify_port_deleted_template), %o0
F0059450: d2022004                 ld      [%o0+4], %o1
F0059454: d222a018                 st      %o1, [%o2+0x18]
F0059458: d2022008                 ld      [%o0+8], %o1
F005945C: d222a01c                 st      %o1, [%o2+0x1C]
F0059460: d202200c                 ld      [%o0+0xC], %o1
F0059464: d222a020                 st      %o1, [%o2+0x20]
F0059468: d2022010                 ld      [%o0+0x10], %o1
F005946C: d222a024                 st      %o1, [%o2+0x24]
F0059470: d2022014                 ld      [%o0+0x14], %o1
F0059474: d222a028                 st      %o1, [%o2+0x28]
F0059478: d2022018                 ld      [%o0+0x18], %o1
F005947C: d222a02c                 st      %o1, [%o2+0x2C]
F0059480: d002201c                 ld      [%o0+0x1C], %o0
F0059484: d022a030                 st      %o0, [%o2+0x30]
F0059488: 90102011                 mov     0x11, %o0
F005948C: d022a014                 st      %o0, [%o2+0x14]
F0059490: f022a01c                 st      %i0, [%o2+0x1C]
F0059494: f222a030                 st      %i1, [%o2+0x30]
F0059498: 9010000a                 mov     %o2, %o0
F005949C: 13000040                 sethi   0x10000, %o1
F00594A0: 94102000                 mov     0, %o2
F00594A4: 7ffffbf6                 call    _ipc_mqueue_send
F00594A8: 96102000                 mov     0, %o3
F00594AC: 81c7e008                 ret
F00594B0: 81e80000                 restore
