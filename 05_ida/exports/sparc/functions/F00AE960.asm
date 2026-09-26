F00AE960: 9de3bf98                 save    %sp, -0x68, %sp
F00AE964: ba100019                 mov     %i1, %i5
F00AE968: 80a76071                 cmp     %i5, 0x71 ! 'q'
F00AE96C: 04800014                 ble     loc_F00AE9BC
F00AE970: b8100018                 mov     %i0, %i4
F00AE974: c407200c                 ld      [%i4+0xC], %g2
F00AE978: c6072010                 ld      [%i4+0x10], %g3
F00AE97C: f0072014                 ld      [%i4+0x14], %i0
F00AE980: 84108003                 bset    %g3, %g2
F00AE984: c6072018                 ld      [%i4+0x18], %g3
F00AE988: 84108018                 bset    %i0, %g2
F00AE98C: 80908003                 orcc    %g2, %g3, %g0
F00AE990: 32800004                 bne,a   loc_F00AE9A0
F00AE994: c027201c                 clr     [%i4+0x1C]
F00AE998: 10800049                 ba      locret_F00AEABC
F00AE99C: c0272004                 clr     [%i4+4]
F00AE9A0: 84102001                 mov     1, %g2
F00AE9A4: c4272020                 st      %g2, [%i4+0x20]
F00AE9A8: c0272018                 clr     [%i4+0x18]
F00AE9AC: c0272014                 clr     [%i4+0x14]
F00AE9B0: c0272010                 clr     [%i4+0x10]
F00AE9B4: 10800042                 ba      locret_F00AEABC
F00AE9B8: c027200c                 clr     [%i4+0xC]
F00AE9BC: 80a7601f                 cmp     %i5, 0x1F
F00AE9C0: 04800017                 ble     loc_F00AEA1C
F00AE9C4: 051fffff                 sethi   0x7FFFFC00, %g2
F00AE9C8: b210a3ff                 or      %g2, 0x3FF, %i1
F00AE9CC: f0072018                 ld      [%i4+0x18], %i0
F00AE9D0: c407201c                 ld      [%i4+0x1C], %g2
F00AE9D4: ba077fe0                 inc     -0x20, %i5
F00AE9D8: c6072020                 ld      [%i4+0x20], %g3
F00AE9DC: b00e0019                 and     %i0, %i1, %i0
F00AE9E0: 84108018                 bset    %i0, %g2
F00AE9E4: 8610c002                 bset    %g2, %g3
F00AE9E8: c4072018                 ld      [%i4+0x18], %g2
F00AE9EC: c6272020                 st      %g3, [%i4+0x20]
F00AE9F0: c6072014                 ld      [%i4+0x14], %g3
F00AE9F4: 80a7601f                 cmp     %i5, 0x1F
F00AE9F8: f0072010                 ld      [%i4+0x10], %i0
F00AE9FC: 8530a01f                 srl     %g2, 31, %g2
F00AEA00: c427201c                 st      %g2, [%i4+0x1C]
F00AEA04: c6272018                 st      %g3, [%i4+0x18]
F00AEA08: c407200c                 ld      [%i4+0xC], %g2
F00AEA0C: f0272014                 st      %i0, [%i4+0x14]
F00AEA10: c4272010                 st      %g2, [%i4+0x10]
F00AEA14: 14bfffee                 bg      loc_F00AE9CC
F00AEA18: c027200c                 clr     [%i4+0xC]
F00AEA1C: 80a76000                 cmp     %i5, 0
F00AEA20: 04800027                 ble     locret_F00AEABC
F00AEA24: b2102001                 mov     1, %i1
F00AEA28: b4077fff                 add     %i5, -1, %i2
F00AEA2C: 872e401a                 sll     %i1, %i2, %g3
F00AEA30: 8600ffff                 inc     -1, %g3
F00AEA34: f6072018                 ld      [%i4+0x18], %i3
F00AEA38: b32e401d                 sll     %i1, %i5, %i1
F00AEA3C: f007201c                 ld      [%i4+0x1C], %i0
F00AEA40: b2067fff                 inc     -1, %i1
F00AEA44: c4072020                 ld      [%i4+0x20], %g2
F00AEA48: 860ec003                 and     %i3, %g3, %g3
F00AEA4C: b0160003                 bset    %g3, %i0
F00AEA50: 84108018                 bset    %i0, %g2
F00AEA54: c4272020                 st      %g2, [%i4+0x20]
F00AEA58: 840ec019                 and     %i3, %i1, %g2
F00AEA5C: 8530801a                 srl     %g2, %i2, %g2
F00AEA60: c427201c                 st      %g2, [%i4+0x1C]
F00AEA64: b4102020                 mov     0x20, %i2 ! ' '
F00AEA68: b426801d                 sub     %i2, %i5, %i2
F00AEA6C: c6072014                 ld      [%i4+0x14], %g3
F00AEA70: b736c01d                 srl     %i3, %i5, %i3
F00AEA74: f0072010                 ld      [%i4+0x10], %i0
F00AEA78: 8408c019                 and     %g3, %i1, %g2
F00AEA7C: 8528801a                 sll     %g2, %i2, %g2
F00AEA80: 8410801b                 bset    %i3, %g2
F00AEA84: c4272018                 st      %g2, [%i4+0x18]
F00AEA88: 840e0019                 and     %i0, %i1, %g2
F00AEA8C: 8528801a                 sll     %g2, %i2, %g2
F00AEA90: 8730c01d                 srl     %g3, %i5, %g3
F00AEA94: 84108003                 bset    %g3, %g2
F00AEA98: c4272014                 st      %g2, [%i4+0x14]
F00AEA9C: c607200c                 ld      [%i4+0xC], %g3
F00AEAA0: b136001d                 srl     %i0, %i5, %i0
F00AEAA4: b208c019                 and     %g3, %i1, %i1
F00AEAA8: b32e401a                 sll     %i1, %i2, %i1
F00AEAAC: b2164018                 bset    %i0, %i1
F00AEAB0: f2272010                 st      %i1, [%i4+0x10]
F00AEAB4: 8730c01d                 srl     %g3, %i5, %g3
F00AEAB8: c627200c                 st      %g3, [%i4+0xC]
F00AEABC: 81c7e008                 ret
F00AEAC0: 81e80000                 restore
