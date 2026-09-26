F000CE70: 9de3bf90                 save    %sp, -0x70, %sp
F000CE74: 90102000                 mov     0, %o0
F000CE78: 193c0033                 sethi   %hi(_wait), %o4
F000CE7C: 92102000                 mov     0, %o1
F000CE80: 9407bff4                 add     %fp, var_C, %o2
F000CE84: 96102000                 mov     0, %o3
F000CE88: 40000026                 call    _wait1
F000CE8C: 98132270                 bset    %lo(_wait), %o4
F000CE90: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F000CE94: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F000CE98: d207bff4                 ld      [%fp+var_C], %o1
F000CE9C: 40026f2e                 call    _unix_syscall_return
F000CEA0: d222a034                 st      %o1, [%o2+0x34]
F000CEA4: 81c7e008                 ret
F000CEA8: 81e80000                 restore
