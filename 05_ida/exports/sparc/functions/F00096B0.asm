F00096B0: 9de3bf98                 save    %sp, -0x68, %sp
F00096B4: 113c04d190122350         set     _lbolt, %o0
F00096BC: 92102000                 mov     0, %o1
F00096C0: 40019e4f                 call    _thread_wakeup_prim
F00096C4: 94102000                 mov     0, %o2
F00096C8: 80a66000                 cmp     %i1, 0
F00096CC: 12800007                 bne     loc_F00096E8
F00096D0: 01000000                 nop
F00096D4: 113c0025901222b0         set     _lightning_bolt, %o0
F00096DC: 4001b5d9                 call    _calloutEntryAllocate
F00096E0: 92102000                 mov     0, %o1
F00096E4: b2100008                 mov     %o0, %i1
F00096E8: 90102000                 mov     0, %o0
F00096EC: 130ee6b292126200         set     0x3B9ACA00, %o1
F00096F4: 4001b49d                 call    _calloutDeadlineFromInterval
F00096F8: 01000000                 nop
F00096FC: 94100008                 mov     %o0, %o2
F0009700: 96100009                 mov     %o1, %o3
F0009704: 9210000a                 mov     %o2, %o1
F0009708: 9410000b                 mov     %o3, %o2
F000970C: 4001b650                 call    _calloutEntryDispatchDelayed
F0009710: 90100019                 mov     %i1, %o0
F0009714: 81c7e008                 ret
F0009718: 81e80000                 restore
