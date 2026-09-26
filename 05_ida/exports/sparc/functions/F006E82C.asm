F006E82C: 9de3bf98                 save    %sp, -0x68, %sp
F006E830: 7fffffb9                 call    sub_F006E714
F006E834: 90102000                 mov     0, %o0
F006E838: 80a66000                 cmp     %i1, 0
F006E83C: 12800007                 bne     loc_F006E858
F006E840: 01000000                 nop
F006E844: 113c01ba9012202c         set     _power_callout, %o0
F006E84C: 4000217d                 call    _calloutEntryAllocate
F006E850: 92102000                 mov     0, %o1
F006E854: b2100008                 mov     %o0, %i1
F006E858: 90102000                 mov     0, %o0
F006E85C: 130f0cd892126080         set     0x3C336080, %o1
F006E864: 40002041                 call    _calloutDeadlineFromInterval
F006E868: 01000000                 nop
F006E86C: 94100008                 mov     %o0, %o2
F006E870: 96100009                 mov     %o1, %o3
F006E874: 9210000a                 mov     %o2, %o1
F006E878: 9410000b                 mov     %o3, %o2
F006E87C: 400021f4                 call    _calloutEntryDispatchDelayed
F006E880: 90100019                 mov     %i1, %o0
F006E884: 81c7e008                 ret
F006E888: 81e80000                 restore
