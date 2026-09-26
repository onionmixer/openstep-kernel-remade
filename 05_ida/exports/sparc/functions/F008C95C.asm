F008C95C: 9de3bf98                 save    %sp, -0x68, %sp
F008C960: 400028f9                 call    _curipl
F008C964: a2100018                 mov     %i0, %l1
F008C968: 80a62000                 cmp     %i0, 0
F008C96C: 0280000b                 be      locret_F008C998
F008C970: a0100008                 mov     %o0, %l0
F008C974: d0062008                 ld      [%i0+8], %o0
F008C978: 80a40008                 cmp     %l0, %o0
F008C97C: 36800007                 bge,a   locret_F008C998
F008C980: e024600c                 st      %l0, [%l1+0xC]
F008C984: 400035cb                 call    _ipltospl
F008C988: 01000000                 nop
F008C98C: 400028e6                 call    _splx
F008C990: 01000000                 nop
F008C994: e024600c                 st      %l0, [%l1+0xC]
F008C998: 81c7e008                 ret
F008C99C: 81e80000                 restore
