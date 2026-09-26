F00AF450: 9de3bf98                 save    %sp, -0x68, %sp
F00AF454: 113c000c                 sethi   %hi(_romp), %o0
F00AF458: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF45C: d202201c                 ld      [%o0+0x1C], %o1
F00AF460: d4026014                 ld      [%o1+0x14], %o2
F00AF464: 90100018                 mov     %i0, %o0
F00AF468: 9fc28000                 call    %o2
F00AF46C: 92100019                 mov     %i1, %o1
F00AF470: 81c7e008                 ret
F00AF474: 91e80008                 restore %g0, %o0, %o0
