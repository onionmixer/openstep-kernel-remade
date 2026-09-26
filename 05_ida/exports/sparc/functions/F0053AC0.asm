F0053AC0: 9de3bf98                 save    %sp, -0x68, %sp
F0053AC4: f6062014                 ld      [%i0+0x14], %i3
F0053AC8: ba100019                 mov     %i1, %i5
F0053ACC: f806e008                 ld      [%i3+8], %i4
F0053AD0: 80a72000                 cmp     %i4, 0
F0053AD4: 02800012                 be      loc_F0053B1C
F0053AD8: 8210001a                 mov     %i2, %g1
F0053ADC: b32f2004                 sll     %i4, 4, %i1
F0053AE0: b406c019                 add     %i3, %i1, %i2
F0053AE4: c406a008                 ld      [%i2+8], %g2
F0053AE8: b0102000                 mov     0, %i0
F0053AEC: c426e008                 st      %g2, [%i3+8]
F0053AF0: c606c019                 ld      [%i3+%i1], %g3
F0053AF4: 05004000                 sethi   0x1000000, %g2
F0053AF8: 8600c002                 add     %g3, %g2, %g3
F0053AFC: c626c019                 st      %g3, [%i3+%i1]
F0053B00: c026a008                 clr     [%i2+8]
F0053B04: 852f2008                 sll     %i4, 8, %g2
F0053B08: 8730e018                 srl     %g3, 24, %g3
F0053B0C: 84108003                 bset    %g3, %g2
F0053B10: c4274000                 st      %g2, [%i5]
F0053B14: 10800003                 ba      locret_F0053B20
F0053B18: f4204000                 st      %i2, [%g1]
F0053B1C: b0102003                 mov     3, %i0
F0053B20: 81c7e008                 ret
F0053B24: 81e80000                 restore
