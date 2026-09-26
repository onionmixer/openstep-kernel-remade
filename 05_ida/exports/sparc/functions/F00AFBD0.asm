F00AFBD0: 9de3bf98                 save    %sp, -0x68, %sp
F00AFBD4: 133c000c                 sethi   %hi(_romp), %o1
F00AFBD8: d4026030                 ld      [%o1+%lo(_romp)], %o2
F00AFBDC: 90100018                 mov     %i0, %o0
F00AFBE0: d602a01c                 ld      [%o2+0x1C], %o3
F00AFBE4: 92100019                 mov     %i1, %o1
F00AFBE8: d802e010                 ld      [%o3+0x10], %o4
F00AFBEC: 9410001a                 mov     %i2, %o2
F00AFBF0: 9fc30000                 call    %o4
F00AFBF4: 9610001b                 mov     %i3, %o3
F00AFBF8: 81c7e008                 ret
F00AFBFC: 91e80008                 restore %g0, %o0, %o0
