F00ED044: 9de3bf98                 save    %sp, -0x68, %sp
F00ED048: a0100018                 mov     %i0, %l0
F00ED04C: 90100010                 mov     %l0, %o0! info
F00ED050: 40000393                 call    _NXPtrHash
F00ED054: d2064000                 ld      [%i1], %o1! data
F00ED058: b0100008                 mov     %o0, %i0
F00ED05C: 90100010                 mov     %l0, %o0! info
F00ED060: 4000038f                 call    _NXPtrHash
F00ED064: d2066004                 ld      [%i1+4], %o1! data
F00ED068: a2100008                 mov     %o0, %l1
F00ED06C: 90100010                 mov     %l0, %o0! info
F00ED070: 4000038b                 call    _NXPtrHash
F00ED074: d2066008                 ld      [%i1+8], %o1
F00ED078: b01e0011                 btog    %l1, %i0
F00ED07C: b01e0008                 btog    %o0, %i0
F00ED080: d006600c                 ld      [%i1+0xC], %o0
F00ED084: b01e0008                 btog    %o0, %i0
F00ED088: 81c7e008                 ret
F00ED08C: 81e80000                 restore
