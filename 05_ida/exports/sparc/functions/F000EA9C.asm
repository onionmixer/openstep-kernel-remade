F000EA9C: 9de3bf98                 save    %sp, -0x68, %sp
F000EAA0: e0062004                 ld      [%i0+4], %l0
F000EAA4: 80a42000                 cmp     %l0, 0
F000EAA8: 0280001c                 be      locret_F000EB18
F000EAAC: 01000000                 nop
F000EAB0: d04c2013                 ldsb    [%l0+0x13], %o0
F000EAB4: 80a22006                 cmp     %o0, 6
F000EAB8: 12800012                 bne     loc_F000EB00
F000EABC: 01000000                 nop
F000EAC0: e0062004                 ld      [%i0+4], %l0
F000EAC4: 80a42000                 cmp     %l0, 0
F000EAC8: 02800014                 be      locret_F000EB18
F000EACC: 90100010                 mov     %l0, %o0! unsigned int
F000EAD0: 40000aa9                 call    _psignal
F000EAD4: 92102001                 mov     1, %o1! char *
F000EAD8: 90100010                 mov     %l0, %o0! unsigned int
F000EADC: 40000aa6                 call    _psignal
F000EAE0: 92102013                 mov     0x13, %o1
F000EAE4: 4000000f                 call    _get_posix_proc
F000EAE8: d0542030                 ldsh    [%l0+0x30], %o0
F000EAEC: e002200c                 ld      [%o0+0xC], %l0
F000EAF0: 80a42000                 cmp     %l0, 0
F000EAF4: 12bffff7                 bne     loc_F000EAD0
F000EAF8: 90100010                 mov     %l0, %o0
F000EAFC: 30800007                 ba,a    locret_F000EB18
F000EB00: 40000008                 call    _get_posix_proc
F000EB04: d0542030                 ldsh    [%l0+0x30], %o0
F000EB08: e002200c                 ld      [%o0+0xC], %l0
F000EB0C: 80a42000                 cmp     %l0, 0
F000EB10: 32bfffe9                 bne,a   loc_F000EAB4
F000EB14: d04c2013                 ldsb    [%l0+0x13], %o0
F000EB18: 81c7e008                 ret
F000EB1C: 81e80000                 restore
