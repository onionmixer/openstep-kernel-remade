F00F42A0: 9de3bf70                 save    %sp, -0x90, %sp
F00F42A4: 92102028                 mov     0x28, %o1 ! '('
F00F42A8: f227bfec                 st      %i1, [%fp+var_14]
F00F42AC: f427bff4                 st      %i2, [%fp+var_C]
F00F42B0: c02fbfd3                 clrb    [%fp+var_2D]
F00F42B4: d227bfd4                 st      %o1, [%fp+var_2C]
F00F42B8: 90102100                 mov     0x100, %o0
F00F42BC: d027bfd8                 st      %o0, [%fp+var_28]
F00F42C0: f027bfe0                 st      %i0, [%fp+var_20]
F00F42C4: 113c03e9                 sethi   %hi(dword_F00FA480), %o0
F00F42C8: d2022080                 ld      [%o0+%lo(dword_F00FA480)], %o1
F00F42CC: b207bfd0                 add     %fp, var_30, %i1
F00F42D0: 113c03e9                 sethi   %hi(dword_F00FA484), %o0
F00F42D4: d0022084                 ld      [%o0+%lo(dword_F00FA484)], %o0
F00F42D8: d227bfe8                 st      %o1, [%fp+var_18]
F00F42DC: 7ffdc8a7                 call    _mig_get_reply_port
F00F42E0: d027bff0                 st      %o0, [%fp+var_10]
F00F42E4: d027bfdc                 st      %o0, [%fp+var_24]
F00F42E8: 90102814                 mov     0x814, %o0
F00F42EC: d027bfe4                 st      %o0, [%fp+var_1C]
F00F42F0: 90100019                 mov     %i1, %o0! reply_port
F00F42F4: 92102000                 mov     0, %o1
F00F42F8: 94102020                 mov     0x20, %o2 ! ' '
F00F42FC: 96102000                 mov     0, %o3
F00F4300: 7ffdc737                 call    _msg_rpc
F00F4304: 98102000                 mov     0, %o4
F00F4308: b0920000                 orcc    %o0, %g0, %i0
F00F430C: 02800006                 be      loc_F00F4324
F00F4310: 80a63f36                 cmp     %i0, -0xCA
F00F4314: 12800023                 bne     locret_F00F43A0
F00F4318: 01000000                 nop
F00F431C: 7ffdc8a4                 call    _mig_dealloc_reply_port
F00F4320: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F4324: d207bfd4                 ld      [%fp+var_2C], %o1
F00F4328: d007bfe4                 ld      [%fp+var_1C], %o0
F00F432C: 80a22878                 cmp     %o0, 0x878
F00F4330: 02800004                 be      loc_F00F4340
F00F4334: d40fbfd3                 ldub    [%fp+var_2D], %o2
F00F4338: 1080001a                 ba      locret_F00F43A0
F00F433C: b0103ed3                 mov     -0x12D, %i0
F00F4340: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4344: 12800017                 bne     locret_F00F43A0
F00F4348: b0103ed4                 mov     -0x12C, %i0
F00F434C: 80a2a001                 cmp     %o2, 1
F00F4350: 0280000a                 be      loc_F00F4378
F00F4354: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4358: 12800012                 bne     locret_F00F43A0
F00F435C: 01000000                 nop
F00F4360: 80a2a001                 cmp     %o2, 1
F00F4364: 1280000f                 bne     locret_F00F43A0
F00F4368: d007bfec                 ld      [%fp+var_14], %o0
F00F436C: 80a22000                 cmp     %o0, 0
F00F4370: 0280000c                 be      locret_F00F43A0
F00F4374: 01000000                 nop
F00F4378: d0066018                 ld      [%i1+0x18], %o0
F00F437C: 133c03e9                 sethi   %hi(dword_F00FA488), %o1
F00F4380: d2026088                 ld      [%o1+%lo(dword_F00FA488)], %o1
F00F4384: 80a20009                 cmp     %o0, %o1
F00F4388: 12800006                 bne     locret_F00F43A0
F00F438C: b0103ed4                 mov     -0x12C, %i0
F00F4390: f006601c                 ld      [%i1+0x1C], %i0
F00F4394: 80a62000                 cmp     %i0, 0
F00F4398: 22800002                 be,a    locret_F00F43A0
F00F439C: b0102000                 mov     0, %i0
F00F43A0: 81c7e008                 ret
F00F43A4: 81e80000                 restore
