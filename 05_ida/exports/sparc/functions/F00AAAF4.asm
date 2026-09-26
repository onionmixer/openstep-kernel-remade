F00AAAF4: 9de3bf90                 save    %sp, -0x70, %sp
F00AAAF8: f027a044                 st      %i0, [%fp+arg_44]
F00AAAFC: 133c04d4                 sethi   %hi(_cons_tp), %o1
F00AAB00: 113c04d490122190         set     _cons, %o0
F00AAB08: d0226290                 st      %o0, [%o1+%lo(_cons_tp)]
F00AAB0C: 92102c00                 mov     0xC00, %o1
F00AAB10: 400045b0                 call    _kminit
F00AAB14: d2322038                 sth     %o1, [%o0+0x38]
F00AAB18: 92102000                 mov     0, %o1
F00AAB1C: 94102000                 mov     0, %o2
F00AAB20: 96102000                 mov     0, %o3
F00AAB24: 113c047f                 sethi   %hi(_mach_title), %o0
F00AAB28: d0022274                 ld      [%o0+%lo(_mach_title)], %o0
F00AAB2C: 40004557                 call    _kmpopup
F00AAB30: 98102000                 mov     0, %o4
F00AAB34: 7fffff83                 call    _startup_early
F00AAB38: 233c0470                 sethi   %hi(aPhysicalMemory), %l1! "physical memory = %d.%d%d megabytes.\n"
F00AAB3C: 113c04f0                 sethi   %hi(_virtual_avail), %o0
F00AAB40: d0022110                 ld      [%o0+%lo(_virtual_avail)], %o0! mach_port_t
F00AAB44: 7ffda986                 call    _panic_init
F00AAB48: d027a044                 st      %o0, [%fp+arg_44]
F00AAB4C: 113c04bc                 sethi   %hi(_version), %o0! "NeXT Mach 4.2: Sun Apr 27 14:33:09 PDT "...
F00AAB50: 7ffda6c2                 call    _printf
F00AAB54: 90122190                 bset    %lo(_version), %o0! "NeXT Mach 4.2: Sun Apr 27 14:33:09 PDT "...
F00AAB58: 113c04f0                 sethi   %hi(_mem_size), %o0
F00AAB5C: 1300006692126199         set     0x19999, %o1
F00AAB64: a2146090                 bset    %lo(aPhysicalMemory), %l1! "physical memory = %d.%d%d megabytes.\n"
F00AAB68: d0022108                 ld      [%o0+%lo(_mem_size)], %o0
F00AAB6C: 153ffc00                 sethi   -0x100000, %o2
F00AAB70: a5322014                 srl     %o0, 20, %l2
F00AAB74: 942a000a                 andn    %o0, %o2, %o2
F00AAB78: a12aa002                 sll     %o2, 2, %l0
F00AAB7C: a004000a                 add     %l0, %o2, %l0
F00AAB80: a12c2001                 sll     %l0, 1, %l0
F00AAB84: 7ffd6f47                 call    _urem
F00AAB88: a1342014                 srl     %l0, 20, %l0
F00AAB8C: 98100008                 mov     %o0, %o4
F00AAB90: 90100011                 mov     %l1, %o0! char *
F00AAB94: 92100012                 mov     %l2, %o1
F00AAB98: 94100010                 mov     %l0, %o2
F00AAB9C: 972b2001                 sll     %o4, 1, %o3
F00AABA0: 9602c00c                 add     %o3, %o4, %o3
F00AABA4: 972ae003                 sll     %o3, 3, %o3
F00AABA8: 9602c00c                 add     %o3, %o4, %o3
F00AABAC: 972ae002                 sll     %o3, 2, %o3
F00AABB0: 7ffda6aa                 call    _printf
F00AABB4: 9732e014                 srl     %o3, 20, %o3
F00AABB8: 293c04d0                 sethi   %hi(_page_mask), %l4
F00AABBC: d40520d8                 ld      [%l4+%lo(_page_mask)], %o2
F00AABC0: 90102000                 mov     0, %o0
F00AABC4: d207a044                 ld      [%fp+arg_44], %o1
F00AABC8: 273c04d1                 sethi   %hi(_kernel_map), %l3
F00AABCC: e004e340                 ld      [%l3+%lo(_kernel_map)], %l0
F00AABD0: 9202400a                 add     %o1, %o2, %o1
F00AABD4: 942a400a                 andn    %o1, %o2, %o2
F00AABD8: 7fff6ef2                 call    _vm_object_allocate
F00AABDC: d427a044                 st      %o2, [%fp+arg_44]
F00AABE0: 92100008                 mov     %o0, %o1
F00AABE4: 90100010                 mov     %l0, %o0
F00AABE8: 94102000                 mov     0, %o2
F00AABEC: 9607a044                 add     %fp, arg_44, %o3
F00AABF0: 19002000                 sethi   0x800000, %o4
F00AABF4: 7fff6677                 call    _vm_map_find
F00AABF8: 9a102001                 mov     1, %o5
F00AABFC: d207a044                 ld      [%fp+arg_44], %o1
F00AAC00: 15002000                 sethi   0x800000, %o2
F00AAC04: d004e340                 ld      [%l3+%lo(_kernel_map)], %o0
F00AAC08: 7fff69ce                 call    _vm_map_remove
F00AAC0C: 9402400a                 add     %o1, %o2, %o2
F00AAC10: 2f3c04cf                 sethi   %hi(_buffers), %l7
F00AAC14: f007a044                 ld      [%fp+arg_44], %i0
F00AAC18: 2d3c0470                 sethi   %hi(_nbuf), %l6
F00AAC1C: e005a058                 ld      [%l6+%lo(_nbuf)], %l0
F00AAC20: 113c0470                 sethi   %hi(_bufpages), %o0
F00AAC24: e2022060                 ld      [%o0+%lo(_bufpages)], %l1
F00AAC28: f025e2f8                 st      %i0, [%l7+%lo(_buffers)]
F00AAC2C: 932c200d                 sll     %l0, 13, %o1! int
F00AAC30: a4100018                 mov     %i0, %l2
F00AAC34: b0060009                 add     %i0, %o1, %i0
F00AAC38: 90100011                 mov     %l1, %o0! int
F00AAC3C: 7ffd6e73                 call    _div
F00AAC40: 92100010                 mov     %l0, %o1
F00AAC44: aa100008                 mov     %o0, %l5
F00AAC48: 90100011                 mov     %l1, %o0
F00AAC4C: 7ffd6f17                 call    _rem
F00AAC50: 92100010                 mov     %l0, %o1
F00AAC54: 9207a044                 add     %fp, arg_44, %o1
F00AAC58: 9407bff4                 add     %fp, var_C, %o2
F00AAC5C: da0520d8                 ld      [%l4+0xD8], %o5
F00AAC60: 98102001                 mov     1, %o4
F00AAC64: a8100008                 mov     %o0, %l4
F00AAC68: 9606000d                 add     %i0, %o5, %o3
F00AAC6C: b02ac00d                 andn    %o3, %o5, %i0
F00AAC70: a4260012                 sub     %i0, %l2, %l2
F00AAC74: d004e340                 ld      [%l3+0x340], %o0
F00AAC78: 7fff6356                 call    _kmem_suballoc
F00AAC7C: 96100012                 mov     %l2, %o3
F00AAC80: a0100008                 mov     %o0, %l0
F00AAC84: 273c04fb                 sethi   %hi(_buffer_map), %l3
F00AAC88: e024e090                 st      %l0, [%l3+%lo(_buffer_map)]
F00AAC8C: 7fff6ec5                 call    _vm_object_allocate
F00AAC90: 90100012                 mov     %l2, %o0
F00AAC94: 92100008                 mov     %o0, %o1
F00AAC98: 90100010                 mov     %l0, %o0
F00AAC9C: 94102000                 mov     0, %o2
F00AACA0: 9607a044                 add     %fp, arg_44, %o3
F00AACA4: 98100012                 mov     %l2, %o4
F00AACA8: 7fff664a                 call    _vm_map_find
F00AACAC: 9a102000                 mov     0, %o5
F00AACB0: d005a058                 ld      [%l6+0x58], %o0
F00AACB4: a0102000                 mov     0, %l0
F00AACB8: 80a40008                 cmp     %l0, %o0
F00AACBC: 1a80001a                 bcc     loc_F00AAD24
F00AACC0: a4056001                 add     %l5, 1, %l2
F00AACC4: 233c0447                 sethi   -0xFEEE400, %l1
F00AACC8: b0100013                 mov     %l3, %i0
F00AACCC: a6100016                 mov     %l6, %l3
F00AACD0: 80a40014                 cmp     %l0, %l4
F00AACD4: 1a800004                 bcc     loc_F00AACE4
F00AACD8: d004613c                 ld      [%l1+0x13C], %o0
F00AACDC: 10800003                 ba      loc_F00AACE8
F00AACE0: 92100012                 mov     %l2, %o1
F00AACE4: 92100015                 mov     %l5, %o1
F00AACE8: 7ffd6e06                 call    _umul
F00AACEC: 01000000                 nop
F00AACF0: 98100008                 mov     %o0, %o4
F00AACF4: 96102000                 mov     0, %o3
F00AACF8: d205e2f8                 ld      [%l7+0x2F8], %o1
F00AACFC: 952c200d                 sll     %l0, 13, %o2
F00AAD00: d0062090                 ld      [%i0+0x90], %o0
F00AAD04: 9202400a                 add     %o1, %o2, %o1
F00AAD08: 7fff6839                 call    _vm_map_pageable
F00AAD0C: 9402400c                 add     %o1, %o4, %o2
F00AAD10: d004e058                 ld      [%l3+0x58], %o0
F00AAD14: a0042001                 inc     %l0
F00AAD18: 80a40008                 cmp     %l0, %o0
F00AAD1C: 0abfffee                 bcs     loc_F00AACD4
F00AAD20: 80a40014                 cmp     %l0, %l4
F00AAD24: 113c0470                 sethi   %hi(_bufpages), %o0
F00AAD28: d2022060                 ld      [%o0+%lo(_bufpages)], %o1
F00AAD2C: 293c04f4                 sethi   %hi(_page_shift), %l4
F00AAD30: d0052348                 ld      [%l4+%lo(_page_shift)], %o0
F00AAD34: 992a4008                 sll     %o1, %o0, %o4
F00AAD38: 94930000                 orcc    %o4, %g0, %o2
F00AAD3C: 133c0470                 sethi   %hi(aUsingDBuffersC), %o1! "using %d buffers containing %d.%d%d meg"...
F00AAD40: 113c0470                 sethi   %hi(_nbuf), %o0
F00AAD44: e4022058                 ld      [%o0+%lo(_nbuf)], %l2
F00AAD48: 16800005                 bge     loc_F00AAD5C
F00AAD4C: aa1260b8                 or      %o1, %lo(aUsingDBuffersC), %l5! "using %d buffers containing %d.%d%d meg"...
F00AAD50: 110003ff901223ff         set     0xFFFFF, %o0
F00AAD58: 94030008                 add     %o4, %o0, %o2
F00AAD5C: a33aa014                 sra     %o2, 20, %l1
F00AAD60: 932c6014                 sll     %l1, 20, %o1
F00AAD64: 92230009                 sub     %o4, %o1, %o1
F00AAD68: 912a6002                 sll     %o1, 2, %o0
F00AAD6C: 90020009                 add     %o0, %o1, %o0
F00AAD70: 96820008                 addcc   %o0, %o0, %o3
F00AAD74: 1c800006                 bpos    loc_F00AAD8C
F00AAD78: 9010000c                 mov     %o4, %o0
F00AAD7C: 110003ff901223ff         set     0xFFFFF, %o0
F00AAD84: 9602c008                 add     %o3, %o0, %o3
F00AAD88: 9010000c                 mov     %o4, %o0
F00AAD8C: 270000669214e199         set     0x19999, %o1
F00AAD94: 7ffd6ec5                 call    _rem
F00AAD98: a13ae014                 sra     %o3, 20, %l0
F00AAD9C: 932a2001                 sll     %o0, 1, %o1
F00AADA0: 92024008                 add     %o1, %o0, %o1
F00AADA4: 932a6003                 sll     %o1, 3, %o1
F00AADA8: 92024008                 add     %o1, %o0, %o1
F00AADAC: 992a6002                 sll     %o1, 2, %o4
F00AADB0: 80a32000                 cmp     %o4, 0
F00AADB4: 16800006                 bge     loc_F00AADCC
F00AADB8: 90100015                 mov     %l5, %o0
F00AADBC: 110003ff901223ff         set     0xFFFFF, %o0
F00AADC4: 98030008                 add     %o4, %o0, %o4
F00AADC8: 90100015                 mov     %l5, %o0! char *
F00AADCC: 92100012                 mov     %l2, %o1
F00AADD0: 94100011                 mov     %l1, %o2
F00AADD4: 96100010                 mov     %l0, %o3
F00AADD8: 7ffda620                 call    _printf
F00AADDC: 993b2014                 sra     %o4, 20, %o4
F00AADE0: 113c04f3                 sethi   %hi(_vm_page_free_count), %o0
F00AADE4: e4022000                 ld      [%o0+%lo(_vm_page_free_count)], %l2
F00AADE8: d0052348                 ld      [%l4+0x348], %o0
F00AADEC: 992c8008                 sll     %l2, %o0, %o4
F00AADF0: 92930000                 orcc    %o4, %g0, %o1
F00AADF4: 113c0470                 sethi   %hi(aAvailableMemor), %o0! "available memory = %d.%d%d megabytes. v"...
F00AADF8: 16800005                 bge     loc_F00AAE0C
F00AADFC: a81220f8                 or      %o0, %lo(aAvailableMemor), %l4! "available memory = %d.%d%d megabytes. v"...
F00AAE00: 110003ff901223ff         set     0xFFFFF, %o0
F00AAE08: 92030008                 add     %o4, %o0, %o1
F00AAE0C: a33a6014                 sra     %o1, 20, %l1
F00AAE10: 932c6014                 sll     %l1, 20, %o1
F00AAE14: 92230009                 sub     %o4, %o1, %o1
F00AAE18: 912a6002                 sll     %o1, 2, %o0
F00AAE1C: 90020009                 add     %o0, %o1, %o0
F00AAE20: 94820008                 addcc   %o0, %o0, %o2
F00AAE24: 1c800006                 bpos    loc_F00AAE3C
F00AAE28: 9010000c                 mov     %o4, %o0
F00AAE2C: 110003ff901223ff         set     0xFFFFF, %o0
F00AAE34: 94028008                 add     %o2, %o0, %o2
F00AAE38: 9010000c                 mov     %o4, %o0
F00AAE3C: 9214e199                 or      %l3, 0x199, %o1
F00AAE40: 7ffd6e9a                 call    _rem
F00AAE44: a13aa014                 sra     %o2, 20, %l0
F00AAE48: 932a2001                 sll     %o0, 1, %o1
F00AAE4C: 92024008                 add     %o1, %o0, %o1
F00AAE50: 932a6003                 sll     %o1, 3, %o1
F00AAE54: 92024008                 add     %o1, %o0, %o1
F00AAE58: 972a6002                 sll     %o1, 2, %o3
F00AAE5C: 80a2e000                 cmp     %o3, 0
F00AAE60: 16800006                 bge     loc_F00AAE78
F00AAE64: 90100014                 mov     %l4, %o0
F00AAE68: 110003ff901223ff         set     0xFFFFF, %o0
F00AAE70: 9602c008                 add     %o3, %o0, %o3
F00AAE74: 90100014                 mov     %l4, %o0! char *
F00AAE78: 92100011                 mov     %l1, %o1
F00AAE7C: 94100010                 mov     %l0, %o2
F00AAE80: 973ae014                 sra     %o3, 20, %o3
F00AAE84: 7ffda5f5                 call    _printf
F00AAE88: 98100012                 mov     %l2, %o4
F00AAE8C: 7fffbc15                 call    _callout_init
F00AAE90: 01000000                 nop
F00AAE94: 7fffb27d                 call    _clock_timer_init
F00AAE98: 01000000                 nop
F00AAE9C: 133c04d292126350         set     _mbutl, %o1
F00AAEA4: 153c04d29412a260         set     _embutl, %o2
F00AAEAC: 113c043c                 sethi   %hi(_nmbclusters), %o0
F00AAEB0: d602237c                 ld      [%o0+%lo(_nmbclusters)], %o3
F00AAEB4: 98102000                 mov     0, %o4
F00AAEB8: 113c04d1                 sethi   %hi(_kernel_map), %o0
F00AAEBC: d0022340                 ld      [%o0+%lo(_kernel_map)], %o0
F00AAEC0: 7fff62c4                 call    _kmem_suballoc
F00AAEC4: 972ae00a                 sll     %o3, 10, %o3
F00AAEC8: 133c04d1                 sethi   %hi(_mb_map), %o1
F00AAECC: d0226380                 st      %o0, [%o1+%lo(_mb_map)]
F00AAED0: 153c0470                 sethi   %hi(_debug_init_done), %o2
F00AAED4: 92102001                 mov     1, %o1
F00AAED8: 113c0464                 sethi   %hi(_iom), %o0
F00AAEDC: d0022338                 ld      [%o0+%lo(_iom)], %o0
F00AAEE0: 80a22000                 cmp     %o0, 0
F00AAEE4: 02800004                 be      loc_F00AAEF4
F00AAEE8: d222a064                 st      %o1, [%o2+%lo(_debug_init_done)]
F00AAEEC: 7fffb9c2                 call    _iom_init
F00AAEF0: 01000000                 nop
F00AAEF4: 400015c6                 call    _configure
F00AAEF8: 01000000                 nop
F00AAEFC: 7fffaf79                 call    _spl0
F00AAF00: 01000000                 nop
F00AAF04: 81c7e008                 ret
F00AAF08: 81e80000                 restore
