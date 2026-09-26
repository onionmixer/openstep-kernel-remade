F00B4BDC: 9de3bf98                 save    %sp, -0x68, %sp
F00B4BE0: 80a66000                 cmp     %i1, 0
F00B4BE4: 12800004                 bne     loc_F00B4BF4
F00B4BE8: a0102000                 mov     0, %l0
F00B4BEC: 1102aea5b2122100         set     0xABA9500, %i1
F00B4BF4: 80a40019                 cmp     %l0, %i1
F00B4BF8: 16800011                 bge     loc_F00B4C3C
F00B4BFC: 01000000                 nop
F00B4C00: 4000001d                 call    _esp_poll
F00B4C04: 01000000                 nop
F00B4C08: 80a22000                 cmp     %o0, 0
F00B4C0C: 32800005                 bne,a   loc_F00B4C20
F00B4C10: d00e2041                 ldub    [%i0+0x41], %o0
F00B4C14: 7fff8b13                 call    _us_spin
F00B4C18: 90102064                 mov     0x64, %o0 ! 'd'
F00B4C1C: d00e2041                 ldub    [%i0+0x41], %o0
F00B4C20: 80a22000                 cmp     %o0, 0
F00B4C24: 02800006                 be      loc_F00B4C3C
F00B4C28: 80a40019                 cmp     %l0, %i1
F00B4C2C: a0042064                 inc     0x64, %l0 ! 'd'
F00B4C30: 80a40019                 cmp     %l0, %i1
F00B4C34: 06bffff3                 bl      loc_F00B4C00
F00B4C38: 01000000                 nop
F00B4C3C: 2680000c                 bl,a    locret_F00B4C6C
F00B4C40: b0102000                 mov     0, %i0
F00B4C44: d00e2041                 ldub    [%i0+0x41], %o0
F00B4C48: 80a22000                 cmp     %o0, 0
F00B4C4C: 02800007                 be      loc_F00B4C68
F00B4C50: 90100018                 mov     %i0, %o0
F00B4C54: 133c0479                 sethi   %hi(aPolledCommandT), %o1! "polled command timeout"
F00B4C58: 40000c2f                 call    _esp_printstate
F00B4C5C: 921260a8                 bset    %lo(aPolledCommandT), %o1! "polled command timeout"
F00B4C60: 10800003                 ba      locret_F00B4C6C
F00B4C64: b0103fff                 mov     -1, %i0
F00B4C68: b0102000                 mov     0, %i0
F00B4C6C: 81c7e008                 ret
F00B4C70: 81e80000                 restore
