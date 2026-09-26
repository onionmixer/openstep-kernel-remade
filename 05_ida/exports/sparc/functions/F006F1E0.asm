F006F1E0: 9de3bf98                 save    %sp, -0x68, %sp
F006F1E4: 80a62000                 cmp     %i0, 0
F006F1E8: 12800004                 bne     loc_F006F1F8
F006F1EC: 80a66001                 cmp     %i1, 1
F006F1F0: 10800028                 ba      locret_F006F290
F006F1F4: b0102004                 mov     4, %i0
F006F1F8: 32800026                 bne,a   locret_F006F290
F006F1FC: b0102005                 mov     5, %i0
F006F200: c4070000                 ld      [%i4], %g2
F006F204: 80a0a004                 cmp     %g2, 4
F006F208: 18800004                 bgu     loc_F006F218
F006F20C: 053c04d1                 sethi   -0xFECBC00, %g2
F006F210: 10800020                 ba      locret_F006F290
F006F214: b0102005                 mov     5, %i0
F006F218: fa062144                 ld      [%i0+0x144], %i5
F006F21C: 8410a360                 bset    0x360, %g2
F006F220: 872f6005                 sll     %i5, 5, %g3
F006F224: 8600c002                 add     %g3, %g2, %g3
F006F228: c400e004                 ld      [%g3+4], %g2
F006F22C: c426c000                 st      %g2, [%i3]
F006F230: c400e008                 ld      [%g3+8], %g2
F006F234: c426e004                 st      %g2, [%i3+4]
F006F238: c4062114                 ld      [%i0+0x114], %g2
F006F23C: 80a0a005                 cmp     %g2, 5
F006F240: 02800004                 be      loc_F006F250
F006F244: 80a0a000                 cmp     %g2, 0
F006F248: 32800003                 bne,a   loc_F006F254
F006F24C: f226e008                 st      %i1, [%i3+8]
F006F250: c026e008                 clr     [%i3+8]
F006F254: 053c04d8                 sethi   %hi(_master_processor), %g2
F006F258: c400a3d0                 ld      [%g2+%lo(_master_processor)], %g2
F006F25C: 80a60002                 cmp     %i0, %g2
F006F260: 12800005                 bne     loc_F006F274
F006F264: fa26e00c                 st      %i5, [%i3+0xC]
F006F268: 84102001                 mov     1, %g2
F006F26C: 10800003                 ba      loc_F006F278
F006F270: c426e010                 st      %g2, [%i3+0x10]
F006F274: c026e010                 clr     [%i3+0x10]
F006F278: 84102005                 mov     5, %g2
F006F27C: c4270000                 st      %g2, [%i4]
F006F280: 053c04d48410a170         set     _realhost, %g2
F006F288: c4268000                 st      %g2, [%i2]
F006F28C: b0102000                 mov     0, %i0
F006F290: 81c7e008                 ret
F006F294: 81e80000                 restore
