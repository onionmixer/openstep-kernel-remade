F007FD38: 9de3bf98                 save    %sp, -0x68, %sp
F007FD3C: d0062004                 ld      [%i0+4], %o0
F007FD40: 80a22028                 cmp     %o0, 0x28 ! '('
F007FD44: 12800014                 bne     loc_F007FD94
F007FD48: 90103ed0                 mov     -0x130, %o0
F007FD4C: d0060000                 ld      [%i0], %o0
F007FD50: 80a22000                 cmp     %o0, 0
F007FD54: 16800010                 bge     loc_F007FD94
F007FD58: 90103ed0                 mov     -0x130, %o0
F007FD5C: d2062018                 ld      [%i0+0x18], %o1
F007FD60: 1104080090122018         set     0x10200018, %o0
F007FD68: 920a7ffc                 and     %o1, -4, %o1
F007FD6C: 80a24008                 cmp     %o1, %o0
F007FD70: 12800009                 bne     loc_F007FD94
F007FD74: 90103ed0                 mov     -0x130, %o0
F007FD78: d0062020                 ld      [%i0+0x20], %o0
F007FD7C: 133c0445                 sethi   %hi(dword_F0111484), %o1
F007FD80: d2026084                 ld      [%o1+%lo(dword_F0111484)], %o1
F007FD84: 80a20009                 cmp     %o0, %o1
F007FD88: 02800005                 be      loc_F007FD9C
F007FD8C: 01000000                 nop
F007FD90: 90103ed0                 mov     -0x130, %o0
F007FD94: 1080000b                 ba      locret_F007FDC0
F007FD98: d026601c                 st      %o0, [%i1+0x1C]
F007FD9C: 7fff9ef6                 call    _convert_port_to_space
F007FDA0: d0062008                 ld      [%i0+8], %o0
F007FDA4: d206201c                 ld      [%i0+0x1C], %o1
F007FDA8: a0100008                 mov     %o0, %l0
F007FDAC: 7fff8e8e                 call    _port_insert_receive
F007FDB0: d4062024                 ld      [%i0+0x24], %o2
F007FDB4: d026601c                 st      %o0, [%i1+0x1C]
F007FDB8: 7fff9f7f                 call    _space_deallocate
F007FDBC: 90100010                 mov     %l0, %o0
F007FDC0: 81c7e008                 ret
F007FDC4: 81e80000                 restore
