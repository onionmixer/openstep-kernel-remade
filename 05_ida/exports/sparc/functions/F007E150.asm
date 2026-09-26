F007E150: 9de3bf90                 save    %sp, -0x70, %sp
F007E154: d0062004                 ld      [%i0+4], %o0
F007E158: 80a22020                 cmp     %o0, 0x20 ! ' '
F007E15C: 1280000e                 bne     loc_F007E194
F007E160: 90103ed0                 mov     -0x130, %o0
F007E164: d0060000                 ld      [%i0], %o0
F007E168: 23200000                 sethi   0x80000000, %l1
F007E16C: 808a0011                 btst    %l1, %o0
F007E170: 12800009                 bne     loc_F007E194
F007E174: 90103ed0                 mov     -0x130, %o0
F007E178: d0062018                 ld      [%i0+0x18], %o0
F007E17C: 133c0444                 sethi   %hi(dword_F01112EC), %o1
F007E180: d20262ec                 ld      [%o1+%lo(dword_F01112EC)], %o1
F007E184: 80a20009                 cmp     %o0, %o1
F007E188: 02800005                 be      loc_F007E19C
F007E18C: 01000000                 nop
F007E190: 90103ed0                 mov     -0x130, %o0
F007E194: 10800019                 ba      locret_F007E1F8
F007E198: d026601c                 st      %o0, [%i1+0x1C]
F007E19C: 7fffa5d6                 call    _convert_port_to_task
F007E1A0: d0062008                 ld      [%i0+8], %o0! target_task
F007E1A4: a0100008                 mov     %o0, %l0
F007E1A8: d206201c                 ld      [%i0+0x1C], %o1! ledgers
F007E1AC: 7fffd34b                 call    _task_create
F007E1B0: 9407bff4                 add     %fp, var_C, %o2
F007E1B4: d026601c                 st      %o0, [%i1+0x1C]
F007E1B8: 7fffd3bc                 call    _task_deallocate
F007E1BC: 90100010                 mov     %l0, %o0
F007E1C0: d006601c                 ld      [%i1+0x1C], %o0
F007E1C4: 80a22000                 cmp     %o0, 0
F007E1C8: 1280000c                 bne     locret_F007E1F8
F007E1CC: 92102028                 mov     0x28, %o1 ! '('
F007E1D0: d0064000                 ld      [%i1], %o0
F007E1D4: d2266004                 st      %o1, [%i1+4]
F007E1D8: 90120011                 bset    %l1, %o0
F007E1DC: d0264000                 st      %o0, [%i1]
F007E1E0: 113c0444                 sethi   %hi(dword_F01112F0), %o0
F007E1E4: d20222f0                 ld      [%o0+%lo(dword_F01112F0)], %o1
F007E1E8: d007bff4                 ld      [%fp+var_C], %o0
F007E1EC: 7fffa644                 call    _convert_task_to_port
F007E1F0: d2266020                 st      %o1, [%i1+0x20]
F007E1F4: d0266024                 st      %o0, [%i1+0x24]
F007E1F8: 81c7e008                 ret
F007E1FC: 81e80000                 restore
