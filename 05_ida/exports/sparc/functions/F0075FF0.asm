F0075FF0: 9de3bf98                 save    %sp, -0x68, %sp
F0075FF4: 86102000                 mov     0, %g3
F0075FF8: 0537ab6fb410a2ef         set     -0x21524111, %i2
F0076000: b2102000                 mov     0, %i1
F0076004: c4064018                 ld      [%i1+%i0], %g2
F0076008: 80a0801a                 cmp     %g2, %i2
F007600C: 32800007                 bne,a   loc_F0076028
F0076010: 8528e002                 sll     %g3, 2, %g2
F0076014: 8600e001                 inc     %g3
F0076018: 80a0effc                 cmp     %g3, 0xFFC
F007601C: 08bffffa                 bleu    loc_F0076004
F0076020: b2066004                 inc     4, %i1
F0076024: 8528e002                 sll     %g3, 2, %g2
F0076028: 3100000fb01623f4         set     0x3FF4, %i0
F0076030: b0260002                 sub     %i0, %g2, %i0
F0076034: 81c7e008                 ret
F0076038: 81e80000                 restore
