F0067BB4: 9de3bf98                 save    %sp, -0x68, %sp
F0067BB8: 90960000                 orcc    %i0, %g0, %o0
F0067BBC: 02800004                 be      locret_F0067BCC
F0067BC0: 01000000                 nop
F0067BC4: 7fffd8a1                 call    _ipc_space_release
F0067BC8: 01000000                 nop
F0067BCC: 81c7e008                 ret
F0067BD0: 81e80000                 restore
