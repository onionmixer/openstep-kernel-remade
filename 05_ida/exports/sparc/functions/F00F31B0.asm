F00F31B0: 9de3bf98                 save    %sp, -0x68, %sp
F00F31B4: e8062008                 ld      [%i0+8], %l4
F00F31B8: 80a52000                 cmp     %l4, 0
F00F31BC: 02800040                 be      locret_F00F32BC
F00F31C0: ea062004                 ld      [%i0+4], %l5
F00F31C4: 113c0506                 sethi   %hi(paLoad), %o0
F00F31C8: e60221f4                 ld      [%o0+%lo(paLoad)], %l3
F00F31CC: e405600c                 ld      [%l5+0xC], %l2
F00F31D0: 80a4a000                 cmp     %l2, 0
F00F31D4: 22800038                 be,a    loc_F00F32B4
F00F31D8: a8853fff                 inccc   -1, %l4
F00F31DC: f014a008                 lduh    [%l2+8], %i0
F00F31E0: 80a62000                 cmp     %i0, 0
F00F31E4: 02800019                 be      loc_F00F3248
F00F31E8: a204a00c                 add     %l2, 0xC, %l1
F00F31EC: e0044000                 ld      [%l1], %l0
F00F31F0: d0040000                 ld      [%l0], %o0
F00F31F4: d202201c                 ld      [%o0+0x1C], %o1
F00F31F8: 80a26000                 cmp     %o1, 0
F00F31FC: 22800011                 be,a    loc_F00F3240
F00F3200: b0863fff                 inccc   -1, %i0
F00F3204: 10800003                 ba      loc_F00F3210
F00F3208: d0024000                 ld      [%o1], %o0
F00F320C: d0024000                 ld      [%o1], %o0
F00F3210: 80a22000                 cmp     %o0, 0
F00F3214: 32bffffe                 bne,a   loc_F00F320C
F00F3218: d2024000                 ld      [%o1], %o1
F00F321C: 90100009                 mov     %o1, %o0
F00F3220: 7ffff2db                 call    _class_lookupMethodInMethodList
F00F3224: 92100013                 mov     %l3, %o1
F00F3228: 94920000                 orcc    %o0, %g0, %o2
F00F322C: 02800004                 be      loc_F00F323C
F00F3230: 90100010                 mov     %l0, %o0
F00F3234: 9fc28000                 call    %o2
F00F3238: 92100013                 mov     %l3, %o1
F00F323C: b0863fff                 inccc   -1, %i0
F00F3240: 12bfffeb                 bne     loc_F00F31EC
F00F3244: a2046004                 inc     4, %l1
F00F3248: e214a00a                 lduh    [%l2+0xA], %l1
F00F324C: d014a008                 lduh    [%l2+8], %o0
F00F3250: 912a2002                 sll     %o0, 2, %o0
F00F3254: 9002200c                 inc     0xC, %o0
F00F3258: 80a46000                 cmp     %l1, 0
F00F325C: 02800015                 be      loc_F00F32B0
F00F3260: b0048008                 add     %l2, %o0, %i0
F00F3264: d0060000                 ld      [%i0], %o0! name
F00F3268: 7ffffaa7                 call    _objc_getClass
F00F326C: d0022004                 ld      [%o0+4], %o0
F00F3270: a0100008                 mov     %o0, %l0
F00F3274: d0060000                 ld      [%i0], %o0
F00F3278: d202200c                 ld      [%o0+0xC], %o1
F00F327C: 80a26000                 cmp     %o1, 0
F00F3280: 02800009                 be      loc_F00F32A4
F00F3284: 90100009                 mov     %o1, %o0
F00F3288: 7ffff2c1                 call    _class_lookupMethodInMethodList
F00F328C: 92100013                 mov     %l3, %o1
F00F3290: 94920000                 orcc    %o0, %g0, %o2
F00F3294: 02800004                 be      loc_F00F32A4
F00F3298: 90100010                 mov     %l0, %o0
F00F329C: 9fc28000                 call    %o2
F00F32A0: 92100013                 mov     %l3, %o1
F00F32A4: a2847fff                 inccc   -1, %l1
F00F32A8: 12bfffef                 bne     loc_F00F3264
F00F32AC: b0062004                 inc     4, %i0
F00F32B0: a8853fff                 inccc   -1, %l4
F00F32B4: 12bfffc6                 bne     loc_F00F31CC
F00F32B8: aa056010                 inc     0x10, %l5
F00F32BC: 81c7e008                 ret
F00F32C0: 81e80000                 restore
