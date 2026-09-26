F007F348: 9de3bf98                 save    %sp, -0x68, %sp
F007F34C: d0062004                 ld      [%i0+4], %o0
F007F350: 80a22020                 cmp     %o0, 0x20 ! ' '
F007F354: 1280000e                 bne     loc_F007F38C
F007F358: 90103ed0                 mov     -0x130, %o0
F007F35C: d0060000                 ld      [%i0], %o0
F007F360: 23200000                 sethi   0x80000000, %l1
F007F364: 808a0011                 btst    %l1, %o0
F007F368: 12800009                 bne     loc_F007F38C
F007F36C: 90103ed0                 mov     -0x130, %o0
F007F370: d0062018                 ld      [%i0+0x18], %o0
F007F374: 133c0444                 sethi   %hi(dword_F01113E8), %o1
F007F378: d20263e8                 ld      [%o1+%lo(dword_F01113E8)], %o1
F007F37C: 80a20009                 cmp     %o0, %o1
F007F380: 02800005                 be      loc_F007F394
F007F384: 01000000                 nop
F007F388: 90103ed0                 mov     -0x130, %o0
F007F38C: 10800016                 ba      locret_F007F3E4
F007F390: d026601c                 st      %o0, [%i1+0x1C]
F007F394: 7fffa1ba                 call    _convert_port_to_thread
F007F398: d0062008                 ld      [%i0+8], %o0! thr_act
F007F39C: a0100008                 mov     %o0, %l0
F007F3A0: d206201c                 ld      [%i0+0x1C], %o1! which_port
F007F3A4: 7fffa076                 call    _thread_get_special_port
F007F3A8: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007F3AC: d026601c                 st      %o0, [%i1+0x1C]
F007F3B0: 7fffd3ff                 call    _thread_deallocate
F007F3B4: 90100010                 mov     %l0, %o0
F007F3B8: d006601c                 ld      [%i1+0x1C], %o0
F007F3BC: 80a22000                 cmp     %o0, 0
F007F3C0: 12800009                 bne     locret_F007F3E4
F007F3C4: 92102028                 mov     0x28, %o1 ! '('
F007F3C8: d0064000                 ld      [%i1], %o0
F007F3CC: d2266004                 st      %o1, [%i1+4]
F007F3D0: 90120011                 bset    %l1, %o0
F007F3D4: d0264000                 st      %o0, [%i1]
F007F3D8: 113c0444                 sethi   %hi(dword_F01113EC), %o0
F007F3DC: d00223ec                 ld      [%o0+%lo(dword_F01113EC)], %o0
F007F3E0: d0266020                 st      %o0, [%i1+0x20]
F007F3E4: 81c7e008                 ret
F007F3E8: 81e80000                 restore
