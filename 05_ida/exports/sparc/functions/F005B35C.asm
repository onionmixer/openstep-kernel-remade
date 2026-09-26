F005B35C: 9de3bf98                 save    %sp, -0x68, %sp
F005B360: d0060000                 ld      [%i0], %o0
F005B364: 80a22000                 cmp     %o0, 0
F005B368: 12bffffe                 bne     loc_F005B360
F005B36C: 01000000                 nop
F005B370: 4000eece                 call    _simple_lock_try
F005B374: 90100018                 mov     %i0, %o0
F005B378: 80a22000                 cmp     %o0, 0
F005B37C: 02bffff9                 be      loc_F005B360
F005B380: 01000000                 nop
F005B384: c0262010                 clr     [%i0+0x10]
F005B388: c026200c                 clr     [%i0+0xC]
F005B38C: 7ffffd67                 call    _ipc_port_clear_receiver
F005B390: 90100018                 mov     %i0, %o0
F005B394: 7ffffe00                 call    _ipc_port_destroy
F005B398: 90100018                 mov     %i0, %o0
F005B39C: 81c7e008                 ret
F005B3A0: 81e80000                 restore
