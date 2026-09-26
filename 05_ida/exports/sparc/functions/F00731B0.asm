F00731B0: 9de3bf98                 save    %sp, -0x68, %sp
F00731B4: 80a62000                 cmp     %i0, 0
F00731B8: 12800004                 bne     loc_F00731C8
F00731BC: 113c04d0                 sethi   -0xFECC000, %o0
F00731C0: 108000ef                 ba      locret_F007357C
F00731C4: b0102004                 mov     4, %i0
F00731C8: d0022260                 ld      [%o0+0x260], %o0
F00731CC: a606201c                 add     %i0, 0x1C, %l3
F00731D0: e202200c                 ld      [%o0+0xC], %l1
F00731D4: 80a60011                 cmp     %i0, %l1
F00731D8: 12800044                 bne     loc_F00732E8
F00731DC: a4100008                 mov     %o0, %l2
F00731E0: d0060000                 ld      [%i0], %o0
F00731E4: 80a22000                 cmp     %o0, 0
F00731E8: 12bffffe                 bne     loc_F00731E0
F00731EC: 01000000                 nop
F00731F0: 40008f2e                 call    _simple_lock_try
F00731F4: 90100018                 mov     %i0, %o0
F00731F8: 80a22000                 cmp     %o0, 0
F00731FC: 02bffff9                 be      loc_F00731E0
F0073200: 01000000                 nop
F0073204: d0062008                 ld      [%i0+8], %o0
F0073208: 80a22000                 cmp     %o0, 0
F007320C: 02800083                 be      loc_F0073418
F0073210: 01000000                 nop
F0073214: 40008e5d                 call    _splusclock
F0073218: a0062028                 add     %i0, 0x28, %l0 ! '('
F007321C: a8100008                 mov     %o0, %l4
F0073220: d0040000                 ld      [%l0], %o0
F0073224: 80a22000                 cmp     %o0, 0
F0073228: 12bffffe                 bne     loc_F0073220
F007322C: 01000000                 nop
F0073230: 40008f1e                 call    _simple_lock_try
F0073234: 90100010                 mov     %l0, %o0
F0073238: 80a22000                 cmp     %o0, 0
F007323C: 02bffff9                 be      loc_F0073220
F0073240: 01000000                 nop
F0073244: a004a020                 add     %l2, 0x20, %l0 ! ' '
F0073248: d0040000                 ld      [%l0], %o0
F007324C: 80a22000                 cmp     %o0, 0
F0073250: 12bffffe                 bne     loc_F0073248
F0073254: 01000000                 nop
F0073258: 40008f14                 call    _simple_lock_try
F007325C: 90100010                 mov     %l0, %o0
F0073260: 80a22000                 cmp     %o0, 0
F0073264: 02bffff9                 be      loc_F0073248
F0073268: 01000000                 nop
F007326C: d004a188                 ld      [%l2+0x188], %o0
F0073270: 80a22000                 cmp     %o0, 0
F0073274: 32800008                 bne,a   loc_F0073294
F0073278: c0262008                 clr     [%i0+8]
F007327C: c024a020                 clr     [%l2+0x20]
F0073280: c0262028                 clr     [%i0+0x28]
F0073284: 40008ea8                 call    _splx
F0073288: 90100014                 mov     %l4, %o0
F007328C: c0260000                 clr     [%i0]
F0073290: 30800056                 ba,a    loc_F00733E8
F0073294: d204a010                 ld      [%l2+0x10], %o1
F0073298: 80a4c009                 cmp     %l3, %o1
F007329C: 12800004                 bne     loc_F00732AC
F00732A0: d004a014                 ld      [%l2+0x14], %o0
F00732A4: 10800003                 ba      loc_F00732B0
F00732A8: d024e004                 st      %o0, [%l3+4]
F00732AC: d0226014                 st      %o0, [%o1+0x14]
F00732B0: 80a4c008                 cmp     %l3, %o0
F00732B4: 22800003                 be,a    loc_F00732C0
F00732B8: d224c000                 st      %o1, [%l3]
F00732BC: d2222010                 st      %o1, [%o0+0x10]
F00732C0: c024a020                 clr     [%l2+0x20]
F00732C4: c0262028                 clr     [%i0+0x28]
F00732C8: 40008e97                 call    _splx
F00732CC: 90100014                 mov     %l4, %o0
F00732D0: c0260000                 clr     [%i0]
F00732D4: 7fffcee0                 call    _ipc_thread_disable
F00732D8: 90100012                 mov     %l2, %o0
F00732DC: 7fffcef2                 call    _ipc_thread_terminate
F00732E0: 90100012                 mov     %l2, %o0
F00732E4: 30800051                 ba,a    loc_F0073428
F00732E8: 1a800015                 bcc     loc_F007333C
F00732EC: 01000000                 nop
F00732F0: d0060000                 ld      [%i0], %o0
F00732F4: 80a22000                 cmp     %o0, 0
F00732F8: 12bffffe                 bne     loc_F00732F0
F00732FC: 01000000                 nop
F0073300: 40008eea                 call    _simple_lock_try
F0073304: 90100018                 mov     %i0, %o0
F0073308: 80a22000                 cmp     %o0, 0
F007330C: 02bffff9                 be      loc_F00732F0
F0073310: 01000000                 nop
F0073314: d0044000                 ld      [%l1], %o0
F0073318: 80a22000                 cmp     %o0, 0
F007331C: 12bffffe                 bne     loc_F0073314
F0073320: 01000000                 nop
F0073324: 40008ee1                 call    _simple_lock_try
F0073328: 90100011                 mov     %l1, %o0
F007332C: 80a22000                 cmp     %o0, 0
F0073330: 02bffff9                 be      loc_F0073314
F0073334: 01000000                 nop
F0073338: 30800013                 ba,a    loc_F0073384
F007333C: d0044000                 ld      [%l1], %o0
F0073340: 80a22000                 cmp     %o0, 0
F0073344: 12bffffe                 bne     loc_F007333C
F0073348: 01000000                 nop
F007334C: 40008ed7                 call    _simple_lock_try
F0073350: 90100011                 mov     %l1, %o0
F0073354: 80a22000                 cmp     %o0, 0
F0073358: 02bffff9                 be      loc_F007333C
F007335C: 01000000                 nop
F0073360: d0060000                 ld      [%i0], %o0
F0073364: 80a22000                 cmp     %o0, 0
F0073368: 12bffffe                 bne     loc_F0073360
F007336C: 01000000                 nop
F0073370: 40008ece                 call    _simple_lock_try
F0073374: 90100018                 mov     %i0, %o0
F0073378: 80a22000                 cmp     %o0, 0
F007337C: 02bffff9                 be      loc_F0073360
F0073380: 01000000                 nop
F0073384: 40008e01                 call    _splusclock
F0073388: a004a020                 add     %l2, 0x20, %l0 ! ' '
F007338C: a8100008                 mov     %o0, %l4
F0073390: d0040000                 ld      [%l0], %o0
F0073394: 80a22000                 cmp     %o0, 0
F0073398: 12bffffe                 bne     loc_F0073390
F007339C: 01000000                 nop
F00733A0: 40008ec2                 call    _simple_lock_try
F00733A4: 90100010                 mov     %l0, %o0
F00733A8: 80a22000                 cmp     %o0, 0
F00733AC: 02bffff9                 be      loc_F0073390
F00733B0: 01000000                 nop
F00733B4: d0046008                 ld      [%l1+8], %o0
F00733B8: 80a22000                 cmp     %o0, 0
F00733BC: 02800006                 be      loc_F00733D4
F00733C0: 01000000                 nop
F00733C4: d004a188                 ld      [%l2+0x188], %o0
F00733C8: 80a22000                 cmp     %o0, 0
F00733CC: 1280000b                 bne     loc_F00733F8
F00733D0: 01000000                 nop
F00733D4: c024a020                 clr     [%l2+0x20]
F00733D8: 40008e53                 call    _splx
F00733DC: 90100014                 mov     %l4, %o0! target_act
F00733E0: c0260000                 clr     [%i0]
F00733E4: c0244000                 clr     [%l1]
F00733E8: 4000052b                 call    _thread_terminate
F00733EC: 90100012                 mov     %l2, %o0
F00733F0: 10800063                 ba      locret_F007357C
F00733F4: b0102005                 mov     5, %i0
F00733F8: c024a020                 clr     [%l2+0x20]
F00733FC: 40008e4a                 call    _splx
F0073400: 90100014                 mov     %l4, %o0
F0073404: c0244000                 clr     [%l1]
F0073408: d0062008                 ld      [%i0+8], %o0
F007340C: 80a22000                 cmp     %o0, 0
F0073410: 32800005                 bne,a   loc_F0073424
F0073414: c0262008                 clr     [%i0+8]
F0073418: c0260000                 clr     [%i0]
F007341C: 10800058                 ba      locret_F007357C
F0073420: b0102005                 mov     5, %i0
F0073424: c0260000                 clr     [%i0]
F0073428: 7fffcdf9                 call    _ipc_task_disable
F007342C: 90100018                 mov     %i0, %o0
F0073430: 40000055                 call    _task_hold
F0073434: 90100018                 mov     %i0, %o0
F0073438: 90100018                 mov     %i0, %o0
F007343C: 40000078                 call    _task_dowait
F0073440: 92102001                 mov     1, %o1
F0073444: d0060000                 ld      [%i0], %o0
F0073448: 80a22000                 cmp     %o0, 0
F007344C: 12bffffe                 bne     loc_F0073444
F0073450: 01000000                 nop
F0073454: 40008e95                 call    _simple_lock_try
F0073458: 90100018                 mov     %i0, %o0
F007345C: 80a22000                 cmp     %o0, 0
F0073460: 02bffff9                 be      loc_F0073444
F0073464: 01000000                 nop
F0073468: 10800015                 ba      loc_F00734BC
F007346C: d004c000                 ld      [%l3], %o0
F0073470: 400004f1                 call    _thread_reference
F0073474: 90100010                 mov     %l0, %o0
F0073478: c0260000                 clr     [%i0]
F007347C: 40000593                 call    _thread_force_terminate
F0073480: 90100010                 mov     %l0, %o0
F0073484: 400003ca                 call    _thread_deallocate
F0073488: 90100010                 mov     %l0, %o0
F007348C: 7ffff8ad                 call    _thread_block_with_continuation
F0073490: 90102000                 mov     0, %o0
F0073494: d0060000                 ld      [%i0], %o0
F0073498: 80a22000                 cmp     %o0, 0
F007349C: 12bffffe                 bne     loc_F0073494
F00734A0: 01000000                 nop
F00734A4: 40008e81                 call    _simple_lock_try
F00734A8: 90100018                 mov     %i0, %o0
F00734AC: 80a22000                 cmp     %o0, 0
F00734B0: 02bffff9                 be      loc_F0073494
F00734B4: 01000000                 nop
F00734B8: d004c000                 ld      [%l3], %o0
F00734BC: 80a4c008                 cmp     %l3, %o0
F00734C0: 32bfffec                 bne,a   loc_F0073470
F00734C4: e004c000                 ld      [%l3], %l0
F00734C8: c0260000                 clr     [%i0]
F00734CC: 7fffcde4                 call    _ipc_task_terminate
F00734D0: 90100018                 mov     %i0, %o0
F00734D4: 7ffffef5                 call    _task_deallocate
F00734D8: 90100018                 mov     %i0, %o0
F00734DC: d004a00c                 ld      [%l2+0xC], %o0
F00734E0: 80a20018                 cmp     %o0, %i0
F00734E4: 32800026                 bne,a   locret_F007357C
F00734E8: b0102000                 mov     0, %i0
F00734EC: d0060000                 ld      [%i0], %o0
F00734F0: 80a22000                 cmp     %o0, 0
F00734F4: 12bffffe                 bne     loc_F00734EC
F00734F8: 01000000                 nop
F00734FC: 40008e6b                 call    _simple_lock_try
F0073500: 90100018                 mov     %i0, %o0
F0073504: 80a22000                 cmp     %o0, 0
F0073508: 02bffff9                 be      loc_F00734EC
F007350C: 01000000                 nop
F0073510: 40008d9e                 call    _splusclock
F0073514: a0062028                 add     %i0, 0x28, %l0 ! '('
F0073518: a8100008                 mov     %o0, %l4
F007351C: d0040000                 ld      [%l0], %o0
F0073520: 80a22000                 cmp     %o0, 0
F0073524: 12bffffe                 bne     loc_F007351C
F0073528: 01000000                 nop
F007352C: 40008e5f                 call    _simple_lock_try
F0073530: 90100010                 mov     %l0, %o0
F0073534: 80a22000                 cmp     %o0, 0
F0073538: 02bffff9                 be      loc_F007351C
F007353C: 01000000                 nop
F0073540: d004e004                 ld      [%l3+4], %o0
F0073544: 80a4c008                 cmp     %l3, %o0
F0073548: 32800003                 bne,a   loc_F0073554
F007354C: e4222010                 st      %l2, [%o0+0x10]
F0073550: e424c000                 st      %l2, [%l3]
F0073554: d024a014                 st      %o0, [%l2+0x14]
F0073558: e624a010                 st      %l3, [%l2+0x10]
F007355C: e424e004                 st      %l2, [%l3+4]
F0073560: c0262028                 clr     [%i0+0x28]
F0073564: 40008df0                 call    _splx
F0073568: 90100014                 mov     %l4, %o0! target_act
F007356C: c0260000                 clr     [%i0]
F0073570: 400004c9                 call    _thread_terminate
F0073574: 90100012                 mov     %l2, %o0
F0073578: b0102000                 mov     0, %i0
F007357C: 81c7e008                 ret
F0073580: 81e80000                 restore
