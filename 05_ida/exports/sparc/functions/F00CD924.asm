F00CD924: 9de3bf90                 save    %sp, -0x70, %sp
F00CD928: 80a6a006                 cmp     %i2, 6
F00CD92C: 0480000c                 ble     loc_F00CD95C
F00CD930: 90100018                 mov     %i0, %o0! id
F00CD934: 133c0504                 sethi   %hi(paName), %o1
F00CD938: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CD93C: 213c03ec                 sethi   %hi(aSUnregisteruni), %l0! "%s unregisterUnixDisk: Bogus partition "...
F00CD940: 40008fcc                 call    _objc_msgSend
F00CD944: a0142330                 bset    %lo(aSUnregisteruni), %l0! "%s unregisterUnixDisk: Bogus partition "...
F00CD948: 92100008                 mov     %o0, %o1
F00CD94C: 90100010                 mov     %l0, %o0
F00CD950: 7fffe1e9                 call    _IOLog
F00CD954: 9410001a                 mov     %i2, %o2
F00CD958: 3080000b                 ba,a    locret_F00CD984
F00CD95C: d04e2116                 ldsb    [%i0+0x116], %o0
F00CD960: 80a22000                 cmp     %o0, 0
F00CD964: 22800005                 be,a    loc_F00CD978
F00CD968: d2062118                 ld      [%i0+0x118], %o1
F00CD96C: d0062118                 ld      [%i0+0x118], %o0
F00CD970: 10800005                 ba      locret_F00CD984
F00CD974: c0220000                 clr     [%o0]
F00CD978: 912ea002                 sll     %i2, 2, %o0
F00CD97C: 90020009                 add     %o0, %o1, %o0
F00CD980: c0222004                 clr     [%o0+4]
F00CD984: 81c7e008                 ret
F00CD988: 81e80000                 restore
