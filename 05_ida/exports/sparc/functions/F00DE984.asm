F00DE984: 9de3bf98                 save    %sp, -0x68, %sp
F00DE988: 80a62000                 cmp     %i0, 0
F00DE98C: 0280000b                 be      loc_F00DE9B8
F00DE990: 113c0505                 sethi   %hi(paChannel), %o0! id
F00DE994: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DE998: 40004bb6                 call    _objc_msgSend
F00DE99C: 90100018                 mov     %i0, %o0! id
F00DE9A0: 133c0505                 sethi   %hi(paRemovestream), %o1
F00DE9A4: d2026094                 ld      [%o1+%lo(paRemovestream)], %o1! SEL
F00DE9A8: 40004bb2                 call    _objc_msgSend
F00DE9AC: 94100018                 mov     %i0, %o2
F00DE9B0: 10800003                 ba      locret_F00DE9BC
F00DE9B4: b0102000                 mov     0, %i0
F00DE9B8: b01020ca                 mov     0xCA, %i0
F00DE9BC: 81c7e008                 ret
F00DE9C0: 81e80000                 restore
