F009C0A8: 9de3bf98                 save    %sp, -0x68, %sp
F009C0AC: c4062020                 ld      [%i0+0x20], %g2
F009C0B0: 80a6a000                 cmp     %i2, 0
F009C0B4: 8400a001                 inc     %g2
F009C0B8: 02800005                 be      locret_F009C0CC
F009C0BC: c4262020                 st      %g2, [%i0+0x20]
F009C0C0: c4062024                 ld      [%i0+0x24], %g2
F009C0C4: 8400a001                 inc     %g2
F009C0C8: c4262024                 st      %g2, [%i0+0x24]
F009C0CC: 81c7e008                 ret
F009C0D0: 81e80000                 restore
