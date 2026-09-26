F008D858: 9de3bf90                 save    %sp, -0x70, %sp
F008D85C: f027bff0                 st      %i0, [%fp+var_10]
F008D860: 133c0506                 sethi   %hi(stru_F0141AFC.ext), %o1
F008D864: d4026328                 ld      [%o1+%lo(stru_F0141AFC.ext)], %o2
F008D868: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008D86C: 133c0504                 sethi   %hi(paInit), %o1
F008D870: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F008D874: 40019042                 call    _objc_msgSendSuper
F008D878: d427bff4                 st      %o2, [%fp+var_C]
F008D87C: d0062004                 ld      [%i0+4], %o0
F008D880: 80a22000                 cmp     %o0, 0
F008D884: 1280000c                 bne     locret_F008D8B4
F008D888: 113c0506                 sethi   %hi(paHashtable), %o0
F008D88C: d002227c                 ld      [%o0+%lo(paHashtable)], %o0! id
F008D890: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F008D894: 40018ff7                 call    _objc_msgSend
F008D898: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F008D89C: 133c0504                 sethi   %hi(paInitkeydesc), %o1
F008D8A0: 153c0448                 sethi   %hi(asc_F0112050), %o2! "*"
F008D8A4: d2026064                 ld      [%o1+%lo(paInitkeydesc)], %o1! SEL
F008D8A8: 40018ff2                 call    _objc_msgSend
F008D8AC: 9412a050                 bset    %lo(asc_F0112050), %o2! "*"
F008D8B0: d0262004                 st      %o0, [%i0+4]
F008D8B4: 81c7e008                 ret
F008D8B8: 81e80000                 restore
