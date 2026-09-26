F0072718: 9de3bf98                 save    %sp, -0x68, %sp
F007271C: 113c01c9                 sethi   %hi(_swtch_continue), %o0
F0072720: 7ffffc08                 call    _thread_block_with_continuation
F0072724: 901222d4                 bset    %lo(_swtch_continue), %o0
F0072728: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F007272C: d20221b0                 ld      [%o0+%lo(_processor_ptr)], %o1
F0072730: d0026108                 ld      [%o1+0x108], %o0
F0072734: 80a22000                 cmp     %o0, 0
F0072738: 14800007                 bg      loc_F0072754
F007273C: b0102000                 mov     0, %i0
F0072740: d002612c                 ld      [%o1+0x12C], %o0
F0072744: d0022108                 ld      [%o0+0x108], %o0
F0072748: 80a22000                 cmp     %o0, 0
F007274C: 04800003                 ble     locret_F0072758
F0072750: 01000000                 nop
F0072754: b0102001                 mov     1, %i0
F0072758: 81c7e008                 ret
F007275C: 81e80000                 restore
