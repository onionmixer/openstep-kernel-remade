F007D82C: 9de3bf98                 save    %sp, -0x68, %sp
F007D830: e2062004                 ld      [%i0+4], %l1
F007D834: 80a46028                 cmp     %l1, 0x28 ! '('
F007D838: 12800012                 bne     loc_F007D880
F007D83C: 90103ed0                 mov     -0x130, %o0
F007D840: d0060000                 ld      [%i0], %o0
F007D844: 80a22000                 cmp     %o0, 0
F007D848: 0680000d                 bl      loc_F007D87C
F007D84C: 133c0444                 sethi   %hi(dword_F0111224), %o1
F007D850: d0062018                 ld      [%i0+0x18], %o0
F007D854: d2026224                 ld      [%o1+%lo(dword_F0111224)], %o1
F007D858: 80a20009                 cmp     %o0, %o1
F007D85C: 12800009                 bne     loc_F007D880
F007D860: 90103ed0                 mov     -0x130, %o0
F007D864: d0062020                 ld      [%i0+0x20], %o0
F007D868: 133c0444                 sethi   %hi(dword_F0111228), %o1
F007D86C: d2026228                 ld      [%o1+%lo(dword_F0111228)], %o1
F007D870: 80a20009                 cmp     %o0, %o1
F007D874: 02800005                 be      loc_F007D888
F007D878: 01000000                 nop
F007D87C: 90103ed0                 mov     -0x130, %o0
F007D880: 10800013                 ba      locret_F007D8CC
F007D884: d026601c                 st      %o0, [%i1+0x1C]
F007D888: 7fffa83b                 call    _convert_port_to_space
F007D88C: d0062008                 ld      [%i0+8], %o0! task
F007D890: a0100008                 mov     %o0, %l0
F007D894: d206201c                 ld      [%i0+0x1C], %o1! name
F007D898: d4062024                 ld      [%i0+0x24], %o2! right
F007D89C: 7fff930e                 call    _mach_port_get_refs
F007D8A0: 96066024                 add     %i1, 0x24, %o3 ! '$'
F007D8A4: d026601c                 st      %o0, [%i1+0x1C]
F007D8A8: 7fffa8c3                 call    _space_deallocate
F007D8AC: 90100010                 mov     %l0, %o0
F007D8B0: d006601c                 ld      [%i1+0x1C], %o0
F007D8B4: 80a22000                 cmp     %o0, 0
F007D8B8: 12800005                 bne     locret_F007D8CC
F007D8BC: 113c0444                 sethi   %hi(dword_F011122C), %o0
F007D8C0: e2266004                 st      %l1, [%i1+4]
F007D8C4: d002222c                 ld      [%o0+%lo(dword_F011122C)], %o0
F007D8C8: d0266020                 st      %o0, [%i1+0x20]
F007D8CC: 81c7e008                 ret
F007D8D0: 81e80000                 restore
