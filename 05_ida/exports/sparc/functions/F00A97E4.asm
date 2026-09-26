F00A97E4: 9de3bf78                 save    %sp, -0x88, %sp! int
F00A97E8: d0062004                 ld      [%i0+4], %o0
F00A97EC: 7fff8202                 call    _fuword
F00A97F0: b6100019                 mov     %i1, %i3
F00A97F4: a0100008                 mov     %o0, %l0
F00A97F8: 91342013                 srl     %l0, 19, %o0
F00A97FC: 920a2003                 and     %o0, 3, %o1
F00A9800: 80a26001                 cmp     %o1, 1
F00A9804: 91342019                 srl     %l0, 25, %o0
F00A9808: a60a201f                 and     %o0, 0x1F, %l3
F00A980C: 9134200e                 srl     %l0, 14, %o0
F00A9810: a20a201f                 and     %o0, 0x1F, %l1
F00A9814: ae0c201f                 and     %l0, 0x1F, %l7
F00A9818: 91342018                 srl     %l0, 24, %o0
F00A981C: b20a2001                 and     %o0, 1, %i1
F00A9820: 9134200d                 srl     %l0, 13, %o0
F00A9824: 0280000d                 be      loc_F00A9858
F00A9828: ac0a2001                 and     %o0, 1, %l6
F00A982C: 80a26001                 cmp     %o1, 1
F00A9830: 0a800008                 bcs     loc_F00A9850
F00A9834: 80a26002                 cmp     %o1, 2
F00A9838: 0280000d                 be      loc_F00A986C
F00A983C: 80a26003                 cmp     %o1, 3
F00A9840: 2280000c                 be,a    loc_F00A9870
F00A9844: a8102008                 mov     8, %l4
F00A9848: 1080000b                 ba      loc_F00A9874
F00A984C: 113c046e                 sethi   -0xFEE4800, %o0
F00A9850: 10800008                 ba      loc_F00A9870
F00A9854: a8102004                 mov     4, %l4
F00A9858: 113c046f                 sethi   %hi(aAlignmentBotch), %o0! "alignment botch\n"
F00A985C: 7ffdab7f                 call    _printf
F00A9860: 901222f8                 bset    %lo(aAlignmentBotch), %o0! "alignment botch\n"
F00A9864: 108000f6                 ba      locret_F00A9C3C
F00A9868: b0102000                 mov     0, %i0
F00A986C: a8102002                 mov     2, %l4
F00A9870: 113c046e                 sethi   -0xFEE4800, %o0
F00A9874: d0022014                 ld      [%o0+0x14], %o0
F00A9878: 80a22000                 cmp     %o0, 0
F00A987C: 02800028                 be      loc_F00A991C
F00A9880: 113c046f                 sethi   %hi(aUnalignedAcces), %o0! "unaligned access at 0x%x, instruction: "...
F00A9884: 90122310                 bset    %lo(aUnalignedAcces), %o0! "unaligned access at 0x%x, instruction: "...
F00A9888: d2062004                 ld      [%i0+4], %o1
F00A988C: 7ffdab73                 call    _printf
F00A9890: 94100010                 mov     %l0, %o2
F00A9894: 91342015                 srl     %l0, 21, %o0
F00A9898: 808a2001                 btst    1, %o0
F00A989C: 113c046f                 sethi   %hi(aTypeSSS), %o0! "type %s %s %s\n"
F00A98A0: 02800005                 be      loc_F00A98B4
F00A98A4: 94122340                 or      %o0, %lo(aTypeSSS), %o2! "type %s %s %s\n"
F00A98A8: 113c046f                 sethi   %hi(aSt), %o0! "st"
F00A98AC: 10800004                 ba      loc_F00A98BC
F00A98B0: 92122350                 or      %o0, %lo(aSt), %o1! "st"
F00A98B4: 113c046f92122358         set     aLd, %o1! "ld"
F00A98BC: 91342016                 srl     %l0, 22, %o0
F00A98C0: 808a2001                 btst    1, %o0
F00A98C4: 02800004                 be      loc_F00A98D4
F00A98C8: 113c046f                 sethi   %hi(aSigned), %o0! "signed"
F00A98CC: 10800004                 ba      loc_F00A98DC
F00A98D0: 98122360                 or      %o0, %lo(aSigned), %o4! "signed"
F00A98D4: 113c046f98122368         set     aUnsigned, %o4! "unsigned"
F00A98DC: 9010000a                 mov     %o2, %o0! char *
F00A98E0: 97342011                 srl     %l0, 17, %o3
F00A98E4: 153c046f9412a2c0         set     _sizestr, %o2
F00A98EC: 960ae00c                 and     %o3, 0xC, %o3
F00A98F0: d602c00a                 ld      [%o3+%o2], %o3
F00A98F4: 7ffdab59                 call    _printf
F00A98F8: 9410000c                 mov     %o4, %o2
F00A98FC: 113c046f90122378         set     aRdDRs1DRs2DImm, %o0! "rd = %d, rs1 = %d, rs2 = %d, imm13 = 0x"...
F00A9904: 92100013                 mov     %l3, %o1
F00A9908: 94100011                 mov     %l1, %o2
F00A990C: 96100017                 mov     %l7, %o3
F00A9910: 193ffff8                 sethi   -0x2000, %o4
F00A9914: 7ffdab51                 call    _printf
F00A9918: 982c000c                 andn    %l0, %o4, %o4
F00A991C: 9134201e                 srl     %l0, 30, %o0
F00A9920: 80a22003                 cmp     %o0, 3
F00A9924: 328000c6                 bne,a   locret_F00A9C3C
F00A9928: b0102000                 mov     0, %i0
F00A992C: 80a5a000                 cmp     %l6, 0
F00A9930: 12800005                 bne     loc_F00A9944
F00A9934: 91342005                 srl     %l0, 5, %o0
F00A9938: 808a20ff                 btst    0xFF, %o0
F00A993C: 328000c0                 bne,a   locret_F00A9C3C
F00A9940: b0102000                 mov     0, %i0
F00A9944: 7ffff0bd                 call    _flush_user_windows_to_stack
F00A9948: aa06200c                 add     %i0, 0xC, %l5
F00A994C: 90100015                 mov     %l5, %o0
F00A9950: 94100011                 mov     %l1, %o2
F00A9954: f0062044                 ld      [%i0+0x44], %i0
F00A9958: a407bff4                 add     %fp, var_C, %l2
F00A995C: 96100012                 mov     %l2, %o3
F00A9960: 7fffff64                 call    sub_F00A96F0
F00A9964: 92100018                 mov     %i0, %o1
F00A9968: 80a22000                 cmp     %o0, 0
F00A996C: 328000b4                 bne,a   locret_F00A9C3C
F00A9970: b0103fff                 mov     -1, %i0
F00A9974: 80a5a000                 cmp     %l6, 0
F00A9978: 02800005                 be      loc_F00A998C
F00A997C: e207bff4                 ld      [%fp+var_C], %l1
F00A9980: 912c2013                 sll     %l0, 19, %o0
F00A9984: 1080000b                 ba      loc_F00A99B0
F00A9988: 913a2013                 sra     %o0, 19, %o0
F00A998C: 90100015                 mov     %l5, %o0
F00A9990: 92100018                 mov     %i0, %o1
F00A9994: 94100017                 mov     %l7, %o2
F00A9998: 7fffff56                 call    sub_F00A96F0
F00A999C: 96100012                 mov     %l2, %o3
F00A99A0: 80a22000                 cmp     %o0, 0
F00A99A4: 328000a6                 bne,a   locret_F00A9C3C
F00A99A8: b0103fff                 mov     -1, %i0
F00A99AC: d007bff4                 ld      [%fp+var_C], %o0
F00A99B0: a2044008                 add     %l1, %o0, %l1
F00A99B4: 113c046e                 sethi   %hi(_aligndebug), %o0
F00A99B8: d0022014                 ld      [%o0+%lo(_aligndebug)], %o0
F00A99BC: 80a22000                 cmp     %o0, 0
F00A99C0: 02800005                 be      loc_F00A99D4
F00A99C4: 113c046f                 sethi   %hi(aAddr0xX_0), %o0! "addr = 0x%x\n"
F00A99C8: 901223a8                 bset    %lo(aAddr0xX_0), %o0! "addr = 0x%x\n"
F00A99CC: 7ffdab23                 call    _printf
F00A99D0: 92100011                 mov     %l1, %o1
F00A99D4: 80a6a000                 cmp     %i2, 0
F00A99D8: 32800002                 bne,a   loc_F00A99E0
F00A99DC: e2268000                 st      %l1, [%i2]
F00A99E0: 80a6e000                 cmp     %i3, 0
F00A99E4: 02800095                 be      loc_F00A9C38
F00A99E8: 91342015                 srl     %l0, 21, %o0
F00A99EC: 808a2001                 btst    1, %o0
F00A99F0: 02800045                 be      loc_F00A9B04
F00A99F4: 80a66000                 cmp     %i1, 0
F00A99F8: 0280000c                 be      loc_F00A9A28
F00A99FC: 9007bfe8                 add     %fp, var_18, %o0
F00A9A00: 7fffae36                 call    __fp_read_pfreg
F00A9A04: 92100013                 mov     %l3, %o1
F00A9A08: 80a52008                 cmp     %l4, 8
F00A9A0C: 1280001f                 bne     loc_F00A9A88
F00A9A10: 113c046e                 sethi   -0xFEE4800, %o0
F00A9A14: 9007bfec                 add     %fp, var_14, %o0
F00A9A18: 7fffae30                 call    __fp_read_pfreg
F00A9A1C: 9204e001                 add     %l3, 1, %o1
F00A9A20: 1080001a                 ba      loc_F00A9A88
F00A9A24: 113c046e                 sethi   -0xFEE4800, %o0
F00A9A28: 90100015                 mov     %l5, %o0
F00A9A2C: 92100018                 mov     %i0, %o1
F00A9A30: 94100013                 mov     %l3, %o2
F00A9A34: a007bff4                 add     %fp, var_C, %l0
F00A9A38: 7fffff2e                 call    sub_F00A96F0
F00A9A3C: 96100010                 mov     %l0, %o3
F00A9A40: 80a22000                 cmp     %o0, 0
F00A9A44: 3280007e                 bne,a   locret_F00A9C3C
F00A9A48: b0103fff                 mov     -1, %i0
F00A9A4C: d007bff4                 ld      [%fp+var_C], %o0
F00A9A50: 80a52008                 cmp     %l4, 8
F00A9A54: 1280000c                 bne     loc_F00A9A84
F00A9A58: d027bfe8                 st      %o0, [%fp+var_18]
F00A9A5C: 90100015                 mov     %l5, %o0
F00A9A60: 92100018                 mov     %i0, %o1
F00A9A64: 9404e001                 add     %l3, 1, %o2
F00A9A68: 7fffff22                 call    sub_F00A96F0
F00A9A6C: 96100010                 mov     %l0, %o3
F00A9A70: 80a22000                 cmp     %o0, 0
F00A9A74: 12800072                 bne     locret_F00A9C3C
F00A9A78: b0103fff                 mov     -1, %i0
F00A9A7C: d007bff4                 ld      [%fp+var_C], %o0
F00A9A80: d027bfec                 st      %o0, [%fp+var_14]
F00A9A84: 113c046e                 sethi   -0xFEE4800, %o0
F00A9A88: d0022014                 ld      [%o0+0x14], %o0
F00A9A8C: 80a22000                 cmp     %o0, 0
F00A9A90: 0280000f                 be      loc_F00A9ACC
F00A9A94: d20fbfe8                 ldub    [%fp+var_18], %o1
F00A9A98: d40fbfe9                 ldub    [%fp+var_18+1], %o2! int
F00A9A9C: d60fbfea                 ldub    [%fp+var_18+2], %o3! int
F00A9AA0: d80fbfeb                 ldub    [%fp+var_18+3], %o4! int
F00A9AA4: c40fbfed                 ldub    [%fp+var_14+1], %g2
F00A9AA8: da0fbfec                 ldub    [%fp+var_14], %o5! int
F00A9AAC: c423a05c                 st      %g2, [%sp+0x88+var_2C]
F00A9AB0: c40fbfee                 ldub    [%fp+var_14+2], %g2
F00A9AB4: 113c046f                 sethi   %hi(aDataXXXXXXXX), %o0! "data %x %x %x %x %x %x %x %x\n"
F00A9AB8: c423a060                 st      %g2, [%sp+0x88+var_28]
F00A9ABC: c40fbfef                 ldub    [%fp+var_14+3], %g2
F00A9AC0: 901223b8                 bset    %lo(aDataXXXXXXXX), %o0! "data %x %x %x %x %x %x %x %x\n"
F00A9AC4: 7ffdaae5                 call    _printf
F00A9AC8: c423a064                 st      %g2, [%sp+0x88+var_24]
F00A9ACC: 80a52002                 cmp     %l4, 2
F00A9AD0: 12800008                 bne     loc_F00A9AF0
F00A9AD4: 9007bfe8                 add     %fp, var_18, %o0
F00A9AD8: 9007bfea                 add     %fp, var_18+2, %o0! int
F00A9ADC: 92100011                 mov     %l1, %o1! int
F00A9AE0: 7fffb97b                 call    _copyout
F00A9AE4: 94102002                 mov     2, %o2! int
F00A9AE8: 10800050                 ba      loc_F00A9C28
F00A9AEC: 80a23fff                 cmp     %o0, -1
F00A9AF0: 92100011                 mov     %l1, %o1! int
F00A9AF4: 7fffb976                 call    _copyout
F00A9AF8: 94100014                 mov     %l4, %o2! int
F00A9AFC: 1080004b                 ba      loc_F00A9C28
F00A9B00: 80a23fff                 cmp     %o0, -1
F00A9B04: 80a52002                 cmp     %l4, 2
F00A9B08: 12800013                 bne     loc_F00A9B54
F00A9B0C: 90100011                 mov     %l1, %o0! int
F00A9B10: 9207bfea                 add     %fp, var_18+2, %o1! int
F00A9B14: 7fffb951                 call    _copyin
F00A9B18: 94102002                 mov     2, %o2! int
F00A9B1C: 80a23fff                 cmp     %o0, -1
F00A9B20: 02800044                 be      loc_F00A9C30
F00A9B24: 91342016                 srl     %l0, 22, %o0
F00A9B28: 808a2001                 btst    1, %o0
F00A9B2C: 02800008                 be      loc_F00A9B4C
F00A9B30: d017bfea                 lduh    [%fp+var_18+2], %o0
F00A9B34: 9132200f                 srl     %o0, 15, %o0
F00A9B38: 80a22000                 cmp     %o0, 0
F00A9B3C: 02800004                 be      loc_F00A9B4C
F00A9B40: 90103fff                 mov     -1, %o0! int
F00A9B44: 1080000a                 ba      loc_F00A9B6C
F00A9B48: d037bfe8                 sth     %o0, [%fp+var_18]
F00A9B4C: 10800008                 ba      loc_F00A9B6C
F00A9B50: c037bfe8                 clrh    [%fp+var_18]
F00A9B54: 9207bfe8                 add     %fp, var_18, %o1! int
F00A9B58: 7fffb940                 call    _copyin
F00A9B5C: 94100014                 mov     %l4, %o2
F00A9B60: 80a23fff                 cmp     %o0, -1
F00A9B64: 22800036                 be,a    locret_F00A9C3C
F00A9B68: b0103fff                 mov     -1, %i0
F00A9B6C: 113c046e                 sethi   %hi(_aligndebug), %o0
F00A9B70: d0022014                 ld      [%o0+%lo(_aligndebug)], %o0
F00A9B74: 80a22000                 cmp     %o0, 0
F00A9B78: 0280000f                 be      loc_F00A9BB4
F00A9B7C: d20fbfe8                 ldub    [%fp+var_18], %o1
F00A9B80: d40fbfe9                 ldub    [%fp+var_18+1], %o2
F00A9B84: d60fbfea                 ldub    [%fp+var_18+2], %o3
F00A9B88: d80fbfeb                 ldub    [%fp+var_18+3], %o4
F00A9B8C: c40fbfed                 ldub    [%fp+var_14+1], %g2
F00A9B90: da0fbfec                 ldub    [%fp+var_14], %o5
F00A9B94: c423a05c                 st      %g2, [%sp+0x88+var_2C]
F00A9B98: c40fbfee                 ldub    [%fp+var_14+2], %g2
F00A9B9C: 113c046f                 sethi   %hi(aDataXXXXXXXX_0), %o0! "data %x %x %x %x %x %x %x %x\n"
F00A9BA0: c423a060                 st      %g2, [%sp+0x88+var_28]
F00A9BA4: c40fbfef                 ldub    [%fp+var_14+3], %g2
F00A9BA8: 901223d8                 bset    %lo(aDataXXXXXXXX_0), %o0! "data %x %x %x %x %x %x %x %x\n"
F00A9BAC: 7ffdaaab                 call    _printf
F00A9BB0: c423a064                 st      %g2, [%sp+0x88+var_24]
F00A9BB4: 80a66000                 cmp     %i1, 0
F00A9BB8: 0280000c                 be      loc_F00A9BE8
F00A9BBC: 9007bfe8                 add     %fp, var_18, %o0
F00A9BC0: 7fffadcb                 call    __fp_write_pfreg
F00A9BC4: 92100013                 mov     %l3, %o1
F00A9BC8: 80a52008                 cmp     %l4, 8
F00A9BCC: 1280001c                 bne     locret_F00A9C3C
F00A9BD0: b0102001                 mov     1, %i0
F00A9BD4: 9007bfec                 add     %fp, var_14, %o0
F00A9BD8: 7fffadc5                 call    __fp_write_pfreg
F00A9BDC: 9204e001                 add     %l3, 1, %o1
F00A9BE0: 10800017                 ba      locret_F00A9C3C
F00A9BE4: b0102001                 mov     1, %i0
F00A9BE8: d007bfe8                 ld      [%fp+var_18], %o0
F00A9BEC: 92100015                 mov     %l5, %o1
F00A9BF0: 94100018                 mov     %i0, %o2
F00A9BF4: 7ffffeda                 call    sub_F00A975C
F00A9BF8: 96100013                 mov     %l3, %o3
F00A9BFC: 80a23fff                 cmp     %o0, -1
F00A9C00: 0280000c                 be      loc_F00A9C30
F00A9C04: 80a52008                 cmp     %l4, 8
F00A9C08: 3280000d                 bne,a   locret_F00A9C3C
F00A9C0C: b0102001                 mov     1, %i0
F00A9C10: d007bfec                 ld      [%fp+var_14], %o0
F00A9C14: 92100015                 mov     %l5, %o1
F00A9C18: 94100018                 mov     %i0, %o2
F00A9C1C: 7ffffed0                 call    sub_F00A975C
F00A9C20: 9604e001                 add     %l3, 1, %o3
F00A9C24: 80a23fff                 cmp     %o0, -1
F00A9C28: 12800005                 bne     locret_F00A9C3C
F00A9C2C: b0102001                 mov     1, %i0
F00A9C30: 10800003                 ba      locret_F00A9C3C
F00A9C34: b0103fff                 mov     -1, %i0
F00A9C38: b0102001                 mov     1, %i0
F00A9C3C: 81c7e008                 ret
F00A9C40: 81e80000                 restore
