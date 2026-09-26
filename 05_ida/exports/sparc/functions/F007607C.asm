F007607C: 9de3bf98                 save    %sp, -0x68, %sp
F0076080: 113c0442                 sethi   %hi(_stack_check_usage), %o0
F0076084: d0022290                 ld      [%o0+%lo(_stack_check_usage)], %o0
F0076088: 80a22000                 cmp     %o0, 0
F007608C: 02800016                 be      locret_F00760E4
F0076090: 01000000                 nop
F0076094: 7fffffd7                 call    _stack_usage
F0076098: 90100018                 mov     %i0, %o0
F007609C: a0100008                 mov     %o0, %l0
F00760A0: 113c04f2b0122170         set     _stack_usage_lock, %i0
F00760A8: d0060000                 ld      [%i0], %o0
F00760AC: 80a22000                 cmp     %o0, 0
F00760B0: 12bffffe                 bne     loc_F00760A8
F00760B4: 01000000                 nop
F00760B8: 4000837c                 call    _simple_lock_try
F00760BC: 90100018                 mov     %i0, %o0
F00760C0: 80a22000                 cmp     %o0, 0
F00760C4: 02bffff9                 be      loc_F00760A8
F00760C8: 133c0442                 sethi   %hi(_stack_max_usage), %o1
F00760CC: d0026294                 ld      [%o1+%lo(_stack_max_usage)], %o0
F00760D0: 80a40008                 cmp     %l0, %o0
F00760D4: 38800002                 bgu,a   loc_F00760DC
F00760D8: e0226294                 st      %l0, [%o1+%lo(_stack_max_usage)]
F00760DC: 113c04f2                 sethi   %hi(_stack_usage_lock), %o0
F00760E0: c0222170                 clr     [%o0+%lo(_stack_usage_lock)]
F00760E4: 81c7e008                 ret
F00760E8: 81e80000                 restore
