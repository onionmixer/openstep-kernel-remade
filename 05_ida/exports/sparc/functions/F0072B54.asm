F0072B54: 9de3bf98                 save    %sp, -0x68, %sp
F0072B58: 80a62000                 cmp     %i0, 0
F0072B5C: 12800004                 bne     loc_F0072B6C
F0072B60: 01000000                 nop
F0072B64: 10800023                 ba      locret_F0072BF0
F0072B68: b0102004                 mov     4, %i0
F0072B6C: 40009007                 call    _splusclock
F0072B70: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0072B74: a2100008                 mov     %o0, %l1
F0072B78: d0040000                 ld      [%l0], %o0
F0072B7C: 80a22000                 cmp     %o0, 0
F0072B80: 12bffffe                 bne     loc_F0072B78
F0072B84: 01000000                 nop
F0072B88: 400090c8                 call    _simple_lock_try
F0072B8C: 90100010                 mov     %l0, %o0
F0072B90: 80a22000                 cmp     %o0, 0
F0072B94: 02bffff9                 be      loc_F0072B78
F0072B98: 01000000                 nop
F0072B9C: d0062064                 ld      [%i0+0x64], %o0
F0072BA0: 80a22000                 cmp     %o0, 0
F0072BA4: 0680000f                 bl      loc_F0072BE0
F0072BA8: 01000000                 nop
F0072BAC: d0062184                 ld      [%i0+0x184], %o0
F0072BB0: 80a22000                 cmp     %o0, 0
F0072BB4: 22800005                 be,a    loc_F0072BC8
F0072BB8: d2062064                 ld      [%i0+0x64], %o1
F0072BBC: 7fffdba6                 call    _reset_timeout
F0072BC0: 90062150                 add     %i0, 0x150, %o0
F0072BC4: d2062064                 ld      [%i0+0x64], %o1
F0072BC8: 90100018                 mov     %i0, %o0
F0072BCC: d2262050                 st      %o1, [%i0+0x50]
F0072BD0: 92103fff                 mov     -1, %o1
F0072BD4: d2262064                 st      %o1, [%i0+0x64]
F0072BD8: 7ffffb5b                 call    _compute_priority
F0072BDC: 92102000                 mov     0, %o1
F0072BE0: c0262020                 clr     [%i0+0x20]
F0072BE4: 40009050                 call    _splx
F0072BE8: 90100011                 mov     %l1, %o0
F0072BEC: b0102000                 mov     0, %i0
F0072BF0: 81c7e008                 ret
F0072BF4: 81e80000                 restore
