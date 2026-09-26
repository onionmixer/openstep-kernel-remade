F003C258: 9de3bf98                 save    %sp, -0x68, %sp
F003C25C: d206205c                 ld      [%i0+0x5C], %o1
F003C260: 293c0433                 sethi   -0xFEF3400, %l4
F003C264: 253c04ea                 sethi   -0xFEC5800, %l2
F003C268: 113c04eaa61223a0         set     _unixauthtab, %l3
F003C270: 80a26001                 cmp     %o1, 1
F003C274: 14800025                 bg      loc_F003C308
F003C278: 113c0433                 sethi   -0xFEF3400, %o0
F003C27C: 80a26000                 cmp     %o1, 0
F003C280: 06800022                 bl      loc_F003C308
F003C284: f0052180                 ld      [%l4+0x180], %i0
F003C288: d404a240                 ld      [%l2+0x240], %o2
F003C28C: d2052180                 ld      [%l4+0x180], %o1
F003C290: 9002a001                 add     %o2, 1, %o0
F003C294: d024a240                 st      %o0, [%l2+0x240]
F003C298: 7fff2982                 call    _urem
F003C29C: a32aa003                 sll     %o2, 3, %l1
F003C2A0: d024a240                 st      %o0, [%l2+0x240]
F003C2A4: d2544013                 ldsh    [%l1+%l3], %o1
F003C2A8: 80a26000                 cmp     %o1, 0
F003C2AC: 02800007                 be      loc_F003C2C8
F003C2B0: a0044013                 add     %l1, %l3, %l0
F003C2B4: b0063fff                 inc     -1, %i0
F003C2B8: 80a62000                 cmp     %i0, 0
F003C2BC: 14bffff4                 bg      loc_F003C28C
F003C2C0: d404a240                 ld      [%l2+0x240], %o2
F003C2C4: 80a26000                 cmp     %o1, 0
F003C2C8: 22800006                 be,a    loc_F003C2E0
F003C2CC: d0042004                 ld      [%l0+4], %o0
F003C2D0: 40001885                 call    _authkern_create
F003C2D4: 01000000                 nop
F003C2D8: 10800010                 ba      locret_F003C318
F003C2DC: b0100008                 mov     %o0, %i0
F003C2E0: 80a22000                 cmp     %o0, 0
F003C2E4: 12800006                 bne     loc_F003C2FC
F003C2E8: 90102001                 mov     1, %o0
F003C2EC: 4000187e                 call    _authkern_create
F003C2F0: 01000000                 nop
F003C2F4: d0242004                 st      %o0, [%l0+4]
F003C2F8: 90102001                 mov     1, %o0! char *
F003C2FC: d0344013                 sth     %o0, [%l1+%l3]
F003C300: 10800006                 ba      locret_F003C318
F003C304: f0042004                 ld      [%l0+4], %i0
F003C308: 7fff60d4                 call    _printf
F003C30C: 90122188                 bset    0x188, %o0
F003C310: 10bfffd8                 ba      loc_F003C270
F003C314: 92102000                 mov     0, %o1
F003C318: 81c7e008                 ret
F003C31C: 81e80000                 restore
