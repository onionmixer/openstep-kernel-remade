F00C03D4: 9de3bf90                 save    %sp, -0x70, %sp
F00C03D8: d0062124                 ld      [%i0+0x124], %o0! id
F00C03DC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C03E0: 4000c524                 call    _objc_msgSend
F00C03E4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C03E8: d0062124                 ld      [%i0+0x124], %o0! id
F00C03EC: 133c0504                 sethi   %hi(paUnlock), %o1
F00C03F0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00C03F4: 4000c51f                 call    _objc_msgSend
F00C03F8: c0262134                 clr     [%i0+0x134]
F00C03FC: 90100018                 mov     %i0, %o0! id
F00C0400: 133c0504                 sethi   %hi(paSetpointerscal), %o1
F00C0404: 173c03e4                 sethi   %hi(unk_F00F91EC), %o3
F00C0408: 94102005                 mov     5, %o2
F00C040C: d20262e4                 ld      [%o1+%lo(paSetpointerscal)], %o1! SEL
F00C0410: 4000c518                 call    _objc_msgSend
F00C0414: 9612e1ec                 bset    %lo(unk_F00F91EC), %o3
F00C0418: 81c7e008                 ret
F00C041C: 81e80000                 restore
