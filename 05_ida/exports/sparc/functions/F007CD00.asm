F007CD00: 9de3bf98                 save    %sp, -0x68, %sp
F007CD04: d0062004                 ld      [%i0+4], %o0
F007CD08: 80a22028                 cmp     %o0, 0x28 ! '('
F007CD0C: 12800012                 bne     loc_F007CD54
F007CD10: 90103ed0                 mov     -0x130, %o0
F007CD14: d0060000                 ld      [%i0], %o0
F007CD18: 80a22000                 cmp     %o0, 0
F007CD1C: 0680000d                 bl      loc_F007CD50
F007CD20: 133c0444                 sethi   %hi(dword_F01110E4), %o1
F007CD24: d0062018                 ld      [%i0+0x18], %o0
F007CD28: d20260e4                 ld      [%o1+%lo(dword_F01110E4)], %o1
F007CD2C: 80a20009                 cmp     %o0, %o1
F007CD30: 12800009                 bne     loc_F007CD54
F007CD34: 90103ed0                 mov     -0x130, %o0
F007CD38: d0062020                 ld      [%i0+0x20], %o0
F007CD3C: 133c0444                 sethi   %hi(dword_F01110E8), %o1
F007CD40: d20260e8                 ld      [%o1+%lo(dword_F01110E8)], %o1
F007CD44: 80a20009                 cmp     %o0, %o1
F007CD48: 02800005                 be      loc_F007CD5C
F007CD4C: 01000000                 nop
F007CD50: 90103ed0                 mov     -0x130, %o0
F007CD54: 1080000b                 ba      locret_F007CD80
F007CD58: d026601c                 st      %o0, [%i1+0x1C]
F007CD5C: 7fffa1a1                 call    _convert_port_to_pset
F007CD60: d0062008                 ld      [%i0+8], %o0! processor_set
F007CD64: d206201c                 ld      [%i0+0x1C], %o1! max_priority
F007CD68: a0100008                 mov     %o0, %l0
F007CD6C: 7fffc9bc                 call    _processor_set_max_priority
F007CD70: d4062024                 ld      [%i0+0x24], %o2
F007CD74: d026601c                 st      %o0, [%i1+0x1C]
F007CD78: 7fffc8f0                 call    _pset_deallocate
F007CD7C: 90100010                 mov     %l0, %o0
F007CD80: 81c7e008                 ret
F007CD84: 81e80000                 restore
