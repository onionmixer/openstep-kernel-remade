F00539DC: 9de3bf90                 save    %sp, -0x70, %sp
F00539E0: 90062020                 add     %i0, 0x20, %o0 ! ' '
F00539E4: 92100019                 mov     %i1, %o1
F00539E8: 9407bff4                 add     %fp, var_C, %o2
F00539EC: 40002b7e                 call    _ipc_splay_tree_bounds
F00539F0: 9607bff0                 add     %fp, var_10, %o3
F00539F4: d007bff4                 ld      [%fp+var_C], %o0
F00539F8: b0102000                 mov     0, %i0
F00539FC: 80a23fff                 cmp     %o0, -1
F0053A00: 02800006                 be      loc_F0053A18
F0053A04: b3366008                 srl     %i1, 8, %i1
F0053A08: 91322008                 srl     %o0, 8, %o0
F0053A0C: 80a20019                 cmp     %o0, %i1
F0053A10: 22800009                 be,a    locret_F0053A34
F0053A14: b0102001                 mov     1, %i0
F0053A18: d007bff0                 ld      [%fp+var_10], %o0
F0053A1C: 80a22000                 cmp     %o0, 0
F0053A20: 02800005                 be      locret_F0053A34
F0053A24: 91322008                 srl     %o0, 8, %o0
F0053A28: 80a20019                 cmp     %o0, %i1
F0053A2C: 22800002                 be,a    locret_F0053A34
F0053A30: b0102001                 mov     1, %i0
F0053A34: 81c7e008                 ret
F0053A38: 81e80000                 restore
