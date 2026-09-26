F00719A0: 9de3bf98                 save    %sp, -0x68, %sp
F00719A4: c406206c                 ld      [%i0+0x6C], %g2
F00719A8: c6062050                 ld      [%i0+0x50], %g3
F00719AC: 8530a019                 srl     %g2, 25, %g2
F00719B0: 86a0c002                 subcc   %g3, %g2, %g3
F00719B4: 2c800002                 bneg,a  loc_F00719BC
F00719B8: 86102000                 mov     0, %g3
F00719BC: c6262058                 st      %g3, [%i0+0x58]
F00719C0: 81c7e008                 ret
F00719C4: 81e80000                 restore
