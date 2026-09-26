F0067A7C: 9de3bf98                 save    %sp, -0x68, %sp
F0067A80: 80a62000                 cmp     %i0, 0
F0067A84: 0280001c                 be      locret_F0067AF4
F0067A88: a0102000                 mov     0, %l0
F0067A8C: 80a63fff                 cmp     %i0, -1
F0067A90: 02800019                 be      locret_F0067AF4
F0067A94: 01000000                 nop
F0067A98: d0060000                 ld      [%i0], %o0
F0067A9C: 80a22000                 cmp     %o0, 0
F0067AA0: 12bffffe                 bne     loc_F0067A98
F0067AA4: 01000000                 nop
F0067AA8: 4000bd00                 call    _simple_lock_try
F0067AAC: 90100018                 mov     %i0, %o0
F0067AB0: 80a22000                 cmp     %o0, 0
F0067AB4: 02bffff9                 be      loc_F0067A98
F0067AB8: 01000000                 nop
F0067ABC: d2062008                 ld      [%i0+8], %o1
F0067AC0: 80a26000                 cmp     %o1, 0
F0067AC4: 1680000b                 bge     loc_F0067AF0
F0067AC8: 01000000                 nop
F0067ACC: 1100003f901223ff         set     0xFFFF, %o0
F0067AD4: 900a4008                 and     %o1, %o0, %o0
F0067AD8: 80a22001                 cmp     %o0, 1
F0067ADC: 12800005                 bne     loc_F0067AF0
F0067AE0: 01000000                 nop
F0067AE4: e0062014                 ld      [%i0+0x14], %l0
F0067AE8: 40003353                 call    _thread_reference
F0067AEC: 90100010                 mov     %l0, %o0
F0067AF0: c0260000                 clr     [%i0]
F0067AF4: 81c7e008                 ret
F0067AF8: 91e80010                 restore %g0, %l0, %o0
