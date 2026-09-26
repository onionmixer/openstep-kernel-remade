F0092258: 9de3bf78                 save    %sp, -0x88, %sp! int
F009225C: 912e2010                 sll     %i0, 16, %o0
F0092260: a73a2010                 sra     %o0, 16, %l3
F0092264: 400002f4                 call    sub_F0092E34
F0092268: 90100013                 mov     %l3, %o0
F009226C: c027bfe4                 clr     [%fp+var_1C]
F0092270: c027bfe0                 clr     [%fp+var_20]
F0092274: a4100008                 mov     %o0, %l2
F0092278: 90100013                 mov     %l3, %o0
F009227C: b00e20ff                 and     %i0, 0xFF, %i0
F0092280: 4000030c                 call    sub_F0092EB0
F0092284: b1362003                 srl     %i0, 3, %i0
F0092288: 80a4a000                 cmp     %l2, 0
F009228C: 12800004                 bne     loc_F009229C
F0092290: a8100008                 mov     %o0, %l4
F0092294: 1080004d                 ba      locret_F00923C8
F0092298: b0102006                 mov     6, %i0
F009229C: 113c0504                 sethi   %hi(paIsformatted), %o0! id
F00922A0: d2022178                 ld      [%o0+%lo(paIsformatted)], %o1! SEL
F00922A4: 40017d73                 call    _objc_msgSend
F00922A8: 90100012                 mov     %l2, %o0
F00922AC: 912a2018                 sll     %o0, 24, %o0
F00922B0: 80a22000                 cmp     %o0, 0
F00922B4: 12800004                 bne     loc_F00922C4
F00922B8: 113c0504                 sethi   -0xFEBF000, %o0
F00922BC: 10800043                 ba      locret_F00923C8
F00922C0: b0102016                 mov     0x16, %i0
F00922C4: e202217c                 ld      [%o0+0x17C], %l1
F00922C8: e0064000                 ld      [%i1], %l0
F00922CC: 90100014                 mov     %l4, %o0! id
F00922D0: 40017d68                 call    _objc_msgSend
F00922D4: 92100011                 mov     %l1, %o1
F00922D8: 133c0504                 sethi   %hi(paGetdmaalignmen), %o1
F00922DC: d2026180                 ld      [%o1+%lo(paGetdmaalignmen)], %o1! SEL
F00922E0: 40017d64                 call    _objc_msgSend
F00922E4: 9407bfe8                 add     %fp, var_18, %o2
F00922E8: 113c0449                 sethi   %hi(_forceSdPageAlign), %o0
F00922EC: d00220e0                 ld      [%o0+%lo(_forceSdPageAlign)], %o0
F00922F0: 80a22000                 cmp     %o0, 0
F00922F4: 02800004                 be      loc_F0092304
F00922F8: 113c0447                 sethi   %hi(_page_size), %o0
F00922FC: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F0092300: d027bfe8                 st      %o0, [%fp+var_18]
F0092304: 90100014                 mov     %l4, %o0! id
F0092308: 40017d5a                 call    _objc_msgSend
F009230C: 92100011                 mov     %l1, %o1
F0092310: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F0092314: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F0092318: 9607bfe4                 add     %fp, var_1C, %o3
F009231C: d4042004                 ld      [%l0+4], %o2
F0092320: 40017d54                 call    _objc_msgSend
F0092324: 9807bfe0                 add     %fp, var_20, %o4
F0092328: 133c0504                 sethi   %hi(paBlocksize), %o1
F009232C: a2100008                 mov     %o0, %l1
F0092330: e8040000                 ld      [%l0], %l4
F0092334: 90100012                 mov     %l2, %o0! id
F0092338: e4042004                 ld      [%l0+4], %l2
F009233C: e2240000                 st      %l1, [%l0]
F0092340: e006600c                 ld      [%i1+0xC], %l0
F0092344: 94102001                 mov     1, %o2
F0092348: d2026188                 ld      [%o1+%lo(paBlocksize)], %o1! SEL
F009234C: 40017d49                 call    _objc_msgSend
F0092350: d426600c                 st      %o2, [%i1+0xC]
F0092354: 94100013                 mov     %l3, %o2! size_t
F0092358: 96102001                 mov     1, %o3! int
F009235C: 9b2e2002                 sll     %i0, 2, %o5! uio
F0092360: 133c0448921263a8         set     unk_F01123A8, %o1
F0092368: 193c024b                 sethi   %hi(sub_F0092E0C), %o4
F009236C: d2034009                 ld      [%o5+%o1], %o1! bp
F0092370: 9813220c                 bset    %lo(sub_F0092E0C), %o4! int
F0092374: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F0092378: 113c02499012214c         set     _sdstrategy, %o0! f_strategy
F0092380: 7ffe5c81                 call    _physio
F0092384: 9a100019                 mov     %i1, %o5! int
F0092388: 80a42001                 cmp     %l0, 1
F009238C: 12800008                 bne     loc_F00923AC
F0092390: b0100008                 mov     %o0, %i0
F0092394: 90100011                 mov     %l1, %o0! void *
F0092398: 92100014                 mov     %l4, %o1! void *
F009239C: 400009dd                 call    _bcopy
F00923A0: 94100012                 mov     %l2, %o2! int
F00923A4: 10800007                 ba      loc_F00923C0
F00923A8: d007bfe4                 ld      [%fp+var_1C], %o0
F00923AC: 90100011                 mov     %l1, %o0! int
F00923B0: 92100014                 mov     %l4, %o1! int
F00923B4: 40001746                 call    _copyout
F00923B8: 94100012                 mov     %l2, %o2
F00923BC: d007bfe4                 ld      [%fp+var_1C], %o0
F00923C0: 4000cee1                 call    _IOFree
F00923C4: d207bfe0                 ld      [%fp+var_20], %o1
F00923C8: 81c7e008                 ret
F00923CC: 81e80000                 restore
