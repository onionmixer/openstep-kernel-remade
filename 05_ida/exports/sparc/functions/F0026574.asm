F0026574: 9de3bf80                 save    %sp, -0x80, %sp
F0026578: 193c04cf                 sethi   %hi(_active_u), %o4
F002657C: d00321d8                 ld      [%o4+%lo(_active_u)], %o0
F0026580: d4020000                 ld      [%o0], %o2
F0026584: d202a028                 ld      [%o2+0x28], %o1
F0026588: 05080000                 sethi   0x20000000, %g2
F002658C: 808a4002                 btst    %g2, %o1
F0026590: 02800039                 be      loc_F0026674
F0026594: 11080000                 sethi   0x20000000, %o0
F0026598: 902a4008                 andn    %o1, %o0, %o0
F002659C: d022a028                 st      %o0, [%o2+0x28]
F00265A0: d00321d8                 ld      [%o4+%lo(_active_u)], %o0
F00265A4: d6022154                 ld      [%o0+0x154], %o3
F00265A8: 9a102000                 mov     0, %o5
F00265AC: 80a2e000                 cmp     %o3, 0
F00265B0: 0680001d                 bl      loc_F0026624
F00265B4: f0062018                 ld      [%i0+0x18], %i0
F00265B8: 8610000c                 mov     %o4, %g3
F00265BC: d400e1d8                 ld      [%g3+0x1D8], %o2
F00265C0: d202a14c                 ld      [%o2+0x14C], %o1
F00265C4: 912ae002                 sll     %o3, 2, %o0
F00265C8: d0024008                 ld      [%o1+%o0], %o0
F00265CC: 80a22000                 cmp     %o0, 0
F00265D0: 22800013                 be,a    loc_F002661C
F00265D4: 9682ffff                 inccc   -1, %o3
F00265D8: d802a150                 ld      [%o2+0x150], %o4
F00265DC: d20b000b                 ldub    [%o4+%o3], %o1
F00265E0: 808a6004                 btst    4, %o1
F00265E4: 2280000e                 be,a    loc_F002661C
F00265E8: 9682ffff                 inccc   -1, %o3
F00265EC: d0022018                 ld      [%o0+0x18], %o0
F00265F0: 80a20018                 cmp     %o0, %i0
F00265F4: 32800006                 bne,a   loc_F002660C
F00265F8: d2028000                 ld      [%o2], %o1
F00265FC: 9a102001                 mov     1, %o5
F0026600: 900a7ffb                 and     %o1, -5, %o0
F0026604: 10800005                 ba      loc_F0026618
F0026608: d02b000b                 stb     %o0, [%o4+%o3]
F002660C: d0026028                 ld      [%o1+0x28], %o0
F0026610: 90120002                 bset    %g2, %o0
F0026614: d0226028                 st      %o0, [%o1+0x28]
F0026618: 9682ffff                 inccc   -1, %o3
F002661C: 3cbfffe9                 bpos,a  loc_F00265C0
F0026620: d400e1d8                 ld      [%g3+0x1D8], %o2
F0026624: 80a36000                 cmp     %o5, 0
F0026628: 02800013                 be      loc_F0026674
F002662C: 90102003                 mov     3, %o0
F0026630: d037bfe0                 sth     %o0, [%fp+var_20]
F0026634: c037bfe2                 clrh    [%fp+var_1E]
F0026638: c027bfe4                 clr     [%fp+var_1C]
F002663C: 113c04cf                 sethi   %hi(_active_u), %o0
F0026640: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0026644: c027bfe8                 clr     [%fp+var_18]
F0026648: d006201c                 ld      [%i0+0x1C], %o0
F002664C: d4024000                 ld      [%o1], %o2
F0026650: d602601c                 ld      [%o1+0x1C], %o3
F0026654: da022060                 ld      [%o0+0x60], %o5
F0026658: 9207bfe0                 add     %fp, var_20, %o1
F002665C: d852a030                 ldsh    [%o2+0x30], %o4
F0026660: 90100018                 mov     %i0, %o0
F0026664: 9fc34000                 call    %o5
F0026668: 94102008                 mov     8, %o2
F002666C: 10800003                 ba      locret_F0026678
F0026670: b0100008                 mov     %o0, %i0
F0026674: b0102000                 mov     0, %i0
F0026678: 81c7e008                 ret
F002667C: 81e80000                 restore
