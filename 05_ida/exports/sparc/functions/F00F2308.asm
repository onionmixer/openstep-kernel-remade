F00F2308: 9de3bf98                 save    %sp, -0x68, %sp
F00F230C: ea062004                 ld      [%i0+4], %l5
F00F2310: 1080001b                 ba      loc_F00F237C
F00F2314: a4102000                 mov     0, %l2
F00F2318: 90054008                 add     %l5, %o0, %o0
F00F231C: d002200c                 ld      [%o0+0xC], %o0
F00F2320: 80a22000                 cmp     %o0, 0
F00F2324: 22800016                 be,a    loc_F00F237C
F00F2328: a404a001                 inc     %l2
F00F232C: d2122008                 lduh    [%o0+8], %o1
F00F2330: d012200a                 lduh    [%o0+0xA], %o0
F00F2334: a8024008                 add     %o1, %o0, %l4
F00F2338: a0100009                 mov     %o1, %l0
F00F233C: 80a24014                 cmp     %o1, %l4
F00F2340: 3a80000f                 bcc,a   loc_F00F237C
F00F2344: a404a001                 inc     %l2
F00F2348: a32ca004                 sll     %l2, 4, %l1
F00F234C: a6054011                 add     %l5, %l1, %l3
F00F2350: d204e00c                 ld      [%l3+0xC], %o1
F00F2354: 912c2002                 sll     %l0, 2, %o0
F00F2358: 90020009                 add     %o0, %o1, %o0
F00F235C: d002200c                 ld      [%o0+0xC], %o0
F00F2360: 7fffffb7                 call    sub_F00F223C
F00F2364: d2054011                 ld      [%l5+%l1], %o1
F00F2368: a0042001                 inc     %l0
F00F236C: 80a40014                 cmp     %l0, %l4
F00F2370: 2abffff9                 bcs,a   loc_F00F2354
F00F2374: d204e00c                 ld      [%l3+0xC], %o1
F00F2378: a404a001                 inc     %l2
F00F237C: d0062008                 ld      [%i0+8], %o0
F00F2380: 80a48008                 cmp     %l2, %o0
F00F2384: 0abfffe5                 bcs     loc_F00F2318
F00F2388: 912ca004                 sll     %l2, 4, %o0
F00F238C: 81c7e008                 ret
F00F2390: 81e80000                 restore
