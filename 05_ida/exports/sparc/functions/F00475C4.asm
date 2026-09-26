F00475C4: 9de3bf98                 save    %sp, -0x68, %sp
F00475C8: 333c04eb                 sethi   %hi(_stable), %i1
F00475CC: c6162042                 lduh    [%i0+0x42], %g3
F00475D0: b2166130                 bset    %lo(_stable), %i1
F00475D4: 8530e008                 srl     %g3, 8, %g2
F00475D8: 8608e0ff                 and     %g3, 0xFF, %g3
F00475DC: 84008003                 add     %g2, %g3, %g2
F00475E0: 8408a00f                 and     %g2, 0xF, %g2
F00475E4: 8528a002                 sll     %g2, 2, %g2
F00475E8: c4008019                 ld      [%g2+%i1], %g2
F00475EC: c6162042                 lduh    [%i0+0x42], %g3
F00475F0: c4260000                 st      %g2, [%i0]
F00475F4: 8530e008                 srl     %g3, 8, %g2
F00475F8: 8608e0ff                 and     %g3, 0xFF, %g3
F00475FC: 84008003                 add     %g2, %g3, %g2
F0047600: 8408a00f                 and     %g2, 0xF, %g2
F0047604: 8528a002                 sll     %g2, 2, %g2
F0047608: f0208019                 st      %i0, [%g2+%i1]
F004760C: 81c7e008                 ret
F0047610: 81e80000                 restore
