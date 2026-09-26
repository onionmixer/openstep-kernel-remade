F00E2644: 9de3bf98                 save    %sp, -0x68, %sp
F00E2648: 10800004                 ba      loc_F00E2658
F00E264C: b2067fff                 inc     -1, %i1
F00E2650: b0062004                 inc     4, %i0
F00E2654: b2067fff                 inc     -1, %i1
F00E2658: 80a67fff                 cmp     %i1, -1
F00E265C: 32bffffd                 bne,a   loc_F00E2650
F00E2660: c0260000                 clr     [%i0]
F00E2664: 81c7e008                 ret
F00E2668: 81e80000                 restore
