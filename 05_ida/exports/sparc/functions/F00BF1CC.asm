F00BF1CC: 9de3bf90                 save    %sp, -0x70, %sp
F00BF1D0: 8607bff8                 add     %fp, var_8, %g3
F00BF1D4: b4102000                 mov     0, %i2
F00BF1D8: b607bffc                 add     %fp, var_4, %i3
F00BF1DC: c4068018                 ld      [%i2+%i0], %g2
F00BF1E0: c420fff8                 st      %g2, [%g3-8]
F00BF1E4: 8600e004                 inc     4, %g3
F00BF1E8: 80a0c01b                 cmp     %g3, %i3
F00BF1EC: 08bffffc                 bleu    loc_F00BF1DC
F00BF1F0: b406a004                 inc     4, %i2
F00BF1F4: c41fbff0                 ldd     [%fp+var_10], %g2
F00BF1F8: c43e4000                 std     %g2, [%i1]
F00BF1FC: 81c7e008                 ret
F00BF200: 81e80000                 restore
