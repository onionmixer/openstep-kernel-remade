F006955C: 9de3bf98                 save    %sp, -0x68, %sp
F0069560: a0100018                 mov     %i0, %l0
F0069564: b0042008                 add     %l0, 8, %i0
F0069568: d0060000                 ld      [%i0], %o0
F006956C: 80a22000                 cmp     %o0, 0
F0069570: 12bffffe                 bne     loc_F0069568
F0069574: 01000000                 nop
F0069578: 4000b64c                 call    _simple_lock_try
F006957C: 90100018                 mov     %i0, %o0
F0069580: 80a22000                 cmp     %o0, 0
F0069584: 02bffff9                 be      loc_F0069568
F0069588: 133c04d0                 sethi   %hi(_active_threads), %o1
F006958C: d0040000                 ld      [%l0], %o0
F0069590: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0069594: 80a20009                 cmp     %o0, %o1
F0069598: 02800006                 be      loc_F00695B0
F006959C: 11000030                 sethi   0xC000, %o0
F00695A0: d2042004                 ld      [%l0+4], %o1
F00695A4: 808a4008                 btst    %o0, %o1
F00695A8: 12800008                 bne     loc_F00695C8
F00695AC: 01000000                 nop
F00695B0: c0242008                 clr     [%l0+8]
F00695B4: d0142004                 lduh    [%l0+4], %o0
F00695B8: b0102001                 mov     1, %i0
F00695BC: 90022001                 inc     %o0
F00695C0: 10800004                 ba      locret_F00695D0
F00695C4: d0342004                 sth     %o0, [%l0+4]
F00695C8: c0242008                 clr     [%l0+8]
F00695CC: b0102000                 mov     0, %i0
F00695D0: 81c7e008                 ret
F00695D4: 81e80000                 restore
