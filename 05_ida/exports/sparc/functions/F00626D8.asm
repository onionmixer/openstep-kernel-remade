F00626D8: 9de3bf90                 save    %sp, -0x70, %sp
F00626DC: 90960000                 orcc    %i0, %g0, %o0
F00626E0: 12800004                 bne     loc_F00626F0
F00626E4: 92100019                 mov     %i1, %o1
F00626E8: 1080000c                 ba      locret_F0062718
F00626EC: b0102010                 mov     0x10, %i0
F00626F0: 94102001                 mov     1, %o2
F00626F4: 7fffdbfa                 call    _ipc_object_translate
F00626F8: 9607bff4                 add     %fp, var_C, %o3
F00626FC: 80a22000                 cmp     %o0, 0
F0062700: 12800006                 bne     locret_F0062718
F0062704: b0100008                 mov     %o0, %i0
F0062708: d007bff4                 ld      [%fp+var_C], %o0
F006270C: f4222018                 st      %i2, [%o0+0x18]
F0062710: c0220000                 clr     [%o0]
F0062714: b0102000                 mov     0, %i0
F0062718: 81c7e008                 ret
F006271C: 81e80000                 restore
