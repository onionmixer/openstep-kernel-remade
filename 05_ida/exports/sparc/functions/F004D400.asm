F004D400: 9de3bf98                 save    %sp, -0x68, %sp
F004D404: 90100018                 mov     %i0, %o0
F004D408: 7fffff6c                 call    sub_F004D1B8
F004D40C: 92067fff                 add     %i1, -1, %o1
F004D410: 94920000                 orcc    %o0, %g0, %o2
F004D414: 2280000e                 be,a    locret_F004D44C
F004D418: f2262008                 st      %i1, [%i0+8]
F004D41C: d002a00c                 ld      [%o2+0xC], %o0
F004D420: 80a22000                 cmp     %o0, 0
F004D424: 2280000a                 be,a    locret_F004D44C
F004D428: f2262008                 st      %i1, [%i0+8]
F004D42C: d0062004                 ld      [%i0+4], %o0
F004D430: d2060000                 ld      [%i0], %o1
F004D434: d222200c                 st      %o1, [%o0+0xC]
F004D438: d4262004                 st      %o2, [%i0+4]
F004D43C: d002a00c                 ld      [%o2+0xC], %o0
F004D440: d0260000                 st      %o0, [%i0]
F004D444: c022a00c                 clr     [%o2+0xC]
F004D448: f2262008                 st      %i1, [%i0+8]
F004D44C: 81c7e008                 ret
F004D450: 81e80000                 restore
