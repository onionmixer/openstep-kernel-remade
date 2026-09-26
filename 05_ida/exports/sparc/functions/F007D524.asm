F007D524: 9de3bf98                 save    %sp, -0x68, %sp
F007D528: d0062004                 ld      [%i0+4], %o0
F007D52C: 80a22020                 cmp     %o0, 0x20 ! ' '
F007D530: 1280000c                 bne     loc_F007D560
F007D534: 90103ed0                 mov     -0x130, %o0
F007D538: d0060000                 ld      [%i0], %o0
F007D53C: 80a22000                 cmp     %o0, 0
F007D540: 06800007                 bl      loc_F007D55C
F007D544: 133c0444                 sethi   %hi(dword_F01111FC), %o1
F007D548: d0062018                 ld      [%i0+0x18], %o0
F007D54C: d20261fc                 ld      [%o1+%lo(dword_F01111FC)], %o1
F007D550: 80a20009                 cmp     %o0, %o1
F007D554: 02800005                 be      loc_F007D568
F007D558: 01000000                 nop
F007D55C: 90103ed0                 mov     -0x130, %o0
F007D560: 10800013                 ba      locret_F007D5AC
F007D564: d026601c                 st      %o0, [%i1+0x1C]
F007D568: 7fffa903                 call    _convert_port_to_space
F007D56C: d0062008                 ld      [%i0+8], %o0! task
F007D570: a0100008                 mov     %o0, %l0
F007D574: d206201c                 ld      [%i0+0x1C], %o1! name
F007D578: 7fff9334                 call    _mach_port_type
F007D57C: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007D580: d026601c                 st      %o0, [%i1+0x1C]
F007D584: 7fffa98c                 call    _space_deallocate
F007D588: 90100010                 mov     %l0, %o0
F007D58C: d006601c                 ld      [%i1+0x1C], %o0
F007D590: 80a22000                 cmp     %o0, 0
F007D594: 12800006                 bne     locret_F007D5AC
F007D598: 90102028                 mov     0x28, %o0 ! '('
F007D59C: d0266004                 st      %o0, [%i1+4]
F007D5A0: 113c0444                 sethi   %hi(dword_F0111200), %o0
F007D5A4: d0022200                 ld      [%o0+%lo(dword_F0111200)], %o0
F007D5A8: d0266020                 st      %o0, [%i1+0x20]
F007D5AC: 81c7e008                 ret
F007D5B0: 81e80000                 restore
