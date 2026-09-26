F008BCC4: 9de3bf58                 save    %sp, -0xA8, %sp
F008BCC8: b0102000                 mov     0, %i0
F008BCCC: 053c04c3                 sethi   %hi(dword_F0130F6C), %g2
F008BCD0: c400a36c                 ld      [%g2+%lo(dword_F0130F6C)], %g2
F008BCD4: 80a0a001                 cmp     %g2, 1
F008BCD8: 0480002c                 ble     loc_F008BD88
F008BCDC: b8102000                 mov     0, %i4
F008BCE0: b4102000                 mov     0, %i2
F008BCE4: 093c04c39e112364         set     dword_F0130F64, %o7
F008BCEC: 053c043c8210a160         set     _ufs_vnodeops, %g1
F008BCF4: c6012364                 ld      [%g4+0x364], %g3
F008BCF8: 80a0c00f                 cmp     %g3, %o7
F008BCFC: 0280001c                 be      loc_F008BD6C
F008BD00: 053c04c3                 sethi   %hi(dword_F0130F64), %g2
F008BD04: b60ea001                 and     %i2, 1, %i3
F008BD08: ba10a364                 or      %g2, %lo(dword_F0130F64), %i5
F008BD0C: 80a6a001                 cmp     %i2, 1
F008BD10: 14800006                 bg      loc_F008BD28
F008BD14: f200e008                 ld      [%g3+8], %i1
F008BD18: c400e02c                 ld      [%g3+0x2C], %g2
F008BD1C: 80a0a000                 cmp     %g2, 0
F008BD20: 22800010                 be,a    loc_F008BD60
F008BD24: c600c000                 ld      [%g3], %g3
F008BD28: 80a6e000                 cmp     %i3, 0
F008BD2C: 32800007                 bne,a   loc_F008BD48
F008BD30: c400e018                 ld      [%g3+0x18], %g2
F008BD34: c406601c                 ld      [%i1+0x1C], %g2
F008BD38: 80a08001                 cmp     %g2, %g1
F008BD3C: 32800009                 bne,a   loc_F008BD60
F008BD40: c600c000                 ld      [%g3], %g3
F008BD44: c400e018                 ld      [%g3+0x18], %g2
F008BD48: 80a0801c                 cmp     %g2, %i4
F008BD4C: 24800005                 ble,a   loc_F008BD60
F008BD50: c600c000                 ld      [%g3], %g3
F008BD54: b8100002                 mov     %g2, %i4
F008BD58: b0100003                 mov     %g3, %i0
F008BD5C: c600c000                 ld      [%g3], %g3
F008BD60: 80a0c01d                 cmp     %g3, %i5
F008BD64: 12bfffeb                 bne     loc_F008BD10
F008BD68: 80a6a001                 cmp     %i2, 1
F008BD6C: 80a62000                 cmp     %i0, 0
F008BD70: 12800009                 bne     locret_F008BD94
F008BD74: b406a001                 inc     %i2
F008BD78: 80a6a003                 cmp     %i2, 3
F008BD7C: 04bfffdf                 ble     loc_F008BCF8
F008BD80: c6012364                 ld      [%g4+0x364], %g3
F008BD84: 30800004                 ba,a    locret_F008BD94
F008BD88: 12800003                 bne     locret_F008BD94
F008BD8C: 053c04c3                 sethi   %hi(dword_F0130F64), %g2
F008BD90: f000a364                 ld      [%g2+%lo(dword_F0130F64)], %i0
F008BD94: 81c7e008                 ret
F008BD98: 81e80000                 restore
