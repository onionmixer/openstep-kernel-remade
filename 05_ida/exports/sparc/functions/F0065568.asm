F0065568: 9de3bf98                 save    %sp, -0x68, %sp
F006556C: a0062158                 add     %i0, 0x158, %l0
F0065570: d0040000                 ld      [%l0], %o0
F0065574: 80a22000                 cmp     %o0, 0
F0065578: 12bffffe                 bne     loc_F0065570
F006557C: 01000000                 nop
F0065580: 4000c64a                 call    _simple_lock_try
F0065584: 90100010                 mov     %l0, %o0
F0065588: 80a22000                 cmp     %o0, 0
F006558C: 02bffff9                 be      loc_F0065570
F0065590: 01000000                 nop
F0065594: d0062154                 ld      [%i0+0x154], %o0
F0065598: 80a22000                 cmp     %o0, 0
F006559C: 02800005                 be      loc_F00655B0
F00655A0: a0102000                 mov     0, %l0
F00655A4: 7fffd690                 call    _ipc_port_make_send
F00655A8: d0062160                 ld      [%i0+0x160], %o0
F00655AC: a0100008                 mov     %o0, %l0
F00655B0: c0262158                 clr     [%i0+0x158]
F00655B4: 400026e1                 call    _pset_deallocate
F00655B8: 90100018                 mov     %i0, %o0
F00655BC: 81c7e008                 ret
F00655C0: 91e80010                 restore %g0, %l0, %o0
