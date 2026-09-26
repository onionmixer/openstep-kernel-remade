F00665C4: 9de3bf98                 save    %sp, -0x68, %sp
F00665C8: 80a6a000                 cmp     %i2, 0
F00665CC: 04800010                 ble     locret_F006660C
F00665D0: 86102001                 mov     1, %g3
F00665D4: 80a0c01a                 cmp     %g3, %i2
F00665D8: 3680000d                 bge,a   locret_F006660C
F00665DC: c02e0000                 clrb    [%i0]
F00665E0: c40e4000                 ldub    [%i1], %g2
F00665E4: c42e0000                 stb     %g2, [%i0]
F00665E8: b2066001                 inc     %i1
F00665EC: 80a0a000                 cmp     %g2, 0
F00665F0: 02800007                 be      locret_F006660C
F00665F4: b0062001                 inc     %i0
F00665F8: 8600e001                 inc     %g3
F00665FC: 80a0c01a                 cmp     %g3, %i2
F0066600: 26bffff9                 bl,a    loc_F00665E4
F0066604: c40e4000                 ldub    [%i1], %g2
F0066608: c02e0000                 clrb    [%i0]
F006660C: 81c7e008                 ret
F0066610: 81e80000                 restore
