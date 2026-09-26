F009BD70: 9de3bf98                 save    %sp, -0x68, %sp
F009BD74: d0062028                 ld      [%i0+0x28], %o0
F009BD78: 7ffff38a                 call    _fpu_fork_context
F009BD7C: d2066028                 ld      [%i1+0x28], %o1
F009BD80: e0066028                 ld      [%i1+0x28], %l0
F009BD84: 9410204c                 mov     0x4C, %o2 ! 'L'! __n
F009BD88: d2062028                 ld      [%i0+0x28], %o1! __src
F009BD8C: 90042234                 add     %l0, 0x234, %o0! __dst
F009BD90: 7ffdad44                 call    _memcpy
F009BD94: 92026234                 inc     0x234, %o1
F009BD98: d204223c                 ld      [%l0+0x23C], %o1
F009BD9C: c024225c                 clr     [%l0+0x25C]
F009BDA0: d004223c                 ld      [%l0+0x23C], %o0
F009BDA4: d2242238                 st      %o1, [%l0+0x238]
F009BDA8: 90022004                 inc     4, %o0
F009BDAC: d024223c                 st      %o0, [%l0+0x23C]
F009BDB0: d2042234                 ld      [%l0+0x234], %o1
F009BDB4: 11000400                 sethi   0x100000, %o0
F009BDB8: 902a4008                 andn    %o1, %o0, %o0
F009BDBC: d0242234                 st      %o0, [%l0+0x234]
F009BDC0: d006600c                 ld      [%i1+0xC], %o0
F009BDC4: d002203c                 ld      [%o0+0x3C], %o0
F009BDC8: d0522030                 ldsh    [%o0+0x30], %o0
F009BDCC: d0242260                 st      %o0, [%l0+0x260]
F009BDD0: 90102001                 mov     1, %o0
F009BDD4: d0242264                 st      %o0, [%l0+0x264]
F009BDD8: 81c7e008                 ret
F009BDDC: 81e80000                 restore
