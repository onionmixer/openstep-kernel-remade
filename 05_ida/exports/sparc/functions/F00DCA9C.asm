F00DCA9C: 9de3bf90                 save    %sp, -0x70, %sp
F00DCAA0: 9010001a                 mov     %i2, %o0! void *
F00DCAA4: 80a72003                 cmp     %i4, 3
F00DCAA8: 1280000c                 bne     loc_F00DCAD8
F00DCAAC: 9210001b                 mov     %i3, %o1
F00DCAB0: 92027fff                 inc     -1, %o1
F00DCAB4: 80a27fff                 cmp     %o1, -1
F00DCAB8: 02800017                 be      locret_F00DCB14
F00DCABC: 94103f80                 mov     -0x80, %o2
F00DCAC0: d42a0000                 stb     %o2, [%o0]
F00DCAC4: 92027fff                 inc     -1, %o1
F00DCAC8: 80a27fff                 cmp     %o1, -1
F00DCACC: 12bffffd                 bne     loc_F00DCAC0
F00DCAD0: 90022001                 inc     %o0
F00DCAD4: 30800010                 ba,a    locret_F00DCB14
F00DCAD8: 80a72001                 cmp     %i4, 1
F00DCADC: 1280000c                 bne     loc_F00DCB0C
F00DCAE0: 01000000                 nop
F00DCAE4: 92027fff                 inc     -1, %o1
F00DCAE8: 80a27fff                 cmp     %o1, -1
F00DCAEC: 0280000a                 be      locret_F00DCB14
F00DCAF0: 9410207f                 mov     0x7F, %o2
F00DCAF4: d42a0000                 stb     %o2, [%o0]
F00DCAF8: 92027fff                 inc     -1, %o1! size_t
F00DCAFC: 80a27fff                 cmp     %o1, -1
F00DCB00: 12bffffd                 bne     loc_F00DCAF4
F00DCB04: 90022001                 inc     %o0
F00DCB08: 30800003                 ba,a    locret_F00DCB14
F00DCB0C: 7ffee0d3                 call    _bzero
F00DCB10: 01000000                 nop
F00DCB14: 81c7e008                 ret
F00DCB18: 81e80000                 restore
