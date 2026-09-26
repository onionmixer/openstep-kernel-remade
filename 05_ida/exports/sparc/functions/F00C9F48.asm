F00C9F48: 9de3bf90                 save    %sp, -0x70, %sp
F00C9F4C: e2062004                 ld      [%i0+4], %l1
F00C9F50: e0044000                 ld      [%l1], %l0
F00C9F54: d0040000                 ld      [%l0], %o0
F00C9F58: 80a22000                 cmp     %o0, 0
F00C9F5C: 12bffffe                 bne     loc_F00C9F54
F00C9F60: 01000000                 nop
F00C9F64: 7fff33d1                 call    _simple_lock_try
F00C9F68: 90100010                 mov     %l0, %o0
F00C9F6C: 80a22000                 cmp     %o0, 0
F00C9F70: 02bffff9                 be      loc_F00C9F54
F00C9F74: 90046008                 add     %l1, 8, %o0
F00C9F78: f4246008                 st      %i2, [%l1+8]
F00C9F7C: d2044000                 ld      [%l1], %o1
F00C9F80: 94102000                 mov     0, %o2
F00C9F84: c0224000                 clr     [%o1]
F00C9F88: 7ffe9c1d                 call    _thread_wakeup_prim
F00C9F8C: 92102001                 mov     1, %o1
F00C9F90: 7ffe7c29                 call    _lock_done
F00C9F94: d0046004                 ld      [%l1+4], %o0
F00C9F98: 81c7e008                 ret
F00C9F9C: 81e80000                 restore
