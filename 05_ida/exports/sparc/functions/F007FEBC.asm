F007FEBC: 9de3bf98                 save    %sp, -0x68, %sp
F007FEC0: e2062004                 ld      [%i0+4], %l1
F007FEC4: 80a46028                 cmp     %l1, 0x28 ! '('
F007FEC8: 12800014                 bne     loc_F007FF18
F007FECC: 90103ed0                 mov     -0x130, %o0
F007FED0: d0060000                 ld      [%i0], %o0
F007FED4: 25200000                 sethi   0x80000000, %l2
F007FED8: 808a0012                 btst    %l2, %o0
F007FEDC: 0280000e                 be      loc_F007FF14
F007FEE0: 133c0445                 sethi   %hi(dword_F0111490), %o1
F007FEE4: d0062018                 ld      [%i0+0x18], %o0
F007FEE8: d2026090                 ld      [%o1+%lo(dword_F0111490)], %o1
F007FEEC: 80a20009                 cmp     %o0, %o1
F007FEF0: 1280000a                 bne     loc_F007FF18
F007FEF4: 90103ed0                 mov     -0x130, %o0
F007FEF8: d2062020                 ld      [%i0+0x20], %o1
F007FEFC: 1104480090122018         set     0x11200018, %o0
F007FF04: 920a7ffc                 and     %o1, -4, %o1
F007FF08: 80a24008                 cmp     %o1, %o0
F007FF0C: 02800005                 be      loc_F007FF20
F007FF10: 01000000                 nop
F007FF14: 90103ed0                 mov     -0x130, %o0
F007FF18: 10800017                 ba      locret_F007FF74
F007FF1C: d026601c                 st      %o0, [%i1+0x1C]
F007FF20: 7fff9e95                 call    _convert_port_to_space
F007FF24: d0062008                 ld      [%i0+8], %o0
F007FF28: a0100008                 mov     %o0, %l0
F007FF2C: d206201c                 ld      [%i0+0x1C], %o1
F007FF30: d4062024                 ld      [%i0+0x24], %o2
F007FF34: 7fff8cd8                 call    _port_set_backup
F007FF38: 96066024                 add     %i1, 0x24, %o3 ! '$'
F007FF3C: d026601c                 st      %o0, [%i1+0x1C]
F007FF40: 7fff9f1d                 call    _space_deallocate
F007FF44: 90100010                 mov     %l0, %o0
F007FF48: d006601c                 ld      [%i1+0x1C], %o0
F007FF4C: 80a22000                 cmp     %o0, 0
F007FF50: 12800009                 bne     locret_F007FF74
F007FF54: 01000000                 nop
F007FF58: d0064000                 ld      [%i1], %o0
F007FF5C: e2266004                 st      %l1, [%i1+4]
F007FF60: 90120012                 bset    %l2, %o0
F007FF64: d0264000                 st      %o0, [%i1]
F007FF68: 113c0445                 sethi   %hi(dword_F0111494), %o0
F007FF6C: d0022094                 ld      [%o0+%lo(dword_F0111494)], %o0
F007FF70: d0266020                 st      %o0, [%i1+0x20]
F007FF74: 81c7e008                 ret
F007FF78: 81e80000                 restore
