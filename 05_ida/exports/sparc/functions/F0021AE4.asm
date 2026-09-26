F0021AE4: 9de3bf70                 save    %sp, -0x90, %sp! int
F0021AE8: 4000023a                 call    _getsock
F0021AEC: 90100018                 mov     %i0, %o0
F0021AF0: a4920000                 orcc    %o0, %g0, %l2
F0021AF4: 0280007c                 be      locret_F0021CE4
F0021AF8: a2102000                 mov     0, %l1
F0021AFC: d0066008                 ld      [%i1+8], %o0
F0021B00: d027bfe0                 st      %o0, [%fp+var_20]
F0021B04: d006600c                 ld      [%i1+0xC], %o0
F0021B08: d027bfe4                 st      %o0, [%fp+var_1C]
F0021B0C: c027bfec                 clr     [%fp+var_14]
F0021B10: c027bfe8                 clr     [%fp+var_18]
F0021B14: c027bff4                 clr     [%fp+var_C]
F0021B18: d006600c                 ld      [%i1+0xC], %o0
F0021B1C: 80a44008                 cmp     %l1, %o0
F0021B20: 16800018                 bge     loc_F0021B80
F0021B24: e0066008                 ld      [%i1+8], %l0
F0021B28: b0042004                 add     %l0, 4, %i0
F0021B2C: d2060000                 ld      [%i0], %o1
F0021B30: 80a26000                 cmp     %o1, 0
F0021B34: 0680004b                 bl      loc_F0021C60
F0021B38: 113c04cf                 sethi   -0xFECC400, %o0
F0021B3C: 2280000c                 be,a    loc_F0021B6C
F0021B40: a2046001                 inc     %l1
F0021B44: d0040000                 ld      [%l0], %o0
F0021B48: 4001a0a0                 call    _useracc
F0021B4C: 94102000                 mov     0, %o2
F0021B50: 80a22000                 cmp     %o0, 0
F0021B54: 02800047                 be      loc_F0021C70
F0021B58: d007bff4                 ld      [%fp+var_C], %o0
F0021B5C: d2060000                 ld      [%i0], %o1
F0021B60: 90020009                 add     %o0, %o1, %o0
F0021B64: d027bff4                 st      %o0, [%fp+var_C]
F0021B68: a2046001                 inc     %l1
F0021B6C: b0062008                 inc     8, %i0
F0021B70: d006600c                 ld      [%i1+0xC], %o0
F0021B74: 80a44008                 cmp     %l1, %o0
F0021B78: 06bfffed                 bl      loc_F0021B2C
F0021B7C: a0042008                 inc     8, %l0
F0021B80: 9207bfdc                 add     %fp, var_24, %o1
F0021B84: 9407bfe0                 add     %fp, var_20, %o2
F0021B88: d607bff4                 ld      [%fp+var_C], %o3
F0021B8C: 9807bfd8                 add     %fp, var_28, %o4! int
F0021B90: d004a018                 ld      [%l2+0x18], %o0
F0021B94: d627bfd4                 st      %o3, [%fp+var_2C]
F0021B98: 7ffff54b                 call    _soreceive
F0021B9C: 9610001a                 mov     %i2, %o3
F0021BA0: 173c04cf                 sethi   %hi(dword_F0133DDC), %o3
F0021BA4: d202e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o1
F0021BA8: d02a6038                 stb     %o0, [%o1+0x38]
F0021BAC: d407bff4                 ld      [%fp+var_C], %o2
F0021BB0: d007bfd4                 ld      [%fp+var_2C], %o0
F0021BB4: d202e1dc                 ld      [%o3+%lo(dword_F0133DDC)], %o1
F0021BB8: 9022000a                 sub     %o0, %o2, %o0
F0021BBC: d0226030                 st      %o0, [%o1+0x30]
F0021BC0: d0064000                 ld      [%i1], %o0
F0021BC4: 80a22000                 cmp     %o0, 0
F0021BC8: 22800019                 be,a    loc_F0021C2C
F0021BCC: d0066010                 ld      [%i1+0x10], %o0
F0021BD0: d0066004                 ld      [%i1+4], %o0
F0021BD4: 80a22000                 cmp     %o0, 0
F0021BD8: 04800006                 ble     loc_F0021BF0
F0021BDC: d027bfd4                 st      %o0, [%fp+var_2C]
F0021BE0: d607bfdc                 ld      [%fp+var_24], %o3! int
F0021BE4: 80a2e000                 cmp     %o3, 0
F0021BE8: 32800004                 bne,a   loc_F0021BF8
F0021BEC: d252e008                 ldsh    [%o3+8], %o1
F0021BF0: 1080000a                 ba      loc_F0021C18
F0021BF4: c027bfd4                 clr     [%fp+var_2C]
F0021BF8: 80a20009                 cmp     %o0, %o1
F0021BFC: 34800002                 bg,a    loc_F0021C04
F0021C00: d227bfd4                 st      %o1, [%fp+var_2C]
F0021C04: d2064000                 ld      [%i1], %o1! int
F0021C08: d002e004                 ld      [%o3+4], %o0! int
F0021C0C: d407bfd4                 ld      [%fp+var_2C], %o2! int
F0021C10: 4001d92f                 call    _copyout
F0021C14: 9002c008                 add     %o3, %o0, %o0
F0021C18: 9007bfd4                 add     %fp, var_2C, %o0! int
F0021C1C: 9210001b                 mov     %i3, %o1! int
F0021C20: 4001d92b                 call    _copyout
F0021C24: 94102004                 mov     4, %o2
F0021C28: d0066010                 ld      [%i1+0x10], %o0
F0021C2C: 80a22000                 cmp     %o0, 0
F0021C30: 02800022                 be      loc_F0021CB8
F0021C34: d007bfd8                 ld      [%fp+var_28], %o0
F0021C38: d0066014                 ld      [%i1+0x14], %o0
F0021C3C: 80a22000                 cmp     %o0, 0
F0021C40: 04800006                 ble     loc_F0021C58
F0021C44: d027bfd4                 st      %o0, [%fp+var_2C]
F0021C48: d607bfd8                 ld      [%fp+var_28], %o3! int
F0021C4C: 80a2e000                 cmp     %o3, 0
F0021C50: 3280000d                 bne,a   loc_F0021C84
F0021C54: d252e008                 ldsh    [%o3+8], %o1
F0021C58: 10800013                 ba      loc_F0021CA4
F0021C5C: c027bfd4                 clr     [%fp+var_2C]
F0021C60: d20221dc                 ld      [%o0+0x1DC], %o1
F0021C64: 90102016                 mov     0x16, %o0
F0021C68: 1080001f                 ba      locret_F0021CE4
F0021C6C: d02a6038                 stb     %o0, [%o1+0x38]
F0021C70: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0021C74: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0021C78: 9010200e                 mov     0xE, %o0
F0021C7C: 1080001a                 ba      locret_F0021CE4
F0021C80: d02a6038                 stb     %o0, [%o1+0x38]
F0021C84: 80a20009                 cmp     %o0, %o1
F0021C88: 34800002                 bg,a    loc_F0021C90
F0021C8C: d227bfd4                 st      %o1, [%fp+var_2C]
F0021C90: d2066010                 ld      [%i1+0x10], %o1! int
F0021C94: d002e004                 ld      [%o3+4], %o0! int
F0021C98: d407bfd4                 ld      [%fp+var_2C], %o2! int
F0021C9C: 4001d90c                 call    _copyout
F0021CA0: 9002c008                 add     %o3, %o0, %o0
F0021CA4: 9007bfd4                 add     %fp, var_2C, %o0! int
F0021CA8: 9210001c                 mov     %i4, %o1! int
F0021CAC: 4001d908                 call    _copyout
F0021CB0: 94102004                 mov     4, %o2
F0021CB4: d007bfd8                 ld      [%fp+var_28], %o0
F0021CB8: 80a22000                 cmp     %o0, 0
F0021CBC: 22800005                 be,a    loc_F0021CD0
F0021CC0: d007bfdc                 ld      [%fp+var_24], %o0
F0021CC4: 7fffefe8                 call    _m_freem
F0021CC8: 01000000                 nop
F0021CCC: d007bfdc                 ld      [%fp+var_24], %o0
F0021CD0: 80a22000                 cmp     %o0, 0
F0021CD4: 02800004                 be      locret_F0021CE4
F0021CD8: 01000000                 nop
F0021CDC: 7fffefe2                 call    _m_freem
F0021CE0: 01000000                 nop
F0021CE4: 81c7e008                 ret
F0021CE8: 81e80000                 restore
