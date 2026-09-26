F000C714: 9de3bf98                 save    %sp, -0x68, %sp
F000C718: 113c04cf                 sethi   %hi(_active_u), %o0
F000C71C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000C720: d0020000                 ld      [%o0], %o0
F000C724: 40000007                 call    _do_exit
F000C728: 92100018                 mov     %i0, %o1
F000C72C: 4001a225                 call    _thread_halt_self_with_continuation
F000C730: 90102000                 mov     0, %o0
F000C734: 30bffffe                 ba,a    loc_F000C72C
