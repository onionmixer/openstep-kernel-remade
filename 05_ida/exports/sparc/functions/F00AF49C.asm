F00AF49C: 9de3bf98                 save    %sp, -0x68, %sp
F00AF4A0: 113c000c                 sethi   %hi(_romp), %o0
F00AF4A4: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AF4A8: d002201c                 ld      [%o0+0x1C], %o0
F00AF4AC: d2022004                 ld      [%o0+4], %o1
F00AF4B0: 9fc24000                 call    %o1
F00AF4B4: 90100018                 mov     %i0, %o0
F00AF4B8: 81c7e008                 ret
F00AF4BC: 91e80008                 restore %g0, %o0, %o0
