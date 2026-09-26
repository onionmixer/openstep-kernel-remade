F007FC94: 9de3bf98                 save    %sp, -0x68, %sp
F007FC98: d0062004                 ld      [%i0+4], %o0
F007FC9C: 80a22020                 cmp     %o0, 0x20 ! ' '
F007FCA0: 1280000e                 bne     loc_F007FCD8
F007FCA4: 90103ed0                 mov     -0x130, %o0
F007FCA8: d0060000                 ld      [%i0], %o0
F007FCAC: 23200000                 sethi   0x80000000, %l1
F007FCB0: 808a0011                 btst    %l1, %o0
F007FCB4: 12800009                 bne     loc_F007FCD8
F007FCB8: 90103ed0                 mov     -0x130, %o0
F007FCBC: d0062018                 ld      [%i0+0x18], %o0
F007FCC0: 133c0445                 sethi   %hi(dword_F011147C), %o1
F007FCC4: d202607c                 ld      [%o1+%lo(dword_F011147C)], %o1
F007FCC8: 80a20009                 cmp     %o0, %o1
F007FCCC: 02800005                 be      loc_F007FCE0
F007FCD0: 01000000                 nop
F007FCD4: 90103ed0                 mov     -0x130, %o0
F007FCD8: 10800016                 ba      locret_F007FD30
F007FCDC: d026601c                 st      %o0, [%i1+0x1C]
F007FCE0: 7fff9f25                 call    _convert_port_to_space
F007FCE4: d0062008                 ld      [%i0+8], %o0
F007FCE8: a0100008                 mov     %o0, %l0
F007FCEC: d206201c                 ld      [%i0+0x1C], %o1
F007FCF0: 7fff8eac                 call    _port_extract_send
F007FCF4: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007FCF8: d026601c                 st      %o0, [%i1+0x1C]
F007FCFC: 7fff9fae                 call    _space_deallocate
F007FD00: 90100010                 mov     %l0, %o0
F007FD04: d006601c                 ld      [%i1+0x1C], %o0
F007FD08: 80a22000                 cmp     %o0, 0
F007FD0C: 12800009                 bne     locret_F007FD30
F007FD10: 92102028                 mov     0x28, %o1 ! '('
F007FD14: d0064000                 ld      [%i1], %o0
F007FD18: d2266004                 st      %o1, [%i1+4]
F007FD1C: 90120011                 bset    %l1, %o0
F007FD20: d0264000                 st      %o0, [%i1]
F007FD24: 113c0445                 sethi   %hi(dword_F0111480), %o0
F007FD28: d0022080                 ld      [%o0+%lo(dword_F0111480)], %o0
F007FD2C: d0266020                 st      %o0, [%i1+0x20]
F007FD30: 81c7e008                 ret
F007FD34: 81e80000                 restore
