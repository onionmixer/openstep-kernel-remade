F009565C: 133c04f6                 sethi   %hi(_contexts), %o1
F0095660: d20261d8                 ld      [%o1+%lo(_contexts)], %o1
F0095664: 952a2002                 sll     %o0, 2, %o2
F0095668: 9202400a                 add     %o1, %o2, %o1
F009566C: d2024000                 ld      [%o1], %o1
F0095670: 920a6003                 and     %o1, 3, %o1
F0095674: 80a26001                 cmp     %o1, 1
F0095678: 02800004                 be      loc_F0095688
F009567C: 92100008                 mov     %o0, %o1
F0095680: 81c3e008                 retl
F0095684: 01000000                 nop
F0095688: 1b3c045c                 sethi   %hi(_v_mmu_flushctx), %o5
F009568C: da0362c0                 ld      [%o5+%lo(_v_mmu_flushctx)], %o5
F0095690: 81c34000                 jmp     %o5
F0095694: 01000000                 nop
