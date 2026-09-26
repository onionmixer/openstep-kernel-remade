F00DF2A4: 9de3bf80                 save    %sp, -0x80, %sp
F00DF2A8: 90102194                 mov     0x194, %o0
F00DF2AC: d027bfe0                 st      %o0, [%fp+var_20]
F00DF2B0: 90102193                 mov     0x193, %o0
F00DF2B4: d027bfe4                 st      %o0, [%fp+var_1C]
F00DF2B8: 90102191                 mov     0x191, %o0
F00DF2BC: d027bfe8                 st      %o0, [%fp+var_18]
F00DF2C0: 90102190                 mov     0x190, %o0
F00DF2C4: d027bfec                 st      %o0, [%fp+var_14]
F00DF2C8: 90102192                 mov     0x192, %o0
F00DF2CC: d027bff0                 st      %o0, [%fp+var_10]
F00DF2D0: 9c03bf88                 inc     -0x78, %sp
F00DF2D4: 9603a060                 add     %sp, arg_60, %o3
F00DF2D8: fa22c000                 st      %i5, [%o3]
F00DF2DC: f422e008                 st      %i2, [%o3+8]
F00DF2E0: d007a05c                 ld      [%fp+arg_5C], %o0
F00DF2E4: 80a6e002                 cmp     %i3, 2
F00DF2E8: 02800009                 be      loc_F00DF30C
F00DF2EC: d022e004                 st      %o0, [%o3+4]
F00DF2F0: 80a6e002                 cmp     %i3, 2
F00DF2F4: 04800008                 ble     loc_F00DF314
F00DF2F8: 80a6e004                 cmp     %i3, 4
F00DF2FC: 12800007                 bne     loc_F00DF318
F00DF300: 9010225a                 mov     0x25A, %o0
F00DF304: 10800005                 ba      loc_F00DF318
F00DF308: 90102258                 mov     0x258, %o0
F00DF30C: 10800003                 ba      loc_F00DF318
F00DF310: 90102259                 mov     0x259, %o0
F00DF314: 9010225a                 mov     0x25A, %o0
F00DF318: d022e00c                 st      %o0, [%o3+0xC]
F00DF31C: f822e010                 st      %i4, [%o3+0x10]
F00DF320: 90100019                 mov     %i1, %o0
F00DF324: 9207bfe0                 add     %fp, var_20, %o1
F00DF328: 7fffff80                 call    __NXAudioSetStreamParameters
F00DF32C: 94102005                 mov     5, %o2
F00DF330: 81c7e008                 ret
F00DF334: 81e80000                 restore
