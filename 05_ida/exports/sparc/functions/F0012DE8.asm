F0012DE8: 9de3bf98                 save    %sp, -0x68, %sp
F0012DEC: 40020f67                 call    _splusclock
F0012DF0: 01000000                 nop
F0012DF4: a0100008                 mov     %o0, %l0
F0012DF8: 90100018                 mov     %i0, %o0
F0012DFC: 92102000                 mov     0, %o1
F0012E00: 4001787f                 call    _thread_wakeup_prim
F0012E04: 94102000                 mov     0, %o2
F0012E08: 40020fc7                 call    _splx
F0012E0C: 90100010                 mov     %l0, %o0
F0012E10: 81c7e008                 ret
F0012E14: 81e80000                 restore
