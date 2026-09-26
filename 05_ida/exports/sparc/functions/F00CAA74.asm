F00CAA74: 9de3bf90                 save    %sp, -0x70, %sp
F00CAA78: 213c0506                 sethi   %hi(paDequeue), %l0
F00CAA7C: d2042074                 ld      [%l0+%lo(paDequeue)], %o1! SEL
F00CAA80: 40009b7c                 call    _objc_msgSend
F00CAA84: 90100018                 mov     %i0, %o0
F00CAA88: 80a22000                 cmp     %o0, 0
F00CAA8C: 22800006                 be,a    loc_F00CAAA4
F00CAA90: f027bff0                 st      %i0, [%fp+var_10]
F00CAA94: 7ffd8404                 call    _nb_free
F00CAA98: 01000000                 nop
F00CAA9C: 10bffff9                 ba      loc_F00CAA80
F00CAAA0: d2042074                 ld      [%l0+0x74], %o1
F00CAAA4: 133c0508                 sethi   %hi(stru_F014204C.ext), %o1
F00CAAA8: d4026078                 ld      [%o1+%lo(stru_F014204C.ext)], %o2
F00CAAAC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CAAB0: 133c0503                 sethi   %hi(paFree), %o1
F00CAAB4: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00CAAB8: 40009bb1                 call    _objc_msgSendSuper
F00CAABC: d427bff4                 st      %o2, [%fp+var_C]
F00CAAC0: 81c7e008                 ret
F00CAAC4: 91e80008                 restore %g0, %o0, %o0
