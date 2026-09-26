F000B1AC: 9de3bf58                 save    %sp, -0xA8, %sp! int
F000B1B0: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000B1B4: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F000B1B8: e2022024                 ld      [%o0+0x24], %l1
F000B1BC: 901421dc                 or      %l0, %lo(dword_F0133DDC), %o0
F000B1C0: d2023ffc                 ld      [%o0-4], %o1
F000B1C4: d4044000                 ld      [%l1], %o2! int
F000B1C8: d0026158                 ld      [%o1+0x158], %o0
F000B1CC: 80a28008                 cmp     %o2, %o0
F000B1D0: 1a80000d                 bcc     loc_F000B204
F000B1D4: 113c04cf                 sethi   -0xFECC400, %o0
F000B1D8: d202614c                 ld      [%o1+0x14C], %o1
F000B1DC: 912aa002                 sll     %o2, 2, %o0
F000B1E0: d2024008                 ld      [%o1+%o0], %o1
F000B1E4: 80a26000                 cmp     %o1, 0
F000B1E8: 02800007                 be      loc_F000B204
F000B1EC: 113c04cf                 sethi   -0xFECC400, %o0
F000B1F0: 113fffc0                 sethi   -0x10000, %o0
F000B1F4: 80a24008                 cmp     %o1, %o0
F000B1F8: 32800006                 bne,a   loc_F000B210
F000B1FC: d052600c                 ldsh    [%o1+0xC], %o0
F000B200: 113c04cf                 sethi   -0xFECC400, %o0
F000B204: d20221dc                 ld      [%o0+0x1DC], %o1
F000B208: 1080001f                 ba      loc_F000B284
F000B20C: 90102009                 mov     9, %o0
F000B210: 80a22001                 cmp     %o0, 1
F000B214: 02800006                 be      loc_F000B22C
F000B218: 80a22002                 cmp     %o0, 2
F000B21C: 22800009                 be,a    loc_F000B240
F000B220: d0026018                 ld      [%o1+0x18], %o0
F000B224: 1080000c                 ba      loc_F000B254
F000B228: 113c042b                 sethi   -0xFEF5400, %o0
F000B22C: d0026018                 ld      [%o1+0x18], %o0! char *
F000B230: 40006c57                 call    _vno_stat
F000B234: 9207bfb8                 add     %fp, var_48, %o1
F000B238: 10800005                 ba      loc_F000B24C
F000B23C: d20421dc                 ld      [%l0+0x1DC], %o1
F000B240: 40002cb4                 call    _soo_stat
F000B244: 9207bfb8                 add     %fp, var_48, %o1
F000B248: d20421dc                 ld      [%l0+0x1DC], %o1
F000B24C: 10800004                 ba      loc_F000B25C
F000B250: d02a6038                 stb     %o0, [%o1+0x38]
F000B254: 400027c7                 call    _panic
F000B258: 90122238                 bset    0x238, %o0
F000B25C: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000B260: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F000B264: d04a2038                 ldsb    [%o0+0x38], %o0
F000B268: 80a22000                 cmp     %o0, 0
F000B26C: 12800007                 bne     locret_F000B288
F000B270: 9007bfb8                 add     %fp, var_48, %o0! int
F000B274: d2046004                 ld      [%l1+4], %o1! int
F000B278: 40023395                 call    _copyout
F000B27C: 94102040                 mov     0x40, %o2 ! '@'
F000B280: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F000B284: d02a6038                 stb     %o0, [%o1+0x38]
F000B288: 81c7e008                 ret
F000B28C: 81e80000                 restore
