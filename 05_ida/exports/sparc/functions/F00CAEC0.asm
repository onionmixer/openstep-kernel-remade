F00CAEC0: 9de3bf98                 save    %sp, -0x68, %sp
F00CAEC4: a6100018                 mov     %i0, %l3
F00CAEC8: ee07a05c                 ld      [%fp+arg_5C], %l7
F00CAECC: 113c0472                 sethi   %hi(_cdevsw), %o0
F00CAED0: ec07a064                 ld      [%fp+arg_64], %l6
F00CAED4: a01221f0                 or      %o0, %lo(_cdevsw), %l0
F00CAED8: ea07a068                 ld      [%fp+arg_68], %l5
F00CAEDC: 133c0474                 sethi   %hi(_nchrdev), %o1
F00CAEE0: d0026154                 ld      [%o1+%lo(_nchrdev)], %o0
F00CAEE4: b0102000                 mov     0, %i0
F00CAEE8: 80a60008                 cmp     %i0, %o0
F00CAEEC: 1680000f                 bge     loc_F00CAF28
F00CAEF0: e807a06c                 ld      [%fp+arg_6C], %l4
F00CAEF4: 253c04bb                 sethi   -0xFED1400, %l2
F00CAEF8: a2100009                 mov     %o1, %l1
F00CAEFC: 90100010                 mov     %l0, %o0! __s1
F00CAF00: 9214a070                 or      %l2, 0x70, %o1! __s2
F00CAF04: 7ffcec8d                 call    _memcmp
F00CAF08: 9410202c                 mov     0x2C, %o2 ! ','! __n
F00CAF0C: 80a22000                 cmp     %o0, 0
F00CAF10: 02800006                 be      loc_F00CAF28
F00CAF14: d0046154                 ld      [%l1+0x154], %o0
F00CAF18: b0062001                 inc     %i0
F00CAF1C: 80a60008                 cmp     %i0, %o0
F00CAF20: 06bffff7                 bl      loc_F00CAEFC
F00CAF24: a004202c                 inc     0x2C, %l0 ! ','
F00CAF28: 912e2001                 sll     %i0, 1, %o0
F00CAF2C: 90020018                 add     %o0, %i0, %o0
F00CAF30: 912a2002                 sll     %o0, 2, %o0
F00CAF34: 90220018                 sub     %o0, %i0, %o0
F00CAF38: a32a2002                 sll     %o0, 2, %l1
F00CAF3C: 113c0472a41221f0         set     _cdevsw, %l2
F00CAF44: 80a62000                 cmp     %i0, 0
F00CAF48: 0680000f                 bl      loc_F00CAF84
F00CAF4C: a0044012                 add     %l1, %l2, %l0
F00CAF50: 113c0474                 sethi   %hi(_nchrdev), %o0
F00CAF54: d0022154                 ld      [%o0+%lo(_nchrdev)], %o0
F00CAF58: 80a60008                 cmp     %i0, %o0
F00CAF5C: 36800017                 bge,a   locret_F00CAFB8
F00CAF60: b0103fff                 mov     -1, %i0
F00CAF64: 90100010                 mov     %l0, %o0! __s1
F00CAF68: 133c04bb92126070         set     off_F012EC70, %o1! __s2
F00CAF70: 7ffcec72                 call    _memcmp
F00CAF74: 9410202c                 mov     0x2C, %o2 ! ','
F00CAF78: 80a22000                 cmp     %o0, 0
F00CAF7C: 22800004                 be,a    loc_F00CAF8C
F00CAF80: e6244012                 st      %l3, [%l1+%l2]
F00CAF84: 1080000d                 ba      locret_F00CAFB8
F00CAF88: b0103fff                 mov     -1, %i0
F00CAF8C: f2242004                 st      %i1, [%l0+4]
F00CAF90: f4242008                 st      %i2, [%l0+8]
F00CAF94: f624200c                 st      %i3, [%l0+0xC]
F00CAF98: f8242010                 st      %i4, [%l0+0x10]
F00CAF9C: fa242014                 st      %i5, [%l0+0x14]
F00CAFA0: ee242018                 st      %l7, [%l0+0x18]
F00CAFA4: d607a060                 ld      [%fp+arg_60], %o3
F00CAFA8: ec242020                 st      %l6, [%l0+0x20]
F00CAFAC: ea242024                 st      %l5, [%l0+0x24]
F00CAFB0: e8242028                 st      %l4, [%l0+0x28]
F00CAFB4: d624201c                 st      %o3, [%l0+0x1C]
F00CAFB8: 81c7e008                 ret
F00CAFBC: 81e80000                 restore
