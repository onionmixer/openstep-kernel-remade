F006A1D0: 9de3bf98                 save    %sp, -0x68, %sp
F006A1D4: c4062010                 ld      [%i0+0x10], %g2
F006A1D8: 8606201c                 add     %i0, 0x1C, %g3
F006A1DC: b0102000                 mov     0, %i0
F006A1E0: 80a60002                 cmp     %i0, %g2
F006A1E4: 1a80000d                 bcc     locret_F006A218
F006A1E8: b2100002                 mov     %g2, %i1
F006A1EC: c400c000                 ld      [%g3], %g2
F006A1F0: 80a0a001                 cmp     %g2, 1
F006A1F4: 12800004                 bne     loc_F006A204
F006A1F8: b0062001                 inc     %i0
F006A1FC: 10800007                 ba      locret_F006A218
F006A200: b0100003                 mov     %g3, %i0
F006A204: c400e004                 ld      [%g3+4], %g2
F006A208: 80a60019                 cmp     %i0, %i1
F006A20C: 0abffff8                 bcs     loc_F006A1EC
F006A210: 8600c002                 add     %g3, %g2, %g3
F006A214: b0102000                 mov     0, %i0
F006A218: 81c7e008                 ret
F006A21C: 81e80000                 restore
