F00E07A8: 9de3bf98                 save    %sp, -0x68, %sp
F00E07AC: d00e0000                 ldub    [%i0], %o0
F00E07B0: d02e4000                 stb     %o0, [%i1]
F00E07B4: d00e2001                 ldub    [%i0+1], %o0
F00E07B8: d02e6001                 stb     %o0, [%i1+1]
F00E07BC: d00e2002                 ldub    [%i0+2], %o0
F00E07C0: d02e6002                 stb     %o0, [%i1+2]
F00E07C4: d00e2003                 ldub    [%i0+3], %o0
F00E07C8: d02e6003                 stb     %o0, [%i1+3]
F00E07CC: d00e2004                 ldub    [%i0+4], %o0
F00E07D0: d02e6004                 stb     %o0, [%i1+4]
F00E07D4: d00e2005                 ldub    [%i0+5], %o0
F00E07D8: d02e6005                 stb     %o0, [%i1+5]
F00E07DC: d00e2006                 ldub    [%i0+6], %o0
F00E07E0: d02e6006                 stb     %o0, [%i1+6]
F00E07E4: d00e2007                 ldub    [%i0+7], %o0
F00E07E8: d02e6007                 stb     %o0, [%i1+7]
F00E07EC: d00e2008                 ldub    [%i0+8], %o0
F00E07F0: d02e6008                 stb     %o0, [%i1+8]
F00E07F4: d20e2009                 ldub    [%i0+9], %o1
F00E07F8: 9006200c                 add     %i0, 0xC, %o0! void *
F00E07FC: d22e6009                 stb     %o1, [%i1+9]
F00E0800: d40e200a                 ldub    [%i0+0xA], %o2
F00E0804: 9206600c                 add     %i1, 0xC, %o1! void *
F00E0808: d42e600a                 stb     %o2, [%i1+0xA]
F00E080C: d60e200b                 ldub    [%i0+0xB], %o3
F00E0810: 94102018                 mov     0x18, %o2! size_t
F00E0814: 7ffed0bf                 call    _bcopy
F00E0818: d62e600b                 stb     %o3, [%i1+0xB]
F00E081C: d00e2024                 ldub    [%i0+0x24], %o0
F00E0820: d02e6024                 stb     %o0, [%i1+0x24]
F00E0824: d00e2025                 ldub    [%i0+0x25], %o0
F00E0828: d02e6025                 stb     %o0, [%i1+0x25]
F00E082C: d00e2026                 ldub    [%i0+0x26], %o0
F00E0830: d02e6026                 stb     %o0, [%i1+0x26]
F00E0834: d00e2027                 ldub    [%i0+0x27], %o0
F00E0838: ac06202c                 add     %i0, 0x2C, %l6 ! ','
F00E083C: d02e6027                 stb     %o0, [%i1+0x27]
F00E0840: d00e2028                 ldub    [%i0+0x28], %o0
F00E0844: aa06602c                 add     %i1, 0x2C, %l5 ! ','
F00E0848: d02e6028                 stb     %o0, [%i1+0x28]
F00E084C: d20e2029                 ldub    [%i0+0x29], %o1
F00E0850: 90100016                 mov     %l6, %o0! void *
F00E0854: d22e6029                 stb     %o1, [%i1+0x29]
F00E0858: d40e202a                 ldub    [%i0+0x2A], %o2
F00E085C: 92100015                 mov     %l5, %o1! void *
F00E0860: d42e602a                 stb     %o2, [%i1+0x2A]
F00E0864: d60e202b                 ldub    [%i0+0x2B], %o3
F00E0868: 94102018                 mov     0x18, %o2! size_t
F00E086C: 7ffed0a9                 call    _bcopy
F00E0870: d62e602b                 stb     %o3, [%i1+0x2B]
F00E0874: 90062044                 add     %i0, 0x44, %o0 ! 'D'! void *
F00E0878: 92066044                 add     %i1, 0x44, %o1 ! 'D'! void *
F00E087C: 7ffed0a5                 call    _bcopy
F00E0880: 94102018                 mov     0x18, %o2
F00E0884: d00e205c                 ldub    [%i0+0x5C], %o0
F00E0888: d02e605c                 stb     %o0, [%i1+0x5C]
F00E088C: d00e205d                 ldub    [%i0+0x5D], %o0
F00E0890: d02e605d                 stb     %o0, [%i1+0x5D]
F00E0894: d00e205e                 ldub    [%i0+0x5E], %o0
F00E0898: d02e605e                 stb     %o0, [%i1+0x5E]
F00E089C: d00e205f                 ldub    [%i0+0x5F], %o0
F00E08A0: d02e605f                 stb     %o0, [%i1+0x5F]
F00E08A4: d00e2060                 ldub    [%i0+0x60], %o0
F00E08A8: d02e6060                 stb     %o0, [%i1+0x60]
F00E08AC: d00e2061                 ldub    [%i0+0x61], %o0
F00E08B0: d02e6061                 stb     %o0, [%i1+0x61]
F00E08B4: d00e2062                 ldub    [%i0+0x62], %o0
F00E08B8: d02e6062                 stb     %o0, [%i1+0x62]
F00E08BC: d00e2063                 ldub    [%i0+0x63], %o0
F00E08C0: d02e6063                 stb     %o0, [%i1+0x63]
F00E08C4: d00e2064                 ldub    [%i0+0x64], %o0
F00E08C8: d02e6064                 stb     %o0, [%i1+0x64]
F00E08CC: d00e2065                 ldub    [%i0+0x65], %o0
F00E08D0: d02e6065                 stb     %o0, [%i1+0x65]
F00E08D4: d00e2066                 ldub    [%i0+0x66], %o0
F00E08D8: d02e6066                 stb     %o0, [%i1+0x66]
F00E08DC: d00e2067                 ldub    [%i0+0x67], %o0
F00E08E0: d02e6067                 stb     %o0, [%i1+0x67]
F00E08E4: d00e2068                 ldub    [%i0+0x68], %o0
F00E08E8: d02e6068                 stb     %o0, [%i1+0x68]
F00E08EC: d00e2069                 ldub    [%i0+0x69], %o0
F00E08F0: d02e6069                 stb     %o0, [%i1+0x69]
F00E08F4: d00e206a                 ldub    [%i0+0x6A], %o0
F00E08F8: d02e606a                 stb     %o0, [%i1+0x6A]
F00E08FC: d00e206b                 ldub    [%i0+0x6B], %o0
F00E0900: d02e606b                 stb     %o0, [%i1+0x6B]
F00E0904: d00e206c                 ldub    [%i0+0x6C], %o0
F00E0908: d02e606c                 stb     %o0, [%i1+0x6C]
F00E090C: d00e206d                 ldub    [%i0+0x6D], %o0
F00E0910: d02e606d                 stb     %o0, [%i1+0x6D]
F00E0914: d00e206e                 ldub    [%i0+0x6E], %o0
F00E0918: d02e606e                 stb     %o0, [%i1+0x6E]
F00E091C: d00e206f                 ldub    [%i0+0x6F], %o0
F00E0920: d02e606f                 stb     %o0, [%i1+0x6F]
F00E0924: d00e2070                 ldub    [%i0+0x70], %o0
F00E0928: d02e6070                 stb     %o0, [%i1+0x70]
F00E092C: d00e2071                 ldub    [%i0+0x71], %o0
F00E0930: d02e6071                 stb     %o0, [%i1+0x71]
F00E0934: d00e2072                 ldub    [%i0+0x72], %o0
F00E0938: d02e6072                 stb     %o0, [%i1+0x72]
F00E093C: d00e2073                 ldub    [%i0+0x73], %o0
F00E0940: d02e6073                 stb     %o0, [%i1+0x73]
F00E0944: d00e2074                 ldub    [%i0+0x74], %o0
F00E0948: d02e6074                 stb     %o0, [%i1+0x74]
F00E094C: d00e2075                 ldub    [%i0+0x75], %o0
F00E0950: d02e6075                 stb     %o0, [%i1+0x75]
F00E0954: d00e2076                 ldub    [%i0+0x76], %o0
F00E0958: d02e6076                 stb     %o0, [%i1+0x76]
F00E095C: d00e2077                 ldub    [%i0+0x77], %o0
F00E0960: 9a06207c                 add     %i0, 0x7C, %o5 ! '|'
F00E0964: d02e6077                 stb     %o0, [%i1+0x77]
F00E0968: d00e2078                 ldub    [%i0+0x78], %o0
F00E096C: 9806607c                 add     %i1, 0x7C, %o4 ! '|'
F00E0970: d02e6078                 stb     %o0, [%i1+0x78]
F00E0974: d00e2079                 ldub    [%i0+0x79], %o0
F00E0978: 96102000                 mov     0, %o3
F00E097C: d02e6079                 stb     %o0, [%i1+0x79]
F00E0980: d00e207a                 ldub    [%i0+0x7A], %o0
F00E0984: 9406607f                 add     %i1, 0x7F, %o2
F00E0988: d02e607a                 stb     %o0, [%i1+0x7A]
F00E098C: d00e207b                 ldub    [%i0+0x7B], %o0
F00E0990: 9206207f                 add     %i0, 0x7F, %o1
F00E0994: d02e607b                 stb     %o0, [%i1+0x7B]
F00E0998: d00b4000                 ldub    [%o5], %o0
F00E099C: 9602e001                 inc     %o3
F00E09A0: d02b0000                 stb     %o0, [%o4]
F00E09A4: d00a7ffe                 ldub    [%o1-2], %o0
F00E09A8: 80a2e001                 cmp     %o3, 1
F00E09AC: d02abffe                 stb     %o0, [%o2-2]
F00E09B0: d00a7fff                 ldub    [%o1-1], %o0
F00E09B4: 9a036004                 inc     4, %o5
F00E09B8: d02abfff                 stb     %o0, [%o2-1]
F00E09BC: d00a4000                 ldub    [%o1], %o0
F00E09C0: 98032004                 inc     4, %o4
F00E09C4: d02a8000                 stb     %o0, [%o2]
F00E09C8: 92026004                 inc     4, %o1
F00E09CC: 04bffff3                 ble     loc_F00E0998
F00E09D0: 9402a004                 inc     4, %o2! size_t
F00E09D4: 9005a058                 add     %l6, 0x58, %o0 ! 'X'! void *
F00E09D8: 92056058                 add     %l5, 0x58, %o1 ! 'X'! void *
F00E09DC: 7ffed04d                 call    _bcopy
F00E09E0: 94102018                 mov     0x18, %o2! size_t
F00E09E4: 9005a070                 add     %l6, 0x70, %o0 ! 'p'! void *
F00E09E8: 92056070                 add     %l5, 0x70, %o1 ! 'p'! void *
F00E09EC: 7ffed049                 call    _bcopy
F00E09F0: 94102020                 mov     0x20, %o2 ! ' '
F00E09F4: a8102000                 mov     0, %l4
F00E09F8: d00da090                 ldub    [%l6+0x90], %o0
F00E09FC: a6102000                 mov     0, %l3
F00E0A00: d02d6090                 stb     %o0, [%l5+0x90]
F00E0A04: d00da091                 ldub    [%l6+0x91], %o0
F00E0A08: a4102000                 mov     0, %l2
F00E0A0C: d02d6091                 stb     %o0, [%l5+0x91]
F00E0A10: a0048016                 add     %l2, %l6, %l0
F00E0A14: a0042092                 inc     0x92, %l0
F00E0A18: a204c015                 add     %l3, %l5, %l1
F00E0A1C: d00c0000                 ldub    [%l0], %o0
F00E0A20: a2046094                 inc     0x94, %l1
F00E0A24: d02c4000                 stb     %o0, [%l1]
F00E0A28: d00c2001                 ldub    [%l0+1], %o0
F00E0A2C: d02c6001                 stb     %o0, [%l1+1]
F00E0A30: d00c2002                 ldub    [%l0+2], %o0
F00E0A34: d02c6002                 stb     %o0, [%l1+2]
F00E0A38: d00c2003                 ldub    [%l0+3], %o0
F00E0A3C: d02c6003                 stb     %o0, [%l1+3]
F00E0A40: d00c2004                 ldub    [%l0+4], %o0
F00E0A44: d02c6004                 stb     %o0, [%l1+4]
F00E0A48: d00c2005                 ldub    [%l0+5], %o0
F00E0A4C: d02c6005                 stb     %o0, [%l1+5]
F00E0A50: d00c2006                 ldub    [%l0+6], %o0
F00E0A54: d02c6006                 stb     %o0, [%l1+6]
F00E0A58: d00c2007                 ldub    [%l0+7], %o0
F00E0A5C: d02c6007                 stb     %o0, [%l1+7]
F00E0A60: d00c2008                 ldub    [%l0+8], %o0
F00E0A64: d02c6008                 stb     %o0, [%l1+8]
F00E0A68: d00c2009                 ldub    [%l0+9], %o0
F00E0A6C: d02c6009                 stb     %o0, [%l1+9]
F00E0A70: d00c200a                 ldub    [%l0+0xA], %o0
F00E0A74: d02c600a                 stb     %o0, [%l1+0xA]
F00E0A78: d00c200b                 ldub    [%l0+0xB], %o0
F00E0A7C: d02c600b                 stb     %o0, [%l1+0xB]
F00E0A80: d00c200c                 ldub    [%l0+0xC], %o0
F00E0A84: d02c600c                 stb     %o0, [%l1+0xC]
F00E0A88: d20c200e                 ldub    [%l0+0xE], %o1
F00E0A8C: a604e030                 inc     0x30, %l3 ! '0'
F00E0A90: d22c600e                 stb     %o1, [%l1+0xE]
F00E0A94: d40c200f                 ldub    [%l0+0xF], %o2
F00E0A98: a404a02e                 inc     0x2E, %l2 ! '.'
F00E0A9C: d42c600f                 stb     %o2, [%l1+0xF]
F00E0AA0: d60c2010                 ldub    [%l0+0x10], %o3
F00E0AA4: a8052001                 inc     %l4
F00E0AA8: d62c6010                 stb     %o3, [%l1+0x10]
F00E0AAC: d60c2011                 ldub    [%l0+0x11], %o3
F00E0AB0: 90042014                 add     %l0, 0x14, %o0! void *
F00E0AB4: d62c6011                 stb     %o3, [%l1+0x11]
F00E0AB8: d60c2012                 ldub    [%l0+0x12], %o3
F00E0ABC: 92046014                 add     %l1, 0x14, %o1! void *
F00E0AC0: d62c6012                 stb     %o3, [%l1+0x12]
F00E0AC4: d60c2013                 ldub    [%l0+0x13], %o3
F00E0AC8: 94102010                 mov     0x10, %o2! size_t
F00E0ACC: 7ffed011                 call    _bcopy
F00E0AD0: d62c6013                 stb     %o3, [%l1+0x13]
F00E0AD4: 90042025                 add     %l0, 0x25, %o0 ! '%'! void *
F00E0AD8: 92046025                 add     %l1, 0x25, %o1 ! '%'! void *
F00E0ADC: d60c2024                 ldub    [%l0+0x24], %o3
F00E0AE0: 94102008                 mov     8, %o2! size_t
F00E0AE4: 7ffed00b                 call    _bcopy
F00E0AE8: d62c6024                 stb     %o3, [%l1+0x24]
F00E0AEC: 80a52007                 cmp     %l4, 7
F00E0AF0: 04bfffc9                 ble     loc_F00E0A14
F00E0AF4: a0048016                 add     %l2, %l6, %l0
F00E0AF8: 9806222e                 add     %i0, 0x22E, %o4
F00E0AFC: 96102000                 mov     0, %o3
F00E0B00: 92066240                 add     %i1, 0x240, %o1
F00E0B04: 94062231                 add     %i0, 0x231, %o2
F00E0B08: d00b0000                 ldub    [%o4], %o0
F00E0B0C: d02a4000                 stb     %o0, [%o1]
F00E0B10: d00abffe                 ldub    [%o2-2], %o0
F00E0B14: 9602e001                 inc     %o3
F00E0B18: d02a6001                 stb     %o0, [%o1+1]
F00E0B1C: d00abfff                 ldub    [%o2-1], %o0
F00E0B20: 80a2e685                 cmp     %o3, 0x685
F00E0B24: d02a6002                 stb     %o0, [%o1+2]
F00E0B28: d00a8000                 ldub    [%o2], %o0
F00E0B2C: 98032004                 inc     4, %o4
F00E0B30: d02a6003                 stb     %o0, [%o1+3]
F00E0B34: 9402a004                 inc     4, %o2
F00E0B38: 04bffff4                 ble     loc_F00E0B08
F00E0B3C: 92026004                 inc     4, %o1
F00E0B40: 1100000790122046         set     0x1C46, %o0
F00E0B48: 13000007                 sethi   0x1C00, %o1
F00E0B4C: d40e0008                 ldub    [%i0+%o0], %o2
F00E0B50: 92126058                 bset    0x58, %o1 ! 'X'
F00E0B54: d42e4009                 stb     %o2, [%i1+%o1]
F00E0B58: 90060008                 add     %i0, %o0, %o0
F00E0B5C: d00a2001                 ldub    [%o0+1], %o0
F00E0B60: 92064009                 add     %i1, %o1, %o1
F00E0B64: d02a6001                 stb     %o0, [%o1+1]
F00E0B68: d00e222e                 ldub    [%i0+0x22E], %o0
F00E0B6C: d02e6240                 stb     %o0, [%i1+0x240]
F00E0B70: d00e222f                 ldub    [%i0+0x22F], %o0
F00E0B74: d02e6241                 stb     %o0, [%i1+0x241]
F00E0B78: 81c7e008                 ret
F00E0B7C: 81e80000                 restore
