F0090D4C: 9de3bf98                 save    %sp, -0x68, %sp
F0090D50: 113c04f0                 sethi   %hi(_kernel_pmap), %o0
F0090D54: d0022100                 ld      [%o0+%lo(_kernel_pmap)], %o0
F0090D58: 40003880                 call    _pmap_extract
F0090D5C: 92100019                 mov     %i1, %o1
F0090D60: 133c04f4                 sethi   %hi(_page_shift), %o1
F0090D64: f0026348                 ld      [%o1+%lo(_page_shift)], %i0
F0090D68: b1320018                 srl     %o0, %i0, %i0
F0090D6C: 81c7e008                 ret
F0090D70: 81e80000                 restore
