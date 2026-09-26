F00CB04C: 9de3bf98                 save    %sp, -0x68, %sp
F00CB050: 80a62000                 cmp     %i0, 0
F00CB054: 872e2003                 sll     %i0, 3, %g3
F00CB058: 053c042fb610a3d8         set     _vfssw, %i3
F00CB060: 06800011                 bl      loc_F00CB0A4
F00CB064: b800c01b                 add     %g3, %i3, %i4
F00CB068: 053c0430                 sethi   %hi(_vfsNVFS), %g2
F00CB06C: c400a08c                 ld      [%g2+%lo(_vfsNVFS)], %g2
F00CB070: 8420801b                 sub     %g2, %i3, %g2
F00CB074: 8538a003                 sra     %g2, 3, %g2
F00CB078: 80a60002                 cmp     %i0, %g2
F00CB07C: 3680000d                 bge,a   locret_F00CB0B0
F00CB080: b0103fff                 mov     -1, %i0
F00CB084: c400c01b                 ld      [%g3+%i3], %g2
F00CB088: 80a0a000                 cmp     %g2, 0
F00CB08C: 32800009                 bne,a   locret_F00CB0B0
F00CB090: b0103fff                 mov     -1, %i0
F00CB094: c4072004                 ld      [%i4+4], %g2
F00CB098: 80a0a000                 cmp     %g2, 0
F00CB09C: 22800004                 be,a    loc_F00CB0AC
F00CB0A0: f220c01b                 st      %i1, [%g3+%i3]
F00CB0A4: 10800003                 ba      locret_F00CB0B0
F00CB0A8: b0103fff                 mov     -1, %i0
F00CB0AC: f4272004                 st      %i2, [%i4+4]
F00CB0B0: 81c7e008                 ret
F00CB0B4: 81e80000                 restore
