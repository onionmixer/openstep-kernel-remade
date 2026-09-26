F00B117C: 9de3bf98                 save    %sp, -0x68, %sp
F00B1180: ba100018                 mov     %i0, %i5
F00B1184: 053c04fb                 sethi   %hi(_dkn), %g2
F00B1188: f400a220                 ld      [%g2+%lo(_dkn)], %i2
F00B118C: 86102000                 mov     0, %g3
F00B1190: 80a0c01a                 cmp     %g3, %i2
F00B1194: 16800013                 bge     loc_F00B11E0
F00B1198: b0103fff                 mov     -1, %i0
F00B119C: 053c04fbb810a0a0         set     _dk_ivec, %i4
F00B11A4: b610001a                 mov     %i2, %i3
F00B11A8: b4102000                 mov     0, %i2
F00B11AC: c406801c                 ld      [%i2+%i4], %g2
F00B11B0: 80a0a000                 cmp     %g2, 0
F00B11B4: 2280000b                 be,a    loc_F00B11E0
F00B11B8: b0100003                 mov     %g3, %i0
F00B11BC: c4488000                 ldsb    [%g2], %g2
F00B11C0: 80a0a000                 cmp     %g2, 0
F00B11C4: 32800004                 bne,a   loc_F00B11D4
F00B11C8: 8600e001                 inc     %g3
F00B11CC: 10800005                 ba      loc_F00B11E0
F00B11D0: b0100003                 mov     %g3, %i0
F00B11D4: 80a0c01b                 cmp     %g3, %i3
F00B11D8: 06bffff5                 bl      loc_F00B11AC
F00B11DC: b406a008                 inc     8, %i2
F00B11E0: 80a62000                 cmp     %i0, 0
F00B11E4: 1680000b                 bge     loc_F00B1210
F00B11E8: 073c04fb                 sethi   -0xFEC1400, %g3
F00B11EC: 073c04fb                 sethi   %hi(_dkn), %g3
F00B11F0: f000e220                 ld      [%g3+%lo(_dkn)], %i0
F00B11F4: 80a6201f                 cmp     %i0, 0x1F
F00B11F8: 04800004                 ble     loc_F00B1208
F00B11FC: 84062001                 add     %i0, 1, %g2
F00B1200: 10800009                 ba      locret_F00B1224
F00B1204: b0103fff                 mov     -1, %i0
F00B1208: c420e220                 st      %g2, [%g3+0x220]
F00B120C: 073c04fb                 sethi   -0xFEC1400, %g3
F00B1210: 8610e0a0                 bset    0xA0, %g3
F00B1214: 852e2003                 sll     %i0, 3, %g2
F00B1218: fa208003                 st      %i5, [%g2+%g3]
F00B121C: 84008003                 add     %g2, %g3, %g2
F00B1220: f230a004                 sth     %i1, [%g2+4]
F00B1224: 81c7e008                 ret
F00B1228: 81e80000                 restore
