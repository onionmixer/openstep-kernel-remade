F00BF864: 9de3bf90                 save    %sp, -0x70, %sp
F00BF868: d0062124                 ld      [%i0+0x124], %o0! id
F00BF86C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BF870: 4000c800                 call    _objc_msgSend
F00BF874: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00BF878: f027bff0                 st      %i0, [%fp+var_10]
F00BF87C: 133c0507                 sethi   %hi(stru_F0141D2C.ext), %o1
F00BF880: d4026158                 ld      [%o1+%lo(stru_F0141D2C.ext)], %o2
F00BF884: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00BF888: 133c0504                 sethi   %hi(paInit), %o1
F00BF88C: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00BF890: 4000c83b                 call    _objc_msgSendSuper
F00BF894: d427bff4                 st      %o2, [%fp+var_C]
F00BF898: d4062128                 ld      [%i0+0x128], %o2
F00BF89C: 80a2a000                 cmp     %o2, 0
F00BF8A0: 22800007                 be,a    loc_F00BF8BC
F00BF8A4: 113c0506                 sethi   -0xFEBE800, %o0
F00BF8A8: 113c0503                 sethi   %hi(paFree), %o0! id
F00BF8AC: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00BF8B0: 4000c7f0                 call    _objc_msgSend
F00BF8B4: 9010000a                 mov     %o2, %o0
F00BF8B8: 113c0506                 sethi   -0xFEBE800, %o0
F00BF8BC: d00222a4                 ld      [%o0+0x2A4], %o0! id
F00BF8C0: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00BF8C4: 4000c7eb                 call    _objc_msgSend
F00BF8C8: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00BF8CC: 153c03e39412a290         set     unk_F00F8E90, %o2
F00BF8D4: 133c0504                 sethi   %hi(paInitfromkeymap), %o1
F00BF8D8: 9610235a                 mov     0x35A, %o3
F00BF8DC: d2026284                 ld      [%o1+%lo(paInitfromkeymap)], %o1! SEL
F00BF8E0: 4000c7e4                 call    _objc_msgSend
F00BF8E4: 98102000                 mov     0, %o4
F00BF8E8: d0262128                 st      %o0, [%i0+0x128]
F00BF8EC: 133c0504                 sethi   %hi(paSetdelegate), %o1
F00BF8F0: d2026288                 ld      [%o1+%lo(paSetdelegate)], %o1! SEL
F00BF8F4: 4000c7df                 call    _objc_msgSend
F00BF8F8: 94100018                 mov     %i0, %o2
F00BF8FC: 113c0504                 sethi   %hi(paInitkeyboard), %o0! id
F00BF900: d20222b4                 ld      [%o0+%lo(paInitkeyboard)], %o1! SEL
F00BF904: 4000c7db                 call    _objc_msgSend
F00BF908: 90100018                 mov     %i0, %o0
F00BF90C: 90102000                 mov     0, %o0
F00BF910: 1301dcd692126140         set     0x7735940, %o1
F00BF918: d03e2168                 std     %o0, [%i0+0x168]
F00BF91C: 133c0504                 sethi   %hi(paUnlock), %o1
F00BF920: d0062124                 ld      [%i0+0x124], %o0! id
F00BF924: 94102000                 mov     0, %o2
F00BF928: 170773599612e100         set     0x1DCD6500, %o3
F00BF930: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00BF934: 4000c7cf                 call    _objc_msgSend
F00BF938: d43e2170                 std     %o2, [%i0+0x170]
F00BF93C: 81c7e008                 ret
F00BF940: 81e80000                 restore
