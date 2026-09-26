F00F3F80: 9de3bf78                 save    %sp, -0x88, %sp
F00F3F84: 92102020                 mov     0x20, %o1 ! ' '
F00F3F88: f227bff4                 st      %i1, [%fp+var_C]
F00F3F8C: 90102001                 mov     1, %o0
F00F3F90: d02fbfdb                 stb     %o0, [%fp+var_25]
F00F3F94: d227bfdc                 st      %o1, [%fp+var_24]
F00F3F98: 90102100                 mov     0x100, %o0
F00F3F9C: d027bfe0                 st      %o0, [%fp+var_20]
F00F3FA0: 113c03e9                 sethi   %hi(dword_F00FA460), %o0
F00F3FA4: d0022060                 ld      [%o0+%lo(dword_F00FA460)], %o0
F00F3FA8: f027bfe8                 st      %i0, [%fp+var_18]
F00F3FAC: b207bfd8                 add     %fp, var_28, %i1
F00F3FB0: 7ffdc972                 call    _mig_get_reply_port
F00F3FB4: d027bff0                 st      %o0, [%fp+var_10]
F00F3FB8: d027bfe4                 st      %o0, [%fp+var_1C]
F00F3FBC: 90102821                 mov     0x821, %o0
F00F3FC0: d027bfec                 st      %o0, [%fp+var_14]
F00F3FC4: 90100019                 mov     %i1, %o0! reply_port
F00F3FC8: 92102000                 mov     0, %o1
F00F3FCC: 94102020                 mov     0x20, %o2 ! ' '
F00F3FD0: 96102000                 mov     0, %o3
F00F3FD4: 7ffdc802                 call    _msg_rpc
F00F3FD8: 98102000                 mov     0, %o4
F00F3FDC: b0920000                 orcc    %o0, %g0, %i0
F00F3FE0: 02800006                 be      loc_F00F3FF8
F00F3FE4: 80a63f36                 cmp     %i0, -0xCA
F00F3FE8: 12800023                 bne     locret_F00F4074
F00F3FEC: 01000000                 nop
F00F3FF0: 7ffdc96f                 call    _mig_dealloc_reply_port
F00F3FF4: 9e03e07c                 inc     0x7C, %o7 ! '|'
F00F3FF8: d207bfdc                 ld      [%fp+var_24], %o1
F00F3FFC: d007bfec                 ld      [%fp+var_14], %o0
F00F4000: 80a22885                 cmp     %o0, 0x885
F00F4004: 02800004                 be      loc_F00F4014
F00F4008: d40fbfdb                 ldub    [%fp+var_25], %o2
F00F400C: 1080001a                 ba      locret_F00F4074
F00F4010: b0103ed3                 mov     -0x12D, %i0
F00F4014: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F4018: 12800017                 bne     locret_F00F4074
F00F401C: b0103ed4                 mov     -0x12C, %i0
F00F4020: 80a2a001                 cmp     %o2, 1
F00F4024: 0280000a                 be      loc_F00F404C
F00F4028: 80a26020                 cmp     %o1, 0x20 ! ' '
F00F402C: 12800012                 bne     locret_F00F4074
F00F4030: 01000000                 nop
F00F4034: 80a2a001                 cmp     %o2, 1
F00F4038: 1280000f                 bne     locret_F00F4074
F00F403C: d007bff4                 ld      [%fp+var_C], %o0
F00F4040: 80a22000                 cmp     %o0, 0
F00F4044: 0280000c                 be      locret_F00F4074
F00F4048: 01000000                 nop
F00F404C: d0066018                 ld      [%i1+0x18], %o0
F00F4050: 133c03e9                 sethi   %hi(dword_F00FA464), %o1
F00F4054: d2026064                 ld      [%o1+%lo(dword_F00FA464)], %o1
F00F4058: 80a20009                 cmp     %o0, %o1
F00F405C: 12800006                 bne     locret_F00F4074
F00F4060: b0103ed4                 mov     -0x12C, %i0
F00F4064: f006601c                 ld      [%i1+0x1C], %i0
F00F4068: 80a62000                 cmp     %i0, 0
F00F406C: 22800002                 be,a    locret_F00F4074
F00F4070: b0102000                 mov     0, %i0
F00F4074: 81c7e008                 ret
F00F4078: 81e80000                 restore
