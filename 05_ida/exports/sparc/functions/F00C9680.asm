F00C9680: 9de3bf90                 save    %sp, -0x70, %sp
F00C9684: 90100018                 mov     %i0, %o0! id
F00C9688: 133c0506                 sethi   %hi(paStartiothreadw_0), %o1
F00C968C: d20260e4                 ld      [%o1+%lo(paStartiothreadw_0)], %o1! SEL
F00C9690: 4000a078                 call    _objc_msgSend
F00C9694: 94103fff                 mov     -1, %o2
F00C9698: 81c7e008                 ret
F00C969C: 91e80008                 restore %g0, %o0, %o0
