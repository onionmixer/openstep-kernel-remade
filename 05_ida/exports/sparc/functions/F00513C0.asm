F00513C0: 9de3bf98                 save    %sp, -0x68, %sp
F00513C4: 90100018                 mov     %i0, %o0
F00513C8: 92103fff                 mov     -1, %o1
F00513CC: f0022030                 ld      [%o0+0x30], %i0
F00513D0: 7fff4fc1                 call    _bflush
F00513D4: 94103fff                 mov     -1, %o2
F00513D8: 213c04d4                 sethi   %hi(_iuniqtime), %l0
F00513DC: 4000747d                 call    _microtime
F00513E0: 90142148                 or      %l0, %lo(_iuniqtime), %o0
F00513E4: d0162044                 lduh    [%i0+0x44], %o0
F00513E8: 808a2004                 btst    4, %o0
F00513EC: 02800003                 be      loc_F00513F8
F00513F0: d0042148                 ld      [%l0+%lo(_iuniqtime)], %o0
F00513F4: d0262074                 st      %o0, [%i0+0x74]
F00513F8: d0162044                 lduh    [%i0+0x44], %o0
F00513FC: 808a2002                 btst    2, %o0
F0051400: 02800003                 be      loc_F005140C
F0051404: d0042148                 ld      [%l0+0x148], %o0
F0051408: d026207c                 st      %o0, [%i0+0x7C]
F005140C: d0162044                 lduh    [%i0+0x44], %o0
F0051410: 808a2040                 btst    0x40, %o0 ! '@'
F0051414: 22800006                 be,a    loc_F005142C
F0051418: d2162044                 lduh    [%i0+0x44], %o1
F005141C: c026204c                 clr     [%i0+0x4C]
F0051420: d0042148                 ld      [%l0+0x148], %o0
F0051424: d0262084                 st      %o0, [%i0+0x84]
F0051428: d2162044                 lduh    [%i0+0x44], %o1
F005142C: 1100003f901223fd         set     0xFFFD, %o0
F0051434: 920a4008                 and     %o1, %o0, %o1
F0051438: d2362044                 sth     %o1, [%i0+0x44]
F005143C: 81c7e008                 ret
F0051440: 91e82000                 restore %g0, 0, %o0
