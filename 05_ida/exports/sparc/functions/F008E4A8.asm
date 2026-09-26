F008E4A8: 9de3bf90                 save    %sp, -0x70, %sp
F008E4AC: 113c0504                 sethi   %hi(paDetachinterrup_0), %o0! id
F008E4B0: d20220b0                 ld      [%o0+%lo(paDetachinterrup_0)], %o1! SEL
F008E4B4: 40018cef                 call    _objc_msgSend
F008E4B8: 90100018                 mov     %i0, %o0
F008E4BC: f027bff0                 st      %i0, [%fp+var_10]
F008E4C0: 133c0507                 sethi   %hi(stru_F0141C8C.ext), %o1
F008E4C4: d40260b8                 ld      [%o1+%lo(stru_F0141C8C.ext)], %o2
F008E4C8: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008E4CC: 133c0503                 sethi   %hi(paFree), %o1
F008E4D0: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F008E4D4: 40018d2a                 call    _objc_msgSendSuper
F008E4D8: d427bff4                 st      %o2, [%fp+var_C]
F008E4DC: 81c7e008                 ret
F008E4E0: 91e80008                 restore %g0, %o0, %o0
