F0027C00: 9de3bf70                 save    %sp, -0x90, %sp! int
F0027C04: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0027C08: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0027C0C: e2022024                 ld      [%o0+0x24], %l1
F0027C10: d0044000                 ld      [%l1], %o0
F0027C14: 40000381                 call    _getvnodefp
F0027C18: 9207bfd4                 add     %fp, var_2C, %o1
F0027C1C: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0027C20: d02a6038                 stb     %o0, [%o1+0x38]
F0027C24: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0027C28: d04a6038                 ldsb    [%o1+0x38], %o0
F0027C2C: 80a22000                 cmp     %o0, 0
F0027C30: 12800046                 bne     locret_F0027D48
F0027C34: d007bfd4                 ld      [%fp+var_2C], %o0
F0027C38: d0022008                 ld      [%o0+8], %o0
F0027C3C: 808a2001                 btst    1, %o0
F0027C40: 32800006                 bne,a   loc_F0027C58
F0027C44: d0046004                 ld      [%l1+4], %o0
F0027C48: 90102009                 mov     9, %o0
F0027C4C: 1080003f                 ba      locret_F0027D48
F0027C50: d02a6038                 stb     %o0, [%o1+0x38]
F0027C54: d0046004                 ld      [%l1+4], %o0
F0027C58: d027bfd8                 st      %o0, [%fp+var_28]
F0027C5C: d0046008                 ld      [%l1+8], %o0
F0027C60: d607bfd4                 ld      [%fp+var_2C], %o3
F0027C64: d027bfdc                 st      %o0, [%fp+var_24]
F0027C68: 9007bfd8                 add     %fp, var_28, %o0
F0027C6C: d027bfe0                 st      %o0, [%fp+var_20]
F0027C70: 90102001                 mov     1, %o0
F0027C74: d027bfe4                 st      %o0, [%fp+var_1C]
F0027C78: d202e01c                 ld      [%o3+0x1C], %o1
F0027C7C: d227bfe8                 st      %o1, [%fp+var_18]
F0027C80: c027bfec                 clr     [%fp+var_14]
F0027C84: d0046008                 ld      [%l1+8], %o0
F0027C88: 80a26000                 cmp     %o1, 0
F0027C8C: 06800014                 bl      loc_F0027CDC
F0027C90: d027bff4                 st      %o0, [%fp+var_C]
F0027C94: d002e018                 ld      [%o3+0x18], %o0
F0027C98: d402e020                 ld      [%o3+0x20], %o2
F0027C9C: d602201c                 ld      [%o0+0x1C], %o3
F0027CA0: d602e03c                 ld      [%o3+0x3C], %o3! int
F0027CA4: 9fc2c000                 call    %o3
F0027CA8: 9207bfe0                 add     %fp, var_20, %o1
F0027CAC: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0027CB0: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0027CB4: d02a6038                 stb     %o0, [%o1+0x38]
F0027CB8: d2046008                 ld      [%l1+8], %o1
F0027CBC: d007bff4                 ld      [%fp+var_C], %o0
F0027CC0: 80a24008                 cmp     %o1, %o0
F0027CC4: 1280000e                 bne     loc_F0027CFC
F0027CC8: 213c04cf                 sethi   -0xFECC400, %l0
F0027CCC: d207bfd4                 ld      [%fp+var_2C], %o1
F0027CD0: 90103c00                 mov     -0x400, %o0
F0027CD4: 10bfffe0                 ba      loc_F0027C54
F0027CD8: d022601c                 st      %o0, [%o1+0x1C]
F0027CDC: d002e018                 ld      [%o3+0x18], %o0
F0027CE0: d402e020                 ld      [%o3+0x20], %o2
F0027CE4: 4000001b                 call    _getfakedirentries
F0027CE8: 9207bfe0                 add     %fp, var_20, %o1
F0027CEC: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0027CF0: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0027CF4: d02a6038                 stb     %o0, [%o1+0x38]
F0027CF8: 213c04cf                 sethi   -0xFECC400, %l0
F0027CFC: d00421dc                 ld      [%l0+0x1DC], %o0
F0027D00: d04a2038                 ldsb    [%o0+0x38], %o0
F0027D04: 80a22000                 cmp     %o0, 0
F0027D08: 12800010                 bne     locret_F0027D48
F0027D0C: d007bfd4                 ld      [%fp+var_2C], %o0! int
F0027D10: 94102004                 mov     4, %o2! int
F0027D14: d204600c                 ld      [%l1+0xC], %o1! int
F0027D18: 4001c0ed                 call    _copyout
F0027D1C: 9002201c                 inc     0x1C, %o0
F0027D20: d20421dc                 ld      [%l0+0x1DC], %o1
F0027D24: d02a6038                 stb     %o0, [%o1+0x38]
F0027D28: d0046008                 ld      [%l1+8], %o0
F0027D2C: d207bff4                 ld      [%fp+var_C], %o1
F0027D30: d40421dc                 ld      [%l0+0x1DC], %o2
F0027D34: 90220009                 sub     %o0, %o1, %o0
F0027D38: d207bfd4                 ld      [%fp+var_2C], %o1
F0027D3C: d022a030                 st      %o0, [%o2+0x30]
F0027D40: d007bfe8                 ld      [%fp+var_18], %o0
F0027D44: d022601c                 st      %o0, [%o1+0x1C]
F0027D48: 81c7e008                 ret
F0027D4C: 81e80000                 restore
