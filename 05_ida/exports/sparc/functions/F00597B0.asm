F00597B0: 9de3bf90                 save    %sp, -0x70, %sp
F00597B4: a0100018                 mov     %i0, %l0
F00597B8: 90100010                 mov     %l0, %o0
F00597BC: 92100019                 mov     %i1, %o1
F00597C0: 7fffe8fa                 call    _ipc_entry_alloc_name
F00597C4: 9407bff4                 add     %fp, var_C, %o2
F00597C8: 80a22000                 cmp     %o0, 0
F00597CC: 12800011                 bne     locret_F0059810
F00597D0: b0100008                 mov     %o0, %i0
F00597D4: 90100010                 mov     %l0, %o0
F00597D8: d407bff4                 ld      [%fp+var_C], %o2
F00597DC: 40000976                 call    _ipc_right_inuse
F00597E0: 92100019                 mov     %i1, %o1
F00597E4: 80a22000                 cmp     %o0, 0
F00597E8: 1280000a                 bne     locret_F0059810
F00597EC: b010200d                 mov     0xD, %i0
F00597F0: d007bff4                 ld      [%fp+var_C], %o0
F00597F4: 13000400                 sethi   0x100000, %o1
F00597F8: d4020000                 ld      [%o0], %o2
F00597FC: 92126001                 bset    1, %o1
F0059800: 94128009                 bset    %o1, %o2
F0059804: d4220000                 st      %o2, [%o0]
F0059808: c0242008                 clr     [%l0+8]
F005980C: b0102000                 mov     0, %i0
F0059810: 81c7e008                 ret
F0059814: 81e80000                 restore
