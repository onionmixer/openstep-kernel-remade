F00E1820: 9de3bf98                 save    %sp, -0x68, %sp
F00E1824: 9210001b                 mov     %i3, %o1
F00E1828: a0102000                 mov     0, %l0
F00E182C: 80a26001                 cmp     %o1, 1
F00E1830: 0280009c                 be      loc_F00E1AA0
F00E1834: f607a05c                 ld      [%fp+arg_5C], %i3
F00E1838: 80a26001                 cmp     %o1, 1
F00E183C: 14800007                 bg      loc_F00E1858
F00E1840: 80a26003                 cmp     %o1, 3
F00E1844: 80a26000                 cmp     %o1, 0
F00E1848: 02800008                 be      loc_F00E1868
F00E184C: 80a72001                 cmp     %i4, 1
F00E1850: 108000fe                 ba      loc_F00E1C48
F00E1854: 113c03f2                 sethi   -0xFF03800, %o0
F00E1858: 02800040                 be      loc_F00E1958
F00E185C: bb3f6008                 sra     %i5, 8, %i5
F00E1860: 108000fa                 ba      loc_F00E1C48
F00E1864: 113c03f2                 sethi   -0xFF03800, %o0
F00E1868: 02800006                 be      loc_F00E1880
F00E186C: b536a001                 srl     %i2, 1, %i2
F00E1870: 80a72002                 cmp     %i4, 2
F00E1874: 02800023                 be      loc_F00E1900
F00E1878: b536a001                 srl     %i2, 1, %i2
F00E187C: 308000f5                 ba,a    locret_F00E1C50
F00E1880: 9007401b                 add     %i5, %i3, %o0
F00E1884: 9332201f                 srl     %o0, 31, %o1
F00E1888: 90020009                 add     %o0, %o1, %o0
F00E188C: b406bfff                 inc     -1, %i2
F00E1890: 80a6bfff                 cmp     %i2, -1
F00E1894: 028000ef                 be      locret_F00E1C50
F00E1898: b73a2001                 sra     %o0, 1, %i3
F00E189C: 1100001fba1223ff         set     0x7FFF, %i5
F00E18A4: 393fffe0                 sethi   -0x8000, %i4
F00E18A8: d0560000                 ldsh    [%i0], %o0
F00E18AC: 7ffc9315                 call    _umul
F00E18B0: 9210001b                 mov     %i3, %o1
F00E18B4: 913a200f                 sra     %o0, 15, %o0
F00E18B8: 80a2001d                 cmp     %o0, %i5
F00E18BC: 04800004                 ble     loc_F00E18CC
F00E18C0: b0062002                 inc     2, %i0
F00E18C4: 10800006                 ba      loc_F00E18DC
F00E18C8: fa364000                 sth     %i5, [%i1]
F00E18CC: 80a2001c                 cmp     %o0, %i4
F00E18D0: 36800006                 bge,a   loc_F00E18E8
F00E18D4: d0364000                 sth     %o0, [%i1]
F00E18D8: f8364000                 sth     %i4, [%i1]
F00E18DC: b2066002                 inc     2, %i1
F00E18E0: 10800003                 ba      loc_F00E18EC
F00E18E4: a0042001                 inc     %l0
F00E18E8: b2066002                 inc     2, %i1
F00E18EC: b406bfff                 inc     -1, %i2
F00E18F0: 80a6bfff                 cmp     %i2, -1
F00E18F4: 32bfffee                 bne,a   loc_F00E18AC
F00E18F8: d0560000                 ldsh    [%i0], %o0
F00E18FC: 308000d5                 ba,a    locret_F00E1C50
F00E1900: b406bfff                 inc     -1, %i2
F00E1904: 80a6bfff                 cmp     %i2, -1
F00E1908: 028000d2                 be      locret_F00E1C50
F00E190C: 01000000                 nop
F00E1910: 9210001d                 mov     %i5, %o1
F00E1914: d0560000                 ldsh    [%i0], %o0
F00E1918: 7ffc92fa                 call    _umul
F00E191C: b406bfff                 inc     -1, %i2
F00E1920: b0062002                 inc     2, %i0
F00E1924: 9132200f                 srl     %o0, 15, %o0
F00E1928: d0364000                 sth     %o0, [%i1]
F00E192C: b2066002                 inc     2, %i1
F00E1930: d0560000                 ldsh    [%i0], %o0
F00E1934: 7ffc92f3                 call    _umul
F00E1938: 9210001b                 mov     %i3, %o1
F00E193C: b0062002                 inc     2, %i0
F00E1940: 9132200f                 srl     %o0, 15, %o0
F00E1944: d0364000                 sth     %o0, [%i1]
F00E1948: 80a6bfff                 cmp     %i2, -1
F00E194C: 12bffff1                 bne     loc_F00E1910
F00E1950: b2066002                 inc     2, %i1
F00E1954: 308000bf                 ba,a    locret_F00E1C50
F00E1958: 80a72001                 cmp     %i4, 1
F00E195C: 02800006                 be      loc_F00E1974
F00E1960: b73ee008                 sra     %i3, 8, %i3
F00E1964: 80a72002                 cmp     %i4, 2
F00E1968: 02800022                 be      loc_F00E19F0
F00E196C: b536a001                 srl     %i2, 1, %i2
F00E1970: 308000b8                 ba,a    locret_F00E1C50
F00E1974: 9007401b                 add     %i5, %i3, %o0
F00E1978: 9332201f                 srl     %o0, 31, %o1
F00E197C: 90020009                 add     %o0, %o1, %o0
F00E1980: b406bfff                 inc     -1, %i2
F00E1984: 80a6bfff                 cmp     %i2, -1
F00E1988: 028000b2                 be      locret_F00E1C50
F00E198C: b73a2001                 sra     %o0, 1, %i3
F00E1990: a410207f                 mov     0x7F, %l2
F00E1994: a2103f80                 mov     -0x80, %l1
F00E1998: d04e0000                 ldsb    [%i0], %o0
F00E199C: 7ffc92d9                 call    _umul
F00E19A0: 9210001b                 mov     %i3, %o1
F00E19A4: 913a2007                 sra     %o0, 7, %o0
F00E19A8: 80a2207f                 cmp     %o0, 0x7F
F00E19AC: 04800004                 ble     loc_F00E19BC
F00E19B0: b0062001                 inc     %i0
F00E19B4: 10800006                 ba      loc_F00E19CC
F00E19B8: e42e4000                 stb     %l2, [%i1]
F00E19BC: 80a23f80                 cmp     %o0, -0x80
F00E19C0: 36800006                 bge,a   loc_F00E19D8
F00E19C4: d02e4000                 stb     %o0, [%i1]
F00E19C8: e22e4000                 stb     %l1, [%i1]
F00E19CC: b2066001                 inc     %i1
F00E19D0: 10800003                 ba      loc_F00E19DC
F00E19D4: a0042001                 inc     %l0
F00E19D8: b2066001                 inc     %i1
F00E19DC: b406bfff                 inc     -1, %i2
F00E19E0: 80a6bfff                 cmp     %i2, -1
F00E19E4: 32bfffee                 bne,a   loc_F00E199C
F00E19E8: d04e0000                 ldsb    [%i0], %o0
F00E19EC: 30800099                 ba,a    locret_F00E1C50
F00E19F0: b406bfff                 inc     -1, %i2
F00E19F4: 80a6bfff                 cmp     %i2, -1
F00E19F8: 02800096                 be      locret_F00E1C50
F00E19FC: a210207f                 mov     0x7F, %l1
F00E1A00: b8103f80                 mov     -0x80, %i4
F00E1A04: d04e0000                 ldsb    [%i0], %o0
F00E1A08: 7ffc92be                 call    _umul
F00E1A0C: 9210001d                 mov     %i5, %o1
F00E1A10: 913a2007                 sra     %o0, 7, %o0
F00E1A14: 80a2207f                 cmp     %o0, 0x7F
F00E1A18: 04800004                 ble     loc_F00E1A28
F00E1A1C: b0062001                 inc     %i0
F00E1A20: 10800006                 ba      loc_F00E1A38
F00E1A24: e22e4000                 stb     %l1, [%i1]
F00E1A28: 80a23f80                 cmp     %o0, -0x80
F00E1A2C: 36800006                 bge,a   loc_F00E1A44
F00E1A30: d02e4000                 stb     %o0, [%i1]
F00E1A34: f82e4000                 stb     %i4, [%i1]
F00E1A38: b2066001                 inc     %i1
F00E1A3C: 10800003                 ba      loc_F00E1A48
F00E1A40: a0042001                 inc     %l0
F00E1A44: b2066001                 inc     %i1
F00E1A48: d04e0000                 ldsb    [%i0], %o0
F00E1A4C: 7ffc92ad                 call    _umul
F00E1A50: 9210001b                 mov     %i3, %o1
F00E1A54: 913a2007                 sra     %o0, 7, %o0
F00E1A58: 80a2207f                 cmp     %o0, 0x7F
F00E1A5C: 04800004                 ble     loc_F00E1A6C
F00E1A60: b0062001                 inc     %i0
F00E1A64: 10800006                 ba      loc_F00E1A7C
F00E1A68: e22e4000                 stb     %l1, [%i1]
F00E1A6C: 80a23f80                 cmp     %o0, -0x80
F00E1A70: 36800006                 bge,a   loc_F00E1A88
F00E1A74: d02e4000                 stb     %o0, [%i1]
F00E1A78: f82e4000                 stb     %i4, [%i1]
F00E1A7C: b2066001                 inc     %i1
F00E1A80: 10800003                 ba      loc_F00E1A8C
F00E1A84: a0042001                 inc     %l0
F00E1A88: b2066001                 inc     %i1
F00E1A8C: b406bfff                 inc     -1, %i2
F00E1A90: 80a6bfff                 cmp     %i2, -1
F00E1A94: 32bfffdd                 bne,a   loc_F00E1A08
F00E1A98: d04e0000                 ldsb    [%i0], %o0
F00E1A9C: 3080006d                 ba,a    locret_F00E1C50
F00E1AA0: bb3f6008                 sra     %i5, 8, %i5
F00E1AA4: 80a72001                 cmp     %i4, 1
F00E1AA8: 02800006                 be      loc_F00E1AC0
F00E1AAC: b73ee008                 sra     %i3, 8, %i3
F00E1AB0: 80a72002                 cmp     %i4, 2
F00E1AB4: 0280002b                 be      loc_F00E1B60
F00E1AB8: b536a001                 srl     %i2, 1, %i2
F00E1ABC: 30800065                 ba,a    locret_F00E1C50
F00E1AC0: 9007401b                 add     %i5, %i3, %o0
F00E1AC4: 9332201f                 srl     %o0, 31, %o1
F00E1AC8: 90020009                 add     %o0, %o1, %o0
F00E1ACC: b406bfff                 inc     -1, %i2
F00E1AD0: 80a6bfff                 cmp     %i2, -1
F00E1AD4: 0280005f                 be      locret_F00E1C50
F00E1AD8: b73a2001                 sra     %o0, 1, %i3
F00E1ADC: 113c03e5b81223c4         set     _audio_muLaw, %i4
F00E1AE4: 1100001fa61223ff         set     0x7FFF, %l3
F00E1AEC: a4102080                 mov     0x80, %l2
F00E1AF0: 233fffe0                 sethi   -0x8000, %l1
F00E1AF4: d00e0000                 ldub    [%i0], %o0
F00E1AF8: 9210001b                 mov     %i3, %o1
F00E1AFC: 912a2001                 sll     %o0, 1, %o0
F00E1B00: d052001c                 ldsh    [%o0+%i4], %o0
F00E1B04: 7ffc927f                 call    _umul
F00E1B08: b0062001                 inc     %i0
F00E1B0C: 913a2007                 sra     %o0, 7, %o0
F00E1B10: 80a20013                 cmp     %o0, %l3
F00E1B14: 04800004                 ble     loc_F00E1B24
F00E1B18: 80a20011                 cmp     %o0, %l1
F00E1B1C: 10800005                 ba      loc_F00E1B30
F00E1B20: e42e4000                 stb     %l2, [%i1]
F00E1B24: 16800006                 bge     loc_F00E1B3C
F00E1B28: 912a2010                 sll     %o0, 16, %o0
F00E1B2C: c02e4000                 clrb    [%i1]
F00E1B30: b2066001                 inc     %i1
F00E1B34: 10800006                 ba      loc_F00E1B4C
F00E1B38: a0042001                 inc     %l0
F00E1B3C: 40000331                 call    _audio_shortToMulaw
F00E1B40: 913a2010                 sra     %o0, 16, %o0
F00E1B44: d02e4000                 stb     %o0, [%i1]
F00E1B48: b2066001                 inc     %i1
F00E1B4C: b406bfff                 inc     -1, %i2
F00E1B50: 80a6bfff                 cmp     %i2, -1
F00E1B54: 32bfffe9                 bne,a   loc_F00E1AF8
F00E1B58: d00e0000                 ldub    [%i0], %o0
F00E1B5C: 3080003d                 ba,a    locret_F00E1C50
F00E1B60: b406bfff                 inc     -1, %i2
F00E1B64: 80a6bfff                 cmp     %i2, -1
F00E1B68: 0280003a                 be      locret_F00E1C50
F00E1B6C: 113c03e5                 sethi   %hi(_audio_muLaw), %o0
F00E1B70: a61223c4                 or      %o0, %lo(_audio_muLaw), %l3
F00E1B74: 1100001fa41223ff         set     0x7FFF, %l2
F00E1B7C: b8102080                 mov     0x80, %i4
F00E1B80: 233fffe0                 sethi   -0x8000, %l1
F00E1B84: d00e0000                 ldub    [%i0], %o0
F00E1B88: 9210001d                 mov     %i5, %o1
F00E1B8C: 912a2001                 sll     %o0, 1, %o0
F00E1B90: d0520013                 ldsh    [%o0+%l3], %o0
F00E1B94: 7ffc925b                 call    _umul
F00E1B98: b0062001                 inc     %i0
F00E1B9C: 913a2007                 sra     %o0, 7, %o0
F00E1BA0: 80a20012                 cmp     %o0, %l2
F00E1BA4: 04800004                 ble     loc_F00E1BB4
F00E1BA8: 80a20011                 cmp     %o0, %l1
F00E1BAC: 10800005                 ba      loc_F00E1BC0
F00E1BB0: f82e4000                 stb     %i4, [%i1]
F00E1BB4: 16800006                 bge     loc_F00E1BCC
F00E1BB8: 912a2010                 sll     %o0, 16, %o0
F00E1BBC: c02e4000                 clrb    [%i1]
F00E1BC0: b2066001                 inc     %i1
F00E1BC4: 10800006                 ba      loc_F00E1BDC
F00E1BC8: a0042001                 inc     %l0
F00E1BCC: 4000030d                 call    _audio_shortToMulaw
F00E1BD0: 913a2010                 sra     %o0, 16, %o0
F00E1BD4: d02e4000                 stb     %o0, [%i1]
F00E1BD8: b2066001                 inc     %i1
F00E1BDC: d00e0000                 ldub    [%i0], %o0
F00E1BE0: 9210001b                 mov     %i3, %o1
F00E1BE4: 912a2001                 sll     %o0, 1, %o0
F00E1BE8: d0520013                 ldsh    [%o0+%l3], %o0
F00E1BEC: 7ffc9245                 call    _umul
F00E1BF0: b0062001                 inc     %i0
F00E1BF4: 913a2007                 sra     %o0, 7, %o0
F00E1BF8: 80a20012                 cmp     %o0, %l2
F00E1BFC: 04800004                 ble     loc_F00E1C0C
F00E1C00: 80a20011                 cmp     %o0, %l1
F00E1C04: 10800005                 ba      loc_F00E1C18
F00E1C08: f82e4000                 stb     %i4, [%i1]
F00E1C0C: 16800006                 bge     loc_F00E1C24
F00E1C10: 912a2010                 sll     %o0, 16, %o0
F00E1C14: c02e4000                 clrb    [%i1]
F00E1C18: b2066001                 inc     %i1
F00E1C1C: 10800006                 ba      loc_F00E1C34
F00E1C20: a0042001                 inc     %l0
F00E1C24: 400002f7                 call    _audio_shortToMulaw
F00E1C28: 913a2010                 sra     %o0, 16, %o0
F00E1C2C: d02e4000                 stb     %o0, [%i1]
F00E1C30: b2066001                 inc     %i1
F00E1C34: b406bfff                 inc     -1, %i2
F00E1C38: 80a6bfff                 cmp     %i2, -1
F00E1C3C: 32bfffd3                 bne,a   loc_F00E1B88
F00E1C40: d00e0000                 ldub    [%i0], %o0
F00E1C44: 30800003                 ba,a    locret_F00E1C50
F00E1C48: 7fff912b                 call    _IOLog
F00E1C4C: 901221d8                 bset    0x1D8, %o0
F00E1C50: 81c7e008                 ret
F00E1C54: 91e80010                 restore %g0, %l0, %o0
