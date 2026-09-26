F0094AE4: 7ffdc106                 call    _flush_user_windows
F0094AE8: 01000000                 nop
F0094AEC: 7ffdc0f8                 call    _reset_windows
F0094AF0: 01000000                 nop
F0094AF4: bc100000                 clr     %fp
F0094AF8: 213c0428a0142024         set     _active_pcb, %l0
F0094B00: e0040000                 ld      [%l0], %l0
F0094B04: 9fc20000                 call    %o0
F0094B08: dc0422a0                 ld      [%l0+0x2A0], %sp
F0094B0C: 00000000                 illtrap
