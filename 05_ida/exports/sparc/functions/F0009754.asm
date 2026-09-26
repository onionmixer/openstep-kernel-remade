F0009754: 9de3bf98                 save    %sp, -0x68, %sp
F0009758: 113c04cf901221e0         set     _bfreelist, %o0
F0009760: 92022110                 add     %o0, 0x110, %o1
F0009764: 80a20009                 cmp     %o0, %o1
F0009768: 1a80000d                 bcc     loc_F000979C
F000976C: 17000100                 sethi   0x40000, %o3
F0009770: 94100009                 mov     %o1, %o2
F0009774: 92022004                 add     %o0, 4, %o1
F0009778: d022600c                 st      %o0, [%o1+0xC]
F000977C: d0226008                 st      %o0, [%o1+8]
F0009780: d0226004                 st      %o0, [%o1+4]
F0009784: d0224000                 st      %o0, [%o1]
F0009788: d6220000                 st      %o3, [%o0]
F000978C: 90022044                 inc     0x44, %o0 ! 'D'
F0009790: 80a2000a                 cmp     %o0, %o2
F0009794: 0abffff9                 bcs     loc_F0009778
F0009798: 92026044                 inc     0x44, %o1 ! 'D'! int
F000979C: 113c0470                 sethi   %hi(_bufpages), %o0
F00097A0: e2022060                 ld      [%o0+%lo(_bufpages)], %l1
F00097A4: 113c0470                 sethi   %hi(_nbuf), %o0
F00097A8: e0022058                 ld      [%o0+%lo(_nbuf)], %l0
F00097AC: a4102000                 mov     0, %l2
F00097B0: 90100011                 mov     %l1, %o0! int
F00097B4: 7ffff395                 call    _div
F00097B8: 92100010                 mov     %l0, %o1
F00097BC: aa100008                 mov     %o0, %l5
F00097C0: 90100011                 mov     %l1, %o0
F00097C4: 7ffff439                 call    _rem
F00097C8: 92100010                 mov     %l0, %o1
F00097CC: 80a48010                 cmp     %l2, %l0
F00097D0: 1680003a                 bge     locret_F00098B8
F00097D4: b0100008                 mov     %o0, %i0
F00097D8: 373c04cf                 sethi   -0xFECC400, %i3
F00097DC: 353c04cf                 sethi   -0xFECC400, %i2
F00097E0: ae056001                 add     %l5, 1, %l7
F00097E4: 2d3c0447                 sethi   -0xFEEE400, %l6
F00097E8: 113c04cfa6122268         set     unk_F0133E68, %l3
F00097F0: a804e044                 add     %l3, 0x44, %l4 ! 'D'
F00097F4: 11000040b2122008         set     0x10008, %i1
F00097FC: a2102000                 mov     0, %l1
F0009800: 80a48018                 cmp     %l2, %i0
F0009804: d006e2f0                 ld      [%i3+0x2F0], %o0
F0009808: 932ca00d                 sll     %l2, 13, %o1
F000980C: a0020011                 add     %o0, %l1, %l0
F0009810: 90103fff                 mov     -1, %o0
F0009814: d034201e                 sth     %o0, [%l0+0x1E]
F0009818: d006a2f8                 ld      [%i2+0x2F8], %o0
F000981C: c0242014                 clr     [%l0+0x14]
F0009820: 90020009                 add     %o0, %o1, %o0
F0009824: 16800005                 bge     loc_F0009838
F0009828: d0242020                 st      %o0, [%l0+0x20]
F000982C: d205a13c                 ld      [%l6+0x13C], %o1
F0009830: 10800004                 ba      loc_F0009840
F0009834: 90100017                 mov     %l7, %o0
F0009838: d205a13c                 ld      [%l6+0x13C], %o1
F000983C: 90100015                 mov     %l5, %o0
F0009840: 7ffff330                 call    _umul
F0009844: 01000000                 nop
F0009848: d0242018                 st      %o0, [%l0+0x18]
F000984C: d0042018                 ld      [%l0+0x18], %o0
F0009850: 80a22000                 cmp     %o0, 0
F0009854: 02800009                 be      loc_F0009878
F0009858: c024203c                 clr     [%l0+0x3C]
F000985C: d004e004                 ld      [%l3+4], %o0
F0009860: d0242004                 st      %o0, [%l0+4]
F0009864: e6242008                 st      %l3, [%l0+8]
F0009868: d004e004                 ld      [%l3+4], %o0
F000986C: e0222008                 st      %l0, [%o0+8]
F0009870: 10800008                 ba      loc_F0009890
F0009874: e024e004                 st      %l0, [%l3+4]
F0009878: d0052004                 ld      [%l4+4], %o0
F000987C: d0242004                 st      %o0, [%l0+4]
F0009880: e8242008                 st      %l4, [%l0+8]
F0009884: d0052004                 ld      [%l4+4], %o0
F0009888: e0222008                 st      %l0, [%o0+8]
F000988C: e0252004                 st      %l0, [%l4+4]
F0009890: c0242040                 clr     [%l0+0x40]
F0009894: f2240000                 st      %i1, [%l0]
F0009898: 40006bf4                 call    _brelse
F000989C: 90100010                 mov     %l0, %o0
F00098A0: 113c0470                 sethi   %hi(_nbuf), %o0
F00098A4: d0022058                 ld      [%o0+%lo(_nbuf)], %o0
F00098A8: a404a001                 inc     %l2
F00098AC: 80a48008                 cmp     %l2, %o0
F00098B0: 06bfffd4                 bl      loc_F0009800
F00098B4: a2046044                 inc     0x44, %l1 ! 'D'
F00098B8: 81c7e008                 ret
F00098BC: 81e80000                 restore
