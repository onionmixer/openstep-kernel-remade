F007FC04: 9de3bf98                 save    %sp, -0x68, %sp
F007FC08: d0062004                 ld      [%i0+4], %o0
F007FC0C: 80a22028                 cmp     %o0, 0x28 ! '('
F007FC10: 12800014                 bne     loc_F007FC60
F007FC14: 90103ed0                 mov     -0x130, %o0
F007FC18: d0060000                 ld      [%i0], %o0
F007FC1C: 80a22000                 cmp     %o0, 0
F007FC20: 16800010                 bge     loc_F007FC60
F007FC24: 90103ed0                 mov     -0x130, %o0
F007FC28: d2062018                 ld      [%i0+0x18], %o1
F007FC2C: 1104480090122018         set     0x11200018, %o0
F007FC34: 920a7ffc                 and     %o1, -4, %o1
F007FC38: 80a24008                 cmp     %o1, %o0
F007FC3C: 12800009                 bne     loc_F007FC60
F007FC40: 90103ed0                 mov     -0x130, %o0
F007FC44: d0062020                 ld      [%i0+0x20], %o0
F007FC48: 133c0445                 sethi   %hi(dword_F0111478), %o1
F007FC4C: d2026078                 ld      [%o1+%lo(dword_F0111478)], %o1
F007FC50: 80a20009                 cmp     %o0, %o1
F007FC54: 02800005                 be      loc_F007FC68
F007FC58: 01000000                 nop
F007FC5C: 90103ed0                 mov     -0x130, %o0
F007FC60: 1080000b                 ba      locret_F007FC8C
F007FC64: d026601c                 st      %o0, [%i1+0x1C]
F007FC68: 7fff9f43                 call    _convert_port_to_space
F007FC6C: d0062008                 ld      [%i0+8], %o0
F007FC70: d206201c                 ld      [%i0+0x1C], %o1
F007FC74: a0100008                 mov     %o0, %l0
F007FC78: 7fff8ea5                 call    _port_insert_send
F007FC7C: d4062024                 ld      [%i0+0x24], %o2
F007FC80: d026601c                 st      %o0, [%i1+0x1C]
F007FC84: 7fff9fcc                 call    _space_deallocate
F007FC88: 90100010                 mov     %l0, %o0
F007FC8C: 81c7e008                 ret
F007FC90: 81e80000                 restore
