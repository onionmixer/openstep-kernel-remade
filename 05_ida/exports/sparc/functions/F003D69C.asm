F003D69C: 9de3bf98                 save    %sp, -0x68, %sp
F003D6A0: d016206c                 lduh    [%i0+0x6C], %o0
F003D6A4: 90023fff                 inc     -1, %o0
F003D6A8: d036206c                 sth     %o0, [%i0+0x6C]
F003D6AC: 912a2010                 sll     %o0, 16, %o0
F003D6B0: 80a22000                 cmp     %o0, 0
F003D6B4: 36800006                 bge,a   loc_F003D6CC
F003D6B8: d056206c                 ldsh    [%i0+0x6C], %o0
F003D6BC: 113c0434                 sethi   %hi(aRunlock), %o0! "RUNLOCK"
F003D6C0: 7fff5eac                 call    _panic
F003D6C4: 90122088                 bset    %lo(aRunlock), %o0! "RUNLOCK"
F003D6C8: d056206c                 ldsh    [%i0+0x6C], %o0
F003D6CC: 80a22000                 cmp     %o0, 0
F003D6D0: 1280000e                 bne     locret_F003D708
F003D6D4: 1100003f                 sethi   0xFC00, %o0
F003D6D8: d2162060                 lduh    [%i0+0x60], %o1
F003D6DC: 901223de                 bset    0x3DE, %o0
F003D6E0: 920a4008                 and     %o1, %o0, %o1
F003D6E4: 808a6002                 btst    2, %o1
F003D6E8: 02800008                 be      locret_F003D708
F003D6EC: d2362060                 sth     %o1, [%i0+0x60]
F003D6F0: 1100003f901223fd         set     0xFFFD, %o0
F003D6F8: 900a4008                 and     %o1, %o0, %o0
F003D6FC: d0362060                 sth     %o0, [%i0+0x60]
F003D700: 7fff55ba                 call    _wakeup
F003D704: 90100018                 mov     %i0, %o0
F003D708: 81c7e008                 ret
F003D70C: 81e80000                 restore
