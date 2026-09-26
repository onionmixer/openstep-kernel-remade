F0020360: 9de3bf98                 save    %sp, -0x68, %sp
F0020364: 90100018                 mov     %i0, %o0! unsigned int
F0020368: d2122014                 lduh    [%o0+0x14], %o1
F002036C: 92126004                 bset    4, %o1
F0020370: d2322014                 sth     %o1, [%o0+0x14]
F0020374: 7fffc8c1                 call    _sleep
F0020378: 9210201a                 mov     0x1A, %o1
F002037C: 81c7e008                 ret
F0020380: 81e80000                 restore
