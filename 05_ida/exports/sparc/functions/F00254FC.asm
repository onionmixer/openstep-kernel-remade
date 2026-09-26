F00254FC: 9de3bf98                 save    %sp, -0x68, %sp
F0025500: 4001c5a2                 call    _splusclock
F0025504: 01000000                 nop
F0025508: 133c04cf921261e0         set     _bfreelist, %o1
F0025510: 940260cc                 add     %o1, 0xCC, %o2
F0025514: 80a2400a                 cmp     %o1, %o2
F0025518: 1a80001e                 bcc     loc_F0025590
F002551C: a0100008                 mov     %o0, %l0
F0025520: 17000040                 sethi   0x10000, %o3
F0025524: 9810000a                 mov     %o2, %o4
F0025528: d402600c                 ld      [%o1+0xC], %o2
F002552C: 80a28009                 cmp     %o2, %o1
F0025530: 22800015                 be,a    loc_F0025584
F0025534: 92026044                 inc     0x44, %o1 ! 'D'
F0025538: d002a040                 ld      [%o2+0x40], %o0
F002553C: 80a60008                 cmp     %i0, %o0
F0025540: 02800004                 be      loc_F0025550
F0025544: 80a62000                 cmp     %i0, 0
F0025548: 3280000b                 bne,a   loc_F0025574
F002554C: d402a00c                 ld      [%o2+0xC], %o2
F0025550: d2028000                 ld      [%o2], %o1
F0025554: 9010000a                 mov     %o2, %o0
F0025558: 920a7dff                 and     %o1, -0x201, %o1
F002555C: 9212400b                 bset    %o3, %o1
F0025560: 4000004c                 call    sub_F0025690
F0025564: d2220000                 st      %o1, [%o0]
F0025568: 4001c5ef                 call    _splx
F002556C: 90100010                 mov     %l0, %o0
F0025570: 30bfffe4                 ba,a    loc_F0025500
F0025574: 80a28009                 cmp     %o2, %o1
F0025578: 32bffff1                 bne,a   loc_F002553C
F002557C: d002a040                 ld      [%o2+0x40], %o0
F0025580: 92026044                 inc     0x44, %o1 ! 'D'
F0025584: 80a2400c                 cmp     %o1, %o4
F0025588: 2abfffe9                 bcs,a   loc_F002552C
F002558C: d402600c                 ld      [%o1+0xC], %o2
F0025590: 4001c5e5                 call    _splx
F0025594: 90100010                 mov     %l0, %o0
F0025598: 81c7e008                 ret
F002559C: 81e80000                 restore
