F007F6A0: 9de3bf98                 save    %sp, -0x68, %sp
F007F6A4: d0062004                 ld      [%i0+4], %o0
F007F6A8: 80a22028                 cmp     %o0, 0x28 ! '('
F007F6AC: 12800012                 bne     loc_F007F6F4
F007F6B0: 90103ed0                 mov     -0x130, %o0
F007F6B4: d0060000                 ld      [%i0], %o0
F007F6B8: 80a22000                 cmp     %o0, 0
F007F6BC: 0680000d                 bl      loc_F007F6F0
F007F6C0: 133c0445                 sethi   %hi(dword_F0111424), %o1
F007F6C4: d0062018                 ld      [%i0+0x18], %o0
F007F6C8: d2026024                 ld      [%o1+%lo(dword_F0111424)], %o1
F007F6CC: 80a20009                 cmp     %o0, %o1
F007F6D0: 12800009                 bne     loc_F007F6F4
F007F6D4: 90103ed0                 mov     -0x130, %o0
F007F6D8: d0062020                 ld      [%i0+0x20], %o0
F007F6DC: 133c0445                 sethi   %hi(dword_F0111428), %o1
F007F6E0: d2026028                 ld      [%o1+%lo(dword_F0111428)], %o1
F007F6E4: 80a20009                 cmp     %o0, %o1
F007F6E8: 02800005                 be      loc_F007F6FC
F007F6EC: 01000000                 nop
F007F6F0: 90103ed0                 mov     -0x130, %o0
F007F6F4: 1080000b                 ba      locret_F007F720
F007F6F8: d026601c                 st      %o0, [%i1+0x1C]
F007F6FC: 7fffa09e                 call    _convert_port_to_space
F007F700: d0062008                 ld      [%i0+8], %o0
F007F704: d206201c                 ld      [%i0+0x1C], %o1
F007F708: a0100008                 mov     %o0, %l0
F007F70C: 7fff8e8d                 call    _port_rename
F007F710: d4062024                 ld      [%i0+0x24], %o2
F007F714: d026601c                 st      %o0, [%i1+0x1C]
F007F718: 7fffa127                 call    _space_deallocate
F007F71C: 90100010                 mov     %l0, %o0
F007F720: 81c7e008                 ret
F007F724: 81e80000                 restore
