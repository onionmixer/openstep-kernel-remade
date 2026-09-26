F00F32F4: 9de3bf98                 save    %sp, -0x68, %sp
F00F32F8: 7ffffcab                 call    sub_F00F25A4
F00F32FC: 01000000                 nop
F00F3300: 133c04bc                 sethi   %hi(dword_F012F12C), %o1
F00F3304: 7ffddb43                 call    _getmachheaders
F00F3308: d022612c                 st      %o0, [%o1+%lo(dword_F012F12C)]
F00F330C: a2920000                 orcc    %o0, %g0, %l1
F00F3310: 0280002d                 be      loc_F00F33C4
F00F3314: a4102000                 mov     0, %l2
F00F3318: 7ffffdad                 call    __objc_headerVector
F00F331C: a0102000                 mov     0, %l0
F00F3320: 133c04bc                 sethi   %hi(dword_F012F124), %o1
F00F3324: d0226124                 st      %o0, [%o1+%lo(dword_F012F124)]
F00F3328: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F332C: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F3330: 80a40008                 cmp     %l0, %o0
F00F3334: 3a800010                 bcc,a   loc_F00F3374
F00F3338: a0102000                 mov     0, %l0
F00F333C: 273c04bc                 sethi   -0xFED1000, %l3
F00F3340: 253c04bc                 sethi   -0xFED1000, %l2
F00F3344: 912c2001                 sll     %l0, 1, %o0
F00F3348: 90020010                 add     %o0, %l0, %o0
F00F334C: 912a2003                 sll     %o0, 3, %o0
F00F3350: d204e124                 ld      [%l3+0x124], %o1
F00F3354: 7ffffe86                 call    sub_F00F2D6C
F00F3358: 90020009                 add     %o0, %o1, %o0
F00F335C: a0042001                 inc     %l0
F00F3360: d004a128                 ld      [%l2+0x128], %o0
F00F3364: 80a40008                 cmp     %l0, %o0
F00F3368: 0abffff8                 bcs     loc_F00F3348
F00F336C: 912c2001                 sll     %l0, 1, %o0
F00F3370: a0102000                 mov     0, %l0
F00F3374: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F3378: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F337C: 80a40008                 cmp     %l0, %o0
F00F3380: 1a80000e                 bcc     loc_F00F33B8
F00F3384: 253c04bc                 sethi   -0xFED1000, %l2
F00F3388: 273c04bc                 sethi   -0xFED1000, %l3
F00F338C: 912c2001                 sll     %l0, 1, %o0
F00F3390: 90020010                 add     %o0, %l0, %o0
F00F3394: 912a2003                 sll     %o0, 3, %o0
F00F3398: d204e124                 ld      [%l3+0x124], %o1
F00F339C: 40000064                 call    sub_F00F352C
F00F33A0: 90020009                 add     %o0, %o1, %o0
F00F33A4: a0042001                 inc     %l0
F00F33A8: d004a128                 ld      [%l2+0x128], %o0
F00F33AC: 80a40008                 cmp     %l0, %o0
F00F33B0: 0abffff8                 bcs     loc_F00F3390
F00F33B4: 912c2001                 sll     %l0, 1, %o0! void *
F00F33B8: 7ffdd3d2                 call    _free
F00F33BC: 90100011                 mov     %l1, %o0
F00F33C0: a4102000                 mov     0, %l2
F00F33C4: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F33C8: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F33CC: 80a48008                 cmp     %l2, %o0
F00F33D0: 3a800031                 bcc,a   loc_F00F3494
F00F33D4: a4102000                 mov     0, %l2
F00F33D8: 293c04bc                 sethi   %hi(dword_F012F124), %l4
F00F33DC: 2b3c04bc                 sethi   -0xFED1000, %l5
F00F33E0: d2052124                 ld      [%l4+%lo(dword_F012F124)], %o1
F00F33E4: 912ca001                 sll     %l2, 1, %o0
F00F33E8: 90020012                 add     %o0, %l2, %o0
F00F33EC: 912a2003                 sll     %o0, 3, %o0
F00F33F0: 92024008                 add     %o1, %o0, %o1
F00F33F4: e6026008                 ld      [%o1+8], %l3
F00F33F8: 80a4e000                 cmp     %l3, 0
F00F33FC: 02800017                 be      loc_F00F3458
F00F3400: e2026004                 ld      [%o1+4], %l1
F00F3404: a0102000                 mov     0, %l0
F00F3408: d004600c                 ld      [%l1+0xC], %o0
F00F340C: 92100008                 mov     %o0, %o1
F00F3410: d0122008                 lduh    [%o0+8], %o0
F00F3414: 80a40008                 cmp     %l0, %o0
F00F3418: 3680000e                 bge,a   loc_F00F3450
F00F341C: a684ffff                 inccc   -1, %l3
F00F3420: 912c2002                 sll     %l0, 2, %o0
F00F3424: 90020009                 add     %o0, %o1, %o0
F00F3428: d002200c                 ld      [%o0+0xC], %o0
F00F342C: 7ffff1aa                 call    __class_install_relationships
F00F3430: d2044000                 ld      [%l1], %o1
F00F3434: a0042001                 inc     %l0
F00F3438: d204600c                 ld      [%l1+0xC], %o1
F00F343C: d0126008                 lduh    [%o1+8], %o0
F00F3440: 80a40008                 cmp     %l0, %o0
F00F3444: 06bffff8                 bl      loc_F00F3424
F00F3448: 912c2002                 sll     %l0, 2, %o0
F00F344C: a684ffff                 inccc   -1, %l3
F00F3450: 12bfffed                 bne     loc_F00F3404
F00F3454: a2046010                 inc     0x10, %l1
F00F3458: a12ca001                 sll     %l2, 1, %l0
F00F345C: a0040012                 add     %l0, %l2, %l0
F00F3460: a12c2003                 sll     %l0, 3, %l0
F00F3464: d0052124                 ld      [%l4+0x124], %o0
F00F3468: 7ffffca2                 call    sub_F00F26F0
F00F346C: 90040008                 add     %l0, %o0, %o0
F00F3470: d0052124                 ld      [%l4+0x124], %o0
F00F3474: 7ffffcbe                 call    sub_F00F276C
F00F3478: 90040008                 add     %l0, %o0, %o0
F00F347C: a404a001                 inc     %l2
F00F3480: d0056128                 ld      [%l5+0x128], %o0
F00F3484: 80a48008                 cmp     %l2, %o0
F00F3488: 0abfffd7                 bcs     loc_F00F33E4
F00F348C: d2052124                 ld      [%l4+0x124], %o1
F00F3490: a4102000                 mov     0, %l2
F00F3494: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F3498: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F349C: 80a48008                 cmp     %l2, %o0
F00F34A0: 3a800010                 bcc,a   loc_F00F34E0
F00F34A4: a4102000                 mov     0, %l2
F00F34A8: 233c04bc                 sethi   -0xFED1000, %l1
F00F34AC: 213c04bc                 sethi   -0xFED1000, %l0
F00F34B0: 912ca001                 sll     %l2, 1, %o0
F00F34B4: 90020012                 add     %o0, %l2, %o0
F00F34B8: 912a2003                 sll     %o0, 3, %o0
F00F34BC: d2046124                 ld      [%l1+0x124], %o1
F00F34C0: 7ffffcc3                 call    sub_F00F27CC
F00F34C4: 90020009                 add     %o0, %o1, %o0
F00F34C8: a404a001                 inc     %l2
F00F34CC: d0042128                 ld      [%l0+0x128], %o0
F00F34D0: 80a48008                 cmp     %l2, %o0
F00F34D4: 0abffff8                 bcs     loc_F00F34B4
F00F34D8: 912ca001                 sll     %l2, 1, %o0
F00F34DC: a4102000                 mov     0, %l2
F00F34E0: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F34E4: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F34E8: 80a48008                 cmp     %l2, %o0
F00F34EC: 1a80000e                 bcc     locret_F00F3524
F00F34F0: 233c04bc                 sethi   -0xFED1000, %l1
F00F34F4: 213c04bc                 sethi   -0xFED1000, %l0
F00F34F8: 912ca001                 sll     %l2, 1, %o0
F00F34FC: 90020012                 add     %o0, %l2, %o0
F00F3500: 912a2003                 sll     %o0, 3, %o0
F00F3504: d2046124                 ld      [%l1+0x124], %o1
F00F3508: 7fffff2a                 call    sub_F00F31B0
F00F350C: 90020009                 add     %o0, %o1, %o0
F00F3510: a404a001                 inc     %l2
F00F3514: d0042128                 ld      [%l0+0x128], %o0
F00F3518: 80a48008                 cmp     %l2, %o0
F00F351C: 0abffff8                 bcs     loc_F00F34FC
F00F3520: 912ca001                 sll     %l2, 1, %o0
F00F3524: 81c7e008                 ret
F00F3528: 81e80000                 restore
