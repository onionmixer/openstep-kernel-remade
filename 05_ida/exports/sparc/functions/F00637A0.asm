F00637A0: 9de3bf98                 save    %sp, -0x68, %sp
F00637A4: 90100018                 mov     %i0, %o0
F00637A8: 92100019                 mov     %i1, %o1
F00637AC: 80a22000                 cmp     %o0, 0
F00637B0: 12800004                 bne     loc_F00637C0
F00637B4: 9810001a                 mov     %i2, %o4
F00637B8: 10800009                 ba      locret_F00637DC
F00637BC: b0102004                 mov     4, %i0
F00637C0: 94102006                 mov     6, %o2
F00637C4: 7fffda52                 call    _ipc_object_copyin_compat
F00637C8: 96102001                 mov     1, %o3
F00637CC: 80a22000                 cmp     %o0, 0
F00637D0: 32800002                 bne,a   loc_F00637D8
F00637D4: 90102004                 mov     4, %o0
F00637D8: b0100008                 mov     %o0, %i0
F00637DC: 81c7e008                 ret
F00637E0: 81e80000                 restore
