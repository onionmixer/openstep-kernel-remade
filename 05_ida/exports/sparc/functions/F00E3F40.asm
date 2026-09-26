F00E3F40: 9de3bf80                 save    %sp, -0x80, %sp
F00E3F44: d2062004                 ld      [%i0+4], %o1
F00E3F48: 80a26070                 cmp     %o1, 0x70 ! 'p'
F00E3F4C: 12800005                 bne     loc_F00E3F60
F00E3F50: d00e2003                 ldub    [%i0+3], %o0
F00E3F54: 80a22000                 cmp     %o0, 0
F00E3F58: 22800005                 be,a    loc_F00E3F6C
F00E3F5C: d0062018                 ld      [%i0+0x18], %o0
F00E3F60: 90103ed0                 mov     -0x130, %o0
F00E3F64: 1080005e                 ba      locret_F00E40DC
F00E3F68: d026601c                 st      %o0, [%i1+0x1C]
F00E3F6C: 900a200c                 and     %o0, 0xC, %o0
F00E3F70: 80a22004                 cmp     %o0, 4
F00E3F74: 12800052                 bne     loc_F00E40BC
F00E3F78: 90103ed0                 mov     -0x130, %o0
F00E3F7C: d206201c                 ld      [%i0+0x1C], %o1
F00E3F80: 1100024090122008         set     0x90008, %o0
F00E3F88: 80a24008                 cmp     %o1, %o0
F00E3F8C: 1280004c                 bne     loc_F00E40BC
F00E3F90: 90103ed0                 mov     -0x130, %o0
F00E3F94: d0062028                 ld      [%i0+0x28], %o0
F00E3F98: 133c03e6                 sethi   %hi(dword_F00F9AE4), %o1
F00E3F9C: d20262e4                 ld      [%o1+%lo(dword_F00F9AE4)], %o1
F00E3FA0: 80a20009                 cmp     %o0, %o1
F00E3FA4: 12800046                 bne     loc_F00E40BC
F00E3FA8: 90103ed0                 mov     -0x130, %o0
F00E3FAC: d0062030                 ld      [%i0+0x30], %o0
F00E3FB0: 133c03e6                 sethi   %hi(dword_F00F9AE8), %o1
F00E3FB4: d20262e8                 ld      [%o1+%lo(dword_F00F9AE8)], %o1
F00E3FB8: 80a20009                 cmp     %o0, %o1
F00E3FBC: 12800040                 bne     loc_F00E40BC
F00E3FC0: 90103ed0                 mov     -0x130, %o0
F00E3FC4: d0062038                 ld      [%i0+0x38], %o0
F00E3FC8: 133c03e6                 sethi   %hi(dword_F00F9AEC), %o1
F00E3FCC: d20262ec                 ld      [%o1+%lo(dword_F00F9AEC)], %o1
F00E3FD0: 80a20009                 cmp     %o0, %o1
F00E3FD4: 1280003a                 bne     loc_F00E40BC
F00E3FD8: 90103ed0                 mov     -0x130, %o0
F00E3FDC: d0062040                 ld      [%i0+0x40], %o0
F00E3FE0: 133c03e6                 sethi   %hi(dword_F00F9AF0), %o1
F00E3FE4: d20262f0                 ld      [%o1+%lo(dword_F00F9AF0)], %o1
F00E3FE8: 80a20009                 cmp     %o0, %o1
F00E3FEC: 12800034                 bne     loc_F00E40BC
F00E3FF0: 90103ed0                 mov     -0x130, %o0
F00E3FF4: d0062048                 ld      [%i0+0x48], %o0
F00E3FF8: 133c03e6                 sethi   %hi(dword_F00F9AF4), %o1
F00E3FFC: d20262f4                 ld      [%o1+%lo(dword_F00F9AF4)], %o1
F00E4000: 80a20009                 cmp     %o0, %o1
F00E4004: 1280002e                 bne     loc_F00E40BC
F00E4008: 90103ed0                 mov     -0x130, %o0
F00E400C: d0062050                 ld      [%i0+0x50], %o0
F00E4010: 133c03e6                 sethi   %hi(dword_F00F9AF8), %o1
F00E4014: d20262f8                 ld      [%o1+%lo(dword_F00F9AF8)], %o1
F00E4018: 80a20009                 cmp     %o0, %o1
F00E401C: 12800028                 bne     loc_F00E40BC
F00E4020: 90103ed0                 mov     -0x130, %o0
F00E4024: d0062058                 ld      [%i0+0x58], %o0
F00E4028: 133c03e6                 sethi   %hi(dword_F00F9AFC), %o1
F00E402C: d20262fc                 ld      [%o1+%lo(dword_F00F9AFC)], %o1
F00E4030: 80a20009                 cmp     %o0, %o1
F00E4034: 12800022                 bne     loc_F00E40BC
F00E4038: 90103ed0                 mov     -0x130, %o0
F00E403C: d0062060                 ld      [%i0+0x60], %o0
F00E4040: 133c03e6                 sethi   %hi(dword_F00F9B00), %o1
F00E4044: d2026300                 ld      [%o1+%lo(dword_F00F9B00)], %o1
F00E4048: 80a20009                 cmp     %o0, %o1
F00E404C: 1280001c                 bne     loc_F00E40BC
F00E4050: 90103ed0                 mov     -0x130, %o0
F00E4054: d0062068                 ld      [%i0+0x68], %o0
F00E4058: 133c03e6                 sethi   %hi(dword_F00F9B04), %o1
F00E405C: d2026304                 ld      [%o1+%lo(dword_F00F9B04)], %o1
F00E4060: 80a20009                 cmp     %o0, %o1
F00E4064: 12800016                 bne     loc_F00E40BC
F00E4068: 90103ed0                 mov     -0x130, %o0
F00E406C: 7fffe7e5                 call    _audio_port_to_stream
F00E4070: d006200c                 ld      [%i0+0xC], %o0
F00E4074: d2062024                 ld      [%i0+0x24], %o1
F00E4078: d4062020                 ld      [%i0+0x20], %o2
F00E407C: d606202c                 ld      [%i0+0x2C], %o3
F00E4080: d8062034                 ld      [%i0+0x34], %o4
F00E4084: c4062044                 ld      [%i0+0x44], %g2
F00E4088: da06203c                 ld      [%i0+0x3C], %o5
F00E408C: c423a05c                 st      %g2, [%sp+0x80+var_24]
F00E4090: c406204c                 ld      [%i0+0x4C], %g2
F00E4094: c423a060                 st      %g2, [%sp+0x80+var_20]
F00E4098: c4062054                 ld      [%i0+0x54], %g2
F00E409C: c423a064                 st      %g2, [%sp+0x80+var_1C]
F00E40A0: c406205c                 ld      [%i0+0x5C], %g2
F00E40A4: c423a068                 st      %g2, [%sp+0x80+var_18]
F00E40A8: c4062064                 ld      [%i0+0x64], %g2
F00E40AC: c423a06c                 st      %g2, [%sp+0x80+var_14]
F00E40B0: c406206c                 ld      [%i0+0x6C], %g2
F00E40B4: 7fffea44                 call    __NXAudioPlayStream
F00E40B8: c423a070                 st      %g2, [%sp+0x80+var_10]
F00E40BC: d026601c                 st      %o0, [%i1+0x1C]
F00E40C0: d006601c                 ld      [%i1+0x1C], %o0
F00E40C4: 80a22000                 cmp     %o0, 0
F00E40C8: 12800005                 bne     locret_F00E40DC
F00E40CC: 92102020                 mov     0x20, %o1 ! ' '
F00E40D0: 90102001                 mov     1, %o0
F00E40D4: d02e6003                 stb     %o0, [%i1+3]
F00E40D8: d2266004                 st      %o1, [%i1+4]
F00E40DC: 81c7e008                 ret
F00E40E0: 81e80000                 restore
