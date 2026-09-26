F00BD880: 9de3bf98                 save    %sp, -0x68, %sp
F00BD884: 86102000                 mov     0, %g3
F00BD888: 053c04c88410a078         set     unk_F0132078, %g2
F00BD890: b0102055                 mov     0x55, %i0 ! 'U'
F00BD894: f028c002                 stb     %i0, [%g3+%g2]
F00BD898: 8600e001                 inc     %g3
F00BD89C: 80a0ee9f                 cmp     %g3, 0xE9F
F00BD8A0: 28bffffe                 bleu,a  loc_F00BD898
F00BD8A4: f028c002                 stb     %i0, [%g3+%g2]
F00BD8A8: 81c7e008                 ret
F00BD8AC: 81e80000                 restore
