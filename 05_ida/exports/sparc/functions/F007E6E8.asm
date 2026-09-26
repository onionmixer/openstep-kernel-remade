F007E6E8: 9de3bf98                 save    %sp, -0x68, %sp
F007E6EC: d0062004                 ld      [%i0+4], %o0
F007E6F0: 80a22030                 cmp     %o0, 0x30 ! '0'
F007E6F4: 12800018                 bne     loc_F007E754
F007E6F8: 90103ed0                 mov     -0x130, %o0
F007E6FC: d0060000                 ld      [%i0], %o0
F007E700: 80a22000                 cmp     %o0, 0
F007E704: 16800014                 bge     loc_F007E754
F007E708: 90103ed0                 mov     -0x130, %o0
F007E70C: d0062018                 ld      [%i0+0x18], %o0
F007E710: 133c0444                 sethi   %hi(dword_F0111348), %o1
F007E714: d2026348                 ld      [%o1+%lo(dword_F0111348)], %o1
F007E718: 80a20009                 cmp     %o0, %o1
F007E71C: 1280000e                 bne     loc_F007E754
F007E720: 90103ed0                 mov     -0x130, %o0
F007E724: d0062020                 ld      [%i0+0x20], %o0
F007E728: 900a200c                 and     %o0, 0xC, %o0
F007E72C: 80a22004                 cmp     %o0, 4
F007E730: 12800009                 bne     loc_F007E754
F007E734: 90103ed0                 mov     -0x130, %o0
F007E738: d2062024                 ld      [%i0+0x24], %o1
F007E73C: 1100024090122008         set     0x90008, %o0
F007E744: 80a24008                 cmp     %o1, %o0
F007E748: 02800005                 be      loc_F007E75C
F007E74C: 01000000                 nop
F007E750: 90103ed0                 mov     -0x130, %o0
F007E754: 1080000c                 ba      locret_F007E784
F007E758: d026601c                 st      %o0, [%i1+0x1C]
F007E75C: 7fffa4a7                 call    _convert_port_to_map
F007E760: d0062008                 ld      [%i0+8], %o0! target_task
F007E764: d206201c                 ld      [%i0+0x1C], %o1! address
F007E768: d406202c                 ld      [%i0+0x2C], %o2! data
F007E76C: a0100008                 mov     %o0, %l0
F007E770: 400030f9                 call    _vm_write
F007E774: d6062028                 ld      [%i0+0x28], %o3
F007E778: d026601c                 st      %o0, [%i1+0x1C]
F007E77C: 400016a4                 call    _vm_map_deallocate
F007E780: 90100010                 mov     %l0, %o0
F007E784: 81c7e008                 ret
F007E788: 81e80000                 restore
