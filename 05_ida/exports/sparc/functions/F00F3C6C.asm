F00F3C6C: 9de3bf78                 save    %sp, -0x88, %sp
F00F3C70: 92102020                 mov     0x20, %o1 ! ' '
F00F3C74: f227bff4                 st      %i1, [%fp+var_C]
F00F3C78: 90102001                 mov     1, %o0
F00F3C7C: d02fbfdb                 stb     %o0, [%fp+var_25]
F00F3C80: d227bfdc                 st      %o1, [%fp+var_24]
F00F3C84: 90102100                 mov     0x100, %o0
F00F3C88: d027bfe0                 st      %o0, [%fp+var_20]
F00F3C8C: 113c03e9                 sethi   %hi(dword_F00FA444), %o0
F00F3C90: d0022044                 ld      [%o0+%lo(dword_F00FA444)], %o0
F00F3C94: f027bfe8                 st      %i0, [%fp+var_18]
F00F3C98: b207bfd8                 add     %fp, var_28, %i1
F00F3C9C: 7ffdca37                 call    _mig_get_reply_port
F00F3CA0: d027bff0                 st      %o0, [%fp+var_10]
F00F3CA4: d027bfe4                 st      %o0, [%fp+var_1C]
F00F3CA8: 9010281d                 mov     0x81D, %o0
F00F3CAC: d027bfec                 st      %o0, [%fp+var_14]
F00F3CB0: 90100019                 mov     %i1, %o0! reply_port
F00F3CB4: 92102000                 mov     0, %o1
F00F3CB8: 94102020                 mov     0x20, %o2 ! ' '
F00F3CBC: 96102000                 mov     0, %o3
F00F3CC0: 7ffdc8c7                 call    _msg_rpc
F00F3CC4: 98102000                 mov     0, %o4
F00F3CC8: b0920000                 orcc    %o0, %g0, %i0
F00F3CCC: 02800006                 be      loc_F00F3CE4
F00F3CD0: 80a63f36                 cmp     %i0, -0xCA
F00F3CD4: 12800023                 bne     locret_F00F3D60
F00F3CD8: 01000000                 nop
F00F3CDC: 7ffdca34                 call    _mig_dealloc_reply_port
F00F3CE0: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F3CE4: d207bfdc                 ld      [%fp+var_24], %o1
F00F3CE8: d007bfec                 ld      [%fp+var_14], %o0
F00F3CEC: 80a22881                 cmp     %o0, 0x881
F00F3CF0: 02800004                 be      loc_F00F3D00
F00F3CF4: d40fbfdb                 ldub    [%fp+var_25], %o2
F00F3CF8: 1080001a                 ba      locret_F00F3D60
F00F3CFC: b0103ed3                 mov     -0x12D, %i0
F00F3D00: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F3D04: 12800017                 bne     locret_F00F3D60
F00F3D08: b0103ed4                 mov     -0x12C, %i0
F00F3D0C: 80a2a001                 cmp     %o2, 1
F00F3D10: 0280000a                 be      loc_F00F3D38
F00F3D14: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F3D18: 12800012                 bne     locret_F00F3D60
F00F3D1C: 01000000                 nop
F00F3D20: 80a2a001                 cmp     %o2, 1
F00F3D24: 1280000f                 bne     locret_F00F3D60
F00F3D28: d007bff4                 ld      [%fp+var_C], %o0
F00F3D2C: 80a22000                 cmp     %o0, 0
F00F3D30: 0280000c                 be      locret_F00F3D60
F00F3D34: 01000000                 nop
F00F3D38: d0066018                 ld      [%i1+0x18], %o0
F00F3D3C: 133c03e9                 sethi   %hi(dword_F00FA448), %o1
F00F3D40: d2026048                 ld      [%o1+%lo(dword_F00FA448)], %o1
F00F3D44: 80a20009                 cmp     %o0, %o1
F00F3D48: 12800006                 bne     locret_F00F3D60
F00F3D4C: b0103ed4                 mov     -0x12C, %i0
F00F3D50: f006601c                 ld      [%i1+0x1C], %i0
F00F3D54: 80a62000                 cmp     %i0, 0
F00F3D58: 22800002                 be,a    locret_F00F3D60
F00F3D5C: b0102000                 mov     0, %i0
F00F3D60: 81c7e008                 ret
F00F3D64: 81e80000                 restore
