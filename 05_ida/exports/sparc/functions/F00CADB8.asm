F00CADB8: 9de3bf98                 save    %sp, -0x68, %sp
F00CADBC: e607a05c                 ld      [%fp+arg_5C], %l3
F00CADC0: e81fa060                 ldd     [%fp+arg_60], %l4
F00CADC4: ec07a068                 ld      [%fp+arg_68], %l6
F00CADC8: 80a63fff                 cmp     %i0, -1
F00CADCC: 12800017                 bne     loc_F00CAE28
F00CADD0: ee07a06c                 ld      [%fp+arg_6C], %l7
F00CADD4: 113c0472a01221f0         set     _cdevsw, %l0
F00CADDC: 133c0474                 sethi   %hi(_nchrdev), %o1
F00CADE0: d0026154                 ld      [%o1+%lo(_nchrdev)], %o0
F00CADE4: b0102000                 mov     0, %i0
F00CADE8: 80a60008                 cmp     %i0, %o0
F00CADEC: 16800010                 bge     loc_F00CAE2C
F00CADF0: 912e2001                 sll     %i0, 1, %o0
F00CADF4: 253c04bb                 sethi   -0xFED1400, %l2
F00CADF8: a2100009                 mov     %o1, %l1
F00CADFC: 90100010                 mov     %l0, %o0! __s1
F00CAE00: 9214a070                 or      %l2, 0x70, %o1! __s2
F00CAE04: 7ffceccd                 call    _memcmp
F00CAE08: 9410202c                 mov     0x2C, %o2 ! ','! __n
F00CAE0C: 80a22000                 cmp     %o0, 0
F00CAE10: 02800006                 be      loc_F00CAE28
F00CAE14: d0046154                 ld      [%l1+0x154], %o0
F00CAE18: b0062001                 inc     %i0
F00CAE1C: 80a60008                 cmp     %i0, %o0
F00CAE20: 06bffff7                 bl      loc_F00CADFC
F00CAE24: a004202c                 inc     0x2C, %l0 ! ','
F00CAE28: 912e2001                 sll     %i0, 1, %o0
F00CAE2C: 90020018                 add     %o0, %i0, %o0
F00CAE30: 912a2002                 sll     %o0, 2, %o0
F00CAE34: 90220018                 sub     %o0, %i0, %o0
F00CAE38: a32a2002                 sll     %o0, 2, %l1
F00CAE3C: 113c0472a41221f0         set     _cdevsw, %l2
F00CAE44: 80a62000                 cmp     %i0, 0
F00CAE48: 0680000f                 bl      loc_F00CAE84
F00CAE4C: a0044012                 add     %l1, %l2, %l0
F00CAE50: 113c0474                 sethi   %hi(_nchrdev), %o0
F00CAE54: d0022154                 ld      [%o0+%lo(_nchrdev)], %o0
F00CAE58: 80a60008                 cmp     %i0, %o0
F00CAE5C: 36800017                 bge,a   locret_F00CAEB8
F00CAE60: b0103fff                 mov     -1, %i0
F00CAE64: 90100010                 mov     %l0, %o0! __s1
F00CAE68: 133c04bb92126070         set     off_F012EC70, %o1! __s2
F00CAE70: 7ffcecb2                 call    _memcmp
F00CAE74: 9410202c                 mov     0x2C, %o2 ! ','
F00CAE78: 80a22000                 cmp     %o0, 0
F00CAE7C: 22800004                 be,a    loc_F00CAE8C
F00CAE80: f2244012                 st      %i1, [%l1+%l2]
F00CAE84: 1080000d                 ba      locret_F00CAEB8
F00CAE88: b0103fff                 mov     -1, %i0
F00CAE8C: f4242004                 st      %i2, [%l0+4]
F00CAE90: f6242008                 st      %i3, [%l0+8]
F00CAE94: f824200c                 st      %i4, [%l0+0xC]
F00CAE98: fa242010                 st      %i5, [%l0+0x10]
F00CAE9C: e6242014                 st      %l3, [%l0+0x14]
F00CAEA0: e8242018                 st      %l4, [%l0+0x18]
F00CAEA4: ea24201c                 st      %l5, [%l0+0x1C]
F00CAEA8: ec242020                 st      %l6, [%l0+0x20]
F00CAEAC: ee242024                 st      %l7, [%l0+0x24]
F00CAEB0: d607a070                 ld      [%fp+arg_70], %o3
F00CAEB4: d6242028                 st      %o3, [%l0+0x28]
F00CAEB8: 81c7e008                 ret
F00CAEBC: 81e80000                 restore
