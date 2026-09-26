F00F4978: 9de3bf68                 save    %sp, -0x98, %sp
F00F497C: 92102030                 mov     0x30, %o1 ! '0'
F00F4980: f227bfe4                 st      %i1, [%fp+var_1C]
F00F4984: f427bff4                 st      %i2, [%fp+var_C]
F00F4988: c02fbfcb                 clrb    [%fp+var_35]
F00F498C: d227bfcc                 st      %o1, [%fp+var_34]
F00F4990: 90102100                 mov     0x100, %o0
F00F4994: d027bfd0                 st      %o0, [%fp+var_30]
F00F4998: 113c03e9                 sethi   %hi(dword_F00FA4D8), %o0
F00F499C: d00220d8                 ld      [%o0+%lo(dword_F00FA4D8)], %o0
F00F49A0: f027bfd8                 st      %i0, [%fp+var_28]
F00F49A4: d027bfe0                 st      %o0, [%fp+var_20]
F00F49A8: 113c03e9                 sethi   %hi(dword_F00FA4DC), %o0
F00F49AC: d20220dc                 ld      [%o0+%lo(dword_F00FA4DC)], %o1
F00F49B0: b207bfc8                 add     %fp, var_38, %i1
F00F49B4: 901220dc                 bset    %lo(dword_F00FA4DC), %o0
F00F49B8: d4022004                 ld      [%o0+4], %o2
F00F49BC: d227bfe8                 st      %o1, [%fp+var_18]
F00F49C0: d0022008                 ld      [%o0+8], %o0
F00F49C4: d427bfec                 st      %o2, [%fp+var_14]
F00F49C8: d027bff0                 st      %o0, [%fp+var_10]
F00F49CC: 7ffdc6eb                 call    _mig_get_reply_port
F00F49D0: f627bff0                 st      %i3, [%fp+var_10]
F00F49D4: d027bfd4                 st      %o0, [%fp+var_2C]
F00F49D8: 901027eb                 mov     0x7EB, %o0
F00F49DC: d027bfdc                 st      %o0, [%fp+var_24]
F00F49E0: 90100019                 mov     %i1, %o0! reply_port
F00F49E4: 92102000                 mov     0, %o1
F00F49E8: 94102020                 mov     0x20, %o2 ! ' '
F00F49EC: 96102000                 mov     0, %o3
F00F49F0: 7ffdc57b                 call    _msg_rpc
F00F49F4: 98102000                 mov     0, %o4
F00F49F8: b0920000                 orcc    %o0, %g0, %i0
F00F49FC: 02800006                 be      loc_F00F4A14
F00F4A00: 80a63f36                 cmp     %i0, -0xCA
F00F4A04: 12800023                 bne     locret_F00F4A90
F00F4A08: 01000000                 nop
F00F4A0C: 7ffdc6e8                 call    _mig_dealloc_reply_port
F00F4A10: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F4A14: d207bfcc                 ld      [%fp+var_34], %o1
F00F4A18: d007bfdc                 ld      [%fp+var_24], %o0
F00F4A1C: 80a2284f                 cmp     %o0, 0x84F
F00F4A20: 02800004                 be      loc_F00F4A30
F00F4A24: d40fbfcb                 ldub    [%fp+var_35], %o2
F00F4A28: 1080001a                 ba      locret_F00F4A90
F00F4A2C: b0103ed3                 mov     -0x12D, %i0
F00F4A30: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4A34: 12800017                 bne     locret_F00F4A90
F00F4A38: b0103ed4                 mov     -0x12C, %i0
F00F4A3C: 80a2a001                 cmp     %o2, 1
F00F4A40: 0280000a                 be      loc_F00F4A68
F00F4A44: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4A48: 12800012                 bne     locret_F00F4A90
F00F4A4C: 01000000                 nop
F00F4A50: 80a2a001                 cmp     %o2, 1
F00F4A54: 1280000f                 bne     locret_F00F4A90
F00F4A58: d007bfe4                 ld      [%fp+var_1C], %o0
F00F4A5C: 80a22000                 cmp     %o0, 0
F00F4A60: 0280000c                 be      locret_F00F4A90
F00F4A64: 01000000                 nop
F00F4A68: d0066018                 ld      [%i1+0x18], %o0
F00F4A6C: 133c03e9                 sethi   %hi(dword_F00FA4E8), %o1
F00F4A70: d20260e8                 ld      [%o1+%lo(dword_F00FA4E8)], %o1
F00F4A74: 80a20009                 cmp     %o0, %o1
F00F4A78: 12800006                 bne     locret_F00F4A90
F00F4A7C: b0103ed4                 mov     -0x12C, %i0
F00F4A80: f006601c                 ld      [%i1+0x1C], %i0
F00F4A84: 80a62000                 cmp     %i0, 0
F00F4A88: 22800002                 be,a    locret_F00F4A90
F00F4A8C: b0102000                 mov     0, %i0
F00F4A90: 81c7e008                 ret
F00F4A94: 81e80000                 restore
