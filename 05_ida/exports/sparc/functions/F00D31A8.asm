F00D31A8: 9de3bf90                 save    %sp, -0x70, %sp
F00D31AC: 11000007901223fe         set     0x1FFE, %o0
F00D31B4: e2062168                 ld      [%i0+0x168], %l1
F00D31B8: 913a001a                 sra     %o0, %i2, %o0
F00D31BC: d2144000                 lduh    [%l1], %o1
F00D31C0: 808a2001                 btst    1, %o0
F00D31C4: 932a6010                 sll     %o1, 16, %o1
F00D31C8: 933a6010                 sra     %o1, 16, %o1
F00D31CC: 912a6001                 sll     %o1, 1, %o0
F00D31D0: 90020009                 add     %o0, %o1, %o0
F00D31D4: 912a2002                 sll     %o0, 2, %o0
F00D31D8: 90220009                 sub     %o0, %o1, %o0
F00D31DC: 912a2002                 sll     %o0, 2, %o0
F00D31E0: 90022050                 inc     0x50, %o0 ! 'P'
F00D31E4: d2146004                 lduh    [%l1+4], %o1
F00D31E8: a4044008                 add     %l1, %o0, %l2
F00D31EC: 932a6010                 sll     %o1, 16, %o1
F00D31F0: 933a6010                 sra     %o1, 16, %o1
F00D31F4: 912a6001                 sll     %o1, 1, %o0
F00D31F8: 90020009                 add     %o0, %o1, %o0
F00D31FC: 912a2002                 sll     %o0, 2, %o0
F00D3200: 90220009                 sub     %o0, %o1, %o0
F00D3204: 912a2002                 sll     %o0, 2, %o0
F00D3208: 90022050                 inc     0x50, %o0 ! 'P'
F00D320C: d2146002                 lduh    [%l1+2], %o1
F00D3210: a6044008                 add     %l1, %o0, %l3
F00D3214: 932a6010                 sll     %o1, 16, %o1
F00D3218: 933a6010                 sra     %o1, 16, %o1
F00D321C: 912a6001                 sll     %o1, 1, %o0
F00D3220: 90020009                 add     %o0, %o1, %o0
F00D3224: 912a2002                 sll     %o0, 2, %o0
F00D3228: 90220009                 sub     %o0, %o1, %o0
F00D322C: 912a2002                 sll     %o0, 2, %o0
F00D3230: 90022050                 inc     0x50, %o0 ! 'P'
F00D3234: 0280000c                 be      loc_F00D3264
F00D3238: a0044008                 add     %l1, %o0, %l0
F00D323C: d00621a0                 ld      [%i0+0x1A0], %o0
F00D3240: d24e21d3                 ldsb    [%i0+0x1D3], %o1
F00D3244: 90070008                 add     %i4, %o0, %o0
F00D3248: 80a26000                 cmp     %o1, 0
F00D324C: 02800006                 be      loc_F00D3264
F00D3250: d02621a4                 st      %o0, [%i0+0x1A4]
F00D3254: 113c0505                 sethi   %hi(paUndoautodim), %o0! id
F00D3258: d20222e0                 ld      [%o0+%lo(paUndoautodim)], %o1! SEL
F00D325C: 40007985                 call    _objc_msgSend
F00D3260: 90100018                 mov     %i0, %o0
F00D3264: d0046010                 ld      [%l1+0x10], %o0
F00D3268: 80a70008                 cmp     %i4, %o0
F00D326C: 28800008                 bleu,a  loc_F00D328C
F00D3270: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D3274: d0046010                 ld      [%l1+0x10], %o0
F00D3278: 90022140                 inc     0x140, %o0
F00D327C: 80a70008                 cmp     %i4, %o0
F00D3280: 2a800002                 bcs,a   loc_F00D3288
F00D3284: f8246010                 st      %i4, [%l1+0x10]
F00D3288: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D328C: 80a22000                 cmp     %o0, 0
F00D3290: 02800008                 be      loc_F00D32B0
F00D3294: a8102000                 mov     0, %l4
F00D3298: d0062168                 ld      [%i0+0x168], %o0
F00D329C: d2120000                 lduh    [%o0], %o1
F00D32A0: d0122002                 lduh    [%o0+2], %o0
F00D32A4: 921a4008                 btog    %o0, %o1
F00D32A8: 80a00009                 cmp     %g0, %o1
F00D32AC: a8402000                 addc    %g0, 0, %l4
F00D32B0: d00c6033                 ldub    [%l1+0x33], %o0
F00D32B4: 808a2002                 btst    2, %o0
F00D32B8: 12800020                 bne     loc_F00D3338
F00D32BC: 80a48010                 cmp     %l2, %l0
F00D32C0: 0280001e                 be      loc_F00D3338
F00D32C4: 01000000                 nop
F00D32C8: d004e008                 ld      [%l3+8], %o0
F00D32CC: 80a2001a                 cmp     %o0, %i2
F00D32D0: 1280001a                 bne     loc_F00D3338
F00D32D4: 901022e0                 mov     0x2E0, %o0
F00D32D8: 913a001a                 sra     %o0, %i2, %o0
F00D32DC: 808a2001                 btst    1, %o0
F00D32E0: 02800016                 be      loc_F00D3338
F00D32E4: a404e004                 add     %l3, 4, %l2
F00D32E8: 7fffbeda                 call    _ev_try_lock
F00D32EC: 90100012                 mov     %l2, %o0
F00D32F0: 80a22000                 cmp     %o0, 0
F00D32F4: 02800011                 be      loc_F00D3338
F00D32F8: 80a76000                 cmp     %i5, 0
F00D32FC: d056c000                 ldsh    [%i3], %o0
F00D3300: d024e00c                 st      %o0, [%l3+0xC]
F00D3304: d056e002                 ldsh    [%i3+2], %o0
F00D3308: d024e010                 st      %o0, [%l3+0x10]
F00D330C: 02800008                 be      loc_F00D332C
F00D3310: f824e014                 st      %i4, [%l3+0x14]
F00D3314: d0074000                 ld      [%i5], %o0
F00D3318: d024e020                 st      %o0, [%l3+0x20]
F00D331C: d0076004                 ld      [%i5+4], %o0
F00D3320: d024e024                 st      %o0, [%l3+0x24]
F00D3324: d0076008                 ld      [%i5+8], %o0
F00D3328: d024e028                 st      %o0, [%l3+0x28]
F00D332C: 7fffbec7                 call    _ev_unlock
F00D3330: 90100012                 mov     %l2, %o0
F00D3334: 30800093                 ba,a    locret_F00D3580
F00D3338: d0144000                 lduh    [%l1], %o0
F00D333C: d2040000                 ld      [%l0], %o1
F00D3340: 912a2010                 sll     %o0, 16, %o0
F00D3344: 913a2010                 sra     %o0, 16, %o0
F00D3348: 80a24008                 cmp     %o1, %o0
F00D334C: 02800081                 be      loc_F00D3550
F00D3350: 90100018                 mov     %i0, %o0
F00D3354: f4242008                 st      %i2, [%l0+8]
F00D3358: d056c000                 ldsh    [%i3], %o0
F00D335C: d024200c                 st      %o0, [%l0+0xC]
F00D3360: d056e002                 ldsh    [%i3+2], %o0
F00D3364: d0242010                 st      %o0, [%l0+0x10]
F00D3368: d004600c                 ld      [%l1+0xC], %o0
F00D336C: 80a76000                 cmp     %i5, 0
F00D3370: d0242018                 st      %o0, [%l0+0x18]
F00D3374: f8242014                 st      %i4, [%l0+0x14]
F00D3378: 02800008                 be      loc_F00D3398
F00D337C: c024201c                 clr     [%l0+0x1C]
F00D3380: d0074000                 ld      [%i5], %o0
F00D3384: d0242020                 st      %o0, [%l0+0x20]
F00D3388: d0076004                 ld      [%i5+4], %o0
F00D338C: d0242024                 st      %o0, [%l0+0x24]
F00D3390: d0076008                 ld      [%i5+8], %o0
F00D3394: d0242028                 st      %o0, [%l0+0x28]
F00D3398: 80a6a002                 cmp     %i2, 2
F00D339C: 22800026                 be,a    loc_F00D3434
F00D33A0: d01621f8                 lduh    [%i0+0x1F8], %o0
F00D33A4: 14800007                 bg      loc_F00D33C0
F00D33A8: 80a6a003                 cmp     %i2, 3
F00D33AC: 80a6a001                 cmp     %i2, 1
F00D33B0: 2280000a                 be,a    loc_F00D33D8
F00D33B4: d2062168                 ld      [%i0+0x168], %o1
F00D33B8: 10800025                 ba      loc_F00D344C
F00D33BC: 90102066                 mov     0x66, %o0 ! 'f'
F00D33C0: 02800011                 be      loc_F00D3404
F00D33C4: 80a6a004                 cmp     %i2, 4
F00D33C8: 2280001e                 be,a    loc_F00D3440
F00D33CC: d01621fa                 lduh    [%i0+0x1FA], %o0
F00D33D0: 1080001f                 ba      loc_F00D344C
F00D33D4: 90102066                 mov     0x66, %o0 ! 'f'
F00D33D8: d0126006                 lduh    [%o1+6], %o0
F00D33DC: 90022001                 inc     %o0
F00D33E0: d0326006                 sth     %o0, [%o1+6]
F00D33E4: d0126006                 lduh    [%o1+6], %o0
F00D33E8: 80a22000                 cmp     %o0, 0
F00D33EC: 02bffffb                 be      loc_F00D33D8
F00D33F0: 01000000                 nop
F00D33F4: d0126006                 lduh    [%o1+6], %o0
F00D33F8: d03621f8                 sth     %o0, [%i0+0x1F8]
F00D33FC: 10800013                 ba      loc_F00D3448
F00D3400: d0342022                 sth     %o0, [%l0+0x22]
F00D3404: d2062168                 ld      [%i0+0x168], %o1
F00D3408: d0126006                 lduh    [%o1+6], %o0
F00D340C: 90022001                 inc     %o0
F00D3410: d0326006                 sth     %o0, [%o1+6]
F00D3414: d0126006                 lduh    [%o1+6], %o0
F00D3418: 80a22000                 cmp     %o0, 0
F00D341C: 02bffffb                 be      loc_F00D3408
F00D3420: 01000000                 nop
F00D3424: d0126006                 lduh    [%o1+6], %o0
F00D3428: d03621fa                 sth     %o0, [%i0+0x1FA]
F00D342C: 10800007                 ba      loc_F00D3448
F00D3430: d0342022                 sth     %o0, [%l0+0x22]
F00D3434: d0342022                 sth     %o0, [%l0+0x22]
F00D3438: 10800004                 ba      loc_F00D3448
F00D343C: c03621f8                 clrh    [%i0+0x1F8]
F00D3440: d0342022                 sth     %o0, [%l0+0x22]
F00D3444: c03621fa                 clrh    [%i0+0x1FA]
F00D3448: 90102066                 mov     0x66, %o0 ! 'f'
F00D344C: 913a001a                 sra     %o0, %i2, %o0
F00D3450: 808a2001                 btst    1, %o0
F00D3454: 02800005                 be      loc_F00D3468
F00D3458: 9010201e                 mov     0x1E, %o0
F00D345C: d00e21c0                 ldub    [%i0+0x1C0], %o0
F00D3460: d02c2028                 stb     %o0, [%l0+0x28]
F00D3464: 9010201e                 mov     0x1E, %o0
F00D3468: 913a001a                 sra     %o0, %i2, %o0
F00D346C: 808a2001                 btst    1, %o0
F00D3470: 22800031                 be,a    loc_F00D3534
F00D3474: d0040000                 ld      [%l0], %o0
F00D3478: d00621b8                 ld      [%i0+0x1B8], %o0
F00D347C: d20621bc                 ld      [%i0+0x1BC], %o1
F00D3480: 90270008                 sub     %i4, %o0, %o0
F00D3484: 80a20009                 cmp     %o0, %o1
F00D3488: 1880001e                 bgu     loc_F00D3500
F00D348C: 80a6a001                 cmp     %i2, 1
F00D3490: d256c000                 ldsh    [%i3], %o1
F00D3494: d05621ac                 ldsh    [%i0+0x1AC], %o0
F00D3498: 92a24008                 subcc   %o1, %o0, %o1
F00D349C: 2c800002                 bneg,a  loc_F00D34A4
F00D34A0: 92200009                 neg     %o1
F00D34A4: d05621b0                 ldsh    [%i0+0x1B0], %o0
F00D34A8: 80a24008                 cmp     %o1, %o0
F00D34AC: 14800015                 bg      loc_F00D3500
F00D34B0: 80a6a001                 cmp     %i2, 1
F00D34B4: d256e002                 ldsh    [%i3+2], %o1
F00D34B8: d05621ae                 ldsh    [%i0+0x1AE], %o0
F00D34BC: 92a24008                 subcc   %o1, %o0, %o1
F00D34C0: 2c800002                 bneg,a  loc_F00D34C8
F00D34C4: 92200009                 neg     %o1
F00D34C8: d05621b2                 ldsh    [%i0+0x1B2], %o0
F00D34CC: 80a24008                 cmp     %o1, %o0
F00D34D0: 1480000c                 bg      loc_F00D3500
F00D34D4: 80a6a001                 cmp     %i2, 1
F00D34D8: 02800004                 be      loc_F00D34E8
F00D34DC: 80a6a003                 cmp     %i2, 3
F00D34E0: 32800006                 bne,a   loc_F00D34F8
F00D34E4: d00621b4                 ld      [%i0+0x1B4], %o0
F00D34E8: d00621b4                 ld      [%i0+0x1B4], %o0
F00D34EC: f82621b8                 st      %i4, [%i0+0x1B8]
F00D34F0: 1080000e                 ba      loc_F00D3528
F00D34F4: 90022001                 inc     %o0
F00D34F8: 1080000e                 ba      loc_F00D3530
F00D34FC: d0242024                 st      %o0, [%l0+0x24]
F00D3500: 02800004                 be      loc_F00D3510
F00D3504: 80a6a003                 cmp     %i2, 3
F00D3508: 3280000a                 bne,a   loc_F00D3530
F00D350C: c0242024                 clr     [%l0+0x24]
F00D3510: d016c000                 lduh    [%i3], %o0
F00D3514: d03621ac                 sth     %o0, [%i0+0x1AC]
F00D3518: d016e002                 lduh    [%i3+2], %o0
F00D351C: d03621ae                 sth     %o0, [%i0+0x1AE]
F00D3520: f82621b8                 st      %i4, [%i0+0x1B8]
F00D3524: 90102001                 mov     1, %o0
F00D3528: d02621b4                 st      %o0, [%i0+0x1B4]
F00D352C: d0242024                 st      %o0, [%l0+0x24]
F00D3530: d0040000                 ld      [%l0], %o0
F00D3534: d0346002                 sth     %o0, [%l1+2]
F00D3538: d004c000                 ld      [%l3], %o0
F00D353C: 80a52000                 cmp     %l4, 0
F00D3540: d0346004                 sth     %o0, [%l1+4]
F00D3544: 1280000f                 bne     locret_F00D3580
F00D3548: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D354C: 3080000a                 ba,a    loc_F00D3574
F00D3550: 133c0504                 sethi   %hi(paName), %o1
F00D3554: 213c03ef                 sethi   %hi(aSPosteventLlev), %l0! "%s: postEvent LLEventQueue overflow.\n"
F00D3558: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D355C: 400078c5                 call    _objc_msgSend
F00D3560: a0142218                 bset    %lo(aSPosteventLlev), %l0! "%s: postEvent LLEventQueue overflow.\n"
F00D3564: 92100008                 mov     %o0, %o1
F00D3568: 7fffcae3                 call    _IOLog
F00D356C: 90100010                 mov     %l0, %o0
F00D3570: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D3574: d20222dc                 ld      [%o0+0x2DC], %o1! SEL
F00D3578: 400078be                 call    _objc_msgSend
F00D357C: 90100018                 mov     %i0, %o0
F00D3580: 81c7e008                 ret
F00D3584: 81e80000                 restore
