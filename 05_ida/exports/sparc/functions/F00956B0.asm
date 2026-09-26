F00956B0: 91322012                 srl     %o0, 18, %o0
F00956B4: 912a2012                 sll     %o0, 18, %o0
F00956B8: 1b3c045c                 sethi   %hi(_v_mmu_flushseg), %o5
F00956BC: da0362c8                 ld      [%o5+%lo(_v_mmu_flushseg)], %o5
F00956C0: 81c34000                 jmp     %o5
F00956C4: 01000000                 nop
