F0077B04: 9de3bf98                 save    %sp, -0x68, %sp
F0077B08: f8066004                 ld      [%i1+4], %i4
F0077B0C: c4062010                 ld      [%i0+0x10], %g2
F0077B10: f6062018                 ld      [%i0+0x18], %i3
F0077B14: 85370002                 srl     %i4, %g2, %g2
F0077B18: 80a0801b                 cmp     %g2, %i3
F0077B1C: 04800003                 ble     loc_F0077B28
F0077B20: b4100002                 mov     %g2, %i2
F0077B24: b410001b                 mov     %i3, %i2
F0077B28: c4062014                 ld      [%i0+0x14], %g2
F0077B2C: 872ea004                 sll     %i2, 4, %g3
F0077B30: 84008003                 add     %g2, %g3, %g2
F0077B34: c600bff0                 ld      [%g2-0x10], %g3
F0077B38: 80a64003                 cmp     %i1, %g3
F0077B3C: 1280001f                 bne     locret_F0077BB8
F0077B40: ba00bff0                 add     %g2, -0x10, %i5
F0077B44: 80a6801b                 cmp     %i2, %i3
F0077B48: 1680000f                 bge     loc_F0077B84
F0077B4C: f2064000                 ld      [%i1], %i1
F0077B50: 80a66000                 cmp     %i1, 0
F0077B54: 02800018                 be      loc_F0077BB4
F0077B58: 8610001c                 mov     %i4, %g3
F0077B5C: c4066004                 ld      [%i1+4], %g2
F0077B60: 80a08003                 cmp     %g2, %g3
F0077B64: 22800015                 be,a    locret_F0077BB8
F0077B68: f2274000                 st      %i1, [%i5]
F0077B6C: f2064000                 ld      [%i1], %i1
F0077B70: 80a66000                 cmp     %i1, 0
F0077B74: 32bffffb                 bne,a   loc_F0077B60
F0077B78: c4066004                 ld      [%i1+4], %g2
F0077B7C: 1080000f                 ba      locret_F0077BB8
F0077B80: f2274000                 st      %i1, [%i5]
F0077B84: 80a66000                 cmp     %i1, 0
F0077B88: 2280000c                 be,a    locret_F0077BB8
F0077B8C: f2274000                 st      %i1, [%i5]
F0077B90: f0062004                 ld      [%i0+4], %i0
F0077B94: c4066004                 ld      [%i1+4], %g2
F0077B98: 80a08018                 cmp     %g2, %i0
F0077B9C: 3a800007                 bcc,a   locret_F0077BB8
F0077BA0: f2274000                 st      %i1, [%i5]
F0077BA4: f2064000                 ld      [%i1], %i1
F0077BA8: 80a66000                 cmp     %i1, 0
F0077BAC: 32bffffb                 bne,a   loc_F0077B98
F0077BB0: c4066004                 ld      [%i1+4], %g2
F0077BB4: f2274000                 st      %i1, [%i5]
F0077BB8: 81c7e008                 ret
F0077BBC: 81e80000                 restore
