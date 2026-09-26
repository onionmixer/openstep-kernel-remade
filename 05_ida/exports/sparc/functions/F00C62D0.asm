F00C62D0: 9de3bf90                 save    %sp, -0x70, %sp
F00C62D4: 113c03ea                 sethi   %hi(aSetformattedOn), %o0! "setFormatted: on IODisk"
F00C62D8: 7fffff93                 call    _IOPanic
F00C62DC: 901222f0                 bset    %lo(aSetformattedOn), %o0! "setFormatted: on IODisk"
F00C62E0: 81c7e008                 ret
F00C62E4: 91e82000                 restore %g0, 0, %o0
