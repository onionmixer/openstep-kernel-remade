F001A52C: 9de3bf98                 save    %sp, -0x68, %sp
F001A530: 10800006                 ba      loc_F001A548
F001A534: d00e0000                 ldub    [%i0], %o0
F001A538: 913a2018                 sra     %o0, 24, %o0
F001A53C: 7ffffa95                 call    _ttyoutput
F001A540: 92100019                 mov     %i1, %o1
F001A544: d00e0000                 ldub    [%i0], %o0
F001A548: 912a2018                 sll     %o0, 24, %o0
F001A54C: 80a22000                 cmp     %o0, 0
F001A550: 12bffffa                 bne     loc_F001A538
F001A554: b0062001                 inc     %i0
F001A558: 81c7e008                 ret
F001A55C: 81e80000                 restore
