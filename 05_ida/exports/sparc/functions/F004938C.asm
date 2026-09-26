F004938C: 9de3bf98                 save    %sp, -0x68, %sp
F0049390: 90100018                 mov     %i0, %o0
F0049394: 92100019                 mov     %i1, %o1
F0049398: 9410001a                 mov     %i2, %o2
F004939C: e2062050                 ld      [%i0+0x50], %l1
F00493A0: 9fc70000                 call    %i4
F00493A4: 9610001b                 mov     %i3, %o3
F00493A8: 80a22000                 cmp     %o0, 0
F00493AC: 02800004                 be      loc_F00493BC
F00493B0: a0100019                 mov     %i1, %l0
F00493B4: 10800030                 ba      locret_F0049474
F00493B8: b0100008                 mov     %o0, %i0
F00493BC: d004602c                 ld      [%l1+0x2C], %o0
F00493C0: b4102001                 mov     1, %i2
F00493C4: 80a68008                 cmp     %i2, %o0
F00493C8: 36800013                 bge,a   loc_F0049414
F00493CC: 90042002                 add     %l0, 2, %o0
F00493D0: b206401a                 add     %i1, %i2, %i1
F00493D4: 80a64008                 cmp     %i1, %o0
F00493D8: 36800002                 bge,a   loc_F00493E0
F00493DC: b2264008                 sub     %i1, %o0, %i1
F00493E0: 90100018                 mov     %i0, %o0
F00493E4: 92100019                 mov     %i1, %o1
F00493E8: 94102000                 mov     0, %o2
F00493EC: 9fc70000                 call    %i4
F00493F0: 9610001b                 mov     %i3, %o3
F00493F4: 80a22000                 cmp     %o0, 0
F00493F8: 12bfffef                 bne     loc_F00493B4
F00493FC: b52ea001                 sll     %i2, 1, %i2
F0049400: d004602c                 ld      [%l1+0x2C], %o0
F0049404: 80a68008                 cmp     %i2, %o0
F0049408: 26bffff3                 bl,a    loc_F00493D4
F004940C: b206401a                 add     %i1, %i2, %i1
F0049410: 90042002                 add     %l0, 2, %o0
F0049414: e004602c                 ld      [%l1+0x2C], %l0
F0049418: b4102002                 mov     2, %i2
F004941C: 7ffef523                 call    _rem
F0049420: 92100010                 mov     %l0, %o1
F0049424: 80a68010                 cmp     %i2, %l0
F0049428: 16800012                 bge     loc_F0049470
F004942C: b2100008                 mov     %o0, %i1
F0049430: 90100018                 mov     %i0, %o0
F0049434: 92100019                 mov     %i1, %o1
F0049438: 94102000                 mov     0, %o2
F004943C: 9fc70000                 call    %i4
F0049440: 9610001b                 mov     %i3, %o3
F0049444: 80a22000                 cmp     %o0, 0
F0049448: 12bfffdb                 bne     loc_F00493B4
F004944C: b2066001                 inc     %i1
F0049450: d004602c                 ld      [%l1+0x2C], %o0
F0049454: 80a64008                 cmp     %i1, %o0
F0049458: 22800002                 be,a    loc_F0049460
F004945C: b2102000                 mov     0, %i1
F0049460: b406a001                 inc     %i2
F0049464: 80a68008                 cmp     %i2, %o0
F0049468: 06bffff3                 bl      loc_F0049434
F004946C: 90100018                 mov     %i0, %o0
F0049470: b0102000                 mov     0, %i0
F0049474: 81c7e008                 ret
F0049478: 81e80000                 restore
