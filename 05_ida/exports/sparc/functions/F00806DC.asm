F00806DC: 9de3bf98                 save    %sp, -0x68, %sp
F00806E0: d0062004                 ld      [%i0+4], %o0
F00806E4: 80a22020                 cmp     %o0, 0x20 ! ' '
F00806E8: 1280000c                 bne     loc_F0080718
F00806EC: 90103ed0                 mov     -0x130, %o0
F00806F0: d0060000                 ld      [%i0], %o0
F00806F4: 80a22000                 cmp     %o0, 0
F00806F8: 06800007                 bl      loc_F0080714
F00806FC: 133c0445                 sethi   %hi(dword_F01116B0), %o1
F0080700: d0062018                 ld      [%i0+0x18], %o0
F0080704: d20262b0                 ld      [%o1+%lo(dword_F01116B0)], %o1
F0080708: 80a20009                 cmp     %o0, %o1
F008070C: 02800005                 be      loc_F0080720
F0080710: 01000000                 nop
F0080714: 90103ed0                 mov     -0x130, %o0
F0080718: 10800013                 ba      locret_F0080764
F008071C: d026601c                 st      %o0, [%i1+0x1C]
F0080720: 7fff9c95                 call    _convert_port_to_space
F0080724: d0062008                 ld      [%i0+8], %o0! task
F0080728: a0100008                 mov     %o0, %l0
F008072C: d206201c                 ld      [%i0+0x1C], %o1! name
F0080730: 7fff79c9                 call    _mach_port_get_srights
F0080734: 94066024                 add     %i1, 0x24, %o2 ! '$'
F0080738: d026601c                 st      %o0, [%i1+0x1C]
F008073C: 7fff9d1e                 call    _space_deallocate
F0080740: 90100010                 mov     %l0, %o0
F0080744: d006601c                 ld      [%i1+0x1C], %o0
F0080748: 80a22000                 cmp     %o0, 0
F008074C: 12800006                 bne     locret_F0080764
F0080750: 90102028                 mov     0x28, %o0 ! '('
F0080754: d0266004                 st      %o0, [%i1+4]
F0080758: 113c0445                 sethi   %hi(dword_F01116B4), %o0
F008075C: d00222b4                 ld      [%o0+%lo(dword_F01116B4)], %o0
F0080760: d0266020                 st      %o0, [%i1+0x20]
F0080764: 81c7e008                 ret
F0080768: 81e80000                 restore
