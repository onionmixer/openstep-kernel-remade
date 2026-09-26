F00E14B0: 9de3bf98                 save    %sp, -0x68, %sp
F00E14B4: 8410213a                 mov     0x13A, %g2
F00E14B8: c4262014                 st      %g2, [%i0+0x14]
F00E14BC: 84102024                 mov     0x24, %g2 ! '$'
F00E14C0: c4262004                 st      %g2, [%i0+4]
F00E14C4: f226200c                 st      %i1, [%i0+0xC]
F00E14C8: f4262010                 st      %i2, [%i0+0x10]
F00E14CC: 053c04bb                 sethi   %hi(dword_F012EF5C), %g2
F00E14D0: c600a35c                 ld      [%g2+%lo(dword_F012EF5C)], %g3
F00E14D4: 053fffc08410a00f         set     -0xFFF1, %g2
F00E14DC: 8608c002                 and     %g3, %g2, %g3
F00E14E0: 8610e020                 bset    0x20, %g3 ! ' '
F00E14E4: c6262018                 st      %g3, [%i0+0x18]
F00E14E8: f626201c                 st      %i3, [%i0+0x1C]
F00E14EC: f8262020                 st      %i4, [%i0+0x20]
F00E14F0: 81c7e008                 ret
F00E14F4: 81e80000                 restore
