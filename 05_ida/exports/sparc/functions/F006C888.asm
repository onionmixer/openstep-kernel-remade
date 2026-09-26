F006C888: 9de3bf98                 save    %sp, -0x68, %sp
F006C88C: 113c04f0a0122210         set     _vm_info_lock_data, %l0
F006C894: d0040000                 ld      [%l0], %o0
F006C898: 80a22000                 cmp     %o0, 0
F006C89C: 12bffffe                 bne     loc_F006C894
F006C8A0: 01000000                 nop
F006C8A4: 4000a981                 call    _simple_lock_try
F006C8A8: 90100010                 mov     %l0, %o0
F006C8AC: 80a22000                 cmp     %o0, 0
F006C8B0: 02bffff9                 be      loc_F006C894
F006C8B4: 01000000                 nop
F006C8B8: d0062038                 ld      [%i0+0x38], %o0
F006C8BC: 80a22000                 cmp     %o0, 0
F006C8C0: 36800005                 bge,a   loc_F006C8D4
F006C8C4: d2162006                 lduh    [%i0+6], %o1
F006C8C8: 7ffffe6d                 call    _vm_info_dequeue
F006C8CC: 90100018                 mov     %i0, %o0
F006C8D0: d2162006                 lduh    [%i0+6], %o1
F006C8D4: 92026001                 inc     %o1
F006C8D8: d2362006                 sth     %o1, [%i0+6]
F006C8DC: 133c04f0                 sethi   %hi(_vm_info_lock_data), %o1
F006C8E0: c0226210                 clr     [%o1+%lo(_vm_info_lock_data)]
F006C8E4: 7ffff138                 call    _lock_write
F006C8E8: 90062018                 add     %i0, 0x18, %o0
F006C8EC: 81c7e008                 ret
F006C8F0: 81e80000                 restore
