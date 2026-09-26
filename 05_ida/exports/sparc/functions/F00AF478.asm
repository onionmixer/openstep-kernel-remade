F00AF478: 9de3bf98                 save    %sp, -0x68, %sp
F00AF47C: 113c000c                 sethi   %hi(_romp), %o0
F00AF480: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF484: d002201c                 ld      [%o0+0x1C], %o0
F00AF488: d2020000                 ld      [%o0], %o1
F00AF48C: 9fc24000                 call    %o1
F00AF490: 90100018                 mov     %i0, %o0
F00AF494: 81c7e008                 ret
F00AF498: 91e80008                 restore %g0, %o0, %o0
