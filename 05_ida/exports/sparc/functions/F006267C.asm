F006267C: 9de3bf90                 save    %sp, -0x70, %sp
F0062680: 90960000                 orcc    %i0, %g0, %o0
F0062684: 12800004                 bne     loc_F0062694
F0062688: 92100019                 mov     %i1, %o1
F006268C: 10800011                 ba      locret_F00626D0
F0062690: b0102010                 mov     0x10, %i0
F0062694: 80a6a010                 cmp     %i2, 0x10
F0062698: 1880000e                 bgu     locret_F00626D0
F006269C: b0102012                 mov     0x12, %i0
F00626A0: 94102001                 mov     1, %o2
F00626A4: 7fffdc0e                 call    _ipc_object_translate
F00626A8: 9607bff4                 add     %fp, var_C, %o3
F00626AC: 80a22000                 cmp     %o0, 0
F00626B0: 12800008                 bne     locret_F00626D0
F00626B4: b0100008                 mov     %o0, %i0
F00626B8: d007bff4                 ld      [%fp+var_C], %o0
F00626BC: 7fffe03e                 call    _ipc_port_set_qlimit
F00626C0: 9210001a                 mov     %i2, %o1
F00626C4: d007bff4                 ld      [%fp+var_C], %o0
F00626C8: b0102000                 mov     0, %i0
F00626CC: c0220000                 clr     [%o0]
F00626D0: 81c7e008                 ret
F00626D4: 81e80000                 restore
