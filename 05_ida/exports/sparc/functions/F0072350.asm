F0072350: 9de3bf98                 save    %sp, -0x68, %sp
F0072354: 113c04d0                 sethi   %hi(_active_threads), %o0
F0072358: e2022260                 ld      [%o0+%lo(_active_threads)], %l1
F007235C: 40000715                 call    _stack_privilege
F0072360: 90100011                 mov     %l1, %o0
F0072364: 40009209                 call    _splusclock
F0072368: a0046020                 add     %l1, 0x20, %l0 ! ' '
F007236C: a4100008                 mov     %o0, %l2
F0072370: c0246050                 clr     [%l1+0x50]
F0072374: c0246058                 clr     [%l1+0x58]
F0072378: d0040000                 ld      [%l0], %o0
F007237C: 80a22000                 cmp     %o0, 0
F0072380: 12bffffe                 bne     loc_F0072378
F0072384: 01000000                 nop
F0072388: 400092c8                 call    _simple_lock_try
F007238C: 90100010                 mov     %l0, %o0
F0072390: 80a22000                 cmp     %o0, 0
F0072394: 02bffff9                 be      loc_F0072378
F0072398: 01000000                 nop
F007239C: d004604c                 ld      [%l1+0x4C], %o0
F00723A0: c0246020                 clr     [%l1+0x20]
F00723A4: 90122080                 bset    0x80, %o0
F00723A8: d024604c                 st      %o0, [%l1+0x4C]
F00723AC: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F00723B0: d20221b0                 ld      [%o0+%lo(_processor_ptr)], %o1
F00723B4: 90100012                 mov     %l2, %o0
F00723B8: 4000925b                 call    _splx
F00723BC: e222611c                 st      %l1, [%o1+0x11C]
F00723C0: 113c01c8                 sethi   %hi(_idle_thread_continue), %o0
F00723C4: 7ffffcdf                 call    _thread_block_with_continuation
F00723C8: 90122110                 bset    %lo(_idle_thread_continue), %o0
F00723CC: 7fffff51                 call    _idle_thread_continue
F00723D0: 01000000                 nop
F00723D4: 81c7e008                 ret
F00723D8: 81e80000                 restore
