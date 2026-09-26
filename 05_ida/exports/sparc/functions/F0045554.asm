F0045554: 9de3bf90                 save    %sp, -0x70, %sp
F0045558: 90100018                 mov     %i0, %o0
F004555C: d2020000                 ld      [%o0], %o1
F0045560: 80a26001                 cmp     %o1, 1
F0045564: 22800010                 be,a    loc_F00455A4
F0045568: d2022004                 ld      [%o0+4], %o1
F004556C: 0a800006                 bcs     loc_F0045584
F0045570: 80a26002                 cmp     %o1, 2
F0045574: 02800016                 be      locret_F00455CC
F0045578: b0102001                 mov     1, %i0
F004557C: 10800014                 ba      locret_F00455CC
F0045580: b0102000                 mov     0, %i0
F0045584: d4564000                 ldsh    [%i1], %o2
F0045588: d6022004                 ld      [%o0+4], %o3
F004558C: 9207bff4                 add     %fp, var_C, %o1
F0045590: d602e004                 ld      [%o3+4], %o3
F0045594: 9fc2c000                 call    %o3
F0045598: d427bff4                 st      %o2, [%fp+var_C]
F004559C: 1080000c                 ba      locret_F00455CC
F00455A0: b0100008                 mov     %o0, %i0
F00455A4: d4024000                 ld      [%o1], %o2
F00455A8: 9fc28000                 call    %o2
F00455AC: 9207bff4                 add     %fp, var_C, %o1
F00455B0: 80a22000                 cmp     %o0, 0
F00455B4: 02800005                 be      loc_F00455C8
F00455B8: d007bff4                 ld      [%fp+var_C], %o0
F00455BC: b0102001                 mov     1, %i0
F00455C0: 10800003                 ba      locret_F00455CC
F00455C4: d0364000                 sth     %o0, [%i1]
F00455C8: b0102000                 mov     0, %i0
F00455CC: 81c7e008                 ret
F00455D0: 81e80000                 restore
