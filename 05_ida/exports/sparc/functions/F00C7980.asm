F00C7980: 9de3bf90                 save    %sp, -0x70, %sp
F00C7984: 113c0506                 sethi   %hi(paUnregisterunix), %o0! id
F00C7988: d202214c                 ld      [%o0+%lo(paUnregisterunix)], %o1! SEL
F00C798C: d40621a4                 ld      [%i0+0x1A4], %o2
F00C7990: 4000a7b8                 call    _objc_msgSend
F00C7994: 90100018                 mov     %i0, %o0
F00C7998: f027bff0                 st      %i0, [%fp+var_10]
F00C799C: 133c0507                 sethi   %hi(stru_F0141F0C.ext), %o1
F00C79A0: d4026338                 ld      [%o1+%lo(stru_F0141F0C.ext)], %o2
F00C79A4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C79A8: 133c0503                 sethi   %hi(paFree), %o1
F00C79AC: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00C79B0: 4000a7f3                 call    _objc_msgSendSuper
F00C79B4: d427bff4                 st      %o2, [%fp+var_C]
F00C79B8: 81c7e008                 ret
F00C79BC: 91e80008                 restore %g0, %o0, %o0
