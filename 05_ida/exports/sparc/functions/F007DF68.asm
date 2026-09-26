F007DF68: 9de3bf98                 save    %sp, -0x68, %sp
F007DF6C: d0062004                 ld      [%i0+4], %o0
F007DF70: 80a22020                 cmp     %o0, 0x20 ! ' '
F007DF74: 1280000c                 bne     loc_F007DFA4
F007DF78: 90103ed0                 mov     -0x130, %o0
F007DF7C: d0060000                 ld      [%i0], %o0
F007DF80: 80a22000                 cmp     %o0, 0
F007DF84: 06800007                 bl      loc_F007DFA0
F007DF88: 133c0444                 sethi   %hi(dword_F011128C), %o1
F007DF8C: d0062018                 ld      [%i0+0x18], %o0
F007DF90: d202628c                 ld      [%o1+%lo(dword_F011128C)], %o1
F007DF94: 80a20009                 cmp     %o0, %o1
F007DF98: 02800005                 be      loc_F007DFAC
F007DF9C: 01000000                 nop
F007DFA0: 90103ed0                 mov     -0x130, %o0
F007DFA4: 10800013                 ba      locret_F007DFF0
F007DFA8: d026601c                 st      %o0, [%i1+0x1C]
F007DFAC: 7fffa672                 call    _convert_port_to_space
F007DFB0: d0062008                 ld      [%i0+8], %o0
F007DFB4: a0100008                 mov     %o0, %l0
F007DFB8: d206201c                 ld      [%i0+0x1C], %o1
F007DFBC: 7fff9348                 call    _mach_port_get_receive_status
F007DFC0: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007DFC4: d026601c                 st      %o0, [%i1+0x1C]
F007DFC8: 7fffa6fb                 call    _space_deallocate
F007DFCC: 90100010                 mov     %l0, %o0
F007DFD0: d006601c                 ld      [%i1+0x1C], %o0
F007DFD4: 80a22000                 cmp     %o0, 0
F007DFD8: 12800006                 bne     locret_F007DFF0
F007DFDC: 90102048                 mov     0x48, %o0 ! 'H'
F007DFE0: d0266004                 st      %o0, [%i1+4]
F007DFE4: 113c0444                 sethi   %hi(dword_F0111290), %o0
F007DFE8: d0022290                 ld      [%o0+%lo(dword_F0111290)], %o0
F007DFEC: d0266020                 st      %o0, [%i1+0x20]
F007DFF0: 81c7e008                 ret
F007DFF4: 81e80000                 restore
