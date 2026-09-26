F00ECB4C: 9de3bf98                 save    %sp, -0x68, %sp
F00ECB50: 7ffe2634                 call    _current_thread_EXTERNAL
F00ECB54: a2100018                 mov     %i0, %l1
F00ECB58: 94100008                 mov     %o0, %o2! size_t
F00ECB5C: 113c04bc92122048         set     unk_F012F048, %o1
F00ECB64: 80a26000                 cmp     %o1, 0
F00ECB68: 0280000a                 be      loc_F00ECB90
F00ECB6C: 01000000                 nop
F00ECB70: d0026010                 ld      [%o1+0x10], %o0
F00ECB74: 80a2000a                 cmp     %o0, %o2
F00ECB78: 22800009                 be,a    loc_F00ECB9C
F00ECB7C: b0100009                 mov     %o1, %i0
F00ECB80: d2026014                 ld      [%o1+0x14], %o1
F00ECB84: 80a26000                 cmp     %o1, 0
F00ECB88: 32bffffb                 bne,a   loc_F00ECB74
F00ECB8C: d0026010                 ld      [%o1+0x10], %o0
F00ECB90: 7fffff3a                 call    sub_F00EC878
F00ECB94: 9010000a                 mov     %o2, %o0
F00ECB98: b0100008                 mov     %o0, %i0
F00ECB9C: d206200c                 ld      [%i0+0xC], %o1
F00ECBA0: d0062008                 ld      [%i0+8], %o0
F00ECBA4: 80a24008                 cmp     %o1, %o0
F00ECBA8: 1280001f                 bne     loc_F00ECC24
F00ECBAC: 90026001                 add     %o1, 1, %o0
F00ECBB0: e0062004                 ld      [%i0+4], %l0
F00ECBB4: 113c04bb90122388         set     unk_F012EF88, %o0
F00ECBBC: 80a40008                 cmp     %l0, %o0
F00ECBC0: 3280000f                 bne,a   loc_F00ECBFC
F00ECBC4: d0062008                 ld      [%i0+8], %o0
F00ECBC8: 92026001                 inc     %o1
F00ECBCC: d2262008                 st      %o1, [%i0+8]
F00ECBD0: 912a6001                 sll     %o1, 1, %o0
F00ECBD4: 90020009                 add     %o0, %o1, %o0! __size
F00ECBD8: 7ffded96                 call    _malloc
F00ECBDC: 912a2002                 sll     %o0, 2, %o0
F00ECBE0: 92100008                 mov     %o0, %o1! void *
F00ECBE4: d2262004                 st      %o1, [%i0+4]
F00ECBE8: 90100010                 mov     %l0, %o0! void *
F00ECBEC: 7ffe9fc9                 call    _bcopy
F00ECBF0: 941020c0                 mov     0xC0, %o2
F00ECBF4: 1080000b                 ba      loc_F00ECC20
F00ECBF8: d206200c                 ld      [%i0+0xC], %o1
F00ECBFC: 90022001                 inc     %o0
F00ECC00: d0262008                 st      %o0, [%i0+8]
F00ECC04: 932a2001                 sll     %o0, 1, %o1
F00ECC08: 92024008                 add     %o1, %o0, %o1! __size
F00ECC0C: d0062004                 ld      [%i0+4], %o0! __ptr
F00ECC10: 7ffded9d                 call    _realloc
F00ECC14: 932a6002                 sll     %o1, 2, %o1
F00ECC18: d0262004                 st      %o0, [%i0+4]
F00ECC1C: d206200c                 ld      [%i0+0xC], %o1
F00ECC20: 90026001                 add     %o1, 1, %o0
F00ECC24: d026200c                 st      %o0, [%i0+0xC]
F00ECC28: 912a6001                 sll     %o1, 1, %o0
F00ECC2C: 90020009                 add     %o0, %o1, %o0
F00ECC30: 912a2002                 sll     %o0, 2, %o0
F00ECC34: d4062004                 ld      [%i0+4], %o2
F00ECC38: 9602000a                 add     %o0, %o2, %o3
F00ECC3C: d2060000                 ld      [%i0], %o1
F00ECC40: d222000a                 st      %o1, [%o0+%o2]
F00ECC44: d2062004                 ld      [%i0+4], %o1
F00ECC48: 9222c009                 sub     %o3, %o1, %o1
F00ECC4C: 912a6002                 sll     %o1, 2, %o0
F00ECC50: 90020009                 add     %o0, %o1, %o0
F00ECC54: 932a2004                 sll     %o0, 4, %o1
F00ECC58: 90020009                 add     %o0, %o1, %o0
F00ECC5C: 932a2008                 sll     %o0, 8, %o1
F00ECC60: 90020009                 add     %o0, %o1, %o0
F00ECC64: 932a2010                 sll     %o0, 16, %o1
F00ECC68: 90020009                 add     %o0, %o1, %o0
F00ECC6C: 90200008                 neg     %o0
F00ECC70: 913a2001                 sra     %o0, 1, %o0
F00ECC74: 90122001                 bset    1, %o0
F00ECC78: d0260000                 st      %o0, [%i0]
F00ECC7C: e222e004                 st      %l1, [%o3+4]
F00ECC80: f222e008                 st      %i1, [%o3+8]
F00ECC84: f0060000                 ld      [%i0], %i0
F00ECC88: 81c7e008                 ret
F00ECC8C: 81e80000                 restore
