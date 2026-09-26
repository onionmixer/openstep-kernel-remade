F00F3D68: 9de3bf70                 save    %sp, -0x90, %sp
F00F3D6C: 92102028                 mov     0x28, %o1 ! '('
F00F3D70: f227bfec                 st      %i1, [%fp+var_14]
F00F3D74: f427bff4                 st      %i2, [%fp+var_C]
F00F3D78: 90102001                 mov     1, %o0
F00F3D7C: d02fbfd3                 stb     %o0, [%fp+var_2D]
F00F3D80: d227bfd4                 st      %o1, [%fp+var_2C]
F00F3D84: 90102100                 mov     0x100, %o0
F00F3D88: d027bfd8                 st      %o0, [%fp+var_28]
F00F3D8C: f027bfe0                 st      %i0, [%fp+var_20]
F00F3D90: 113c03e9                 sethi   %hi(dword_F00FA44C), %o0
F00F3D94: d202204c                 ld      [%o0+%lo(dword_F00FA44C)], %o1
F00F3D98: b207bfd0                 add     %fp, var_30, %i1
F00F3D9C: 113c03e9                 sethi   %hi(dword_F00FA450), %o0
F00F3DA0: d0022050                 ld      [%o0+%lo(dword_F00FA450)], %o0
F00F3DA4: d227bfe8                 st      %o1, [%fp+var_18]
F00F3DA8: 7ffdc9f4                 call    _mig_get_reply_port
F00F3DAC: d027bff0                 st      %o0, [%fp+var_10]
F00F3DB0: d027bfdc                 st      %o0, [%fp+var_24]
F00F3DB4: 90102822                 mov     0x822, %o0
F00F3DB8: d027bfe4                 st      %o0, [%fp+var_1C]
F00F3DBC: 90100019                 mov     %i1, %o0! reply_port
F00F3DC0: 92102000                 mov     0, %o1
F00F3DC4: 94102020                 mov     0x20, %o2 ! ' '
F00F3DC8: 96102000                 mov     0, %o3
F00F3DCC: 7ffdc884                 call    _msg_rpc
F00F3DD0: 98102000                 mov     0, %o4
F00F3DD4: b0920000                 orcc    %o0, %g0, %i0
F00F3DD8: 02800006                 be      loc_F00F3DF0
F00F3DDC: 80a63f36                 cmp     %i0, -0xCA
F00F3DE0: 12800023                 bne     locret_F00F3E6C
F00F3DE4: 01000000                 nop
F00F3DE8: 7ffdc9f1                 call    _mig_dealloc_reply_port
F00F3DEC: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F3DF0: d207bfd4                 ld      [%fp+var_2C], %o1
F00F3DF4: d007bfe4                 ld      [%fp+var_1C], %o0
F00F3DF8: 80a22886                 cmp     %o0, 0x886
F00F3DFC: 02800004                 be      loc_F00F3E0C
F00F3E00: d40fbfd3                 ldub    [%fp+var_2D], %o2
F00F3E04: 1080001a                 ba      locret_F00F3E6C
F00F3E08: b0103ed3                 mov     -0x12D, %i0
F00F3E0C: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F3E10: 12800017                 bne     locret_F00F3E6C
F00F3E14: b0103ed4                 mov     -0x12C, %i0
F00F3E18: 80a2a001                 cmp     %o2, 1
F00F3E1C: 0280000a                 be      loc_F00F3E44
F00F3E20: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F3E24: 12800012                 bne     locret_F00F3E6C
F00F3E28: 01000000                 nop
F00F3E2C: 80a2a001                 cmp     %o2, 1
F00F3E30: 1280000f                 bne     locret_F00F3E6C
F00F3E34: d007bfec                 ld      [%fp+var_14], %o0
F00F3E38: 80a22000                 cmp     %o0, 0
F00F3E3C: 0280000c                 be      locret_F00F3E6C
F00F3E40: 01000000                 nop
F00F3E44: d0066018                 ld      [%i1+0x18], %o0
F00F3E48: 133c03e9                 sethi   %hi(dword_F00FA454), %o1
F00F3E4C: d2026054                 ld      [%o1+%lo(dword_F00FA454)], %o1
F00F3E50: 80a20009                 cmp     %o0, %o1
F00F3E54: 12800006                 bne     locret_F00F3E6C
F00F3E58: b0103ed4                 mov     -0x12C, %i0
F00F3E5C: f006601c                 ld      [%i1+0x1C], %i0
F00F3E60: 80a62000                 cmp     %i0, 0
F00F3E64: 22800002                 be,a    locret_F00F3E6C
F00F3E68: b0102000                 mov     0, %i0
F00F3E6C: 81c7e008                 ret
F00F3E70: 81e80000                 restore
