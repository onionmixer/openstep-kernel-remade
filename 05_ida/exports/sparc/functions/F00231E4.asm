F00231E4: 9de3bf98                 save    %sp, -0x68, %sp
F00231E8: 90960000                 orcc    %i0, %g0, %o0
F00231EC: 02800004                 be      locret_F00231FC
F00231F0: 133c008c                 sethi   %hi(_unp_discard), %o1
F00231F4: 40000004                 call    _unp_scan
F00231F8: 921262d8                 bset    %lo(_unp_discard), %o1
F00231FC: 81c7e008                 ret
F0023200: 81e80000                 restore
