F00EB040: 9de3bf90                 save    %sp, -0x70, %sp
F00EB044: 133c0504                 sethi   %hi(paInitcount), %o1
F00EB048: 90100018                 mov     %i0, %o0! id
F00EB04C: d20260bc                 ld      [%o1+%lo(paInitcount)], %o1! SEL
F00EB050: 40001a08                 call    _objc_msgSend
F00EB054: 94102000                 mov     0, %o2
F00EB058: 81c7e008                 ret
F00EB05C: 91e80008                 restore %g0, %o0, %o0
