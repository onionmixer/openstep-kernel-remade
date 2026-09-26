F007D978: 9de3bf98                 save    %sp, -0x68, %sp
F007D97C: d0062004                 ld      [%i0+4], %o0
F007D980: 80a22020                 cmp     %o0, 0x20 ! ' '
F007D984: 1280000c                 bne     loc_F007D9B4
F007D988: 90103ed0                 mov     -0x130, %o0
F007D98C: d0060000                 ld      [%i0], %o0
F007D990: 80a22000                 cmp     %o0, 0
F007D994: 06800007                 bl      loc_F007D9B0
F007D998: 133c0444                 sethi   %hi(dword_F011123C), %o1
F007D99C: d0062018                 ld      [%i0+0x18], %o0
F007D9A0: d202623c                 ld      [%o1+%lo(dword_F011123C)], %o1
F007D9A4: 80a20009                 cmp     %o0, %o1
F007D9A8: 02800005                 be      loc_F007D9BC
F007D9AC: 01000000                 nop
F007D9B0: 90103ed0                 mov     -0x130, %o0
F007D9B4: 10800013                 ba      locret_F007DA00
F007D9B8: d026601c                 st      %o0, [%i1+0x1C]
F007D9BC: 7fffa7ee                 call    _convert_port_to_space
F007D9C0: d0062008                 ld      [%i0+8], %o0
F007D9C4: a0100008                 mov     %o0, %l0
F007D9C8: d206201c                 ld      [%i0+0x1C], %o1
F007D9CC: 7fff9311                 call    _old_mach_port_get_receive_status
F007D9D0: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007D9D4: d026601c                 st      %o0, [%i1+0x1C]
F007D9D8: 7fffa877                 call    _space_deallocate
F007D9DC: 90100010                 mov     %l0, %o0
F007D9E0: d006601c                 ld      [%i1+0x1C], %o0
F007D9E4: 80a22000                 cmp     %o0, 0
F007D9E8: 12800006                 bne     locret_F007DA00
F007D9EC: 90102044                 mov     0x44, %o0 ! 'D'
F007D9F0: d0266004                 st      %o0, [%i1+4]
F007D9F4: 113c0444                 sethi   %hi(dword_F0111240), %o0
F007D9F8: d0022240                 ld      [%o0+%lo(dword_F0111240)], %o0
F007D9FC: d0266020                 st      %o0, [%i1+0x20]
F007DA00: 81c7e008                 ret
F007DA04: 81e80000                 restore
