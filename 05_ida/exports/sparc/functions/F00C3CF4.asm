F00C3CF4: 9de3bf90                 save    %sp, -0x70, %sp
F00C3CF8: 113c0503                 sethi   %hi(paFree), %o0
F00C3CFC: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00C3D00: d006202c                 ld      [%i0+0x2C], %o0! id
F00C3D04: 4000b6db                 call    _objc_msgSend
F00C3D08: 92100010                 mov     %l0, %o1
F00C3D0C: f027bff0                 st      %i0, [%fp+var_10]
F00C3D10: 133c0507                 sethi   %hi(stru_F0141E1C.ext), %o1
F00C3D14: d4026248                 ld      [%o1+%lo(stru_F0141E1C.ext)], %o2
F00C3D18: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C3D1C: 92100010                 mov     %l0, %o1! SEL
F00C3D20: 4000b717                 call    _objc_msgSendSuper
F00C3D24: d427bff4                 st      %o2, [%fp+var_C]
F00C3D28: 81c7e008                 ret
F00C3D2C: 91e80008                 restore %g0, %o0, %o0
