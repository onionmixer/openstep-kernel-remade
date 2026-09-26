F00CB98C: 9de3bf90                 save    %sp, -0x70, %sp
F00CB990: d006212c                 ld      [%i0+0x12C], %o0! id
F00CB994: 133c0506                 sethi   %hi(paSend), %o1
F00CB998: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00CB99C: 400097b5                 call    _objc_msgSend
F00CB9A0: 94102001                 mov     1, %o2
F00CB9A4: 81c7e008                 ret
F00CB9A8: 91e80008                 restore %g0, %o0, %o0
