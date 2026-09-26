F007FAD4: 9de3bf98                 save    %sp, -0x68, %sp
F007FAD8: d0062004                 ld      [%i0+4], %o0
F007FADC: 80a22020                 cmp     %o0, 0x20 ! ' '
F007FAE0: 1280000c                 bne     loc_F007FB10
F007FAE4: 90103ed0                 mov     -0x130, %o0
F007FAE8: d0060000                 ld      [%i0], %o0
F007FAEC: 80a22000                 cmp     %o0, 0
F007FAF0: 06800007                 bl      loc_F007FB0C
F007FAF4: 133c0445                 sethi   %hi(dword_F0111464), %o1
F007FAF8: d0062018                 ld      [%i0+0x18], %o0
F007FAFC: d2026064                 ld      [%o1+%lo(dword_F0111464)], %o1
F007FB00: 80a20009                 cmp     %o0, %o1
F007FB04: 02800005                 be      loc_F007FB18
F007FB08: 01000000                 nop
F007FB0C: 90103ed0                 mov     -0x130, %o0
F007FB10: 1080000a                 ba      locret_F007FB38
F007FB14: d026601c                 st      %o0, [%i1+0x1C]
F007FB18: 7fff9f97                 call    _convert_port_to_space
F007FB1C: d0062008                 ld      [%i0+8], %o0
F007FB20: a0100008                 mov     %o0, %l0
F007FB24: 7fff8ec6                 call    _port_set_remove
F007FB28: d206201c                 ld      [%i0+0x1C], %o1
F007FB2C: d026601c                 st      %o0, [%i1+0x1C]
F007FB30: 7fffa021                 call    _space_deallocate
F007FB34: 90100010                 mov     %l0, %o0
F007FB38: 81c7e008                 ret
F007FB3C: 81e80000                 restore
