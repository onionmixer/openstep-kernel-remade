F007CF04: 9de3bf90                 save    %sp, -0x70, %sp
F007CF08: d0062004                 ld      [%i0+4], %o0
F007CF0C: 80a22018                 cmp     %o0, 0x18
F007CF10: 12800008                 bne     loc_F007CF30
F007CF14: 90103ed0                 mov     -0x130, %o0
F007CF18: d0060000                 ld      [%i0], %o0
F007CF1C: 23200000                 sethi   0x80000000, %l1
F007CF20: 808a0011                 btst    %l1, %o0
F007CF24: 02800005                 be      loc_F007CF38
F007CF28: 01000000                 nop
F007CF2C: 90103ed0                 mov     -0x130, %o0
F007CF30: 1080001d                 ba      locret_F007CFA4
F007CF34: d026601c                 st      %o0, [%i1+0x1C]
F007CF38: 7fffa12a                 call    _convert_port_to_pset
F007CF3C: d0062008                 ld      [%i0+8], %o0! processor_set
F007CF40: a0100008                 mov     %o0, %l0
F007CF44: 9206602c                 add     %i1, 0x2C, %o1 ! ','! task_list
F007CF48: 7fffca65                 call    _processor_set_tasks
F007CF4C: 9407bff4                 add     %fp, var_C, %o2
F007CF50: d026601c                 st      %o0, [%i1+0x1C]
F007CF54: 7fffc879                 call    _pset_deallocate
F007CF58: 90100010                 mov     %l0, %o0
F007CF5C: d006601c                 ld      [%i1+0x1C], %o0
F007CF60: 80a22000                 cmp     %o0, 0
F007CF64: 12800010                 bne     locret_F007CFA4
F007CF68: 92102030                 mov     0x30, %o1 ! '0'
F007CF6C: d0064000                 ld      [%i1], %o0
F007CF70: d2266004                 st      %o1, [%i1+4]
F007CF74: 90120011                 bset    %l1, %o0
F007CF78: d0264000                 st      %o0, [%i1]
F007CF7C: 113c0444                 sethi   %hi(dword_F0111100), %o0
F007CF80: d2022100                 ld      [%o0+%lo(dword_F0111100)], %o1
F007CF84: d2266020                 st      %o1, [%i1+0x20]
F007CF88: 90122100                 bset    %lo(dword_F0111100), %o0
F007CF8C: d2022004                 ld      [%o0+4], %o1
F007CF90: d2266024                 st      %o1, [%i1+0x24]
F007CF94: d0022008                 ld      [%o0+8], %o0
F007CF98: d207bff4                 ld      [%fp+var_C], %o1
F007CF9C: d0266028                 st      %o0, [%i1+0x28]
F007CFA0: d2266028                 st      %o1, [%i1+0x28]
F007CFA4: 81c7e008                 ret
F007CFA8: 81e80000                 restore
