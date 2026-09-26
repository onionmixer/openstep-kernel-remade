F00EC918: 053c04bc8610a048         set     unk_F012F048, %g3
F00EC920: 80a0e000                 cmp     %g3, 0
F00EC924: 0280000b                 be      loc_F00EC950
F00EC928: 01000000                 nop
F00EC92C: c400e010                 ld      [%g3+0x10], %g2
F00EC930: 80a08008                 cmp     %g2, %o0
F00EC934: 02800007                 be      loc_F00EC950
F00EC938: 80a0e000                 cmp     %g3, 0
F00EC93C: c600e014                 ld      [%g3+0x14], %g3
F00EC940: 80a0e000                 cmp     %g3, 0
F00EC944: 32bffffb                 bne,a   loc_F00EC930
F00EC948: c400e010                 ld      [%g3+0x10], %g2
F00EC94C: 80a0e000                 cmp     %g3, 0
F00EC950: 02800005                 be      locret_F00EC964
F00EC954: 01000000                 nop
F00EC958: c020c000                 clr     [%g3]
F00EC95C: c020e00c                 clr     [%g3+0xC]
F00EC960: c020e010                 clr     [%g3+0x10]
F00EC964: 81c3e008                 retl
F00EC968: 01000000                 nop
