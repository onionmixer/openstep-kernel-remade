F007F7A0: 9de3bf98                 save    %sp, -0x68, %sp
F007F7A4: d0062004                 ld      [%i0+4], %o0
F007F7A8: 80a22020                 cmp     %o0, 0x20 ! ' '
F007F7AC: 1280000c                 bne     loc_F007F7DC
F007F7B0: 90103ed0                 mov     -0x130, %o0
F007F7B4: d0060000                 ld      [%i0], %o0
F007F7B8: 80a22000                 cmp     %o0, 0
F007F7BC: 06800007                 bl      loc_F007F7D8
F007F7C0: 133c0445                 sethi   %hi(dword_F0111430), %o1
F007F7C4: d0062018                 ld      [%i0+0x18], %o0
F007F7C8: d2026030                 ld      [%o1+%lo(dword_F0111430)], %o1
F007F7CC: 80a20009                 cmp     %o0, %o1
F007F7D0: 02800005                 be      loc_F007F7E4
F007F7D4: 01000000                 nop
F007F7D8: 90103ed0                 mov     -0x130, %o0
F007F7DC: 1080000a                 ba      locret_F007F804
F007F7E0: d026601c                 st      %o0, [%i1+0x1C]
F007F7E4: 7fffa064                 call    _convert_port_to_space
F007F7E8: d0062008                 ld      [%i0+8], %o0
F007F7EC: a0100008                 mov     %o0, %l0
F007F7F0: 7fff8e71                 call    _port_deallocate
F007F7F4: d206201c                 ld      [%i0+0x1C], %o1
F007F7F8: d026601c                 st      %o0, [%i1+0x1C]
F007F7FC: 7fffa0ee                 call    _space_deallocate
F007F800: 90100010                 mov     %l0, %o0
F007F804: 81c7e008                 ret
F007F808: 81e80000                 restore
