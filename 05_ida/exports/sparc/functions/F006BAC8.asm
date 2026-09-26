F006BAC8: 9de3bf98                 save    %sp, -0x68, %sp
F006BACC: b80f200f                 and     %i4, 0xF, %i4
F006BAD0: b92f2003                 sll     %i4, 3, %i4
F006BAD4: 053c04f08410a120         set     _listeners, %g2
F006BADC: b8070002                 add     %i4, %g2, %i4
F006BAE0: fa072004                 ld      [%i4+4], %i5
F006BAE4: 80a76000                 cmp     %i5, 0
F006BAE8: 0280002d                 be      loc_F006BB9C
F006BAEC: 8210001d                 mov     %i5, %g1
F006BAF0: 852ee010                 sll     %i3, 16, %g2
F006BAF4: b730a010                 srl     %g2, 16, %i3
F006BAF8: 852e6010                 sll     %i1, 16, %g2
F006BAFC: 8530a010                 srl     %g2, 16, %g2
F006BB00: c617600e                 lduh    [%i5+0xE], %g3
F006BB04: 80a0e000                 cmp     %g3, 0
F006BB08: 02800004                 be      loc_F006BB18
F006BB0C: 80a0c01b                 cmp     %g3, %i3
F006BB10: 3280001f                 bne,a   loc_F006BB8C
F006BB14: 8210001d                 mov     %i5, %g1
F006BB18: c617600c                 lduh    [%i5+0xC], %g3
F006BB1C: 80a0e000                 cmp     %g3, 0
F006BB20: 02800004                 be      loc_F006BB30
F006BB24: 80a0c002                 cmp     %g3, %g2
F006BB28: 32800019                 bne,a   loc_F006BB8C
F006BB2C: 8210001d                 mov     %i5, %g1
F006BB30: c6076004                 ld      [%i5+4], %g3
F006BB34: 80a0e000                 cmp     %g3, 0
F006BB38: 02800004                 be      loc_F006BB48
F006BB3C: 80a0c018                 cmp     %g3, %i0
F006BB40: 32800013                 bne,a   loc_F006BB8C
F006BB44: 8210001d                 mov     %i5, %g1
F006BB48: c6076008                 ld      [%i5+8], %g3
F006BB4C: 80a0e000                 cmp     %g3, 0
F006BB50: 02800004                 be      loc_F006BB60
F006BB54: 80a0c01a                 cmp     %g3, %i2
F006BB58: 3280000d                 bne,a   loc_F006BB8C
F006BB5C: 8210001d                 mov     %i5, %g1
F006BB60: c4072004                 ld      [%i4+4], %g2
F006BB64: 80a74002                 cmp     %i5, %g2
F006BB68: 2280000e                 be,a    locret_F006BBA0
F006BB6C: f0076010                 ld      [%i5+0x10], %i0
F006BB70: c4074000                 ld      [%i5], %g2
F006BB74: c4204000                 st      %g2, [%g1]
F006BB78: c4072004                 ld      [%i4+4], %g2
F006BB7C: c4274000                 st      %g2, [%i5]
F006BB80: fa272004                 st      %i5, [%i4+4]
F006BB84: 10800007                 ba      locret_F006BBA0
F006BB88: f0076010                 ld      [%i5+0x10], %i0
F006BB8C: fa074000                 ld      [%i5], %i5
F006BB90: 80a76000                 cmp     %i5, 0
F006BB94: 32bfffdc                 bne,a   loc_F006BB04
F006BB98: c617600e                 lduh    [%i5+0xE], %g3
F006BB9C: b0102000                 mov     0, %i0
F006BBA0: 81c7e008                 ret
F006BBA4: 81e80000                 restore
