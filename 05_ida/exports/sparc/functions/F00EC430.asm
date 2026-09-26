F00EC430: 9de3bf98                 save    %sp, -0x68, %sp
F00EC434: 113c04bc                 sethi   %hi(__realloc), %o0
F00EC438: d40220f0                 ld      [%o0+%lo(__realloc)], %o2
F00EC43C: 90100018                 mov     %i0, %o0
F00EC440: 9fc28000                 call    %o2
F00EC444: 92100019                 mov     %i1, %o1
F00EC448: 81c7e008                 ret
F00EC44C: 91e80008                 restore %g0, %o0, %o0
