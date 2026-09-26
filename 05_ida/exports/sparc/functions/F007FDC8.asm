F007FDC8: 9de3bf98                 save    %sp, -0x68, %sp
F007FDCC: d0062004                 ld      [%i0+4], %o0
F007FDD0: 80a22020                 cmp     %o0, 0x20 ! ' '
F007FDD4: 1280000e                 bne     loc_F007FE0C
F007FDD8: 90103ed0                 mov     -0x130, %o0
F007FDDC: d0060000                 ld      [%i0], %o0
F007FDE0: 23200000                 sethi   0x80000000, %l1
F007FDE4: 808a0011                 btst    %l1, %o0
F007FDE8: 12800009                 bne     loc_F007FE0C
F007FDEC: 90103ed0                 mov     -0x130, %o0
F007FDF0: d0062018                 ld      [%i0+0x18], %o0
F007FDF4: 133c0445                 sethi   %hi(dword_F0111488), %o1
F007FDF8: d2026088                 ld      [%o1+%lo(dword_F0111488)], %o1
F007FDFC: 80a20009                 cmp     %o0, %o1
F007FE00: 02800005                 be      loc_F007FE14
F007FE04: 01000000                 nop
F007FE08: 90103ed0                 mov     -0x130, %o0
F007FE0C: 1080002a                 ba      locret_F007FEB4
F007FE10: d026601c                 st      %o0, [%i1+0x1C]
F007FE14: 7fff9ed8                 call    _convert_port_to_space
F007FE18: d0062008                 ld      [%i0+8], %o0
F007FE1C: a0100008                 mov     %o0, %l0
F007FE20: d206201c                 ld      [%i0+0x1C], %o1
F007FE24: 7fff8e95                 call    _port_extract_receive
F007FE28: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007FE2C: d026601c                 st      %o0, [%i1+0x1C]
F007FE30: 7fff9f61                 call    _space_deallocate
F007FE34: 90100010                 mov     %l0, %o0
F007FE38: d006601c                 ld      [%i1+0x1C], %o0
F007FE3C: 80a22000                 cmp     %o0, 0
F007FE40: 1280001d                 bne     locret_F007FEB4
F007FE44: 92102028                 mov     0x28, %o1 ! '('
F007FE48: d0064000                 ld      [%i1], %o0
F007FE4C: d2266004                 st      %o1, [%i1+4]
F007FE50: 90120011                 bset    %l1, %o0
F007FE54: d0264000                 st      %o0, [%i1]
F007FE58: 113c0445                 sethi   %hi(dword_F011148C), %o0
F007FE5C: d002208c                 ld      [%o0+%lo(dword_F011148C)], %o0
F007FE60: d0266020                 st      %o0, [%i1+0x20]
F007FE64: d206200c                 ld      [%i0+0xC], %o1
F007FE68: 80a26000                 cmp     %o1, 0
F007FE6C: 02800012                 be      locret_F007FEB4
F007FE70: 80a27fff                 cmp     %o1, -1
F007FE74: 02800010                 be      locret_F007FEB4
F007FE78: 01000000                 nop
F007FE7C: d0066024                 ld      [%i1+0x24], %o0
F007FE80: 80a22000                 cmp     %o0, 0
F007FE84: 0280000c                 be      locret_F007FEB4
F007FE88: 80a23fff                 cmp     %o0, -1
F007FE8C: 0280000a                 be      locret_F007FEB4
F007FE90: 01000000                 nop
F007FE94: 7fff6bcc                 call    _ipc_port_check_circularity
F007FE98: 01000000                 nop
F007FE9C: 80a22000                 cmp     %o0, 0
F007FEA0: 02800005                 be      locret_F007FEB4
F007FEA4: 13100000                 sethi   0x40000000, %o1
F007FEA8: d0064000                 ld      [%i1], %o0
F007FEAC: 90120009                 bset    %o1, %o0
F007FEB0: d0264000                 st      %o0, [%i1]
F007FEB4: 81c7e008                 ret
F007FEB8: 81e80000                 restore
