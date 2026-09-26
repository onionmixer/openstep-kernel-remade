F00F36E4: 9de3bf98                 save    %sp, -0x68, %sp
F00F36E8: 80a62000                 cmp     %i0, 0
F00F36EC: 12800004                 bne     loc_F00F36FC
F00F36F0: 92100018                 mov     %i0, %o1
F00F36F4: 1080007d                 ba      locret_F00F38E8
F00F36F8: b0102000                 mov     0, %i0
F00F36FC: 94102000                 mov     0, %o2
F00F3700: d00a4000                 ldub    [%o1], %o0
F00F3704: 80a22000                 cmp     %o0, 0
F00F3708: 02800016                 be      loc_F00F3760
F00F370C: 92026001                 inc     %o1
F00F3710: 941a8008                 btog    %o0, %o2
F00F3714: d00a4000                 ldub    [%o1], %o0
F00F3718: 80a22000                 cmp     %o0, 0
F00F371C: 02800011                 be      loc_F00F3760
F00F3720: 912a2008                 sll     %o0, 8, %o0
F00F3724: 941a8008                 btog    %o0, %o2
F00F3728: 92026001                 inc     %o1
F00F372C: d00a4000                 ldub    [%o1], %o0
F00F3730: 80a22000                 cmp     %o0, 0
F00F3734: 0280000b                 be      loc_F00F3760
F00F3738: 912a2010                 sll     %o0, 16, %o0
F00F373C: 941a8008                 btog    %o0, %o2
F00F3740: 92026001                 inc     %o1
F00F3744: d00a4000                 ldub    [%o1], %o0
F00F3748: 80a22000                 cmp     %o0, 0
F00F374C: 02800005                 be      loc_F00F3760
F00F3750: 912a2018                 sll     %o0, 24, %o0
F00F3754: 941a8008                 btog    %o0, %o2
F00F3758: 10bfffea                 ba      loc_F00F3700
F00F375C: 92026001                 inc     %o1
F00F3760: 113c04bc                 sethi   %hi(off_F012F16C), %o0
F00F3764: e202216c                 ld      [%o0+%lo(off_F012F16C)], %l1
F00F3768: 80a46000                 cmp     %l1, 0
F00F376C: 0280005d                 be      loc_F00F38E0
F00F3770: a810000a                 mov     %o2, %l4
F00F3774: 113c04bcac122150         set     unk_F012F150, %l6
F00F377C: 113c03e8ae122388         set     unk_F00FA388, %l7
F00F3784: 2b3c04bc                 sethi   -0xFED1000, %l5
F00F3788: 273c04bc                 sethi   -0xFED1000, %l3
F00F378C: d004600c                 ld      [%l1+0xC], %o0
F00F3790: 80a60008                 cmp     %i0, %o0
F00F3794: 0a800006                 bcs     loc_F00F37AC
F00F3798: 90100014                 mov     %l4, %o0
F00F379C: d0046010                 ld      [%l1+0x10], %o0
F00F37A0: 80a60008                 cmp     %i0, %o0
F00F37A4: 0a800051                 bcs     locret_F00F38E8
F00F37A8: 90100014                 mov     %l4, %o0
F00F37AC: 7ffc4c3d                 call    _urem
F00F37B0: d2046004                 ld      [%l1+4], %o1
F00F37B4: a4100008                 mov     %o0, %l2
F00F37B8: d2046014                 ld      [%l1+0x14], %o1
F00F37BC: 912ca002                 sll     %l2, 2, %o0
F00F37C0: e0024008                 ld      [%o1+%o0], %l0
F00F37C4: 80a42000                 cmp     %l0, 0
F00F37C8: 02800013                 be      loc_F00F3814
F00F37CC: 80a44016                 cmp     %l1, %l6
F00F37D0: d4042004                 ld      [%l0+4], %o2
F00F37D4: d24e0000                 ldsb    [%i0], %o1! __s2
F00F37D8: d04a8000                 ldsb    [%o2], %o0
F00F37DC: 80a24008                 cmp     %o1, %o0
F00F37E0: 32800009                 bne,a   loc_F00F3804
F00F37E4: e0040000                 ld      [%l0], %l0
F00F37E8: 90100018                 mov     %i0, %o0! __s1
F00F37EC: 7ffc5270                 call    _strcmp
F00F37F0: 9210000a                 mov     %o2, %o1
F00F37F4: 80a22000                 cmp     %o0, 0
F00F37F8: 2280003c                 be,a    locret_F00F38E8
F00F37FC: f0042004                 ld      [%l0+4], %i0
F00F3800: e0040000                 ld      [%l0], %l0
F00F3804: 80a42000                 cmp     %l0, 0
F00F3808: 32bffff3                 bne,a   loc_F00F37D4
F00F380C: d4042004                 ld      [%l0+4], %o2
F00F3810: 80a44016                 cmp     %l1, %l6
F00F3814: 32800030                 bne,a   loc_F00F38D4
F00F3818: e2046018                 ld      [%l1+0x18], %l1
F00F381C: d0046008                 ld      [%l1+8], %o0
F00F3820: 90022001                 inc     %o0
F00F3824: d0246008                 st      %o0, [%l1+8]
F00F3828: d0046014                 ld      [%l1+0x14], %o0
F00F382C: 80a20017                 cmp     %o0, %l7
F00F3830: 32800011                 bne,a   loc_F00F3874
F00F3834: 932ca002                 sll     %l2, 2, %o1
F00F3838: 90102335                 mov     0x335, %o0
F00F383C: d0246004                 st      %o0, [%l1+4]
F00F3840: 7fffff47                 call    sub_F00F355C
F00F3844: 90102cd4                 mov     0xCD4, %o0! __b
F00F3848: d0246014                 st      %o0, [%l1+0x14]
F00F384C: d4046004                 ld      [%l1+4], %o2! __len
F00F3850: 92102000                 mov     0, %o1! __c
F00F3854: 7ffc4aca                 call    _memset
F00F3858: 952aa002                 sll     %o2, 2, %o2
F00F385C: 90100014                 mov     %l4, %o0
F00F3860: 7ffc4c10                 call    _urem
F00F3864: d2046004                 ld      [%l1+4], %o1
F00F3868: a4100008                 mov     %o0, %l2
F00F386C: d0046014                 ld      [%l1+0x14], %o0
F00F3870: 932ca002                 sll     %l2, 2, %o1
F00F3874: e0020009                 ld      [%o0+%o1], %l0
F00F3878: d0056174                 ld      [%l5+0x174], %o0
F00F387C: 80a22000                 cmp     %o0, 0
F00F3880: 02800005                 be      loc_F00F3894
F00F3884: d004e178                 ld      [%l3+0x178], %o0
F00F3888: 80a22027                 cmp     %o0, 0x27 ! '''
F00F388C: 04800007                 ble     loc_F00F38A8
F00F3890: d204e178                 ld      [%l3+0x178], %o1
F00F3894: 7fffff32                 call    sub_F00F355C
F00F3898: 90102140                 mov     0x140, %o0
F00F389C: d0256174                 st      %o0, [%l5+0x174]
F00F38A0: c024e178                 clr     [%l3+0x178]
F00F38A4: d204e178                 ld      [%l3+0x178], %o1
F00F38A8: 90026001                 add     %o1, 1, %o0
F00F38AC: d024e178                 st      %o0, [%l3+0x178]
F00F38B0: 932a6003                 sll     %o1, 3, %o1
F00F38B4: d0056174                 ld      [%l5+0x174], %o0
F00F38B8: 94024008                 add     %o1, %o0, %o2
F00F38BC: e0224008                 st      %l0, [%o1+%o0]
F00F38C0: f022a004                 st      %i0, [%o2+4]
F00F38C4: d2046014                 ld      [%l1+0x14], %o1
F00F38C8: 912ca002                 sll     %l2, 2, %o0
F00F38CC: 10800007                 ba      locret_F00F38E8
F00F38D0: d4224008                 st      %o2, [%o1+%o0]
F00F38D4: 80a46000                 cmp     %l1, 0
F00F38D8: 32bfffae                 bne,a   loc_F00F3790
F00F38DC: d004600c                 ld      [%l1+0xC], %o0
F00F38E0: 7ffe62a4                 call    _abort
F00F38E8: 81c7e008                 ret
F00F38EC: 81e80000                 restore
