F00A3338: 9de3bf98                 save    %sp, -0x68, %sp
F00A333C: 40000118                 call    sub_F00A379C
F00A3340: 213c000c                 sethi   %hi(_bootops), %l0
F00A3344: d0042038                 ld      [%l0+%lo(_bootops)], %o0
F00A3348: d002203c                 ld      [%o0+0x3C], %o0! void *
F00A334C: 80a22000                 cmp     %o0, 0
F00A3350: 02800006                 be      loc_F00A3368
F00A3354: 133c0485                 sethi   %hi(_static_KERNBOOTSTRUCT), %o1
F00A3358: 92126050                 bset    %lo(_static_KERNBOOTSTRUCT), %o1! void *
F00A335C: 15000034                 sethi   0xD000, %o2! size_t
F00A3360: 7fffc5ec                 call    _bcopy
F00A3364: 9412a128                 bset    0x128, %o2
F00A3368: 7fff1b0f                 call    _getlastaddr
F00A336C: 01000000                 nop
F00A3370: d2042038                 ld      [%l0+0x38], %o1
F00A3374: 153c04f8                 sethi   %hi(_end), %o2
F00A3378: d2026040                 ld      [%o1+0x40], %o1
F00A337C: d022a130                 st      %o0, [%o2+%lo(_end)]
F00A3380: 90020009                 add     %o0, %o1, %o0
F00A3384: 400000fe                 call    sub_F00A377C
F00A3388: d022a130                 st      %o0, [%o2+%lo(_end)]
F00A338C: 133c04f6                 sethi   %hi(_etext), %o1
F00A3390: d02261e0                 st      %o0, [%o1+%lo(_etext)]
F00A3394: 113c0464                 sethi   %hi(aNextstep_0), %o0! "NeXTSTEP"
F00A3398: 40002f8f                 call    _prom_init
F00A339C: 90122360                 bset    %lo(aNextstep_0), %o0! "NeXTSTEP"
F00A33A0: 7fffd368                 call    _map_wellknown_devices
F00A33A4: 213c044a                 sethi   %hi(_mach_info), %l0
F00A33A8: 7fffd466                 call    _fill_machinfo
F00A33AC: 01000000                 nop
F00A33B0: 7fffd493                 call    _fill_hostidinfo
F00A33B4: 01000000                 nop
F00A33B8: 40003816                 call    _setcputype
F00A33BC: 01000000                 nop
F00A33C0: 400000e0                 call    sub_F00A3740
F00A33C4: d0042238                 ld      [%l0+%lo(_mach_info)], %o0
F00A33C8: d2042238                 ld      [%l0+%lo(_mach_info)], %o1
F00A33CC: 113c04f8                 sethi   %hi(_cpu), %o0
F00A33D0: d2222120                 st      %o1, [%o0+%lo(_cpu)]
F00A33D4: 113c044a                 sethi   %hi(_mod_info), %o0
F00A33D8: 4000023d                 call    _setcpudelay
F00A33DC: a2122264                 or      %o0, %lo(_mod_info), %l1
F00A33E0: d0046018                 ld      [%l1+0x18], %o0
F00A33E4: 80a22000                 cmp     %o0, 0
F00A33E8: 02800015                 be      loc_F00A343C
F00A33EC: 113c044a                 sethi   -0xFEED800, %o0
F00A33F0: d0046020                 ld      [%l1+0x20], %o0
F00A33F4: 80a22000                 cmp     %o0, 0
F00A33F8: 0280000c                 be      loc_F00A3428
F00A33FC: 113c0464                 sethi   -0xFEE7000, %o0
F00A3400: d0046064                 ld      [%l1+0x64], %o0
F00A3404: 80a22000                 cmp     %o0, 0
F00A3408: 02800005                 be      loc_F00A341C
F00A340C: 133c0464                 sethi   %hi(_cache), %o1
F00A3410: 90102003                 mov     3, %o0
F00A3414: 10800009                 ba      loc_F00A3438
F00A3418: d0226330                 st      %o0, [%o1+%lo(_cache)]
F00A341C: 90102002                 mov     2, %o0
F00A3420: 10800006                 ba      loc_F00A3438
F00A3424: d0226330                 st      %o0, [%o1+0x330]
F00A3428: 92102001                 mov     1, %o1
F00A342C: d2222330                 st      %o1, [%o0+0x330]
F00A3430: 113c0464                 sethi   %hi(_vac), %o0
F00A3434: d2222334                 st      %o1, [%o0+%lo(_vac)]
F00A3438: 113c044a                 sethi   -0xFEED800, %o0
F00A343C: d2022244                 ld      [%o0+0x244], %o1
F00A3440: 153c0464                 sethi   %hi(_bcopy_buf), %o2
F00A3444: 113c0464                 sethi   %hi(_iom), %o0
F00A3448: d2222338                 st      %o1, [%o0+%lo(_iom)]
F00A344C: d2046044                 ld      [%l1+0x44], %o1
F00A3450: 173c0464                 sethi   %hi(_nctxs), %o3
F00A3454: d002e310                 ld      [%o3+%lo(_nctxs)], %o0
F00A3458: 80a22000                 cmp     %o0, 0
F00A345C: 12800008                 bne     loc_F00A347C
F00A3460: d222a33c                 st      %o1, [%o2+%lo(_bcopy_buf)]
F00A3464: d0046038                 ld      [%l1+0x38], %o0
F00A3468: 13000004                 sethi   0x1000, %o1
F00A346C: 80a20009                 cmp     %o0, %o1
F00A3470: 08800003                 bleu    loc_F00A347C
F00A3474: d022e310                 st      %o0, [%o3+%lo(_nctxs)]
F00A3478: d222e310                 st      %o1, [%o3+%lo(_nctxs)]
F00A347C: 113c0464                 sethi   %hi(_vac), %o0
F00A3480: d0022334                 ld      [%o0+%lo(_vac)], %o0
F00A3484: 80a22000                 cmp     %o0, 0
F00A3488: 02800011                 be      loc_F00A34CC
F00A348C: 11000004                 sethi   0x1000, %o0! int
F00A3490: e0046028                 ld      [%l1+0x28], %l0
F00A3494: 133c04f8                 sethi   %hi(_vac_linesize), %o1
F00A3498: e0226140                 st      %l0, [%o1+%lo(_vac_linesize)]
F00A349C: e204602c                 ld      [%l1+0x2C], %l1
F00A34A0: 133c04f8                 sethi   %hi(_vac_nlines), %o1! int
F00A34A4: e2226148                 st      %l1, [%o1+%lo(_vac_nlines)]
F00A34A8: 7ffd8c58                 call    _div
F00A34AC: 92100010                 mov     %l0, %o1
F00A34B0: 133c04f8                 sethi   %hi(_vac_pglines), %o1
F00A34B4: d0226150                 st      %o0, [%o1+%lo(_vac_pglines)]
F00A34B8: 90100011                 mov     %l1, %o0
F00A34BC: 7ffd8c11                 call    _umul
F00A34C0: 92100010                 mov     %l0, %o1
F00A34C4: 133c0464                 sethi   %hi(_vac_size), %o1
F00A34C8: d0226318                 st      %o0, [%o1+%lo(_vac_size)]
F00A34CC: 113c0464                 sethi   %hi(_bcopy_buf), %o0
F00A34D0: d002233c                 ld      [%o0+%lo(_bcopy_buf)], %o0
F00A34D4: 80a22000                 cmp     %o0, 0
F00A34D8: 0280000b                 be      loc_F00A3504
F00A34DC: 113c0464                 sethi   %hi(_use_bcopy), %o0
F00A34E0: d0022304                 ld      [%o0+%lo(_use_bcopy)], %o0
F00A34E4: 80a22000                 cmp     %o0, 0
F00A34E8: 02800004                 be      loc_F00A34F8
F00A34EC: 113c0464                 sethi   %hi(_bcopy_res), %o0
F00A34F0: 10800005                 ba      loc_F00A3504
F00A34F4: c0222300                 clr     [%o0+%lo(_bcopy_res)]
F00A34F8: 133c0464                 sethi   %hi(_bcopy_res), %o1
F00A34FC: 90103fff                 mov     -1, %o0
F00A3500: d0226300                 st      %o0, [%o1+%lo(_bcopy_res)]
F00A3504: 40000981                 call    _init_mon_clock
F00A3508: 01000000                 nop
F00A350C: 7fffcd98                 call    _splzs
F00A3510: 01000000                 nop
F00A3514: 7fffff7a                 call    _bootflags
F00A3518: 01000000                 nop
F00A351C: 133c0447                 sethi   %hi(_page_size), %o1
F00A3520: d002613c                 ld      [%o1+%lo(_page_size)], %o0
F00A3524: 80a22000                 cmp     %o0, 0
F00A3528: 12800003                 bne     loc_F00A3534
F00A352C: 11000008                 sethi   0x2000, %o0
F00A3530: d022613c                 st      %o0, [%o1+%lo(_page_size)]
F00A3534: 7fff94d8                 call    _vm_set_page_size
F00A3538: 213c04c5                 sethi   %hi(dword_F013155C), %l0
F00A353C: d004215c                 ld      [%l0+%lo(dword_F013155C)], %o0
F00A3540: 80a22000                 cmp     %o0, 0
F00A3544: 02800003                 be      loc_F00A3550
F00A3548: 912a200a                 sll     %o0, 10, %o0
F00A354C: d024215c                 st      %o0, [%l0+%lo(dword_F013155C)]
F00A3550: 4000023c                 call    _srmmu_init
F00A3554: d004215c                 ld      [%l0+0x15C], %o0
F00A3558: 113c04f0                 sethi   %hi(_mem_size), %o0
F00A355C: d2022108                 ld      [%o0+%lo(_mem_size)], %o1
F00A3560: 153c0464                 sethi   %hi(_vac), %o2
F00A3564: d002a334                 ld      [%o2+%lo(_vac)], %o0
F00A3568: 80a22000                 cmp     %o0, 0
F00A356C: 02800018                 be      loc_F00A35CC
F00A3570: d224215c                 st      %o1, [%l0+0x15C]
F00A3574: 113c0464                 sethi   %hi(_use_cache), %o0
F00A3578: d00222c4                 ld      [%o0+%lo(_use_cache)], %o0
F00A357C: 80a22000                 cmp     %o0, 0
F00A3580: 0280000d                 be      loc_F00A35B4
F00A3584: 113c04f7                 sethi   %hi(_vac_mode), %o0
F00A3588: 7fffc890                 call    _vac_init
F00A358C: c02221f8                 clr     [%o0+%lo(_vac_mode)]
F00A3590: 7fffc914                 call    _cache_on
F00A3594: 01000000                 nop
F00A3598: 400001cd                 call    _setcpudelay
F00A359C: 01000000                 nop
F00A35A0: 113c0464                 sethi   %hi(_vac_size), %o0
F00A35A4: d2022318                 ld      [%o0+%lo(_vac_size)], %o1
F00A35A8: 113c0464                 sethi   %hi(_shm_alignment), %o0
F00A35AC: 10800029                 ba      loc_F00A3650
F00A35B0: d2222328                 st      %o1, [%o0+%lo(_shm_alignment)]
F00A35B4: 113c0464                 sethi   %hi(_cache), %o0
F00A35B8: c0222330                 clr     [%o0+%lo(_cache)]
F00A35BC: 400001c4                 call    _setcpudelay
F00A35C0: c022a334                 clr     [%o2+0x334]
F00A35C4: 10800021                 ba      loc_F00A3648
F00A35C8: 133c0464                 sethi   -0xFEE7000, %o1
F00A35CC: 113c0464                 sethi   %hi(_use_cache), %o0
F00A35D0: d00222c4                 ld      [%o0+%lo(_use_cache)], %o0
F00A35D4: 80a22000                 cmp     %o0, 0
F00A35D8: 22800019                 be,a    loc_F00A363C
F00A35DC: c022a334                 clr     [%o2+0x334]
F00A35E0: 7fffc87a                 call    _vac_init
F00A35E4: 01000000                 nop
F00A35E8: 400001b9                 call    _setcpudelay
F00A35EC: 01000000                 nop
F00A35F0: 113c0464                 sethi   %hi(_no_mix), %o0
F00A35F4: d00222b8                 ld      [%o0+%lo(_no_mix)], %o0
F00A35F8: 80a22000                 cmp     %o0, 0
F00A35FC: 12800013                 bne     loc_F00A3648
F00A3600: 133c0464                 sethi   -0xFEE7000, %o1
F00A3604: 113c0464                 sethi   %hi(_use_mix), %o0
F00A3608: d00222cc                 ld      [%o0+%lo(_use_mix)], %o0
F00A360C: 80a22000                 cmp     %o0, 0
F00A3610: 02800006                 be      loc_F00A3628
F00A3614: 11000004                 sethi   0x1000, %o0
F00A3618: 7fffcb35                 call    _bpt_reg
F00A361C: 92102000                 mov     0, %o1
F00A3620: 1080000a                 ba      loc_F00A3648
F00A3624: 133c0464                 sethi   -0xFEE7000, %o1
F00A3628: 90102000                 mov     0, %o0
F00A362C: 7fffcb30                 call    _bpt_reg
F00A3630: 13000004                 sethi   0x1000, %o1
F00A3634: 10800005                 ba      loc_F00A3648
F00A3638: 133c0464                 sethi   -0xFEE7000, %o1
F00A363C: 113c0464                 sethi   %hi(_cache), %o0
F00A3640: c0222330                 clr     [%o0+%lo(_cache)]
F00A3644: 133c0464                 sethi   -0xFEE7000, %o1
F00A3648: 11000004                 sethi   0x1000, %o0
F00A364C: d0226328                 st      %o0, [%o1+0x328]
F00A3650: 113c0464                 sethi   %hi(_debug_msg), %o0
F00A3654: d0022344                 ld      [%o0+%lo(_debug_msg)], %o0
F00A3658: 80a22000                 cmp     %o0, 0
F00A365C: 02800005                 be      loc_F00A3670
F00A3660: 113c0464                 sethi   -0xFEE7000, %o0
F00A3664: 7fffff23                 call    _print_debug_msg
F00A3668: 01000000                 nop
F00A366C: 113c0464                 sethi   -0xFEE7000, %o0
F00A3670: d202232c                 ld      [%o0+0x32C], %o1
F00A3674: 94102000                 mov     0, %o2
F00A3678: 80a28009                 cmp     %o2, %o1
F00A367C: 16800010                 bge     loc_F00A36BC
F00A3680: 113c044a                 sethi   -0xFEED800, %o0
F00A3684: 113c04f89a122110         set     _a_head, %o5
F00A368C: 9610203f                 mov     0x3F, %o3 ! '?'
F00A3690: 113c04f890122118         set     _a_tail, %o0
F00A3698: 98100009                 mov     %o1, %o4
F00A369C: 92102000                 mov     0, %o1
F00A36A0: d622400d                 st      %o3, [%o1+%o5]
F00A36A4: d6224008                 st      %o3, [%o1+%o0]
F00A36A8: 9402a001                 inc     %o2
F00A36AC: 80a2800c                 cmp     %o2, %o4
F00A36B0: 06bffffc                 bl      loc_F00A36A0
F00A36B4: 92026004                 inc     4, %o1
F00A36B8: 113c044a                 sethi   -0xFEED800, %o0
F00A36BC: d0022240                 ld      [%o0+0x240], %o0
F00A36C0: 94102000                 mov     0, %o2
F00A36C4: 80a28008                 cmp     %o2, %o0
F00A36C8: 1a800005                 bcc     loc_F00A36DC
F00A36CC: 9402a001                 inc     %o2
F00A36D0: 80a28008                 cmp     %o2, %o0
F00A36D4: 0abfffff                 bcs     loc_F00A36D0
F00A36D8: 9402a001                 inc     %o2
F00A36DC: 4000004a                 call    sub_F00A3804
F00A36E0: 01000000                 nop
F00A36E4: 113c04f390122030         set     _mem_region, %o0
F00A36EC: 153c04f09412a110         set     _virtual_avail, %o2
F00A36F4: 133c04f4                 sethi   %hi(_num_regions), %o1
F00A36F8: 173c04f4                 sethi   %hi(_virtual_end), %o3
F00A36FC: d2026330                 ld      [%o1+%lo(_num_regions)], %o1
F00A3700: 7fffe293                 call    _pmap_bootstrap
F00A3704: 9612e338                 bset    %lo(_virtual_end), %o3
F00A3708: 40000914                 call    _start_mon_clock
F00A370C: 01000000                 nop
F00A3710: 7fffce8d                 call    _memerr_init
F00A3714: 01000000                 nop
F00A3718: 113c04d0                 sethi   %hi(_page_mask), %o0
F00A371C: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F00A3720: 13000004                 sethi   0x1000, %o1
F00A3724: 94020009                 add     %o0, %o1, %o2
F00A3728: 7fff8b76                 call    _vm_alloc_from_regions
F00A372C: 902a8008                 andn    %o2, %o0, %o0
F00A3730: 133c042d                 sethi   %hi(_pmsgbuf), %o1
F00A3734: d022608c                 st      %o0, [%o1+%lo(_pmsgbuf)]
F00A3738: 81c7e008                 ret
F00A373C: 81e80000                 restore
