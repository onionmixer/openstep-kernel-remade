F007361C: 9de3bf98                 save    %sp, -0x68, %sp
F0073620: a6102000                 mov     0, %l3
F0073624: 113c04d0                 sethi   %hi(_active_threads), %o0
F0073628: e8022260                 ld      [%o0+%lo(_active_threads)], %l4
F007362C: a406201c                 add     %i0, 0x1C, %l2
F0073630: a2102000                 mov     0, %l1
F0073634: d0060000                 ld      [%i0], %o0
F0073638: 80a22000                 cmp     %o0, 0
F007363C: 12bffffe                 bne     loc_F0073634
F0073640: 01000000                 nop
F0073644: 40008e19                 call    _simple_lock_try
F0073648: 90100018                 mov     %i0, %o0
F007364C: 80a22000                 cmp     %o0, 0
F0073650: 02bffff9                 be      loc_F0073634
F0073654: 01000000                 nop
F0073658: e0048000                 ld      [%l2], %l0
F007365C: 80a48010                 cmp     %l2, %l0
F0073660: 02800026                 be      loc_F00736F8
F0073664: 01000000                 nop
F0073668: d0062008                 ld      [%i0+8], %o0
F007366C: 80a22000                 cmp     %o0, 0
F0073670: 12800007                 bne     loc_F007368C
F0073674: 80a40014                 cmp     %l0, %l4
F0073678: 80a66000                 cmp     %i1, 0
F007367C: 12800004                 bne     loc_F007368C
F0073680: 80a40014                 cmp     %l0, %l4
F0073684: 1080001d                 ba      loc_F00736F8
F0073688: a6102005                 mov     5, %l3
F007368C: 22800018                 be,a    loc_F00736EC
F0073690: e0042010                 ld      [%l0+0x10], %l0
F0073694: 40000468                 call    _thread_reference
F0073698: 90100010                 mov     %l0, %o0
F007369C: c0260000                 clr     [%i0]
F00736A0: 80a46000                 cmp     %l1, 0
F00736A4: 02800005                 be      loc_F00736B8
F00736A8: 90100010                 mov     %l0, %o0
F00736AC: 40000340                 call    _thread_deallocate
F00736B0: 90100011                 mov     %l1, %o0
F00736B4: 90100010                 mov     %l0, %o0
F00736B8: 40000701                 call    _thread_dowait
F00736BC: 92102001                 mov     1, %o1
F00736C0: a2100010                 mov     %l0, %l1
F00736C4: d0060000                 ld      [%i0], %o0
F00736C8: 80a22000                 cmp     %o0, 0
F00736CC: 12bffffe                 bne     loc_F00736C4
F00736D0: 01000000                 nop
F00736D4: 40008df5                 call    _simple_lock_try
F00736D8: 90100018                 mov     %i0, %o0
F00736DC: 80a22000                 cmp     %o0, 0
F00736E0: 02bffff9                 be      loc_F00736C4
F00736E4: 01000000                 nop
F00736E8: e0042010                 ld      [%l0+0x10], %l0
F00736EC: 80a48010                 cmp     %l2, %l0
F00736F0: 32bfffdf                 bne,a   loc_F007366C
F00736F4: d0062008                 ld      [%i0+8], %o0
F00736F8: c0260000                 clr     [%i0]
F00736FC: 80a46000                 cmp     %l1, 0
F0073700: 02800004                 be      locret_F0073710
F0073704: 01000000                 nop
F0073708: 40000329                 call    _thread_deallocate
F007370C: 90100011                 mov     %l1, %o0
F0073710: 81c7e008                 ret
F0073714: 91e80013                 restore %g0, %l3, %o0
