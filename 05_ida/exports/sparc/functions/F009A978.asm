F009A978: 9de3bf98                 save    %sp, -0x68, %sp
F009A97C: 90100018                 mov     %i0, %o0
F009A980: 92100019                 mov     %i1, %o1
F009A984: f0024000                 ld      [%o1], %i0
F009A988: 80a60008                 cmp     %i0, %o0
F009A98C: 02800014                 be      locret_F009A9DC
F009A990: 01000000                 nop
F009A994: 7ffff138                 call    _swapl
F009A998: 01000000                 nop
F009A99C: 808e2003                 btst    3, %i0
F009A9A0: 0280000f                 be      locret_F009A9DC
F009A9A4: 80a73fff                 cmp     %i4, -1
F009A9A8: 0280000d                 be      locret_F009A9DC
F009A9AC: 9010001b                 mov     %i3, %o0
F009A9B0: 9210001a                 mov     %i2, %o1
F009A9B4: 40002838                 call    _srmmu_tlbflush
F009A9B8: 9410001c                 mov     %i4, %o2
F009A9BC: 113c0464                 sethi   %hi(_vac), %o0
F009A9C0: d0022334                 ld      [%o0+%lo(_vac)], %o0
F009A9C4: 80a22000                 cmp     %o0, 0
F009A9C8: 02800005                 be      locret_F009A9DC
F009A9CC: 9010001b                 mov     %i3, %o0
F009A9D0: 9210001a                 mov     %i2, %o1
F009A9D4: 4000284c                 call    _srmmu_vacflush
F009A9D8: 9410001c                 mov     %i4, %o2
F009A9DC: 81c7e008                 ret
F009A9E0: 81e80000                 restore
