F0063878: 9de3bf98                 save    %sp, -0x68, %sp
F006387C: 90100018                 mov     %i0, %o0
F0063880: 92100019                 mov     %i1, %o1
F0063884: 80a22000                 cmp     %o0, 0
F0063888: 12800004                 bne     loc_F0063898
F006388C: 9810001a                 mov     %i2, %o4
F0063890: 10800009                 ba      locret_F00638B4
F0063894: b0102004                 mov     4, %i0
F0063898: 94102005                 mov     5, %o2
F006389C: 7fffda1c                 call    _ipc_object_copyin_compat
F00638A0: 96102001                 mov     1, %o3
F00638A4: 80a22000                 cmp     %o0, 0
F00638A8: 32800002                 bne,a   loc_F00638B0
F00638AC: 90102004                 mov     4, %o0
F00638B0: b0100008                 mov     %o0, %i0
F00638B4: 81c7e008                 ret
F00638B8: 81e80000                 restore
