F000B290: 9de3bf98                 save    %sp, -0x68, %sp
F000B294: 80a620ff                 cmp     %i0, 0xFF
F000B298: 14800024                 bg      loc_F000B328
F000B29C: 113c04cf                 sethi   -0xFECC400, %o0
F000B2A0: 253c04d0                 sethi   %hi(_active_threads), %l2
F000B2A4: 213c04cfa21421d8         set     _active_u, %l1
F000B2AC: 273fffc0                 sethi   -0x10000, %l3
F000B2B0: d004a260                 ld      [%l2+%lo(_active_threads)], %o0
F000B2B4: d002200c                 ld      [%o0+0xC], %o0
F000B2B8: d0022038                 ld      [%o0+0x38], %o0
F000B2BC: 4000012f                 call    _expand_fdlist
F000B2C0: 92100018                 mov     %i0, %o1
F000B2C4: d00421d8                 ld      [%l0+0x1D8], %o0
F000B2C8: d002214c                 ld      [%o0+0x14C], %o0
F000B2CC: 952e2002                 sll     %i0, 2, %o2
F000B2D0: d002000a                 ld      [%o0+%o2], %o0
F000B2D4: 80a22000                 cmp     %o0, 0
F000B2D8: 32800010                 bne,a   loc_F000B318
F000B2DC: b0062001                 inc     %i0
F000B2E0: d0046004                 ld      [%l1+4], %o0
F000B2E4: f0222030                 st      %i0, [%o0+0x30]
F000B2E8: d00421d8                 ld      [%l0+0x1D8], %o0
F000B2EC: d0022150                 ld      [%o0+0x150], %o0
F000B2F0: c02a0018                 clrb    [%o0+%i0]
F000B2F4: d20421d8                 ld      [%l0+0x1D8], %o1
F000B2F8: d0026154                 ld      [%o1+0x154], %o0
F000B2FC: 80a60008                 cmp     %i0, %o0
F000B300: 34800002                 bg,a    loc_F000B308
F000B304: f0226154                 st      %i0, [%o1+0x154]
F000B308: d00421d8                 ld      [%l0+0x1D8], %o0
F000B30C: d002214c                 ld      [%o0+0x14C], %o0
F000B310: 1080000a                 ba      locret_F000B338
F000B314: e622000a                 st      %l3, [%o0+%o2]
F000B318: 80a620ff                 cmp     %i0, 0xFF
F000B31C: 04bfffe6                 ble     loc_F000B2B4
F000B320: d004a260                 ld      [%l2+0x260], %o0
F000B324: 113c04cf                 sethi   -0xFECC400, %o0
F000B328: d20221dc                 ld      [%o0+0x1DC], %o1
F000B32C: b0103fff                 mov     -1, %i0
F000B330: 90102018                 mov     0x18, %o0
F000B334: d02a6038                 stb     %o0, [%o1+0x38]
F000B338: 81c7e008                 ret
F000B33C: 81e80000                 restore
