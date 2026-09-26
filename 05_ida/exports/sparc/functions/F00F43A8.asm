F00F43A8: 9de3bf70                 save    %sp, -0x90, %sp
F00F43AC: 92102028                 mov     0x28, %o1 ! '('
F00F43B0: f227bfec                 st      %i1, [%fp+var_14]
F00F43B4: f427bff4                 st      %i2, [%fp+var_C]
F00F43B8: 90102001                 mov     1, %o0
F00F43BC: d02fbfd3                 stb     %o0, [%fp+var_2D]
F00F43C0: d227bfd4                 st      %o1, [%fp+var_2C]
F00F43C4: 90102100                 mov     0x100, %o0
F00F43C8: d027bfd8                 st      %o0, [%fp+var_28]
F00F43CC: f027bfe0                 st      %i0, [%fp+var_20]
F00F43D0: 113c03e9                 sethi   %hi(dword_F00FA48C), %o0
F00F43D4: d202208c                 ld      [%o0+%lo(dword_F00FA48C)], %o1
F00F43D8: b207bfd0                 add     %fp, var_30, %i1
F00F43DC: 113c03e9                 sethi   %hi(dword_F00FA490), %o0
F00F43E0: d0022090                 ld      [%o0+%lo(dword_F00FA490)], %o0
F00F43E4: d227bfe8                 st      %o1, [%fp+var_18]
F00F43E8: 7ffdc864                 call    _mig_get_reply_port
F00F43EC: d027bff0                 st      %o0, [%fp+var_10]
F00F43F0: d027bfdc                 st      %o0, [%fp+var_24]
F00F43F4: 901027e7                 mov     0x7E7, %o0
F00F43F8: d027bfe4                 st      %o0, [%fp+var_1C]
F00F43FC: 90100019                 mov     %i1, %o0! reply_port
F00F4400: 92102000                 mov     0, %o1
F00F4404: 94102020                 mov     0x20, %o2 ! ' '
F00F4408: 96102000                 mov     0, %o3
F00F440C: 7ffdc6f4                 call    _msg_rpc
F00F4410: 98102000                 mov     0, %o4
F00F4414: b0920000                 orcc    %o0, %g0, %i0
F00F4418: 02800006                 be      loc_F00F4430
F00F441C: 80a63f36                 cmp     %i0, -0xCA
F00F4420: 12800023                 bne     locret_F00F44AC
F00F4424: 01000000                 nop
F00F4428: 7ffdc861                 call    _mig_dealloc_reply_port
F00F442C: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F4430: d207bfd4                 ld      [%fp+var_2C], %o1
F00F4434: d007bfe4                 ld      [%fp+var_1C], %o0
F00F4438: 80a2284b                 cmp     %o0, 0x84B
F00F443C: 02800004                 be      loc_F00F444C
F00F4440: d40fbfd3                 ldub    [%fp+var_2D], %o2
F00F4444: 1080001a                 ba      locret_F00F44AC
F00F4448: b0103ed3                 mov     -0x12D, %i0
F00F444C: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4450: 12800017                 bne     locret_F00F44AC
F00F4454: b0103ed4                 mov     -0x12C, %i0
F00F4458: 80a2a001                 cmp     %o2, 1
F00F445C: 0280000a                 be      loc_F00F4484
F00F4460: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4464: 12800012                 bne     locret_F00F44AC
F00F4468: 01000000                 nop
F00F446C: 80a2a001                 cmp     %o2, 1
F00F4470: 1280000f                 bne     locret_F00F44AC
F00F4474: d007bfec                 ld      [%fp+var_14], %o0
F00F4478: 80a22000                 cmp     %o0, 0
F00F447C: 0280000c                 be      locret_F00F44AC
F00F4480: 01000000                 nop
F00F4484: d0066018                 ld      [%i1+0x18], %o0
F00F4488: 133c03e9                 sethi   %hi(dword_F00FA494), %o1
F00F448C: d2026094                 ld      [%o1+%lo(dword_F00FA494)], %o1
F00F4490: 80a20009                 cmp     %o0, %o1
F00F4494: 12800006                 bne     locret_F00F44AC
F00F4498: b0103ed4                 mov     -0x12C, %i0
F00F449C: f006601c                 ld      [%i1+0x1C], %i0
F00F44A0: 80a62000                 cmp     %i0, 0
F00F44A4: 22800002                 be,a    locret_F00F44AC
F00F44A8: b0102000                 mov     0, %i0
F00F44AC: 81c7e008                 ret
F00F44B0: 81e80000                 restore
