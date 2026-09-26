F00DC160: 9de3bf90                 save    %sp, -0x70, %sp
F00DC164: c406a004                 ld      [%i2+4], %g2
F00DC168: c606a008                 ld      [%i2+8], %g3
F00DC16C: b0208003                 sub     %g2, %g3, %i0
F00DC170: 80a6001d                 cmp     %i0, %i5
F00DC174: 38800002                 bgu,a   loc_F00DC17C
F00DC178: b010001d                 mov     %i5, %i0
F00DC17C: 8400c018                 add     %g3, %i0, %g2
F00DC180: c426a008                 st      %g2, [%i2+8]
F00DC184: 81c7e008                 ret
F00DC188: 81e80000                 restore
