F005ED18: 9de3bf90                 save    %sp, -0x70, %sp
F005ED1C: 113c04f0                 sethi   %hi(_kalloc_map), %o0
F005ED20: d0022038                 ld      [%o0+%lo(_kalloc_map)], %o0
F005ED24: 92100019                 mov     %i1, %o1
F005ED28: 94100018                 mov     %i0, %o2
F005ED2C: 9607bff4                 add     %fp, var_C, %o3
F005ED30: 40009266                 call    _kmem_realloc
F005ED34: 9810001a                 mov     %i2, %o4
F005ED38: 80a22000                 cmp     %o0, 0
F005ED3C: 32800002                 bne,a   loc_F005ED44
F005ED40: c027bff4                 clr     [%fp+var_C]
F005ED44: f007bff4                 ld      [%fp+var_C], %i0
F005ED48: 81c7e008                 ret
F005ED4C: 81e80000                 restore
