F00717A4: 9de3bf98                 save    %sp, -0x68, %sp
F00717A8: 113c04d0                 sethi   %hi(_active_threads), %o0
F00717AC: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F00717B0: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F00717B4: 400094f5                 call    _splusclock
F00717B8: e00221b0                 ld      [%o0+%lo(_processor_ptr)], %l0
F00717BC: a4100008                 mov     %o0, %l2
F00717C0: 90100011                 mov     %l1, %o0
F00717C4: 92100018                 mov     %i0, %o1
F00717C8: 7fffff08                 call    _thread_invoke
F00717CC: 94100019                 mov     %i1, %o2
F00717D0: 80a22000                 cmp     %o0, 0
F00717D4: 12800006                 bne     loc_F00717EC
F00717D8: 01000000                 nop
F00717DC: 7ffffe94                 call    _thread_select
F00717E0: 90100010                 mov     %l0, %o0
F00717E4: 10bffff7                 ba      loc_F00717C0
F00717E8: b2100008                 mov     %o0, %i1
F00717EC: 4000954e                 call    _splx
F00717F0: 90100012                 mov     %l2, %o0
F00717F4: 81c7e008                 ret
F00717F8: 81e80000                 restore
