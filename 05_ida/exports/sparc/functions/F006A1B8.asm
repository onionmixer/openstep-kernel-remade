F006A1B8: 9de3bf98                 save    %sp, -0x68, %sp
F006A1BC: 113c0000                 sethi   %hi(dword_F0000000), %o0
F006A1C0: 40000004                 call    _firstsegfromheader
F006A1C4: 90122000                 bset    %lo(dword_F0000000), %o0
F006A1C8: 81c7e008                 ret
F006A1CC: 91e80008                 restore %g0, %o0, %o0
