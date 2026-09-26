F0091A58: 9de3bf90                 save    %sp, -0x70, %sp
F0091A5C: d0062004                 ld      [%i0+4], %o0
F0091A60: 80a22020                 cmp     %o0, 0x20 ! ' '
F0091A64: 1280000c                 bne     loc_F0091A94
F0091A68: 90103ed0                 mov     -0x130, %o0
F0091A6C: d0060000                 ld      [%i0], %o0
F0091A70: 80a22000                 cmp     %o0, 0
F0091A74: 06800007                 bl      loc_F0091A90
F0091A78: 133c0448                 sethi   %hi(dword_F01122C8), %o1
F0091A7C: d0062018                 ld      [%i0+0x18], %o0
F0091A80: d20262c8                 ld      [%o1+%lo(dword_F01122C8)], %o1
F0091A84: 80a20009                 cmp     %o0, %o1
F0091A88: 02800005                 be      loc_F0091A9C
F0091A8C: 13000004                 sethi   0x1000, %o1
F0091A90: 90103ed0                 mov     -0x130, %o0
F0091A94: 1080001a                 ba      locret_F0091AFC
F0091A98: d026601c                 st      %o0, [%i1+0x1C]
F0091A9C: d0062008                 ld      [%i0+8], %o0
F0091AA0: 7fff4dfb                 call    _convert_port_to_host
F0091AA4: d227bff4                 st      %o1, [%fp+var_C]
F0091AA8: 9406602c                 add     %i1, 0x2C, %o2 ! ','
F0091AAC: d206201c                 ld      [%i0+0x1C], %o1
F0091AB0: 7ffffc6f                 call    _kern_IOGetSystemConfig
F0091AB4: 9607bff4                 add     %fp, var_C, %o3
F0091AB8: 80a22000                 cmp     %o0, 0
F0091ABC: 12800010                 bne     locret_F0091AFC
F0091AC0: d026601c                 st      %o0, [%i1+0x1C]
F0091AC4: 113c0448                 sethi   %hi(dword_F01122CC), %o0
F0091AC8: d20222cc                 ld      [%o0+%lo(dword_F01122CC)], %o1
F0091ACC: d2266020                 st      %o1, [%i1+0x20]
F0091AD0: 901222cc                 bset    %lo(dword_F01122CC), %o0
F0091AD4: d2022004                 ld      [%o0+4], %o1
F0091AD8: d2266024                 st      %o1, [%i1+0x24]
F0091ADC: d2022008                 ld      [%o0+8], %o1
F0091AE0: d007bff4                 ld      [%fp+var_C], %o0
F0091AE4: d2266028                 st      %o1, [%i1+0x28]
F0091AE8: d0266028                 st      %o0, [%i1+0x28]
F0091AEC: 90022003                 inc     3, %o0
F0091AF0: 900a3ffc                 and     %o0, -4, %o0
F0091AF4: 9002202c                 inc     0x2C, %o0 ! ','
F0091AF8: d0266004                 st      %o0, [%i1+4]
F0091AFC: 81c7e008                 ret
F0091B00: 81e80000                 restore
