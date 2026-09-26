F00EC1B8: 9de3bf90                 save    %sp, -0x70, %sp
F00EC1BC: 113c04bc                 sethi   %hi(__cvtToId), %o0
F00EC1C0: d20220f8                 ld      [%o0+%lo(__cvtToId)], %o1
F00EC1C4: 9fc24000                 call    %o1
F00EC1C8: 9010001a                 mov     %i2, %o0
F00EC1CC: 81c7e008                 ret
F00EC1D0: 91e80008                 restore %g0, %o0, %o0
