F007DBDC: 9de3bf98                 save    %sp, -0x68, %sp
F007DBE0: d0062004                 ld      [%i0+4], %o0
F007DBE4: 80a22028                 cmp     %o0, 0x28 ! '('
F007DBE8: 12800012                 bne     loc_F007DC30
F007DBEC: 90103ed0                 mov     -0x130, %o0
F007DBF0: d0060000                 ld      [%i0], %o0
F007DBF4: 80a22000                 cmp     %o0, 0
F007DBF8: 0680000d                 bl      loc_F007DC2C
F007DBFC: 133c0444                 sethi   %hi(dword_F0111264), %o1
F007DC00: d0062018                 ld      [%i0+0x18], %o0
F007DC04: d2026264                 ld      [%o1+%lo(dword_F0111264)], %o1
F007DC08: 80a20009                 cmp     %o0, %o1
F007DC0C: 12800009                 bne     loc_F007DC30
F007DC10: 90103ed0                 mov     -0x130, %o0
F007DC14: d0062020                 ld      [%i0+0x20], %o0
F007DC18: 133c0444                 sethi   %hi(dword_F0111268), %o1
F007DC1C: d2026268                 ld      [%o1+%lo(dword_F0111268)], %o1
F007DC20: 80a20009                 cmp     %o0, %o1
F007DC24: 02800005                 be      loc_F007DC38
F007DC28: 01000000                 nop
F007DC2C: 90103ed0                 mov     -0x130, %o0
F007DC30: 1080000b                 ba      locret_F007DC5C
F007DC34: d026601c                 st      %o0, [%i1+0x1C]
F007DC38: 7fffa74f                 call    _convert_port_to_space
F007DC3C: d0062008                 ld      [%i0+8], %o0! task
F007DC40: d206201c                 ld      [%i0+0x1C], %o1! member
F007DC44: a0100008                 mov     %o0, %l0
F007DC48: 7fff937d                 call    _mach_port_move_member
F007DC4C: d4062024                 ld      [%i0+0x24], %o2
F007DC50: d026601c                 st      %o0, [%i1+0x1C]
F007DC54: 7fffa7d8                 call    _space_deallocate
F007DC58: 90100010                 mov     %l0, %o0
F007DC5C: 81c7e008                 ret
F007DC60: 81e80000                 restore
