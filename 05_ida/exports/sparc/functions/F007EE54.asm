F007EE54: 9de3bf98                 save    %sp, -0x68, %sp
F007EE58: d0062004                 ld      [%i0+4], %o0
F007EE5C: 80a22020                 cmp     %o0, 0x20 ! ' '
F007EE60: 1280000e                 bne     loc_F007EE98
F007EE64: 90103ed0                 mov     -0x130, %o0
F007EE68: d0060000                 ld      [%i0], %o0
F007EE6C: 23200000                 sethi   0x80000000, %l1
F007EE70: 808a0011                 btst    %l1, %o0
F007EE74: 12800009                 bne     loc_F007EE98
F007EE78: 90103ed0                 mov     -0x130, %o0
F007EE7C: d0062018                 ld      [%i0+0x18], %o0
F007EE80: 133c0444                 sethi   %hi(dword_F01113B4), %o1
F007EE84: d20263b4                 ld      [%o1+%lo(dword_F01113B4)], %o1
F007EE88: 80a20009                 cmp     %o0, %o1
F007EE8C: 02800005                 be      loc_F007EEA0
F007EE90: 01000000                 nop
F007EE94: 90103ed0                 mov     -0x130, %o0
F007EE98: 10800016                 ba      locret_F007EEF0
F007EE9C: d026601c                 st      %o0, [%i1+0x1C]
F007EEA0: 7fffa295                 call    _convert_port_to_task
F007EEA4: d0062008                 ld      [%i0+8], %o0! task
F007EEA8: a0100008                 mov     %o0, %l0
F007EEAC: d206201c                 ld      [%i0+0x1C], %o1! which_port
F007EEB0: 7fffa126                 call    _task_get_special_port
F007EEB4: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007EEB8: d026601c                 st      %o0, [%i1+0x1C]
F007EEBC: 7fffd07b                 call    _task_deallocate
F007EEC0: 90100010                 mov     %l0, %o0
F007EEC4: d006601c                 ld      [%i1+0x1C], %o0
F007EEC8: 80a22000                 cmp     %o0, 0
F007EECC: 12800009                 bne     locret_F007EEF0
F007EED0: 92102028                 mov     0x28, %o1 ! '('
F007EED4: d0064000                 ld      [%i1], %o0
F007EED8: d2266004                 st      %o1, [%i1+4]
F007EEDC: 90120011                 bset    %l1, %o0
F007EEE0: d0264000                 st      %o0, [%i1]
F007EEE4: 113c0444                 sethi   %hi(dword_F01113B8), %o0
F007EEE8: d00223b8                 ld      [%o0+%lo(dword_F01113B8)], %o0
F007EEEC: d0266020                 st      %o0, [%i1+0x20]
F007EEF0: 81c7e008                 ret
F007EEF4: 81e80000                 restore
