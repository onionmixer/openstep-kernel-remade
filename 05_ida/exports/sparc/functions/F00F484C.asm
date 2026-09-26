F00F484C: 9de3bf60                 save    %sp, -0xA0, %sp
F00F4850: 92102038                 mov     0x38, %o1 ! '8'
F00F4854: f227bfdc                 st      %i1, [%fp+var_24]
F00F4858: f427bfe4                 st      %i2, [%fp+var_1C]
F00F485C: f627bfec                 st      %i3, [%fp+var_14]
F00F4860: f827bff4                 st      %i4, [%fp+var_C]
F00F4864: 90102001                 mov     1, %o0
F00F4868: d02fbfc3                 stb     %o0, [%fp+var_3D]
F00F486C: d227bfc4                 st      %o1, [%fp+var_3C]
F00F4870: 90102100                 mov     0x100, %o0
F00F4874: d027bfc8                 st      %o0, [%fp+var_38]
F00F4878: 113c03e9                 sethi   %hi(dword_F00FA4C4), %o0
F00F487C: d20220c4                 ld      [%o0+%lo(dword_F00FA4C4)], %o1
F00F4880: f027bfd0                 st      %i0, [%fp+var_30]
F00F4884: 113c03e9                 sethi   %hi(dword_F00FA4C8), %o0
F00F4888: d00220c8                 ld      [%o0+%lo(dword_F00FA4C8)], %o0
F00F488C: d227bfd8                 st      %o1, [%fp+var_28]
F00F4890: d027bfe0                 st      %o0, [%fp+var_20]
F00F4894: 113c03e9                 sethi   %hi(dword_F00FA4CC), %o0
F00F4898: d20220cc                 ld      [%o0+%lo(dword_F00FA4CC)], %o1
F00F489C: b207bfc0                 add     %fp, var_40, %i1
F00F48A0: 113c03e9                 sethi   %hi(dword_F00FA4D0), %o0
F00F48A4: d00220d0                 ld      [%o0+%lo(dword_F00FA4D0)], %o0
F00F48A8: d227bfe8                 st      %o1, [%fp+var_18]
F00F48AC: 7ffdc733                 call    _mig_get_reply_port
F00F48B0: d027bff0                 st      %o0, [%fp+var_10]
F00F48B4: d027bfcc                 st      %o0, [%fp+var_34]
F00F48B8: 901027e8                 mov     0x7E8, %o0
F00F48BC: d027bfd4                 st      %o0, [%fp+var_2C]
F00F48C0: 90100019                 mov     %i1, %o0! reply_port
F00F48C4: 92102000                 mov     0, %o1
F00F48C8: 94102020                 mov     0x20, %o2 ! ' '
F00F48CC: 96102000                 mov     0, %o3
F00F48D0: 7ffdc5c3                 call    _msg_rpc
F00F48D4: 98102000                 mov     0, %o4
F00F48D8: b0920000                 orcc    %o0, %g0, %i0
F00F48DC: 02800006                 be      loc_F00F48F4
F00F48E0: 80a63f36                 cmp     %i0, -0xCA
F00F48E4: 12800023                 bne     locret_F00F4970
F00F48E8: 01000000                 nop
F00F48EC: 7ffdc730                 call    _mig_dealloc_reply_port
F00F48F0: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F48F4: d207bfc4                 ld      [%fp+var_3C], %o1
F00F48F8: d007bfd4                 ld      [%fp+var_2C], %o0
F00F48FC: 80a2284c                 cmp     %o0, 0x84C
F00F4900: 02800004                 be      loc_F00F4910
F00F4904: d40fbfc3                 ldub    [%fp+var_3D], %o2
F00F4908: 1080001a                 ba      locret_F00F4970
F00F490C: b0103ed3                 mov     -0x12D, %i0
F00F4910: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4914: 12800017                 bne     locret_F00F4970
F00F4918: b0103ed4                 mov     -0x12C, %i0
F00F491C: 80a2a001                 cmp     %o2, 1
F00F4920: 0280000a                 be      loc_F00F4948
F00F4924: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4928: 12800012                 bne     locret_F00F4970
F00F492C: 01000000                 nop
F00F4930: 80a2a001                 cmp     %o2, 1
F00F4934: 1280000f                 bne     locret_F00F4970
F00F4938: d007bfdc                 ld      [%fp+var_24], %o0
F00F493C: 80a22000                 cmp     %o0, 0
F00F4940: 0280000c                 be      locret_F00F4970
F00F4944: 01000000                 nop
F00F4948: d0066018                 ld      [%i1+0x18], %o0
F00F494C: 133c03e9                 sethi   %hi(dword_F00FA4D4), %o1
F00F4950: d20260d4                 ld      [%o1+%lo(dword_F00FA4D4)], %o1
F00F4954: 80a20009                 cmp     %o0, %o1
F00F4958: 12800006                 bne     locret_F00F4970
F00F495C: b0103ed4                 mov     -0x12C, %i0
F00F4960: f006601c                 ld      [%i1+0x1C], %i0
F00F4964: 80a62000                 cmp     %i0, 0
F00F4968: 22800002                 be,a    locret_F00F4970
F00F496C: b0102000                 mov     0, %i0
F00F4970: 81c7e008                 ret
F00F4974: 81e80000                 restore
