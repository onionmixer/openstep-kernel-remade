F008B824: 9de3bf90                 save    %sp, -0x70, %sp
F008B828: 80a62000                 cmp     %i0, 0
F008B82C: 32800006                 bne,a   loc_F008B844
F008B830: d006200c                 ld      [%i0+0xC], %o0
F008B834: 113c0447                 sethi   %hi(aVnodeHasPageFa), %o0! "vnode_has_page: failed lookup"
F008B838: 7ffe264e                 call    _panic
F008B83C: 901222f8                 bset    %lo(aVnodeHasPageFa), %o0! "vnode_has_page: failed lookup"
F008B840: d006200c                 ld      [%i0+0xC], %o0
F008B844: 80a22000                 cmp     %o0, 0
F008B848: 1680000c                 bge     loc_F008B878
F008B84C: 113c0447                 sethi   -0xFEEE400, %o0
F008B850: 90100018                 mov     %i0, %o0! char *
F008B854: 92100019                 mov     %i1, %o1
F008B858: 94102001                 mov     1, %o2
F008B85C: 7ffffe37                 call    sub_F008B138
F008B860: 9607bff4                 add     %fp, var_C, %o3
F008B864: 80a22005                 cmp     %o0, 5
F008B868: 12800006                 bne     locret_F008B880
F008B86C: b0102001                 mov     1, %i0
F008B870: 10800004                 ba      locret_F008B880
F008B874: b0102000                 mov     0, %i0
F008B878: 7ffe263e                 call    _panic
F008B87C: 90122318                 bset    0x318, %o0
F008B880: 81c7e008                 ret
F008B884: 81e80000                 restore
