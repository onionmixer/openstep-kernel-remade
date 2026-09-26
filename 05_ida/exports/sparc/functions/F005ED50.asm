F005ED50: 9de3bf98                 save    %sp, -0x68, %sp
F005ED54: 94100018                 mov     %i0, %o2
F005ED58: 113c0447                 sethi   %hi(_page_size), %o0
F005ED5C: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F005ED60: 80a28008                 cmp     %o2, %o0
F005ED64: 1a800006                 bcc     loc_F005ED7C
F005ED68: 92100019                 mov     %i1, %o1
F005ED6C: 90100009                 mov     %o1, %o0
F005ED70: 4000250c                 call    _kfree
F005ED74: 9210000a                 mov     %o2, %o1
F005ED78: 30800004                 ba,a    locret_F005ED88
F005ED7C: 113c04f0                 sethi   %hi(_kalloc_map), %o0
F005ED80: 400092c1                 call    _kmem_free
F005ED84: d0022038                 ld      [%o0+%lo(_kalloc_map)], %o0
F005ED88: 81c7e008                 ret
F005ED8C: 81e80000                 restore
