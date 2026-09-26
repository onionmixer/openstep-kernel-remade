F00CC8A8: 9de3bf90                 save    %sp, -0x70, %sp
F00CC8AC: 113c0506                 sethi   %hi(paCleartimeout), %o0! id
F00CC8B0: d2022064                 ld      [%o0+%lo(paCleartimeout)], %o1! SEL
F00CC8B4: 400093ef                 call    _objc_msgSend
F00CC8B8: 90100018                 mov     %i0, %o0
F00CC8BC: d0062154                 ld      [%i0+0x154], %o0! id
F00CC8C0: 80a22000                 cmp     %o0, 0
F00CC8C4: 2280000b                 be,a    loc_F00CC8F0
F00CC8C8: d4062150                 ld      [%i0+0x150], %o2
F00CC8CC: 133c0506                 sethi   %hi(paSend), %o1
F00CC8D0: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00CC8D4: 400093e7                 call    _objc_msgSend
F00CC8D8: 94102004                 mov     4, %o2
F00CC8DC: d0062154                 ld      [%i0+0x154], %o0! id
F00CC8E0: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00CC8E4: 400093e3                 call    _objc_msgSend
F00CC8E8: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00CC8EC: d4062150                 ld      [%i0+0x150], %o2
F00CC8F0: 80a2a000                 cmp     %o2, 0
F00CC8F4: 02800005                 be      loc_F00CC908
F00CC8F8: 113c0503                 sethi   %hi(paFree), %o0! id
F00CC8FC: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00CC900: 400093dc                 call    _objc_msgSend
F00CC904: 9010000a                 mov     %o2, %o0
F00CC908: f027bff0                 st      %i0, [%fp+var_10]
F00CC90C: 133c0508                 sethi   %hi(stru_F01420EC.super_class), %o1
F00CC910: d40260f0                 ld      [%o1+%lo(stru_F01420EC.super_class)], %o2
F00CC914: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CC918: 133c0503                 sethi   %hi(paFree), %o1
F00CC91C: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00CC920: 40009417                 call    _objc_msgSendSuper
F00CC924: d427bff4                 st      %o2, [%fp+var_C]
F00CC928: 81c7e008                 ret
F00CC92C: 91e80008                 restore %g0, %o0, %o0
