F00E0B80: 9de3bf98                 save    %sp, -0x68, %sp
F00E0B84: d00e0000                 ldub    [%i0], %o0
F00E0B88: d02e4000                 stb     %o0, [%i1]
F00E0B8C: d00e2001                 ldub    [%i0+1], %o0
F00E0B90: d02e6001                 stb     %o0, [%i1+1]
F00E0B94: d00e2002                 ldub    [%i0+2], %o0
F00E0B98: d02e6002                 stb     %o0, [%i1+2]
F00E0B9C: d00e2003                 ldub    [%i0+3], %o0
F00E0BA0: d02e6003                 stb     %o0, [%i1+3]
F00E0BA4: d00e2004                 ldub    [%i0+4], %o0
F00E0BA8: d02e6004                 stb     %o0, [%i1+4]
F00E0BAC: d00e2005                 ldub    [%i0+5], %o0
F00E0BB0: d02e6005                 stb     %o0, [%i1+5]
F00E0BB4: d00e2006                 ldub    [%i0+6], %o0
F00E0BB8: d02e6006                 stb     %o0, [%i1+6]
F00E0BBC: d00e2007                 ldub    [%i0+7], %o0
F00E0BC0: d02e6007                 stb     %o0, [%i1+7]
F00E0BC4: d00e2008                 ldub    [%i0+8], %o0
F00E0BC8: d02e6008                 stb     %o0, [%i1+8]
F00E0BCC: d00e2009                 ldub    [%i0+9], %o0
F00E0BD0: d02e6009                 stb     %o0, [%i1+9]
F00E0BD4: d00e200a                 ldub    [%i0+0xA], %o0
F00E0BD8: d02e600a                 stb     %o0, [%i1+0xA]
F00E0BDC: d00e200b                 ldub    [%i0+0xB], %o0
F00E0BE0: d02e600b                 stb     %o0, [%i1+0xB]
F00E0BE4: d00e200c                 ldub    [%i0+0xC], %o0
F00E0BE8: d02e600c                 stb     %o0, [%i1+0xC]
F00E0BEC: d00e200e                 ldub    [%i0+0xE], %o0
F00E0BF0: d02e600e                 stb     %o0, [%i1+0xE]
F00E0BF4: d00e200f                 ldub    [%i0+0xF], %o0
F00E0BF8: d02e600f                 stb     %o0, [%i1+0xF]
F00E0BFC: d00e2010                 ldub    [%i0+0x10], %o0
F00E0C00: d02e6010                 stb     %o0, [%i1+0x10]
F00E0C04: d20e2011                 ldub    [%i0+0x11], %o1
F00E0C08: 90062014                 add     %i0, 0x14, %o0! void *
F00E0C0C: d22e6011                 stb     %o1, [%i1+0x11]
F00E0C10: d40e2012                 ldub    [%i0+0x12], %o2
F00E0C14: 92066014                 add     %i1, 0x14, %o1! void *
F00E0C18: d42e6012                 stb     %o2, [%i1+0x12]
F00E0C1C: d60e2013                 ldub    [%i0+0x13], %o3
F00E0C20: 94102010                 mov     0x10, %o2! size_t
F00E0C24: 7ffecfbb                 call    _bcopy
F00E0C28: d62e6013                 stb     %o3, [%i1+0x13]
F00E0C2C: 90062025                 add     %i0, 0x25, %o0 ! '%'! void *
F00E0C30: 92066025                 add     %i1, 0x25, %o1 ! '%'! void *
F00E0C34: d60e2024                 ldub    [%i0+0x24], %o3
F00E0C38: 94102008                 mov     8, %o2! size_t
F00E0C3C: 7ffecfb5                 call    _bcopy
F00E0C40: d62e6024                 stb     %o3, [%i1+0x24]
F00E0C44: 81c7e008                 ret
F00E0C48: 81e80000                 restore
