F007ED24: 9de3bf98                 save    %sp, -0x68, %sp
F007ED28: d0062004                 ld      [%i0+4], %o0
F007ED2C: 80a22028                 cmp     %o0, 0x28 ! '('
F007ED30: 12800012                 bne     loc_F007ED78
F007ED34: 90103ed0                 mov     -0x130, %o0
F007ED38: d0060000                 ld      [%i0], %o0
F007ED3C: 80a22000                 cmp     %o0, 0
F007ED40: 0680000d                 bl      loc_F007ED74
F007ED44: 133c0444                 sethi   %hi(dword_F01113AC), %o1
F007ED48: d0062018                 ld      [%i0+0x18], %o0
F007ED4C: d20263ac                 ld      [%o1+%lo(dword_F01113AC)], %o1
F007ED50: 80a20009                 cmp     %o0, %o1
F007ED54: 12800009                 bne     loc_F007ED78
F007ED58: 90103ed0                 mov     -0x130, %o0
F007ED5C: d0062020                 ld      [%i0+0x20], %o0
F007ED60: 133c0444                 sethi   %hi(dword_F01113B0), %o1
F007ED64: d20263b0                 ld      [%o1+%lo(dword_F01113B0)], %o1
F007ED68: 80a20009                 cmp     %o0, %o1
F007ED6C: 02800005                 be      loc_F007ED80
F007ED70: 01000000                 nop
F007ED74: 90103ed0                 mov     -0x130, %o0
F007ED78: 1080000b                 ba      locret_F007EDA4
F007ED7C: d026601c                 st      %o0, [%i1+0x1C]
F007ED80: 7fffa2dd                 call    _convert_port_to_task
F007ED84: d0062008                 ld      [%i0+8], %o0
F007ED88: d206201c                 ld      [%i0+0x1C], %o1
F007ED8C: a0100008                 mov     %o0, %l0
F007ED90: 7fffb465                 call    _xxx_cpu_control
F007ED94: d4062024                 ld      [%i0+0x24], %o2
F007ED98: d026601c                 st      %o0, [%i1+0x1C]
F007ED9C: 7fffd0c3                 call    _task_deallocate
F007EDA0: 90100010                 mov     %l0, %o0
F007EDA4: 81c7e008                 ret
F007EDA8: 81e80000                 restore
