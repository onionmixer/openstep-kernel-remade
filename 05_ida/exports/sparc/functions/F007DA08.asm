F007DA08: 9de3bf98                 save    %sp, -0x68, %sp
F007DA0C: d0062004                 ld      [%i0+4], %o0
F007DA10: 80a22028                 cmp     %o0, 0x28 ! '('
F007DA14: 12800012                 bne     loc_F007DA5C
F007DA18: 90103ed0                 mov     -0x130, %o0
F007DA1C: d0060000                 ld      [%i0], %o0
F007DA20: 80a22000                 cmp     %o0, 0
F007DA24: 0680000d                 bl      loc_F007DA58
F007DA28: 133c0444                 sethi   %hi(dword_F0111244), %o1
F007DA2C: d0062018                 ld      [%i0+0x18], %o0
F007DA30: d2026244                 ld      [%o1+%lo(dword_F0111244)], %o1
F007DA34: 80a20009                 cmp     %o0, %o1
F007DA38: 12800009                 bne     loc_F007DA5C
F007DA3C: 90103ed0                 mov     -0x130, %o0
F007DA40: d0062020                 ld      [%i0+0x20], %o0
F007DA44: 133c0444                 sethi   %hi(dword_F0111248), %o1
F007DA48: d2026248                 ld      [%o1+%lo(dword_F0111248)], %o1
F007DA4C: 80a20009                 cmp     %o0, %o1
F007DA50: 02800005                 be      loc_F007DA64
F007DA54: 01000000                 nop
F007DA58: 90103ed0                 mov     -0x130, %o0
F007DA5C: 1080000b                 ba      locret_F007DA88
F007DA60: d026601c                 st      %o0, [%i1+0x1C]
F007DA64: 7fffa7c4                 call    _convert_port_to_space
F007DA68: d0062008                 ld      [%i0+8], %o0
F007DA6C: d206201c                 ld      [%i0+0x1C], %o1
F007DA70: a0100008                 mov     %o0, %l0
F007DA74: 7fff9302                 call    _mach_port_set_qlimit
F007DA78: d4062024                 ld      [%i0+0x24], %o2
F007DA7C: d026601c                 st      %o0, [%i1+0x1C]
F007DA80: 7fffa84d                 call    _space_deallocate
F007DA84: 90100010                 mov     %l0, %o0
F007DA88: 81c7e008                 ret
F007DA8C: 81e80000                 restore
