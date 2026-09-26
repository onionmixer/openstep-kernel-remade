F00EC150: 9de3bf90                 save    %sp, -0x70, %sp
F00EC154: 133c0506                 sethi   %hi(paIsmemberofclas), %o1
F00EC158: 90100018                 mov     %i0, %o0! id
F00EC15C: d202620c                 ld      [%o1+%lo(paIsmemberofclas)], %o1! SEL
F00EC160: 400015c4                 call    _objc_msgSend
F00EC164: 9410001a                 mov     %i2, %o2
F00EC168: 912a2018                 sll     %o0, 24, %o0
F00EC16C: b13a2018                 sra     %o0, 24, %i0
F00EC170: 81c7e008                 ret
F00EC174: 81e80000                 restore
