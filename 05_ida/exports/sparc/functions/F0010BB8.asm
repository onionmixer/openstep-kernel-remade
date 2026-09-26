F0010BB8: 9de3bf88                 save    %sp, -0x78, %sp! int
F0010BBC: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F0010BC0: d004e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o0
F0010BC4: e0022024                 ld      [%o0+0x24], %l0
F0010BC8: e2040000                 ld      [%l0], %l1
F0010BCC: 98047fff                 add     %l1, -1, %o4! int
F0010BD0: 80a3201e                 cmp     %o4, 0x1E
F0010BD4: 18800007                 bgu     loc_F0010BF0
F0010BD8: 9214e1dc                 or      %l3, %lo(dword_F0133DDC), %o1
F0010BDC: 80a46009                 cmp     %l1, 9
F0010BE0: 02800004                 be      loc_F0010BF0
F0010BE4: 80a46011                 cmp     %l1, 0x11
F0010BE8: 32800007                 bne,a   loc_F0010C04
F0010BEC: d0042008                 ld      [%l0+8], %o0
F0010BF0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0010BF4: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0010BF8: 90102016                 mov     0x16, %o0
F0010BFC: 10800045                 ba      locret_F0010D10
F0010C00: d02a6038                 stb     %o0, [%o1+0x38]
F0010C04: 80a22000                 cmp     %o0, 0
F0010C08: 02800021                 be      loc_F0010C8C
F0010C0C: a407bfe8                 add     %fp, var_18, %l2
F0010C10: d4027ffc                 ld      [%o1-4], %o2! int
F0010C14: 912c6002                 sll     %l1, 2, %o0
F0010C18: 9002000a                 add     %o0, %o2, %o0
F0010C1C: d2022030                 ld      [%o0+0x30], %o1
F0010C20: d227bfe8                 st      %o1, [%fp+var_18]
F0010C24: d00220b4                 ld      [%o0+0xB4], %o0
F0010C28: 96102001                 mov     1, %o3! int
F0010C2C: d027bfec                 st      %o0, [%fp+var_14]
F0010C30: c027bff0                 clr     [%fp+var_10]
F0010C34: d002a138                 ld      [%o2+0x138], %o0
F0010C38: 932ac00c                 sll     %o3, %o4, %o1
F0010C3C: 808a0009                 btst    %o1, %o0
F0010C40: 32800002                 bne,a   loc_F0010C48
F0010C44: d627bff0                 st      %o3, [%fp+var_10]
F0010C48: d002a13c                 ld      [%o2+0x13C], %o0
F0010C4C: 808a0009                 btst    %o1, %o0
F0010C50: 02800004                 be      loc_F0010C60
F0010C54: d007bff0                 ld      [%fp+var_10], %o0
F0010C58: 90122002                 bset    2, %o0
F0010C5C: d027bff0                 st      %o0, [%fp+var_10]
F0010C60: 90100012                 mov     %l2, %o0! int
F0010C64: d2042008                 ld      [%l0+8], %o1! int
F0010C68: 40021d19                 call    _copyout
F0010C6C: 9410200c                 mov     0xC, %o2! int
F0010C70: d204e1dc                 ld      [%l3+0x1DC], %o1
F0010C74: d02a6038                 stb     %o0, [%o1+0x38]
F0010C78: d004e1dc                 ld      [%l3+0x1DC], %o0
F0010C7C: d04a2038                 ldsb    [%o0+0x38], %o0
F0010C80: 80a22000                 cmp     %o0, 0
F0010C84: 12800023                 bne     locret_F0010D10
F0010C88: 01000000                 nop
F0010C8C: d0042004                 ld      [%l0+4], %o0! int
F0010C90: 80a22000                 cmp     %o0, 0
F0010C94: 0280001f                 be      locret_F0010D10
F0010C98: 92100012                 mov     %l2, %o1! int
F0010C9C: 40021cef                 call    _copyin
F0010CA0: 9410200c                 mov     0xC, %o2
F0010CA4: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0010CA8: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F0010CAC: d02aa038                 stb     %o0, [%o2+0x38]
F0010CB0: d40261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o2
F0010CB4: d04aa038                 ldsb    [%o2+0x38], %o0
F0010CB8: 80a22000                 cmp     %o0, 0
F0010CBC: 12800015                 bne     locret_F0010D10
F0010CC0: 921261dc                 bset    %lo(dword_F0133DDC), %o1
F0010CC4: 80a46013                 cmp     %l1, 0x13
F0010CC8: 12800010                 bne     loc_F0010D08
F0010CCC: 90100011                 mov     %l1, %o0
F0010CD0: d0048000                 ld      [%l2], %o0
F0010CD4: 80a22001                 cmp     %o0, 1
F0010CD8: 1280000c                 bne     loc_F0010D08
F0010CDC: 90100011                 mov     %l1, %o0
F0010CE0: d0027ffc                 ld      [%o1-4], %o0
F0010CE4: d0020000                 ld      [%o0], %o0
F0010CE8: d2022014                 ld      [%o0+0x14], %o1
F0010CEC: 11000010                 sethi   0x4000, %o0
F0010CF0: 808a4008                 btst    %o0, %o1
F0010CF4: 12800005                 bne     loc_F0010D08
F0010CF8: 90100011                 mov     %l1, %o0
F0010CFC: 90102016                 mov     0x16, %o0
F0010D00: 10800004                 ba      locret_F0010D10
F0010D04: d02aa038                 stb     %o0, [%o2+0x38]
F0010D08: 40000004                 call    _setsigvec
F0010D0C: 92100012                 mov     %l2, %o1
F0010D10: 81c7e008                 ret
F0010D14: 81e80000                 restore
