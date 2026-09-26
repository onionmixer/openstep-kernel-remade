F00051D8: a1480000                 rdhpr   %hpstate, %l0
F00051DC: 273c000c                 sethi   %hi(sys_trap), %l3
F00051E0: 81c4e170                 jmp     %l3+%lo(sys_trap)
F00051E4: a81020fe                 mov     0xFE, %l4
