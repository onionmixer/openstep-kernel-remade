F006A25C: 9de3bf98                 save    %sp, -0x68, %sp
F006A260: b6100018                 mov     %i0, %i3
F006A264: f406e010                 ld      [%i3+0x10], %i2
F006A268: 86102000                 mov     0, %g3
F006A26C: 80a0c01a                 cmp     %g3, %i2
F006A270: 1a80000a                 bcc     loc_F006A298
F006A274: b006e01c                 add     %i3, 0x1C, %i0
F006A278: 80a60019                 cmp     %i0, %i1
F006A27C: 22800008                 be,a    loc_F006A29C
F006A280: f206e010                 ld      [%i3+0x10], %i1
F006A284: 8600e001                 inc     %g3
F006A288: c4062004                 ld      [%i0+4], %g2
F006A28C: 80a0c01a                 cmp     %g3, %i2
F006A290: 0abffffa                 bcs     loc_F006A278
F006A294: b0060002                 add     %i0, %g2, %i0
F006A298: f206e010                 ld      [%i3+0x10], %i1
F006A29C: 80a0c019                 cmp     %g3, %i1
F006A2A0: 2280000e                 be,a    locret_F006A2D8
F006A2A4: b0102000                 mov     0, %i0
F006A2A8: c4062004                 ld      [%i0+4], %g2
F006A2AC: 1a80000a                 bcc     loc_F006A2D4
F006A2B0: b0060002                 add     %i0, %g2, %i0
F006A2B4: c4060000                 ld      [%i0], %g2
F006A2B8: 80a0a001                 cmp     %g2, 1
F006A2BC: 02800007                 be      locret_F006A2D8
F006A2C0: 8600e001                 inc     %g3
F006A2C4: c4062004                 ld      [%i0+4], %g2
F006A2C8: 80a0c019                 cmp     %g3, %i1
F006A2CC: 0abffffa                 bcs     loc_F006A2B4
F006A2D0: b0060002                 add     %i0, %g2, %i0
F006A2D4: b0102000                 mov     0, %i0
F006A2D8: 81c7e008                 ret
F006A2DC: 81e80000                 restore
