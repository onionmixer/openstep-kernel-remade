F00EC414: 9de3bf98                 save    %sp, -0x68, %sp
F00EC418: 113c04bc                 sethi   %hi(__dealloc), %o0
F00EC41C: d20220f4                 ld      [%o0+%lo(__dealloc)], %o1
F00EC420: 9fc24000                 call    %o1
F00EC424: 90100018                 mov     %i0, %o0
F00EC428: 81c7e008                 ret
F00EC42C: 91e80008                 restore %g0, %o0, %o0
