F000F8F8: 9de3bf98                 save    %sp, -0x68, %sp
F000F8FC: 053c04cf                 sethi   %hi(_active_u), %g2
F000F900: c400a1d8                 ld      [%g2+%lo(_active_u)], %g2
F000F904: f200a01c                 ld      [%g2+0x1C], %i1
F000F908: b12e2010                 sll     %i0, 16, %i0
F000F90C: c4566004                 ldsh    [%i1+4], %g2
F000F910: b13e2010                 sra     %i0, 16, %i0
F000F914: 80a08018                 cmp     %g2, %i0
F000F918: 12800004                 bne     loc_F000F928
F000F91C: 8606600a                 add     %i1, 0xA, %g3
F000F920: 10800011                 ba      locret_F000F964
F000F924: b0102001                 mov     1, %i0
F000F928: 8406602a                 add     %i1, 0x2A, %g2 ! '*'
F000F92C: 80a0c002                 cmp     %g3, %g2
F000F930: 3a80000d                 bcc,a   locret_F000F964
F000F934: b0102000                 mov     0, %i0
F000F938: b2100002                 mov     %g2, %i1
F000F93C: c450c000                 ldsh    [%g3], %g2
F000F940: 80a0bfff                 cmp     %g2, -1
F000F944: 02800007                 be      loc_F000F960
F000F948: 80a08018                 cmp     %g2, %i0
F000F94C: 02bffff5                 be      loc_F000F920
F000F950: 8600e002                 inc     2, %g3
F000F954: 80a0c019                 cmp     %g3, %i1
F000F958: 2abffffa                 bcs,a   loc_F000F940
F000F95C: c450c000                 ldsh    [%g3], %g2
F000F960: b0102000                 mov     0, %i0
F000F964: 81c7e008                 ret
F000F968: 81e80000                 restore
