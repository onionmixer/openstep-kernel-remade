F008CAA0: 9de3bf90                 save    %sp, -0x70, %sp
F008CAA4: 113c0503                 sethi   %hi(paFree), %o0! id
F008CAA8: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008CAAC: 40019371                 call    _objc_msgSend
F008CAB0: 90100018                 mov     %i0, %o0
F008CAB4: 81c7e008                 ret
F008CAB8: 91e80008                 restore %g0, %o0, %o0
