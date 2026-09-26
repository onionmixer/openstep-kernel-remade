F00D53D8: 9de3bf98                 save    %sp, -0x68, %sp
F00D53DC: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D53E0: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D53E4: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00D53E8: 40007122                 call    _objc_msgSend
F00D53EC: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00D53F0: a0920000                 orcc    %o0, %g0, %l0
F00D53F4: 12800004                 bne     loc_F00D5404
F00D53F8: 9010001a                 mov     %i2, %o0! __s1
F00D53FC: 10800018                 ba      locret_F00D545C
F00D5400: b0103d27                 mov     -0x2D9, %i0
F00D5404: 133c03f092126030         set     aEv, %o1! "Ev_"
F00D540C: 7ffccc37                 call    _strncmp
F00D5410: 94102003                 mov     3, %o2
F00D5414: 80a22000                 cmp     %o0, 0
F00D5418: 3280000a                 bne,a   loc_F00D5440
F00D541C: 90100010                 mov     %l0, %o0
F00D5420: 113c0505                 sethi   %hi(paEvPort), %o0! id
F00D5424: d2022274                 ld      [%o0+%lo(paEvPort)], %o1! SEL
F00D5428: 40007112                 call    _objc_msgSend
F00D542C: 90100010                 mov     %l0, %o0
F00D5430: 80a20018                 cmp     %o0, %i0
F00D5434: 1280000a                 bne     locret_F00D545C
F00D5438: b0103d3f                 mov     -0x2C1, %i0
F00D543C: 90100010                 mov     %l0, %o0! id
F00D5440: 133c0504                 sethi   %hi(paSetintvaluesFo_0), %o1
F00D5444: d2026280                 ld      [%o1+%lo(paSetintvaluesFo_0)], %o1! SEL
F00D5448: 9410001b                 mov     %i3, %o2
F00D544C: 9610001a                 mov     %i2, %o3
F00D5450: 40007108                 call    _objc_msgSend
F00D5454: 9810001c                 mov     %i4, %o4
F00D5458: b0100008                 mov     %o0, %i0
F00D545C: 81c7e008                 ret
F00D5460: 81e80000                 restore
