F0046F88: 9de3bf98                 save    %sp, -0x68, %sp
F0046F8C: 80a66001                 cmp     %i1, 1
F0046F90: 0280000e                 be      loc_F0046FC8
F0046F94: f0062030                 ld      [%i0+0x30], %i0
F0046F98: 80a66001                 cmp     %i1, 1
F0046F9C: 14800007                 bg      loc_F0046FB8
F0046FA0: 80a66002                 cmp     %i1, 2
F0046FA4: 80a66000                 cmp     %i1, 0
F0046FA8: 22800025                 be,a    loc_F004703C
F0046FAC: d0562082                 ldsh    [%i0+0x82], %o0
F0046FB0: 10800031                 ba      locret_F0047074
F0046FB4: b0102000                 mov     0, %i0
F0046FB8: 22800010                 be,a    loc_F0046FF8
F0046FBC: d006207c                 ld      [%i0+0x7C], %o0
F0046FC0: 1080002d                 ba      locret_F0047074
F0046FC4: b0102000                 mov     0, %i0
F0046FC8: d006207c                 ld      [%i0+0x7C], %o0
F0046FCC: 80a22000                 cmp     %o0, 0
F0046FD0: 32800029                 bne,a   locret_F0047074
F0046FD4: b0102001                 mov     1, %i0
F0046FD8: 7fff3c1a                 call    _selthreadcache
F0046FDC: 90062070                 add     %i0, 0x70, %o0 ! 'p'
F0046FE0: 80a22000                 cmp     %o0, 0
F0046FE4: 22800024                 be,a    locret_F0047074
F0046FE8: b0102000                 mov     0, %i0
F0046FEC: d0162088                 lduh    [%i0+0x88], %o0
F0046FF0: 1080001f                 ba      loc_F004706C
F0046FF4: 90122004                 bset    4, %o0
F0046FF8: 133c043c                 sethi   %hi(_fifoinfo), %o1
F0046FFC: d2026394                 ld      [%o1+%lo(_fifoinfo)], %o1
F0047000: 80a20009                 cmp     %o0, %o1
F0047004: 1a800006                 bcc     loc_F004701C
F0047008: 01000000                 nop
F004700C: d0562082                 ldsh    [%i0+0x82], %o0
F0047010: 80a22000                 cmp     %o0, 0
F0047014: 34800018                 bg,a    locret_F0047074
F0047018: b0102001                 mov     1, %i0
F004701C: 7fff3c09                 call    _selthreadcache
F0047020: 90062074                 add     %i0, 0x74, %o0 ! 't'
F0047024: 80a22000                 cmp     %o0, 0
F0047028: 22800013                 be,a    locret_F0047074
F004702C: b0102000                 mov     0, %i0
F0047030: d0162088                 lduh    [%i0+0x88], %o0
F0047034: 1080000e                 ba      loc_F004706C
F0047038: 90122008                 bset    8, %o0
F004703C: 80a22000                 cmp     %o0, 0
F0047040: 12800004                 bne     loc_F0047050
F0047044: 01000000                 nop
F0047048: 1080000b                 ba      locret_F0047074
F004704C: b0102001                 mov     1, %i0
F0047050: 7fff3bfc                 call    _selthreadcache
F0047054: 90062078                 add     %i0, 0x78, %o0 ! 'x'
F0047058: 80a22000                 cmp     %o0, 0
F004705C: 22800006                 be,a    locret_F0047074
F0047060: b0102000                 mov     0, %i0
F0047064: d0162088                 lduh    [%i0+0x88], %o0
F0047068: 90122010                 bset    0x10, %o0
F004706C: d0362088                 sth     %o0, [%i0+0x88]
F0047070: b0102000                 mov     0, %i0
F0047074: 81c7e008                 ret
F0047078: 81e80000                 restore
