F0098A44: 9de3bf98                 save    %sp, -0x68, %sp
F0098A48: 053c044b                 sethi   %hi(word_F0112E0A), %g2
F0098A4C: c410a20a                 lduh    [%g2+%lo(word_F0112E0A)], %g2
F0098A50: 8088a002                 btst    2, %g2
F0098A54: 02800012                 be      locret_F0098A9C
F0098A58: 053c044d                 sethi   %hi(_report_ce), %g2
F0098A5C: c400a070                 ld      [%g2+%lo(_report_ce)], %g2
F0098A60: 80a0a000                 cmp     %g2, 0
F0098A64: 02800005                 be      loc_F0098A78
F0098A68: 073c044d                 sethi   %hi(_efervalue), %g3
F0098A6C: c400e074                 ld      [%g3+%lo(_efervalue)], %g2
F0098A70: 10800004                 ba      loc_F0098A80
F0098A74: 8410a003                 bset    3, %g2
F0098A78: c400e074                 ld      [%g3+0x74], %g2
F0098A7C: 8410a001                 bset    1, %g2
F0098A80: c420e074                 st      %g2, [%g3+0x74]
F0098A84: 313fbfbc                 sethi   -0x1011000, %i0
F0098A88: c4060000                 ld      [%i0], %g2
F0098A8C: 073c044d                 sethi   %hi(_efervalue), %g3
F0098A90: c600e074                 ld      [%g3+%lo(_efervalue)], %g3
F0098A94: 84108003                 bset    %g3, %g2
F0098A98: c4260000                 st      %g2, [%i0]
F0098A9C: 81c7e008                 ret
F0098AA0: 81e80000                 restore
