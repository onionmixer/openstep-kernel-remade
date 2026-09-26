F007F9E0: 9de3bf98                 save    %sp, -0x68, %sp
F007F9E4: d0062004                 ld      [%i0+4], %o0
F007F9E8: 80a22020                 cmp     %o0, 0x20 ! ' '
F007F9EC: 1280000c                 bne     loc_F007FA1C
F007F9F0: 90103ed0                 mov     -0x130, %o0
F007F9F4: d0060000                 ld      [%i0], %o0
F007F9F8: 80a22000                 cmp     %o0, 0
F007F9FC: 06800007                 bl      loc_F007FA18
F007FA00: 133c0445                 sethi   %hi(dword_F0111458), %o1
F007FA04: d0062018                 ld      [%i0+0x18], %o0
F007FA08: d2026058                 ld      [%o1+%lo(dword_F0111458)], %o1
F007FA0C: 80a20009                 cmp     %o0, %o1
F007FA10: 02800005                 be      loc_F007FA24
F007FA14: 01000000                 nop
F007FA18: 90103ed0                 mov     -0x130, %o0
F007FA1C: 1080000a                 ba      locret_F007FA44
F007FA20: d026601c                 st      %o0, [%i1+0x1C]
F007FA24: 7fff9fd4                 call    _convert_port_to_space
F007FA28: d0062008                 ld      [%i0+8], %o0
F007FA2C: a0100008                 mov     %o0, %l0
F007FA30: 7fff8eb6                 call    _port_set_deallocate
F007FA34: d206201c                 ld      [%i0+0x1C], %o1
F007FA38: d026601c                 st      %o0, [%i1+0x1C]
F007FA3C: 7fffa05e                 call    _space_deallocate
F007FA40: 90100010                 mov     %l0, %o0
F007FA44: 81c7e008                 ret
F007FA48: 81e80000                 restore
