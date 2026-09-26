F00923D0: 9de3bf78                 save    %sp, -0x88, %sp! int
F00923D4: a12e2010                 sll     %i0, 16, %l0
F00923D8: a13c2010                 sra     %l0, 16, %l0
F00923DC: 40000296                 call    sub_F0092E34
F00923E0: 90100010                 mov     %l0, %o0
F00923E4: c027bfe4                 clr     [%fp+var_1C]
F00923E8: c027bfe0                 clr     [%fp+var_20]
F00923EC: a4100008                 mov     %o0, %l2
F00923F0: 90100010                 mov     %l0, %o0
F00923F4: 920e20ff                 and     %i0, 0xFF, %o1
F00923F8: 400002ae                 call    sub_F0092EB0
F00923FC: a9326003                 srl     %o1, 3, %l4
F0092400: 80a4a000                 cmp     %l2, 0
F0092404: 12800004                 bne     loc_F0092414
F0092408: a6100008                 mov     %o0, %l3
F009240C: 1080004e                 ba      locret_F0092544
F0092410: b0102006                 mov     6, %i0
F0092414: 113c0504                 sethi   %hi(paIsformatted), %o0! id
F0092418: d2022178                 ld      [%o0+%lo(paIsformatted)], %o1! SEL
F009241C: 40017d15                 call    _objc_msgSend
F0092420: 90100012                 mov     %l2, %o0
F0092424: 912a2018                 sll     %o0, 24, %o0
F0092428: 80a22000                 cmp     %o0, 0
F009242C: 12800004                 bne     loc_F009243C
F0092430: 113c0504                 sethi   -0xFEBF000, %o0
F0092434: 10800044                 ba      locret_F0092544
F0092438: b0102016                 mov     0x16, %i0
F009243C: e202217c                 ld      [%o0+0x17C], %l1
F0092440: e0064000                 ld      [%i1], %l0
F0092444: 90100013                 mov     %l3, %o0! id
F0092448: 40017d0a                 call    _objc_msgSend
F009244C: 92100011                 mov     %l1, %o1
F0092450: 133c0504                 sethi   %hi(paGetdmaalignmen), %o1
F0092454: d2026180                 ld      [%o1+%lo(paGetdmaalignmen)], %o1! SEL
F0092458: 40017d06                 call    _objc_msgSend
F009245C: 9407bfe8                 add     %fp, var_18, %o2
F0092460: 113c0449                 sethi   %hi(_forceSdPageAlign), %o0
F0092464: d00220e0                 ld      [%o0+%lo(_forceSdPageAlign)], %o0
F0092468: 80a22000                 cmp     %o0, 0
F009246C: 02800004                 be      loc_F009247C
F0092470: 113c0447                 sethi   %hi(_page_size), %o0
F0092474: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F0092478: d027bfec                 st      %o0, [%fp+var_14]
F009247C: 90100013                 mov     %l3, %o0! id
F0092480: 40017cfc                 call    _objc_msgSend
F0092484: 92100011                 mov     %l1, %o1
F0092488: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F009248C: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F0092490: 9607bfe4                 add     %fp, var_1C, %o3! int
F0092494: d4042004                 ld      [%l0+4], %o2
F0092498: 40017cf6                 call    _objc_msgSend
F009249C: 9807bfe0                 add     %fp, var_20, %o4! int
F00924A0: d4040000                 ld      [%l0], %o2! size_t
F00924A4: 92100008                 mov     %o0, %o1! int
F00924A8: d2240000                 st      %o1, [%l0]
F00924AC: d006600c                 ld      [%i1+0xC], %o0
F00924B0: 80a22001                 cmp     %o0, 1
F00924B4: 12800007                 bne     loc_F00924D0
F00924B8: a2102001                 mov     1, %l1
F00924BC: 9010000a                 mov     %o2, %o0! void *
F00924C0: 40000994                 call    _bcopy
F00924C4: d4042004                 ld      [%l0+4], %o2! int
F00924C8: 10800008                 ba      loc_F00924E8
F00924CC: 113c0504                 sethi   -0xFEBF000, %o0
F00924D0: 9010000a                 mov     %o2, %o0! int
F00924D4: 400016e1                 call    _copyin
F00924D8: d4042004                 ld      [%l0+4], %o2
F00924DC: 90102001                 mov     1, %o0
F00924E0: d026600c                 st      %o0, [%i1+0xC]
F00924E4: 113c0504                 sethi   -0xFEBF000, %o0! id
F00924E8: d2022188                 ld      [%o0+0x188], %o1! SEL
F00924EC: 40017ce1                 call    _objc_msgSend
F00924F0: 90100012                 mov     %l2, %o0
F00924F4: 952e2010                 sll     %i0, 16, %o2
F00924F8: 953aa010                 sra     %o2, 16, %o2! dev
F00924FC: 96102000                 mov     0, %o3! flags
F0092500: 9b2d2002                 sll     %l4, 2, %o5! uio
F0092504: 133c0448921263a8         set     unk_F01123A8, %o1
F009250C: 193c024b                 sethi   %hi(sub_F0092E0C), %o4
F0092510: d2034009                 ld      [%o5+%o1], %o1! bp
F0092514: 9813220c                 bset    %lo(sub_F0092E0C), %o4! f_minphys
F0092518: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F009251C: 113c02499012214c         set     _sdstrategy, %o0! f_strategy
F0092524: 7ffe5c18                 call    _physio
F0092528: 9a100019                 mov     %i1, %o5
F009252C: 80a46000                 cmp     %l1, 0
F0092530: 02800005                 be      locret_F0092544
F0092534: b0100008                 mov     %o0, %i0
F0092538: d007bfe4                 ld      [%fp+var_1C], %o0
F009253C: 4000ce82                 call    _IOFree
F0092540: d207bfe0                 ld      [%fp+var_20], %o1
F0092544: 81c7e008                 ret
F0092548: 81e80000                 restore
