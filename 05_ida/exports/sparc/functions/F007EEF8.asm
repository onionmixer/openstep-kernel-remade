F007EEF8: 9de3bf98                 save    %sp, -0x68, %sp
F007EEFC: d0062004                 ld      [%i0+4], %o0
F007EF00: 80a22028                 cmp     %o0, 0x28 ! '('
F007EF04: 12800014                 bne     loc_F007EF54
F007EF08: 90103ed0                 mov     -0x130, %o0
F007EF0C: d0060000                 ld      [%i0], %o0
F007EF10: 80a22000                 cmp     %o0, 0
F007EF14: 16800010                 bge     loc_F007EF54
F007EF18: 90103ed0                 mov     -0x130, %o0
F007EF1C: d0062018                 ld      [%i0+0x18], %o0
F007EF20: 133c0444                 sethi   %hi(dword_F01113BC), %o1
F007EF24: d20263bc                 ld      [%o1+%lo(dword_F01113BC)], %o1
F007EF28: 80a20009                 cmp     %o0, %o1
F007EF2C: 1280000a                 bne     loc_F007EF54
F007EF30: 90103ed0                 mov     -0x130, %o0
F007EF34: d2062020                 ld      [%i0+0x20], %o1
F007EF38: 1104480090122018         set     0x11200018, %o0
F007EF40: 920a7ffc                 and     %o1, -4, %o1
F007EF44: 80a24008                 cmp     %o1, %o0
F007EF48: 02800005                 be      loc_F007EF5C
F007EF4C: 01000000                 nop
F007EF50: 90103ed0                 mov     -0x130, %o0
F007EF54: 1080000b                 ba      locret_F007EF80
F007EF58: d026601c                 st      %o0, [%i1+0x1C]
F007EF5C: 7fffa266                 call    _convert_port_to_task
F007EF60: d0062008                 ld      [%i0+8], %o0! task
F007EF64: d206201c                 ld      [%i0+0x1C], %o1! which_port
F007EF68: a0100008                 mov     %o0, %l0
F007EF6C: 7fffa13c                 call    _task_set_special_port
F007EF70: d4062024                 ld      [%i0+0x24], %o2
F007EF74: d026601c                 st      %o0, [%i1+0x1C]
F007EF78: 7fffd04c                 call    _task_deallocate
F007EF7C: 90100010                 mov     %l0, %o0
F007EF80: 81c7e008                 ret
F007EF84: 81e80000                 restore
