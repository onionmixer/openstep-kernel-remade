F002BAB8: 9de3bf98                 save    %sp, -0x68, %sp
F002BABC: 90100018                 mov     %i0, %o0
F002BAC0: 9210200c                 mov     0xC, %o1
F002BAC4: d2222004                 st      %o1, [%o0+4]
F002BAC8: 7fffc867                 call    _m_freem
F002BACC: c0322008                 clrh    [%o0+8]
F002BAD0: 81c7e008                 ret
F002BAD4: 81e80000                 restore
