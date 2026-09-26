F006FB2C: 9de3bf98                 save    %sp, -0x68, %sp
F006FB30: 113c0440                 sethi   %hi(aKdpUnknownRequ), %o0! "kdp_unknown request %x len %d seq %x ke"...
F006FB34: 1500003f                 sethi   0xFC00, %o2
F006FB38: da060000                 ld      [%i0], %o5
F006FB3C: 9412a3ff                 bset    0x3FF, %o2
F006FB40: d60e2001                 ldub    [%i0+1], %o3
F006FB44: 90122178                 bset    %lo(aKdpUnknownRequ), %o0! "kdp_unknown request %x len %d seq %x ke"...
F006FB48: d8062004                 ld      [%i0+4], %o4
F006FB4C: 93336019                 srl     %o5, 25, %o1
F006FB50: 7ffff92a                 call    _safe_prf
F006FB54: 940b400a                 and     %o5, %o2, %o2
F006FB58: 81c7e008                 ret
F006FB5C: 91e82000                 restore %g0, 0, %o0
