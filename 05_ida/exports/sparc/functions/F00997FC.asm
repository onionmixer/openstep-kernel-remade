F00997FC: 9de3bf98                 save    %sp, -0x68, %sp
F0099800: 90100019                 mov     %i1, %o0
F0099804: 40000035                 call    _iom_ptefind
F0099808: 9210001b                 mov     %i3, %o1
F009980C: b2920000                 orcc    %o0, %g0, %i1
F0099810: 32800006                 bne,a   loc_F0099828
F0099814: b12e2008                 sll     %i0, 8, %i0
F0099818: 113c045b                 sethi   %hi(aIomPteloadBadM), %o0! "iom_pteload: bad map addr"
F009981C: 7ffdee55                 call    _panic
F0099820: 901223e0                 bset    %lo(aIomPteloadBadM), %o0! "iom_pteload: bad map addr"
F0099824: b12e2008                 sll     %i0, 8, %i0
F0099828: 808ea001                 btst    1, %i2
F009982C: 02800003                 be      loc_F0099838
F0099830: b0162002                 bset    2, %i0
F0099834: b0162004                 bset    4, %i0
F0099838: 113c0464                 sethi   %hi(_cache), %o0
F009983C: d0022330                 ld      [%o0+%lo(_cache)], %o0
F0099840: 90023ffe                 inc     -2, %o0
F0099844: 80a22001                 cmp     %o0, 1
F0099848: 08800008                 bleu    loc_F0099868
F009984C: 113c0464                 sethi   %hi(_vac), %o0
F0099850: d0022334                 ld      [%o0+%lo(_vac)], %o0
F0099854: 80a22000                 cmp     %o0, 0
F0099858: 02800005                 be      loc_F009986C
F009985C: 808ea002                 btst    2, %i2
F0099860: 22800004                 be,a    locret_F0099870
F0099864: f0264000                 st      %i0, [%i1]
F0099868: b0162080                 bset    0x80, %i0
F009986C: f0264000                 st      %i0, [%i1]
F0099870: 81c7e008                 ret
F0099874: 81e80000                 restore
