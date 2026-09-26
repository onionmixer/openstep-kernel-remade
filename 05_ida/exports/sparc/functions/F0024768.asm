F0024768: 9de3bf98                 save    %sp, -0x68, %sp
F002476C: e0060000                 ld      [%i0], %l0
F0024770: 900c3df8                 and     %l0, -0x208, %o0
F0024774: a28c2200                 andcc   %l0, 0x200, %l1
F0024778: 12800007                 bne     loc_F0024794
F002477C: d0260000                 st      %o0, [%i0]
F0024780: 113c04cf                 sethi   %hi(_active_u), %o0
F0024784: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0024788: d002619c                 ld      [%o1+0x19C], %o0
F002478C: 90022001                 inc     %o0
F0024790: d022619c                 st      %o0, [%o1+0x19C]
F0024794: d2062014                 ld      [%i0+0x14], %o1
F0024798: d0062018                 ld      [%i0+0x18], %o0
F002479C: 80a24008                 cmp     %o1, %o0
F00247A0: 24800006                 ble,a   loc_F00247B8
F00247A4: d0062040                 ld      [%i0+0x40], %o0
F00247A8: 113c042f                 sethi   %hi(aBwrite), %o0! "bwrite"
F00247AC: 7fffc271                 call    _panic
F00247B0: 90122308                 bset    %lo(aBwrite), %o0! "bwrite"
F00247B4: d0062040                 ld      [%i0+0x40], %o0
F00247B8: d002201c                 ld      [%o0+0x1C], %o0
F00247BC: d2022054                 ld      [%o0+0x54], %o1
F00247C0: 9fc24000                 call    %o1
F00247C4: 90100018                 mov     %i0, %o0
F00247C8: 808c2100                 btst    0x100, %l0
F00247CC: 12800007                 bne     loc_F00247E8
F00247D0: 80a46000                 cmp     %l1, 0
F00247D4: 40000223                 call    _biowait
F00247D8: 90100018                 mov     %i0, %o0
F00247DC: 40000023                 call    _brelse
F00247E0: 90100018                 mov     %i0, %o0
F00247E4: 30800006                 ba,a    locret_F00247FC
F00247E8: 02800005                 be      locret_F00247FC
F00247EC: 01000000                 nop
F00247F0: d0060000                 ld      [%i0], %o0
F00247F4: 90122080                 bset    0x80, %o0
F00247F8: d0260000                 st      %o0, [%i0]
F00247FC: 81c7e008                 ret
F0024800: 81e80000                 restore
