F0071BFC: 9de3bf98                 save    %sp, -0x68, %sp
F0071C00: e2066058                 ld      [%i1+0x58], %l1
F0071C04: 80a4601f                 cmp     %l1, 0x1F
F0071C08: 08800006                 bleu    loc_F0071C20
F0071C0C: 113c0441                 sethi   %hi(aRunQueueEnqueu), %o0! "run_queue_enqueue: pri too high (%d)\n"
F0071C10: 90122138                 bset    %lo(aRunQueueEnqueu), %o0! "run_queue_enqueue: pri too high (%d)\n"
F0071C14: 7ffe8a91                 call    _printf
F0071C18: 92100011                 mov     %l1, %o1
F0071C1C: a210201f                 mov     0x1F, %l1
F0071C20: a0062100                 add     %i0, 0x100, %l0
F0071C24: d0040000                 ld      [%l0], %o0
F0071C28: 80a22000                 cmp     %o0, 0
F0071C2C: 12bffffe                 bne     loc_F0071C24
F0071C30: 01000000                 nop
F0071C34: 4000949d                 call    _simple_lock_try
F0071C38: 90100010                 mov     %l0, %o0
F0071C3C: 80a22000                 cmp     %o0, 0
F0071C40: 02bffff9                 be      loc_F0071C24
F0071C44: 912c6003                 sll     %l1, 3, %o0
F0071C48: 90020018                 add     %o0, %i0, %o0
F0071C4C: d0264000                 st      %o0, [%i1]
F0071C50: d2022004                 ld      [%o0+4], %o1
F0071C54: d2266004                 st      %o1, [%i1+4]
F0071C58: f2224000                 st      %i1, [%o1]
F0071C5C: f2222004                 st      %i1, [%o0+4]
F0071C60: d0062104                 ld      [%i0+0x104], %o0
F0071C64: 80a44008                 cmp     %l1, %o0
F0071C68: 38800007                 bgu,a   loc_F0071C84
F0071C6C: e2262104                 st      %l1, [%i0+0x104]
F0071C70: d0062108                 ld      [%i0+0x108], %o0
F0071C74: 80a22000                 cmp     %o0, 0
F0071C78: 12800005                 bne     loc_F0071C8C
F0071C7C: 90022001                 inc     %o0
F0071C80: e2262104                 st      %l1, [%i0+0x104]
F0071C84: d0062108                 ld      [%i0+0x108], %o0
F0071C88: 90022001                 inc     %o0
F0071C8C: d0262108                 st      %o0, [%i0+0x108]
F0071C90: f0266008                 st      %i0, [%i1+8]
F0071C94: c0262100                 clr     [%i0+0x100]
F0071C98: 81c7e008                 ret
F0071C9C: 81e80000                 restore
