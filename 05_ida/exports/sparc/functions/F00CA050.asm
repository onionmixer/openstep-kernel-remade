F00CA050: 9de3bf90                 save    %sp, -0x70, %sp
F00CA054: d0062004                 ld      [%i0+4], %o0
F00CA058: 7ffe7b5b                 call    _lock_write
F00CA05C: d0020000                 ld      [%o0], %o0
F00CA060: 81c7e008                 ret
F00CA064: 81e80000                 restore
