F0064094: 9de3bf88                 save    %sp, -0x78, %sp
F0064098: 133c04ef                 sethi   %hi(_ipc_kmsg_cache), %o1
F006409C: e2026348                 ld      [%o1+%lo(_ipc_kmsg_cache)], %l1
F00640A0: 113c04d0                 sethi   %hi(_active_threads), %o0
F00640A4: 80a46000                 cmp     %l1, 0
F00640A8: 02800004                 be      loc_F00640B8
F00640AC: ec022260                 ld      [%o0+%lo(_active_threads)], %l6
F00640B0: 1080000d                 ba      loc_F00640E4
F00640B4: c0226348                 clr     [%o1+%lo(_ipc_kmsg_cache)]
F00640B8: 40000fee                 call    _kalloc
F00640BC: 90102100                 mov     0x100, %o0
F00640C0: a2920000                 orcc    %o0, %g0, %l1
F00640C4: 32800006                 bne,a   loc_F00640DC
F00640C8: 90102100                 mov     0x100, %o0
F00640CC: 113c043e                 sethi   %hi(aExceptionRaise), %o0! "exception_raise"
F00640D0: 7ffec428                 call    _panic
F00640D4: 901220d8                 bset    %lo(aExceptionRaise), %o0! "exception_raise"
F00640D8: 90102100                 mov     0x100, %o0
F00640DC: d0246008                 st      %o0, [%l1+8]
F00640E0: c024600c                 clr     [%l1+0xC]
F00640E4: c0246010                 clr     [%l1+0x10]
F00640E8: a005a0a8                 add     %l6, 0xA8, %l0
F00640EC: d0040000                 ld      [%l0], %o0
F00640F0: 80a22000                 cmp     %o0, 0
F00640F4: 12bffffe                 bne     loc_F00640EC
F00640F8: 01000000                 nop
F00640FC: 4000cb6b                 call    _simple_lock_try
F0064100: 90100010                 mov     %l0, %o0
F0064104: 80a22000                 cmp     %o0, 0
F0064108: 02bffff9                 be      loc_F00640EC
F006410C: 01000000                 nop
F0064110: e605a0c0                 ld      [%l6+0xC0], %l3
F0064114: 80a4e000                 cmp     %l3, 0
F0064118: 1280001b                 bne     loc_F0064184
F006411C: 01000000                 nop
F0064120: c025a0a8                 clr     [%l6+0xA8]
F0064124: 113c04ef                 sethi   %hi(_ipc_space_reply), %o0
F0064128: d0022338                 ld      [%o0+%lo(_ipc_space_reply)], %o0
F006412C: 9205a0a8                 add     %l6, 0xA8, %o1
F0064130: 7fffdc77                 call    _ipc_port_alloc_special
F0064134: a0100009                 mov     %o1, %l0
F0064138: a6100008                 mov     %o0, %l3
F006413C: d0040000                 ld      [%l0], %o0
F0064140: 80a22000                 cmp     %o0, 0
F0064144: 12bffffe                 bne     loc_F006413C
F0064148: 01000000                 nop
F006414C: 4000cb57                 call    _simple_lock_try
F0064150: 90100010                 mov     %l0, %o0
F0064154: 80a22000                 cmp     %o0, 0
F0064158: 02bffff9                 be      loc_F006413C
F006415C: 80a4e000                 cmp     %l3, 0
F0064160: 02800006                 be      loc_F0064178
F0064164: 113c043e                 sethi   -0xFEF0800, %o0
F0064168: d005a0c0                 ld      [%l6+0xC0], %o0
F006416C: 80a22000                 cmp     %o0, 0
F0064170: 02800004                 be      loc_F0064180
F0064174: 113c043e                 sethi   -0xFEF0800, %o0! char *
F0064178: 7ffec3fe                 call    _panic
F006417C: 901220e8                 bset    0xE8, %o0
F0064180: e625a0c0                 st      %l3, [%l6+0xC0]
F0064184: d004c000                 ld      [%l3], %o0
F0064188: 80a22000                 cmp     %o0, 0
F006418C: 12bffffe                 bne     loc_F0064184
F0064190: 01000000                 nop
F0064194: 4000cb45                 call    _simple_lock_try
F0064198: 90100013                 mov     %l3, %o0
F006419C: 80a22000                 cmp     %o0, 0
F00641A0: 02bffff9                 be      loc_F0064184
F00641A4: aa04e040                 add     %l3, 0x40, %l5 ! '@'
F00641A8: c025a0a8                 clr     [%l6+0xA8]
F00641AC: d004e020                 ld      [%l3+0x20], %o0
F00641B0: 90022001                 inc     %o0
F00641B4: d024e020                 st      %o0, [%l3+0x20]
F00641B8: d004e004                 ld      [%l3+4], %o0
F00641BC: 90022002                 inc     2, %o0
F00641C0: d024e004                 st      %o0, [%l3+4]
F00641C4: e625a0c4                 st      %l3, [%l6+0xC4]
F00641C8: d0054000                 ld      [%l5], %o0
F00641CC: 80a22000                 cmp     %o0, 0
F00641D0: 12bffffe                 bne     loc_F00641C8
F00641D4: 01000000                 nop
F00641D8: 4000cb34                 call    _simple_lock_try
F00641DC: 90100015                 mov     %l5, %o0
F00641E0: 80a22000                 cmp     %o0, 0
F00641E4: 02bffff9                 be      loc_F00641C8
F00641E8: 01000000                 nop
F00641EC: c024c000                 clr     [%l3]
F00641F0: 4000cb2e                 call    _simple_lock_try
F00641F4: 90100018                 mov     %i0, %o0
F00641F8: 80a22000                 cmp     %o0, 0
F00641FC: 32800005                 bne,a   loc_F0064210
F0064200: d0062008                 ld      [%i0+8], %o0
F0064204: c0254000                 clr     [%l5]
F0064208: 10800132                 ba      loc_F00646D0
F006420C: 11200004                 sethi   -0x7FFFF000, %o0
F0064210: 80a22000                 cmp     %o0, 0
F0064214: 16800011                 bge     loc_F0064258
F0064218: 133c04ef                 sethi   %hi(_ipc_space_kernel), %o1
F006421C: d006200c                 ld      [%i0+0xC], %o0
F0064220: d2026330                 ld      [%o1+%lo(_ipc_space_kernel)], %o1
F0064224: 80a20009                 cmp     %o0, %o1
F0064228: 0280000c                 be      loc_F0064258
F006422C: 01000000                 nop
F0064230: d0062030                 ld      [%i0+0x30], %o0
F0064234: 80a22000                 cmp     %o0, 0
F0064238: 12800003                 bne     loc_F0064244
F006423C: a0022010                 add     %o0, 0x10, %l0
F0064240: a0062040                 add     %i0, 0x40, %l0 ! '@'
F0064244: 4000cb19                 call    _simple_lock_try
F0064248: 90100010                 mov     %l0, %o0
F006424C: 80a22000                 cmp     %o0, 0
F0064250: 12800006                 bne     loc_F0064268
F0064254: 01000000                 nop
F0064258: c0254000                 clr     [%l5]
F006425C: c0260000                 clr     [%i0]
F0064260: 1080011c                 ba      loc_F00646D0
F0064264: 11200004                 sethi   -0x7FFFF000, %o0
F0064268: c0260000                 clr     [%i0]
F006426C: e4042008                 ld      [%l0+8], %l2
F0064270: 80a4a000                 cmp     %l2, 0
F0064274: 0280001f                 be      loc_F00642F0
F0064278: 01000000                 nop
F006427C: d005a038                 ld      [%l6+0x38], %o0
F0064280: 80a22000                 cmp     %o0, 0
F0064284: 0280001b                 be      loc_F00642F0
F0064288: 113c0184                 sethi   %hi(_mach_msg_continue), %o0
F006428C: d204a034                 ld      [%l2+0x34], %o1
F0064290: 90122088                 bset    %lo(_mach_msg_continue), %o0
F0064294: 80a24008                 cmp     %o1, %o0
F0064298: 0280000e                 be      loc_F00642D0
F006429C: 113c017e                 sethi   %hi(_mach_msg_receive_continue), %o0
F00642A0: 90122380                 bset    %lo(_mach_msg_receive_continue), %o0
F00642A4: 80a24008                 cmp     %o1, %o0
F00642A8: 12800012                 bne     loc_F00642F0
F00642AC: 01000000                 nop
F00642B0: d004a09c                 ld      [%l2+0x9C], %o0
F00642B4: 80a2203f                 cmp     %o0, 0x3F ! '?'
F00642B8: 0880000e                 bleu    loc_F00642F0
F00642BC: 01000000                 nop
F00642C0: d004a0c8                 ld      [%l2+0xC8], %o0
F00642C4: 808a2200                 btst    0x200, %o0
F00642C8: 1280000a                 bne     loc_F00642F0
F00642CC: 01000000                 nop
F00642D0: 90100016                 mov     %l6, %o0
F00642D4: 133c0192921260e8         set     _exception_raise_continue, %o1
F00642DC: 40000997                 call    _thread_handoff
F00642E0: 94100012                 mov     %l2, %o2
F00642E4: 80a22000                 cmp     %o0, 0
F00642E8: 32800006                 bne,a   loc_F0064300
F00642EC: d2056008                 ld      [%l5+8], %o1
F00642F0: c0254000                 clr     [%l5]
F00642F4: c0240000                 clr     [%l0]
F00642F8: 108000f6                 ba      loc_F00646D0
F00642FC: 11200004                 sethi   -0x7FFFF000, %o0
F0064300: 80a26000                 cmp     %o1, 0
F0064304: 22800007                 be,a    loc_F0064320
F0064308: ec256008                 st      %l6, [%l5+8]
F006430C: d0026094                 ld      [%o1+0x94], %o0
F0064310: d225a090                 st      %o1, [%l6+0x90]
F0064314: d025a094                 st      %o0, [%l6+0x94]
F0064318: ec226094                 st      %l6, [%o1+0x94]
F006431C: ec222090                 st      %l6, [%o0+0x90]
F0064320: 1104001090122001         set     0x10004001, %o0
F0064328: d025a098                 st      %o0, [%l6+0x98]
F006432C: 90103fff                 mov     -1, %o0
F0064330: d025a09c                 st      %o0, [%l6+0x9C]
F0064334: c0254000                 clr     [%l5]
F0064338: d204a090                 ld      [%l2+0x90], %o1
F006433C: 80a24012                 cmp     %o1, %l2
F0064340: 22800008                 be,a    loc_F0064360
F0064344: c0242008                 clr     [%l0+8]
F0064348: d004a094                 ld      [%l2+0x94], %o0
F006434C: d2242008                 st      %o1, [%l0+8]
F0064350: d0226094                 st      %o0, [%o1+0x94]
F0064354: d2222090                 st      %o1, [%o0+0x90]
F0064358: e424a090                 st      %l2, [%l2+0x90]
F006435C: e424a094                 st      %l2, [%l2+0x94]
F0064360: c0240000                 clr     [%l0]
F0064364: e004a0d8                 ld      [%l2+0xD8], %l0
F0064368: d0040000                 ld      [%l0], %o0
F006436C: 80a22000                 cmp     %o0, 0
F0064370: 12bffffe                 bne     loc_F0064368
F0064374: 01000000                 nop
F0064378: 4000cacc                 call    _simple_lock_try
F006437C: 90100010                 mov     %l0, %o0
F0064380: 80a22000                 cmp     %o0, 0
F0064384: 02bffff9                 be      loc_F0064368
F0064388: 01000000                 nop
F006438C: d0042004                 ld      [%l0+4], %o0
F0064390: 90023fff                 inc     -1, %o0
F0064394: d0242004                 st      %o0, [%l0+4]
F0064398: c0240000                 clr     [%l0]
F006439C: 80a22000                 cmp     %o0, 0
F00643A0: 1280000a                 bne     loc_F00643C8
F00643A4: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F00643A8: d0042008                 ld      [%l0+8], %o0
F00643AC: 92126300                 bset    %lo(_ipc_object_zones), %o1
F00643B0: 912a2001                 sll     %o0, 1, %o0
F00643B4: 91322011                 srl     %o0, 17, %o0
F00643B8: 912a2002                 sll     %o0, 2, %o0
F00643BC: d0020009                 ld      [%o0+%o1], %o0
F00643C0: 40005384                 call    _zfree
F00643C4: 92100010                 mov     %l0, %o1
F00643C8: d204a00c                 ld      [%l2+0xC], %o1
F00643CC: 11200004                 sethi   -0x7FFFF000, %o0
F00643D0: ee026088                 ld      [%o1+0x88], %l7
F00643D4: 90122112                 bset    0x112, %o0
F00643D8: d0246014                 st      %o0, [%l1+0x14]
F00643DC: 90102040                 mov     0x40, %o0 ! '@'
F00643E0: d0246018                 st      %o0, [%l1+0x18]
F00643E4: c0246024                 clr     [%l1+0x24]
F00643E8: 90102960                 mov     0x960, %o0
F00643EC: d0246028                 st      %o0, [%l1+0x28]
F00643F0: 133c043e                 sethi   %hi(_exc_port_proto), %o1
F00643F4: d00260cc                 ld      [%o1+%lo(_exc_port_proto)], %o0
F00643F8: d024602c                 st      %o0, [%l1+0x2C]
F00643FC: d00260cc                 ld      [%o1+%lo(_exc_port_proto)], %o0
F0064400: d0246034                 st      %o0, [%l1+0x34]
F0064404: 133c043e                 sethi   %hi(_exc_code_proto), %o1
F0064408: d00260d0                 ld      [%o1+%lo(_exc_code_proto)], %o0
F006440C: d024603c                 st      %o0, [%l1+0x3C]
F0064410: f6246040                 st      %i3, [%l1+0x40]
F0064414: d00260d0                 ld      [%o1+%lo(_exc_code_proto)], %o0
F0064418: d0246044                 st      %o0, [%l1+0x44]
F006441C: f8246048                 st      %i4, [%l1+0x48]
F0064420: d00260d0                 ld      [%o1+%lo(_exc_code_proto)], %o0
F0064424: d024604c                 st      %o0, [%l1+0x4C]
F0064428: fa246050                 st      %i5, [%l1+0x50]
F006442C: d004a0cc                 ld      [%l2+0xCC], %o0
F0064430: 80a2203f                 cmp     %o0, 0x3F ! '?'
F0064434: 1880000e                 bgu     loc_F006446C
F0064438: a8046014                 add     %l1, 0x14, %l4
F006443C: 1120000490122211         set     -0x7FFFEDEF, %o0
F0064444: d0246014                 st      %o0, [%l1+0x14]
F0064448: f024601c                 st      %i0, [%l1+0x1C]
F006444C: e6246020                 st      %l3, [%l1+0x20]
F0064450: f2246030                 st      %i1, [%l1+0x30]
F0064454: f4246038                 st      %i2, [%l1+0x38]
F0064458: 7fffc274                 call    _ipc_kmsg_destroy
F006445C: 90100011                 mov     %l1, %o0
F0064460: 11040010                 sethi   0x10004000, %o0
F0064464: 4000deea                 call    _thread_syscall_return
F0064468: 90122004                 bset    4, %o0
F006446C: a005e008                 add     %l7, 8, %l0
F0064470: d0040000                 ld      [%l0], %o0
F0064474: 80a22000                 cmp     %o0, 0
F0064478: 12bffffe                 bne     loc_F0064470
F006447C: 01000000                 nop
F0064480: 4000ca8a                 call    _simple_lock_try
F0064484: 90100010                 mov     %l0, %o0
F0064488: 80a22000                 cmp     %o0, 0
F006448C: 02bffff9                 be      loc_F0064470
F0064490: 01000000                 nop
F0064494: d0060000                 ld      [%i0], %o0
F0064498: 80a22000                 cmp     %o0, 0
F006449C: 12bffffe                 bne     loc_F0064494
F00644A0: 01000000                 nop
F00644A4: 4000ca81                 call    _simple_lock_try
F00644A8: 90100018                 mov     %i0, %o0
F00644AC: 80a22000                 cmp     %o0, 0
F00644B0: 02bffff9                 be      loc_F0064494
F00644B4: 01000000                 nop
F00644B8: d0062008                 ld      [%i0+8], %o0
F00644BC: 80a22000                 cmp     %o0, 0
F00644C0: 16800007                 bge     loc_F00644DC
F00644C4: 01000000                 nop
F00644C8: 4000ca78                 call    _simple_lock_try
F00644CC: 90100013                 mov     %l3, %o0
F00644D0: 80a22000                 cmp     %o0, 0
F00644D4: 3280001b                 bne,a   loc_F0064540
F00644D8: d004e008                 ld      [%l3+8], %o0
F00644DC: c0260000                 clr     [%i0]
F00644E0: c025e008                 clr     [%l7+8]
F00644E4: 1120000490122211         set     -0x7FFFEDEF, %o0
F00644EC: d0250000                 st      %o0, [%l4]
F00644F0: f0252008                 st      %i0, [%l4+8]
F00644F4: e625200c                 st      %l3, [%l4+0xC]
F00644F8: 90100014                 mov     %l4, %o0
F00644FC: 92100017                 mov     %l7, %o1
F0064500: 7fffc7c4                 call    _ipc_kmsg_copyout_header
F0064504: 94102000                 mov     0, %o2
F0064508: a0920000                 orcc    %o0, %g0, %l0
F006450C: 02800043                 be      loc_F0064618
F0064510: 90100011                 mov     %l1, %o0
F0064514: f225201c                 st      %i1, [%l4+0x1C]
F0064518: f4252024                 st      %i2, [%l4+0x24]
F006451C: 7fffcb02                 call    _ipc_kmsg_copyout_dest
F0064520: 92100017                 mov     %l7, %o1
F0064524: d004a0c4                 ld      [%l2+0xC4], %o0
F0064528: 92100011                 mov     %l1, %o1
F006452C: 7fffc39d                 call    _ipc_kmsg_put
F0064530: 94102018                 mov     0x18, %o2
F0064534: 4000deb6                 call    _thread_syscall_return
F0064538: 90100010                 mov     %l0, %o0
F006453C: d004e008                 ld      [%l3+8], %o0
F0064540: 80a22000                 cmp     %o0, 0
F0064544: 06800004                 bl      loc_F0064554
F0064548: 01000000                 nop
F006454C: c024c000                 clr     [%l3]
F0064550: 30bfffe3                 ba,a    loc_F00644DC
F0064554: c024c000                 clr     [%l3]
F0064558: da05e014                 ld      [%l7+0x14], %o5
F006455C: d2036008                 ld      [%o5+8], %o1
F0064560: 80a26000                 cmp     %o1, 0
F0064564: 02bfffde                 be      loc_F00644DC
F0064568: 972a6004                 sll     %o1, 4, %o3
F006456C: 9803400b                 add     %o5, %o3, %o4
F0064570: d0032008                 ld      [%o4+8], %o0
F0064574: d0236008                 st      %o0, [%o5+8]
F0064578: c0232008                 clr     [%o4+8]
F006457C: d403400b                 ld      [%o5+%o3], %o2
F0064580: 11004000                 sethi   0x1000000, %o0
F0064584: 94028008                 add     %o2, %o0, %o2
F0064588: 912a6008                 sll     %o1, 8, %o0
F006458C: 9332a018                 srl     %o2, 24, %o1
F0064590: 90120009                 bset    %o1, %o0
F0064594: d0252008                 st      %o0, [%l4+8]
F0064598: 1100010090122001         set     0x40001, %o0
F00645A0: 94128008                 bset    %o0, %o2
F00645A4: d423400b                 st      %o2, [%o5+%o3]
F00645A8: e6232004                 st      %l3, [%o4+4]
F00645AC: c025e008                 clr     [%l7+8]
F00645B0: d0062004                 ld      [%i0+4], %o0
F00645B4: 90023fff                 inc     -1, %o0
F00645B8: d0262004                 st      %o0, [%i0+4]
F00645BC: d006200c                 ld      [%i0+0xC], %o0
F00645C0: 80a20017                 cmp     %o0, %l7
F00645C4: 12800003                 bne     loc_F00645D0
F00645C8: 90102000                 mov     0, %o0
F00645CC: d0062010                 ld      [%i0+0x10], %o0
F00645D0: d025200c                 st      %o0, [%l4+0xC]
F00645D4: d006201c                 ld      [%i0+0x1C], %o0
F00645D8: 90023fff                 inc     -1, %o0
F00645DC: 80a22000                 cmp     %o0, 0
F00645E0: 1280000d                 bne     loc_F0064614
F00645E4: d026201c                 st      %o0, [%i0+0x1C]
F00645E8: d0062024                 ld      [%i0+0x24], %o0
F00645EC: 80a22000                 cmp     %o0, 0
F00645F0: 02800009                 be      loc_F0064614
F00645F4: 01000000                 nop
F00645F8: c0262024                 clr     [%i0+0x24]
F00645FC: d2062018                 ld      [%i0+0x18], %o1
F0064600: c0260000                 clr     [%i0]
F0064604: 7fffd300                 call    _ipc_notify_no_senders
F0064608: 01000000                 nop
F006460C: 10800004                 ba      loc_F006461C
F0064610: 90100017                 mov     %l7, %o0
F0064614: c0260000                 clr     [%i0]
F0064618: 90100017                 mov     %l7, %o0
F006461C: 92100019                 mov     %i1, %o1
F0064620: 94102011                 mov     0x11, %o2
F0064624: 7fffc99b                 call    _ipc_kmsg_copyout_object
F0064628: 9605201c                 add     %l4, 0x1C, %o3
F006462C: a0100008                 mov     %o0, %l0
F0064630: 90100017                 mov     %l7, %o0
F0064634: 9210001a                 mov     %i2, %o1
F0064638: 94102011                 mov     0x11, %o2
F006463C: 7fffc995                 call    _ipc_kmsg_copyout_object
F0064640: 96052024                 add     %l4, 0x24, %o3 ! '$'
F0064644: a0940008                 orcc    %l0, %o0, %l0
F0064648: 2280000b                 be,a    loc_F0064674
F006464C: c0246010                 clr     [%l1+0x10]
F0064650: d004a0c4                 ld      [%l2+0xC4], %o0
F0064654: d4046018                 ld      [%l1+0x18], %o2
F0064658: 7fffc352                 call    _ipc_kmsg_put
F006465C: 92100011                 mov     %l1, %o1
F0064660: 110400109012200c         set     0x1000400C, %o0
F0064668: 4000de69                 call    _thread_syscall_return
F006466C: 90140008                 bset    %l0, %o0
F0064670: c0246010                 clr     [%l1+0x10]
F0064674: 90046014                 add     %l1, 0x14, %o0
F0064678: d204a0c4                 ld      [%l2+0xC4], %o1
F006467C: 4000ceaa                 call    _copyoutmsg
F0064680: 94102040                 mov     0x40, %o2 ! '@'
F0064684: 80a22000                 cmp     %o0, 0
F0064688: 32800008                 bne,a   loc_F00646A8
F006468C: d004a0c4                 ld      [%l2+0xC4], %o0
F0064690: 113c04ef                 sethi   %hi(_ipc_kmsg_cache), %o0
F0064694: d0022348                 ld      [%o0+%lo(_ipc_kmsg_cache)], %o0
F0064698: 80a22000                 cmp     %o0, 0
F006469C: 22800009                 be,a    loc_F00646C0
F00646A0: 113c04ef                 sethi   -0xFEC4400, %o0
F00646A4: d004a0c4                 ld      [%l2+0xC4], %o0
F00646A8: d4046018                 ld      [%l1+0x18], %o2
F00646AC: 7fffc33d                 call    _ipc_kmsg_put
F00646B0: 92100011                 mov     %l1, %o1
F00646B4: 4000de56                 call    _thread_syscall_return
F00646B8: 01000000                 nop
F00646BC: 113c04ef                 sethi   -0xFEC4400, %o0
F00646C0: e2222348                 st      %l1, [%o0+0x348]
F00646C4: 4000de52                 call    _thread_syscall_return
F00646C8: 90102000                 mov     0, %o0
F00646CC: 11200004                 sethi   -0x7FFFF000, %o0
F00646D0: 90122211                 bset    0x211, %o0
F00646D4: d0246014                 st      %o0, [%l1+0x14]
F00646D8: 90102040                 mov     0x40, %o0 ! '@'
F00646DC: d0246018                 st      %o0, [%l1+0x18]
F00646E0: f024601c                 st      %i0, [%l1+0x1C]
F00646E4: e6246020                 st      %l3, [%l1+0x20]
F00646E8: c0246024                 clr     [%l1+0x24]
F00646EC: 90102960                 mov     0x960, %o0
F00646F0: d0246028                 st      %o0, [%l1+0x28]
F00646F4: 133c043e                 sethi   %hi(_exc_port_proto), %o1
F00646F8: d00260cc                 ld      [%o1+%lo(_exc_port_proto)], %o0
F00646FC: d024602c                 st      %o0, [%l1+0x2C]
F0064700: f2246030                 st      %i1, [%l1+0x30]
F0064704: d00260cc                 ld      [%o1+%lo(_exc_port_proto)], %o0
F0064708: d0246034                 st      %o0, [%l1+0x34]
F006470C: f4246038                 st      %i2, [%l1+0x38]
F0064710: 133c043e                 sethi   %hi(_exc_code_proto), %o1
F0064714: d00260d0                 ld      [%o1+%lo(_exc_code_proto)], %o0
F0064718: d024603c                 st      %o0, [%l1+0x3C]
F006471C: f6246040                 st      %i3, [%l1+0x40]
F0064720: d00260d0                 ld      [%o1+%lo(_exc_code_proto)], %o0
F0064724: 153c043e                 sethi   %hi(_exception_raise_misses), %o2
F0064728: d0246044                 st      %o0, [%l1+0x44]
F006472C: d002a0d4                 ld      [%o2+%lo(_exception_raise_misses)], %o0
F0064730: f8246048                 st      %i4, [%l1+0x48]
F0064734: d20260d0                 ld      [%o1+%lo(_exc_code_proto)], %o1
F0064738: 90022001                 inc     %o0
F006473C: d022a0d4                 st      %o0, [%o2+%lo(_exception_raise_misses)]
F0064740: d224604c                 st      %o1, [%l1+0x4C]
F0064744: fa246050                 st      %i5, [%l1+0x50]
F0064748: 90100011                 mov     %l1, %o0
F006474C: 13000040                 sethi   0x10000, %o1
F0064750: 94102000                 mov     0, %o2
F0064754: 7fffcf4a                 call    _ipc_mqueue_send
F0064758: 96102000                 mov     0, %o3
F006475C: d004c000                 ld      [%l3], %o0
F0064760: 80a22000                 cmp     %o0, 0
F0064764: 12bffffe                 bne     loc_F006475C
F0064768: 01000000                 nop
F006476C: 4000c9cf                 call    _simple_lock_try
F0064770: 90100013                 mov     %l3, %o0
F0064774: 80a22000                 cmp     %o0, 0
F0064778: 02bffff9                 be      loc_F006475C
F006477C: 01000000                 nop
F0064780: d004e008                 ld      [%l3+8], %o0
F0064784: 80a22000                 cmp     %o0, 0
F0064788: 06800008                 bl      loc_F00647A8
F006478C: 01000000                 nop
F0064790: c024c000                 clr     [%l3]
F0064794: 1104001090122009         set     0x10004009, %o0
F006479C: 92102000                 mov     0, %o1
F00647A0: 1080001f                 ba      loc_F006481C
F00647A4: 94102000                 mov     0, %o2
F00647A8: d0054000                 ld      [%l5], %o0
F00647AC: 80a22000                 cmp     %o0, 0
F00647B0: 12bffffe                 bne     loc_F00647A8
F00647B4: 01000000                 nop
F00647B8: 4000c9bc                 call    _simple_lock_try
F00647BC: 90100015                 mov     %l5, %o0
F00647C0: 80a22000                 cmp     %o0, 0
F00647C4: 02bffff9                 be      loc_F00647A8
F00647C8: 01000000                 nop
F00647CC: c024c000                 clr     [%l3]
F00647D0: d005a038                 ld      [%l6+0x38], %o0
F00647D4: 80a22000                 cmp     %o0, 0
F00647D8: 02800004                 be      loc_F00647E8
F00647DC: 113c0192                 sethi   %hi(_exception_raise_continue), %o0
F00647E0: 10800003                 ba      loc_F00647EC
F00647E4: 9a1220e8                 or      %o0, %lo(_exception_raise_continue), %o5
F00647E8: 9a102000                 mov     0, %o5
F00647EC: 9007bff4                 add     %fp, var_C, %o0
F00647F0: d023a05c                 st      %o0, [%sp+0x78+var_1C]
F00647F4: 9007bff0                 add     %fp, var_10, %o0
F00647F8: d023a060                 st      %o0, [%sp+0x78+var_18]
F00647FC: 90100015                 mov     %l5, %o0
F0064800: 92102000                 mov     0, %o1
F0064804: 94103fff                 mov     -1, %o2
F0064808: 96102000                 mov     0, %o3
F006480C: 7fffd0ab                 call    _ipc_mqueue_receive
F0064810: 98102000                 mov     0, %o4
F0064814: d207bff4                 ld      [%fp+var_C], %o1
F0064818: d407bff0                 ld      [%fp+var_10], %o2
F006481C: 40000048                 call    _exception_raise_continue_slow
F0064820: 01000000                 nop
F0064824: 81c7e008                 ret
F0064828: 81e80000                 restore
