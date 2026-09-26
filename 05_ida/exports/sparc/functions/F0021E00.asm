F0021E00: 9de3bf90                 save    %sp, -0x70, %sp! int
F0021E04: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0021E08: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0021E0C: e0022024                 ld      [%o0+0x24], %l0
F0021E10: d0040000                 ld      [%l0], %o0
F0021E14: 4000016f                 call    _getsock
F0021E18: c027bff0                 clr     [%fp+var_10]
F0021E1C: a4920000                 orcc    %o0, %g0, %l2
F0021E20: 02800046                 be      locret_F0021F38
F0021E24: 01000000                 nop
F0021E28: d004200c                 ld      [%l0+0xC], %o0
F0021E2C: 80a22000                 cmp     %o0, 0
F0021E30: 0280000e                 be      loc_F0021E68
F0021E34: 9207bff4                 add     %fp, var_C, %o1! int
F0021E38: d0042010                 ld      [%l0+0x10], %o0! int
F0021E3C: 4001d887                 call    _copyin
F0021E40: 94102004                 mov     4, %o2
F0021E44: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0021E48: d02a6038                 stb     %o0, [%o1+0x38]
F0021E4C: d00461dc                 ld      [%l1+0x1DC], %o0
F0021E50: d04a2038                 ldsb    [%o0+0x38], %o0
F0021E54: 80a22000                 cmp     %o0, 0
F0021E58: 12800038                 bne     locret_F0021F38
F0021E5C: 01000000                 nop
F0021E60: 10800004                 ba      loc_F0021E70
F0021E64: d004a018                 ld      [%l2+0x18], %o0
F0021E68: c027bff4                 clr     [%fp+var_C]
F0021E6C: d004a018                 ld      [%l2+0x18], %o0
F0021E70: d2042004                 ld      [%l0+4], %o1
F0021E74: d4042008                 ld      [%l0+8], %o2
F0021E78: 7ffff79c                 call    _sogetopt
F0021E7C: 9607bff0                 add     %fp, var_10, %o3
F0021E80: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F0021E84: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F0021E88: d02a6038                 stb     %o0, [%o1+0x38]
F0021E8C: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F0021E90: d04a2038                 ldsb    [%o0+0x38], %o0
F0021E94: 80a22000                 cmp     %o0, 0
F0021E98: 12800023                 bne     loc_F0021F24
F0021E9C: d007bff0                 ld      [%fp+var_10], %o0
F0021EA0: d004200c                 ld      [%l0+0xC], %o0
F0021EA4: 80a22000                 cmp     %o0, 0
F0021EA8: 0280001e                 be      loc_F0021F20
F0021EAC: d207bff4                 ld      [%fp+var_C], %o1
F0021EB0: 80a26000                 cmp     %o1, 0
F0021EB4: 0280001b                 be      loc_F0021F20
F0021EB8: d607bff0                 ld      [%fp+var_10], %o3! int
F0021EBC: 80a2e000                 cmp     %o3, 0
F0021EC0: 02800019                 be      loc_F0021F24
F0021EC4: d007bff0                 ld      [%fp+var_10], %o0
F0021EC8: d052e008                 ldsh    [%o3+8], %o0
F0021ECC: 80a24008                 cmp     %o1, %o0
F0021ED0: 34800002                 bg,a    loc_F0021ED8
F0021ED4: d027bff4                 st      %o0, [%fp+var_C]
F0021ED8: d204200c                 ld      [%l0+0xC], %o1! int
F0021EDC: d002e004                 ld      [%o3+4], %o0! int
F0021EE0: d407bff4                 ld      [%fp+var_C], %o2! int
F0021EE4: 4001d87a                 call    _copyout
F0021EE8: 9002c008                 add     %o3, %o0, %o0
F0021EEC: d20461dc                 ld      [%l1+0x1DC], %o1
F0021EF0: d02a6038                 stb     %o0, [%o1+0x38]
F0021EF4: d00461dc                 ld      [%l1+0x1DC], %o0
F0021EF8: d04a2038                 ldsb    [%o0+0x38], %o0
F0021EFC: 80a22000                 cmp     %o0, 0
F0021F00: 12800009                 bne     loc_F0021F24
F0021F04: d007bff0                 ld      [%fp+var_10], %o0
F0021F08: 9007bff4                 add     %fp, var_C, %o0! int
F0021F0C: d2042010                 ld      [%l0+0x10], %o1! int
F0021F10: 4001d86f                 call    _copyout
F0021F14: 94102004                 mov     4, %o2
F0021F18: d20461dc                 ld      [%l1+0x1DC], %o1
F0021F1C: d02a6038                 stb     %o0, [%o1+0x38]
F0021F20: d007bff0                 ld      [%fp+var_10], %o0
F0021F24: 80a22000                 cmp     %o0, 0
F0021F28: 02800004                 be      locret_F0021F38
F0021F2C: 01000000                 nop
F0021F30: 7fffeee1                 call    _m_free
F0021F34: 01000000                 nop
F0021F38: 81c7e008                 ret
F0021F3C: 81e80000                 restore
