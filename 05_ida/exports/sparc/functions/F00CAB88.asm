F00CAB88: 9de3bf98                 save    %sp, -0x68, %sp
F00CAB8C: 80a63fff                 cmp     %i0, -1
F00CAB90: 12800017                 bne     loc_F00CABEC
F00CAB94: e60fa05f                 ldub    [%fp+arg_5F], %l3
F00CAB98: 113c0471a01223ac         set     _bdevsw, %l0
F00CABA0: 133c0472                 sethi   %hi(_nblkdev), %o1
F00CABA4: d00261ec                 ld      [%o1+%lo(_nblkdev)], %o0
F00CABA8: b0102000                 mov     0, %i0
F00CABAC: 80a60008                 cmp     %i0, %o0
F00CABB0: 16800010                 bge     loc_F00CABF0
F00CABB4: 912e2001                 sll     %i0, 1, %o0
F00CABB8: 253c04bb                 sethi   -0xFED1400, %l2
F00CABBC: a2100009                 mov     %o1, %l1
F00CABC0: 90100010                 mov     %l0, %o0! __s1
F00CABC4: 9214a09c                 or      %l2, 0x9C, %o1! __s2
F00CABC8: 7ffced5c                 call    _memcmp
F00CABCC: 94102018                 mov     0x18, %o2! __n
F00CABD0: 80a22000                 cmp     %o0, 0
F00CABD4: 02800006                 be      loc_F00CABEC
F00CABD8: d00461ec                 ld      [%l1+0x1EC], %o0
F00CABDC: b0062001                 inc     %i0
F00CABE0: 80a60008                 cmp     %i0, %o0
F00CABE4: 06bffff7                 bl      loc_F00CABC0
F00CABE8: a0042018                 inc     0x18, %l0
F00CABEC: 912e2001                 sll     %i0, 1, %o0
F00CABF0: 90020018                 add     %o0, %i0, %o0
F00CABF4: a32a2003                 sll     %o0, 3, %l1
F00CABF8: 113c0471a41223ac         set     _bdevsw, %l2
F00CAC00: 80a62000                 cmp     %i0, 0
F00CAC04: 0680000f                 bl      loc_F00CAC40
F00CAC08: a0044012                 add     %l1, %l2, %l0
F00CAC0C: 113c0472                 sethi   %hi(_nblkdev), %o0
F00CAC10: d00221ec                 ld      [%o0+%lo(_nblkdev)], %o0
F00CAC14: 80a60008                 cmp     %i0, %o0
F00CAC18: 36800015                 bge,a   locret_F00CAC6C
F00CAC1C: b0103fff                 mov     -1, %i0
F00CAC20: 90100010                 mov     %l0, %o0! __s1
F00CAC24: 133c04bb9212609c         set     off_F012EC9C, %o1! __s2
F00CAC2C: 7ffced43                 call    _memcmp
F00CAC30: 94102018                 mov     0x18, %o2
F00CAC34: 80a22000                 cmp     %o0, 0
F00CAC38: 22800004                 be,a    loc_F00CAC48
F00CAC3C: f2244012                 st      %i1, [%l1+%l2]
F00CAC40: 1080000b                 ba      locret_F00CAC6C
F00CAC44: b0103fff                 mov     -1, %i0
F00CAC48: f4242004                 st      %i2, [%l0+4]
F00CAC4C: f6242008                 st      %i3, [%l0+8]
F00CAC50: f824200c                 st      %i4, [%l0+0xC]
F00CAC54: fa242010                 st      %i5, [%l0+0x10]
F00CAC58: 80a4e000                 cmp     %l3, 0
F00CAC5C: 02800004                 be      locret_F00CAC6C
F00CAC60: c0242014                 clr     [%l0+0x14]
F00CAC64: 90102400                 mov     0x400, %o0
F00CAC68: d0242014                 st      %o0, [%l0+0x14]
F00CAC6C: 81c7e008                 ret
F00CAC70: 81e80000                 restore
