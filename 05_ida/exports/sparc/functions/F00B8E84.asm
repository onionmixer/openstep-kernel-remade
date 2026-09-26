F00B8E84: 9de3bf98                 save    %sp, -0x68, %sp
F00B8E88: c6060000                 ld      [%i0], %g3
F00B8E8C: c4062008                 ld      [%i0+8], %g2
F00B8E90: 8600ffff                 inc     -1, %g3
F00B8E94: c6260000                 st      %g3, [%i0]
F00B8E98: 8400a001                 inc     %g2
F00B8E9C: 8408a007                 and     %g2, 7, %g2
F00B8EA0: c4262008                 st      %g2, [%i0+8]
F00B8EA4: 8528a002                 sll     %g2, 2, %g2
F00B8EA8: 84008018                 add     %g2, %i0, %g2
F00B8EAC: f000a014                 ld      [%g2+0x14], %i0
F00B8EB0: c020a014                 clr     [%g2+0x14]
F00B8EB4: 81c7e008                 ret
F00B8EB8: 81e80000                 restore
