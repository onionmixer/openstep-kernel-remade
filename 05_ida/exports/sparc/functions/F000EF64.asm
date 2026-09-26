F000EF64: 9de3bf98                 save    %sp, -0x68, %sp
F000EF68: 313c04cf                 sethi   %hi(dword_F0133DDC), %i0
F000EF6C: c60621dc                 ld      [%i0+%lo(dword_F0133DDC)], %g3
F000EF70: c400e024                 ld      [%g3+0x24], %g2
F000EF74: f2008000                 ld      [%g2], %i1
F000EF78: 80a66001                 cmp     %i1, 1
F000EF7C: 18800015                 bgu     loc_F000EFD0
F000EF80: b41621dc                 or      %i0, %lo(dword_F0133DDC), %i2
F000EF84: c406bffc                 ld      [%i2-4], %g2
F000EF88: c4008000                 ld      [%g2], %g2
F000EF8C: c400a014                 ld      [%g2+0x14], %g2
F000EF90: 8528a001                 sll     %g2, 1, %g2
F000EF94: 8528a010                 sll     %g2, 16, %g2
F000EF98: 8538a01f                 sra     %g2, 31, %g2
F000EF9C: 80a00002                 cmp     %g0, %g2
F000EFA0: 84602000                 subc    %g0, 0, %g2
F000EFA4: c420e030                 st      %g2, [%g3+0x30]
F000EFA8: c406bffc                 ld      [%i2-4], %g2
F000EFAC: f0008000                 ld      [%g2], %i0
F000EFB0: c4062014                 ld      [%i0+0x14], %g2
F000EFB4: 07000010                 sethi   0x4000, %g3
F000EFB8: 86288003                 andn    %g2, %g3, %g3
F000EFBC: 840e6001                 and     %i1, 1, %g2
F000EFC0: 8528a00e                 sll     %g2, 14, %g2
F000EFC4: 8610c002                 bset    %g2, %g3
F000EFC8: 10800007                 ba      locret_F000EFE4
F000EFCC: c6262014                 st      %g3, [%i0+0x14]
F000EFD0: 84103fff                 mov     -1, %g2
F000EFD4: c420e030                 st      %g2, [%g3+0x30]
F000EFD8: c60621dc                 ld      [%i0+0x1DC], %g3
F000EFDC: 84102016                 mov     0x16, %g2
F000EFE0: c428e038                 stb     %g2, [%g3+0x38]
F000EFE4: 81c7e008                 ret
F000EFE8: 81e80000                 restore
