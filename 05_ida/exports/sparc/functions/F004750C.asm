F004750C: 9de3bf98                 save    %sp, -0x68, %sp
F0047510: a0100018                 mov     %i0, %l0
F0047514: 912c2010                 sll     %l0, 16, %o0
F0047518: a33a2010                 sra     %o0, 16, %l1
F004751C: 90100011                 mov     %l1, %o0
F0047520: 92102000                 mov     0, %o1! size_t
F0047524: 400000e8                 call    sub_F00478C4
F0047528: 94100019                 mov     %i1, %o2
F004752C: b0920000                 orcc    %o0, %g0, %i0
F0047530: 3280001a                 bne,a   loc_F0047598
F0047534: d0162040                 lduh    [%i0+0x40], %o0
F0047538: 400082ce                 call    _kalloc
F004753C: 90102068                 mov     0x68, %o0! void *
F0047540: b0100008                 mov     %o0, %i0
F0047544: 40013645                 call    _bzero
F0047548: 92102068                 mov     0x68, %o1 ! 'h'
F004754C: 113c0438901223c8         set     _spec_vnodeops, %o0
F0047554: d0262020                 st      %o0, [%i0+0x20]
F0047558: 80a66003                 cmp     %i1, 3
F004755C: 12800005                 bne     loc_F0047570
F0047560: f226202c                 st      %i1, [%i0+0x2C]
F0047564: 7fffff60                 call    _bdevvp
F0047568: 90100011                 mov     %l1, %o0
F004756C: d026203c                 st      %o0, [%i0+0x3C]
F0047570: c0262038                 clr     [%i0+0x38]
F0047574: e0362042                 sth     %l0, [%i0+0x42]
F0047578: e0362030                 sth     %l0, [%i0+0x30]
F004757C: 90102001                 mov     1, %o0
F0047580: d036200a                 sth     %o0, [%i0+0xA]
F0047584: f0262034                 st      %i0, [%i0+0x34]
F0047588: c0262028                 clr     [%i0+0x28]
F004758C: 4000000e                 call    sub_F00475C4
F0047590: 90100018                 mov     %i0, %o0
F0047594: 3080000a                 ba,a    locret_F00475BC
F0047598: 808a2001                 btst    1, %o0
F004759C: 02800008                 be      locret_F00475BC
F00475A0: 90122010                 bset    0x10, %o0
F00475A4: d0362040                 sth     %o0, [%i0+0x40]
F00475A8: 90100018                 mov     %i0, %o0! unsigned int
F00475AC: 7fff2c33                 call    _sleep
F00475B0: 9210200a                 mov     0xA, %o1
F00475B4: 10bfffd9                 ba      loc_F0047518
F00475B8: 912c2010                 sll     %l0, 16, %o0
F00475BC: 81c7e008                 ret
F00475C0: 91ee2004                 restore %i0, 4, %o0
