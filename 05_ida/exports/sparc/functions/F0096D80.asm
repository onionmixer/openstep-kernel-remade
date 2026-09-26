F0096D80: 1b3c0464                 sethi   %hi(_Cpudelay), %o5
F0096D84: d803631c                 ld      [%o5+%lo(_Cpudelay)], %o4
F0096D88: 96932000                 orcc    %o4, 0, %o3
F0096D8C: 12800000                 bne     loc_F0096D8C
F0096D90: 96a2e001                 deccc   %o3
F0096D94: 90a22001                 deccc   %o0
F0096D98: 14bffffd                 bg      loc_F0096D8C
F0096D9C: 96932000                 orcc    %o4, 0, %o3
F0096DA0: 81c3e008                 retl
F0096DA4: 01000000                 nop
