F000EE5C: 9de3bf98                 save    %sp, -0x68, %sp
F000EE60: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000EE64: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F000EE68: d2022024                 ld      [%o0+0x24], %o1
F000EE6C: d0024000                 ld      [%o1], %o0
F000EE70: 80a22000                 cmp     %o0, 0
F000EE74: 12800006                 bne     loc_F000EE8C
F000EE78: 901421dc                 or      %l0, %lo(dword_F0133DDC), %o0
F000EE7C: d0023ffc                 ld      [%o0-4], %o0
F000EE80: d0020000                 ld      [%o0], %o0
F000EE84: d0522030                 ldsh    [%o0+0x30], %o0
F000EE88: d0224000                 st      %o0, [%o1]
F000EE8C: 7ffffd8d                 call    _pfind
F000EE90: d0024000                 ld      [%o1], %o0
F000EE94: 80a22000                 cmp     %o0, 0
F000EE98: 12800005                 bne     loc_F000EEAC
F000EE9C: d20421dc                 ld      [%l0+0x1DC], %o1
F000EEA0: 90102003                 mov     3, %o0
F000EEA4: 10800004                 ba      locret_F000EEB4
F000EEA8: d02a6038                 stb     %o0, [%o1+0x38]
F000EEAC: d052202e                 ldsh    [%o0+0x2E], %o0
F000EEB0: d0226030                 st      %o0, [%o1+0x30]
F000EEB4: 81c7e008                 ret
F000EEB8: 81e80000                 restore
