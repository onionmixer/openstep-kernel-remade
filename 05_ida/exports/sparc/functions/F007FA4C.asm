F007FA4C: 9de3bf98                 save    %sp, -0x68, %sp
F007FA50: d0062004                 ld      [%i0+4], %o0
F007FA54: 80a22028                 cmp     %o0, 0x28 ! '('
F007FA58: 12800012                 bne     loc_F007FAA0
F007FA5C: 90103ed0                 mov     -0x130, %o0
F007FA60: d0060000                 ld      [%i0], %o0
F007FA64: 80a22000                 cmp     %o0, 0
F007FA68: 0680000d                 bl      loc_F007FA9C
F007FA6C: 133c0445                 sethi   %hi(dword_F011145C), %o1
F007FA70: d0062018                 ld      [%i0+0x18], %o0
F007FA74: d202605c                 ld      [%o1+%lo(dword_F011145C)], %o1
F007FA78: 80a20009                 cmp     %o0, %o1
F007FA7C: 12800009                 bne     loc_F007FAA0
F007FA80: 90103ed0                 mov     -0x130, %o0
F007FA84: d0062020                 ld      [%i0+0x20], %o0
F007FA88: 133c0445                 sethi   %hi(dword_F0111460), %o1
F007FA8C: d2026060                 ld      [%o1+%lo(dword_F0111460)], %o1
F007FA90: 80a20009                 cmp     %o0, %o1
F007FA94: 02800005                 be      loc_F007FAA8
F007FA98: 01000000                 nop
F007FA9C: 90103ed0                 mov     -0x130, %o0
F007FAA0: 1080000b                 ba      locret_F007FACC
F007FAA4: d026601c                 st      %o0, [%i1+0x1C]
F007FAA8: 7fff9fb3                 call    _convert_port_to_space
F007FAAC: d0062008                 ld      [%i0+8], %o0
F007FAB0: d206201c                 ld      [%i0+0x1C], %o1
F007FAB4: a0100008                 mov     %o0, %l0
F007FAB8: 7fff8ead                 call    _port_set_add
F007FABC: d4062024                 ld      [%i0+0x24], %o2
F007FAC0: d026601c                 st      %o0, [%i1+0x1C]
F007FAC4: 7fffa03c                 call    _space_deallocate
F007FAC8: 90100010                 mov     %l0, %o0
F007FACC: 81c7e008                 ret
F007FAD0: 81e80000                 restore
