F00BF418: 9de3bf90                 save    %sp, -0x70, %sp
F00BF41C: d04e214e                 ldsb    [%i0+0x14E], %o0
F00BF420: 80a22000                 cmp     %o0, 0
F00BF424: 1280001d                 bne     locret_F00BF498
F00BF428: 80a6a00a                 cmp     %i2, 0xA
F00BF42C: 1280000c                 bne     loc_F00BF45C
F00BF430: 80a6a00b                 cmp     %i2, 0xB
F00BF434: f6262150                 st      %i3, [%i0+0x150]
F00BF438: d41e2170                 ldd     [%i0+0x170], %o2
F00BF43C: 90100018                 mov     %i0, %o0
F00BF440: d81e2158                 ldd     [%i0+0x158], %o4
F00BF444: 133c0504                 sethi   %hi(paScheduleautore), %o1
F00BF448: d2026290                 ld      [%o1+%lo(paScheduleautore)], %o1
F00BF44C: 9682c00d                 addcc   %o3, %o5, %o3
F00BF450: 9442800c                 addc    %o2, %o4, %o2
F00BF454: 1080000f                 ba      loc_F00BF490
F00BF458: d43e2160                 std     %o2, [%i0+0x160]
F00BF45C: 1280000f                 bne     locret_F00BF498
F00BF460: 01000000                 nop
F00BF464: d0062150                 ld      [%i0+0x150], %o0
F00BF468: 80a2001b                 cmp     %o0, %i3
F00BF46C: 1280000b                 bne     locret_F00BF498
F00BF470: 90103fff                 mov     -1, %o0
F00BF474: 84102000                 mov     0, %g2
F00BF478: 86102000                 mov     0, %g3
F00BF47C: d0262150                 st      %o0, [%i0+0x150]
F00BF480: 113c0504                 sethi   %hi(paScheduleautore), %o0
F00BF484: d2022290                 ld      [%o0+%lo(paScheduleautore)], %o1! SEL
F00BF488: c43e2160                 std     %g2, [%i0+0x160]
F00BF48C: 90100018                 mov     %i0, %o0! id
F00BF490: 4000c8f8                 call    _objc_msgSend
F00BF494: 01000000                 nop
F00BF498: 81c7e008                 ret
F00BF49C: 81e80000                 restore
