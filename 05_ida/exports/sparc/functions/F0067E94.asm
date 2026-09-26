F0067E94: 9de3bf98                 save    %sp, -0x68, %sp
F0067E98: 90960000                 orcc    %i0, %g0, %o0
F0067E9C: 02800004                 be      locret_F0067EAC
F0067EA0: 01000000                 nop
F0067EA4: 7fffcc66                 call    _ipc_port_copy_send
F0067EA8: 01000000                 nop
F0067EAC: 81c7e008                 ret
F0067EB0: 81e80000                 restore
