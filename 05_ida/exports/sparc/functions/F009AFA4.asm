F009AFA4: 9de3bf98                 save    %sp, -0x68, %sp
F009AFA8: 92100019                 mov     %i1, %o1
F009AFAC: e0024000                 ld      [%o1], %l0
F009AFB0: 7fffefb1                 call    _swapl
F009AFB4: 90100018                 mov     %i0, %o0
F009AFB8: a00c2003                 and     %l0, 3, %l0
F009AFBC: 80a42001                 cmp     %l0, 1
F009AFC0: 12800007                 bne     locret_F009AFDC
F009AFC4: 80a73fff                 cmp     %i4, -1
F009AFC8: 02800005                 be      locret_F009AFDC
F009AFCC: 9010001b                 mov     %i3, %o0
F009AFD0: 9210001a                 mov     %i2, %o1
F009AFD4: 400026b0                 call    _srmmu_tlbflush
F009AFD8: 9410001c                 mov     %i4, %o2
F009AFDC: 81c7e008                 ret
F009AFE0: 81e80000                 restore
