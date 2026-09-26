F005956C: 9de3bf98                 save    %sp, -0x68, %sp
F0059570: 40003ac0                 call    _kalloc
F0059574: 90102034                 mov     0x34, %o0 ! '4'
F0059578: 94920000                 orcc    %o0, %g0, %o2
F005957C: 1280000c                 bne     loc_F00595AC
F0059580: 90102034                 mov     0x34, %o0 ! '4'
F0059584: 113c043d901221b8         set     aDroppedPortDes_0, %o0! "dropped port-destroyed-compat (0x%08x, "...
F005958C: 92100018                 mov     %i0, %o1
F0059590: 7ffeec32                 call    _printf
F0059594: 94100019                 mov     %i1, %o2
F0059598: 400006e1                 call    _ipc_port_release_send
F005959C: 90100018                 mov     %i0, %o0
F00595A0: 40000747                 call    _ipc_port_release_receive
F00595A4: 90100019                 mov     %i1, %o0
F00595A8: 30800020                 ba,a    locret_F0059628
F00595AC: d022a008                 st      %o0, [%o2+8]
F00595B0: c022a00c                 clr     [%o2+0xC]
F00595B4: c022a010                 clr     [%o2+0x10]
F00595B8: 113c04ef                 sethi   %hi(_ipc_notify_port_destroyed_template), %o0
F00595BC: d20223f0                 ld      [%o0+%lo(_ipc_notify_port_destroyed_template)], %o1
F00595C0: d222a014                 st      %o1, [%o2+0x14]
F00595C4: 901223f0                 bset    %lo(_ipc_notify_port_destroyed_template), %o0
F00595C8: d2022004                 ld      [%o0+4], %o1
F00595CC: d222a018                 st      %o1, [%o2+0x18]
F00595D0: d2022008                 ld      [%o0+8], %o1
F00595D4: d222a01c                 st      %o1, [%o2+0x1C]
F00595D8: d202200c                 ld      [%o0+0xC], %o1
F00595DC: d222a020                 st      %o1, [%o2+0x20]
F00595E0: d2022010                 ld      [%o0+0x10], %o1
F00595E4: d222a024                 st      %o1, [%o2+0x24]
F00595E8: d2022014                 ld      [%o0+0x14], %o1
F00595EC: d222a028                 st      %o1, [%o2+0x28]
F00595F0: d2022018                 ld      [%o0+0x18], %o1
F00595F4: d222a02c                 st      %o1, [%o2+0x2C]
F00595F8: d002201c                 ld      [%o0+0x1C], %o0
F00595FC: d022a030                 st      %o0, [%o2+0x30]
F0059600: 1120000090122011         set     -0x7FFFFFEF, %o0
F0059608: d022a014                 st      %o0, [%o2+0x14]
F005960C: f022a01c                 st      %i0, [%o2+0x1C]
F0059610: f222a030                 st      %i1, [%o2+0x30]
F0059614: 9010000a                 mov     %o2, %o0
F0059618: 13000040                 sethi   0x10000, %o1
F005961C: 94102000                 mov     0, %o2
F0059620: 7ffffb97                 call    _ipc_mqueue_send
F0059624: 96102000                 mov     0, %o3
F0059628: 81c7e008                 ret
F005962C: 81e80000                 restore
