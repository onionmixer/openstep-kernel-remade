F007EC94: 9de3bf98                 save    %sp, -0x68, %sp
F007EC98: d0062004                 ld      [%i0+4], %o0
F007EC9C: 80a22020                 cmp     %o0, 0x20 ! ' '
F007ECA0: 1280000c                 bne     loc_F007ECD0
F007ECA4: 90103ed0                 mov     -0x130, %o0
F007ECA8: d0060000                 ld      [%i0], %o0
F007ECAC: 80a22000                 cmp     %o0, 0
F007ECB0: 06800007                 bl      loc_F007ECCC
F007ECB4: 133c0444                 sethi   %hi(dword_F01113A4), %o1
F007ECB8: d0062018                 ld      [%i0+0x18], %o0
F007ECBC: d20263a4                 ld      [%o1+%lo(dword_F01113A4)], %o1
F007ECC0: 80a20009                 cmp     %o0, %o1
F007ECC4: 02800005                 be      loc_F007ECD8
F007ECC8: 01000000                 nop
F007ECCC: 90103ed0                 mov     -0x130, %o0
F007ECD0: 10800013                 ba      locret_F007ED1C
F007ECD4: d026601c                 st      %o0, [%i1+0x1C]
F007ECD8: 7fffa307                 call    _convert_port_to_task
F007ECDC: d0062008                 ld      [%i0+8], %o0
F007ECE0: a0100008                 mov     %o0, %l0
F007ECE4: d206201c                 ld      [%i0+0x1C], %o1
F007ECE8: 7fffb473                 call    _xxx_slot_info
F007ECEC: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007ECF0: d026601c                 st      %o0, [%i1+0x1C]
F007ECF4: 7fffd0ed                 call    _task_deallocate
F007ECF8: 90100010                 mov     %l0, %o0
F007ECFC: d006601c                 ld      [%i1+0x1C], %o0
F007ED00: 80a22000                 cmp     %o0, 0
F007ED04: 12800006                 bne     locret_F007ED1C
F007ED08: 90102044                 mov     0x44, %o0 ! 'D'
F007ED0C: d0266004                 st      %o0, [%i1+4]
F007ED10: 113c0444                 sethi   %hi(dword_F01113A8), %o0
F007ED14: d00223a8                 ld      [%o0+%lo(dword_F01113A8)], %o0
F007ED18: d0266020                 st      %o0, [%i1+0x20]
F007ED1C: 81c7e008                 ret
F007ED20: 81e80000                 restore
