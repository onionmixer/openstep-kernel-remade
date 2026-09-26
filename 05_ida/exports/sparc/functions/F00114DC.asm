F00114DC: 9de3bf98                 save    %sp, -0x68, %sp
F00114E0: 90960000                 orcc    %i0, %g0, %o0
F00114E4: 02800009                 be      locret_F0011508
F00114E8: 01000000                 nop
F00114EC: 7ffff45d                 call    _pgfind
F00114F0: 01000000                 nop
F00114F4: 80a22000                 cmp     %o0, 0
F00114F8: 02800004                 be      locret_F0011508
F00114FC: 92100019                 mov     %i1, %o1
F0011500: 40000004                 call    _pgsignal
F0011504: 94102000                 mov     0, %o2
F0011508: 81c7e008                 ret
F001150C: 81e80000                 restore
