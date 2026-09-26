F0054ABC: 9de3bf98                 save    %sp, -0x68, %sp
F0054AC0: 113c04ef                 sethi   %hi(_ipc_hash_global_size), %o0
F0054AC4: d00222e8                 ld      [%o0+%lo(_ipc_hash_global_size)], %o0
F0054AC8: 80a20019                 cmp     %o0, %i1
F0054ACC: 2a800002                 bcs,a   loc_F0054AD4
F0054AD0: b2100008                 mov     %o0, %i1
F0054AD4: a4102000                 mov     0, %l2
F0054AD8: 80a48019                 cmp     %l2, %i1
F0054ADC: 1a800020                 bcc     loc_F0054B5C
F0054AE0: 113c04ef                 sethi   -0xFEC4400, %o0
F0054AE4: 293c04ef                 sethi   -0xFEC4400, %l4
F0054AE8: a6102000                 mov     0, %l3
F0054AEC: a2102000                 mov     0, %l1
F0054AF0: d20522f0                 ld      [%l4+0x2F0], %o1
F0054AF4: 912ca003                 sll     %l2, 3, %o0
F0054AF8: a0024008                 add     %o1, %o0, %l0
F0054AFC: d0040000                 ld      [%l0], %o0
F0054B00: 80a22000                 cmp     %o0, 0
F0054B04: 12bffffe                 bne     loc_F0054AFC
F0054B08: 01000000                 nop
F0054B0C: 400108e7                 call    _simple_lock_try
F0054B10: 90100010                 mov     %l0, %o0
F0054B14: 80a22000                 cmp     %o0, 0
F0054B18: 02bffff9                 be      loc_F0054AFC
F0054B1C: 01000000                 nop
F0054B20: d0042004                 ld      [%l0+4], %o0
F0054B24: 80a22000                 cmp     %o0, 0
F0054B28: 02800006                 be      loc_F0054B40
F0054B2C: 01000000                 nop
F0054B30: d002200c                 ld      [%o0+0xC], %o0
F0054B34: 80a22000                 cmp     %o0, 0
F0054B38: 12bffffe                 bne     loc_F0054B30
F0054B3C: a2046001                 inc     %l1
F0054B40: c0240000                 clr     [%l0]
F0054B44: e224c018                 st      %l1, [%l3+%i0]
F0054B48: a404a001                 inc     %l2
F0054B4C: 80a48019                 cmp     %l2, %i1
F0054B50: 0abfffe7                 bcs     loc_F0054AEC
F0054B54: a604e004                 inc     4, %l3
F0054B58: 113c04ef                 sethi   -0xFEC4400, %o0
F0054B5C: f00222e8                 ld      [%o0+0x2E8], %i0
F0054B60: 81c7e008                 ret
F0054B64: 81e80000                 restore
