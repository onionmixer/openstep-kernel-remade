F00D9C04: 9de3bf90                 save    %sp, -0x70, %sp
F00D9C08: 90100018                 mov     %i0, %o0! id
F00D9C0C: 133c0505                 sethi   %hi(paSubclassrespon), %o1
F00D9C10: d20260cc                 ld      [%o1+%lo(paSubclassrespon)], %o1! SEL
F00D9C14: 40005f17                 call    _objc_msgSend
F00D9C18: 94100019                 mov     %i1, %o2
F00D9C1C: 81c7e008                 ret
F00D9C20: 81e80000                 restore
