F007D63C: 9de3bf98                 save    %sp, -0x68, %sp
F007D640: d0062004                 ld      [%i0+4], %o0
F007D644: 80a22028                 cmp     %o0, 0x28 ! '('
F007D648: 12800012                 bne     loc_F007D690
F007D64C: 90103ed0                 mov     -0x130, %o0
F007D650: d0060000                 ld      [%i0], %o0
F007D654: 80a22000                 cmp     %o0, 0
F007D658: 0680000d                 bl      loc_F007D68C
F007D65C: 133c0444                 sethi   %hi(dword_F011120C), %o1
F007D660: d0062018                 ld      [%i0+0x18], %o0
F007D664: d202620c                 ld      [%o1+%lo(dword_F011120C)], %o1
F007D668: 80a20009                 cmp     %o0, %o1
F007D66C: 12800009                 bne     loc_F007D690
F007D670: 90103ed0                 mov     -0x130, %o0
F007D674: d0062020                 ld      [%i0+0x20], %o0
F007D678: 133c0444                 sethi   %hi(dword_F0111210), %o1
F007D67C: d2026210                 ld      [%o1+%lo(dword_F0111210)], %o1
F007D680: 80a20009                 cmp     %o0, %o1
F007D684: 02800005                 be      loc_F007D698
F007D688: 01000000                 nop
F007D68C: 90103ed0                 mov     -0x130, %o0
F007D690: 1080000b                 ba      locret_F007D6BC
F007D694: d026601c                 st      %o0, [%i1+0x1C]
F007D698: 7fffa8b7                 call    _convert_port_to_space
F007D69C: d0062008                 ld      [%i0+8], %o0! task
F007D6A0: d206201c                 ld      [%i0+0x1C], %o1! right
F007D6A4: a0100008                 mov     %o0, %l0
F007D6A8: 7fff9314                 call    _mach_port_allocate_name
F007D6AC: d4062024                 ld      [%i0+0x24], %o2
F007D6B0: d026601c                 st      %o0, [%i1+0x1C]
F007D6B4: 7fffa940                 call    _space_deallocate
F007D6B8: 90100010                 mov     %l0, %o0
F007D6BC: 81c7e008                 ret
F007D6C0: 81e80000                 restore
