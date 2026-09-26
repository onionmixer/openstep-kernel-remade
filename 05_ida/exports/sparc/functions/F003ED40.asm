F003ED40: 9de3bf98                 save    %sp, -0x68, %sp
F003ED44: d00e2004                 ldub    [%i0+4], %o0
F003ED48: 7fffffde                 call    sub_F003ECC0
F003ED4C: 92100019                 mov     %i1, %o1
F003ED50: 92100008                 mov     %o0, %o1
F003ED54: a010202e                 mov     0x2E, %l0 ! '.'
F003ED58: e02a4000                 stb     %l0, [%o1]
F003ED5C: d00e2005                 ldub    [%i0+5], %o0
F003ED60: 7fffffd8                 call    sub_F003ECC0
F003ED64: 92026001                 inc     %o1
F003ED68: 92100008                 mov     %o0, %o1
F003ED6C: e02a4000                 stb     %l0, [%o1]
F003ED70: d00e2006                 ldub    [%i0+6], %o0
F003ED74: 7fffffd3                 call    sub_F003ECC0
F003ED78: 92026001                 inc     %o1
F003ED7C: 92100008                 mov     %o0, %o1
F003ED80: e02a4000                 stb     %l0, [%o1]
F003ED84: d00e2007                 ldub    [%i0+7], %o0
F003ED88: 7fffffce                 call    sub_F003ECC0
F003ED8C: 92026001                 inc     %o1
F003ED90: c02a0000                 clrb    [%o0]
F003ED94: 81c7e008                 ret
F003ED98: 81e80000                 restore
