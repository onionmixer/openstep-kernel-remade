F00E1738: 9de3bf98                 save    %sp, -0x68, %sp
F00E173C: 84102140                 mov     0x140, %g2
F00E1740: c4262014                 st      %g2, [%i0+0x14]
F00E1744: 84102030                 mov     0x30, %g2 ! '0'
F00E1748: c4262004                 st      %g2, [%i0+4]
F00E174C: f2262010                 st      %i1, [%i0+0x10]
F00E1750: 053c04bb                 sethi   %hi(dword_F012EF5C), %g2
F00E1754: 073fffc0                 sethi   -0x10000, %g3
F00E1758: c400a35c                 ld      [%g2+%lo(dword_F012EF5C)], %g2
F00E175C: 8610e00f                 bset    0xF, %g3
F00E1760: 84088003                 and     %g2, %g3, %g2
F00E1764: 8410a050                 bset    0x50, %g2 ! 'P'
F00E1768: c4262018                 st      %g2, [%i0+0x18]
F00E176C: f426201c                 st      %i2, [%i0+0x1C]
F00E1770: f6262020                 st      %i3, [%i0+0x20]
F00E1774: f8262024                 st      %i4, [%i0+0x24]
F00E1778: c407a05c                 ld      [%fp+arg_5C], %g2
F00E177C: fa262028                 st      %i5, [%i0+0x28]
F00E1780: c426202c                 st      %g2, [%i0+0x2C]
F00E1784: 81c7e008                 ret
F00E1788: 81e80000                 restore
