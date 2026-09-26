F002C38C: 9de3bf98                 save    %sp, -0x68, %sp
F002C390: 4001aa41                 call    _splnet
F002C394: 01000000                 nop
F002C398: 133c04d8                 sethi   %hi(_netisr), %o1
F002C39C: d00263d8                 ld      [%o1+%lo(_netisr)], %o0
F002C3A0: 80a22000                 cmp     %o0, 0
F002C3A4: 02800015                 be      loc_F002C3F8
F002C3A8: 113c04d8                 sethi   -0xFECA000, %o0
F002C3AC: a0100009                 mov     %o1, %l0
F002C3B0: d00423d8                 ld      [%l0+0x3D8], %o0
F002C3B4: 808a2004                 btst    4, %o0
F002C3B8: 02800004                 be      loc_F002C3C8
F002C3BC: 900a3ffb                 and     %o0, -5, %o0
F002C3C0: 400016a4                 call    _ipintr
F002C3C4: d02423d8                 st      %o0, [%l0+0x3D8]
F002C3C8: d00423d8                 ld      [%l0+0x3D8], %o0
F002C3CC: 808a2001                 btst    1, %o0
F002C3D0: 02800007                 be      loc_F002C3EC
F002C3D4: 80a22000                 cmp     %o0, 0
F002C3D8: 900a3ffe                 and     %o0, -2, %o0
F002C3DC: 4000010a                 call    _rawintr
F002C3E0: d02423d8                 st      %o0, [%l0+0x3D8]
F002C3E4: d00423d8                 ld      [%l0+0x3D8], %o0
F002C3E8: 80a22000                 cmp     %o0, 0
F002C3EC: 32bffff2                 bne,a   loc_F002C3B4
F002C3F0: d00423d8                 ld      [%l0+0x3D8], %o0
F002C3F4: 113c04d8                 sethi   -0xFECA000, %o0
F002C3F8: 901223e0                 bset    0x3E0, %o0
F002C3FC: 40011236                 call    _assert_wait
F002C400: 92102000                 mov     0, %o1
F002C404: 113c00b0                 sethi   %hi(_netisr_thread_continue), %o0
F002C408: 400114ce                 call    _thread_block_with_continuation
F002C40C: 9012238c                 bset    %lo(_netisr_thread_continue), %o0
F002C410: 81c7e008                 ret
F002C414: 81e80000                 restore
