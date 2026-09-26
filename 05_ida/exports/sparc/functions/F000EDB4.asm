F000EDB4: 9de3bf98                 save    %sp, -0x68, %sp
F000EDB8: 073c04cfb210e1dc         set     dword_F0133DDC, %i1
F000EDC0: c4067ffc                 ld      [%i1-4], %g2
F000EDC4: c600e1dc                 ld      [%g3+0x1DC], %g3
F000EDC8: c4008000                 ld      [%g2], %g2
F000EDCC: f400e024                 ld      [%g3+0x24], %i2
F000EDD0: c400a014                 ld      [%g2+0x14], %g2
F000EDD4: 313c04d0                 sethi   %hi(_active_threads), %i0
F000EDD8: c6062260                 ld      [%i0+%lo(_active_threads)], %g3
F000EDDC: 8528a010                 sll     %g2, 16, %g2
F000EDE0: 8538a01f                 sra     %g2, 31, %g2
F000EDE4: 80a00002                 cmp     %g0, %g2
F000EDE8: c600e084                 ld      [%g3+0x84], %g3
F000EDEC: 84602000                 subc    %g0, 0, %g2
F000EDF0: c420e030                 st      %g2, [%g3+0x30]
F000EDF4: c4067ffc                 ld      [%i1-4], %g2
F000EDF8: f2008000                 ld      [%g2], %i1
F000EDFC: f0066014                 ld      [%i1+0x14], %i0
F000EE00: 07000020                 sethi   0x8000, %g3
F000EE04: c4068000                 ld      [%i2], %g2
F000EE08: 862e0003                 andn    %i0, %g3, %g3
F000EE0C: 80a00002                 cmp     %g0, %g2
F000EE10: 84402000                 addc    %g0, 0, %g2
F000EE14: 8528a00f                 sll     %g2, 15, %g2
F000EE18: 8610c002                 bset    %g2, %g3
F000EE1C: c6266014                 st      %g3, [%i1+0x14]
F000EE20: 81c7e008                 ret
F000EE24: 91e82000                 restore %g0, 0, %o0
