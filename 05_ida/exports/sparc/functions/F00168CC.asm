F00168CC: 9de3bf98                 save    %sp, -0x68, %sp
F00168D0: 40001206                 call    _ttynty
F00168D4: 90100018                 mov     %i0, %o0
F00168D8: 133c042d                 sethi   %hi(_ttydefaults), %o1
F00168DC: d40a63e0                 ldub    [%o1+%lo(_ttydefaults)], %o2
F00168E0: d42e204d                 stb     %o2, [%i0+0x4D]
F00168E4: 921263e0                 bset    %lo(_ttydefaults), %o1
F00168E8: d40a6001                 ldub    [%o1+1], %o2
F00168EC: d42e204e                 stb     %o2, [%i0+0x4E]
F00168F0: d40a6002                 ldub    [%o1+2], %o2
F00168F4: d42e204f                 stb     %o2, [%i0+0x4F]
F00168F8: d40a6003                 ldub    [%o1+3], %o2
F00168FC: d42e2050                 stb     %o2, [%i0+0x50]
F0016900: d40a6004                 ldub    [%o1+4], %o2
F0016904: d42e2051                 stb     %o2, [%i0+0x51]
F0016908: d40a6005                 ldub    [%o1+5], %o2
F001690C: d42e2052                 stb     %o2, [%i0+0x52]
F0016910: d40a6006                 ldub    [%o1+6], %o2
F0016914: d42e2053                 stb     %o2, [%i0+0x53]
F0016918: d40a6007                 ldub    [%o1+7], %o2
F001691C: d42e2054                 stb     %o2, [%i0+0x54]
F0016920: d40a6008                 ldub    [%o1+8], %o2
F0016924: d42e2055                 stb     %o2, [%i0+0x55]
F0016928: d40a6009                 ldub    [%o1+9], %o2
F001692C: d42e2056                 stb     %o2, [%i0+0x56]
F0016930: d40a600a                 ldub    [%o1+0xA], %o2
F0016934: d42e2057                 stb     %o2, [%i0+0x57]
F0016938: d40a600b                 ldub    [%o1+0xB], %o2
F001693C: d42e2058                 stb     %o2, [%i0+0x58]
F0016940: d40a600c                 ldub    [%o1+0xC], %o2
F0016944: d42e2059                 stb     %o2, [%i0+0x59]
F0016948: d20a600d                 ldub    [%o1+0xD], %o1
F001694C: d22e205a                 stb     %o1, [%i0+0x5A]
F0016950: 9210205c                 mov     0x5C, %o1 ! '\'
F0016954: d22a2014                 stb     %o1, [%o0+0x14]
F0016958: 92102001                 mov     1, %o1
F001695C: d22a2015                 stb     %o1, [%o0+0x15]
F0016960: 7fffff06                 call    _ttysetspec
F0016964: c02a2016                 clrb    [%o0+0x16]
F0016968: 81c7e008                 ret
F001696C: 81e80000                 restore
