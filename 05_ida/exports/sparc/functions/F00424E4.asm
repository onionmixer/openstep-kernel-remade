F00424E4: 9de3bf98                 save    %sp, -0x68, %sp
F00424E8: 400096e2                 call    _kalloc
F00424EC: 90102028                 mov     0x28, %o0! void *
F00424F0: b0100008                 mov     %o0, %i0
F00424F4: 40014a59                 call    _bzero
F00424F8: 92102028                 mov     0x28, %o1 ! '('
F00424FC: 113c043690122188         set     unk_F010D988, %o0
F0042504: d0262020                 st      %o0, [%i0+0x20]
F0042508: 90102001                 mov     1, %o0
F004250C: d0260000                 st      %o0, [%i0]
F0042510: 113c04eb                 sethi   %hi(__null_auth), %o0
F0042514: d2022020                 ld      [%o0+%lo(__null_auth)], %o1
F0042518: d226200c                 st      %o1, [%i0+0xC]
F004251C: 90122020                 bset    %lo(__null_auth), %o0
F0042520: d2022004                 ld      [%o0+4], %o1
F0042524: d2262010                 st      %o1, [%i0+0x10]
F0042528: d0022008                 ld      [%o0+8], %o0
F004252C: d0262014                 st      %o0, [%i0+0x14]
F0042530: 81c7e008                 ret
F0042534: 81e80000                 restore
