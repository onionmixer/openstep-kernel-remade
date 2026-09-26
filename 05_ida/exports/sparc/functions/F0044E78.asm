F0044E78: 9de3bf98                 save    %sp, -0x68, %sp
F0044E7C: 40008c7d                 call    _kalloc
F0044E80: 90102034                 mov     0x34, %o0 ! '4'
F0044E84: a2100008                 mov     %o0, %l1
F0044E88: 11000008                 sethi   0x2000, %o0
F0044E8C: 40008c79                 call    _kalloc
F0044E90: 90122260                 bset    0x260, %o0
F0044E94: d024602c                 st      %o0, [%l1+0x2C]
F0044E98: 40008c76                 call    _kalloc
F0044E9C: 901021cc                 mov     0x1CC, %o0! void *
F0044EA0: a0100008                 mov     %o0, %l0
F0044EA4: 40013fed                 call    _bzero
F0044EA8: 921021cc                 mov     0x1CC, %o1
F0044EAC: c024600c                 clr     [%l1+0xC]
F0044EB0: e0246030                 st      %l0, [%l1+0x30]
F0044EB4: a004203c                 inc     0x3C, %l0 ! '<'
F0044EB8: e0246024                 st      %l0, [%l1+0x24]
F0044EBC: 113c043790122250         set     _svckudp_op, %o0! SVCXPRT *
F0044EC4: d0246008                 st      %o0, [%l1+8]
F0044EC8: f2346004                 sth     %i1, [%l1+4]
F0044ECC: f0244000                 st      %i0, [%l1]
F0044ED0: 7ffffe1b                 call    _xprt_register
F0044ED4: 90100011                 mov     %l1, %o0
F0044ED8: 81c7e008                 ret
F0044EDC: 91e80011                 restore %g0, %l1, %o0
