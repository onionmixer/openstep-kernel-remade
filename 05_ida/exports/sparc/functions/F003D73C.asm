F003D73C: 9de3bf98                 save    %sp, -0x68, %sp
F003D740: a0100018                 mov     %i0, %l0
F003D744: d4142060                 lduh    [%l0+0x60], %o2
F003D748: 808aa001                 btst    1, %o2
F003D74C: 02800035                 be      loc_F003D820
F003D750: 113c00f5                 sethi   %hi(sub_F003D710), %o0
F003D754: 293c04d0                 sethi   -0xFECC000, %l4
F003D758: 273c04ea                 sethi   -0xFEC5800, %l3
F003D75C: a2122310                 or      %o0, %lo(sub_F003D710), %l1
F003D760: 253c04ea                 sethi   -0xFEC5800, %l2
F003D764: d2042068                 ld      [%l0+0x68], %o1
F003D768: d0052260                 ld      [%l4+0x260], %o0
F003D76C: 80a24008                 cmp     %o1, %o0
F003D770: 0280002c                 be      loc_F003D820
F003D774: 808aa020                 btst    0x20, %o2 ! ' '
F003D778: 02800006                 be      loc_F003D790
F003D77C: b0102001                 mov     1, %i0
F003D780: d004e258                 ld      [%l3+0x258], %o0
F003D784: 90022001                 inc     %o0
F003D788: 10800030                 ba      locret_F003D848
F003D78C: d024e258                 st      %o0, [%l3+0x258]
F003D790: 9012a002                 or      %o2, 2, %o0
F003D794: 400164fd                 call    _splusclock
F003D798: d0342060                 sth     %o0, [%l0+0x60]
F003D79C: 133c043e                 sethi   %hi(_hz), %o1
F003D7A0: d20263e0                 ld      [%o1+%lo(_hz)], %o1
F003D7A4: b0100008                 mov     %o0, %i0
F003D7A8: 7fff2356                 call    _umul
F003D7AC: 90100019                 mov     %i1, %o0
F003D7B0: 94100008                 mov     %o0, %o2
F003D7B4: 90100011                 mov     %l1, %o0! int
F003D7B8: 7fff321c                 call    _timeout
F003D7BC: 92100010                 mov     %l0, %o1
F003D7C0: 90100010                 mov     %l0, %o0! unsigned int
F003D7C4: 7fff53ad                 call    _sleep
F003D7C8: 9210200a                 mov     0xA, %o1
F003D7CC: 90100011                 mov     %l1, %o0
F003D7D0: 7fff3221                 call    _untimeout
F003D7D4: 92100010                 mov     %l0, %o1
F003D7D8: 80a22000                 cmp     %o0, 0
F003D7DC: 1280000b                 bne     loc_F003D808
F003D7E0: d404a260                 ld      [%l2+0x260], %o2
F003D7E4: 90100018                 mov     %i0, %o0
F003D7E8: d2142060                 lduh    [%l0+0x60], %o1
F003D7EC: 9402a001                 inc     %o2
F003D7F0: d424a260                 st      %o2, [%l2+0x260]
F003D7F4: 92126020                 bset    0x20, %o1 ! ' '
F003D7F8: 4001654b                 call    _splx
F003D7FC: d2342060                 sth     %o1, [%l0+0x60]
F003D800: 10800012                 ba      locret_F003D848
F003D804: b0102001                 mov     1, %i0
F003D808: 40016547                 call    _splx
F003D80C: 90100018                 mov     %i0, %o0
F003D810: d4142060                 lduh    [%l0+0x60], %o2
F003D814: 808aa001                 btst    1, %o2
F003D818: 32bfffd4                 bne,a   loc_F003D768
F003D81C: d2042068                 ld      [%l0+0x68], %o1
F003D820: 113c04d0                 sethi   %hi(_active_threads), %o0
F003D824: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F003D828: b0102000                 mov     0, %i0
F003D82C: d214206c                 lduh    [%l0+0x6C], %o1
F003D830: d0242068                 st      %o0, [%l0+0x68]
F003D834: 92026001                 inc     %o1
F003D838: d0142060                 lduh    [%l0+0x60], %o0
F003D83C: d234206c                 sth     %o1, [%l0+0x6C]
F003D840: 90122001                 bset    1, %o0
F003D844: d0342060                 sth     %o0, [%l0+0x60]
F003D848: 81c7e008                 ret
F003D84C: 81e80000                 restore
