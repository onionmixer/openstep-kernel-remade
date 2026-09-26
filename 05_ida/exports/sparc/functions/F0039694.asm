F0039694: 9de3bf98                 save    %sp, -0x68, %sp
F0039698: d4062030                 ld      [%i0+0x30], %o2
F003969C: d012a010                 lduh    [%o2+0x10], %o0
F00396A0: 808a2080                 btst    0x80, %o0
F00396A4: 12800012                 bne     locret_F00396EC
F00396A8: 01000000                 nop
F00396AC: d2064000                 ld      [%i1], %o1
F00396B0: d002a0a8                 ld      [%o2+0xA8], %o0
F00396B4: 80a24008                 cmp     %o1, %o0
F00396B8: 1280000b                 bne     loc_F00396E4
F00396BC: 90100018                 mov     %i0, %o0
F00396C0: d2066004                 ld      [%i1+4], %o1
F00396C4: d002a0ac                 ld      [%o2+0xAC], %o0
F00396C8: 80a24008                 cmp     %o1, %o0
F00396CC: 12800006                 bne     loc_F00396E4
F00396D0: 90100018                 mov     %i0, %o0
F00396D4: d002a098                 ld      [%o2+0x98], %o0
F00396D8: 80a68008                 cmp     %i2, %o0
F00396DC: 02800004                 be      locret_F00396EC
F00396E0: 90100018                 mov     %i0, %o0
F00396E4: 7fffffde                 call    _nfs_purge_caches
F00396E8: 9210001b                 mov     %i3, %o1
F00396EC: 81c7e008                 ret
F00396F0: 81e80000                 restore
