F008F464: 9de3bf90                 save    %sp, -0x70, %sp
F008F468: 90100018                 mov     %i0, %o0! id
F008F46C: 133c0504                 sethi   %hi(paStringforkey), %o1
F008F470: d202610c                 ld      [%o1+%lo(paStringforkey)], %o1! SEL
F008F474: 400188ff                 call    _objc_msgSend
F008F478: 9410001a                 mov     %i2, %o2
F008F47C: a0920000                 orcc    %o0, %g0, %l0
F008F480: 02800018                 be      locret_F008F4E0
F008F484: 90100010                 mov     %l0, %o0! __s
F008F488: 7ffdd79d                 call    _strchr
F008F48C: 9210202d                 mov     0x2D, %o1 ! '-'
F008F490: 80a22000                 cmp     %o0, 0
F008F494: 02800005                 be      loc_F008F4A8
F008F498: 90100018                 mov     %i0, %o0! id
F008F49C: 133c0504                 sethi   %hi(paParserangereso), %o1
F008F4A0: 10800004                 ba      loc_F008F4B0
F008F4A4: d2026110                 ld      [%o1+%lo(paParserangereso)], %o1
F008F4A8: 133c0504                 sethi   %hi(paParseitemresou), %o1
F008F4AC: d2026114                 ld      [%o1+%lo(paParseitemresou)], %o1! SEL
F008F4B0: 9410001a                 mov     %i2, %o2
F008F4B4: 400188ef                 call    _objc_msgSend
F008F4B8: 96100010                 mov     %l0, %o3
F008F4BC: 94920000                 orcc    %o0, %g0, %o2
F008F4C0: 02800007                 be      loc_F008F4DC
F008F4C4: 90100018                 mov     %i0, %o0! id
F008F4C8: 133c0504                 sethi   %hi(paSetresourcesFo), %o1
F008F4CC: d2026118                 ld      [%o1+%lo(paSetresourcesFo)], %o1! SEL
F008F4D0: 400188e8                 call    _objc_msgSend
F008F4D4: 9610001a                 mov     %i2, %o3
F008F4D8: 30800002                 ba,a    locret_F008F4E0
F008F4DC: b0102000                 mov     0, %i0
F008F4E0: 81c7e008                 ret
F008F4E4: 81e80000                 restore
