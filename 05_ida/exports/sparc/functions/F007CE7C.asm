F007CE7C: 9de3bf98                 save    %sp, -0x68, %sp
F007CE80: d0062004                 ld      [%i0+4], %o0
F007CE84: 80a22028                 cmp     %o0, 0x28 ! '('
F007CE88: 12800012                 bne     loc_F007CED0
F007CE8C: 90103ed0                 mov     -0x130, %o0
F007CE90: d0060000                 ld      [%i0], %o0
F007CE94: 80a22000                 cmp     %o0, 0
F007CE98: 0680000d                 bl      loc_F007CECC
F007CE9C: 133c0444                 sethi   %hi(dword_F01110F8), %o1
F007CEA0: d0062018                 ld      [%i0+0x18], %o0
F007CEA4: d20260f8                 ld      [%o1+%lo(dword_F01110F8)], %o1
F007CEA8: 80a20009                 cmp     %o0, %o1
F007CEAC: 12800009                 bne     loc_F007CED0
F007CEB0: 90103ed0                 mov     -0x130, %o0
F007CEB4: d0062020                 ld      [%i0+0x20], %o0
F007CEB8: 133c0444                 sethi   %hi(dword_F01110FC), %o1
F007CEBC: d20260fc                 ld      [%o1+%lo(dword_F01110FC)], %o1
F007CEC0: 80a20009                 cmp     %o0, %o1
F007CEC4: 02800005                 be      loc_F007CED8
F007CEC8: 01000000                 nop
F007CECC: 90103ed0                 mov     -0x130, %o0
F007CED0: 1080000b                 ba      locret_F007CEFC
F007CED4: d026601c                 st      %o0, [%i1+0x1C]
F007CED8: 7fffa142                 call    _convert_port_to_pset
F007CEDC: d0062008                 ld      [%i0+8], %o0! processor_set
F007CEE0: d206201c                 ld      [%i0+0x1C], %o1! policy
F007CEE4: a0100008                 mov     %o0, %l0
F007CEE8: 7fffc99e                 call    _processor_set_policy_disable
F007CEEC: d4062024                 ld      [%i0+0x24], %o2
F007CEF0: d026601c                 st      %o0, [%i1+0x1C]
F007CEF4: 7fffc891                 call    _pset_deallocate
F007CEF8: 90100010                 mov     %l0, %o0
F007CEFC: 81c7e008                 ret
F007CF00: 81e80000                 restore
