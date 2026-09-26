F0088E88: 9de3bf98                 save    %sp, -0x68, %sp
F0088E8C: d2062020                 ld      [%i0+0x20], %o1
F0088E90: 11080000                 sethi   0x20000000, %o0
F0088E94: 808a4008                 btst    %o0, %o1
F0088E98: 0280003e                 be      locret_F0088F90
F0088E9C: 113c04f4                 sethi   %hi(_page_shift), %o0
F0088EA0: d4062018                 ld      [%i0+0x18], %o2
F0088EA4: d0022348                 ld      [%o0+%lo(_page_shift)], %o0
F0088EA8: 173c04f6                 sethi   %hi(_vm_page_buckets), %o3
F0088EAC: 95328008                 srl     %o2, %o0, %o2
F0088EB0: d0062014                 ld      [%i0+0x14], %o0
F0088EB4: 133c04f6                 sethi   %hi(_vm_page_hash_mask), %o1
F0088EB8: d2026140                 ld      [%o1+%lo(_vm_page_hash_mask)], %o1
F0088EBC: 9002000a                 add     %o0, %o2, %o0
F0088EC0: 900a0009                 and     %o0, %o1, %o0
F0088EC4: d202e138                 ld      [%o3+%lo(_vm_page_buckets)], %o1
F0088EC8: 912a2003                 sll     %o0, 3, %o0
F0088ECC: 4000373b                 call    _spltty
F0088ED0: a0024008                 add     %o1, %o0, %l0
F0088ED4: a2100008                 mov     %o0, %l1
F0088ED8: d0040000                 ld      [%l0], %o0
F0088EDC: 80a22000                 cmp     %o0, 0
F0088EE0: 12bffffe                 bne     loc_F0088ED8
F0088EE4: 01000000                 nop
F0088EE8: 400037f0                 call    _simple_lock_try
F0088EEC: 90100010                 mov     %l0, %o0
F0088EF0: 80a22000                 cmp     %o0, 0
F0088EF4: 02bffff9                 be      loc_F0088ED8
F0088EF8: 01000000                 nop
F0088EFC: d0042004                 ld      [%l0+4], %o0
F0088F00: 80a20018                 cmp     %o0, %i0
F0088F04: 12800005                 bne     loc_F0088F18
F0088F08: 92022010                 add     %o0, 0x10, %o1
F0088F0C: d0062010                 ld      [%i0+0x10], %o0
F0088F10: 10800008                 ba      loc_F0088F30
F0088F14: d0242004                 st      %o0, [%l0+4]
F0088F18: d0022010                 ld      [%o0+0x10], %o0
F0088F1C: 80a20018                 cmp     %o0, %i0
F0088F20: 32bffffe                 bne,a   loc_F0088F18
F0088F24: 92022010                 add     %o0, 0x10, %o1
F0088F28: d0022010                 ld      [%o0+0x10], %o0
F0088F2C: d0224000                 st      %o0, [%o1]
F0088F30: c0240000                 clr     [%l0]
F0088F34: 4000377c                 call    _splx
F0088F38: 90100011                 mov     %l1, %o0
F0088F3C: d4062008                 ld      [%i0+8], %o2
F0088F40: d0062014                 ld      [%i0+0x14], %o0
F0088F44: 80a2000a                 cmp     %o0, %o2
F0088F48: 12800004                 bne     loc_F0088F58
F0088F4C: d206200c                 ld      [%i0+0xC], %o1
F0088F50: 10800003                 ba      loc_F0088F5C
F0088F54: d222a004                 st      %o1, [%o2+4]
F0088F58: d222a00c                 st      %o1, [%o2+0xC]
F0088F5C: d0062014                 ld      [%i0+0x14], %o0
F0088F60: 80a20009                 cmp     %o0, %o1
F0088F64: 22800003                 be,a    loc_F0088F70
F0088F68: d4224000                 st      %o2, [%o1]
F0088F6C: d4226008                 st      %o2, [%o1+8]
F0088F70: d2062014                 ld      [%i0+0x14], %o1
F0088F74: d012601a                 lduh    [%o1+0x1A], %o0
F0088F78: 90023fff                 inc     -1, %o0
F0088F7C: d032601a                 sth     %o0, [%o1+0x1A]
F0088F80: d2062020                 ld      [%i0+0x20], %o1
F0088F84: 11080000                 sethi   0x20000000, %o0
F0088F88: 902a4008                 andn    %o1, %o0, %o0
F0088F8C: d0262020                 st      %o0, [%i0+0x20]
F0088F90: 81c7e008                 ret
F0088F94: 81e80000                 restore
