F0058FEC: 9de3bf98                 save    %sp, -0x68, %sp
F0058FF0: 40003c20                 call    _kalloc
F0058FF4: 90102034                 mov     0x34, %o0 ! '4'
F0058FF8: 94920000                 orcc    %o0, %g0, %o2
F0058FFC: 1280000a                 bne     loc_F0059024
F0059000: 90102034                 mov     0x34, %o0 ! '4'
F0059004: 113c043d90122068         set     aDroppedPortDel, %o0! "dropped port-deleted (0x%08x, 0x%x)\n"
F005900C: 92100018                 mov     %i0, %o1
F0059010: 7ffeed92                 call    _printf
F0059014: 94100019                 mov     %i1, %o2
F0059018: 40000886                 call    _ipc_port_release_sonce
F005901C: 90100018                 mov     %i0, %o0
F0059020: 3080001d                 ba,a    locret_F0059094
F0059024: d022a008                 st      %o0, [%o2+8]
F0059028: c022a00c                 clr     [%o2+0xC]
F005902C: c022a010                 clr     [%o2+0x10]
F0059030: 113c04ef                 sethi   %hi(_ipc_notify_port_deleted_template), %o0
F0059034: d20223d0                 ld      [%o0+%lo(_ipc_notify_port_deleted_template)], %o1
F0059038: d222a014                 st      %o1, [%o2+0x14]
F005903C: 901223d0                 bset    %lo(_ipc_notify_port_deleted_template), %o0
F0059040: d2022004                 ld      [%o0+4], %o1
F0059044: d222a018                 st      %o1, [%o2+0x18]
F0059048: d2022008                 ld      [%o0+8], %o1
F005904C: d222a01c                 st      %o1, [%o2+0x1C]
F0059050: d202200c                 ld      [%o0+0xC], %o1
F0059054: d222a020                 st      %o1, [%o2+0x20]
F0059058: d2022010                 ld      [%o0+0x10], %o1
F005905C: d222a024                 st      %o1, [%o2+0x24]
F0059060: d2022014                 ld      [%o0+0x14], %o1
F0059064: d222a028                 st      %o1, [%o2+0x28]
F0059068: d2022018                 ld      [%o0+0x18], %o1
F005906C: d222a02c                 st      %o1, [%o2+0x2C]
F0059070: d002201c                 ld      [%o0+0x1C], %o0
F0059074: d022a030                 st      %o0, [%o2+0x30]
F0059078: f022a01c                 st      %i0, [%o2+0x1C]
F005907C: f222a030                 st      %i1, [%o2+0x30]
F0059080: 9010000a                 mov     %o2, %o0
F0059084: 13000040                 sethi   0x10000, %o1
F0059088: 94102000                 mov     0, %o2
F005908C: 7ffffcfc                 call    _ipc_mqueue_send
F0059090: 96102000                 mov     0, %o3
F0059094: 81c7e008                 ret
F0059098: 81e80000                 restore
