F00AF004: 9de3bf98                 save    %sp, -0x68, %sp
F00AF008: 113c000c                 sethi   %hi(_romp), %o0
F00AF00C: d2022030                 ld      [%o0+%lo(_romp)], %o1
F00AF010: d402601c                 ld      [%o1+0x1C], %o2
F00AF014: 90100018                 mov     %i0, %o0
F00AF018: d602a00c                 ld      [%o2+0xC], %o3
F00AF01C: 92100019                 mov     %i1, %o1
F00AF020: 9fc2c000                 call    %o3
F00AF024: 9410001a                 mov     %i2, %o2
F00AF028: 81c7e008                 ret
F00AF02C: 91e80008                 restore %g0, %o0, %o0
