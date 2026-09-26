F008A4F4: 9de3bf88                 save    %sp, -0x78, %sp
F008A4F8: 92062008                 add     %i0, 8, %o1! void *
F008A4FC: d006600c                 ld      [%i1+0xC], %o0! void *
F008A500: 94102011                 mov     0x11, %o2! size_t
F008A504: e4022038                 ld      [%o0+0x38], %l2
F008A508: a2066020                 add     %i1, 0x20, %l1 ! ' '
F008A50C: e0066084                 ld      [%i1+0x84], %l0
F008A510: 40002980                 call    _bcopy
F008A514: 9004a008                 add     %l2, 8, %o0
F008A518: 90042004                 add     %l0, 4, %o0! void *
F008A51C: 9206201c                 add     %i0, 0x1C, %o1! void *
F008A520: 4000297c                 call    _bcopy
F008A524: 94102020                 mov     0x20, %o2 ! ' '
F008A528: 9004a030                 add     %l2, 0x30, %o0 ! '0'! void *
F008A52C: 92062070                 add     %i0, 0x70, %o1 ! 'p'! void *
F008A530: d604a01c                 ld      [%l2+0x1C], %o3
F008A534: 94102084                 mov     0x84, %o2! size_t
F008A538: 40002976                 call    _bcopy
F008A53C: d6262054                 st      %o3, [%i0+0x54]
F008A540: d2042044                 ld      [%l0+0x44], %o1
F008A544: 900626a4                 add     %i0, 0x6A4, %o0! __dst
F008A548: d2262184                 st      %o1, [%i0+0x184]
F008A54C: d404a164                 ld      [%l2+0x164], %o2
F008A550: 9204a16c                 add     %l2, 0x16C, %o1! __src
F008A554: d426269c                 st      %o2, [%i0+0x69C]
F008A558: d614a168                 lduh    [%l2+0x168], %o3
F008A55C: 94102048                 mov     0x48, %o2 ! 'H'! __n
F008A560: 7ffdf350                 call    _memcpy
F008A564: d63626a0                 sth     %o3, [%i0+0x6A0]
F008A568: 40003188                 call    _splusclock
F008A56C: 01000000                 nop
F008A570: a0100008                 mov     %o0, %l0
F008A574: d0044000                 ld      [%l1], %o0
F008A578: 80a22000                 cmp     %o0, 0
F008A57C: 12bffffe                 bne     loc_F008A574
F008A580: 01000000                 nop
F008A584: 40003249                 call    _simple_lock_try
F008A588: 90100011                 mov     %l1, %o0
F008A58C: 80a22000                 cmp     %o0, 0
F008A590: 02bffff9                 be      loc_F008A574
F008A594: 90100019                 mov     %i1, %o0
F008A598: 9207bfe8                 add     %fp, var_18, %o1
F008A59C: 7fffb516                 call    _thread_read_times
F008A5A0: 9407bff0                 add     %fp, var_10, %o2
F008A5A4: c0266020                 clr     [%i1+0x20]
F008A5A8: 400031df                 call    _splx
F008A5AC: 90100010                 mov     %l0, %o0
F008A5B0: d007bff0                 ld      [%fp+var_10], %o0
F008A5B4: d02626ac                 st      %o0, [%i0+0x6AC]
F008A5B8: d207bff4                 ld      [%fp+var_C], %o1
F008A5BC: 900626ec                 add     %i0, 0x6EC, %o0! __dst
F008A5C0: d22626b0                 st      %o1, [%i0+0x6B0]
F008A5C4: d407bfe8                 ld      [%fp+var_18], %o2
F008A5C8: 9204a1b4                 add     %l2, 0x1B4, %o1! __src
F008A5CC: d42626a4                 st      %o2, [%i0+0x6A4]
F008A5D0: d607bfec                 ld      [%fp+var_14], %o3
F008A5D4: 94102048                 mov     0x48, %o2 ! 'H'! __n
F008A5D8: 7ffdf332                 call    _memcpy
F008A5DC: d62626a8                 st      %o3, [%i0+0x6A8]
F008A5E0: 81c7e008                 ret
F008A5E4: 81e80000                 restore
