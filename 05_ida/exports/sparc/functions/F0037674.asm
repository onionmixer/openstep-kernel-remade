F0037674: 9de3bf98                 save    %sp, -0x68, %sp
F0037678: d006201c                 ld      [%i0+0x1C], %o0
F003767C: d2522006                 ldsh    [%o0+6], %o1
F0037680: 80a26004                 cmp     %o1, 4
F0037684: 0280000c                 be      loc_F00376B4
F0037688: d4122056                 lduh    [%o0+0x56], %o2
F003768C: 80a2a041                 cmp     %o2, 0x41 ! 'A'
F0037690: 02800007                 be      loc_F00376AC
F0037694: 80a2a033                 cmp     %o2, 0x33 ! '3'
F0037698: 02800005                 be      loc_F00376AC
F003769C: 80a2a040                 cmp     %o2, 0x40 ! '@'
F00376A0: 32800006                 bne,a   loc_F00376B8
F00376A4: d0062020                 ld      [%i0+0x20], %o0
F00376A8: d006201c                 ld      [%i0+0x1C], %o0
F00376AC: 1080000d                 ba      locret_F00376E0
F00376B0: c0322056                 clrh    [%o0+0x56]
F00376B4: d0062020                 ld      [%i0+0x20], %o0
F00376B8: d432206a                 sth     %o2, [%o0+0x6A]
F00376BC: d006201c                 ld      [%i0+0x1C], %o0
F00376C0: 7fff6dca                 call    _wakeup
F00376C4: 90022054                 inc     0x54, %o0 ! 'T'
F00376C8: d006201c                 ld      [%i0+0x1C], %o0
F00376CC: 7fffa350                 call    _sowakeup
F00376D0: 92022024                 add     %o0, 0x24, %o1 ! '$'
F00376D4: d006201c                 ld      [%i0+0x1C], %o0
F00376D8: 7fffa34d                 call    _sowakeup
F00376DC: 9202203c                 add     %o0, 0x3C, %o1 ! '<'
F00376E0: 81c7e008                 ret
F00376E4: 81e80000                 restore
