F008C9A0: 9de3bf98                 save    %sp, -0x68, %sp
F008C9A4: 80a62000                 cmp     %i0, 0
F008C9A8: 02800006                 be      locret_F008C9C0
F008C9AC: 01000000                 nop
F008C9B0: 400035c0                 call    _ipltospl
F008C9B4: d006200c                 ld      [%i0+0xC], %o0
F008C9B8: 400028db                 call    _splx
F008C9BC: 01000000                 nop
F008C9C0: 81c7e008                 ret
F008C9C4: 81e80000                 restore
