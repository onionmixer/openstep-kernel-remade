F00D28E8: 9de3bf90                 save    %sp, -0x70, %sp
F00D28EC: d04e21d0                 ldsb    [%i0+0x1D0], %o0
F00D28F0: 80a22000                 cmp     %o0, 0
F00D28F4: 12800004                 bne     loc_F00D2904
F00D28F8: e006a004                 ld      [%i2+4], %l0
F00D28FC: 10800059                 ba      locret_F00D2A60
F00D2900: b0103d3f                 mov     -0x2C1, %i0
F00D2904: d0062180                 ld      [%i0+0x180], %o0
F00D2908: 80a22000                 cmp     %o0, 0
F00D290C: 12800014                 bne     loc_F00D295C
F00D2910: 80a42000                 cmp     %l0, 0
F00D2914: d2068000                 ld      [%i2], %o1
F00D2918: 912a6002                 sll     %o1, 2, %o0
F00D291C: 90020009                 add     %o0, %o1, %o0
F00D2920: 912a2002                 sll     %o0, 2, %o0! void *
F00D2924: 7fffcd83                 call    _IOMalloc
F00D2928: d026217c                 st      %o0, [%i0+0x17C]
F00D292C: d206217c                 ld      [%i0+0x17C], %o1! size_t
F00D2930: 7fff094a                 call    _bzero
F00D2934: d0262180                 st      %o0, [%i0+0x180]
F00D2938: 90102e18                 mov     0xE18, %o0
F00D293C: d0262160                 st      %o0, [%i0+0x160]
F00D2940: c0262184                 clr     [%i0+0x184]
F00D2944: c0262188                 clr     [%i0+0x188]
F00D2948: c036219e                 clrh    [%i0+0x19E]
F00D294C: c036219a                 clrh    [%i0+0x19A]
F00D2950: c036219c                 clrh    [%i0+0x19C]
F00D2954: c0362198                 clrh    [%i0+0x198]
F00D2958: 80a42000                 cmp     %l0, 0
F00D295C: 26800041                 bl,a    locret_F00D2A60
F00D2960: b0103d3e                 mov     -0x2C2, %i0
F00D2964: d006217c                 ld      [%i0+0x17C], %o0
F00D2968: 7ffccf26                 call    _udiv
F00D296C: 92102014                 mov     0x14, %o1
F00D2970: 80a40008                 cmp     %l0, %o0
F00D2974: 0a800004                 bcs     loc_F00D2984
F00D2978: 912c2002                 sll     %l0, 2, %o0
F00D297C: 10800039                 ba      locret_F00D2A60
F00D2980: b0103d3e                 mov     -0x2C2, %i0
F00D2984: 90020010                 add     %o0, %l0, %o0
F00D2988: d4062180                 ld      [%i0+0x180], %o2
F00D298C: 912a2002                 sll     %o0, 2, %o0
F00D2990: d206a00c                 ld      [%i2+0xC], %o1
F00D2994: 94028008                 add     %o2, %o0, %o2
F00D2998: d232a00c                 sth     %o1, [%o2+0xC]
F00D299C: d006a010                 ld      [%i2+0x10], %o0
F00D29A0: d032a00e                 sth     %o0, [%o2+0xE]
F00D29A4: d006a014                 ld      [%i2+0x14], %o0
F00D29A8: d032a010                 sth     %o0, [%o2+0x10]
F00D29AC: d006a018                 ld      [%i2+0x18], %o0
F00D29B0: d032a012                 sth     %o0, [%o2+0x12]
F00D29B4: d006a008                 ld      [%i2+8], %o0
F00D29B8: d022a008                 st      %o0, [%o2+8]
F00D29BC: d0062160                 ld      [%i0+0x160], %o0
F00D29C0: d206a008                 ld      [%i2+8], %o1
F00D29C4: 90020009                 add     %o0, %o1, %o0
F00D29C8: d0262160                 st      %o0, [%i0+0x160]
F00D29CC: d012a00c                 lduh    [%o2+0xC], %o0
F00D29D0: d2562198                 ldsh    [%i0+0x198], %o1
F00D29D4: 912a2010                 sll     %o0, 16, %o0
F00D29D8: 913a2010                 sra     %o0, 16, %o0
F00D29DC: 80a20009                 cmp     %o0, %o1
F00D29E0: 16800004                 bge     loc_F00D29F0
F00D29E4: 01000000                 nop
F00D29E8: d012a00c                 lduh    [%o2+0xC], %o0
F00D29EC: d0362198                 sth     %o0, [%i0+0x198]
F00D29F0: d012a010                 lduh    [%o2+0x10], %o0
F00D29F4: d256219c                 ldsh    [%i0+0x19C], %o1
F00D29F8: 912a2010                 sll     %o0, 16, %o0
F00D29FC: 913a2010                 sra     %o0, 16, %o0
F00D2A00: 80a20009                 cmp     %o0, %o1
F00D2A04: 16800004                 bge     loc_F00D2A14
F00D2A08: 01000000                 nop
F00D2A0C: d012a010                 lduh    [%o2+0x10], %o0
F00D2A10: d036219c                 sth     %o0, [%i0+0x19C]
F00D2A14: d012a00e                 lduh    [%o2+0xE], %o0
F00D2A18: d256219a                 ldsh    [%i0+0x19A], %o1
F00D2A1C: 912a2010                 sll     %o0, 16, %o0
F00D2A20: 913a2010                 sra     %o0, 16, %o0
F00D2A24: 80a20009                 cmp     %o0, %o1
F00D2A28: 16800004                 bge     loc_F00D2A38
F00D2A2C: 01000000                 nop
F00D2A30: d012a00e                 lduh    [%o2+0xE], %o0
F00D2A34: d036219a                 sth     %o0, [%i0+0x19A]
F00D2A38: d012a012                 lduh    [%o2+0x12], %o0
F00D2A3C: d256219e                 ldsh    [%i0+0x19E], %o1
F00D2A40: 912a2010                 sll     %o0, 16, %o0
F00D2A44: 913a2010                 sra     %o0, 16, %o0
F00D2A48: 80a20009                 cmp     %o0, %o1
F00D2A4C: 36800005                 bge,a   locret_F00D2A60
F00D2A50: b0102000                 mov     0, %i0
F00D2A54: d012a012                 lduh    [%o2+0x12], %o0
F00D2A58: d036219e                 sth     %o0, [%i0+0x19E]
F00D2A5C: b0102000                 mov     0, %i0
F00D2A60: 81c7e008                 ret
F00D2A64: 81e80000                 restore
