F00694BC: 9de3bf98                 save    %sp, -0x68, %sp
F00694C0: a0100018                 mov     %i0, %l0
F00694C4: b0042008                 add     %l0, 8, %i0
F00694C8: d0060000                 ld      [%i0], %o0
F00694CC: 80a22000                 cmp     %o0, 0
F00694D0: 12bffffe                 bne     loc_F00694C8
F00694D4: 01000000                 nop
F00694D8: 4000b674                 call    _simple_lock_try
F00694DC: 90100018                 mov     %i0, %o0
F00694E0: 80a22000                 cmp     %o0, 0
F00694E4: 02bffff9                 be      loc_F00694C8
F00694E8: 133c04d0                 sethi   %hi(_active_threads), %o1
F00694EC: d0040000                 ld      [%l0], %o0
F00694F0: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F00694F4: 80a20009                 cmp     %o0, %o1
F00694F8: 3280000c                 bne,a   loc_F0069528
F00694FC: d2042004                 ld      [%l0+4], %o1
F0069500: c0242008                 clr     [%l0+8]
F0069504: d0042004                 ld      [%l0+4], %o0
F0069508: b0102001                 mov     1, %i0
F006950C: 920a3000                 and     %o0, -0x1000, %o1
F0069510: 900a2fff                 and     %o0, 0xFFF, %o0
F0069514: 90022001                 inc     %o0
F0069518: 900a2fff                 and     %o0, 0xFFF, %o0
F006951C: 92124008                 bset    %o0, %o1
F0069520: 1080000d                 ba      locret_F0069554
F0069524: d2242004                 st      %o1, [%l0+4]
F0069528: 113ffff0                 sethi   -0x4000, %o0
F006952C: 808a4008                 btst    %o0, %o1
F0069530: 12800007                 bne     loc_F006954C
F0069534: 11000010                 sethi   0x4000, %o0
F0069538: 90124008                 bset    %o1, %o0
F006953C: d0242004                 st      %o0, [%l0+4]
F0069540: c0242008                 clr     [%l0+8]
F0069544: 10800004                 ba      locret_F0069554
F0069548: b0102001                 mov     1, %i0
F006954C: c0242008                 clr     [%l0+8]
F0069550: b0102000                 mov     0, %i0
F0069554: 81c7e008                 ret
F0069558: 81e80000                 restore
