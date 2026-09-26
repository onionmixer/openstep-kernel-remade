F005ECC8: 9de3bf90                 save    %sp, -0x70, %sp
F005ECCC: 113c0447                 sethi   %hi(_page_size), %o0
F005ECD0: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F005ECD4: 94100018                 mov     %i0, %o2
F005ECD8: 80a28008                 cmp     %o2, %o0
F005ECDC: 1a800006                 bcc     loc_F005ECF4
F005ECE0: 113c04f0                 sethi   -0xFEC4000, %o0
F005ECE4: 400024e3                 call    _kalloc
F005ECE8: 9010000a                 mov     %o2, %o0
F005ECEC: 10800008                 ba      loc_F005ED0C
F005ECF0: d027bff4                 st      %o0, [%fp+var_C]
F005ECF4: d0022038                 ld      [%o0+0x38], %o0
F005ECF8: 40009268                 call    _kmem_alloc
F005ECFC: 9207bff4                 add     %fp, var_C, %o1
F005ED00: 80a22000                 cmp     %o0, 0
F005ED04: 32800002                 bne,a   loc_F005ED0C
F005ED08: c027bff4                 clr     [%fp+var_C]
F005ED0C: f007bff4                 ld      [%fp+var_C], %i0
F005ED10: 81c7e008                 ret
F005ED14: 81e80000                 restore
