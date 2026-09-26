F001CA08: 9de3bf98                 save    %sp, -0x68, %sp
F001CA0C: 4001e86b                 call    _spltty
F001CA10: 01000000                 nop
F001CA14: d2060000                 ld      [%i0], %o1
F001CA18: 80a26000                 cmp     %o1, 0
F001CA1C: 04800049                 ble     loc_F001CB40
F001CA20: a6100008                 mov     %o0, %l3
F001CA24: 80a66000                 cmp     %i1, 0
F001CA28: 04800040                 ble     loc_F001CB28
F001CA2C: d0060000                 ld      [%i0], %o0
F001CA30: 233c043c                 sethi   -0xFEF1000, %l1
F001CA34: 253c043c                 sethi   -0xFEF1000, %l2
F001CA38: 213c04d4                 sethi   -0xFECB000, %l0
F001CA3C: 80a22000                 cmp     %o0, 0
F001CA40: 0280003b                 be      loc_F001CB2C
F001CA44: 01000000                 nop
F001CA48: d0062004                 ld      [%i0+4], %o0
F001CA4C: d2062008                 ld      [%i0+8], %o1
F001CA50: 960a3fc0                 and     %o0, -0x40, %o3
F001CA54: 90027fff                 add     %o1, -1, %o0
F001CA58: 900a3fc0                 and     %o0, -0x40, %o0
F001CA5C: 80a2c008                 cmp     %o3, %o0
F001CA60: 32800002                 bne,a   loc_F001CA68
F001CA64: 9202e040                 add     %o3, 0x40, %o1 ! '@'
F001CA68: d0062004                 ld      [%i0+4], %o0
F001CA6C: 92224008                 sub     %o1, %o0, %o1
F001CA70: 80a64009                 cmp     %i1, %o1
F001CA74: 16800017                 bge     loc_F001CAD0
F001CA78: d0060000                 ld      [%i0], %o0
F001CA7C: d2062004                 ld      [%i0+4], %o1
F001CA80: 90220019                 sub     %o0, %i1, %o0
F001CA84: d0260000                 st      %o0, [%i0]
F001CA88: 92024019                 add     %o1, %i1, %o1
F001CA8C: d0060000                 ld      [%i0], %o0
F001CA90: 80a22000                 cmp     %o0, 0
F001CA94: 14800024                 bg      loc_F001CB24
F001CA98: d2262004                 st      %o1, [%i0+4]
F001CA9C: d004638c                 ld      [%l1+0x38C], %o0
F001CAA0: d24c22b0                 ldsb    [%l0+0x2B0], %o1
F001CAA4: d022c000                 st      %o0, [%o3]
F001CAA8: d624638c                 st      %o3, [%l1+0x38C]
F001CAAC: d004a390                 ld      [%l2+0x390], %o0
F001CAB0: 80a26000                 cmp     %o1, 0
F001CAB4: 90022034                 inc     0x34, %o0 ! '4'
F001CAB8: 0280001b                 be      loc_F001CB24
F001CABC: d024a390                 st      %o0, [%l2+0x390]
F001CAC0: 7fffd8ca                 call    _wakeup
F001CAC4: 901422b0                 or      %l0, 0x2B0, %o0
F001CAC8: 10800017                 ba      loc_F001CB24
F001CACC: c02c22b0                 clrb    [%l0+0x2B0]
F001CAD0: b2264009                 sub     %i1, %o1, %i1
F001CAD4: d404638c                 ld      [%l1+0x38C], %o2
F001CAD8: 90220009                 sub     %o0, %o1, %o0
F001CADC: d0260000                 st      %o0, [%i0]
F001CAE0: d004a390                 ld      [%l2+0x390], %o0
F001CAE4: d624638c                 st      %o3, [%l1+0x38C]
F001CAE8: d24c22b0                 ldsb    [%l0+0x2B0], %o1
F001CAEC: 90022034                 inc     0x34, %o0 ! '4'
F001CAF0: d024a390                 st      %o0, [%l2+0x390]
F001CAF4: d002c000                 ld      [%o3], %o0
F001CAF8: 80a26000                 cmp     %o1, 0
F001CAFC: 9002200c                 inc     0xC, %o0
F001CB00: d0262004                 st      %o0, [%i0+4]
F001CB04: 02800005                 be      loc_F001CB18
F001CB08: d422c000                 st      %o2, [%o3]
F001CB0C: 7fffd8b7                 call    _wakeup
F001CB10: 901422b0                 or      %l0, 0x2B0, %o0
F001CB14: c02c22b0                 clrb    [%l0+0x2B0]
F001CB18: 80a66000                 cmp     %i1, 0
F001CB1C: 34bfffc8                 bg,a    loc_F001CA3C
F001CB20: d0060000                 ld      [%i0], %o0
F001CB24: d0060000                 ld      [%i0], %o0
F001CB28: 80a22000                 cmp     %o0, 0
F001CB2C: 14800005                 bg      loc_F001CB40
F001CB30: 01000000                 nop
F001CB34: c0262008                 clr     [%i0+8]
F001CB38: c0262004                 clr     [%i0+4]
F001CB3C: c0260000                 clr     [%i0]
F001CB40: 4001e879                 call    _splx
F001CB44: 90100013                 mov     %l3, %o0
F001CB48: 81c7e008                 ret
F001CB4C: 81e80000                 restore
