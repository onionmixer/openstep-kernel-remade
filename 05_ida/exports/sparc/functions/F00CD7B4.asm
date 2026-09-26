F00CD7B4: 9de3bf90                 save    %sp, -0x70, %sp
F00CD7B8: c6062128                 ld      [%i0+0x128], %g3
F00CD7BC: b0062128                 inc     0x128, %i0
F00CD7C0: 80a60003                 cmp     %i0, %g3
F00CD7C4: 22800018                 be,a    locret_F00CD824
F00CD7C8: b0102000                 mov     0, %i0
F00CD7CC: c400c000                 ld      [%g3], %g2
F00CD7D0: 80a0801a                 cmp     %g2, %i2
F00CD7D4: 32800010                 bne,a   loc_F00CD814
F00CD7D8: c600e014                 ld      [%g3+0x14], %g3
F00CD7DC: c400e004                 ld      [%g3+4], %g2
F00CD7E0: 80a0801b                 cmp     %g2, %i3
F00CD7E4: 3280000c                 bne,a   loc_F00CD814
F00CD7E8: c600e014                 ld      [%g3+0x14], %g3
F00CD7EC: c400e008                 ld      [%g3+8], %g2
F00CD7F0: 80a0801c                 cmp     %g2, %i4
F00CD7F4: 32800008                 bne,a   loc_F00CD814
F00CD7F8: c600e014                 ld      [%g3+0x14], %g3
F00CD7FC: c400e00c                 ld      [%g3+0xC], %g2
F00CD800: 80a0801d                 cmp     %g2, %i5
F00CD804: 32800004                 bne,a   loc_F00CD814
F00CD808: c600e014                 ld      [%g3+0x14], %g3
F00CD80C: 10800006                 ba      locret_F00CD824
F00CD810: b0100003                 mov     %g3, %i0
F00CD814: 80a60003                 cmp     %i0, %g3
F00CD818: 32bfffee                 bne,a   loc_F00CD7D0
F00CD81C: c400c000                 ld      [%g3], %g2
F00CD820: b0102000                 mov     0, %i0
F00CD824: 81c7e008                 ret
F00CD828: 81e80000                 restore
