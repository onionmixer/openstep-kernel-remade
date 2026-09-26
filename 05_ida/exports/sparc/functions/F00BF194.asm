F00BF194: 9de3bf90                 save    %sp, -0x70, %sp
F00BF198: b407bff8                 add     %fp, var_8, %i2
F00BF19C: c41e0000                 ldd     [%i0], %g2
F00BF1A0: b6102000                 mov     0, %i3
F00BF1A4: b007bffc                 add     %fp, var_4, %i0
F00BF1A8: c43fbff0                 std     %g2, [%fp+var_10]
F00BF1AC: c406bff8                 ld      [%i2-8], %g2
F00BF1B0: c426c019                 st      %g2, [%i3+%i1]
F00BF1B4: b406a004                 inc     4, %i2
F00BF1B8: 80a68018                 cmp     %i2, %i0
F00BF1BC: 08bffffc                 bleu    loc_F00BF1AC
F00BF1C0: b606e004                 inc     4, %i3
F00BF1C4: 81c7e008                 ret
F00BF1C8: 81e80000                 restore
