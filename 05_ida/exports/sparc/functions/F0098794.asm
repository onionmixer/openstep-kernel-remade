F0098794: 9de3bf98                 save    %sp, -0x68, %sp
F0098798: d2066010                 ld      [%i1+0x10], %o1
F009879C: 80a26000                 cmp     %o1, 0
F00987A0: 22800006                 be,a    loc_F00987B8
F00987A4: e2066008                 ld      [%i1+8], %l1
F00987A8: d0024000                 ld      [%o1], %o0
F00987AC: 90022001                 inc     %o0
F00987B0: d0224000                 st      %o0, [%o1]
F00987B4: e2066008                 ld      [%i1+8], %l1
F00987B8: d006600c                 ld      [%i1+0xC], %o0
F00987BC: 80a44008                 cmp     %l1, %o0
F00987C0: 1a80001f                 bcc     locret_F009883C
F00987C4: a4102001                 mov     1, %l2
F00987C8: a0046008                 add     %l1, 8, %l0
F00987CC: d0043ffc                 ld      [%l0-4], %o0
F00987D0: 80a22001                 cmp     %o0, 1
F00987D4: 22800007                 be,a    loc_F00987F0
F00987D8: d2044000                 ld      [%l1], %o1
F00987DC: 0a80000a                 bcs     loc_F0098804
F00987E0: 80a22002                 cmp     %o0, 2
F00987E4: 32800012                 bne,a   loc_F009882C
F00987E8: d006600c                 ld      [%i1+0xC], %o0
F00987EC: d2044000                 ld      [%l1], %o1
F00987F0: d4040000                 ld      [%l0], %o2
F00987F4: 40005a04                 call    _prom_getprop
F00987F8: 90100018                 mov     %i0, %o0
F00987FC: 1080000c                 ba      loc_F009882C
F0098800: d006600c                 ld      [%i1+0xC], %o0
F0098804: d2044000                 ld      [%l1], %o1
F0098808: 400059f5                 call    _prom_getproplen
F009880C: 90100018                 mov     %i0, %o0
F0098810: 80a23fff                 cmp     %o0, -1
F0098814: 12800004                 bne     loc_F0098824
F0098818: d0040000                 ld      [%l0], %o0
F009881C: 10800003                 ba      loc_F0098828
F0098820: c0220000                 clr     [%o0]
F0098824: e4220000                 st      %l2, [%o0]
F0098828: d006600c                 ld      [%i1+0xC], %o0
F009882C: a204600c                 inc     0xC, %l1
F0098830: 80a44008                 cmp     %l1, %o0
F0098834: 0abfffe6                 bcs     loc_F00987CC
F0098838: a004200c                 inc     0xC, %l0
F009883C: 81c7e008                 ret
F0098840: 81e80000                 restore
