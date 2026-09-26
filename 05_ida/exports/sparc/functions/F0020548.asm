F0020548: 9de3bf98                 save    %sp, -0x68, %sp
F002054C: 92964000                 orcc    %i1, %g0, %o1
F0020550: 02800014                 be      locret_F00205A0
F0020554: 01000000                 nop
F0020558: d406200c                 ld      [%i0+0xC], %o2
F002055C: 80a2a000                 cmp     %o2, 0
F0020560: 0280000e                 be      loc_F0020598
F0020564: 01000000                 nop
F0020568: 10800003                 ba      loc_F0020574
F002056C: d002a07c                 ld      [%o2+0x7C], %o0
F0020570: d002a07c                 ld      [%o2+0x7C], %o0
F0020574: 80a22000                 cmp     %o0, 0
F0020578: 32bffffe                 bne,a   loc_F0020570
F002057C: d402a07c                 ld      [%o2+0x7C], %o2
F0020580: 10800003                 ba      loc_F002058C
F0020584: d0028000                 ld      [%o2], %o0
F0020588: d0028000                 ld      [%o2], %o0
F002058C: 80a22000                 cmp     %o0, 0
F0020590: 32bffffe                 bne,a   loc_F0020588
F0020594: d4028000                 ld      [%o2], %o2
F0020598: 400000fe                 call    _sbcompress
F002059C: 90100018                 mov     %i0, %o0
F00205A0: 81c7e008                 ret
F00205A4: 81e80000                 restore
