F001B1C0: 9de3bf98                 save    %sp, -0x68, %sp
F001B1C4: 113c04d4901222a0         set     _pty_alloc_lock, %o0
F001B1CC: 400136cf                 call    _lock_init
F001B1D0: 92102001                 mov     1, %o1
F001B1D4: 81c7e008                 ret
F001B1D8: 81e80000                 restore
