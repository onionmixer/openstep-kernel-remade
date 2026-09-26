F00EB834: 9de3bf90                 save    %sp, -0x70, %sp
F00EB838: 113c04bc                 sethi   %hi(__dealloc), %o0
F00EB83C: d20220f4                 ld      [%o0+%lo(__dealloc)], %o1
F00EB840: 9fc24000                 call    %o1
F00EB844: 90100018                 mov     %i0, %o0
F00EB848: 81c7e008                 ret
F00EB84C: 91e80008                 restore %g0, %o0, %o0
