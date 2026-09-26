F007F80C: 9de3bf98                 save    %sp, -0x68, %sp
F007F810: d0062004                 ld      [%i0+4], %o0
F007F814: 80a22028                 cmp     %o0, 0x28 ! '('
F007F818: 12800012                 bne     loc_F007F860
F007F81C: 90103ed0                 mov     -0x130, %o0
F007F820: d0060000                 ld      [%i0], %o0
F007F824: 80a22000                 cmp     %o0, 0
F007F828: 0680000d                 bl      loc_F007F85C
F007F82C: 133c0445                 sethi   %hi(dword_F0111434), %o1
F007F830: d0062018                 ld      [%i0+0x18], %o0
F007F834: d2026034                 ld      [%o1+%lo(dword_F0111434)], %o1
F007F838: 80a20009                 cmp     %o0, %o1
F007F83C: 12800009                 bne     loc_F007F860
F007F840: 90103ed0                 mov     -0x130, %o0
F007F844: d0062020                 ld      [%i0+0x20], %o0
F007F848: 133c0445                 sethi   %hi(dword_F0111438), %o1
F007F84C: d2026038                 ld      [%o1+%lo(dword_F0111438)], %o1
F007F850: 80a20009                 cmp     %o0, %o1
F007F854: 02800005                 be      loc_F007F868
F007F858: 01000000                 nop
F007F85C: 90103ed0                 mov     -0x130, %o0
F007F860: 1080000b                 ba      locret_F007F88C
F007F864: d026601c                 st      %o0, [%i1+0x1C]
F007F868: 7fffa043                 call    _convert_port_to_space
F007F86C: d0062008                 ld      [%i0+8], %o0
F007F870: d206201c                 ld      [%i0+0x1C], %o1
F007F874: a0100008                 mov     %o0, %l0
F007F878: 7fff8e70                 call    _port_set_backlog
F007F87C: d4062024                 ld      [%i0+0x24], %o2
F007F880: d026601c                 st      %o0, [%i1+0x1C]
F007F884: 7fffa0cc                 call    _space_deallocate
F007F888: 90100010                 mov     %l0, %o0
F007F88C: 81c7e008                 ret
F007F890: 81e80000                 restore
