F001B834: 9de3bf98                 save    %sp, -0x68, %sp
F001B838: a00e20ff                 and     %i0, 0xFF, %l0
F001B83C: 80a4201f                 cmp     %l0, 0x1F
F001B840: 04800004                 ble     loc_F001B850
F001B844: 912e2010                 sll     %i0, 16, %o0
F001B848: 10800027                 ba      locret_F001B8E4
F001B84C: b0102006                 mov     6, %i0
F001B850: 7ffffe63                 call    _pty_alloc
F001B854: 913a2010                 sra     %o0, 16, %o0
F001B858: f0022008                 ld      [%o0+8], %i0
F001B85C: d0062024                 ld      [%i0+0x24], %o0
F001B860: 80a22000                 cmp     %o0, 0
F001B864: 32800020                 bne,a   locret_F001B8E4
F001B868: b0102005                 mov     5, %i0
F001B86C: 113c006d901222ec         set     _ptsstart, %o0
F001B874: d44e2047                 ldsb    [%i0+0x47], %o2
F001B878: d0262024                 st      %o0, [%i0+0x24]
F001B87C: 932aa001                 sll     %o2, 1, %o1
F001B880: 9202400a                 add     %o1, %o2, %o1
F001B884: 932a6004                 sll     %o1, 4, %o1
F001B888: 153c042e9412a0cc         set     _linesw, %o2
F001B890: 9202400a                 add     %o1, %o2, %o1
F001B894: d4026024                 ld      [%o1+0x24], %o2
F001B898: 90100018                 mov     %i0, %o0
F001B89C: 9fc28000                 call    %o2
F001B8A0: 92102001                 mov     1, %o1
F001B8A4: d2062040                 ld      [%i0+0x40], %o1
F001B8A8: 11001000                 sethi   0x400000, %o0
F001B8AC: 902a4008                 andn    %o1, %o0, %o0
F001B8B0: 90122010                 bset    0x10, %o0
F001B8B4: d0262040                 st      %o0, [%i0+0x40]
F001B8B8: 932c2004                 sll     %l0, 4, %o1
F001B8BC: 113c04bc90122204         set     unk_F012F204, %o0
F001B8C4: 92024008                 add     %o1, %o0, %o1
F001B8C8: d002600c                 ld      [%o1+0xC], %o0
F001B8CC: b0102000                 mov     0, %i0
F001B8D0: c0220000                 clr     [%o0]
F001B8D4: c02a200c                 clrb    [%o0+0xC]
F001B8D8: c02a200d                 clrb    [%o0+0xD]
F001B8DC: c0222008                 clr     [%o0+8]
F001B8E0: c0222004                 clr     [%o0+4]
F001B8E4: 81c7e008                 ret
F001B8E8: 81e80000                 restore
