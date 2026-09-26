F00F407C: 9de3bf70                 save    %sp, -0x90, %sp
F00F4080: 92102028                 mov     0x28, %o1 ! '('
F00F4084: f227bfec                 st      %i1, [%fp+var_14]
F00F4088: f427bff4                 st      %i2, [%fp+var_C]
F00F408C: c02fbfd3                 clrb    [%fp+var_2D]
F00F4090: d227bfd4                 st      %o1, [%fp+var_2C]
F00F4094: 90102100                 mov     0x100, %o0
F00F4098: d027bfd8                 st      %o0, [%fp+var_28]
F00F409C: f027bfe0                 st      %i0, [%fp+var_20]
F00F40A0: 113c03e9                 sethi   %hi(dword_F00FA468), %o0
F00F40A4: d2022068                 ld      [%o0+%lo(dword_F00FA468)], %o1
F00F40A8: b207bfd0                 add     %fp, var_30, %i1
F00F40AC: 113c03e9                 sethi   %hi(dword_F00FA46C), %o0
F00F40B0: d002206c                 ld      [%o0+%lo(dword_F00FA46C)], %o0
F00F40B4: d227bfe8                 st      %o1, [%fp+var_18]
F00F40B8: 7ffdc930                 call    _mig_get_reply_port
F00F40BC: d027bff0                 st      %o0, [%fp+var_10]
F00F40C0: d027bfdc                 st      %o0, [%fp+var_24]
F00F40C4: 9010280b                 mov     0x80B, %o0
F00F40C8: d027bfe4                 st      %o0, [%fp+var_1C]
F00F40CC: 90100019                 mov     %i1, %o0! reply_port
F00F40D0: 92102000                 mov     0, %o1
F00F40D4: 94102020                 mov     0x20, %o2 ! ' '
F00F40D8: 96102000                 mov     0, %o3
F00F40DC: 7ffdc7c0                 call    _msg_rpc
F00F40E0: 98102000                 mov     0, %o4
F00F40E4: b0920000                 orcc    %o0, %g0, %i0
F00F40E8: 02800006                 be      loc_F00F4100
F00F40EC: 80a63f36                 cmp     %i0, -0xCA
F00F40F0: 12800023                 bne     locret_F00F417C
F00F40F4: 01000000                 nop
F00F40F8: 7ffdc92d                 call    _mig_dealloc_reply_port
F00F40FC: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F4100: d207bfd4                 ld      [%fp+var_2C], %o1
F00F4104: d007bfe4                 ld      [%fp+var_1C], %o0
F00F4108: 80a2286f                 cmp     %o0, 0x86F
F00F410C: 02800004                 be      loc_F00F411C
F00F4110: d40fbfd3                 ldub    [%fp+var_2D], %o2
F00F4114: 1080001a                 ba      locret_F00F417C
F00F4118: b0103ed3                 mov     -0x12D, %i0
F00F411C: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4120: 12800017                 bne     locret_F00F417C
F00F4124: b0103ed4                 mov     -0x12C, %i0
F00F4128: 80a2a001                 cmp     %o2, 1
F00F412C: 0280000a                 be      loc_F00F4154
F00F4130: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4134: 12800012                 bne     locret_F00F417C
F00F4138: 01000000                 nop
F00F413C: 80a2a001                 cmp     %o2, 1
F00F4140: 1280000f                 bne     locret_F00F417C
F00F4144: d007bfec                 ld      [%fp+var_14], %o0
F00F4148: 80a22000                 cmp     %o0, 0
F00F414C: 0280000c                 be      locret_F00F417C
F00F4150: 01000000                 nop
F00F4154: d0066018                 ld      [%i1+0x18], %o0
F00F4158: 133c03e9                 sethi   %hi(dword_F00FA470), %o1
F00F415C: d2026070                 ld      [%o1+%lo(dword_F00FA470)], %o1
F00F4160: 80a20009                 cmp     %o0, %o1
F00F4164: 12800006                 bne     locret_F00F417C
F00F4168: b0103ed4                 mov     -0x12C, %i0
F00F416C: f006601c                 ld      [%i1+0x1C], %i0
F00F4170: 80a62000                 cmp     %i0, 0
F00F4174: 22800002                 be,a    locret_F00F417C
F00F4178: b0102000                 mov     0, %i0
F00F417C: 81c7e008                 ret
F00F4180: 81e80000                 restore
