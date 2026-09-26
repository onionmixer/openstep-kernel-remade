F009DC54: 9de3bf98                 save    %sp, -0x68, %sp
F009DC58: d0062008                 ld      [%i0+8], %o0
F009DC5C: 80a22000                 cmp     %o0, 0
F009DC60: 12800004                 bne     locret_F009DC70
F009DC64: 113c045f                 sethi   %hi(aPmapIs0InSegE), %o0! "pmap is 0 in seg_e\n"
F009DC68: 7ffdda7c                 call    _printf
F009DC6C: 90122240                 bset    %lo(aPmapIs0InSegE), %o0! "pmap is 0 in seg_e\n"
F009DC70: 81c7e008                 ret
F009DC74: 81e80000                 restore
