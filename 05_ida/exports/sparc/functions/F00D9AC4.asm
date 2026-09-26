F00D9AC4: 9de3bf90                 save    %sp, -0x70, %sp
F00D9AC8: 90100018                 mov     %i0, %o0! id
F00D9ACC: 133c0505                 sethi   %hi(paSubclassrespon), %o1
F00D9AD0: d20260cc                 ld      [%o1+%lo(paSubclassrespon)], %o1! SEL
F00D9AD4: 40005f67                 call    _objc_msgSend
F00D9AD8: 94100019                 mov     %i1, %o2
F00D9ADC: 81c7e008                 ret
F00D9AE0: 91e82000                 restore %g0, 0, %o0
