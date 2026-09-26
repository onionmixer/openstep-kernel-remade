F007DA90: 9de3bf98                 save    %sp, -0x68, %sp
F007DA94: d0062004                 ld      [%i0+4], %o0
F007DA98: 80a22028                 cmp     %o0, 0x28 ! '('
F007DA9C: 12800012                 bne     loc_F007DAE4
F007DAA0: 90103ed0                 mov     -0x130, %o0
F007DAA4: d0060000                 ld      [%i0], %o0
F007DAA8: 80a22000                 cmp     %o0, 0
F007DAAC: 0680000d                 bl      loc_F007DAE0
F007DAB0: 133c0444                 sethi   %hi(dword_F011124C), %o1
F007DAB4: d0062018                 ld      [%i0+0x18], %o0
F007DAB8: d202624c                 ld      [%o1+%lo(dword_F011124C)], %o1
F007DABC: 80a20009                 cmp     %o0, %o1
F007DAC0: 12800009                 bne     loc_F007DAE4
F007DAC4: 90103ed0                 mov     -0x130, %o0
F007DAC8: d0062020                 ld      [%i0+0x20], %o0
F007DACC: 133c0444                 sethi   %hi(dword_F0111250), %o1
F007DAD0: d2026250                 ld      [%o1+%lo(dword_F0111250)], %o1
F007DAD4: 80a20009                 cmp     %o0, %o1
F007DAD8: 02800005                 be      loc_F007DAEC
F007DADC: 01000000                 nop
F007DAE0: 90103ed0                 mov     -0x130, %o0
F007DAE4: 1080000b                 ba      locret_F007DB10
F007DAE8: d026601c                 st      %o0, [%i1+0x1C]
F007DAEC: 7fffa7a2                 call    _convert_port_to_space
F007DAF0: d0062008                 ld      [%i0+8], %o0! task
F007DAF4: d206201c                 ld      [%i0+0x1C], %o1! name
F007DAF8: a0100008                 mov     %o0, %l0
F007DAFC: 7fff92f7                 call    _mach_port_set_mscount
F007DB00: d4062024                 ld      [%i0+0x24], %o2
F007DB04: d026601c                 st      %o0, [%i1+0x1C]
F007DB08: 7fffa82b                 call    _space_deallocate
F007DB0C: 90100010                 mov     %l0, %o0
F007DB10: 81c7e008                 ret
F007DB14: 81e80000                 restore
