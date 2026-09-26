F0012EC0: 9de3bf88                 save    %sp, -0x78, %sp! int
F0012EC4: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0012EC8: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0012ECC: d0022024                 ld      [%o0+0x24], %o0
F0012ED0: d0020000                 ld      [%o0], %o0! int
F0012ED4: 80a22000                 cmp     %o0, 0
F0012ED8: 0280000e                 be      locret_F0012F10
F0012EDC: a207bff0                 add     %fp, var_10, %l1
F0012EE0: 92100011                 mov     %l1, %o1! int
F0012EE4: 4002145d                 call    _copyin
F0012EE8: 94102008                 mov     8, %o2
F0012EEC: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0012EF0: d02a6038                 stb     %o0, [%o1+0x38]
F0012EF4: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0012EF8: d04a2038                 ldsb    [%o0+0x38], %o0
F0012EFC: 80a22000                 cmp     %o0, 0
F0012F00: 12800004                 bne     locret_F0012F10
F0012F04: 01000000                 nop
F0012F08: 40000004                 call    _setthetime
F0012F0C: 90100011                 mov     %l1, %o0
F0012F10: 81c7e008                 ret
F0012F14: 81e80000                 restore
