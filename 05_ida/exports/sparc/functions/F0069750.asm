F0069750: 9de3bf98                 save    %sp, -0x68, %sp
F0069754: a0062008                 add     %i0, 8, %l0
F0069758: d0040000                 ld      [%l0], %o0
F006975C: 80a22000                 cmp     %o0, 0
F0069760: 12bffffe                 bne     loc_F0069758
F0069764: 01000000                 nop
F0069768: 4000b5d0                 call    _simple_lock_try
F006976C: 90100010                 mov     %l0, %o0
F0069770: 80a22000                 cmp     %o0, 0
F0069774: 02bffff9                 be      loc_F0069758
F0069778: 133c04d0                 sethi   %hi(_active_threads), %o1
F006977C: d0060000                 ld      [%i0], %o0
F0069780: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0069784: 80a20009                 cmp     %o0, %o1
F0069788: 02800004                 be      loc_F0069798
F006978C: 113c043e                 sethi   %hi(aLockClearRecur), %o0! "lock_clear_recursive: wrong thread"
F0069790: 7ffeae78                 call    _panic
F0069794: 901223b8                 bset    %lo(aLockClearRecur), %o0! "lock_clear_recursive: wrong thread"
F0069798: d0062004                 ld      [%i0+4], %o0
F006979C: 808a2fff                 btst    0xFFF, %o0
F00697A0: 12800003                 bne     loc_F00697AC
F00697A4: 90103fff                 mov     -1, %o0
F00697A8: d0260000                 st      %o0, [%i0]
F00697AC: c0262008                 clr     [%i0+8]
F00697B0: 81c7e008                 ret
F00697B4: 81e80000                 restore
