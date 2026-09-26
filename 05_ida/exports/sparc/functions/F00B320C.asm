F00B320C: 9de3bd98                 save    %sp, -0x268, %sp
F00B3210: 96102000                 mov     0, %o3
F00B3214: a6102000                 mov     0, %l3
F00B3218: d04e0000                 ldsb    [%i0], %o0
F00B321C: a0100018                 mov     %i0, %l0
F00B3220: 80a22000                 cmp     %o0, 0
F00B3224: 0280000b                 be      loc_F00B3250
F00B3228: a410200a                 mov     0xA, %l2
F00B322C: d04c0000                 ldsb    [%l0], %o0
F00B3230: 80a22039                 cmp     %o0, 0x39 ! '9'
F00B3234: 04800009                 ble     loc_F00B3258
F00B3238: 80a22000                 cmp     %o0, 0
F00B323C: a0042001                 inc     %l0
F00B3240: d04c0000                 ldsb    [%l0], %o0
F00B3244: 80a22000                 cmp     %o0, 0
F00B3248: 12bffffb                 bne     loc_F00B3234
F00B324C: 80a22039                 cmp     %o0, 0x39 ! '9'
F00B3250: d04c0000                 ldsb    [%l0], %o0
F00B3254: 80a22000                 cmp     %o0, 0
F00B3258: 02800013                 be      loc_F00B32A4
F00B325C: e20c0000                 ldub    [%l0], %l1
F00B3260: 90047fd0                 add     %l1, -0x30, %o0
F00B3264: 900a20ff                 and     %o0, 0xFF, %o0
F00B3268: 80a22009                 cmp     %o0, 9
F00B326C: 1880000e                 bgu     loc_F00B32A4
F00B3270: 9010000b                 mov     %o3, %o0
F00B3274: 7ffd4ca3                 call    _umul
F00B3278: 92100012                 mov     %l2, %o1
F00B327C: c02c0000                 clrb    [%l0]
F00B3280: a0042001                 inc     %l0
F00B3284: 90023fd0                 inc     -0x30, %o0
F00B3288: 932c6018                 sll     %l1, 24, %o1
F00B328C: 933a6018                 sra     %o1, 24, %o1
F00B3290: d44c0000                 ldsb    [%l0], %o2
F00B3294: 96020009                 add     %o0, %o1, %o3
F00B3298: 80a2a000                 cmp     %o2, 0
F00B329C: 12bffff1                 bne     loc_F00B3260
F00B32A0: e20c0000                 ldub    [%l0], %l1
F00B32A4: d04c0000                 ldsb    [%l0], %o0
F00B32A8: 80a22000                 cmp     %o0, 0
F00B32AC: 32800002                 bne,a   loc_F00B32B4
F00B32B0: a6100008                 mov     %o0, %l3
F00B32B4: 133c04fb                 sethi   %hi(_top_devinfo), %o1
F00B32B8: d4026088                 ld      [%o1+%lo(_top_devinfo)], %o2
F00B32BC: 90100018                 mov     %i0, %o0
F00B32C0: 7fffffbc                 call    _path_findnodebyname
F00B32C4: 9210000b                 mov     %o3, %o1
F00B32C8: 233c0477                 sethi   %hi(dword_F011DDA0), %l1
F00B32CC: d20461a0                 ld      [%l1+%lo(dword_F011DDA0)], %o1
F00B32D0: 80a26000                 cmp     %o1, 0
F00B32D4: 02800006                 be      loc_F00B32EC
F00B32D8: a0100008                 mov     %o0, %l0
F00B32DC: 113c0477901222d0         set     aPathToDeviPath, %o0! "path_to_devi: path_findnodebyname retur"...
F00B32E4: 7ffd84dd                 call    _printf
F00B32E8: 92100010                 mov     %l0, %o1
F00B32EC: 80a42000                 cmp     %l0, 0
F00B32F0: 02800064                 be      locret_F00B3480
F00B32F4: c02e0000                 clrb    [%i0]
F00B32F8: d00461a0                 ld      [%l1+0x1A0], %o0
F00B32FC: 80a22000                 cmp     %o0, 0
F00B3300: 22800008                 be,a    loc_F00B3320
F00B3304: e2040000                 ld      [%l0], %l1
F00B3308: d204200c                 ld      [%l0+0xC], %o1
F00B330C: 113c0477                 sethi   %hi(aPathToDeviDevi), %o0! "path_to_devi: devi_name %s, devi_parent"...
F00B3310: d4040000                 ld      [%l0], %o2
F00B3314: 7ffd84d1                 call    _printf
F00B3318: 90122308                 bset    %lo(aPathToDeviDevi), %o0! "path_to_devi: devi_name %s, devi_parent"...
F00B331C: e2040000                 ld      [%l0], %l1
F00B3320: 80a46000                 cmp     %l1, 0
F00B3324: 02800044                 be      loc_F00B3434
F00B3328: 912ce018                 sll     %l3, 24, %o0
F00B332C: a407bdf8                 add     %fp, var_208, %l2
F00B3330: 7ffffe58                 call    _path_getencodefunc
F00B3334: d0040000                 ld      [%l0], %o0
F00B3338: 94920000                 orcc    %o0, %g0, %o2
F00B333C: 12800005                 bne     loc_F00B3350
F00B3340: 90100010                 mov     %l0, %o0
F00B3344: 113c02cd94122120         set     _obio_encode_reg, %o2
F00B334C: 90100010                 mov     %l0, %o0
F00B3350: 9fc28000                 call    %o2
F00B3354: 92100012                 mov     %l2, %o1
F00B3358: 80a23fff                 cmp     %o0, -1
F00B335C: 22800032                 be,a    loc_F00B3424
F00B3360: a0100011                 mov     %l1, %l0
F00B3364: 80a23fff                 cmp     %o0, -1
F00B3368: 14800007                 bg      loc_F00B3384
F00B336C: 80a22000                 cmp     %o0, 0
F00B3370: 80a23ffe                 cmp     %o0, -2
F00B3374: 02800008                 be      loc_F00B3394
F00B3378: d04fbdf8                 ldsb    [%fp+var_208], %o0
F00B337C: 1080000e                 ba      loc_F00B33B4
F00B3380: 80a22000                 cmp     %o0, 0
F00B3384: 1280000b                 bne     loc_F00B33B0
F00B3388: d04fbdf8                 ldsb    [%fp+var_208], %o0
F00B338C: 1080003d                 ba      locret_F00B3480
F00B3390: c02e0000                 clrb    [%i0]
F00B3394: 80a22000                 cmp     %o0, 0
F00B3398: 02800016                 be      loc_F00B33F0
F00B339C: 9007bef8                 add     %fp, var_108, %o0
F00B33A0: 133c047792126338         set     aSS_3, %o1! "/%s%s"
F00B33A8: 10800010                 ba      loc_F00B33E8
F00B33AC: 94100012                 mov     %l2, %o2
F00B33B0: 80a22000                 cmp     %o0, 0
F00B33B4: 0280000a                 be      loc_F00B33DC
F00B33B8: 9007bef8                 add     %fp, var_108, %o0! char *
F00B33BC: 133c047792126340         set     aSSS, %o1! "/%s@%s%s"
F00B33C4: d404200c                 ld      [%l0+0xC], %o2
F00B33C8: 9607bdf8                 add     %fp, var_208, %o3
F00B33CC: 7ffd84e7                 call    _sprintf
F00B33D0: 98100018                 mov     %i0, %o4
F00B33D4: 10800008                 ba      loc_F00B33F4
F00B33D8: 90100018                 mov     %i0, %o0! char *
F00B33DC: 133c047792126350         set     aSS_4, %o1! "/%s%s"
F00B33E4: d404200c                 ld      [%l0+0xC], %o2
F00B33E8: 7ffd84e0                 call    _sprintf
F00B33EC: 96100018                 mov     %i0, %o3
F00B33F0: 90100018                 mov     %i0, %o0! __dst
F00B33F4: 7ffd504d                 call    _strcpy
F00B33F8: 9207bef8                 add     %fp, var_108, %o1
F00B33FC: 113c0477                 sethi   %hi(dword_F011DDA0), %o0
F00B3400: d00221a0                 ld      [%o0+%lo(dword_F011DDA0)], %o0
F00B3404: 80a22000                 cmp     %o0, 0
F00B3408: 02800007                 be      loc_F00B3424
F00B340C: a0100011                 mov     %l1, %l0
F00B3410: 113c047790122358         set     aNameS, %o0! "***name <%s>\n"
F00B3418: 7ffd8490                 call    _printf
F00B341C: 92100018                 mov     %i0, %o1
F00B3420: a0100011                 mov     %l1, %l0
F00B3424: e2044000                 ld      [%l1], %l1
F00B3428: 80a46000                 cmp     %l1, 0
F00B342C: 12bfffc1                 bne     loc_F00B3330
F00B3430: 912ce018                 sll     %l3, 24, %o0
F00B3434: a13a2018                 sra     %o0, 24, %l0
F00B3438: 80a42000                 cmp     %l0, 0
F00B343C: 0280000a                 be      loc_F00B3464
F00B3440: 113c0477                 sethi   -0xFEE2400, %o0! __s
F00B3444: 7ffd4ffd                 call    _strlen
F00B3448: 90100018                 mov     %i0, %o0
F00B344C: 90060008                 add     %i0, %o0, %o0! char *
F00B3450: 133c047792126368         set     aC_1, %o1! ":%c"
F00B3458: 7ffd84c4                 call    _sprintf
F00B345C: 94100010                 mov     %l0, %o2
F00B3460: 113c0477                 sethi   -0xFEE2400, %o0
F00B3464: d00221a0                 ld      [%o0+0x1A0], %o0
F00B3468: 80a22000                 cmp     %o0, 0
F00B346C: 02800005                 be      locret_F00B3480
F00B3470: 113c0477                 sethi   %hi(aNameS_0), %o0! "name = '%s'\n"
F00B3474: 90122370                 bset    %lo(aNameS_0), %o0! "name = '%s'\n"
F00B3478: 7ffd8478                 call    _printf
F00B347C: 92100018                 mov     %i0, %o1
F00B3480: 81c7e008                 ret
F00B3484: 81e80000                 restore
