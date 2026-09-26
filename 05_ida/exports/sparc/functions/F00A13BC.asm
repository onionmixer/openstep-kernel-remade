F00A13BC: 9de3bf98                 save    %sp, -0x68, %sp
F00A13C0: 073c04f78610e270         set     _pmap_info, %g3
F00A13C8: c400e0b4                 ld      [%g3+0xB4], %g2
F00A13CC: 8400a001                 inc     %g2
F00A13D0: c420e0b4                 st      %g2, [%g3+0xB4]
F00A13D4: c4060000                 ld      [%i0], %g2
F00A13D8: 80a60002                 cmp     %i0, %g2
F00A13DC: 32800003                 bne,a   loc_F00A13E8
F00A13E0: f220a010                 st      %i1, [%g2+0x10]
F00A13E4: f2262004                 st      %i1, [%i0+4]
F00A13E8: c426600c                 st      %g2, [%i1+0xC]
F00A13EC: f0266010                 st      %i0, [%i1+0x10]
F00A13F0: f2260000                 st      %i1, [%i0]
F00A13F4: c4062008                 ld      [%i0+8], %g2
F00A13F8: 8400a001                 inc     %g2
F00A13FC: c4262008                 st      %g2, [%i0+8]
F00A1400: 81c7e008                 ret
F00A1404: 81e80000                 restore
