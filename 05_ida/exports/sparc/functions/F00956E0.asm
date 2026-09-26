F00956E0: 9132200c                 srl     %o0, 12, %o0
F00956E4: 912a200c                 sll     %o0, 12, %o0
F00956E8: 1b3c045c                 sethi   %hi(_v_mmu_flushpagectx), %o5
F00956EC: da0362d0                 ld      [%o5+%lo(_v_mmu_flushpagectx)], %o5
F00956F0: 81c34000                 jmp     %o5
F00956F4: 01000000                 nop
