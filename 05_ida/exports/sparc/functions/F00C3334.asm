F00C3334: 9de3bf60                 save    %sp, -0xA0, %sp
F00C3338: a2102000                 mov     0, %l1
F00C333C: b2102000                 mov     0, %i1
F00C3340: a8102000                 mov     0, %l4
F00C3344: c02fbfe7                 clrb    [%fp+var_19]
F00C3348: c02fbfc7                 clrb    [%fp+var_39]
F00C334C: b4102000                 mov     0, %i2
F00C3350: c027bff0                 clr     [%fp+var_10]
F00C3354: 40000af7                 call    _IOMalloc
F00C3358: 90102080                 mov     0x80, %o0
F00C335C: b8100008                 mov     %o0, %i4
F00C3360: 113c0506                 sethi   %hi(paIoconfigtable), %o0
F00C3364: d0022298                 ld      [%o0+%lo(paIoconfigtable)], %o0! id
F00C3368: 133c0504                 sethi   %hi(paNewforconfigda), %o1
F00C336C: d202615c                 ld      [%o1+%lo(paNewforconfigda)], %o1! SEL
F00C3370: 4000b940                 call    _objc_msgSend
F00C3374: 94100018                 mov     %i0, %o2
F00C3378: b0100008                 mov     %o0, %i0
F00C337C: 133c0504                 sethi   %hi(paValueforstring), %o1! SEL
F00C3380: 153c04b9                 sethi   %hi(aServerName_0), %o2! "Server Name"
F00C3384: e00260e8                 ld      [%o1+%lo(paValueforstring)], %l0
F00C3388: 9412a280                 bset    %lo(aServerName_0), %o2! "Server Name"
F00C338C: 4000b939                 call    _objc_msgSend
F00C3390: 92100010                 mov     %l0, %o1
F00C3394: ae100008                 mov     %o0, %l7
F00C3398: 90100018                 mov     %i0, %o0! id
F00C339C: 92100010                 mov     %l0, %o1! SEL
F00C33A0: 153c04b9                 sethi   %hi(aDynamic), %o2! "Dynamic"
F00C33A4: 4000b933                 call    _objc_msgSend
F00C33A8: 9412a290                 bset    %lo(aDynamic), %o2! "Dynamic"
F00C33AC: a0920000                 orcc    %o0, %g0, %l0
F00C33B0: 0280001a                 be      loc_F00C3418
F00C33B4: 90100018                 mov     %i0, %o0
F00C33B8: d04c0000                 ldsb    [%l0], %o0
F00C33BC: 80a22059                 cmp     %o0, 0x59 ! 'Y'
F00C33C0: 02800004                 be      loc_F00C33D0
F00C33C4: 80a22079                 cmp     %o0, 0x79 ! 'y'
F00C33C8: 1280000f                 bne     loc_F00C3404
F00C33CC: 90100018                 mov     %i0, %o0
F00C33D0: 113c04fd                 sethi   %hi(_autoConfigTables), %o0
F00C33D4: d0022390                 ld      [%o0+%lo(_autoConfigTables)], %o0! id
F00C33D8: 133c0504                 sethi   %hi(paAddobject), %o1
F00C33DC: d20260a4                 ld      [%o1+%lo(paAddobject)], %o1! SEL
F00C33E0: 4000b924                 call    _objc_msgSend
F00C33E4: 94100018                 mov     %i0, %o2
F00C33E8: 90100018                 mov     %i0, %o0! id
F00C33EC: 133c0504                 sethi   %hi(paFreestring), %o1
F00C33F0: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00C33F4: 4000b91f                 call    _objc_msgSend
F00C33F8: 94100010                 mov     %l0, %o2
F00C33FC: 1080019d                 ba      locret_F00C3A70
F00C3400: b0102001                 mov     1, %i0
F00C3404: 133c0504                 sethi   %hi(paFreestring), %o1
F00C3408: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00C340C: 4000b919                 call    _objc_msgSend
F00C3410: 94100010                 mov     %l0, %o2
F00C3414: 90100018                 mov     %i0, %o0! id
F00C3418: 133c0504                 sethi   %hi(paValueforstring), %o1
F00C341C: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00C3420: 153c04b9                 sethi   %hi(aPromName), %o2! "Prom Name"
F00C3424: 4000b913                 call    _objc_msgSend
F00C3428: 9412a298                 bset    %lo(aPromName), %o2! "Prom Name"
F00C342C: 80a22000                 cmp     %o0, 0
F00C3430: 02800009                 be      loc_F00C3454
F00C3434: d027bfcc                 st      %o0, [%fp+__s1]
F00C3438: d007bfcc                 ld      [%fp+__s1], %o0! __s1
F00C343C: 133c04b9                 sethi   %hi(aPseudo), %o1! "pseudo"
F00C3440: 7ffd135b                 call    _strcmp
F00C3444: 921262a8                 bset    %lo(aPseudo), %o1! "pseudo"
F00C3448: 80a22000                 cmp     %o0, 0
F00C344C: 12800005                 bne     loc_F00C3460
F00C3450: 90100018                 mov     %i0, %o0
F00C3454: 98102001                 mov     1, %o4
F00C3458: d82fbfc7                 stb     %o4, [%fp+var_39]
F00C345C: 90100018                 mov     %i0, %o0! id
F00C3460: 133c0504                 sethi   %hi(paValueforstring), %o1! SEL
F00C3464: e40260e8                 ld      [%o1+%lo(paValueforstring)], %l2
F00C3468: 153c04b99412a2b0         set     aClassNames, %o2! "Class Names"
F00C3470: 4000b900                 call    _objc_msgSend
F00C3474: 92100012                 mov     %l2, %o1
F00C3478: a0920000                 orcc    %o0, %g0, %l0
F00C347C: 32800009                 bne,a   loc_F00C34A0
F00C3480: 113c0506                 sethi   -0xFEBE800, %o0
F00C3484: 90100018                 mov     %i0, %o0! id
F00C3488: 92100012                 mov     %l2, %o1! SEL
F00C348C: 153c04b9                 sethi   %hi(aDriverName_0), %o2! "Driver Name"
F00C3490: 4000b8f8                 call    _objc_msgSend
F00C3494: 9412a2c0                 bset    %lo(aDriverName_0), %o2! "Driver Name"
F00C3498: a0100008                 mov     %o0, %l0
F00C349C: 113c0506                 sethi   -0xFEBE800, %o0
F00C34A0: d00222ac                 ld      [%o0+0x2AC], %o0! id
F00C34A4: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00C34A8: 4000b8f2                 call    _objc_msgSend
F00C34AC: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00C34B0: 133c0504                 sethi   %hi(paInitwithwhites), %o1
F00C34B4: d202613c                 ld      [%o1+%lo(paInitwithwhites)], %o1! SEL
F00C34B8: 4000b8ee                 call    _objc_msgSend
F00C34BC: 94100010                 mov     %l0, %o2
F00C34C0: d027bfec                 st      %o0, [%fp+var_14]
F00C34C4: 7ffd0fdd                 call    _strlen
F00C34C8: 90100010                 mov     %l0, %o0
F00C34CC: 92022001                 add     %o0, 1, %o1
F00C34D0: 40000a9d                 call    _IOFree
F00C34D4: 90100010                 mov     %l0, %o0
F00C34D8: 90100018                 mov     %i0, %o0! id
F00C34DC: 92100012                 mov     %l2, %o1! SEL
F00C34E0: 153c04b9                 sethi   %hi(aBusType_1), %o2! "Bus Type"
F00C34E4: 4000b8e3                 call    _objc_msgSend
F00C34E8: 9412a2d0                 bset    %lo(aBusType_1), %o2! "Bus Type"
F00C34EC: b6920000                 orcc    %o0, %g0, %i3
F00C34F0: 02800007                 be      loc_F00C350C
F00C34F4: 113c04b9                 sethi   -0xFED1C00, %o0
F00C34F8: d04ec000                 ldsb    [%i3], %o0
F00C34FC: 80a22000                 cmp     %o0, 0
F00C3500: 32800005                 bne,a   loc_F00C3514
F00C3504: f627bfdc                 st      %i3, [%fp+var_24]
F00C3508: 113c04b9                 sethi   -0xFED1C00, %o0
F00C350C: 901222e0                 bset    0x2E0, %o0
F00C3510: d027bfdc                 st      %o0, [%fp+var_24]
F00C3514: 9010001c                 mov     %i4, %o0! name
F00C3518: 133c04b9                 sethi   %hi(aSkernbus_0), %o1! "%sKernBus"
F00C351C: d407bfdc                 ld      [%fp+var_24], %o2
F00C3520: 7ffd4492                 call    _sprintf
F00C3524: 921262e8                 bset    %lo(aSkernbus_0), %o1! "%sKernBus"
F00C3528: 4000b9f7                 call    _objc_getClass
F00C352C: 9010001c                 mov     %i4, %o0
F00C3530: 80a22000                 cmp     %o0, 0
F00C3534: 12800005                 bne     loc_F00C3548
F00C3538: d027bfd4                 st      %o0, [%fp+var_2C]
F00C353C: 113c04fd                 sethi   %hi(_defaultBusClass), %o0
F00C3540: d00223a0                 ld      [%o0+%lo(_defaultBusClass)], %o0
F00C3544: d027bfd4                 st      %o0, [%fp+var_2C]
F00C3548: 90100018                 mov     %i0, %o0! id
F00C354C: 133c0504                 sethi   %hi(paValueforstring), %o1
F00C3550: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00C3554: 153c04b9                 sethi   %hi(aInstance), %o2! "Instance"
F00C3558: 4000b8c6                 call    _objc_msgSend
F00C355C: 9412a2f8                 bset    %lo(aInstance), %o2! "Instance"
F00C3560: 80a22000                 cmp     %o0, 0
F00C3564: 02800010                 be      loc_F00C35A4
F00C3568: d027bff4                 st      %o0, [%fp+var_C]
F00C356C: 9207bff4                 add     %fp, var_C, %o1
F00C3570: 7ffffe65                 call    sub_F00C2F04
F00C3574: 9407bff0                 add     %fp, var_10, %o2
F00C3578: 80a22000                 cmp     %o0, 0
F00C357C: 2280000b                 be,a    loc_F00C35A8
F00C3580: c027bff0                 clr     [%fp+var_10]
F00C3584: d007bff0                 ld      [%fp+var_10], %o0
F00C3588: 80a22001                 cmp     %o0, 1
F00C358C: 04800008                 ble     loc_F00C35AC
F00C3590: ba102000                 mov     0, %i5
F00C3594: 10800006                 ba      loc_F00C35AC
F00C3598: c027bff0                 clr     [%fp+var_10]
F00C359C: 108000cb                 ba      loc_F00C38C8
F00C35A0: ba102001                 mov     1, %i5
F00C35A4: c027bff0                 clr     [%fp+var_10]
F00C35A8: ba102000                 mov     0, %i5
F00C35AC: ac102000                 mov     0, %l6
F00C35B0: 113c0503                 sethi   %hi(paAlloc), %o0
F00C35B4: ea0223f0                 ld      [%o0+%lo(paAlloc)], %l5
F00C35B8: 113c0504                 sethi   %hi(paCount_0), %o0! id
F00C35BC: d20220b8                 ld      [%o0+%lo(paCount_0)], %o1! SEL
F00C35C0: 4000b8ac                 call    _objc_msgSend
F00C35C4: d007bfec                 ld      [%fp+var_14], %o0
F00C35C8: 80a58008                 cmp     %l6, %o0
F00C35CC: 1a8000bf                 bcc     loc_F00C38C8
F00C35D0: d007bfec                 ld      [%fp+var_14], %o0! name
F00C35D4: 133c0504                 sethi   %hi(paStringat), %o1
F00C35D8: d2026334                 ld      [%o1+%lo(paStringat)], %o1! SEL
F00C35DC: 4000b8a5                 call    _objc_msgSend
F00C35E0: 94100016                 mov     %l6, %o2
F00C35E4: 4000b9c8                 call    _objc_getClass
F00C35E8: a0100008                 mov     %o0, %l0
F00C35EC: a6920000                 orcc    %o0, %g0, %l3
F00C35F0: 1280000c                 bne     loc_F00C3620
F00C35F4: d80fbfe7                 ldub    [%fp+var_19], %o4
F00C35F8: 113c04b990122308         set     aConfiguredrive, %o0! "configureDriver: driver class '%s' was "...
F00C3600: 40000abd                 call    _IOLog
F00C3604: 92100010                 mov     %l0, %o1
F00C3608: 80a5e000                 cmp     %l7, 0
F00C360C: 028000ef                 be      loc_F00C39C8
F00C3610: 113c04b9                 sethi   %hi(aDriverSCouldNo), %o0! "Driver %s could not be configured\n"
F00C3614: 90122340                 bset    %lo(aDriverSCouldNo), %o0! "Driver %s could not be configured\n"
F00C3618: 108000e9                 ba      loc_F00C39BC
F00C361C: 92100017                 mov     %l7, %o1
F00C3620: 80a32000                 cmp     %o4, 0
F00C3624: 1280000d                 bne     loc_F00C3658
F00C3628: d007bfd4                 ld      [%fp+var_2C], %o0
F00C362C: 80a5e000                 cmp     %l7, 0
F00C3630: 02800008                 be      loc_F00C3650
F00C3634: 98102001                 mov     1, %o4
F00C3638: 7ffffeb5                 call    sub_F00C310C
F00C363C: 90100017                 mov     %l7, %o0
F00C3640: 912a2018                 sll     %o0, 24, %o0
F00C3644: 80a22000                 cmp     %o0, 0
F00C3648: 028000df                 be      loc_F00C39C4
F00C364C: 98102001                 mov     1, %o4
F00C3650: d82fbfe7                 stb     %o4, [%fp+var_19]
F00C3654: d007bfd4                 ld      [%fp+var_2C], %o0! id
F00C3658: 133c0504                 sethi   %hi(paConfiguredrive), %o1
F00C365C: d2026338                 ld      [%o1+%lo(paConfiguredrive)], %o1! SEL
F00C3660: 4000b884                 call    _objc_msgSend
F00C3664: 94100018                 mov     %i0, %o2
F00C3668: 912a2018                 sll     %o0, 24, %o0
F00C366C: 80a22000                 cmp     %o0, 0
F00C3670: 12bfffcb                 bne     loc_F00C359C
F00C3674: 113c0504                 sethi   %hi(paDevicestyle), %o0! id
F00C3678: d202233c                 ld      [%o0+%lo(paDevicestyle)], %o1! SEL
F00C367C: 4000b87d                 call    _objc_msgSend
F00C3680: 90100013                 mov     %l3, %o0
F00C3684: 80a22000                 cmp     %o0, 0
F00C3688: 02800006                 be      loc_F00C36A0
F00C368C: 80a22002                 cmp     %o0, 2
F00C3690: 18800072                 bgu     loc_F00C3858
F00C3694: 113c04ba                 sethi   -0xFED1800, %o0
F00C3698: 1080005a                 ba      loc_F00C3800
F00C369C: 113c0506                 sethi   -0xFEBE800, %o0
F00C36A0: d007bfd4                 ld      [%fp+var_2C], %o0! id
F00C36A4: 133c0504                 sethi   %hi(paDevicedescript), %o1
F00C36A8: d2026340                 ld      [%o1+%lo(paDevicedescript)], %o1! SEL
F00C36AC: 4000b871                 call    _objc_msgSend
F00C36B0: 94100018                 mov     %i0, %o2
F00C36B4: a2920000                 orcc    %o0, %g0, %l1
F00C36B8: 028000be                 be      loc_F00C39B0
F00C36BC: 253c0504                 sethi   %hi(paBus_0), %l2
F00C36C0: 4000b86c                 call    _objc_msgSend
F00C36C4: d204a344                 ld      [%l2+%lo(paBus_0)], %o1
F00C36C8: 80a22000                 cmp     %o0, 0
F00C36CC: 12800009                 bne     loc_F00C36F0
F00C36D0: d80fbfc7                 ldub    [%fp+var_39], %o4
F00C36D4: 113c0504                 sethi   %hi(paSetbus), %o0
F00C36D8: d2022348                 ld      [%o0+%lo(paSetbus)], %o1! SEL
F00C36DC: 113c04fd                 sethi   %hi(_defaultBus), %o0! id
F00C36E0: d4022398                 ld      [%o0+%lo(_defaultBus)], %o2
F00C36E4: 4000b863                 call    _objc_msgSend
F00C36E8: 90100011                 mov     %l1, %o0
F00C36EC: d80fbfc7                 ldub    [%fp+var_39], %o4
F00C36F0: 80a32000                 cmp     %o4, 0
F00C36F4: 1280000d                 bne     loc_F00C3728
F00C36F8: d204a344                 ld      [%l2+0x344], %o1
F00C36FC: d207bff0                 ld      [%fp+var_10], %o1
F00C3700: 7fffb852                 call    _findDeviceinfoForDevice
F00C3704: d007bfcc                 ld      [%fp+__s1], %o0
F00C3708: b4920000                 orcc    %o0, %g0, %i2
F00C370C: 0280009d                 be      loc_F00C3980
F00C3710: 90100011                 mov     %l1, %o0! id
F00C3714: 133c0504                 sethi   %hi(paAdddeviceinfo), %o1
F00C3718: d202634c                 ld      [%o1+%lo(paAdddeviceinfo)], %o1! SEL
F00C371C: 4000b855                 call    _objc_msgSend
F00C3720: 9410001a                 mov     %i2, %o2
F00C3724: d204a344                 ld      [%l2+0x344], %o1! SEL
F00C3728: 4000b852                 call    _objc_msgSend
F00C372C: 90100011                 mov     %l1, %o0! id
F00C3730: 133c0504                 sethi   %hi(paAllocateresour), %o1
F00C3734: d2026350                 ld      [%o1+%lo(paAllocateresour)], %o1! SEL
F00C3738: 4000b84e                 call    _objc_msgSend
F00C373C: 94100011                 mov     %l1, %o2
F00C3740: 80a22000                 cmp     %o0, 0
F00C3744: 02800096                 be      loc_F00C399C
F00C3748: 113c04b9                 sethi   -0xFED1C00, %o0
F00C374C: 113c0506                 sethi   %hi(paKerndevice), %o0
F00C3750: d00222b0                 ld      [%o0+%lo(paKerndevice)], %o0! id
F00C3754: 4000b847                 call    _objc_msgSend
F00C3758: 92100015                 mov     %l5, %o1
F00C375C: 133c0504                 sethi   %hi(paInitwithdevice), %o1
F00C3760: d2026354                 ld      [%o1+%lo(paInitwithdevice)], %o1! SEL
F00C3764: 4000b843                 call    _objc_msgSend
F00C3768: 94100011                 mov     %l1, %o2
F00C376C: b2920000                 orcc    %o0, %g0, %i1
F00C3770: 0280008d                 be      loc_F00C39A4
F00C3774: 133c0504                 sethi   %hi(paSetdevice), %o1
F00C3778: 90100011                 mov     %l1, %o0! id
F00C377C: d2026358                 ld      [%o1+%lo(paSetdevice)], %o1! SEL
F00C3780: 4000b83c                 call    _objc_msgSend
F00C3784: 94100019                 mov     %i1, %o2
F00C3788: 9010001c                 mov     %i4, %o0! name
F00C378C: 133c04ba                 sethi   %hi(aIoSdevicedescr), %o1! "IO%sDeviceDescription"
F00C3790: d407bfdc                 ld      [%fp+var_24], %o2
F00C3794: 7ffd43f5                 call    _sprintf
F00C3798: 92126070                 bset    %lo(aIoSdevicedescr), %o1! "IO%sDeviceDescription"
F00C379C: 4000b95a                 call    _objc_getClass
F00C37A0: 9010001c                 mov     %i4, %o0! id
F00C37A4: 4000b833                 call    _objc_msgSend
F00C37A8: 92100015                 mov     %l5, %o1
F00C37AC: 133c0504                 sethi   %hi(paInitwithdelega), %o1
F00C37B0: d202635c                 ld      [%o1+%lo(paInitwithdelega)], %o1! SEL
F00C37B4: 4000b82f                 call    _objc_msgSend
F00C37B8: 94100011                 mov     %l1, %o2
F00C37BC: a8920000                 orcc    %o0, %g0, %l4
F00C37C0: 02800082                 be      loc_F00C39C8
F00C37C4: 80a5e000                 cmp     %l7, 0
F00C37C8: 7fff32cd                 call    _create_dev_port
F00C37CC: 90100019                 mov     %i1, %o0! id
F00C37D0: 94100008                 mov     %o0, %o2
F00C37D4: 133c0504                 sethi   %hi(paSetdeviceport), %o1
F00C37D8: d2026360                 ld      [%o1+%lo(paSetdeviceport)], %o1! SEL
F00C37DC: 4000b825                 call    _objc_msgSend
F00C37E0: 90100014                 mov     %l4, %o0
F00C37E4: 90100014                 mov     %l4, %o0! id
F00C37E8: 133c0504                 sethi   %hi(paSetdeviceinfo), %o1
F00C37EC: d2026364                 ld      [%o1+%lo(paSetdeviceinfo)], %o1! SEL
F00C37F0: 4000b820                 call    _objc_msgSend
F00C37F4: 9410001a                 mov     %i2, %o2
F00C37F8: 1080001a                 ba      loc_F00C3860
F00C37FC: 113c0504                 sethi   -0xFEBF000, %o0
F00C3800: d0022280                 ld      [%o0+0x280], %o0! id
F00C3804: 4000b81b                 call    _objc_msgSend
F00C3808: 92100015                 mov     %l5, %o1
F00C380C: 133c0504                 sethi   %hi(paInitfromconfig), %o1
F00C3810: d2026070                 ld      [%o1+%lo(paInitfromconfig)], %o1! SEL
F00C3814: 4000b817                 call    _objc_msgSend
F00C3818: 94100018                 mov     %i0, %o2
F00C381C: a2920000                 orcc    %o0, %g0, %l1
F00C3820: 02800069                 be      loc_F00C39C4
F00C3824: 113c0506                 sethi   %hi(paIodevicedescri), %o0
F00C3828: d00222b4                 ld      [%o0+%lo(paIodevicedescri)], %o0! id
F00C382C: 4000b811                 call    _objc_msgSend
F00C3830: 92100015                 mov     %l5, %o1
F00C3834: 133c0504                 sethi   %hi(paInitwithdelega), %o1
F00C3838: d202635c                 ld      [%o1+%lo(paInitwithdelega)], %o1! SEL
F00C383C: 4000b80d                 call    _objc_msgSend
F00C3840: 94100011                 mov     %l1, %o2
F00C3844: a8920000                 orcc    %o0, %g0, %l4
F00C3848: 02800060                 be      loc_F00C39C8
F00C384C: 80a5e000                 cmp     %l7, 0
F00C3850: 10800004                 ba      loc_F00C3860
F00C3854: 113c0504                 sethi   -0xFEBF000, %o0
F00C3858: 10800058                 ba      loc_F00C39B8
F00C385C: 90122088                 bset    0x88, %o0
F00C3860: d2022270                 ld      [%o0+0x270], %o1! SEL
F00C3864: 113c0504                 sethi   %hi(paProbe), %o0! id
F00C3868: d4022368                 ld      [%o0+%lo(paProbe)], %o2
F00C386C: 4000b801                 call    _objc_msgSend
F00C3870: 90100013                 mov     %l3, %o0
F00C3874: 912a2018                 sll     %o0, 24, %o0
F00C3878: 80a22000                 cmp     %o0, 0
F00C387C: 12800008                 bne     loc_F00C389C
F00C3880: 94100013                 mov     %l3, %o2
F00C3884: 113c04ba901220a8         set     aConfiguredrive_0, %o0! "configureDriver: Class %s does not resp"...
F00C388C: 40000a1a                 call    _IOLog
F00C3890: 92100010                 mov     %l0, %o1
F00C3894: 10bfff49                 ba      loc_F00C35B8
F00C3898: ac05a001                 inc     %l6
F00C389C: 113c0506                 sethi   %hi(paIodevice_0), %o0
F00C38A0: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F00C38A4: 133c0504                 sethi   %hi(paAddloadedclass_0), %o1
F00C38A8: d202600c                 ld      [%o1+%lo(paAddloadedclass_0)], %o1! SEL
F00C38AC: 4000b7f1                 call    _objc_msgSend
F00C38B0: 96100014                 mov     %l4, %o3
F00C38B4: 80a22000                 cmp     %o0, 0
F00C38B8: 22800002                 be,a    loc_F00C38C0
F00C38BC: ba076001                 inc     %i5
F00C38C0: 10bfff3e                 ba      loc_F00C35B8
F00C38C4: ac05a001                 inc     %l6
F00C38C8: 9010001c                 mov     %i4, %o0
F00C38CC: 4000099e                 call    _IOFree
F00C38D0: 92102080                 mov     0x80, %o1! SEL
F00C38D4: 113c0503                 sethi   %hi(paFree), %o0
F00C38D8: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00C38DC: d007bfec                 ld      [%fp+var_14], %o0! id
F00C38E0: 4000b7e4                 call    _objc_msgSend
F00C38E4: 92100010                 mov     %l0, %o1
F00C38E8: 80a5e000                 cmp     %l7, 0
F00C38EC: 02800006                 be      loc_F00C3904
F00C38F0: 90100018                 mov     %i0, %o0! id
F00C38F4: 133c0504                 sethi   %hi(paFreestring), %o1
F00C38F8: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00C38FC: 4000b7dd                 call    _objc_msgSend
F00C3900: 94100017                 mov     %l7, %o2
F00C3904: 80a6e000                 cmp     %i3, 0
F00C3908: 02800006                 be      loc_F00C3920
F00C390C: 90100018                 mov     %i0, %o0! id
F00C3910: 133c0504                 sethi   %hi(paFreestring), %o1
F00C3914: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00C3918: 4000b7d6                 call    _objc_msgSend
F00C391C: 9410001b                 mov     %i3, %o2
F00C3920: 80a76000                 cmp     %i5, 0
F00C3924: 02800004                 be      loc_F00C3934
F00C3928: 80a62000                 cmp     %i0, 0
F00C392C: 10800051                 ba      locret_F00C3A70
F00C3930: b0102001                 mov     1, %i0
F00C3934: 02800004                 be      loc_F00C3944
F00C3938: 90100018                 mov     %i0, %o0! id
F00C393C: 4000b7cd                 call    _objc_msgSend
F00C3940: 92100010                 mov     %l0, %o1! SEL
F00C3944: 80a52000                 cmp     %l4, 0
F00C3948: 02800004                 be      loc_F00C3958
F00C394C: 90100014                 mov     %l4, %o0! id
F00C3950: 4000b7c8                 call    _objc_msgSend
F00C3954: 92100010                 mov     %l0, %o1! SEL
F00C3958: 80a46000                 cmp     %l1, 0
F00C395C: 02800004                 be      loc_F00C396C
F00C3960: 90100011                 mov     %l1, %o0! id
F00C3964: 4000b7c3                 call    _objc_msgSend
F00C3968: 92100010                 mov     %l0, %o1
F00C396C: 80a66000                 cmp     %i1, 0
F00C3970: 0280003f                 be      loc_F00C3A6C
F00C3974: 90100019                 mov     %i1, %o0
F00C3978: 1080003b                 ba      loc_F00C3A64
F00C397C: 92100010                 mov     %l0, %o1
F00C3980: 113c04b9901223a8         set     aConfiguredrive_1, %o0! "configureDriver: could not find device "...
F00C3988: d207bfcc                 ld      [%fp+__s1], %o1
F00C398C: 400009da                 call    _IOLog
F00C3990: 94100010                 mov     %l0, %o2
F00C3994: 1080000d                 ba      loc_F00C39C8
F00C3998: 80a5e000                 cmp     %l7, 0
F00C399C: 10800007                 ba      loc_F00C39B8
F00C39A0: 901223f0                 bset    0x3F0, %o0
F00C39A4: 113c04ba                 sethi   %hi(aConfiguredrive_2), %o0! "configureDriver: initFromDeviceDescript"...
F00C39A8: 10800004                 ba      loc_F00C39B8
F00C39AC: 90122030                 bset    %lo(aConfiguredrive_2), %o0! "configureDriver: initFromDeviceDescript"...
F00C39B0: 113c04b990122368         set     aConfiguredrive_3, %o0! "configureDriver: initFromConfigTable fa"...
F00C39B8: 92100010                 mov     %l0, %o1
F00C39BC: 400009ce                 call    _IOLog
F00C39C0: 01000000                 nop
F00C39C4: 80a5e000                 cmp     %l7, 0
F00C39C8: 02800006                 be      loc_F00C39E0
F00C39CC: 90100018                 mov     %i0, %o0! id
F00C39D0: 133c0504                 sethi   %hi(paFreestring), %o1
F00C39D4: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00C39D8: 4000b7a6                 call    _objc_msgSend
F00C39DC: 94100017                 mov     %l7, %o2
F00C39E0: 80a6e000                 cmp     %i3, 0
F00C39E4: 02800006                 be      loc_F00C39FC
F00C39E8: 90100018                 mov     %i0, %o0! id
F00C39EC: 133c0504                 sethi   %hi(paFreestring), %o1
F00C39F0: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00C39F4: 4000b79f                 call    _objc_msgSend
F00C39F8: 9410001b                 mov     %i3, %o2
F00C39FC: 80a62000                 cmp     %i0, 0
F00C3A00: 02800007                 be      loc_F00C3A1C
F00C3A04: 80a52000                 cmp     %l4, 0
F00C3A08: 113c0503                 sethi   %hi(paFree), %o0! id
F00C3A0C: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C3A10: 4000b798                 call    _objc_msgSend
F00C3A14: 90100018                 mov     %i0, %o0
F00C3A18: 80a52000                 cmp     %l4, 0
F00C3A1C: 02800007                 be      loc_F00C3A38
F00C3A20: 80a46000                 cmp     %l1, 0
F00C3A24: 113c0503                 sethi   %hi(paFree), %o0! id
F00C3A28: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C3A2C: 4000b791                 call    _objc_msgSend
F00C3A30: 90100014                 mov     %l4, %o0
F00C3A34: 80a46000                 cmp     %l1, 0
F00C3A38: 02800007                 be      loc_F00C3A54
F00C3A3C: 80a66000                 cmp     %i1, 0
F00C3A40: 113c0503                 sethi   %hi(paFree), %o0! id
F00C3A44: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C3A48: 4000b78a                 call    _objc_msgSend
F00C3A4C: 90100011                 mov     %l1, %o0
F00C3A50: 80a66000                 cmp     %i1, 0
F00C3A54: 02800006                 be      loc_F00C3A6C
F00C3A58: 113c0503                 sethi   %hi(paFree), %o0
F00C3A5C: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C3A60: 90100019                 mov     %i1, %o0! id
F00C3A64: 4000b783                 call    _objc_msgSend
F00C3A68: 01000000                 nop
F00C3A6C: b0102000                 mov     0, %i0
F00C3A70: 81c7e008                 ret
F00C3A74: 81e80000                 restore
