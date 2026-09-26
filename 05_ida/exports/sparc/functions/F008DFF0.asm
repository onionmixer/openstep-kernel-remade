F008DFF0: 9de3bf90                 save    %sp, -0x70, %sp
F008DFF4: d006201c                 ld      [%i0+0x1C], %o0! id
F008DFF8: 133c0504                 sethi   %hi(paAcquire), %o1! SEL
F008DFFC: 40018e1d                 call    _objc_msgSend
F008E000: d2026098                 ld      [%o1+%lo(paAcquire)], %o1
F008E004: d0062018                 ld      [%i0+0x18], %o0
F008E008: 80a22000                 cmp     %o0, 0
F008E00C: 1480000f                 bg      loc_F008E048
F008E010: d006201c                 ld      [%i0+0x1C], %o0! id
F008E014: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F008E018: 40018e16                 call    _objc_msgSend
F008E01C: d202609c                 ld      [%o1+%lo(paRelease)], %o1
F008E020: f027bff0                 st      %i0, [%fp+var_10]
F008E024: 133c0507                 sethi   %hi(stru_F0141C3C.ext), %o1
F008E028: d4026068                 ld      [%o1+%lo(stru_F0141C3C.ext)], %o2
F008E02C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008E030: 133c0503                 sethi   %hi(paFree), %o1
F008E034: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008E038: 40018e51                 call    _objc_msgSendSuper
F008E03C: d427bff4                 st      %o2, [%fp+var_C]
F008E040: 10800005                 ba      locret_F008E054
F008E044: b0100008                 mov     %o0, %i0
F008E048: 133c0504                 sethi   %hi(paRelease), %o1! SEL
F008E04C: 40018e09                 call    _objc_msgSend
F008E050: d202609c                 ld      [%o1+%lo(paRelease)], %o1
F008E054: 81c7e008                 ret
F008E058: 81e80000                 restore
