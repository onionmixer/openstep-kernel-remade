F007F1D4: 9de3bf90                 save    %sp, -0x70, %sp
F007F1D8: d0062004                 ld      [%i0+4], %o0
F007F1DC: 80a22020                 cmp     %o0, 0x20 ! ' '
F007F1E0: 1280000c                 bne     loc_F007F210
F007F1E4: 90103ed0                 mov     -0x130, %o0
F007F1E8: d0060000                 ld      [%i0], %o0
F007F1EC: 80a22000                 cmp     %o0, 0
F007F1F0: 06800007                 bl      loc_F007F20C
F007F1F4: 133c0444                 sethi   %hi(dword_F01113D4), %o1
F007F1F8: d0062018                 ld      [%i0+0x18], %o0
F007F1FC: d20263d4                 ld      [%o1+%lo(dword_F01113D4)], %o1
F007F200: 80a20009                 cmp     %o0, %o1
F007F204: 02800005                 be      loc_F007F218
F007F208: 01000000                 nop
F007F20C: 90103ed0                 mov     -0x130, %o0
F007F210: 1080001e                 ba      locret_F007F288
F007F214: d026601c                 st      %o0, [%i1+0x1C]
F007F218: 7fffa219                 call    _convert_port_to_thread
F007F21C: d0062008                 ld      [%i0+8], %o0! target_act
F007F220: 92102400                 mov     0x400, %o1
F007F224: d227bff4                 st      %o1, [%fp+var_C]
F007F228: a0100008                 mov     %o0, %l0
F007F22C: 9406602c                 add     %i1, 0x2C, %o2 ! ','! old_state
F007F230: d206201c                 ld      [%i0+0x1C], %o1! flavor
F007F234: 7fffd90a                 call    _thread_get_state
F007F238: 9607bff4                 add     %fp, var_C, %o3
F007F23C: d026601c                 st      %o0, [%i1+0x1C]
F007F240: 7fffd45b                 call    _thread_deallocate
F007F244: 90100010                 mov     %l0, %o0
F007F248: d006601c                 ld      [%i1+0x1C], %o0
F007F24C: 80a22000                 cmp     %o0, 0
F007F250: 1280000e                 bne     locret_F007F288
F007F254: 113c0444                 sethi   %hi(dword_F01113D8), %o0
F007F258: d20223d8                 ld      [%o0+%lo(dword_F01113D8)], %o1
F007F25C: d2266020                 st      %o1, [%i1+0x20]
F007F260: 901223d8                 bset    %lo(dword_F01113D8), %o0
F007F264: d2022004                 ld      [%o0+4], %o1
F007F268: d2266024                 st      %o1, [%i1+0x24]
F007F26C: d2022008                 ld      [%o0+8], %o1
F007F270: d007bff4                 ld      [%fp+var_C], %o0
F007F274: d2266028                 st      %o1, [%i1+0x28]
F007F278: d0266028                 st      %o0, [%i1+0x28]
F007F27C: 912a2002                 sll     %o0, 2, %o0
F007F280: 9002202c                 inc     0x2C, %o0 ! ','
F007F284: d0266004                 st      %o0, [%i1+4]
F007F288: 81c7e008                 ret
F007F28C: 81e80000                 restore
