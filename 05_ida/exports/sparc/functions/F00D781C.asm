F00D781C: 9de3bf90                 save    %sp, -0x70, %sp
F00D7820: d006213c                 ld      [%i0+0x13C], %o0
F00D7824: 80a22000                 cmp     %o0, 0
F00D7828: 32800012                 bne,a   loc_F00D7870
F00D782C: 113c0505                 sethi   -0xFEBEC00, %o0
F00D7830: 7fffb9c0                 call    _IOMalloc
F00D7834: 90102018                 mov     0x18, %o0
F00D7838: d026213c                 st      %o0, [%i0+0x13C]
F00D783C: 92102001                 mov     1, %o1
F00D7840: d22a2003                 stb     %o1, [%o0+3]
F00D7844: d206213c                 ld      [%i0+0x13C], %o1
F00D7848: 90102018                 mov     0x18, %o0
F00D784C: d0226004                 st      %o0, [%o1+4]
F00D7850: d006213c                 ld      [%i0+0x13C], %o0
F00D7854: c0222008                 clr     [%o0+8]
F00D7858: d006213c                 ld      [%i0+0x13C], %o0
F00D785C: c022200c                 clr     [%o0+0xC]
F00D7860: d206213c                 ld      [%i0+0x13C], %o1
F00D7864: d0062134                 ld      [%i0+0x134], %o0
F00D7868: d0226010                 st      %o0, [%o1+0x10]
F00D786C: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D7870: d2022214                 ld      [%o0+0x214], %o1! SEL
F00D7874: 400067ff                 call    _objc_msgSend
F00D7878: 9010001a                 mov     %i2, %o0
F00D787C: 912a2018                 sll     %o0, 24, %o0
F00D7880: 80a22000                 cmp     %o0, 0
F00D7884: 02800004                 be      loc_F00D7894
F00D7888: 90102385                 mov     0x385, %o0
F00D788C: 10800004                 ba      loc_F00D789C
F00D7890: d206213c                 ld      [%i0+0x13C], %o1
F00D7894: d206213c                 ld      [%i0+0x13C], %o1
F00D7898: 90102384                 mov     0x384, %o0
F00D789C: d0226014                 st      %o0, [%o1+0x14]
F00D78A0: d006213c                 ld      [%i0+0x13C], %o0
F00D78A4: 92102001                 mov     1, %o1
F00D78A8: 7ffe38e1                 call    _msg_send_from_kernel
F00D78AC: 941023e8                 mov     0x3E8, %o2
F00D78B0: 92920000                 orcc    %o0, %g0, %o1
F00D78B4: 02800006                 be      locret_F00D78CC
F00D78B8: 80a27f99                 cmp     %o1, -0x67
F00D78BC: 02800004                 be      locret_F00D78CC
F00D78C0: 113c03f0                 sethi   %hi(aAudioDataPendi), %o0! "Audio: data pending msg_send error: %d"...
F00D78C4: 7fffba0c                 call    _IOLog
F00D78C8: 90122168                 bset    %lo(aAudioDataPendi), %o0! "Audio: data pending msg_send error: %d"...
F00D78CC: 81c7e008                 ret
F00D78D0: 81e80000                 restore
