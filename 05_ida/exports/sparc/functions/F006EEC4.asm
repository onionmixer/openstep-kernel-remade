F006EEC4: 9de3bf98                 save    %sp, -0x68, %sp
F006EEC8: d006612c                 ld      [%i1+0x12C], %o0
F006EECC: 80a60008                 cmp     %i0, %o0
F006EED0: 02800004                 be      loc_F006EEE0
F006EED4: 113c0440                 sethi   %hi(aPsetRemoveProc), %o0! "pset_remove_processor: wrong pset"
F006EED8: 7ffe98a6                 call    _panic
F006EEDC: 90122068                 bset    %lo(aPsetRemoveProc), %o0! "pset_remove_processor: wrong pset"
F006EEE0: d4066134                 ld      [%i1+0x134], %o2
F006EEE4: 9006211c                 add     %i0, 0x11C, %o0
F006EEE8: 80a2000a                 cmp     %o0, %o2
F006EEEC: 12800004                 bne     loc_F006EEFC
F006EEF0: d2066138                 ld      [%i1+0x138], %o1
F006EEF4: 10800004                 ba      loc_F006EF04
F006EEF8: d2262120                 st      %o1, [%i0+0x120]
F006EEFC: d222a138                 st      %o1, [%o2+0x138]
F006EF00: 9006211c                 add     %i0, 0x11C, %o0
F006EF04: 80a20009                 cmp     %o0, %o1
F006EF08: 32800003                 bne,a   loc_F006EF14
F006EF0C: d4226134                 st      %o2, [%o1+0x134]
F006EF10: d426211c                 st      %o2, [%i0+0x11C]
F006EF14: c026612c                 clr     [%i1+0x12C]
F006EF18: d2062124                 ld      [%i0+0x124], %o1
F006EF1C: 90100018                 mov     %i0, %o0
F006EF20: 92027fff                 inc     -1, %o1
F006EF24: 400000f2                 call    _quantum_set
F006EF28: d2222124                 st      %o1, [%o0+0x124]
F006EF2C: 81c7e008                 ret
F006EF30: 81e80000                 restore
