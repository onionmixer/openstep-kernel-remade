F007E608: 9de3bf90                 save    %sp, -0x70, %sp
F007E60C: d0062004                 ld      [%i0+4], %o0
F007E610: 80a22028                 cmp     %o0, 0x28 ! '('
F007E614: 12800014                 bne     loc_F007E664
F007E618: 90103ed0                 mov     -0x130, %o0
F007E61C: d0060000                 ld      [%i0], %o0
F007E620: 23200000                 sethi   0x80000000, %l1
F007E624: 808a0011                 btst    %l1, %o0
F007E628: 1280000f                 bne     loc_F007E664
F007E62C: 90103ed0                 mov     -0x130, %o0
F007E630: d0062018                 ld      [%i0+0x18], %o0
F007E634: 133c0444                 sethi   %hi(dword_F0111334), %o1
F007E638: d2026334                 ld      [%o1+%lo(dword_F0111334)], %o1
F007E63C: 80a20009                 cmp     %o0, %o1
F007E640: 12800009                 bne     loc_F007E664
F007E644: 90103ed0                 mov     -0x130, %o0
F007E648: d0062020                 ld      [%i0+0x20], %o0
F007E64C: 133c0444                 sethi   %hi(dword_F0111338), %o1
F007E650: d2026338                 ld      [%o1+%lo(dword_F0111338)], %o1
F007E654: 80a20009                 cmp     %o0, %o1
F007E658: 02800005                 be      loc_F007E66C
F007E65C: 01000000                 nop
F007E660: 90103ed0                 mov     -0x130, %o0
F007E664: 1080001f                 ba      locret_F007E6E0
F007E668: d026601c                 st      %o0, [%i1+0x1C]
F007E66C: 7fffa4e3                 call    _convert_port_to_map
F007E670: d0062008                 ld      [%i0+8], %o0! target_task
F007E674: a0100008                 mov     %o0, %l0
F007E678: d206201c                 ld      [%i0+0x1C], %o1! address
F007E67C: 9606602c                 add     %i1, 0x2C, %o3 ! ','! data
F007E680: d4062024                 ld      [%i0+0x24], %o2! size
F007E684: 40003103                 call    _vm_read
F007E688: 9807bff4                 add     %fp, var_C, %o4
F007E68C: d026601c                 st      %o0, [%i1+0x1C]
F007E690: 400016df                 call    _vm_map_deallocate
F007E694: 90100010                 mov     %l0, %o0
F007E698: d006601c                 ld      [%i1+0x1C], %o0
F007E69C: 80a22000                 cmp     %o0, 0
F007E6A0: 12800010                 bne     locret_F007E6E0
F007E6A4: 92102030                 mov     0x30, %o1 ! '0'
F007E6A8: d0064000                 ld      [%i1], %o0
F007E6AC: d2266004                 st      %o1, [%i1+4]
F007E6B0: 90120011                 bset    %l1, %o0
F007E6B4: d0264000                 st      %o0, [%i1]
F007E6B8: 113c0444                 sethi   %hi(dword_F011133C), %o0
F007E6BC: d202233c                 ld      [%o0+%lo(dword_F011133C)], %o1
F007E6C0: d2266020                 st      %o1, [%i1+0x20]
F007E6C4: 9012233c                 bset    %lo(dword_F011133C), %o0
F007E6C8: d2022004                 ld      [%o0+4], %o1
F007E6CC: d2266024                 st      %o1, [%i1+0x24]
F007E6D0: d0022008                 ld      [%o0+8], %o0
F007E6D4: d207bff4                 ld      [%fp+var_C], %o1
F007E6D8: d0266028                 st      %o0, [%i1+0x28]
F007E6DC: d2266028                 st      %o1, [%i1+0x28]
F007E6E0: 81c7e008                 ret
F007E6E4: 81e80000                 restore
