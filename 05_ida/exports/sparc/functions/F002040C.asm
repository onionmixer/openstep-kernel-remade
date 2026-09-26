F002040C: 9de3bf98                 save    %sp, -0x68, %sp
F0020410: 7fffffdd                 call    _sbwakeup
F0020414: 90100019                 mov     %i1, %o0
F0020418: d0162006                 lduh    [%i0+6], %o0
F002041C: 808a2200                 btst    0x200, %o0
F0020420: 02800013                 be      locret_F002046C
F0020424: 01000000                 nop
F0020428: d056205a                 ldsh    [%i0+0x5A], %o0! unsigned int
F002042C: 80a22000                 cmp     %o0, 0
F0020430: 16800006                 bge     loc_F0020448
F0020434: 01000000                 nop
F0020438: 90200008                 neg     %o0
F002043C: 7fffc428                 call    _gsignal
F0020440: 92102017                 mov     0x17, %o1! char *
F0020444: 3080000a                 ba,a    locret_F002046C
F0020448: 04800009                 ble     locret_F002046C
F002044C: 01000000                 nop
F0020450: 7fffb81c                 call    _pfind
F0020454: 01000000                 nop
F0020458: 80a22000                 cmp     %o0, 0
F002045C: 02800004                 be      locret_F002046C
F0020460: 01000000                 nop
F0020464: 7fffc444                 call    _psignal
F0020468: 92102017                 mov     0x17, %o1
F002046C: 81c7e008                 ret
F0020470: 81e80000                 restore
