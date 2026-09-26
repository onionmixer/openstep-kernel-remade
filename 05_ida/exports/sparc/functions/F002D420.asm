F002D420: 9de3bf68                 save    %sp, -0x98, %sp
F002D424: a007bfc8                 add     %fp, var_38, %l0
F002D428: 90100010                 mov     %l0, %o0! void *
F002D42C: 40019e8b                 call    _bzero
F002D430: 92102030                 mov     0x30, %o1 ! '0'
F002D434: d0160000                 lduh    [%i0], %o0
F002D438: d037bfcc                 sth     %o0, [%fp+var_34]
F002D43C: d0162002                 lduh    [%i0+2], %o0
F002D440: d037bfce                 sth     %o0, [%fp+var_32]
F002D444: d0162004                 lduh    [%i0+4], %o0
F002D448: d037bfd0                 sth     %o0, [%fp+var_30]
F002D44C: d0162006                 lduh    [%i0+6], %o0
F002D450: d037bfd2                 sth     %o0, [%fp+var_2E]
F002D454: d0162008                 lduh    [%i0+8], %o0
F002D458: d037bfd4                 sth     %o0, [%fp+var_2C]
F002D45C: d016200a                 lduh    [%i0+0xA], %o0
F002D460: d037bfd6                 sth     %o0, [%fp+var_2A]
F002D464: d016200c                 lduh    [%i0+0xC], %o0
F002D468: d037bfd8                 sth     %o0, [%fp+var_28]
F002D46C: d016200e                 lduh    [%i0+0xE], %o0
F002D470: d037bfda                 sth     %o0, [%fp+var_26]
F002D474: d0164000                 lduh    [%i1], %o0
F002D478: d037bfdc                 sth     %o0, [%fp+var_24]
F002D47C: d0166002                 lduh    [%i1+2], %o0
F002D480: d037bfde                 sth     %o0, [%fp+var_22]
F002D484: d0166004                 lduh    [%i1+4], %o0
F002D488: d037bfe0                 sth     %o0, [%fp+var_20]
F002D48C: d0166006                 lduh    [%i1+6], %o0
F002D490: d037bfe2                 sth     %o0, [%fp+var_1E]
F002D494: d0166008                 lduh    [%i1+8], %o0
F002D498: d037bfe4                 sth     %o0, [%fp+var_1C]
F002D49C: d016600a                 lduh    [%i1+0xA], %o0
F002D4A0: d037bfe6                 sth     %o0, [%fp+var_1A]
F002D4A4: d216600c                 lduh    [%i1+0xC], %o1
F002D4A8: 9010001a                 mov     %i2, %o0
F002D4AC: d237bfe8                 sth     %o1, [%fp+var_18]
F002D4B0: d416600e                 lduh    [%i1+0xE], %o2
F002D4B4: 92100010                 mov     %l0, %o1
F002D4B8: d437bfea                 sth     %o2, [%fp+var_16]
F002D4BC: 7fffff0f                 call    _rtrequest
F002D4C0: f637bfec                 sth     %i3, [%fp+var_14]
F002D4C4: 81c7e008                 ret
F002D4C8: 81e80000                 restore
