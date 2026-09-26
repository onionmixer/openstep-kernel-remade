F006550C: 9de3bf98                 save    %sp, -0x68, %sp
F0065510: a0062158                 add     %i0, 0x158, %l0
F0065514: d0040000                 ld      [%l0], %o0
F0065518: 80a22000                 cmp     %o0, 0
F006551C: 12bffffe                 bne     loc_F0065514
F0065520: 01000000                 nop
F0065524: 4000c661                 call    _simple_lock_try
F0065528: 90100010                 mov     %l0, %o0
F006552C: 80a22000                 cmp     %o0, 0
F0065530: 02bffff9                 be      loc_F0065514
F0065534: 01000000                 nop
F0065538: d0062154                 ld      [%i0+0x154], %o0
F006553C: 80a22000                 cmp     %o0, 0
F0065540: 02800005                 be      loc_F0065554
F0065544: a0102000                 mov     0, %l0
F0065548: 7fffd6a7                 call    _ipc_port_make_send
F006554C: d006215c                 ld      [%i0+0x15C], %o0
F0065550: a0100008                 mov     %o0, %l0
F0065554: c0262158                 clr     [%i0+0x158]
F0065558: 400026f8                 call    _pset_deallocate
F006555C: 90100018                 mov     %i0, %o0
F0065560: 81c7e008                 ret
F0065564: 91e80010                 restore %g0, %l0, %o0
