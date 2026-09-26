F00841C0: 9de3bf98                 save    %sp, -0x68, %sp
F00841C4: 80a62000                 cmp     %i0, 0
F00841C8: 0280000f                 be      locret_F0084204
F00841CC: a0062034                 add     %i0, 0x34, %l0 ! '4'
F00841D0: d0040000                 ld      [%l0], %o0
F00841D4: 80a22000                 cmp     %o0, 0
F00841D8: 12bffffe                 bne     loc_F00841D0
F00841DC: 01000000                 nop
F00841E0: 40004b32                 call    _simple_lock_try
F00841E4: 90100010                 mov     %l0, %o0
F00841E8: 80a22000                 cmp     %o0, 0
F00841EC: 02bffff9                 be      loc_F00841D0
F00841F0: 01000000                 nop
F00841F4: d0062030                 ld      [%i0+0x30], %o0
F00841F8: c0262034                 clr     [%i0+0x34]
F00841FC: 90022001                 inc     %o0
F0084200: d0262030                 st      %o0, [%i0+0x30]
F0084204: 81c7e008                 ret
F0084208: 81e80000                 restore
