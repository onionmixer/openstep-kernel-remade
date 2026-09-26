F00BEBE4: 9de3bf98                 save    %sp, -0x68, %sp
F00BEBE8: d006201c                 ld      [%i0+0x1C], %o0
F00BEBEC: 40001cd6                 call    _IOFree
F00BEBF0: 92102054                 mov     0x54, %o1 ! 'T'
F00BEBF4: 90100018                 mov     %i0, %o0
F00BEBF8: 40001cd3                 call    _IOFree
F00BEBFC: 92102020                 mov     0x20, %o1 ! ' '
F00BEC00: 81c7e008                 ret
F00BEC04: 81e80000                 restore
