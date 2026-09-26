F0014534: 9de3bf98                 save    %sp, -0x68, %sp
F0014538: 1120011d90122076         set     -0x7FFB8B8A, %o0
F0014540: 80a60008                 cmp     %i0, %o0
F0014544: 2280003d                 be,a    loc_F0014638
F0014548: d2064000                 ld      [%i1], %o1
F001454C: 1480000d                 bg      loc_F0014580
F0014550: 11100119                 sethi   0x40046400, %o0
F0014554: 112001199012227d         set     -0x7FFB9983, %o0
F001455C: 80a60008                 cmp     %i0, %o0
F0014560: 0280002a                 be      loc_F0014608
F0014564: 11200119                 sethi   -0x7FFB9C00, %o0
F0014568: 9012227e                 bset    0x27E, %o0
F001456C: 80a60008                 cmp     %i0, %o0
F0014570: 2280001b                 be,a    loc_F00145DC
F0014574: d0064000                 ld      [%i1], %o0
F0014578: 10800036                 ba      locret_F0014650
F001457C: b0103fff                 mov     -1, %i0
F0014580: 9012227f                 bset    0x27F, %o0
F0014584: 80a60008                 cmp     %i0, %o0
F0014588: 02800008                 be      loc_F00145A8
F001458C: 1110011d                 sethi   0x40047400, %o0
F0014590: 90122077                 bset    0x77, %o0 ! 'w'
F0014594: 80a60008                 cmp     %i0, %o0
F0014598: 0280002b                 be      loc_F0014644
F001459C: 113c04d4                 sethi   -0xFECB000, %o0
F00145A0: 1080002c                 ba      locret_F0014650
F00145A4: b0103fff                 mov     -1, %i0
F00145A8: 40020978                 call    _splusclock
F00145AC: 01000000                 nop
F00145B0: 133c042d                 sethi   %hi(_pmsgbuf), %o1
F00145B4: d202608c                 ld      [%o1+%lo(_pmsgbuf)], %o1
F00145B8: d4026004                 ld      [%o1+4], %o2
F00145BC: d2026008                 ld      [%o1+8], %o1
F00145C0: 400209d9                 call    _splx
F00145C4: b0228009                 sub     %o2, %o1, %i0
F00145C8: 80a62000                 cmp     %i0, 0
F00145CC: 26800002                 bl,a    loc_F00145D4
F00145D0: b0062ff4                 inc     0xFF4, %i0
F00145D4: 1080001e                 ba      loc_F001464C
F00145D8: f0264000                 st      %i0, [%i1]
F00145DC: 80a22000                 cmp     %o0, 0
F00145E0: 02800006                 be      loc_F00145F8
F00145E4: 133c04d4                 sethi   %hi(_logsoftc), %o1
F00145E8: d0026180                 ld      [%o1+%lo(_logsoftc)], %o0
F00145EC: 90122002                 bset    2, %o0
F00145F0: 10800017                 ba      loc_F001464C
F00145F4: d0226180                 st      %o0, [%o1+%lo(_logsoftc)]
F00145F8: d0026180                 ld      [%o1+0x180], %o0
F00145FC: 900a3ffd                 and     %o0, -3, %o0
F0014600: 10800013                 ba      loc_F001464C
F0014604: d0226180                 st      %o0, [%o1+0x180]
F0014608: d0064000                 ld      [%i1], %o0
F001460C: 80a22000                 cmp     %o0, 0
F0014610: 02800006                 be      loc_F0014628
F0014614: 133c04d4                 sethi   %hi(_logsoftc), %o1
F0014618: d0026180                 ld      [%o1+%lo(_logsoftc)], %o0
F001461C: 90122004                 bset    4, %o0
F0014620: 1080000b                 ba      loc_F001464C
F0014624: d0226180                 st      %o0, [%o1+%lo(_logsoftc)]
F0014628: d0026180                 ld      [%o1+0x180], %o0
F001462C: 900a3ffb                 and     %o0, -5, %o0
F0014630: 10800007                 ba      loc_F001464C
F0014634: d0226180                 st      %o0, [%o1+0x180]
F0014638: 113c04d4                 sethi   %hi(dword_F0135188), %o0
F001463C: 10800004                 ba      loc_F001464C
F0014640: d2222188                 st      %o1, [%o0+%lo(dword_F0135188)]
F0014644: d0022188                 ld      [%o0+0x188], %o0
F0014648: d0264000                 st      %o0, [%i1]
F001464C: b0102000                 mov     0, %i0
F0014650: 81c7e008                 ret
F0014654: 81e80000                 restore
