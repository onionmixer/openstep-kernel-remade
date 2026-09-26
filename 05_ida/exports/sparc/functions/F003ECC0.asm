F003ECC0: 9de3bf88                 save    %sp, -0x78, %sp
F003ECC4: a207bfe8                 add     %fp, var_18, %l1
F003ECC8: 113c0435a41221b8         set     a0123456789, %l2! "0123456789"
F003ECD0: a12e2010                 sll     %i0, 16, %l0
F003ECD4: a1342010                 srl     %l0, 16, %l0
F003ECD8: 90100010                 mov     %l0, %o0
F003ECDC: 7fff1ef1                 call    _urem
F003ECE0: 9210200a                 mov     0xA, %o1
F003ECE4: 92100008                 mov     %o0, %o1
F003ECE8: 932a6010                 sll     %o1, 16, %o1
F003ECEC: 93326010                 srl     %o1, 16, %o1
F003ECF0: d40a4012                 ldub    [%o1+%l2], %o2
F003ECF4: 90100010                 mov     %l0, %o0
F003ECF8: 9210200a                 mov     0xA, %o1
F003ECFC: d42c4000                 stb     %o2, [%l1]
F003ED00: 7fff1e40                 call    _udiv
F003ED04: a2046001                 inc     %l1
F003ED08: b0100008                 mov     %o0, %i0
F003ED0C: 912a2010                 sll     %o0, 16, %o0
F003ED10: 80a22000                 cmp     %o0, 0
F003ED14: 12bffff0                 bne     loc_F003ECD4
F003ED18: a12e2010                 sll     %i0, 16, %l0
F003ED1C: 9207bfe8                 add     %fp, var_18, %o1
F003ED20: a2047fff                 inc     -1, %l1
F003ED24: d00c4000                 ldub    [%l1], %o0
F003ED28: 80a44009                 cmp     %l1, %o1
F003ED2C: d02e4000                 stb     %o0, [%i1]
F003ED30: 18bffffc                 bgu     loc_F003ED20
F003ED34: b2066001                 inc     %i1
F003ED38: 81c7e008                 ret
F003ED3C: 91e80019                 restore %g0, %i1, %o0
