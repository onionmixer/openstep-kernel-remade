F007DFF8: 9de3bf98                 save    %sp, -0x68, %sp
F007DFFC: d0062004                 ld      [%i0+4], %o0
F007E000: 80a22028                 cmp     %o0, 0x28 ! '('
F007E004: 12800012                 bne     loc_F007E04C
F007E008: 90103ed0                 mov     -0x130, %o0
F007E00C: d0060000                 ld      [%i0], %o0
F007E010: 80a22000                 cmp     %o0, 0
F007E014: 0680000d                 bl      loc_F007E048
F007E018: 133c0444                 sethi   %hi(dword_F0111294), %o1
F007E01C: d0062018                 ld      [%i0+0x18], %o0
F007E020: d2026294                 ld      [%o1+%lo(dword_F0111294)], %o1
F007E024: 80a20009                 cmp     %o0, %o1
F007E028: 12800009                 bne     loc_F007E04C
F007E02C: 90103ed0                 mov     -0x130, %o0
F007E030: d0062020                 ld      [%i0+0x20], %o0
F007E034: 133c0444                 sethi   %hi(dword_F0111298), %o1
F007E038: d2026298                 ld      [%o1+%lo(dword_F0111298)], %o1
F007E03C: 80a20009                 cmp     %o0, %o1
F007E040: 02800005                 be      loc_F007E054
F007E044: 01000000                 nop
F007E048: 90103ed0                 mov     -0x130, %o0
F007E04C: 1080000b                 ba      locret_F007E078
F007E050: d026601c                 st      %o0, [%i1+0x1C]
F007E054: 7fffa648                 call    _convert_port_to_space
F007E058: d0062008                 ld      [%i0+8], %o0! task
F007E05C: d206201c                 ld      [%i0+0x1C], %o1! name
F007E060: a0100008                 mov     %o0, %l0
F007E064: 7fff91af                 call    _mach_port_set_seqno
F007E068: d4062024                 ld      [%i0+0x24], %o2
F007E06C: d026601c                 st      %o0, [%i1+0x1C]
F007E070: 7fffa6d1                 call    _space_deallocate
F007E074: 90100010                 mov     %l0, %o0
F007E078: 81c7e008                 ret
F007E07C: 81e80000                 restore
