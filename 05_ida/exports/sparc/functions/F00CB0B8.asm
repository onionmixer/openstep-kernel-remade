F00CB0B8: 9de3bf98                 save    %sp, -0x68, %sp
F00CB0BC: ba100018                 mov     %i0, %i5
F00CB0C0: 053c042f8610a3d8         set     _vfssw, %g3
F00CB0C8: 053c0430                 sethi   %hi(_vfsNVFS), %g2
F00CB0CC: c400a08c                 ld      [%g2+%lo(_vfsNVFS)], %g2
F00CB0D0: 80a0c002                 cmp     %g3, %g2
F00CB0D4: 1a800024                 bcc     loc_F00CB164
F00CB0D8: b0102000                 mov     0, %i0
F00CB0DC: b6100003                 mov     %g3, %i3
F00CB0E0: 84208003                 sub     %g2, %g3, %g2
F00CB0E4: b938a003                 sra     %g2, 3, %i4
F00CB0E8: c400c000                 ld      [%g3], %g2
F00CB0EC: 80a0a000                 cmp     %g2, 0
F00CB0F0: 12800018                 bne     loc_F00CB150
F00CB0F4: 053c0430                 sethi   -0xFEF4000, %g2
F00CB0F8: c400e004                 ld      [%g3+4], %g2
F00CB0FC: 80a0a000                 cmp     %g2, 0
F00CB100: 32800014                 bne,a   loc_F00CB150
F00CB104: 053c0430                 sethi   -0xFEF4000, %g2
F00CB108: 80a62000                 cmp     %i0, 0
F00CB10C: 872e2003                 sll     %i0, 3, %g3
F00CB110: 06800015                 bl      loc_F00CB164
F00CB114: b400c01b                 add     %g3, %i3, %i2
F00CB118: 80a6001c                 cmp     %i0, %i4
F00CB11C: 36800013                 bge,a   locret_F00CB168
F00CB120: b0103fff                 mov     -1, %i0
F00CB124: c400c01b                 ld      [%g3+%i3], %g2
F00CB128: 80a0a000                 cmp     %g2, 0
F00CB12C: 3280000f                 bne,a   locret_F00CB168
F00CB130: b0103fff                 mov     -1, %i0
F00CB134: c406a004                 ld      [%i2+4], %g2
F00CB138: 80a0a000                 cmp     %g2, 0
F00CB13C: 3280000b                 bne,a   locret_F00CB168
F00CB140: b0103fff                 mov     -1, %i0
F00CB144: fa20c01b                 st      %i5, [%g3+%i3]
F00CB148: 10800008                 ba      locret_F00CB168
F00CB14C: f226a004                 st      %i1, [%i2+4]
F00CB150: c400a08c                 ld      [%g2+0x8C], %g2
F00CB154: 8600e008                 inc     8, %g3
F00CB158: 80a0c002                 cmp     %g3, %g2
F00CB15C: 0abfffe3                 bcs     loc_F00CB0E8
F00CB160: b0062001                 inc     %i0
F00CB164: b0103fff                 mov     -1, %i0
F00CB168: 81c7e008                 ret
F00CB16C: 81e80000                 restore
