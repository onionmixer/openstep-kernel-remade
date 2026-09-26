F00243B8: 9de3bf98                 save    %sp, -0x68, %sp
F00243BC: 073c042f                 sethi   %hi(_vfssw), %g3
F00243C0: 053c0430                 sethi   %hi(_vfsNVFS), %g2
F00243C4: c400a08c                 ld      [%g2+%lo(_vfsNVFS)], %g2
F00243C8: 8610e3d8                 bset    %lo(_vfssw), %g3
F00243CC: 80a0c002                 cmp     %g3, %g2
F00243D0: 3a80000d                 bcc,a   loc_F0024404
F00243D4: 313c042f                 sethi   -0xFEF4400, %i0
F00243D8: f0062004                 ld      [%i0+4], %i0
F00243DC: b2100002                 mov     %g2, %i1
F00243E0: c400e004                 ld      [%g3+4], %g2
F00243E4: 80a08018                 cmp     %g2, %i0
F00243E8: 22800007                 be,a    loc_F0024404
F00243EC: 313c042f                 sethi   -0xFEF4400, %i0
F00243F0: 8600e008                 inc     8, %g3
F00243F4: 80a0c019                 cmp     %g3, %i1
F00243F8: 2abffffb                 bcs,a   loc_F00243E4
F00243FC: c400e004                 ld      [%g3+4], %g2
F0024400: 313c042f                 sethi   -0xFEF4400, %i0
F0024404: b01623d8                 bset    0x3D8, %i0
F0024408: b020c018                 sub     %g3, %i0, %i0
F002440C: b13e2003                 sra     %i0, 3, %i0
F0024410: 81c7e008                 ret
F0024414: 91ee2080                 restore %i0, 0x80, %o0
