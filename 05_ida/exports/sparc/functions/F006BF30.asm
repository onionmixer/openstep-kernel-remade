F006BF30: 9de3bf98                 save    %sp, -0x68, %sp
F006BF34: 113c04d2901221b0         set     _processor_ptr, %o0
F006BF3C: 932e2002                 sll     %i0, 2, %o1
F006BF40: e4024008                 ld      [%o1+%o0], %l2
F006BF44: 113c04d4a0122118         set     unk_F0135118, %l0
F006BF4C: d0040000                 ld      [%l0], %o0
F006BF50: 80a22000                 cmp     %o0, 0
F006BF54: 12bffffe                 bne     loc_F006BF4C
F006BF58: 01000000                 nop
F006BF5C: 4000abd3                 call    _simple_lock_try
F006BF60: 90100010                 mov     %l0, %o0
F006BF64: 80a22000                 cmp     %o0, 0
F006BF68: 02bffff9                 be      loc_F006BF4C
F006BF6C: 01000000                 nop
F006BF70: 4000ab06                 call    _splusclock
F006BF74: a004a13c                 add     %l2, 0x13C, %l0
F006BF78: a6100008                 mov     %o0, %l3
F006BF7C: d0040000                 ld      [%l0], %o0
F006BF80: 80a22000                 cmp     %o0, 0
F006BF84: 12bffffe                 bne     loc_F006BF7C
F006BF88: 01000000                 nop
F006BF8C: 4000abc7                 call    _simple_lock_try
F006BF90: 90100010                 mov     %l0, %o0
F006BF94: 80a22000                 cmp     %o0, 0
F006BF98: 02bffff9                 be      loc_F006BF7C
F006BF9C: 932e2005                 sll     %i0, 5, %o1
F006BFA0: 113c04d190122360         set     _machine_slot, %o0
F006BFA8: 92024008                 add     %o1, %o0, %o1
F006BFAC: a2102001                 mov     1, %l1
F006BFB0: e222600c                 st      %l1, [%o1+0xC]
F006BFB4: 153c04f09412a040         set     _machine_info, %o2
F006BFBC: d202a00c                 ld      [%o2+0xC], %o1
F006BFC0: 213c04d3a01423c0         set     _default_pset, %l0
F006BFC8: 90100010                 mov     %l0, %o0
F006BFCC: 92026001                 inc     %o1
F006BFD0: d222a00c                 st      %o1, [%o2+0xC]
F006BFD4: 40000bd8                 call    _pset_add_processor
F006BFD8: 92100012                 mov     %l2, %o1
F006BFDC: e224a114                 st      %l1, [%l2+0x114]
F006BFE0: c024a13c                 clr     [%l2+0x13C]
F006BFE4: 4000ab50                 call    _splx
F006BFE8: 90100013                 mov     %l3, %o0
F006BFEC: c0242158                 clr     [%l0+0x158]
F006BFF0: 81c7e008                 ret
F006BFF4: 81e80000                 restore
