F00C1BF0: 9de3bf90                 save    %sp, -0x70, %sp
F00C1BF4: 113c0503                 sethi   %hi(paFree), %o0
F00C1BF8: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00C1BFC: d0062148                 ld      [%i0+0x148], %o0! id
F00C1C00: 4000bf1c                 call    _objc_msgSend
F00C1C04: 92100010                 mov     %l0, %o1
F00C1C08: f027bff0                 st      %i0, [%fp+var_10]
F00C1C0C: 133c0507                 sethi   %hi(stru_F0141DCC.super_class), %o1
F00C1C10: d40261d0                 ld      [%o1+%lo(stru_F0141DCC.super_class)], %o2
F00C1C14: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C1C18: 92100010                 mov     %l0, %o1! SEL
F00C1C1C: 4000bf58                 call    _objc_msgSendSuper
F00C1C20: d427bff4                 st      %o2, [%fp+var_C]
F00C1C24: 81c7e008                 ret
F00C1C28: 91e80008                 restore %g0, %o0, %o0
