F004DAC4: 9de3bf98                 save    %sp, -0x68, %sp
F004DAC8: 113c04ef                 sethi   %hi(_inode_zone), %o0
F004DACC: 4000ad80                 call    _zalloc
F004DAD0: d00221b0                 ld      [%o0+%lo(_inode_zone)], %o0! void *
F004DAD4: b0920000                 orcc    %o0, %g0, %i0
F004DAD8: 22800018                 be,a    locret_F004DB38
F004DADC: b0102000                 mov     0, %i0
F004DAE0: 40011cde                 call    _bzero
F004DAE4: 921020e8                 mov     0xE8, %o1
F004DAE8: f0260000                 st      %i0, [%i0]
F004DAEC: f0262004                 st      %i0, [%i0+4]
F004DAF0: c026205c                 clr     [%i0+0x5C]
F004DAF4: c0262060                 clr     [%i0+0x60]
F004DAF8: f026203c                 st      %i0, [%i0+0x3C]
F004DAFC: 113c043c90122160         set     _ufs_vnodeops, %o0
F004DB04: d0262028                 st      %o0, [%i0+0x28]
F004DB08: c026200c                 clr     [%i0+0xC]
F004DB0C: 4000799c                 call    _vm_info_init
F004DB10: 9006200c                 add     %i0, 0xC, %o0
F004DB14: 113c04d4                 sethi   %hi(_inode_list), %o0
F004DB18: d6022140                 ld      [%o0+%lo(_inode_list)], %o3
F004DB1C: d406200c                 ld      [%i0+0xC], %o2
F004DB20: f0222140                 st      %i0, [%o0+%lo(_inode_list)]
F004DB24: d202a038                 ld      [%o2+0x38], %o1
F004DB28: 11080000                 sethi   0x20000000, %o0
F004DB2C: 902a4008                 andn    %o1, %o0, %o0
F004DB30: d022a038                 st      %o0, [%o2+0x38]
F004DB34: d6262008                 st      %o3, [%i0+8]
F004DB38: 81c7e008                 ret
F004DB3C: 81e80000                 restore
