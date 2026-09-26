F00CB288: 9de3bf90                 save    %sp, -0x70, %sp
F00CB28C: 113c0503                 sethi   %hi(paFree), %o0
F00CB290: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00CB294: d0062008                 ld      [%i0+8], %o0! id
F00CB298: 40009976                 call    _objc_msgSend
F00CB29C: 92100010                 mov     %l0, %o1
F00CB2A0: 7ffe7305                 call    _port_release
F00CB2A4: d0062004                 ld      [%i0+4], %o0
F00CB2A8: f027bff0                 st      %i0, [%fp+var_10]
F00CB2AC: 133c0508                 sethi   %hi(stru_F014209C.ext), %o1
F00CB2B0: d40260c8                 ld      [%o1+%lo(stru_F014209C.ext)], %o2
F00CB2B4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CB2B8: 92100010                 mov     %l0, %o1! SEL
F00CB2BC: 400099b0                 call    _objc_msgSendSuper
F00CB2C0: d427bff4                 st      %o2, [%fp+var_C]
F00CB2C4: 81c7e008                 ret
F00CB2C8: 91e80008                 restore %g0, %o0, %o0
