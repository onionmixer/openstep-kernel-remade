F006A3C4: 9de3bf98                 save    %sp, -0x68, %sp
F006A3C8: c4062010                 ld      [%i0+0x10], %g2
F006A3CC: 8606201c                 add     %i0, 0x1C, %g3
F006A3D0: b0102000                 mov     0, %i0
F006A3D4: 80a60002                 cmp     %i0, %g2
F006A3D8: 1a80000d                 bcc     locret_F006A40C
F006A3DC: b2100002                 mov     %g2, %i1
F006A3E0: c400c000                 ld      [%g3], %g2
F006A3E4: 80a0a009                 cmp     %g2, 9
F006A3E8: 12800004                 bne     loc_F006A3F8
F006A3EC: b0062001                 inc     %i0
F006A3F0: 10800007                 ba      locret_F006A40C
F006A3F4: b0100003                 mov     %g3, %i0
F006A3F8: c400e004                 ld      [%g3+4], %g2
F006A3FC: 80a60019                 cmp     %i0, %i1
F006A400: 0abffff8                 bcs     loc_F006A3E0
F006A404: 8600c002                 add     %g3, %g2, %g3
F006A408: b0102000                 mov     0, %i0
F006A40C: 81c7e008                 ret
F006A410: 81e80000                 restore
