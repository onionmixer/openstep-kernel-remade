F00956C8: 9132200c                 srl     %o0, 12, %o0
F00956CC: 912a200c                 sll     %o0, 12, %o0
F00956D0: 1b3c045c                 sethi   %hi(_v_mmu_flushpage), %o5
F00956D4: da0362cc                 ld      [%o5+%lo(_v_mmu_flushpage)], %o5
F00956D8: 81c34000                 jmp     %o5
F00956DC: 01000000                 nop
