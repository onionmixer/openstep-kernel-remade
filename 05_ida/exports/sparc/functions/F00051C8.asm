F00051C8: a1480000                 rdhpr   %hpstate, %l0
F00051CC: 273c000c                 sethi   %hi(sys_trap), %l3
F00051D0: 81c4e170                 jmp     %l3+%lo(sys_trap)
F00051D4: a81020ff                 mov     0xFF, %l4
