F00998FC: 9de3bf98                 save    %sp, -0x68, %sp
F0099900: 113c04f6                 sethi   %hi(_sbusmap), %o0
F0099904: d0022320                 ld      [%o0+%lo(_sbusmap)], %o0
F0099908: 80a64008                 cmp     %i1, %o0
F009990C: 0280000b                 be      loc_F0099938
F0099910: 92100018                 mov     %i0, %o1
F0099914: 113c04f6                 sethi   %hi(_bigsbusmap), %o0
F0099918: d00222f0                 ld      [%o0+%lo(_bigsbusmap)], %o0
F009991C: 80a64008                 cmp     %i1, %o0
F0099920: 02800006                 be      loc_F0099938
F0099924: 113c04f6                 sethi   %hi(_mbutlmap), %o0
F0099928: d0022310                 ld      [%o0+%lo(_mbutlmap)], %o0
F009992C: 80a64008                 cmp     %i1, %o0
F0099930: 12800013                 bne     loc_F009997C
F0099934: 113c045c                 sethi   -0xFEE9000, %o0
F0099938: 90027ffe                 add     %o1, -2, %o0
F009993C: 80a220fd                 cmp     %o0, 0xFD
F0099940: 08800011                 bleu    locret_F0099984
F0099944: b0026f00                 add     %o1, 0xF00, %i0
F0099948: 113ffc04                 sethi   -0xFF000, %o0
F009994C: b0024008                 add     %o1, %o0, %i0
F0099950: 80a625ff                 cmp     %i0, 0x5FF
F0099954: 0880000c                 bleu    locret_F0099984
F0099958: 113ffc02                 sethi   -0xFF800, %o0
F009995C: 90122200                 bset    0x200, %o0
F0099960: 90024008                 add     %o1, %o0, %o0
F0099964: 80a221ff                 cmp     %o0, 0x1FF
F0099968: 08800007                 bleu    locret_F0099984
F009996C: 113c045c                 sethi   %hi(aMapAddrToDvmaP), %o0! "map_addr_to_dvma_pfn: bad sbus map_addr"
F0099970: 7ffdee00                 call    _panic
F0099974: 90122000                 bset    %lo(aMapAddrToDvmaP), %o0! "map_addr_to_dvma_pfn: bad sbus map_addr"
F0099978: 113c045c                 sethi   -0xFEE9000, %o0! char *
F009997C: 7ffdedfd                 call    _panic
F0099980: 90122028                 bset    0x28, %o0 ! '('
F0099984: 81c7e008                 ret
F0099988: 81e80000                 restore
