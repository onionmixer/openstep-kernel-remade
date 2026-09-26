F00E04BC: 9de3bf98                 save    %sp, -0x68, %sp
F00E04C0: 90100018                 mov     %i0, %o0! void *
F00E04C4: 92100019                 mov     %i1, %o1! void *
F00E04C8: 7ffed192                 call    _bcopy
F00E04CC: 94102018                 mov     0x18, %o2! size_t
F00E04D0: 90062018                 add     %i0, 0x18, %o0! void *
F00E04D4: 92066018                 add     %i1, 0x18, %o1! void *
F00E04D8: 7ffed18e                 call    _bcopy
F00E04DC: 94102018                 mov     0x18, %o2
F00E04E0: d00e2030                 ldub    [%i0+0x30], %o0
F00E04E4: d02e6030                 stb     %o0, [%i1+0x30]
F00E04E8: d00e2031                 ldub    [%i0+0x31], %o0
F00E04EC: d02e6031                 stb     %o0, [%i1+0x31]
F00E04F0: d00e2032                 ldub    [%i0+0x32], %o0
F00E04F4: d02e6032                 stb     %o0, [%i1+0x32]
F00E04F8: d00e2033                 ldub    [%i0+0x33], %o0
F00E04FC: d02e6033                 stb     %o0, [%i1+0x33]
F00E0500: d00e2034                 ldub    [%i0+0x34], %o0
F00E0504: d02e6034                 stb     %o0, [%i1+0x34]
F00E0508: d00e2035                 ldub    [%i0+0x35], %o0
F00E050C: d02e6035                 stb     %o0, [%i1+0x35]
F00E0510: d00e2036                 ldub    [%i0+0x36], %o0
F00E0514: d02e6036                 stb     %o0, [%i1+0x36]
F00E0518: d00e2037                 ldub    [%i0+0x37], %o0
F00E051C: d02e6037                 stb     %o0, [%i1+0x37]
F00E0520: d00e2038                 ldub    [%i0+0x38], %o0
F00E0524: d02e6038                 stb     %o0, [%i1+0x38]
F00E0528: d00e2039                 ldub    [%i0+0x39], %o0
F00E052C: d02e6039                 stb     %o0, [%i1+0x39]
F00E0530: d00e203a                 ldub    [%i0+0x3A], %o0
F00E0534: d02e603a                 stb     %o0, [%i1+0x3A]
F00E0538: d00e203b                 ldub    [%i0+0x3B], %o0
F00E053C: d02e603b                 stb     %o0, [%i1+0x3B]
F00E0540: d00e203c                 ldub    [%i0+0x3C], %o0
F00E0544: d02e603c                 stb     %o0, [%i1+0x3C]
F00E0548: d00e203d                 ldub    [%i0+0x3D], %o0
F00E054C: d02e603d                 stb     %o0, [%i1+0x3D]
F00E0550: d00e203e                 ldub    [%i0+0x3E], %o0
F00E0554: d02e603e                 stb     %o0, [%i1+0x3E]
F00E0558: d00e203f                 ldub    [%i0+0x3F], %o0
F00E055C: d02e603f                 stb     %o0, [%i1+0x3F]
F00E0560: d00e2040                 ldub    [%i0+0x40], %o0
F00E0564: d02e6040                 stb     %o0, [%i1+0x40]
F00E0568: d00e2041                 ldub    [%i0+0x41], %o0
F00E056C: d02e6041                 stb     %o0, [%i1+0x41]
F00E0570: d00e2042                 ldub    [%i0+0x42], %o0
F00E0574: d02e6042                 stb     %o0, [%i1+0x42]
F00E0578: d00e2043                 ldub    [%i0+0x43], %o0
F00E057C: d02e6043                 stb     %o0, [%i1+0x43]
F00E0580: d00e2044                 ldub    [%i0+0x44], %o0
F00E0584: d02e6044                 stb     %o0, [%i1+0x44]
F00E0588: d00e2045                 ldub    [%i0+0x45], %o0
F00E058C: d02e6045                 stb     %o0, [%i1+0x45]
F00E0590: d00e2046                 ldub    [%i0+0x46], %o0
F00E0594: d02e6046                 stb     %o0, [%i1+0x46]
F00E0598: d00e2047                 ldub    [%i0+0x47], %o0
F00E059C: d02e6047                 stb     %o0, [%i1+0x47]
F00E05A0: d00e2048                 ldub    [%i0+0x48], %o0
F00E05A4: d02e6048                 stb     %o0, [%i1+0x48]
F00E05A8: d00e2049                 ldub    [%i0+0x49], %o0
F00E05AC: d02e6049                 stb     %o0, [%i1+0x49]
F00E05B0: d00e204a                 ldub    [%i0+0x4A], %o0
F00E05B4: d02e604a                 stb     %o0, [%i1+0x4A]
F00E05B8: d00e204b                 ldub    [%i0+0x4B], %o0
F00E05BC: 9a062050                 add     %i0, 0x50, %o5 ! 'P'
F00E05C0: d02e604b                 stb     %o0, [%i1+0x4B]
F00E05C4: d00e204c                 ldub    [%i0+0x4C], %o0
F00E05C8: 98066050                 add     %i1, 0x50, %o4 ! 'P'
F00E05CC: d02e604c                 stb     %o0, [%i1+0x4C]
F00E05D0: d00e204d                 ldub    [%i0+0x4D], %o0
F00E05D4: 96102000                 mov     0, %o3
F00E05D8: d02e604d                 stb     %o0, [%i1+0x4D]
F00E05DC: d00e204e                 ldub    [%i0+0x4E], %o0
F00E05E0: 94066053                 add     %i1, 0x53, %o2 ! 'S'
F00E05E4: d02e604e                 stb     %o0, [%i1+0x4E]
F00E05E8: d00e204f                 ldub    [%i0+0x4F], %o0
F00E05EC: 92062053                 add     %i0, 0x53, %o1 ! 'S'
F00E05F0: d02e604f                 stb     %o0, [%i1+0x4F]
F00E05F4: d00b4000                 ldub    [%o5], %o0
F00E05F8: 9602e001                 inc     %o3
F00E05FC: d02b0000                 stb     %o0, [%o4]
F00E0600: d00a7ffe                 ldub    [%o1-2], %o0
F00E0604: 80a2e001                 cmp     %o3, 1
F00E0608: d02abffe                 stb     %o0, [%o2-2]
F00E060C: d00a7fff                 ldub    [%o1-1], %o0
F00E0610: 9a036004                 inc     4, %o5
F00E0614: d02abfff                 stb     %o0, [%o2-1]
F00E0618: d00a4000                 ldub    [%o1], %o0
F00E061C: 98032004                 inc     4, %o4
F00E0620: d02a8000                 stb     %o0, [%o2]
F00E0624: 92026004                 inc     4, %o1
F00E0628: 04bffff3                 ble     loc_F00E05F4
F00E062C: 9402a004                 inc     4, %o2! size_t
F00E0630: 90062058                 add     %i0, 0x58, %o0 ! 'X'! void *
F00E0634: 92066058                 add     %i1, 0x58, %o1 ! 'X'! void *
F00E0638: 7ffed136                 call    _bcopy
F00E063C: 94102018                 mov     0x18, %o2! size_t
F00E0640: 90062070                 add     %i0, 0x70, %o0 ! 'p'! void *
F00E0644: 92066070                 add     %i1, 0x70, %o1 ! 'p'! void *
F00E0648: 7ffed132                 call    _bcopy
F00E064C: 94102020                 mov     0x20, %o2 ! ' '
F00E0650: a8102000                 mov     0, %l4
F00E0654: d00e2090                 ldub    [%i0+0x90], %o0
F00E0658: a6102000                 mov     0, %l3
F00E065C: d02e6090                 stb     %o0, [%i1+0x90]
F00E0660: d00e2091                 ldub    [%i0+0x91], %o0
F00E0664: a4102000                 mov     0, %l2
F00E0668: d02e6091                 stb     %o0, [%i1+0x91]
F00E066C: a0048018                 add     %l2, %i0, %l0
F00E0670: a0042092                 inc     0x92, %l0
F00E0674: a204c019                 add     %l3, %i1, %l1
F00E0678: d00c0000                 ldub    [%l0], %o0
F00E067C: a2046094                 inc     0x94, %l1
F00E0680: d02c4000                 stb     %o0, [%l1]
F00E0684: d00c2001                 ldub    [%l0+1], %o0
F00E0688: d02c6001                 stb     %o0, [%l1+1]
F00E068C: d00c2002                 ldub    [%l0+2], %o0
F00E0690: d02c6002                 stb     %o0, [%l1+2]
F00E0694: d00c2003                 ldub    [%l0+3], %o0
F00E0698: d02c6003                 stb     %o0, [%l1+3]
F00E069C: d00c2004                 ldub    [%l0+4], %o0
F00E06A0: d02c6004                 stb     %o0, [%l1+4]
F00E06A4: d00c2005                 ldub    [%l0+5], %o0
F00E06A8: d02c6005                 stb     %o0, [%l1+5]
F00E06AC: d00c2006                 ldub    [%l0+6], %o0
F00E06B0: d02c6006                 stb     %o0, [%l1+6]
F00E06B4: d00c2007                 ldub    [%l0+7], %o0
F00E06B8: d02c6007                 stb     %o0, [%l1+7]
F00E06BC: d00c2008                 ldub    [%l0+8], %o0
F00E06C0: d02c6008                 stb     %o0, [%l1+8]
F00E06C4: d00c2009                 ldub    [%l0+9], %o0
F00E06C8: d02c6009                 stb     %o0, [%l1+9]
F00E06CC: d00c200a                 ldub    [%l0+0xA], %o0
F00E06D0: d02c600a                 stb     %o0, [%l1+0xA]
F00E06D4: d00c200b                 ldub    [%l0+0xB], %o0
F00E06D8: d02c600b                 stb     %o0, [%l1+0xB]
F00E06DC: d00c200c                 ldub    [%l0+0xC], %o0
F00E06E0: d02c600c                 stb     %o0, [%l1+0xC]
F00E06E4: d20c200e                 ldub    [%l0+0xE], %o1
F00E06E8: a604e030                 inc     0x30, %l3 ! '0'
F00E06EC: d22c600e                 stb     %o1, [%l1+0xE]
F00E06F0: d40c200f                 ldub    [%l0+0xF], %o2
F00E06F4: a404a02e                 inc     0x2E, %l2 ! '.'
F00E06F8: d42c600f                 stb     %o2, [%l1+0xF]
F00E06FC: d60c2010                 ldub    [%l0+0x10], %o3
F00E0700: a8052001                 inc     %l4
F00E0704: d62c6010                 stb     %o3, [%l1+0x10]
F00E0708: d60c2011                 ldub    [%l0+0x11], %o3
F00E070C: 90042014                 add     %l0, 0x14, %o0! void *
F00E0710: d62c6011                 stb     %o3, [%l1+0x11]
F00E0714: d60c2012                 ldub    [%l0+0x12], %o3
F00E0718: 92046014                 add     %l1, 0x14, %o1! void *
F00E071C: d62c6012                 stb     %o3, [%l1+0x12]
F00E0720: d60c2013                 ldub    [%l0+0x13], %o3
F00E0724: 94102010                 mov     0x10, %o2! size_t
F00E0728: 7ffed0fa                 call    _bcopy
F00E072C: d62c6013                 stb     %o3, [%l1+0x13]
F00E0730: 90042025                 add     %l0, 0x25, %o0 ! '%'! void *
F00E0734: 92046025                 add     %l1, 0x25, %o1 ! '%'! void *
F00E0738: d60c2024                 ldub    [%l0+0x24], %o3
F00E073C: 94102008                 mov     8, %o2! size_t
F00E0740: 7ffed0f4                 call    _bcopy
F00E0744: d62c6024                 stb     %o3, [%l1+0x24]
F00E0748: 80a52007                 cmp     %l4, 7
F00E074C: 04bfffc9                 ble     loc_F00E0670
F00E0750: a0048018                 add     %l2, %i0, %l0
F00E0754: 81c7e008                 ret
F00E0758: 81e80000                 restore
