F005AFE4: 9de3bf98                 save    %sp, -0x68, %sp
F005AFE8: d0060000                 ld      [%i0], %o0
F005AFEC: 80a22000                 cmp     %o0, 0
F005AFF0: 12bffffe                 bne     loc_F005AFE8
F005AFF4: 01000000                 nop
F005AFF8: 4000efac                 call    _simple_lock_try
F005AFFC: 90100018                 mov     %i0, %o0
F005B000: 80a22000                 cmp     %o0, 0
F005B004: 02bffff9                 be      loc_F005AFE8
F005B008: 01000000                 nop
F005B00C: d0062018                 ld      [%i0+0x18], %o0
F005B010: d206201c                 ld      [%i0+0x1C], %o1
F005B014: 90022001                 inc     %o0
F005B018: d0262018                 st      %o0, [%i0+0x18]
F005B01C: 92026001                 inc     %o1
F005B020: d226201c                 st      %o1, [%i0+0x1C]
F005B024: d0062004                 ld      [%i0+4], %o0
F005B028: 90022001                 inc     %o0
F005B02C: d0262004                 st      %o0, [%i0+4]
F005B030: c0260000                 clr     [%i0]
F005B034: 81c7e008                 ret
F005B038: 81e80000                 restore
