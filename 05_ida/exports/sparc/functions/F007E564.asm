F007E564: 9de3bf98                 save    %sp, -0x68, %sp
F007E568: d0062004                 ld      [%i0+4], %o0
F007E56C: 80a22030                 cmp     %o0, 0x30 ! '0'
F007E570: 12800018                 bne     loc_F007E5D0
F007E574: 90103ed0                 mov     -0x130, %o0
F007E578: d0060000                 ld      [%i0], %o0
F007E57C: 80a22000                 cmp     %o0, 0
F007E580: 06800013                 bl      loc_F007E5CC
F007E584: 133c0444                 sethi   %hi(dword_F0111328), %o1
F007E588: d0062018                 ld      [%i0+0x18], %o0
F007E58C: d2026328                 ld      [%o1+%lo(dword_F0111328)], %o1
F007E590: 80a20009                 cmp     %o0, %o1
F007E594: 1280000f                 bne     loc_F007E5D0
F007E598: 90103ed0                 mov     -0x130, %o0
F007E59C: d0062020                 ld      [%i0+0x20], %o0
F007E5A0: 133c0444                 sethi   %hi(dword_F011132C), %o1
F007E5A4: d202632c                 ld      [%o1+%lo(dword_F011132C)], %o1
F007E5A8: 80a20009                 cmp     %o0, %o1
F007E5AC: 12800009                 bne     loc_F007E5D0
F007E5B0: 90103ed0                 mov     -0x130, %o0
F007E5B4: d0062028                 ld      [%i0+0x28], %o0
F007E5B8: 133c0444                 sethi   %hi(dword_F0111330), %o1
F007E5BC: d2026330                 ld      [%o1+%lo(dword_F0111330)], %o1
F007E5C0: 80a20009                 cmp     %o0, %o1
F007E5C4: 02800005                 be      loc_F007E5D8
F007E5C8: 01000000                 nop
F007E5CC: 90103ed0                 mov     -0x130, %o0
F007E5D0: 1080000c                 ba      locret_F007E600
F007E5D4: d026601c                 st      %o0, [%i1+0x1C]
F007E5D8: 7fffa508                 call    _convert_port_to_map
F007E5DC: d0062008                 ld      [%i0+8], %o0! target_task
F007E5E0: d206201c                 ld      [%i0+0x1C], %o1! address
F007E5E4: d4062024                 ld      [%i0+0x24], %o2! size
F007E5E8: a0100008                 mov     %o0, %l0
F007E5EC: 400030c2                 call    _vm_inherit
F007E5F0: d606202c                 ld      [%i0+0x2C], %o3
F007E5F4: d026601c                 st      %o0, [%i1+0x1C]
F007E5F8: 40001705                 call    _vm_map_deallocate
F007E5FC: 90100010                 mov     %l0, %o0
F007E600: 81c7e008                 ret
F007E604: 81e80000                 restore
