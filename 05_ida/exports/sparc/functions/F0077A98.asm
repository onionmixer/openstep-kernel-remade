F0077A98: 9de3bf90                 save    %sp, -0x70, %sp
F0077A9C: b6100019                 mov     %i1, %i3
F0077AA0: f4062004                 ld      [%i0+4], %i2
F0077AA4: f427bff4                 st      %i2, [%fp+var_C]
F0077AA8: f8060000                 ld      [%i0], %i4
F0077AAC: f827bff0                 st      %i4, [%fp+var_10]
F0077AB0: c4062008                 ld      [%i0+8], %g2
F0077AB4: 80a68002                 cmp     %i2, %g2
F0077AB8: 32bffffb                 bne,a   loc_F0077AA4
F0077ABC: f4062004                 ld      [%i0+4], %i2
F0077AC0: c606e004                 ld      [%i3+4], %g3
F0077AC4: f206c000                 ld      [%i3], %i1
F0077AC8: f426e004                 st      %i2, [%i3+4]
F0077ACC: c407bff0                 ld      [%fp+var_10], %g2
F0077AD0: 86268003                 sub     %i2, %g3, %g3
F0077AD4: c426c000                 st      %g2, [%i3]
F0077AD8: 8528e005                 sll     %g3, 5, %g2
F0077ADC: 84208003                 sub     %g2, %g3, %g2
F0077AE0: b128a006                 sll     %g2, 6, %i0
F0077AE4: b0260002                 sub     %i0, %g2, %i0
F0077AE8: b12e2003                 sll     %i0, 3, %i0
F0077AEC: b0060003                 add     %i0, %g3, %i0
F0077AF0: b12e2006                 sll     %i0, 6, %i0
F0077AF4: b006001c                 add     %i0, %i4, %i0
F0077AF8: b0260019                 sub     %i0, %i1, %i0
F0077AFC: 81c7e008                 ret
F0077B00: 81e80000                 restore
