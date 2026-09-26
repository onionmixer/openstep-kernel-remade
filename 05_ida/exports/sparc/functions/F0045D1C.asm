F0045D1C: 9de3bf98                 save    %sp, -0x68, %sp
F0045D20: a0100018                 mov     %i0, %l0
F0045D24: d0042014                 ld      [%l0+0x14], %o0
F0045D28: 90023ffc                 inc     -4, %o0
F0045D2C: 80a22000                 cmp     %o0, 0
F0045D30: 16800015                 bge     loc_F0045D84
F0045D34: d0242014                 st      %o0, [%l0+0x14]
F0045D38: 80a23ffc                 cmp     %o0, -4
F0045D3C: 02800004                 be      loc_F0045D4C
F0045D40: 113c0438                 sethi   %hi(aXdrMbufPutlong), %o0! "xdr_mbuf: putlong, long crosses mbufs!"...
F0045D44: 7fff3a45                 call    _printf
F0045D48: 901220f0                 bset    %lo(aXdrMbufPutlong), %o0! "xdr_mbuf: putlong, long crosses mbufs!"...
F0045D4C: d0042010                 ld      [%l0+0x10], %o0
F0045D50: 80a22000                 cmp     %o0, 0
F0045D54: 0280001c                 be      locret_F0045DC4
F0045D58: b0102000                 mov     0, %i0
F0045D5C: d2020000                 ld      [%o0], %o1
F0045D60: 80a26000                 cmp     %o1, 0
F0045D64: 02800018                 be      locret_F0045DC4
F0045D68: d2242010                 st      %o1, [%l0+0x10]
F0045D6C: d0026004                 ld      [%o1+4], %o0
F0045D70: 90024008                 add     %o1, %o0, %o0
F0045D74: d024200c                 st      %o0, [%l0+0xC]
F0045D78: d0526008                 ldsh    [%o1+8], %o0
F0045D7C: 90023ffc                 inc     -4, %o0
F0045D80: d0242014                 st      %o0, [%l0+0x14]
F0045D84: d204200c                 ld      [%l0+0xC], %o1! void *
F0045D88: 808a6003                 btst    3, %o1
F0045D8C: 12800005                 bne     loc_F0045DA0
F0045D90: 90100019                 mov     %i1, %o0
F0045D94: 808e6003                 btst    3, %i1
F0045D98: 22800006                 be,a    loc_F0045DB0
F0045D9C: d0064000                 ld      [%i1], %o0! void *
F0045DA0: 40013b5c                 call    _bcopy
F0045DA4: 94102004                 mov     4, %o2
F0045DA8: 10800004                 ba      loc_F0045DB8
F0045DAC: d004200c                 ld      [%l0+0xC], %o0
F0045DB0: d0224000                 st      %o0, [%o1]
F0045DB4: d004200c                 ld      [%l0+0xC], %o0
F0045DB8: b0102001                 mov     1, %i0
F0045DBC: 90022004                 inc     4, %o0
F0045DC0: d024200c                 st      %o0, [%l0+0xC]
F0045DC4: 81c7e008                 ret
F0045DC8: 81e80000                 restore
