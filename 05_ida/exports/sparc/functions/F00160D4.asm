F00160D4: 9de3bf98                 save    %sp, -0x68, %sp
F00160D8: 80a62000                 cmp     %i0, 0
F00160DC: 32800006                 bne,a   loc_F00160F4
F00160E0: d0060000                 ld      [%i0], %o0
F00160E4: 113c042d                 sethi   %hi(aSelthreadclear), %o0! "selthreadclear not passed an address\n"
F00160E8: 7ffffc22                 call    _panic
F00160EC: 90122168                 bset    %lo(aSelthreadclear), %o0! "selthreadclear not passed an address\n"
F00160F0: d0060000                 ld      [%i0], %o0
F00160F4: 80a22000                 cmp     %o0, 0
F00160F8: 22800005                 be,a    locret_F001610C
F00160FC: c0260000                 clr     [%i0]
F0016100: 40017995                 call    _thread_deallocate_interrupt
F0016104: 01000000                 nop
F0016108: c0260000                 clr     [%i0]
F001610C: 81c7e008                 ret
F0016110: 81e80000                 restore
