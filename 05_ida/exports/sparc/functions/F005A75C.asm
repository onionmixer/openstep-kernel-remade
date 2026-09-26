F005A75C: 9de3bf98                 save    %sp, -0x68, %sp
F005A760: e0062024                 ld      [%i0+0x24], %l0
F005A764: d006201c                 ld      [%i0+0x1C], %o0
F005A768: 80a22000                 cmp     %o0, 0
F005A76C: 1280000d                 bne     loc_F005A7A0
F005A770: d2062018                 ld      [%i0+0x18], %o1
F005A774: 80a64009                 cmp     %i1, %o1
F005A778: 1880000a                 bgu     loc_F005A7A0
F005A77C: 80a6a000                 cmp     %i2, 0
F005A780: 22800009                 be,a    loc_F005A7A4
F005A784: f4262024                 st      %i2, [%i0+0x24]
F005A788: c0262024                 clr     [%i0+0x24]
F005A78C: c0260000                 clr     [%i0]
F005A790: 7ffffa9d                 call    _ipc_notify_no_senders
F005A794: 9010001a                 mov     %i2, %o0
F005A798: 10800005                 ba      locret_F005A7AC
F005A79C: e026c000                 st      %l0, [%i3]
F005A7A0: f4262024                 st      %i2, [%i0+0x24]
F005A7A4: c0260000                 clr     [%i0]
F005A7A8: e026c000                 st      %l0, [%i3]
F005A7AC: 81c7e008                 ret
F005A7B0: 81e80000                 restore
