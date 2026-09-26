F007EBDC: 9de3bf98                 save    %sp, -0x68, %sp
F007EBE0: d0062004                 ld      [%i0+4], %o0
F007EBE4: 80a22020                 cmp     %o0, 0x20 ! ' '
F007EBE8: 12800010                 bne     loc_F007EC28
F007EBEC: 90103ed0                 mov     -0x130, %o0
F007EBF0: d0060000                 ld      [%i0], %o0
F007EBF4: 80a22000                 cmp     %o0, 0
F007EBF8: 1680000c                 bge     loc_F007EC28
F007EBFC: 90103ed0                 mov     -0x130, %o0
F007EC00: d2062018                 ld      [%i0+0x18], %o1
F007EC04: 1104480090122018         set     0x11200018, %o0
F007EC0C: 920a7ffc                 and     %o1, -4, %o1
F007EC10: 80a24008                 cmp     %o1, %o0
F007EC14: 12800005                 bne     loc_F007EC28
F007EC18: 90103ed0                 mov     -0x130, %o0
F007EC1C: d0062008                 ld      [%i0+8], %o0
F007EC20: 7fffb363                 call    _netipc_ignore
F007EC24: d206201c                 ld      [%i0+0x1C], %o1
F007EC28: d026601c                 st      %o0, [%i1+0x1C]
F007EC2C: 81c7e008                 ret
F007EC30: 81e80000                 restore
