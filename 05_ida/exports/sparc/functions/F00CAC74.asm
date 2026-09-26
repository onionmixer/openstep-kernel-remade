F00CAC74: 9de3bf98                 save    %sp, -0x68, %sp
F00CAC78: a6100018                 mov     %i0, %l3
F00CAC7C: 113c0471a01223ac         set     _bdevsw, %l0
F00CAC84: 133c0472                 sethi   %hi(_nblkdev), %o1
F00CAC88: d00261ec                 ld      [%o1+%lo(_nblkdev)], %o0
F00CAC8C: b0102000                 mov     0, %i0
F00CAC90: 80a60008                 cmp     %i0, %o0
F00CAC94: 16800010                 bge     loc_F00CACD4
F00CAC98: 912e2001                 sll     %i0, 1, %o0
F00CAC9C: 253c04bb                 sethi   -0xFED1400, %l2
F00CACA0: a2100009                 mov     %o1, %l1
F00CACA4: 90100010                 mov     %l0, %o0! __s1
F00CACA8: 9214a09c                 or      %l2, 0x9C, %o1! __s2
F00CACAC: 7ffced23                 call    _memcmp
F00CACB0: 94102018                 mov     0x18, %o2! __n
F00CACB4: 80a22000                 cmp     %o0, 0
F00CACB8: 02800006                 be      loc_F00CACD0
F00CACBC: d00461ec                 ld      [%l1+0x1EC], %o0
F00CACC0: b0062001                 inc     %i0
F00CACC4: 80a60008                 cmp     %i0, %o0
F00CACC8: 06bffff7                 bl      loc_F00CACA4
F00CACCC: a0042018                 inc     0x18, %l0
F00CACD0: 912e2001                 sll     %i0, 1, %o0
F00CACD4: 90020018                 add     %o0, %i0, %o0
F00CACD8: a32a2003                 sll     %o0, 3, %l1
F00CACDC: 113c0471a41223ac         set     _bdevsw, %l2
F00CACE4: 80a62000                 cmp     %i0, 0
F00CACE8: 0680000f                 bl      loc_F00CAD24
F00CACEC: a0044012                 add     %l1, %l2, %l0
F00CACF0: 113c0472                 sethi   %hi(_nblkdev), %o0
F00CACF4: d00221ec                 ld      [%o0+%lo(_nblkdev)], %o0
F00CACF8: 80a60008                 cmp     %i0, %o0
F00CACFC: 36800016                 bge,a   locret_F00CAD54
F00CAD00: b0103fff                 mov     -1, %i0
F00CAD04: 90100010                 mov     %l0, %o0! __s1
F00CAD08: 133c04bb9212609c         set     off_F012EC9C, %o1! __s2
F00CAD10: 7ffced0a                 call    _memcmp
F00CAD14: 94102018                 mov     0x18, %o2
F00CAD18: 80a22000                 cmp     %o0, 0
F00CAD1C: 22800004                 be,a    loc_F00CAD2C
F00CAD20: e6244012                 st      %l3, [%l1+%l2]
F00CAD24: 1080000c                 ba      locret_F00CAD54
F00CAD28: b0103fff                 mov     -1, %i0
F00CAD2C: f2242004                 st      %i1, [%l0+4]
F00CAD30: f4242008                 st      %i2, [%l0+8]
F00CAD34: f624200c                 st      %i3, [%l0+0xC]
F00CAD38: f8242010                 st      %i4, [%l0+0x10]
F00CAD3C: 912f6018                 sll     %i5, 24, %o0
F00CAD40: 80a22000                 cmp     %o0, 0
F00CAD44: 02800004                 be      locret_F00CAD54
F00CAD48: c0242014                 clr     [%l0+0x14]
F00CAD4C: 90102400                 mov     0x400, %o0
F00CAD50: d0242014                 st      %o0, [%l0+0x14]
F00CAD54: 81c7e008                 ret
F00CAD58: 81e80000                 restore
