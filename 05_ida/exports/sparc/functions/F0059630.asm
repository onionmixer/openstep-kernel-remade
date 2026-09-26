F0059630: 9de3bf98                 save    %sp, -0x68, %sp
F0059634: d0060000                 ld      [%i0], %o0
F0059638: 80a22000                 cmp     %o0, 0
F005963C: 12bffffe                 bne     loc_F0059634
F0059640: 01000000                 nop
F0059644: 4000f619                 call    _simple_lock_try
F0059648: 90100018                 mov     %i0, %o0
F005964C: 80a22000                 cmp     %o0, 0
F0059650: 02bffff9                 be      loc_F0059634
F0059654: 01000000                 nop
F0059658: d0062004                 ld      [%i0+4], %o0
F005965C: 90022001                 inc     %o0
F0059660: d0262004                 st      %o0, [%i0+4]
F0059664: c0260000                 clr     [%i0]
F0059668: 81c7e008                 ret
F005966C: 81e80000                 restore
