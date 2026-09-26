F0067EB4: 9de3bf98                 save    %sp, -0x68, %sp
F0067EB8: 90960000                 orcc    %i0, %g0, %o0
F0067EBC: 02800004                 be      locret_F0067ECC
F0067EC0: 01000000                 nop
F0067EC4: 7fffcc96                 call    _ipc_port_release_send
F0067EC8: 01000000                 nop
F0067ECC: 81c7e008                 ret
F0067ED0: 81e80000                 restore
