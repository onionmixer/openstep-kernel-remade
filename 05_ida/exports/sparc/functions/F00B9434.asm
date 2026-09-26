F00B9434: 9de3bf98                 save    %sp, -0x68, %sp
F00B9438: d0064000                 ld      [%i1], %o0
F00B943C: 80a22000                 cmp     %o0, 0
F00B9440: 0280000e                 be      loc_F00B9478
F00B9444: 94100018                 mov     %i0, %o2
F00B9448: 920aa0ff                 and     %o2, 0xFF, %o1
F00B944C: f0064000                 ld      [%i1], %i0
F00B9450: d00e0000                 ldub    [%i0], %o0
F00B9454: 80a24008                 cmp     %o1, %o0
F00B9458: 12800004                 bne     loc_F00B9468
F00B945C: b2066004                 inc     4, %i1
F00B9460: 1080000d                 ba      locret_F00B9494
F00B9464: b0062001                 inc     %i0
F00B9468: d0064000                 ld      [%i1], %o0
F00B946C: 80a22000                 cmp     %o0, 0
F00B9470: 32bffff8                 bne,a   loc_F00B9450
F00B9474: f0064000                 ld      [%i1], %i0
F00B9478: 313c04c6b0162008         set     unk_F0131808, %i0
F00B9480: 90100018                 mov     %i0, %o0! char *
F00B9484: 133c047e921261b0         set     aUndecodedCmd0x, %o1! "<undecoded cmd 0x%x>"
F00B948C: 7ffd6cb7                 call    _sprintf
F00B9490: 940aa0ff                 and     %o2, 0xFF, %o2
F00B9494: 81c7e008                 ret
F00B9498: 81e80000                 restore
