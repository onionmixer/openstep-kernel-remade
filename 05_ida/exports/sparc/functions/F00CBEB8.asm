F00CBEB8: 9de3bf90                 save    %sp, -0x70, %sp
F00CBEBC: d00e8000                 ldub    [%i2], %o0
F00CBEC0: 808a2001                 btst    1, %o0
F00CBEC4: 02800048                 be      locret_F00CBFE4
F00CBEC8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CBECC: d0062138                 ld      [%i0+0x138], %o0! id
F00CBED0: 40009668                 call    _objc_msgSend
F00CBED4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CBED8: 90100018                 mov     %i0, %o0! id
F00CBEDC: 133c0506                 sethi   %hi(paSearchmulti), %o1
F00CBEE0: d202605c                 ld      [%o1+%lo(paSearchmulti)], %o1! SEL
F00CBEE4: 40009663                 call    _objc_msgSend
F00CBEE8: 9410001a                 mov     %i2, %o2
F00CBEEC: 94920000                 orcc    %o0, %g0, %o2
F00CBEF0: 0280000d                 be      loc_F00CBF24
F00CBEF4: 01000000                 nop
F00CBEF8: d202a010                 ld      [%o2+0x10], %o1
F00CBEFC: 90026001                 add     %o1, 1, %o0
F00CBF00: 80a22000                 cmp     %o0, 0
F00CBF04: 16800034                 bge     loc_F00CBFD4
F00CBF08: d022a010                 st      %o0, [%o2+0x10]
F00CBF0C: 10800032                 ba      loc_F00CBFD4
F00CBF10: d222a010                 st      %o1, [%o2+0x10]
F00CBF14: d4262148                 st      %o2, [%i0+0x148]
F00CBF18: d222a008                 st      %o1, [%o2+8]
F00CBF1C: 1080001d                 ba      loc_F00CBF90
F00CBF20: d222a00c                 st      %o1, [%o2+0xC]
F00CBF24: 7fffe803                 call    _IOMalloc
F00CBF28: 90102014                 mov     0x14, %o0
F00CBF2C: d20e8000                 ldub    [%i2], %o1
F00CBF30: 94100008                 mov     %o0, %o2
F00CBF34: d22a8000                 stb     %o1, [%o2]
F00CBF38: d00ea001                 ldub    [%i2+1], %o0
F00CBF3C: d02aa001                 stb     %o0, [%o2+1]
F00CBF40: d00ea002                 ldub    [%i2+2], %o0
F00CBF44: d02aa002                 stb     %o0, [%o2+2]
F00CBF48: d00ea003                 ldub    [%i2+3], %o0
F00CBF4C: d02aa003                 stb     %o0, [%o2+3]
F00CBF50: d00ea004                 ldub    [%i2+4], %o0
F00CBF54: d02aa004                 stb     %o0, [%o2+4]
F00CBF58: d00ea005                 ldub    [%i2+5], %o0
F00CBF5C: d02aa005                 stb     %o0, [%o2+5]
F00CBF60: 90102001                 mov     1, %o0
F00CBF64: d022a010                 st      %o0, [%o2+0x10]
F00CBF68: 92062144                 add     %i0, 0x144, %o1
F00CBF6C: d0062144                 ld      [%i0+0x144], %o0
F00CBF70: 80a24008                 cmp     %o1, %o0
F00CBF74: 22bfffe8                 be,a    loc_F00CBF14
F00CBF78: d4262144                 st      %o2, [%i0+0x144]
F00CBF7C: d0062148                 ld      [%i0+0x148], %o0
F00CBF80: d022a00c                 st      %o0, [%o2+0xC]
F00CBF84: d222a008                 st      %o1, [%o2+8]
F00CBF88: d4262148                 st      %o2, [%i0+0x148]
F00CBF8C: d4222008                 st      %o2, [%o0+8]
F00CBF90: d00e8000                 ldub    [%i2], %o0
F00CBF94: d02e213c                 stb     %o0, [%i0+0x13C]
F00CBF98: d00ea001                 ldub    [%i2+1], %o0
F00CBF9C: d02e213d                 stb     %o0, [%i0+0x13D]
F00CBFA0: d00ea002                 ldub    [%i2+2], %o0
F00CBFA4: d02e213e                 stb     %o0, [%i0+0x13E]
F00CBFA8: d00ea003                 ldub    [%i2+3], %o0
F00CBFAC: d02e213f                 stb     %o0, [%i0+0x13F]
F00CBFB0: d20ea004                 ldub    [%i2+4], %o1
F00CBFB4: 94102007                 mov     7, %o2
F00CBFB8: d006212c                 ld      [%i0+0x12C], %o0! id
F00CBFBC: d22e2140                 stb     %o1, [%i0+0x140]
F00CBFC0: d60ea005                 ldub    [%i2+5], %o3
F00CBFC4: 133c0506                 sethi   %hi(paSend), %o1
F00CBFC8: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00CBFCC: 40009629                 call    _objc_msgSend
F00CBFD0: d62e2141                 stb     %o3, [%i0+0x141]
F00CBFD4: d0062138                 ld      [%i0+0x138], %o0! id
F00CBFD8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00CBFDC: 40009625                 call    _objc_msgSend
F00CBFE0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00CBFE4: 81c7e008                 ret
F00CBFE8: 81e80000                 restore
