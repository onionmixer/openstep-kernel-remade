F009CDF4: 9de3bf98                 save    %sp, -0x68, %sp
F009CDF8: 113c04f7                 sethi   %hi(_pmap_info), %o0! int
F009CDFC: d2122270                 lduh    [%o0+%lo(_pmap_info)], %o1! int
F009CE00: f0060000                 ld      [%i0], %i0
F009CE04: 7ffda601                 call    _div
F009CE08: 90102040                 mov     0x40, %o0 ! '@'
F009CE0C: d20e200f                 ldub    [%i0+0xF], %o1
F009CE10: 80a24008                 cmp     %o1, %o0
F009CE14: 32800042                 bne,a   locret_F009CF1C
F009CE18: b0102000                 mov     0, %i0
F009CE1C: d0062010                 ld      [%i0+0x10], %o0
F009CE20: 133c04f8                 sethi   %hi(_wmap0), %o1
F009CE24: d2026030                 ld      [%o1+%lo(_wmap0)], %o1
F009CE28: 80a20009                 cmp     %o0, %o1
F009CE2C: 3280003c                 bne,a   locret_F009CF1C
F009CE30: b0102000                 mov     0, %i0
F009CE34: d0062014                 ld      [%i0+0x14], %o0
F009CE38: 133c04f8                 sethi   %hi(_wmap1), %o1
F009CE3C: d2026038                 ld      [%o1+%lo(_wmap1)], %o1
F009CE40: 80a20009                 cmp     %o0, %o1
F009CE44: 32800036                 bne,a   locret_F009CF1C
F009CE48: b0102000                 mov     0, %i0
F009CE4C: d0062018                 ld      [%i0+0x18], %o0
F009CE50: 80a22000                 cmp     %o0, 0
F009CE54: 32800032                 bne,a   locret_F009CF1C
F009CE58: b0102000                 mov     0, %i0
F009CE5C: d006201c                 ld      [%i0+0x1C], %o0
F009CE60: 80a22000                 cmp     %o0, 0
F009CE64: 3280002e                 bne,a   locret_F009CF1C
F009CE68: b0102000                 mov     0, %i0
F009CE6C: f0060000                 ld      [%i0], %i0
F009CE70: d0060000                 ld      [%i0], %o0
F009CE74: 95322008                 srl     %o0, 8, %o2
F009CE78: 808aa03f                 btst    0x3F, %o2 ! '?'
F009CE7C: 32800028                 bne,a   locret_F009CF1C
F009CE80: b0102000                 mov     0, %i0
F009CE84: c0264000                 clr     [%i1]
F009CE88: c0268000                 clr     [%i2]
F009CE8C: 96102000                 mov     0, %o3
F009CE90: d0060000                 ld      [%i0], %o0
F009CE94: 84102001                 mov     1, %g2
F009CE98: 9b322007                 srl     %o0, 7, %o5
F009CE9C: 9a0b6001                 and     %o5, 1, %o5
F009CEA0: 99322002                 srl     %o0, 2, %o4
F009CEA4: 980b2007                 and     %o4, 7, %o4
F009CEA8: d2060000                 ld      [%i0], %o1
F009CEAC: 91326008                 srl     %o1, 8, %o0
F009CEB0: 80a2000a                 cmp     %o0, %o2
F009CEB4: 3280001a                 bne,a   locret_F009CF1C
F009CEB8: b0102000                 mov     0, %i0
F009CEBC: 91326007                 srl     %o1, 7, %o0
F009CEC0: 900a2001                 and     %o0, 1, %o0
F009CEC4: 80a2000d                 cmp     %o0, %o5
F009CEC8: 32800015                 bne,a   locret_F009CF1C
F009CECC: b0102000                 mov     0, %i0
F009CED0: 91326002                 srl     %o1, 2, %o0
F009CED4: 900a2007                 and     %o0, 7, %o0
F009CED8: 80a2000c                 cmp     %o0, %o4
F009CEDC: 02800004                 be      loc_F009CEEC
F009CEE0: 808a6040                 btst    0x40, %o1 ! '@'
F009CEE4: 1080000e                 ba      locret_F009CF1C
F009CEE8: b0102000                 mov     0, %i0
F009CEEC: 32800002                 bne,a   loc_F009CEF4
F009CEF0: c4264000                 st      %g2, [%i1]
F009CEF4: d0060000                 ld      [%i0], %o0
F009CEF8: 808a2020                 btst    0x20, %o0 ! ' '
F009CEFC: 32800002                 bne,a   loc_F009CF04
F009CF00: c4268000                 st      %g2, [%i2]
F009CF04: b0062004                 inc     4, %i0
F009CF08: 9602e001                 inc     %o3
F009CF0C: 80a2e03f                 cmp     %o3, 0x3F ! '?'
F009CF10: 04bfffe6                 ble     loc_F009CEA8
F009CF14: 9402a001                 inc     %o2
F009CF18: b0102001                 mov     1, %i0
F009CF1C: 81c7e008                 ret
F009CF20: 81e80000                 restore
