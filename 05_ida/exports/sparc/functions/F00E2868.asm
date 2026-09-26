F00E2868: 9de3bf98                 save    %sp, -0x68, %sp
F00E286C: b12e2018                 sll     %i0, 24, %i0
F00E2870: 053c04bb                 sethi   %hi(dword_F012EF60), %g2
F00E2874: c400a360                 ld      [%g2+%lo(dword_F012EF60)], %g2
F00E2878: b13e2018                 sra     %i0, 24, %i0
F00E287C: b0060002                 add     %i0, %g2, %i0
F00E2880: 05000008                 sethi   0x2000, %g2
F00E2884: f00e0002                 ldub    [%i0+%g2], %i0
F00E2888: 81c7e008                 ret
F00E288C: 81e80000                 restore
