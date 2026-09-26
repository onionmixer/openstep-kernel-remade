F00CA2A8: 9de3bf98                 save    %sp, -0x68, %sp
F00CA2AC: 80a66001                 cmp     %i1, 1
F00CA2B0: 02800008                 be      loc_F00CA2D0
F00CA2B4: 90100018                 mov     %i0, %o0
F00CA2B8: 80a66001                 cmp     %i1, 1
F00CA2BC: 0a800007                 bcs     loc_F00CA2D8
F00CA2C0: 80a66002                 cmp     %i1, 2
F00CA2C4: 02800007                 be      loc_F00CA2E0
F00CA2C8: 80a6a001                 cmp     %i2, 1
F00CA2CC: 30800010                 ba,a    loc_F00CA30C
F00CA2D0: 7fff08b3                 call    __io_get_kern_port
F00CA2D4: 01000000                 nop
F00CA2D8: 1080000c                 ba      loc_F00CA308
F00CA2DC: 92100008                 mov     %o0, %o1
F00CA2E0: 7fff08bd                 call    __io_convert_port_in
F00CA2E4: 01000000                 nop
F00CA2E8: 92920000                 orcc    %o0, %g0, %o1
F00CA2EC: 12800008                 bne     loc_F00CA30C
F00CA2F0: 80a6a001                 cmp     %i2, 1
F00CA2F4: 113c03ec                 sethi   %hi(aIoconvertportB), %o0! "IOConvertPort: Bad Port\n"
F00CA2F8: 7fffef7f                 call    _IOLog
F00CA2FC: 90122068                 bset    %lo(aIoconvertportB), %o0! "IOConvertPort: Bad Port\n"
F00CA300: 10800014                 ba      locret_F00CA350
F00CA304: b0102000                 mov     0, %i0
F00CA308: 80a6a001                 cmp     %i2, 1
F00CA30C: 02800009                 be      loc_F00CA330
F00CA310: 80a6a001                 cmp     %i2, 1
F00CA314: 0a800005                 bcs     loc_F00CA328
F00CA318: 80a6a002                 cmp     %i2, 2
F00CA31C: 02800009                 be      loc_F00CA340
F00CA320: b0100010                 mov     %l0, %i0
F00CA324: 3080000b                 ba,a    locret_F00CA350
F00CA328: 10800009                 ba      loc_F00CA34C
F00CA32C: a0100009                 mov     %o1, %l0
F00CA330: 7fff088f                 call    __io_task_get_port
F00CA334: 90100009                 mov     %o1, %o0
F00CA338: 10800005                 ba      loc_F00CA34C
F00CA33C: a0100008                 mov     %o0, %l0
F00CA340: 7fff08b4                 call    __io_convert_port_out
F00CA344: 90100009                 mov     %o1, %o0
F00CA348: a0100008                 mov     %o0, %l0
F00CA34C: b0100010                 mov     %l0, %i0
F00CA350: 81c7e008                 ret
F00CA354: 81e80000                 restore
