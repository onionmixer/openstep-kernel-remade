F0070C30: 9de3bf98                 save    %sp, -0x68, %sp
F0070C34: 113c04d0                 sethi   %hi(_active_threads), %o0
F0070C38: 400097d4                 call    _splusclock
F0070C3C: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F0070C40: a4100008                 mov     %o0, %l2
F0070C44: a0046020                 add     %l1, 0x20, %l0 ! ' '
F0070C48: d0040000                 ld      [%l0], %o0
F0070C4C: 80a22000                 cmp     %o0, 0
F0070C50: 12bffffe                 bne     loc_F0070C48
F0070C54: 01000000                 nop
F0070C58: 40009894                 call    _simple_lock_try
F0070C5C: 90100010                 mov     %l0, %o0
F0070C60: 80a22000                 cmp     %o0, 0
F0070C64: 02bffff9                 be      loc_F0070C48
F0070C68: 01000000                 nop
F0070C6C: d004604c                 ld      [%l1+0x4C], %o0
F0070C70: 808a2001                 btst    1, %o0
F0070C74: 02800004                 be      loc_F0070C84
F0070C78: 90046118                 add     %l1, 0x118, %o0
F0070C7C: 7fffe355                 call    _set_timeout
F0070C80: 92100018                 mov     %i0, %o1
F0070C84: c0246020                 clr     [%l1+0x20]
F0070C88: 40009827                 call    _splx
F0070C8C: 90100012                 mov     %l2, %o0
F0070C90: 81c7e008                 ret
F0070C94: 81e80000                 restore
