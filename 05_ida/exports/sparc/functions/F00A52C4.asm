F00A52C4: 9de3bf98                 save    %sp, -0x68, %sp
F00A52C8: c4062008                 ld      [%i0+8], %g2
F00A52CC: 86062008                 add     %i0, 8, %g3
F00A52D0: 80a0a000                 cmp     %g2, 0
F00A52D4: 0280000b                 be      locret_F00A5300
F00A52D8: b0102000                 mov     0, %i0
F00A52DC: c400c000                 ld      [%g3], %g2
F00A52E0: 80a60002                 cmp     %i0, %g2
F00A52E4: 26800002                 bl,a    loc_F00A52EC
F00A52E8: b0100002                 mov     %g2, %i0
F00A52EC: 8600e008                 inc     8, %g3
F00A52F0: c400c000                 ld      [%g3], %g2
F00A52F4: 80a0a000                 cmp     %g2, 0
F00A52F8: 12bffffb                 bne     loc_F00A52E4
F00A52FC: 80a60002                 cmp     %i0, %g2
F00A5300: 81c7e008                 ret
F00A5304: 81e80000                 restore
