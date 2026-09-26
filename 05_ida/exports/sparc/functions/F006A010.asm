F006A010: 9de3bf98                 save    %sp, -0x68, %sp
F006A014: 7ffff887                 call    _malloc
F006A018: 90102008                 mov     8, %o0
F006A01C: 133c000092126000         set     dword_F0000000, %o1
F006A024: d2220000                 st      %o1, [%o0]
F006A028: c0222004                 clr     [%o0+4]
F006A02C: 81c7e008                 ret
F006A030: 91e80008                 restore %g0, %o0, %o0
