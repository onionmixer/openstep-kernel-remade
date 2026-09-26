F00882D0: 9de3bf98                 save    %sp, -0x68, %sp
F00882D4: 80a62000                 cmp     %i0, 0
F00882D8: 02800006                 be      loc_F00882F0
F00882DC: 113c0447                 sethi   -0xFEEE400, %o0
F00882E0: d0060000                 ld      [%i0], %o0
F00882E4: 80a22000                 cmp     %o0, 0
F00882E8: 02800004                 be      loc_F00882F8
F00882EC: 113c0447                 sethi   -0xFEEE400, %o0! char *
F00882F0: 7ffe33a0                 call    _panic
F00882F4: 90122120                 bset    0x120, %o0
F00882F8: 90100018                 mov     %i0, %o0
F00882FC: 40000d4a                 call    _vnode_has_page
F0088300: 92100019                 mov     %i1, %o1
F0088304: 81c7e008                 ret
F0088308: 91e80008                 restore %g0, %o0, %o0
