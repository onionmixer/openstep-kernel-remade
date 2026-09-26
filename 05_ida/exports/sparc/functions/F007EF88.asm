F007EF88: 9de3bf90                 save    %sp, -0x70, %sp
F007EF8C: d0062004                 ld      [%i0+4], %o0
F007EF90: 80a22020                 cmp     %o0, 0x20 ! ' '
F007EF94: 1280000c                 bne     loc_F007EFC4
F007EF98: 90103ed0                 mov     -0x130, %o0
F007EF9C: d0060000                 ld      [%i0], %o0
F007EFA0: 80a22000                 cmp     %o0, 0
F007EFA4: 06800007                 bl      loc_F007EFC0
F007EFA8: 133c0444                 sethi   %hi(dword_F01113C0), %o1
F007EFAC: d0062018                 ld      [%i0+0x18], %o0
F007EFB0: d20263c0                 ld      [%o1+%lo(dword_F01113C0)], %o1
F007EFB4: 80a20009                 cmp     %o0, %o1
F007EFB8: 02800005                 be      loc_F007EFCC
F007EFBC: 01000000                 nop
F007EFC0: 90103ed0                 mov     -0x130, %o0
F007EFC4: 1080001e                 ba      locret_F007F03C
F007EFC8: d026601c                 st      %o0, [%i1+0x1C]
F007EFCC: 7fffa24a                 call    _convert_port_to_task
F007EFD0: d0062008                 ld      [%i0+8], %o0! target_task
F007EFD4: 92102400                 mov     0x400, %o1
F007EFD8: d227bff4                 st      %o1, [%fp+var_C]
F007EFDC: a0100008                 mov     %o0, %l0
F007EFE0: 9406602c                 add     %i1, 0x2C, %o2 ! ','! task_info_out
F007EFE4: d206201c                 ld      [%i0+0x1C], %o1! flavor
F007EFE8: 7fffd2f1                 call    _task_info
F007EFEC: 9607bff4                 add     %fp, var_C, %o3
F007EFF0: d026601c                 st      %o0, [%i1+0x1C]
F007EFF4: 7fffd02d                 call    _task_deallocate
F007EFF8: 90100010                 mov     %l0, %o0
F007EFFC: d006601c                 ld      [%i1+0x1C], %o0
F007F000: 80a22000                 cmp     %o0, 0
F007F004: 1280000e                 bne     locret_F007F03C
F007F008: 113c0444                 sethi   %hi(dword_F01113C4), %o0
F007F00C: d20223c4                 ld      [%o0+%lo(dword_F01113C4)], %o1
F007F010: d2266020                 st      %o1, [%i1+0x20]
F007F014: 901223c4                 bset    %lo(dword_F01113C4), %o0
F007F018: d2022004                 ld      [%o0+4], %o1
F007F01C: d2266024                 st      %o1, [%i1+0x24]
F007F020: d2022008                 ld      [%o0+8], %o1
F007F024: d007bff4                 ld      [%fp+var_C], %o0
F007F028: d2266028                 st      %o1, [%i1+0x28]
F007F02C: d0266028                 st      %o0, [%i1+0x28]
F007F030: 912a2002                 sll     %o0, 2, %o0
F007F034: 9002202c                 inc     0x2C, %o0 ! ','
F007F038: d0266004                 st      %o0, [%i1+4]
F007F03C: 81c7e008                 ret
F007F040: 81e80000                 restore
