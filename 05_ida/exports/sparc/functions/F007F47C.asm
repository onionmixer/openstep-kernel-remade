F007F47C: 9de3bf90                 save    %sp, -0x70, %sp
F007F480: d0062004                 ld      [%i0+4], %o0
F007F484: 80a22020                 cmp     %o0, 0x20 ! ' '
F007F488: 1280000c                 bne     loc_F007F4B8
F007F48C: 90103ed0                 mov     -0x130, %o0
F007F490: d0060000                 ld      [%i0], %o0
F007F494: 80a22000                 cmp     %o0, 0
F007F498: 06800007                 bl      loc_F007F4B4
F007F49C: 133c0444                 sethi   %hi(dword_F01113F4), %o1
F007F4A0: d0062018                 ld      [%i0+0x18], %o0
F007F4A4: d20263f4                 ld      [%o1+%lo(dword_F01113F4)], %o1
F007F4A8: 80a20009                 cmp     %o0, %o1
F007F4AC: 02800005                 be      loc_F007F4C0
F007F4B0: 01000000                 nop
F007F4B4: 90103ed0                 mov     -0x130, %o0
F007F4B8: 1080001e                 ba      locret_F007F530
F007F4BC: d026601c                 st      %o0, [%i1+0x1C]
F007F4C0: 7fffa16f                 call    _convert_port_to_thread
F007F4C4: d0062008                 ld      [%i0+8], %o0! target_act
F007F4C8: 92102400                 mov     0x400, %o1
F007F4CC: d227bff4                 st      %o1, [%fp+var_C]
F007F4D0: a0100008                 mov     %o0, %l0
F007F4D4: 9406602c                 add     %i1, 0x2C, %o2 ! ','! thread_info_out
F007F4D8: d206201c                 ld      [%i0+0x1C], %o1! flavor
F007F4DC: 7fffd892                 call    _thread_info
F007F4E0: 9607bff4                 add     %fp, var_C, %o3
F007F4E4: d026601c                 st      %o0, [%i1+0x1C]
F007F4E8: 7fffd3b1                 call    _thread_deallocate
F007F4EC: 90100010                 mov     %l0, %o0
F007F4F0: d006601c                 ld      [%i1+0x1C], %o0
F007F4F4: 80a22000                 cmp     %o0, 0
F007F4F8: 1280000e                 bne     locret_F007F530
F007F4FC: 113c0444                 sethi   %hi(dword_F01113F8), %o0
F007F500: d20223f8                 ld      [%o0+%lo(dword_F01113F8)], %o1
F007F504: d2266020                 st      %o1, [%i1+0x20]
F007F508: 901223f8                 bset    %lo(dword_F01113F8), %o0
F007F50C: d2022004                 ld      [%o0+4], %o1
F007F510: d2266024                 st      %o1, [%i1+0x24]
F007F514: d2022008                 ld      [%o0+8], %o1
F007F518: d007bff4                 ld      [%fp+var_C], %o0
F007F51C: d2266028                 st      %o1, [%i1+0x28]
F007F520: d0266028                 st      %o0, [%i1+0x28]
F007F524: 912a2002                 sll     %o0, 2, %o0
F007F528: 9002202c                 inc     0x2C, %o0 ! ','
F007F52C: d0266004                 st      %o0, [%i1+4]
F007F530: 81c7e008                 ret
F007F534: 81e80000                 restore
