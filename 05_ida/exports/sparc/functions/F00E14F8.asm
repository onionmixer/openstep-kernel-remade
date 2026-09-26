F00E14F8: 9de3bf98                 save    %sp, -0x68, %sp
F00E14FC: c02e2003                 clrb    [%i0+3]
F00E1500: 84102030                 mov     0x30, %g2 ! '0'
F00E1504: c4262004                 st      %g2, [%i0+4]
F00E1508: c0262008                 clr     [%i0+8]
F00E150C: f2262010                 st      %i1, [%i0+0x10]
F00E1510: c026200c                 clr     [%i0+0xC]
F00E1514: 8410212c                 mov     0x12C, %g2
F00E1518: c4262014                 st      %g2, [%i0+0x14]
F00E151C: 053c04bb                 sethi   %hi(dword_F012EF5C), %g2
F00E1520: c400a35c                 ld      [%g2+%lo(dword_F012EF5C)], %g2
F00E1524: c4262018                 st      %g2, [%i0+0x18]
F00E1528: f426201c                 st      %i2, [%i0+0x1C]
F00E152C: 053c04bb                 sethi   %hi(dword_F012EF50), %g2
F00E1530: c600a350                 ld      [%g2+%lo(dword_F012EF50)], %g3
F00E1534: c6262020                 st      %g3, [%i0+0x20]
F00E1538: 8410a350                 bset    %lo(dword_F012EF50), %g2
F00E153C: c400a004                 ld      [%g2+4], %g2
F00E1540: c4262024                 st      %g2, [%i0+0x24]
F00E1544: f8262028                 st      %i4, [%i0+0x28]
F00E1548: f626202c                 st      %i3, [%i0+0x2C]
F00E154C: 81c7e008                 ret
F00E1550: 81e80000                 restore
