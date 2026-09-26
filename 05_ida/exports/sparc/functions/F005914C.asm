F005914C: 9de3bf98                 save    %sp, -0x68, %sp
F0059150: 40003bc8                 call    _kalloc
F0059154: 90102034                 mov     0x34, %o0 ! '4'
F0059158: 94920000                 orcc    %o0, %g0, %o2
F005915C: 1280000c                 bne     loc_F005918C
F0059160: 90102034                 mov     0x34, %o0 ! '4'
F0059164: 113c043d901220b8         set     aDroppedPortDes, %o0! "dropped port-destroyed (0x%08x, 0x%08x)"...
F005916C: 92100018                 mov     %i0, %o1
F0059170: 7ffeed3a                 call    _printf
F0059174: 94100019                 mov     %i1, %o2
F0059178: 4000082e                 call    _ipc_port_release_sonce
F005917C: 90100018                 mov     %i0, %o0
F0059180: 4000084f                 call    _ipc_port_release_receive
F0059184: 90100019                 mov     %i1, %o0
F0059188: 3080001d                 ba,a    locret_F00591FC
F005918C: d022a008                 st      %o0, [%o2+8]
F0059190: c022a00c                 clr     [%o2+0xC]
F0059194: c022a010                 clr     [%o2+0x10]
F0059198: 113c04ef                 sethi   %hi(_ipc_notify_port_destroyed_template), %o0
F005919C: d20223f0                 ld      [%o0+%lo(_ipc_notify_port_destroyed_template)], %o1
F00591A0: d222a014                 st      %o1, [%o2+0x14]
F00591A4: 901223f0                 bset    %lo(_ipc_notify_port_destroyed_template), %o0
F00591A8: d2022004                 ld      [%o0+4], %o1
F00591AC: d222a018                 st      %o1, [%o2+0x18]
F00591B0: d2022008                 ld      [%o0+8], %o1
F00591B4: d222a01c                 st      %o1, [%o2+0x1C]
F00591B8: d202200c                 ld      [%o0+0xC], %o1
F00591BC: d222a020                 st      %o1, [%o2+0x20]
F00591C0: d2022010                 ld      [%o0+0x10], %o1
F00591C4: d222a024                 st      %o1, [%o2+0x24]
F00591C8: d2022014                 ld      [%o0+0x14], %o1
F00591CC: d222a028                 st      %o1, [%o2+0x28]
F00591D0: d2022018                 ld      [%o0+0x18], %o1
F00591D4: d222a02c                 st      %o1, [%o2+0x2C]
F00591D8: d002201c                 ld      [%o0+0x1C], %o0
F00591DC: d022a030                 st      %o0, [%o2+0x30]
F00591E0: f022a01c                 st      %i0, [%o2+0x1C]
F00591E4: f222a030                 st      %i1, [%o2+0x30]
F00591E8: 9010000a                 mov     %o2, %o0
F00591EC: 13000040                 sethi   0x10000, %o1
F00591F0: 94102000                 mov     0, %o2
F00591F4: 7ffffca2                 call    _ipc_mqueue_send
F00591F8: 96102000                 mov     0, %o3
F00591FC: 81c7e008                 ret
F0059200: 81e80000                 restore
