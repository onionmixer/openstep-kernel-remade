F00AEFDC: 9de3bf98                 save    %sp, -0x68, %sp
F00AEFE0: 113c000c                 sethi   %hi(_romp), %o0
F00AEFE4: d0022030                 ld      [%o0+%lo(_romp)], %o0
F00AEFE8: d202201c                 ld      [%o0+0x1C], %o1
F00AEFEC: d4026008                 ld      [%o1+8], %o2
F00AEFF0: 90100018                 mov     %i0, %o0
F00AEFF4: 9fc28000                 call    %o2
F00AEFF8: 92100019                 mov     %i1, %o1
F00AEFFC: 81c7e008                 ret
F00AF000: 91e80008                 restore %g0, %o0, %o0
