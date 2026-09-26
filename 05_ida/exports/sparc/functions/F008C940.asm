F008C940: 9de3bf90                 save    %sp, -0x70, %sp
F008C944: 400035db                 call    _ipltospl
F008C948: d006200c                 ld      [%i0+0xC], %o0
F008C94C: 400028f6                 call    _splx
F008C950: 01000000                 nop
F008C954: 81c7e008                 ret
F008C958: 81e80000                 restore
