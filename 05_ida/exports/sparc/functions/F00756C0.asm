F00756C0: 9de3bf98                 save    %sp, -0x68, %sp
F00756C4: a0960000                 orcc    %i0, %g0, %l0
F00756C8: 02800006                 be      loc_F00756E0
F00756CC: 113c04d0                 sethi   %hi(_active_threads), %o0
F00756D0: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F00756D4: 80a40008                 cmp     %l0, %o0
F00756D8: 12800004                 bne     loc_F00756E8
F00756DC: 01000000                 nop
F00756E0: 1080000f                 ba      locret_F007571C
F00756E4: b0102004                 mov     4, %i0
F00756E8: 7ffffedd                 call    _thread_hold
F00756EC: 90100010                 mov     %l0, %o0
F00756F0: 90100010                 mov     %l0, %o0
F00756F4: 7ffffef2                 call    _thread_dowait
F00756F8: 92102001                 mov     1, %o1
F00756FC: 90100010                 mov     %l0, %o0
F0075700: 92100019                 mov     %i1, %o1
F0075704: 9410001a                 mov     %i2, %o2
F0075708: 400098d1                 call    _thread_setstatus
F007570C: 9610001b                 mov     %i3, %o3
F0075710: b0100008                 mov     %o0, %i0
F0075714: 7fffff48                 call    _thread_release
F0075718: 90100010                 mov     %l0, %o0
F007571C: 81c7e008                 ret
F0075720: 81e80000                 restore
