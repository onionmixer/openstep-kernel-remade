F000CEAC: 9de3bf50                 save    %sp, -0xB0, %sp! int
F000CEB0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000CEB4: a407bfb0                 add     %fp, var_50, %l2
F000CEB8: 92100012                 mov     %l2, %o1
F000CEBC: d40221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o2
F000CEC0: 193c0033                 sethi   %hi(_wait3), %o4
F000CEC4: da02a024                 ld      [%o2+0x24], %o5! int
F000CEC8: 96102000                 mov     0, %o3! int
F000CECC: d0036004                 ld      [%o5+4], %o0
F000CED0: 981322ac                 bset    %lo(_wait3), %o4! int
F000CED4: e2036008                 ld      [%o5+8], %l1
F000CED8: 40000012                 call    _wait1
F000CEDC: 9402a034                 inc     0x34, %o2 ! '4'! int
F000CEE0: a0920000                 orcc    %o0, %g0, %l0
F000CEE4: 02800005                 be      loc_F000CEF8
F000CEE8: 80a46000                 cmp     %l1, 0
F000CEEC: 40026f1a                 call    _unix_syscall_return
F000CEF0: 01000000                 nop
F000CEF4: 80a46000                 cmp     %l1, 0
F000CEF8: 02800006                 be      loc_F000CF10
F000CEFC: 90100012                 mov     %l2, %o0! int
F000CF00: 92100011                 mov     %l1, %o1! int
F000CF04: 40022c72                 call    _copyout
F000CF08: 94102048                 mov     0x48, %o2 ! 'H'
F000CF0C: a0100008                 mov     %o0, %l0
F000CF10: 40026f11                 call    _unix_syscall_return
F000CF14: 90100010                 mov     %l0, %o0
F000CF18: 81c7e008                 ret
F000CF1C: 81e80000                 restore
