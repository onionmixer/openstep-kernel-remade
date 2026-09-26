F00C4AEC: 9de3bf90                 save    %sp, -0x70, %sp
F00C4AF0: 113c0506                 sethi   %hi(paUnregisterdevi), %o0! id
F00C4AF4: d20221ec                 ld      [%o0+%lo(paUnregisterdevi)], %o1! SEL
F00C4AF8: 4000b35e                 call    _objc_msgSend
F00C4AFC: 90100018                 mov     %i0, %o0
F00C4B00: f027bff0                 st      %i0, [%fp+var_10]
F00C4B04: 133c0507                 sethi   %hi(stru_F0141E6C.ext), %o1
F00C4B08: d4026298                 ld      [%o1+%lo(stru_F0141E6C.ext)], %o2
F00C4B0C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C4B10: 133c0503                 sethi   %hi(paFree), %o1
F00C4B14: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C4B18: 4000b399                 call    _objc_msgSendSuper
F00C4B1C: d427bff4                 st      %o2, [%fp+var_C]
F00C4B20: 81c7e008                 ret
F00C4B24: 91e80008                 restore %g0, %o0, %o0
