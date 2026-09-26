F007D6C4: 9de3bf98                 save    %sp, -0x68, %sp
F007D6C8: d0062004                 ld      [%i0+4], %o0
F007D6CC: 80a22020                 cmp     %o0, 0x20 ! ' '
F007D6D0: 1280000c                 bne     loc_F007D700
F007D6D4: 90103ed0                 mov     -0x130, %o0
F007D6D8: d0060000                 ld      [%i0], %o0
F007D6DC: 80a22000                 cmp     %o0, 0
F007D6E0: 06800007                 bl      loc_F007D6FC
F007D6E4: 133c0444                 sethi   %hi(dword_F0111214), %o1
F007D6E8: d0062018                 ld      [%i0+0x18], %o0
F007D6EC: d2026214                 ld      [%o1+%lo(dword_F0111214)], %o1
F007D6F0: 80a20009                 cmp     %o0, %o1
F007D6F4: 02800005                 be      loc_F007D708
F007D6F8: 01000000                 nop
F007D6FC: 90103ed0                 mov     -0x130, %o0
F007D700: 10800013                 ba      locret_F007D74C
F007D704: d026601c                 st      %o0, [%i1+0x1C]
F007D708: 7fffa89b                 call    _convert_port_to_space
F007D70C: d0062008                 ld      [%i0+8], %o0! task
F007D710: a0100008                 mov     %o0, %l0
F007D714: d206201c                 ld      [%i0+0x1C], %o1! right
F007D718: 7fff9323                 call    _mach_port_allocate
F007D71C: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007D720: d026601c                 st      %o0, [%i1+0x1C]
F007D724: 7fffa924                 call    _space_deallocate
F007D728: 90100010                 mov     %l0, %o0
F007D72C: d006601c                 ld      [%i1+0x1C], %o0
F007D730: 80a22000                 cmp     %o0, 0
F007D734: 12800006                 bne     locret_F007D74C
F007D738: 90102028                 mov     0x28, %o0 ! '('
F007D73C: d0266004                 st      %o0, [%i1+4]
F007D740: 113c0444                 sethi   %hi(dword_F0111218), %o0
F007D744: d0022218                 ld      [%o0+%lo(dword_F0111218)], %o0
F007D748: d0266020                 st      %o0, [%i1+0x20]
F007D74C: 81c7e008                 ret
F007D750: 81e80000                 restore
