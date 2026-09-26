F00E1584: 9de3bf98                 save    %sp, -0x68, %sp
F00E1588: 84102024                 mov     0x24, %g2 ! '$'
F00E158C: c4262004                 st      %g2, [%i0+4]
F00E1590: 8410212e                 mov     0x12E, %g2
F00E1594: c4262014                 st      %g2, [%i0+0x14]
F00E1598: f2262010                 st      %i1, [%i0+0x10]
F00E159C: 053c04bb                 sethi   %hi(dword_F012EF5C), %g2
F00E15A0: c400a35c                 ld      [%g2+%lo(dword_F012EF5C)], %g2
F00E15A4: c4262018                 st      %g2, [%i0+0x18]
F00E15A8: f426201c                 st      %i2, [%i0+0x1C]
F00E15AC: f6262020                 st      %i3, [%i0+0x20]
F00E15B0: 81c7e008                 ret
F00E15B4: 81e80000                 restore
