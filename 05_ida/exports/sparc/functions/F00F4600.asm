F00F4600: 9de3bf70                 save    %sp, -0x90, %sp
F00F4604: 92102028                 mov     0x28, %o1 ! '('
F00F4608: f227bfec                 st      %i1, [%fp+var_14]
F00F460C: f427bff4                 st      %i2, [%fp+var_C]
F00F4610: 90102001                 mov     1, %o0
F00F4614: d02fbfd3                 stb     %o0, [%fp+var_2D]
F00F4618: d227bfd4                 st      %o1, [%fp+var_2C]
F00F461C: 90102100                 mov     0x100, %o0
F00F4620: d027bfd8                 st      %o0, [%fp+var_28]
F00F4624: f027bfe0                 st      %i0, [%fp+var_20]
F00F4628: 113c03e9                 sethi   %hi(dword_F00FA4A4), %o0
F00F462C: d20220a4                 ld      [%o0+%lo(dword_F00FA4A4)], %o1
F00F4630: b207bfd0                 add     %fp, var_30, %i1
F00F4634: 113c03e9                 sethi   %hi(dword_F00FA4A8), %o0
F00F4638: d00220a8                 ld      [%o0+%lo(dword_F00FA4A8)], %o0
F00F463C: d227bfe8                 st      %o1, [%fp+var_18]
F00F4640: 7ffdc7ce                 call    _mig_get_reply_port
F00F4644: d027bff0                 st      %o0, [%fp+var_10]
F00F4648: d027bfdc                 st      %o0, [%fp+var_24]
F00F464C: 9010281e                 mov     0x81E, %o0
F00F4650: d027bfe4                 st      %o0, [%fp+var_1C]
F00F4654: 90100019                 mov     %i1, %o0! reply_port
F00F4658: 92102000                 mov     0, %o1
F00F465C: 94102020                 mov     0x20, %o2 ! ' '
F00F4660: 96102000                 mov     0, %o3
F00F4664: 7ffdc65e                 call    _msg_rpc
F00F4668: 98102000                 mov     0, %o4
F00F466C: b0920000                 orcc    %o0, %g0, %i0
F00F4670: 02800006                 be      loc_F00F4688
F00F4674: 80a63f36                 cmp     %i0, -0xCA
F00F4678: 12800023                 bne     locret_F00F4704
F00F467C: 01000000                 nop
F00F4680: 7ffdc7cb                 call    _mig_dealloc_reply_port
F00F4684: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F4688: d207bfd4                 ld      [%fp+var_2C], %o1
F00F468C: d007bfe4                 ld      [%fp+var_1C], %o0
F00F4690: 80a22882                 cmp     %o0, 0x882
F00F4694: 02800004                 be      loc_F00F46A4
F00F4698: d40fbfd3                 ldub    [%fp+var_2D], %o2
F00F469C: 1080001a                 ba      locret_F00F4704
F00F46A0: b0103ed3                 mov     -0x12D, %i0
F00F46A4: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F46A8: 12800017                 bne     locret_F00F4704
F00F46AC: b0103ed4                 mov     -0x12C, %i0
F00F46B0: 80a2a001                 cmp     %o2, 1
F00F46B4: 0280000a                 be      loc_F00F46DC
F00F46B8: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F46BC: 12800012                 bne     locret_F00F4704
F00F46C0: 01000000                 nop
F00F46C4: 80a2a001                 cmp     %o2, 1
F00F46C8: 1280000f                 bne     locret_F00F4704
F00F46CC: d007bfec                 ld      [%fp+var_14], %o0
F00F46D0: 80a22000                 cmp     %o0, 0
F00F46D4: 0280000c                 be      locret_F00F4704
F00F46D8: 01000000                 nop
F00F46DC: d0066018                 ld      [%i1+0x18], %o0
F00F46E0: 133c03e9                 sethi   %hi(dword_F00FA4AC), %o1
F00F46E4: d20260ac                 ld      [%o1+%lo(dword_F00FA4AC)], %o1
F00F46E8: 80a20009                 cmp     %o0, %o1
F00F46EC: 12800006                 bne     locret_F00F4704
F00F46F0: b0103ed4                 mov     -0x12C, %i0
F00F46F4: f006601c                 ld      [%i1+0x1C], %i0
F00F46F8: 80a62000                 cmp     %i0, 0
F00F46FC: 22800002                 be,a    locret_F00F4704
F00F4700: b0102000                 mov     0, %i0
F00F4704: 81c7e008                 ret
F00F4708: 81e80000                 restore
