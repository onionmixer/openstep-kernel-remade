F00CD8BC: 9de3bf90                 save    %sp, -0x70, %sp
F00CD8C0: 80a6a006                 cmp     %i2, 6
F00CD8C4: 0480000c                 ble     loc_F00CD8F4
F00CD8C8: 90100018                 mov     %i0, %o0! id
F00CD8CC: 133c0504                 sethi   %hi(paName), %o1
F00CD8D0: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CD8D4: 213c03ec                 sethi   %hi(aSRegisterunixd), %l0! "%s registerUnixDisk: Bogus partition (%"...
F00CD8D8: 40008fe6                 call    _objc_msgSend
F00CD8DC: a0142300                 bset    %lo(aSRegisterunixd), %l0! "%s registerUnixDisk: Bogus partition (%"...
F00CD8E0: 92100008                 mov     %o0, %o1
F00CD8E4: 90100010                 mov     %l0, %o0
F00CD8E8: 7fffe203                 call    _IOLog
F00CD8EC: 9410001a                 mov     %i2, %o2
F00CD8F0: 3080000b                 ba,a    locret_F00CD91C
F00CD8F4: d04e2116                 ldsb    [%i0+0x116], %o0
F00CD8F8: 80a22000                 cmp     %o0, 0
F00CD8FC: 22800005                 be,a    loc_F00CD910
F00CD900: d2062118                 ld      [%i0+0x118], %o1
F00CD904: d0062118                 ld      [%i0+0x118], %o0
F00CD908: 10800005                 ba      locret_F00CD91C
F00CD90C: f0220000                 st      %i0, [%o0]
F00CD910: 912ea002                 sll     %i2, 2, %o0
F00CD914: 90020009                 add     %o0, %o1, %o0
F00CD918: f0222004                 st      %i0, [%o0+4]
F00CD91C: 81c7e008                 ret
F00CD920: 81e80000                 restore
