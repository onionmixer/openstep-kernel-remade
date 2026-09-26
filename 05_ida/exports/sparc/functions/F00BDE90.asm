F00BDE90: 9de3bf98                 save    %sp, -0x68, %sp
F00BDE94: 40002027                 call    _IOMalloc
F00BDE98: 90102020                 mov     0x20, %o0 ! ' '
F00BDE9C: b0920000                 orcc    %o0, %g0, %i0
F00BDEA0: 02800011                 be      loc_F00BDEE4
F00BDEA4: 113c02f7                 sethi   %hi(sub_F00BDDAC), %o0
F00BDEA8: 901221ac                 bset    %lo(sub_F00BDDAC), %o0
F00BDEAC: d0260000                 st      %o0, [%i0]
F00BDEB0: 113c02f7901221c4         set     sub_F00BDDC4, %o0
F00BDEB8: d0262004                 st      %o0, [%i0+4]
F00BDEBC: c0262008                 clr     [%i0+8]
F00BDEC0: c026200c                 clr     [%i0+0xC]
F00BDEC4: c0262010                 clr     [%i0+0x10]
F00BDEC8: 113c02f7901221d0         set     sub_F00BDDD0, %o0
F00BDED0: d0262014                 st      %o0, [%i0+0x14]
F00BDED4: 113c02f7901221f8         set     sub_F00BDDF8, %o0
F00BDEDC: 10800003                 ba      locret_F00BDEE8
F00BDEE0: d0262018                 st      %o0, [%i0+0x18]
F00BDEE4: b0102000                 mov     0, %i0
F00BDEE8: 81c7e008                 ret
F00BDEEC: 81e80000                 restore
