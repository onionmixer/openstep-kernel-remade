F0077CDC: 9de3bf98                 save    %sp, -0x68, %sp
F0077CE0: c4066004                 ld      [%i1+4], %g2
F0077CE4: c6062010                 ld      [%i0+0x10], %g3
F0077CE8: f8062018                 ld      [%i0+0x18], %i4
F0077CEC: 85308003                 srl     %g2, %g3, %g2
F0077CF0: 80a0801c                 cmp     %g2, %i4
F0077CF4: 04800003                 ble     loc_F0077D00
F0077CF8: ba100002                 mov     %g2, %i5
F0077CFC: ba10001c                 mov     %i4, %i5
F0077D00: 85368003                 srl     %i2, %g3, %g2
F0077D04: 80a0801c                 cmp     %g2, %i4
F0077D08: 04800003                 ble     loc_F0077D14
F0077D0C: b6100002                 mov     %g2, %i3
F0077D10: b610001c                 mov     %i4, %i3
F0077D14: 80a6c01d                 cmp     %i3, %i5
F0077D18: 0280002f                 be      locret_F0077DD4
F0077D1C: 872ee004                 sll     %i3, 4, %g3
F0077D20: c4062014                 ld      [%i0+0x14], %g2
F0077D24: 84008003                 add     %g2, %g3, %g2
F0077D28: c600bff0                 ld      [%g2-0x10], %g3
F0077D2C: 80a64003                 cmp     %i1, %g3
F0077D30: 1280001f                 bne     loc_F0077DAC
F0077D34: 8200bff0                 add     %g2, -0x10, %g1
F0077D38: 80a6c01c                 cmp     %i3, %i4
F0077D3C: 1680000f                 bge     loc_F0077D78
F0077D40: c6064000                 ld      [%i1], %g3
F0077D44: 80a0e000                 cmp     %g3, 0
F0077D48: 22800019                 be,a    loc_F0077DAC
F0077D4C: c6204000                 st      %g3, [%g1]
F0077D50: c400e004                 ld      [%g3+4], %g2
F0077D54: 80a0801a                 cmp     %g2, %i2
F0077D58: 22800015                 be,a    loc_F0077DAC
F0077D5C: c6204000                 st      %g3, [%g1]
F0077D60: c600c000                 ld      [%g3], %g3
F0077D64: 80a0e000                 cmp     %g3, 0
F0077D68: 32bffffb                 bne,a   loc_F0077D54
F0077D6C: c400e004                 ld      [%g3+4], %g2
F0077D70: 1080000f                 ba      loc_F0077DAC
F0077D74: c6204000                 st      %g3, [%g1]
F0077D78: 80a0e000                 cmp     %g3, 0
F0077D7C: 2280000c                 be,a    loc_F0077DAC
F0077D80: c6204000                 st      %g3, [%g1]
F0077D84: f4062004                 ld      [%i0+4], %i2
F0077D88: c400e004                 ld      [%g3+4], %g2
F0077D8C: 80a0801a                 cmp     %g2, %i2
F0077D90: 3a800007                 bcc,a   loc_F0077DAC
F0077D94: c6204000                 st      %g3, [%g1]
F0077D98: c600c000                 ld      [%g3], %g3
F0077D9C: 80a0e000                 cmp     %g3, 0
F0077DA0: 32bffffb                 bne,a   loc_F0077D8C
F0077DA4: c400e004                 ld      [%g3+4], %g2
F0077DA8: c6204000                 st      %g3, [%g1]
F0077DAC: c6062014                 ld      [%i0+0x14], %g3
F0077DB0: 852f6004                 sll     %i5, 4, %g2
F0077DB4: 8600c002                 add     %g3, %g2, %g3
F0077DB8: c400fff0                 ld      [%g3-0x10], %g2
F0077DBC: 80a0a000                 cmp     %g2, 0
F0077DC0: 02800004                 be      loc_F0077DD0
F0077DC4: 80a64002                 cmp     %i1, %g2
F0077DC8: 1a800003                 bcc     locret_F0077DD4
F0077DCC: 01000000                 nop
F0077DD0: f220fff0                 st      %i1, [%g3-0x10]
F0077DD4: 81c7e008                 ret
F0077DD8: 81e80000                 restore
