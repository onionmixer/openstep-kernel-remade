F00A32B0: 9de3bf98                 save    %sp, -0x68, %sp
F00A32B4: d0060000                 ld      [%i0], %o0
F00A32B8: 80a22000                 cmp     %o0, 0
F00A32BC: 12bffffe                 bne     loc_F00A32B4
F00A32C0: 01000000                 nop
F00A32C4: 7fffcef9                 call    _simple_lock_try
F00A32C8: 90100018                 mov     %i0, %o0
F00A32CC: 80a22000                 cmp     %o0, 0
F00A32D0: 02bffff9                 be      loc_F00A32B4
F00A32D4: 01000000                 nop
F00A32D8: 81c7e008                 ret
F00A32DC: 81e80000                 restore
