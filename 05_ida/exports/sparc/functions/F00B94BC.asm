F00B94BC: 9de3bf98                 save    %sp, -0x68, %sp
F00B94C0: 90100018                 mov     %i0, %o0! __s1
F00B94C4: 133c047e                 sethi   %hi(aEspdma), %o1! "espdma"
F00B94C8: 7ffd3b39                 call    _strcmp
F00B94CC: 92126228                 bset    %lo(aEspdma), %o1! "espdma"
F00B94D0: 80a22000                 cmp     %o0, 0
F00B94D4: 12800007                 bne     locret_F00B94F0
F00B94D8: b0102000                 mov     0, %i0
F00B94DC: 133c0474                 sethi   %hi(_ndma_map), %o1
F00B94E0: d00261d8                 ld      [%o1+%lo(_ndma_map)], %o0
F00B94E4: b0102001                 mov     1, %i0
F00B94E8: 90022001                 inc     %o0
F00B94EC: d02261d8                 st      %o0, [%o1+%lo(_ndma_map)]
F00B94F0: 81c7e008                 ret
F00B94F4: 81e80000                 restore
