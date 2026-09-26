F00C8724: 9de3bf90                 save    %sp, -0x70, %sp
F00C8728: 113c04cc                 sethi   %hi(dword_F01330B0), %o0
F00C872C: d00220b0                 ld      [%o0+%lo(dword_F01330B0)], %o0! id
F00C8730: 133c0504                 sethi   %hi(paLock), %o1
F00C8734: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00C8738: 4000a44e                 call    _objc_msgSend
F00C873C: a2102000                 mov     0, %l1
F00C8740: 133c04cc                 sethi   %hi(dword_F01330A8), %o1
F00C8744: d00260a8                 ld      [%o1+%lo(dword_F01330A8)], %o0
F00C8748: 941260a8                 or      %o1, %lo(dword_F01330A8), %o2
F00C874C: 80a2000a                 cmp     %o0, %o2
F00C8750: 028000ce                 be      loc_F00C8A88
F00C8754: 113c0322                 sethi   %hi(jpt_F00C8850), %o0
F00C8758: b2100009                 mov     %o1, %i1
F00C875C: aa10000a                 mov     %o2, %l5
F00C8760: 2d3c04cca815a0a0         set     dword_F01330A0, %l4
F00C8768: b0122058                 or      %o0, %lo(jpt_F00C8850), %i0
F00C876C: 2f3c0506                 sethi   -0xFEBE800, %l7
F00C8770: e60660a8                 ld      [%i1+0xA8], %l3
F00C8774: d404e010                 ld      [%l3+0x10], %o2
F00C8778: 80a28015                 cmp     %o2, %l5
F00C877C: 02800004                 be      loc_F00C878C
F00C8780: d204e014                 ld      [%l3+0x14], %o1
F00C8784: 10800003                 ba      loc_F00C8790
F00C8788: 9002a010                 add     %o2, 0x10, %o0
F00C878C: 90100015                 mov     %l5, %o0
F00C8790: 80a24015                 cmp     %o1, %l5
F00C8794: 02800004                 be      loc_F00C87A4
F00C8798: d2222004                 st      %o1, [%o0+4]
F00C879C: 10800003                 ba      loc_F00C87A8
F00C87A0: 90026010                 add     %o1, 0x10, %o0
F00C87A4: 90100015                 mov     %l5, %o0
F00C87A8: d4220000                 st      %o2, [%o0]
F00C87AC: 113c04cc                 sethi   %hi(dword_F01330B0), %o0
F00C87B0: d00220b0                 ld      [%o0+%lo(dword_F01330B0)], %o0! id
F00C87B4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C87B8: 4000a42e                 call    _objc_msgSend
F00C87BC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C87C0: d004c000                 ld      [%l3], %o0
F00C87C4: 80a22000                 cmp     %o0, 0
F00C87C8: 0280001e                 be      loc_F00C8840
F00C87CC: e404e004                 ld      [%l3+4], %l2
F00C87D0: d605a0a0                 ld      [%l6+0xA0], %o3
F00C87D4: 80a2c014                 cmp     %o3, %l4
F00C87D8: 0280000b                 be      loc_F00C8804
F00C87DC: 113c04cc                 sethi   %hi(dword_F01330A0), %o0
F00C87E0: 921220a0                 or      %o0, %lo(dword_F01330A0), %o1
F00C87E4: d002c000                 ld      [%o3], %o0
F00C87E8: 80a20012                 cmp     %o0, %l2
F00C87EC: 22800007                 be,a    loc_F00C8808
F00C87F0: a210000b                 mov     %o3, %l1
F00C87F4: d602e018                 ld      [%o3+0x18], %o3
F00C87F8: 80a2c009                 cmp     %o3, %o1
F00C87FC: 32bffffb                 bne,a   loc_F00C87E8
F00C8800: d002c000                 ld      [%o3], %o0
F00C8804: a2102000                 mov     0, %l1
F00C8808: 80a46000                 cmp     %l1, 0
F00C880C: 3280000d                 bne,a   loc_F00C8840
F00C8810: d004c000                 ld      [%l3], %o0
F00C8814: 113c0504                 sethi   %hi(paName), %o0! id
F00C8818: d2022008                 ld      [%o0+%lo(paName)], %o1! SEL
F00C881C: 4000a415                 call    _objc_msgSend
F00C8820: 90100012                 mov     %l2, %o0
F00C8824: 153c03eb                 sethi   %hi(aVolcheckDiskSN), %o2! "volCheck: disk %s not registered, cmd ="...
F00C8828: 92100008                 mov     %o0, %o1
F00C882C: 9012a378                 or      %o2, %lo(aVolcheckDiskSN), %o0! "volCheck: disk %s not registered, cmd ="...
F00C8830: 7ffff631                 call    _IOLog
F00C8834: d404c000                 ld      [%l3], %o2
F00C8838: 10800088                 ba      loc_F00C8A58
F00C883C: 90100013                 mov     %l3, %o0
F00C8840: 80a22005                 cmp     %o0, 5! switch 6 cases
F00C8844: 18800084                 bgu     def_F00C8850! jumptable F00C8850 default case
F00C8848: 912a2002                 sll     %o0, 2, %o0
F00C884C: d0020018                 ld      [%o0+%i0], %o0
F00C8850: 81c20000                 jmp     %o0! switch jump
F00C8854: 01000000                 nop
F00C8870: 113c0506                 sethi   %hi(paUpdatereadysta), %o0! jumptable F00C8850 case 0
F00C8874: d20221c8                 ld      [%o0+%lo(paUpdatereadysta)], %o1! SEL
F00C8878: 4000a3fe                 call    _objc_msgSend
F00C887C: 90100012                 mov     %l2, %o0
F00C8880: a0100008                 mov     %o0, %l0
F00C8884: 90100012                 mov     %l2, %o0! id
F00C8888: d205e178                 ld      [%l7+0x178], %o1! SEL
F00C888C: 4000a3f9                 call    _objc_msgSend
F00C8890: 94100010                 mov     %l0, %o2
F00C8894: 80a42000                 cmp     %l0, 0
F00C8898: 1280000e                 bne     loc_F00C88D0
F00C889C: 01000000                 nop
F00C88A0: d254e00c                 ldsh    [%l3+0xC], %o1
F00C88A4: d454e00e                 ldsh    [%l3+0xE], %o2
F00C88A8: 4000007f                 call    sub_F00C8AA4
F00C88AC: 90100012                 mov     %l2, %o0
F00C88B0: 113c0504                 sethi   %hi(paIsremovable), %o0! id
F00C88B4: d20221a8                 ld      [%o0+%lo(paIsremovable)], %o1! SEL
F00C88B8: 4000a3ee                 call    _objc_msgSend
F00C88BC: 90100012                 mov     %l2, %o0
F00C88C0: 912a2018                 sll     %o0, 24, %o0
F00C88C4: 80a22000                 cmp     %o0, 0
F00C88C8: 02800064                 be      loc_F00C8A58
F00C88CC: 90100013                 mov     %l3, %o0
F00C88D0: 7ffff598                 call    _IOMalloc
F00C88D4: 90102020                 mov     0x20, %o0 ! ' '
F00C88D8: a2100008                 mov     %o0, %l1
F00C88DC: e4244000                 st      %l2, [%l1]
F00C88E0: d014e00c                 lduh    [%l3+0xC], %o0
F00C88E4: d0346004                 sth     %o0, [%l1+4]
F00C88E8: d014e00e                 lduh    [%l3+0xE], %o0
F00C88EC: d0346006                 sth     %o0, [%l1+6]
F00C88F0: c0246008                 clr     [%l1+8]
F00C88F4: c02c600c                 clrb    [%l1+0xC]
F00C88F8: c02c600d                 clrb    [%l1+0xD]
F00C88FC: d004e008                 ld      [%l3+8], %o0
F00C8900: d0246014                 st      %o0, [%l1+0x14]
F00C8904: d005a0a0                 ld      [%l6+0xA0], %o0
F00C8908: 80a20014                 cmp     %o0, %l4
F00C890C: 22800046                 be,a    loc_F00C8A24
F00C8910: e225a0a0                 st      %l1, [%l6+0xA0]
F00C8914: d0052004                 ld      [%l4+4], %o0
F00C8918: d024601c                 st      %o0, [%l1+0x1C]
F00C891C: e8246018                 st      %l4, [%l1+0x18]
F00C8920: e2252004                 st      %l1, [%l4+4]
F00C8924: 1080004c                 ba      def_F00C8850! jumptable F00C8850 default case
F00C8928: e2222018                 st      %l1, [%o0+0x18]
F00C892C: d4046018                 ld      [%l1+0x18], %o2! jumptable F00C8850 case 1
F00C8930: 80a28014                 cmp     %o2, %l4
F00C8934: 02800004                 be      loc_F00C8944
F00C8938: d204601c                 ld      [%l1+0x1C], %o1
F00C893C: 10800003                 ba      loc_F00C8948
F00C8940: 9002a018                 add     %o2, 0x18, %o0
F00C8944: 9010000a                 mov     %o2, %o0
F00C8948: 80a24014                 cmp     %o1, %l4
F00C894C: 02800004                 be      loc_F00C895C
F00C8950: d2222004                 st      %o1, [%o0+4]
F00C8954: 10800003                 ba      loc_F00C8960
F00C8958: 90026018                 add     %o1, 0x18, %o0
F00C895C: 90100009                 mov     %o1, %o0
F00C8960: d4220000                 st      %o2, [%o0]
F00C8964: 90100011                 mov     %l1, %o0
F00C8968: 7ffff577                 call    _IOFree
F00C896C: 92102020                 mov     0x20, %o1 ! ' '
F00C8970: 1080003a                 ba      loc_F00C8A58
F00C8974: 90100013                 mov     %l3, %o0
F00C8978: 113c0506                 sethi   %hi(paUnit_0), %o0! jumptable F00C8850 case 2
F00C897C: d2022138                 ld      [%o0+%lo(paUnit_0)], %o1! SEL
F00C8980: 4000a3bc                 call    _objc_msgSend
F00C8984: 90100012                 mov     %l2, %o0
F00C8988: d24c600d                 ldsb    [%l1+0xD], %o1
F00C898C: 80a26000                 cmp     %o1, 0
F00C8990: 12800031                 bne     def_F00C8850! jumptable F00C8850 default case
F00C8994: a0100008                 mov     %o0, %l0
F00C8998: 113c0506                 sethi   %hi(paLastreadystate_0), %o0! id
F00C899C: d202217c                 ld      [%o0+%lo(paLastreadystate_0)], %o1! SEL
F00C89A0: 4000a3b4                 call    _objc_msgSend
F00C89A4: 90100012                 mov     %l2, %o0
F00C89A8: 80a22000                 cmp     %o0, 0
F00C89AC: 0280002a                 be      def_F00C8850! jumptable F00C8850 default case
F00C89B0: 113c0322                 sethi   %hi(sub_F00C8BC4), %o0
F00C89B4: 901223c4                 bset    %lo(sub_F00C8BC4), %o0
F00C89B8: 92102000                 mov     0, %o1
F00C89BC: d404e008                 ld      [%l3+8], %o2
F00C89C0: 96046010                 add     %l1, 0x10, %o3
F00C89C4: 98100012                 mov     %l2, %o4
F00C89C8: 9a102000                 mov     0, %o5
F00C89CC: d623a05c                 st      %o3, [%sp+0x70+var_14]
F00C89D0: 7fff2d40                 call    _vol_panel_disk_num
F00C89D4: 96100010                 mov     %l0, %o3
F00C89D8: 90102001                 mov     1, %o0
F00C89DC: 1080001e                 ba      def_F00C8850! jumptable F00C8850 default case
F00C89E0: d02c600d                 stb     %o0, [%l1+0xD]
F00C89E4: 90100012                 mov     %l2, %o0! jumptable F00C8850 case 3
F00C89E8: d205e178                 ld      [%l7+0x178], %o1! SEL
F00C89EC: 4000a3a1                 call    _objc_msgSend
F00C89F0: 94102003                 mov     3, %o2
F00C89F4: 90102005                 mov     5, %o0
F00C89F8: d0246008                 st      %o0, [%l1+8]
F00C89FC: c02c600c                 clrb    [%l1+0xC]
F00C8A00: d004e008                 ld      [%l3+8], %o0
F00C8A04: 10800014                 ba      def_F00C8850! jumptable F00C8850 default case
F00C8A08: d0246014                 st      %o0, [%l1+0x14]
F00C8A0C: 90100012                 mov     %l2, %o0! jumptable F00C8850 case 4
F00C8A10: d205e178                 ld      [%l7+0x178], %o1! SEL
F00C8A14: 4000a397                 call    _objc_msgSend
F00C8A18: 94102001                 mov     1, %o2
F00C8A1C: 1080000f                 ba      loc_F00C8A58
F00C8A20: 90100013                 mov     %l3, %o0
F00C8A24: e2222004                 st      %l1, [%o0+4]
F00C8A28: d0246018                 st      %o0, [%l1+0x18]
F00C8A2C: 1080000a                 ba      def_F00C8850! jumptable F00C8850 default case
F00C8A30: d024601c                 st      %o0, [%l1+0x1C]
F00C8A34: d04c600d                 ldsb    [%l1+0xD], %o0! jumptable F00C8850 case 5
F00C8A38: 80a22000                 cmp     %o0, 0
F00C8A3C: 02800006                 be      def_F00C8850! jumptable F00C8850 default case
F00C8A40: 113c0506                 sethi   %hi(paAbortrequest), %o0! id
F00C8A44: d2022120                 ld      [%o0+%lo(paAbortrequest)], %o1! SEL
F00C8A48: c02c600d                 clrb    [%l1+0xD]
F00C8A4C: 4000a389                 call    _objc_msgSend
F00C8A50: 90100012                 mov     %l2, %o0
F00C8A54: 90100013                 mov     %l3, %o0! jumptable F00C8850 default case
F00C8A58: 7ffff53b                 call    _IOFree
F00C8A5C: 92102018                 mov     0x18, %o1
F00C8A60: 113c04cc                 sethi   %hi(dword_F01330B0), %o0
F00C8A64: d00220b0                 ld      [%o0+%lo(dword_F01330B0)], %o0! id
F00C8A68: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C8A6C: 4000a381                 call    _objc_msgSend
F00C8A70: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C8A74: 133c04cc                 sethi   %hi(dword_F01330A8), %o1
F00C8A78: d00260a8                 ld      [%o1+%lo(dword_F01330A8)], %o0
F00C8A7C: 80a20015                 cmp     %o0, %l5
F00C8A80: 12bfff3d                 bne     loc_F00C8774
F00C8A84: e60660a8                 ld      [%i1+0xA8], %l3
F00C8A88: 113c04cc                 sethi   %hi(dword_F01330B0), %o0
F00C8A8C: d00220b0                 ld      [%o0+%lo(dword_F01330B0)], %o0! id
F00C8A90: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C8A94: 4000a377                 call    _objc_msgSend
F00C8A98: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C8A9C: 81c7e008                 ret
F00C8AA0: 81e80000                 restore
