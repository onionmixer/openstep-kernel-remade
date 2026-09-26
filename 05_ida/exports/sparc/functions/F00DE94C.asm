F00DE94C: 9de3bf98                 save    %sp, -0x68, %sp
F00DE950: 90100018                 mov     %i0, %o0! id
F00DE954: 94100019                 mov     %i1, %o2
F00DE958: 80a22000                 cmp     %o0, 0
F00DE95C: 02800007                 be      loc_F00DE978
F00DE960: 9610001a                 mov     %i2, %o3
F00DE964: 133c0505                 sethi   %hi(paBytesprocessed_0), %o1! SEL
F00DE968: 40004bc2                 call    _objc_msgSend
F00DE96C: d2026000                 ld      [%o1+%lo(paBytesprocessed_0)], %o1
F00DE970: 10800003                 ba      locret_F00DE97C
F00DE974: b0102000                 mov     0, %i0
F00DE978: b01020ca                 mov     0xCA, %i0
F00DE97C: 81c7e008                 ret
F00DE980: 81e80000                 restore
