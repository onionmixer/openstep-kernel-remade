F003D624: 9de3bf98                 save    %sp, -0x68, %sp
F003D628: d4162060                 lduh    [%i0+0x60], %o2
F003D62C: 808aa001                 btst    1, %o2
F003D630: 02800011                 be      loc_F003D674
F003D634: 113c04d0                 sethi   -0xFECC000, %o0
F003D638: 213c04d0                 sethi   -0xFECC000, %l0
F003D63C: d2062068                 ld      [%i0+0x68], %o1
F003D640: d0042260                 ld      [%l0+0x260], %o0
F003D644: 80a24008                 cmp     %o1, %o0
F003D648: 0280000a                 be      loc_F003D670
F003D64C: 9012a002                 or      %o2, 2, %o0
F003D650: d0362060                 sth     %o0, [%i0+0x60]
F003D654: 90100018                 mov     %i0, %o0! unsigned int
F003D658: 7fff5408                 call    _sleep
F003D65C: 9210200a                 mov     0xA, %o1
F003D660: d4162060                 lduh    [%i0+0x60], %o2
F003D664: 808aa001                 btst    1, %o2
F003D668: 32bffff6                 bne,a   loc_F003D640
F003D66C: d2062068                 ld      [%i0+0x68], %o1
F003D670: 113c04d0                 sethi   -0xFECC000, %o0
F003D674: d0022260                 ld      [%o0+0x260], %o0
F003D678: d216206c                 lduh    [%i0+0x6C], %o1
F003D67C: d0262068                 st      %o0, [%i0+0x68]
F003D680: 92026001                 inc     %o1
F003D684: d0162060                 lduh    [%i0+0x60], %o0
F003D688: d236206c                 sth     %o1, [%i0+0x6C]
F003D68C: 90122001                 bset    1, %o0
F003D690: d0362060                 sth     %o0, [%i0+0x60]
F003D694: 81c7e008                 ret
F003D698: 81e80000                 restore
