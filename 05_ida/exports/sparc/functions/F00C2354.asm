F00C2354: 9de3bf90                 save    %sp, -0x70, %sp
F00C2358: d006212c                 ld      [%i0+0x12C], %o0! id
F00C235C: 133c0504                 sethi   %hi(paDetachmouse), %o1! SEL
F00C2360: 4000bd44                 call    _objc_msgSend
F00C2364: d2026328                 ld      [%o1+%lo(paDetachmouse)], %o1
F00C2368: f027bff0                 st      %i0, [%fp+var_10]
F00C236C: 133c0507                 sethi   %hi(stru_F0141DCC.ext), %o1
F00C2370: d40261f8                 ld      [%o1+%lo(stru_F0141DCC.ext)], %o2
F00C2374: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C2378: 133c0503                 sethi   %hi(paFree), %o1
F00C237C: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C2380: 4000bd7f                 call    _objc_msgSendSuper
F00C2384: d427bff4                 st      %o2, [%fp+var_C]
F00C2388: 81c7e008                 ret
F00C238C: 91e80008                 restore %g0, %o0, %o0
