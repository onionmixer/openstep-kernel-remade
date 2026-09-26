F00EF280: 9de3bf98                 save    %sp, -0x68, %sp
F00EF284: 113c04bc                 sethi   %hi(__alloc), %o0
F00EF288: d40220e8                 ld      [%o0+%lo(__alloc)], %o2
F00EF28C: 90100018                 mov     %i0, %o0
F00EF290: 9fc28000                 call    %o2
F00EF294: 92100019                 mov     %i1, %o1
F00EF298: 81c7e008                 ret
F00EF29C: 91e80008                 restore %g0, %o0, %o0
