F00F3E74: 9de3bf70                 save    %sp, -0x90, %sp
F00F3E78: 92102018                 mov     0x18, %o1
F00F3E7C: 90102001                 mov     1, %o0
F00F3E80: d02fbfd3                 stb     %o0, [%fp+var_2D]
F00F3E84: d227bfd4                 st      %o1, [%fp+var_2C]
F00F3E88: 90102100                 mov     0x100, %o0
F00F3E8C: d027bfd8                 st      %o0, [%fp+var_28]
F00F3E90: f027bfe0                 st      %i0, [%fp+var_20]
F00F3E94: 7ffdc9b9                 call    _mig_get_reply_port
F00F3E98: a007bfd0                 add     %fp, var_30, %l0
F00F3E9C: d027bfdc                 st      %o0, [%fp+var_24]
F00F3EA0: 90102820                 mov     0x820, %o0
F00F3EA4: d027bfe4                 st      %o0, [%fp+var_1C]
F00F3EA8: 90100010                 mov     %l0, %o0! reply_port
F00F3EAC: 92102000                 mov     0, %o1
F00F3EB0: 94102028                 mov     0x28, %o2 ! '('
F00F3EB4: 96102000                 mov     0, %o3
F00F3EB8: 7ffdc849                 call    _msg_rpc
F00F3EBC: 98102000                 mov     0, %o4
F00F3EC0: b0920000                 orcc    %o0, %g0, %i0
F00F3EC4: 02800006                 be      loc_F00F3EDC
F00F3EC8: 80a63f36                 cmp     %i0, -0xCA
F00F3ECC: 1280002b                 bne     locret_F00F3F78
F00F3ED0: 01000000                 nop
F00F3ED4: 7ffdc9b6                 call    _mig_dealloc_reply_port
F00F3ED8: 9e03e09c                 inc     0x9C, %o7
F00F3EDC: d207bfd4                 ld      [%fp+var_2C], %o1
F00F3EE0: d007bfe4                 ld      [%fp+var_1C], %o0
F00F3EE4: 80a22884                 cmp     %o0, 0x884
F00F3EE8: 02800004                 be      loc_F00F3EF8
F00F3EEC: d40fbfd3                 ldub    [%fp+var_2D], %o2
F00F3EF0: 10800022                 ba      locret_F00F3F78
F00F3EF4: b0103ed3                 mov     -0x12D, %i0
F00F3EF8: 80a26028                 cmp     %o1, 0x28 ! '('
F00F3EFC: 12800005                 bne     loc_F00F3F10
F00F3F00: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F3F04: 80a2a001                 cmp     %o2, 1
F00F3F08: 0280000a                 be      loc_F00F3F30
F00F3F0C: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F3F10: 1280001a                 bne     locret_F00F3F78
F00F3F14: b0103ed4                 mov     -0x12C, %i0
F00F3F18: 80a2a001                 cmp     %o2, 1
F00F3F1C: 12800017                 bne     locret_F00F3F78
F00F3F20: d007bfec                 ld      [%fp+var_14], %o0
F00F3F24: 80a22000                 cmp     %o0, 0
F00F3F28: 02800014                 be      locret_F00F3F78
F00F3F2C: 01000000                 nop
F00F3F30: d0042018                 ld      [%l0+0x18], %o0
F00F3F34: 133c03e9                 sethi   %hi(dword_F00FA458), %o1
F00F3F38: d2026058                 ld      [%o1+%lo(dword_F00FA458)], %o1
F00F3F3C: 80a20009                 cmp     %o0, %o1
F00F3F40: 1280000e                 bne     locret_F00F3F78
F00F3F44: b0103ed4                 mov     -0x12C, %i0
F00F3F48: f004201c                 ld      [%l0+0x1C], %i0
F00F3F4C: 80a62000                 cmp     %i0, 0
F00F3F50: 1280000a                 bne     locret_F00F3F78
F00F3F54: 133c03e9                 sethi   %hi(dword_F00FA45C), %o1
F00F3F58: d0042020                 ld      [%l0+0x20], %o0
F00F3F5C: d202605c                 ld      [%o1+%lo(dword_F00FA45C)], %o1
F00F3F60: 80a20009                 cmp     %o0, %o1
F00F3F64: 12800005                 bne     locret_F00F3F78
F00F3F68: b0103ed4                 mov     -0x12C, %i0
F00F3F6C: d0042024                 ld      [%l0+0x24], %o0
F00F3F70: d0264000                 st      %o0, [%i1]
F00F3F74: f004201c                 ld      [%l0+0x1C], %i0
F00F3F78: 81c7e008                 ret
F00F3F7C: 81e80000                 restore
