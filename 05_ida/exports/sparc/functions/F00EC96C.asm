F00EC96C: 9de3bf90                 save    %sp, -0x70, %sp
F00EC970: 7ffe26ac                 call    _current_thread_EXTERNAL
F00EC974: 01000000                 nop
F00EC978: 94100008                 mov     %o0, %o2
F00EC97C: 113c04bc92122048         set     unk_F012F048, %o1
F00EC984: 80a26000                 cmp     %o1, 0
F00EC988: 0280000b                 be      loc_F00EC9B4
F00EC98C: 01000000                 nop
F00EC990: d0026010                 ld      [%o1+0x10], %o0
F00EC994: 80a2000a                 cmp     %o0, %o2
F00EC998: 32800004                 bne,a   loc_F00EC9A8
F00EC99C: d2026014                 ld      [%o1+0x14], %o1
F00EC9A0: 10800008                 ba      loc_F00EC9C0
F00EC9A4: a4100009                 mov     %o1, %l2
F00EC9A8: 80a26000                 cmp     %o1, 0
F00EC9AC: 32bffffa                 bne,a   loc_F00EC994
F00EC9B0: d0026010                 ld      [%o1+0x10], %o0
F00EC9B4: 7fffffb1                 call    sub_F00EC878
F00EC9B8: 9010000a                 mov     %o2, %o0
F00EC9BC: a4100008                 mov     %o0, %l2
F00EC9C0: e0048000                 ld      [%l2], %l0
F00EC9C4: 80a40018                 cmp     %l0, %i0
F00EC9C8: 02800021                 be      loc_F00ECA4C
F00EC9CC: 80a42000                 cmp     %l0, 0
F00EC9D0: 9607bff4                 add     %fp, var_C, %o3
F00EC9D4: 193c03f3                 sethi   -0xFF03400, %o4
F00EC9D8: 0280001c                 be      loc_F00ECA48
F00EC9DC: 808c2001                 btst    1, %l0
F00EC9E0: 12800005                 bne     loc_F00EC9F4
F00EC9E4: 01000000                 nop
F00EC9E8: 80a4000b                 cmp     %l0, %o3
F00EC9EC: 08800010                 bleu    loc_F00ECA2C
F00EC9F0: 808c2001                 btst    1, %l0
F00EC9F4: 0280000b                 be      loc_F00ECA20
F00EC9F8: 92043fff                 add     %l0, -1, %o1
F00EC9FC: 9132601f                 srl     %o1, 31, %o0
F00ECA00: 92024008                 add     %o1, %o0, %o1
F00ECA04: 933a6001                 sra     %o1, 1, %o1
F00ECA08: d404a004                 ld      [%l2+4], %o2
F00ECA0C: 912a6001                 sll     %o1, 1, %o0
F00ECA10: 90020009                 add     %o0, %o1, %o0
F00ECA14: 912a2002                 sll     %o0, 2, %o0
F00ECA18: 10800003                 ba      loc_F00ECA24
F00ECA1C: d0028008                 ld      [%o2+%o0], %o0
F00ECA20: d0042074                 ld      [%l0+0x74], %o0
F00ECA24: 10800006                 ba      loc_F00ECA3C
F00ECA28: a0100008                 mov     %o0, %l0
F00ECA2C: 40000fc7                 call    __NXLogError
F00ECA30: 901321f8                 or      %o4, 0x1F8, %o0
F00ECA34: 7ffe7e4f                 call    _abort
F00ECA38: 01000000                 nop
F00ECA3C: 80a40018                 cmp     %l0, %i0
F00ECA40: 12bfffe6                 bne     loc_F00EC9D8
F00ECA44: 80a42000                 cmp     %l0, 0
F00ECA48: 80a42000                 cmp     %l0, 0
F00ECA4C: 0280003e                 be      locret_F00ECB44
F00ECA50: 80a66000                 cmp     %i1, 0
F00ECA54: 12800006                 bne     loc_F00ECA6C
F00ECA58: a2100012                 mov     %l2, %l1
F00ECA5C: 113c03f3                 sethi   %hi(aExceptionHandl), %o0! "Exception handlers were not properly re"...
F00ECA60: 40000fba                 call    __NXLogError
F00ECA64: 901221f8                 bset    %lo(aExceptionHandl), %o0! "Exception handlers were not properly re"...
F00ECA68: a2100012                 mov     %l2, %l1
F00ECA6C: e0044000                 ld      [%l1], %l0
F00ECA70: 808c2001                 btst    1, %l0
F00ECA74: 0280002b                 be      loc_F00ECB20
F00ECA78: 90043fff                 add     %l0, -1, %o0
F00ECA7C: 9332201f                 srl     %o0, 31, %o1
F00ECA80: 90020009                 add     %o0, %o1, %o0
F00ECA84: 913a2001                 sra     %o0, 1, %o0
F00ECA88: 932a2001                 sll     %o0, 1, %o1
F00ECA8C: 92024008                 add     %o1, %o0, %o1
F00ECA90: 932a6002                 sll     %o1, 2, %o1
F00ECA94: d404a004                 ld      [%l2+4], %o2
F00ECA98: 9002400a                 add     %o1, %o2, %o0
F00ECA9C: 80a66000                 cmp     %i1, 0
F00ECAA0: 02800007                 be      loc_F00ECABC
F00ECAA4: d027bff4                 st      %o0, [%fp+var_C]
F00ECAA8: 80a40018                 cmp     %l0, %i0
F00ECAAC: 32800024                 bne,a   loc_F00ECB3C
F00ECAB0: e207bff4                 ld      [%fp+var_C], %l1
F00ECAB4: 10800020                 ba      loc_F00ECB34
F00ECAB8: d002400a                 ld      [%o1+%o2], %o0
F00ECABC: 80a40018                 cmp     %l0, %i0
F00ECAC0: 02800008                 be      loc_F00ECAE0
F00ECAC4: 92102001                 mov     1, %o1
F00ECAC8: d007bff4                 ld      [%fp+var_C], %o0
F00ECACC: d8022004                 ld      [%o0+4], %o4
F00ECAD0: d0022008                 ld      [%o0+8], %o0
F00ECAD4: 94102000                 mov     0, %o2
F00ECAD8: 9fc30000                 call    %o4
F00ECADC: 96102000                 mov     0, %o3
F00ECAE0: d407bff4                 ld      [%fp+var_C], %o2
F00ECAE4: d204a004                 ld      [%l2+4], %o1
F00ECAE8: 92228009                 sub     %o2, %o1, %o1
F00ECAEC: 912a6002                 sll     %o1, 2, %o0
F00ECAF0: 90020009                 add     %o0, %o1, %o0
F00ECAF4: 932a2004                 sll     %o0, 4, %o1
F00ECAF8: 90020009                 add     %o0, %o1, %o0
F00ECAFC: 932a2008                 sll     %o0, 8, %o1
F00ECB00: 90020009                 add     %o0, %o1, %o0
F00ECB04: 932a2010                 sll     %o0, 16, %o1
F00ECB08: 90020009                 add     %o0, %o1, %o0
F00ECB0C: 90200008                 neg     %o0
F00ECB10: 913a2002                 sra     %o0, 2, %o0
F00ECB14: d024a00c                 st      %o0, [%l2+0xC]
F00ECB18: 10800007                 ba      loc_F00ECB34
F00ECB1C: d0028000                 ld      [%o2], %o0
F00ECB20: 80a66000                 cmp     %i1, 0
F00ECB24: 22800004                 be,a    loc_F00ECB34
F00ECB28: d0042074                 ld      [%l0+0x74], %o0
F00ECB2C: 10800003                 ba      loc_F00ECB38
F00ECB30: a2042074                 add     %l0, 0x74, %l1 ! 't'
F00ECB34: d0244000                 st      %o0, [%l1]
F00ECB38: 80a40018                 cmp     %l0, %i0
F00ECB3C: 32bfffcd                 bne,a   loc_F00ECA70
F00ECB40: e0044000                 ld      [%l1], %l0
F00ECB44: 81c7e008                 ret
F00ECB48: 81e80000                 restore
