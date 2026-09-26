F0012E78: 9de3bf90                 save    %sp, -0x70, %sp! int
F0012E7C: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0012E80: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0012E84: e2022024                 ld      [%o0+0x24], %l1
F0012E88: d0044000                 ld      [%l1], %o0
F0012E8C: 80a22000                 cmp     %o0, 0
F0012E90: 0280000a                 be      locret_F0012EB8
F0012E94: a007bff0                 add     %fp, var_10, %l0
F0012E98: 40016dce                 call    _microtime
F0012E9C: 90100010                 mov     %l0, %o0
F0012EA0: 90100010                 mov     %l0, %o0! int
F0012EA4: d2044000                 ld      [%l1], %o1! int
F0012EA8: 40021489                 call    _copyout
F0012EAC: 94102008                 mov     8, %o2
F0012EB0: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0012EB4: d02a6038                 stb     %o0, [%o1+0x38]
F0012EB8: 81c7e008                 ret
F0012EBC: 81e80000                 restore
