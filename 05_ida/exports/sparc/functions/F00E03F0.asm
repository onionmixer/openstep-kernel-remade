F00E03F0: 9de3bf98                 save    %sp, -0x68, %sp
F00E03F4: d00e0000                 ldub    [%i0], %o0
F00E03F8: d02e4000                 stb     %o0, [%i1]
F00E03FC: d00e2001                 ldub    [%i0+1], %o0
F00E0400: d02e6001                 stb     %o0, [%i1+1]
F00E0404: d00e2002                 ldub    [%i0+2], %o0
F00E0408: d02e6002                 stb     %o0, [%i1+2]
F00E040C: d00e2003                 ldub    [%i0+3], %o0
F00E0410: d02e6003                 stb     %o0, [%i1+3]
F00E0414: d00e2004                 ldub    [%i0+4], %o0
F00E0418: d02e6004                 stb     %o0, [%i1+4]
F00E041C: d00e2005                 ldub    [%i0+5], %o0
F00E0420: d02e6005                 stb     %o0, [%i1+5]
F00E0424: d00e2006                 ldub    [%i0+6], %o0
F00E0428: d02e6006                 stb     %o0, [%i1+6]
F00E042C: d00e2007                 ldub    [%i0+7], %o0
F00E0430: d02e6007                 stb     %o0, [%i1+7]
F00E0434: d00e2008                 ldub    [%i0+8], %o0
F00E0438: d02e6008                 stb     %o0, [%i1+8]
F00E043C: d00e2009                 ldub    [%i0+9], %o0
F00E0440: d02e6009                 stb     %o0, [%i1+9]
F00E0444: d00e200a                 ldub    [%i0+0xA], %o0
F00E0448: d02e600a                 stb     %o0, [%i1+0xA]
F00E044C: d00e200b                 ldub    [%i0+0xB], %o0
F00E0450: d02e600b                 stb     %o0, [%i1+0xB]
F00E0454: d00e200c                 ldub    [%i0+0xC], %o0
F00E0458: d02e600c                 stb     %o0, [%i1+0xC]
F00E045C: d00e200e                 ldub    [%i0+0xE], %o0
F00E0460: d02e600e                 stb     %o0, [%i1+0xE]
F00E0464: d00e200f                 ldub    [%i0+0xF], %o0
F00E0468: d02e600f                 stb     %o0, [%i1+0xF]
F00E046C: d00e2010                 ldub    [%i0+0x10], %o0
F00E0470: d02e6010                 stb     %o0, [%i1+0x10]
F00E0474: d20e2011                 ldub    [%i0+0x11], %o1
F00E0478: 90062014                 add     %i0, 0x14, %o0! void *
F00E047C: d22e6011                 stb     %o1, [%i1+0x11]
F00E0480: d40e2012                 ldub    [%i0+0x12], %o2
F00E0484: 92066014                 add     %i1, 0x14, %o1! void *
F00E0488: d42e6012                 stb     %o2, [%i1+0x12]
F00E048C: d60e2013                 ldub    [%i0+0x13], %o3
F00E0490: 94102010                 mov     0x10, %o2! size_t
F00E0494: 7ffed19f                 call    _bcopy
F00E0498: d62e6013                 stb     %o3, [%i1+0x13]
F00E049C: 90062025                 add     %i0, 0x25, %o0 ! '%'! void *
F00E04A0: 92066025                 add     %i1, 0x25, %o1 ! '%'! void *
F00E04A4: d60e2024                 ldub    [%i0+0x24], %o3
F00E04A8: 94102008                 mov     8, %o2! size_t
F00E04AC: 7ffed199                 call    _bcopy
F00E04B0: d62e6024                 stb     %o3, [%i1+0x24]
F00E04B4: 81c7e008                 ret
F00E04B8: 81e80000                 restore
