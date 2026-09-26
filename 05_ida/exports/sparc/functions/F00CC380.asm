F00CC380: 9de3bf90                 save    %sp, -0x70, %sp
F00CC384: 113c0503                 sethi   %hi(paFree), %o0
F00CC388: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00CC38C: d0062008                 ld      [%i0+8], %o0! id
F00CC390: 40009538                 call    _objc_msgSend
F00CC394: 92100010                 mov     %l0, %o1
F00CC398: 7ffe6ec7                 call    _port_release
F00CC39C: d0062004                 ld      [%i0+4], %o0
F00CC3A0: f027bff0                 st      %i0, [%fp+var_10]
F00CC3A4: 133c0508                 sethi   %hi(stru_F01420EC.ext), %o1
F00CC3A8: d4026118                 ld      [%o1+%lo(stru_F01420EC.ext)], %o2
F00CC3AC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CC3B0: 92100010                 mov     %l0, %o1! SEL
F00CC3B4: 40009572                 call    _objc_msgSendSuper
F00CC3B8: d427bff4                 st      %o2, [%fp+var_C]
F00CC3BC: 81c7e008                 ret
F00CC3C0: 91e80008                 restore %g0, %o0, %o0
