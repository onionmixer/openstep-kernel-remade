F00637E4: 9de3bf98                 save    %sp, -0x68, %sp
F00637E8: 90100018                 mov     %i0, %o0
F00637EC: 92100019                 mov     %i1, %o1
F00637F0: 80a22000                 cmp     %o0, 0
F00637F4: 0280000b                 be      loc_F0063820
F00637F8: 9610001a                 mov     %i2, %o3
F00637FC: 80a2e000                 cmp     %o3, 0
F0063800: 02800008                 be      loc_F0063820
F0063804: 80a2ffff                 cmp     %o3, -1
F0063808: 02800006                 be      loc_F0063820
F006380C: 80a26000                 cmp     %o1, 0
F0063810: 02800004                 be      loc_F0063820
F0063814: 80a27fff                 cmp     %o1, -1
F0063818: 12800004                 bne     loc_F0063828
F006381C: 01000000                 nop
F0063820: 10800014                 ba      locret_F0063870
F0063824: b0102004                 mov     4, %i0
F0063828: 7fffdac9                 call    _ipc_object_copyout_name_compat
F006382C: 94102010                 mov     0x10, %o2
F0063830: 80a22006                 cmp     %o0, 6
F0063834: 0280000f                 be      locret_F0063870
F0063838: b0100008                 mov     %o0, %i0
F006383C: 04800008                 ble     loc_F006385C
F0063840: 80a2200d                 cmp     %o0, 0xD
F0063844: 0280000b                 be      locret_F0063870
F0063848: 80a22015                 cmp     %o0, 0x15
F006384C: 12800008                 bne     loc_F006386C
F0063850: 90102004                 mov     4, %o0
F0063854: 10800006                 ba      loc_F006386C
F0063858: 90102005                 mov     5, %o0
F006385C: 80a22000                 cmp     %o0, 0
F0063860: 02800004                 be      locret_F0063870
F0063864: b0100008                 mov     %o0, %i0
F0063868: 90102004                 mov     4, %o0
F006386C: b0100008                 mov     %o0, %i0
F0063870: 81c7e008                 ret
F0063874: 81e80000                 restore
