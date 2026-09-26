F000CDE0: 9de3bf48                 save    %sp, -0xB8, %sp! int
F000CDE4: a407bfb0                 add     %fp, var_50, %l2
F000CDE8: 92100012                 mov     %l2, %o1
F000CDEC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000CDF0: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F000CDF4: a607bfac                 add     %fp, var_54, %l3
F000CDF8: e2022024                 ld      [%o0+0x24], %l1
F000CDFC: 94100013                 mov     %l3, %o2! int
F000CE00: d0046008                 ld      [%l1+8], %o0
F000CE04: 193c0033                 sethi   %hi(_wait4), %o4
F000CE08: d6044000                 ld      [%l1], %o3! int
F000CE0C: 40000045                 call    _wait1
F000CE10: 981321e0                 bset    %lo(_wait4), %o4! int
F000CE14: a0920000                 orcc    %o0, %g0, %l0
F000CE18: 22800005                 be,a    loc_F000CE2C
F000CE1C: d204600c                 ld      [%l1+0xC], %o1
F000CE20: 40026f4d                 call    _unix_syscall_return
F000CE24: 01000000                 nop
F000CE28: d204600c                 ld      [%l1+0xC], %o1! int
F000CE2C: 80a26000                 cmp     %o1, 0
F000CE30: 02800005                 be      loc_F000CE44
F000CE34: 90100012                 mov     %l2, %o0! int
F000CE38: 40022ca5                 call    _copyout
F000CE3C: 94102048                 mov     0x48, %o2 ! 'H'! int
F000CE40: a0100008                 mov     %o0, %l0
F000CE44: d2046004                 ld      [%l1+4], %o1! int
F000CE48: 80a26000                 cmp     %o1, 0
F000CE4C: 02800005                 be      loc_F000CE60
F000CE50: 90100013                 mov     %l3, %o0! int
F000CE54: 40022c9e                 call    _copyout
F000CE58: 94102004                 mov     4, %o2
F000CE5C: a0100008                 mov     %o0, %l0
F000CE60: 40026f3d                 call    _unix_syscall_return
F000CE64: 90100010                 mov     %l0, %o0
F000CE68: 81c7e008                 ret
F000CE6C: 81e80000                 restore
