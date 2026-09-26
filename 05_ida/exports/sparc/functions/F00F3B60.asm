F00F3B60: 9de3bf70                 save    %sp, -0x90, %sp
F00F3B64: 92102018                 mov     0x18, %o1
F00F3B68: 90102001                 mov     1, %o0
F00F3B6C: d02fbfd3                 stb     %o0, [%fp+var_2D]
F00F3B70: d227bfd4                 st      %o1, [%fp+var_2C]
F00F3B74: 90102100                 mov     0x100, %o0
F00F3B78: d027bfd8                 st      %o0, [%fp+var_28]
F00F3B7C: f027bfe0                 st      %i0, [%fp+var_20]
F00F3B80: 7ffdca7e                 call    _mig_get_reply_port
F00F3B84: a007bfd0                 add     %fp, var_30, %l0
F00F3B88: d027bfdc                 st      %o0, [%fp+var_24]
F00F3B8C: 9010281c                 mov     0x81C, %o0
F00F3B90: d027bfe4                 st      %o0, [%fp+var_1C]
F00F3B94: 90100010                 mov     %l0, %o0! reply_port
F00F3B98: 92102000                 mov     0, %o1
F00F3B9C: 94102028                 mov     0x28, %o2 ! '('
F00F3BA0: 96102000                 mov     0, %o3
F00F3BA4: 7ffdc90e                 call    _msg_rpc
F00F3BA8: 98102000                 mov     0, %o4
F00F3BAC: b0920000                 orcc    %o0, %g0, %i0
F00F3BB0: 02800006                 be      loc_F00F3BC8
F00F3BB4: 80a63f36                 cmp     %i0, -0xCA
F00F3BB8: 1280002b                 bne     locret_F00F3C64
F00F3BBC: 01000000                 nop
F00F3BC0: 7ffdca7b                 call    _mig_dealloc_reply_port
F00F3BC4: 9e03e09c                 inc     0x9C, %o7
F00F3BC8: d207bfd4                 ld      [%fp+var_2C], %o1
F00F3BCC: d007bfe4                 ld      [%fp+var_1C], %o0
F00F3BD0: 80a22880                 cmp     %o0, 0x880
F00F3BD4: 02800004                 be      loc_F00F3BE4
F00F3BD8: d40fbfd3                 ldub    [%fp+var_2D], %o2
F00F3BDC: 10800022                 ba      locret_F00F3C64
F00F3BE0: b0103ed3                 mov     -0x12D, %i0
F00F3BE4: 80a26028                 cmp     %o1, 0x28 ! '('
F00F3BE8: 12800005                 bne     loc_F00F3BFC
F00F3BEC: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F3BF0: 80a2a001                 cmp     %o2, 1
F00F3BF4: 0280000a                 be      loc_F00F3C1C
F00F3BF8: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F3BFC: 1280001a                 bne     locret_F00F3C64
F00F3C00: b0103ed4                 mov     -0x12C, %i0
F00F3C04: 80a2a001                 cmp     %o2, 1
F00F3C08: 12800017                 bne     locret_F00F3C64
F00F3C0C: d007bfec                 ld      [%fp+var_14], %o0
F00F3C10: 80a22000                 cmp     %o0, 0
F00F3C14: 02800014                 be      locret_F00F3C64
F00F3C18: 01000000                 nop
F00F3C1C: d0042018                 ld      [%l0+0x18], %o0
F00F3C20: 133c03e9                 sethi   %hi(dword_F00FA43C), %o1
F00F3C24: d202603c                 ld      [%o1+%lo(dword_F00FA43C)], %o1
F00F3C28: 80a20009                 cmp     %o0, %o1
F00F3C2C: 1280000e                 bne     locret_F00F3C64
F00F3C30: b0103ed4                 mov     -0x12C, %i0
F00F3C34: f004201c                 ld      [%l0+0x1C], %i0
F00F3C38: 80a62000                 cmp     %i0, 0
F00F3C3C: 1280000a                 bne     locret_F00F3C64
F00F3C40: 133c03e9                 sethi   %hi(dword_F00FA440), %o1
F00F3C44: d0042020                 ld      [%l0+0x20], %o0
F00F3C48: d2026040                 ld      [%o1+%lo(dword_F00FA440)], %o1
F00F3C4C: 80a20009                 cmp     %o0, %o1
F00F3C50: 12800005                 bne     locret_F00F3C64
F00F3C54: b0103ed4                 mov     -0x12C, %i0
F00F3C58: d0042024                 ld      [%l0+0x24], %o0
F00F3C5C: d0264000                 st      %o0, [%i1]
F00F3C60: f004201c                 ld      [%l0+0x1C], %i0
F00F3C64: 81c7e008                 ret
F00F3C68: 81e80000                 restore
