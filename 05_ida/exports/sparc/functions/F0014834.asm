F0014834: 9de3bf98                 save    %sp, -0x68, %sp
F0014838: 90100019                 mov     %i1, %o0
F001483C: 9210001a                 mov     %i2, %o1
F0014840: 94102005                 mov     5, %o2
F0014844: 40000022                 call    _prf
F0014848: 96102000                 mov     0, %o3
F001484C: 80a22000                 cmp     %o0, 0
F0014850: 02800004                 be      locret_F0014860
F0014854: 01000000                 nop
F0014858: 7fffff07                 call    _logwakeup
F001485C: 01000000                 nop
F0014860: 81c7e008                 ret
F0014864: 91e82000                 restore %g0, 0, %o0
