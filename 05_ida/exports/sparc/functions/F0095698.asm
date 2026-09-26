F0095698: 91322018                 srl     %o0, 24, %o0
F009569C: 912a2018                 sll     %o0, 24, %o0
F00956A0: 1b3c045c                 sethi   %hi(_v_mmu_flushrgn), %o5
F00956A4: da0362c4                 ld      [%o5+%lo(_v_mmu_flushrgn)], %o5
F00956A8: 81c34000                 jmp     %o5
F00956AC: 01000000                 nop
