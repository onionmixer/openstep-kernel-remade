F008C904: 9de3bf90                 save    %sp, -0x70, %sp
F008C908: 4000290f                 call    _curipl
F008C90C: 01000000                 nop
F008C910: d2062008                 ld      [%i0+8], %o1
F008C914: a0100008                 mov     %o0, %l0
F008C918: 80a40009                 cmp     %l0, %o1
F008C91C: 36800007                 bge,a   locret_F008C938
F008C920: e026200c                 st      %l0, [%i0+0xC]
F008C924: 400035e3                 call    _ipltospl
F008C928: 90100009                 mov     %o1, %o0
F008C92C: 400028fe                 call    _splx
F008C930: 01000000                 nop
F008C934: e026200c                 st      %l0, [%i0+0xC]
F008C938: 81c7e008                 ret
F008C93C: 81e80000                 restore
