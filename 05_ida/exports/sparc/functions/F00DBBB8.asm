F00DBBB8: 9de3bf90                 save    %sp, -0x70, %sp
F00DBBBC: 7fffa8dd                 call    _IOMalloc
F00DBBC0: 90102044                 mov     0x44, %o0! void *
F00DBBC4: b0100008                 mov     %o0, %i0
F00DBBC8: 7ffee4a4                 call    _bzero
F00DBBCC: 92102044                 mov     0x44, %o1 ! 'D'
F00DBBD0: 81c7e008                 ret
F00DBBD4: 81e80000                 restore
