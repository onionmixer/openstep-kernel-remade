F007D5B4: 9de3bf98                 save    %sp, -0x68, %sp
F007D5B8: d0062004                 ld      [%i0+4], %o0
F007D5BC: 80a22028                 cmp     %o0, 0x28 ! '('
F007D5C0: 12800012                 bne     loc_F007D608
F007D5C4: 90103ed0                 mov     -0x130, %o0
F007D5C8: d0060000                 ld      [%i0], %o0
F007D5CC: 80a22000                 cmp     %o0, 0
F007D5D0: 0680000d                 bl      loc_F007D604
F007D5D4: 133c0444                 sethi   %hi(dword_F0111204), %o1
F007D5D8: d0062018                 ld      [%i0+0x18], %o0
F007D5DC: d2026204                 ld      [%o1+%lo(dword_F0111204)], %o1
F007D5E0: 80a20009                 cmp     %o0, %o1
F007D5E4: 12800009                 bne     loc_F007D608
F007D5E8: 90103ed0                 mov     -0x130, %o0
F007D5EC: d0062020                 ld      [%i0+0x20], %o0
F007D5F0: 133c0444                 sethi   %hi(dword_F0111208), %o1
F007D5F4: d2026208                 ld      [%o1+%lo(dword_F0111208)], %o1
F007D5F8: 80a20009                 cmp     %o0, %o1
F007D5FC: 02800005                 be      loc_F007D610
F007D600: 01000000                 nop
F007D604: 90103ed0                 mov     -0x130, %o0
F007D608: 1080000b                 ba      locret_F007D634
F007D60C: d026601c                 st      %o0, [%i1+0x1C]
F007D610: 7fffa8d9                 call    _convert_port_to_space
F007D614: d0062008                 ld      [%i0+8], %o0! task
F007D618: d206201c                 ld      [%i0+0x1C], %o1! old_name
F007D61C: a0100008                 mov     %o0, %l0
F007D620: 7fff9322                 call    _mach_port_rename
F007D624: d4062024                 ld      [%i0+0x24], %o2
F007D628: d026601c                 st      %o0, [%i1+0x1C]
F007D62C: 7fffa962                 call    _space_deallocate
F007D630: 90100010                 mov     %l0, %o0
F007D634: 81c7e008                 ret
F007D638: 81e80000                 restore
