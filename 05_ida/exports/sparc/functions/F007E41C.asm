F007E41C: 9de3bf98                 save    %sp, -0x68, %sp
F007E420: d0062004                 ld      [%i0+4], %o0
F007E424: 80a22028                 cmp     %o0, 0x28 ! '('
F007E428: 12800012                 bne     loc_F007E470
F007E42C: 90103ed0                 mov     -0x130, %o0
F007E430: d0060000                 ld      [%i0], %o0
F007E434: 80a22000                 cmp     %o0, 0
F007E438: 0680000d                 bl      loc_F007E46C
F007E43C: 133c0444                 sethi   %hi(dword_F0111310), %o1
F007E440: d0062018                 ld      [%i0+0x18], %o0
F007E444: d2026310                 ld      [%o1+%lo(dword_F0111310)], %o1
F007E448: 80a20009                 cmp     %o0, %o1
F007E44C: 12800009                 bne     loc_F007E470
F007E450: 90103ed0                 mov     -0x130, %o0
F007E454: d0062020                 ld      [%i0+0x20], %o0
F007E458: 133c0444                 sethi   %hi(dword_F0111314), %o1
F007E45C: d2026314                 ld      [%o1+%lo(dword_F0111314)], %o1
F007E460: 80a20009                 cmp     %o0, %o1
F007E464: 02800005                 be      loc_F007E478
F007E468: 01000000                 nop
F007E46C: 90103ed0                 mov     -0x130, %o0
F007E470: 1080000b                 ba      locret_F007E49C
F007E474: d026601c                 st      %o0, [%i1+0x1C]
F007E478: 7fffa560                 call    _convert_port_to_map
F007E47C: d0062008                 ld      [%i0+8], %o0! target_task
F007E480: d206201c                 ld      [%i0+0x1C], %o1! address
F007E484: a0100008                 mov     %o0, %l0
F007E488: 40003106                 call    _vm_deallocate
F007E48C: d4062024                 ld      [%i0+0x24], %o2
F007E490: d026601c                 st      %o0, [%i1+0x1C]
F007E494: 4000175e                 call    _vm_map_deallocate
F007E498: 90100010                 mov     %l0, %o0
F007E49C: 81c7e008                 ret
F007E4A0: 81e80000                 restore
