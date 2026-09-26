F00D9BE4: 9de3bf90                 save    %sp, -0x70, %sp
F00D9BE8: 90100018                 mov     %i0, %o0! id
F00D9BEC: 133c0505                 sethi   %hi(paSubclassrespon), %o1
F00D9BF0: d20260cc                 ld      [%o1+%lo(paSubclassrespon)], %o1! SEL
F00D9BF4: 40005f1f                 call    _objc_msgSend
F00D9BF8: 94100019                 mov     %i1, %o2
F00D9BFC: 81c7e008                 ret
F00D9C00: 91e82000                 restore %g0, 0, %o0
