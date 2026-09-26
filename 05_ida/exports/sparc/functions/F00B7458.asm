F00B7458: 9de3bf98                 save    %sp, -0x68, %sp
F00B745C: f206209c                 ld      [%i0+0x9C], %i1
F00B7460: 84102044                 mov     0x44, %g2 ! 'D'
F00B7464: c42e600c                 stb     %g2, [%i1+0xC]
F00B7468: c45620b2                 ldsh    [%i0+0xB2], %g2
F00B746C: 80a0bfff                 cmp     %g2, -1
F00B7470: 02800011                 be      loc_F00B74B4
F00B7474: 8528a002                 sll     %g2, 2, %g2
F00B7478: 84008018                 add     %g2, %i0, %g2
F00B747C: c600a0b8                 ld      [%g2+0xB8], %g3
F00B7480: 80a0e000                 cmp     %g3, 0
F00B7484: 0280000c                 be      loc_F00B74B4
F00B7488: 053c047c                 sethi   %hi(_scsi_options), %g2
F00B748C: c400a158                 ld      [%g2+%lo(_scsi_options)], %g2
F00B7490: 8088a040                 btst    0x40, %g2 ! '@'
F00B7494: 22800009                 be,a    locret_F00B74B8
F00B7498: c02e2046                 clrb    [%i0+0x46]
F00B749C: c400e014                 ld      [%g3+0x14], %g2
F00B74A0: 8088a008                 btst    8, %g2
F00B74A4: 22800005                 be,a    locret_F00B74B8
F00B74A8: c02e2046                 clrb    [%i0+0x46]
F00B74AC: c40e2032                 ldub    [%i0+0x32], %g2
F00B74B0: c42e6020                 stb     %g2, [%i1+0x20]
F00B74B4: c02e2046                 clrb    [%i0+0x46]
F00B74B8: 81c7e008                 ret
F00B74BC: 81e80000                 restore
