F005BA7C: 9de3bf98                 save    %sp, -0x68, %sp
F005BA80: a0062008                 add     %i0, 8, %l0
F005BA84: d0040000                 ld      [%l0], %o0
F005BA88: 80a22000                 cmp     %o0, 0
F005BA8C: 12bffffe                 bne     loc_F005BA84
F005BA90: 01000000                 nop
F005BA94: 4000ed05                 call    _simple_lock_try
F005BA98: 90100010                 mov     %l0, %o0
F005BA9C: 80a22000                 cmp     %o0, 0
F005BAA0: 02bffff9                 be      loc_F005BA84
F005BAA4: 01000000                 nop
F005BAA8: d006200c                 ld      [%i0+0xC], %o0
F005BAAC: 80a22000                 cmp     %o0, 0
F005BAB0: 12800005                 bne     loc_F005BAC4
F005BAB4: 90100018                 mov     %i0, %o0
F005BAB8: c0262008                 clr     [%i0+8]
F005BABC: 1080000c                 ba      locret_F005BAEC
F005BAC0: b0102010                 mov     0x10, %i0
F005BAC4: 7fffdfde                 call    _ipc_entry_lookup
F005BAC8: 92100019                 mov     %i1, %o1
F005BACC: 80a22000                 cmp     %o0, 0
F005BAD0: 02800005                 be      loc_F005BAE4
F005BAD4: 01000000                 nop
F005BAD8: d0268000                 st      %o0, [%i2]
F005BADC: 10800004                 ba      locret_F005BAEC
F005BAE0: b0102000                 mov     0, %i0
F005BAE4: c0262008                 clr     [%i0+8]
F005BAE8: b010200f                 mov     0xF, %i0
F005BAEC: 81c7e008                 ret
F005BAF0: 81e80000                 restore
