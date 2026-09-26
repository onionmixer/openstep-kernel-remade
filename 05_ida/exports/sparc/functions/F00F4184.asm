F00F4184: 9de3bf70                 save    %sp, -0x90, %sp
F00F4188: 92102020                 mov     0x20, %o1 ! ' '
F00F418C: f227bfec                 st      %i1, [%fp+var_14]
F00F4190: 90102001                 mov     1, %o0
F00F4194: d02fbfd3                 stb     %o0, [%fp+var_2D]
F00F4198: d227bfd4                 st      %o1, [%fp+var_2C]
F00F419C: 90102100                 mov     0x100, %o0
F00F41A0: d027bfd8                 st      %o0, [%fp+var_28]
F00F41A4: 113c03e9                 sethi   %hi(dword_F00FA474), %o0
F00F41A8: d0022074                 ld      [%o0+%lo(dword_F00FA474)], %o0
F00F41AC: f027bfe0                 st      %i0, [%fp+var_20]
F00F41B0: b207bfd0                 add     %fp, var_30, %i1
F00F41B4: 7ffdc8f1                 call    _mig_get_reply_port
F00F41B8: d027bfe8                 st      %o0, [%fp+var_18]
F00F41BC: d027bfdc                 st      %o0, [%fp+var_24]
F00F41C0: 90102813                 mov     0x813, %o0
F00F41C4: d027bfe4                 st      %o0, [%fp+var_1C]
F00F41C8: 90100019                 mov     %i1, %o0! reply_port
F00F41CC: 92102000                 mov     0, %o1
F00F41D0: 94102028                 mov     0x28, %o2 ! '('
F00F41D4: 96102000                 mov     0, %o3
F00F41D8: 7ffdc781                 call    _msg_rpc
F00F41DC: 98102000                 mov     0, %o4
F00F41E0: b0920000                 orcc    %o0, %g0, %i0
F00F41E4: 02800006                 be      loc_F00F41FC
F00F41E8: 80a63f36                 cmp     %i0, -0xCA
F00F41EC: 1280002b                 bne     locret_F00F4298
F00F41F0: 01000000                 nop
F00F41F4: 7ffdc8ee                 call    _mig_dealloc_reply_port
F00F41F8: 9e03e09c                 inc     0x9C, %o7
F00F41FC: d207bfd4                 ld      [%fp+var_2C], %o1
F00F4200: d007bfe4                 ld      [%fp+var_1C], %o0
F00F4204: 80a22877                 cmp     %o0, 0x877
F00F4208: 02800004                 be      loc_F00F4218
F00F420C: d40fbfd3                 ldub    [%fp+var_2D], %o2
F00F4210: 10800022                 ba      locret_F00F4298
F00F4214: b0103ed3                 mov     -0x12D, %i0
F00F4218: 80a26028                 cmp     %o1, 0x28 ! '('
F00F421C: 12800005                 bne     loc_F00F4230
F00F4220: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4224: 80a2a000                 cmp     %o2, 0
F00F4228: 0280000a                 be      loc_F00F4250
F00F422C: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4230: 1280001a                 bne     locret_F00F4298
F00F4234: b0103ed4                 mov     -0x12C, %i0
F00F4238: 80a2a001                 cmp     %o2, 1
F00F423C: 12800017                 bne     locret_F00F4298
F00F4240: d007bfec                 ld      [%fp+var_14], %o0
F00F4244: 80a22000                 cmp     %o0, 0
F00F4248: 02800014                 be      locret_F00F4298
F00F424C: 01000000                 nop
F00F4250: d0066018                 ld      [%i1+0x18], %o0
F00F4254: 133c03e9                 sethi   %hi(dword_F00FA478), %o1
F00F4258: d2026078                 ld      [%o1+%lo(dword_F00FA478)], %o1
F00F425C: 80a20009                 cmp     %o0, %o1
F00F4260: 1280000e                 bne     locret_F00F4298
F00F4264: b0103ed4                 mov     -0x12C, %i0
F00F4268: f006601c                 ld      [%i1+0x1C], %i0
F00F426C: 80a62000                 cmp     %i0, 0
F00F4270: 1280000a                 bne     locret_F00F4298
F00F4274: 133c03e9                 sethi   %hi(dword_F00FA47C), %o1
F00F4278: d0066020                 ld      [%i1+0x20], %o0
F00F427C: d202607c                 ld      [%o1+%lo(dword_F00FA47C)], %o1
F00F4280: 80a20009                 cmp     %o0, %o1
F00F4284: 12800005                 bne     locret_F00F4298
F00F4288: b0103ed4                 mov     -0x12C, %i0
F00F428C: d0066024                 ld      [%i1+0x24], %o0
F00F4290: d0268000                 st      %o0, [%i2]
F00F4294: f006601c                 ld      [%i1+0x1C], %i0
F00F4298: 81c7e008                 ret
F00F429C: 81e80000                 restore
