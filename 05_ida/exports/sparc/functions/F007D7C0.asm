F007D7C0: 9de3bf98                 save    %sp, -0x68, %sp
F007D7C4: d0062004                 ld      [%i0+4], %o0
F007D7C8: 80a22020                 cmp     %o0, 0x20 ! ' '
F007D7CC: 1280000c                 bne     loc_F007D7FC
F007D7D0: 90103ed0                 mov     -0x130, %o0
F007D7D4: d0060000                 ld      [%i0], %o0
F007D7D8: 80a22000                 cmp     %o0, 0
F007D7DC: 06800007                 bl      loc_F007D7F8
F007D7E0: 133c0444                 sethi   %hi(dword_F0111220), %o1
F007D7E4: d0062018                 ld      [%i0+0x18], %o0
F007D7E8: d2026220                 ld      [%o1+%lo(dword_F0111220)], %o1! name
F007D7EC: 80a20009                 cmp     %o0, %o1
F007D7F0: 02800005                 be      loc_F007D804
F007D7F4: 01000000                 nop
F007D7F8: 90103ed0                 mov     -0x130, %o0
F007D7FC: 1080000a                 ba      locret_F007D824
F007D800: d026601c                 st      %o0, [%i1+0x1C]
F007D804: 7fffa85c                 call    _convert_port_to_space
F007D808: d0062008                 ld      [%i0+8], %o0! task
F007D80C: a0100008                 mov     %o0, %l0
F007D810: 7fff931e                 call    _mach_port_deallocate
F007D814: d206201c                 ld      [%i0+0x1C], %o1
F007D818: d026601c                 st      %o0, [%i1+0x1C]
F007D81C: 7fffa8e6                 call    _space_deallocate
F007D820: 90100010                 mov     %l0, %o0
F007D824: 81c7e008                 ret
F007D828: 81e80000                 restore
