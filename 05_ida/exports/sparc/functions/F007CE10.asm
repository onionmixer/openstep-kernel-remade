F007CE10: 9de3bf98                 save    %sp, -0x68, %sp
F007CE14: d0062004                 ld      [%i0+4], %o0
F007CE18: 80a22020                 cmp     %o0, 0x20 ! ' '
F007CE1C: 1280000c                 bne     loc_F007CE4C
F007CE20: 90103ed0                 mov     -0x130, %o0
F007CE24: d0060000                 ld      [%i0], %o0
F007CE28: 80a22000                 cmp     %o0, 0
F007CE2C: 06800007                 bl      loc_F007CE48
F007CE30: 133c0444                 sethi   %hi(dword_F01110F4), %o1
F007CE34: d0062018                 ld      [%i0+0x18], %o0
F007CE38: d20260f4                 ld      [%o1+%lo(dword_F01110F4)], %o1! policy
F007CE3C: 80a20009                 cmp     %o0, %o1
F007CE40: 02800005                 be      loc_F007CE54
F007CE44: 01000000                 nop
F007CE48: 90103ed0                 mov     -0x130, %o0
F007CE4C: 1080000a                 ba      locret_F007CE74
F007CE50: d026601c                 st      %o0, [%i1+0x1C]
F007CE54: 7fffa163                 call    _convert_port_to_pset
F007CE58: d0062008                 ld      [%i0+8], %o0! processor_set
F007CE5C: a0100008                 mov     %o0, %l0
F007CE60: 7fffc9a7                 call    _processor_set_policy_enable
F007CE64: d206201c                 ld      [%i0+0x1C], %o1
F007CE68: d026601c                 st      %o0, [%i1+0x1C]
F007CE6C: 7fffc8b3                 call    _pset_deallocate
F007CE70: 90100010                 mov     %l0, %o0
F007CE74: 81c7e008                 ret
F007CE78: 81e80000                 restore
