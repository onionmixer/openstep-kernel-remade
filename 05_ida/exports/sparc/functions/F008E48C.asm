F008E48C: 9de3bf90                 save    %sp, -0x70, %sp
F008E490: 113c0503                 sethi   %hi(paFree), %o0! id
F008E494: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008E498: 40018cf6                 call    _objc_msgSend
F008E49C: 90100018                 mov     %i0, %o0
F008E4A0: 81c7e008                 ret
F008E4A4: 91e80008                 restore %g0, %o0, %o0
