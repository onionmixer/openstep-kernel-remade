F0012FCC: 9de3bf70                 save    %sp, -0x90, %sp! int
F0012FD0: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0012FD4: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0012FD8: 7ffff265                 call    _suser
F0012FDC: e2022024                 ld      [%o0+0x24], %l1
F0012FE0: 80a22000                 cmp     %o0, 0
F0012FE4: 02800021                 be      locret_F0013068
F0012FE8: 9207bff0                 add     %fp, var_10, %o1! int
F0012FEC: d0044000                 ld      [%l1], %o0! int
F0012FF0: 4002141a                 call    _copyin
F0012FF4: 94102008                 mov     8, %o2
F0012FF8: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0012FFC: d02a6038                 stb     %o0, [%o1+0x38]
F0013000: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0013004: d04a2038                 ldsb    [%o0+0x38], %o0
F0013008: 80a22000                 cmp     %o0, 0
F001300C: 12800017                 bne     locret_F0013068
F0013010: 113c04d4                 sethi   %hi(dword_F0135174), %o0
F0013014: d0022174                 ld      [%o0+%lo(dword_F0135174)], %o0
F0013018: 9207bfd0                 add     %fp, var_30, %o1
F001301C: d807bff0                 ld      [%fp+var_10], %o4! int
F0013020: 9407bfd8                 add     %fp, var_28, %o2
F0013024: d607bff4                 ld      [%fp+var_C], %o3! int
F0013028: d827bfe0                 st      %o4, [%fp+var_20]
F001302C: d627bfe4                 st      %o3, [%fp+var_1C]
F0013030: d827bfd0                 st      %o4, [%fp+var_30]
F0013034: 40015ae1                 call    _host_adjust_time
F0013038: d627bfd4                 st      %o3, [%fp+var_2C]
F001303C: d0046004                 ld      [%l1+4], %o0
F0013040: 80a22000                 cmp     %o0, 0
F0013044: 02800009                 be      locret_F0013068
F0013048: d407bfd8                 ld      [%fp+var_28], %o2! int
F001304C: 9007bfe8                 add     %fp, var_18, %o0! int
F0013050: d207bfdc                 ld      [%fp+var_24], %o1
F0013054: d427bfe8                 st      %o2, [%fp+var_18]
F0013058: d227bfec                 st      %o1, [%fp+var_14]
F001305C: d2046004                 ld      [%l1+4], %o1! int
F0013060: 4002141b                 call    _copyout
F0013064: 94102008                 mov     8, %o2
F0013068: 81c7e008                 ret
F001306C: 81e80000                 restore
