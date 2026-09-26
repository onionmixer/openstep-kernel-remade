F00AF278: 9de3bf98                 save    %sp, -0x68, %sp
F00AF27C: 113c000c                 sethi   %hi(_romp), %o0
F00AF280: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF284: d202207c                 ld      [%o0+0x7C], %o1
F00AF288: 9fc24000                 call    %o1
F00AF28C: 90100018                 mov     %i0, %o0
F00AF290: 81c7e008                 ret
F00AF294: 81e80000                 restore
