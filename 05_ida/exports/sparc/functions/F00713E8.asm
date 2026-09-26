F00713E8: 9de3bf98                 save    %sp, -0x68, %sp
F00713EC: 80a6001a                 cmp     %i0, %i2
F00713F0: 12800017                 bne     loc_F007144C
F00713F4: a006a020                 add     %i2, 0x20, %l0 ! ' '
F00713F8: b0062020                 inc     0x20, %i0 ! ' '
F00713FC: d0060000                 ld      [%i0], %o0
F0071400: 80a22000                 cmp     %o0, 0
F0071404: 12bffffe                 bne     loc_F00713FC
F0071408: 01000000                 nop
F007140C: 400096a7                 call    _simple_lock_try
F0071410: 90100018                 mov     %i0, %o0
F0071414: 80a22000                 cmp     %o0, 0
F0071418: 02bffff9                 be      loc_F00713FC
F007141C: 01000000                 nop
F0071420: c026a020                 clr     [%i2+0x20]
F0071424: d006a04c                 ld      [%i2+0x4C], %o0
F0071428: 80a66000                 cmp     %i1, 0
F007142C: 900a3ff7                 and     %o0, -9, %o0
F0071430: 028000b3                 be      loc_F00716FC
F0071434: d026a04c                 st      %o0, [%i2+0x4C]
F0071438: 4000962a                 call    _spl0
F007143C: b0102001                 mov     1, %i0
F0071440: 40008da9                 call    _call_continuation
F0071444: 90100019                 mov     %i1, %o0
F0071448: 308000ae                 ba,a    locret_F0071700
F007144C: d0040000                 ld      [%l0], %o0
F0071450: 80a22000                 cmp     %o0, 0
F0071454: 12bffffe                 bne     loc_F007144C
F0071458: 01000000                 nop
F007145C: 40009693                 call    _simple_lock_try
F0071460: 90100010                 mov     %l0, %o0
F0071464: 80a22000                 cmp     %o0, 0
F0071468: 02bffff9                 be      loc_F007144C
F007146C: 133c04f0                 sethi   %hi(_active_stacks), %o1
F0071470: d0062030                 ld      [%i0+0x30], %o0
F0071474: d2026058                 ld      [%o1+%lo(_active_stacks)], %o1
F0071478: 80a20009                 cmp     %o0, %o1
F007147C: 02800074                 be      loc_F007164C
F0071480: 80a66000                 cmp     %i1, 0
F0071484: 02800073                 be      loc_F0071650
F0071488: d006a04c                 ld      [%i2+0x4C], %o0
F007148C: 920a2300                 and     %o0, 0x300, %o1
F0071490: 80a26100                 cmp     %o1, 0x100
F0071494: 22800007                 be,a    loc_F00714B0
F0071498: 900a3ef7                 and     %o0, -0x109, %o0
F007149C: 04800082                 ble     loc_F00716A4
F00714A0: 80a26200                 cmp     %o1, 0x200
F00714A4: 02800076                 be      loc_F007167C
F00714A8: 01000000                 nop
F00714AC: 3080007e                 ba,a    loc_F00716A4
F00714B0: d026a04c                 st      %o0, [%i2+0x4C]
F00714B4: c026a020                 clr     [%i2+0x20]
F00714B8: 133c04cf                 sethi   %hi(_need_ast), %o1
F00714BC: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F00714C0: d406a18c                 ld      [%i2+0x18C], %o2
F00714C4: 900a3ffc                 and     %o0, -4, %o0
F00714C8: 9012000a                 bset    %o2, %o0
F00714CC: d0226160                 st      %o0, [%o1+%lo(_need_ast)]
F00714D0: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F00714D4: 7ffe724c                 call    _switch_unix_context
F00714D8: 9010001a                 mov     %i2, %o0
F00714DC: 90100018                 mov     %i0, %o0
F00714E0: 4000aa71                 call    _stack_handoff
F00714E4: 9210001a                 mov     %i2, %o1
F00714E8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00714EC: d0040000                 ld      [%l0], %o0
F00714F0: 80a22000                 cmp     %o0, 0
F00714F4: 12bffffe                 bne     loc_F00714EC
F00714F8: 01000000                 nop
F00714FC: 4000966b                 call    _simple_lock_try
F0071500: 90100010                 mov     %l0, %o0
F0071504: 80a22000                 cmp     %o0, 0
F0071508: 02bffff9                 be      loc_F00714EC
F007150C: 01000000                 nop
F0071510: d006204c                 ld      [%i0+0x4C], %o0
F0071514: 80a2200c                 cmp     %o0, 0xC
F0071518: 02800033                 be      loc_F00715E4
F007151C: f2262034                 st      %i1, [%i0+0x34]
F0071520: 80a2200c                 cmp     %o0, 0xC
F0071524: 14800010                 bg      loc_F0071564
F0071528: 80a2200f                 cmp     %o0, 0xF
F007152C: 80a22005                 cmp     %o0, 5
F0071530: 22800035                 be,a    loc_F0071604
F0071534: d006204c                 ld      [%i0+0x4C], %o0
F0071538: 14800007                 bg      loc_F0071554
F007153C: 80a22007                 cmp     %o0, 7
F0071540: 80a22004                 cmp     %o0, 4
F0071544: 02800029                 be      loc_F00715E8
F0071548: 90100018                 mov     %i0, %o0
F007154C: 10800034                 ba      loc_F007161C
F0071550: 113c0441                 sethi   -0xFEEFC00, %o0
F0071554: 14800032                 bg      loc_F007161C
F0071558: 113c0441                 sethi   -0xFEEFC00, %o0
F007155C: 10800014                 ba      loc_F00715AC
F0071560: d006204c                 ld      [%i0+0x4C], %o0
F0071564: 02800027                 be      loc_F0071600
F0071568: 80a2200f                 cmp     %o0, 0xF
F007156C: 14800009                 bg      loc_F0071590
F0071570: 80a22016                 cmp     %o0, 0x16
F0071574: 80a2200d                 cmp     %o0, 0xD
F0071578: 02800022                 be      loc_F0071600
F007157C: 80a2200e                 cmp     %o0, 0xE
F0071580: 0280001a                 be      loc_F00715E8
F0071584: 90100018                 mov     %i0, %o0
F0071588: 10800025                 ba      loc_F007161C
F007158C: 113c0441                 sethi   -0xFEEFC00, %o0
F0071590: 02800006                 be      loc_F00715A8
F0071594: 80a22084                 cmp     %o0, 0x84
F0071598: 0280001f                 be      loc_F0071614
F007159C: 90102184                 mov     0x184, %o0
F00715A0: 1080001f                 ba      loc_F007161C
F00715A4: 113c0441                 sethi   -0xFEEFC00, %o0
F00715A8: d006204c                 ld      [%i0+0x4C], %o0
F00715AC: d2062048                 ld      [%i0+0x48], %o1
F00715B0: 900a3ffb                 and     %o0, -5, %o0
F00715B4: 90122100                 bset    0x100, %o0
F00715B8: 80a26000                 cmp     %o1, 0
F00715BC: 0280001a                 be      loc_F0071624
F00715C0: d026204c                 st      %o0, [%i0+0x4C]
F00715C4: c0262048                 clr     [%i0+0x48]
F00715C8: c0262020                 clr     [%i0+0x20]
F00715CC: 90062048                 add     %i0, 0x48, %o0 ! 'H'
F00715D0: 92102000                 mov     0, %o1
F00715D4: 7ffffe8a                 call    _thread_wakeup_prim
F00715D8: 94102000                 mov     0, %o2
F00715DC: 10800014                 ba      loc_F007162C
F00715E0: 133c043e                 sethi   -0xFEF0800, %o1
F00715E4: 90100018                 mov     %i0, %o0
F00715E8: d406204c                 ld      [%i0+0x4C], %o2
F00715EC: 92102000                 mov     0, %o1
F00715F0: 9412a100                 bset    0x100, %o2
F00715F4: 400001ab                 call    _thread_setrun
F00715F8: d426204c                 st      %o2, [%i0+0x4C]
F00715FC: 3080000a                 ba,a    loc_F0071624
F0071600: d006204c                 ld      [%i0+0x4C], %o0
F0071604: 900a3ffb                 and     %o0, -5, %o0
F0071608: 90122100                 bset    0x100, %o0! char *
F007160C: 10800006                 ba      loc_F0071624
F0071610: d026204c                 st      %o0, [%i0+0x4C]
F0071614: 10800004                 ba      loc_F0071624
F0071618: d026204c                 st      %o0, [%i0+0x4C]
F007161C: 7ffe8ed5                 call    _panic
F0071620: 90122018                 bset    0x18, %o0
F0071624: c0262020                 clr     [%i0+0x20]
F0071628: 133c043e                 sethi   -0xFEF0800, %o1
F007162C: d00260a8                 ld      [%o1+0xA8], %o0
F0071630: 90022001                 inc     %o0
F0071634: 400095ab                 call    _spl0
F0071638: d02260a8                 st      %o0, [%o1+0xA8]
F007163C: 40008d2a                 call    _call_continuation
F0071640: d006a034                 ld      [%i2+0x34], %o0
F0071644: 1080002f                 ba      locret_F0071700
F0071648: b0102001                 mov     1, %i0
F007164C: d006a04c                 ld      [%i2+0x4C], %o0
F0071650: 808a2100                 btst    0x100, %o0
F0071654: 02800013                 be      loc_F00716A0
F0071658: 808a2200                 btst    0x200, %o0
F007165C: 12800008                 bne     loc_F007167C
F0071660: 9010001a                 mov     %i2, %o0
F0071664: 133c01c5                 sethi   %hi(_thread_continue), %o1
F0071668: 7fffdd1f                 call    _stack_alloc_try
F007166C: 92126308                 bset    %lo(_thread_continue), %o1
F0071670: 80a22000                 cmp     %o0, 0
F0071674: 3280000c                 bne,a   loc_F00716A4
F0071678: d006a04c                 ld      [%i2+0x4C], %o0
F007167C: 40001377                 call    _thread_swapin
F0071680: 9010001a                 mov     %i2, %o0
F0071684: c026a020                 clr     [%i2+0x20]
F0071688: 133c043e                 sethi   %hi(_c_thread_invoke_misses), %o1
F007168C: d00260ac                 ld      [%o1+%lo(_c_thread_invoke_misses)], %o0
F0071690: b0102000                 mov     0, %i0
F0071694: 90022001                 inc     %o0
F0071698: 1080001a                 ba      locret_F0071700
F007169C: d02260ac                 st      %o0, [%o1+%lo(_c_thread_invoke_misses)]
F00716A0: d006a04c                 ld      [%i2+0x4C], %o0
F00716A4: c026a020                 clr     [%i2+0x20]
F00716A8: 900a3ef7                 and     %o0, -0x109, %o0
F00716AC: d026a04c                 st      %o0, [%i2+0x4C]
F00716B0: 133c04cf                 sethi   %hi(_need_ast), %o1
F00716B4: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F00716B8: d406a18c                 ld      [%i2+0x18C], %o2
F00716BC: 900a3ffc                 and     %o0, -4, %o0
F00716C0: 9012000a                 bset    %o2, %o0
F00716C4: d0226160                 st      %o0, [%o1+%lo(_need_ast)]
F00716C8: d0026160                 ld      [%o1+%lo(_need_ast)], %o0
F00716CC: 7ffe71ce                 call    _switch_unix_context
F00716D0: 9010001a                 mov     %i2, %o0
F00716D4: 90100018                 mov     %i0, %o0
F00716D8: 92100019                 mov     %i1, %o1
F00716DC: 193c043e                 sethi   %hi(_c_thread_invoke_csw), %o4
F00716E0: d60320b0                 ld      [%o4+%lo(_c_thread_invoke_csw)], %o3
F00716E4: 9410001a                 mov     %i2, %o2
F00716E8: 9602e001                 inc     %o3
F00716EC: 4000aa0f                 call    _switch_context
F00716F0: d62320b0                 st      %o3, [%o4+%lo(_c_thread_invoke_csw)]
F00716F4: 40000042                 call    _thread_dispatch
F00716F8: 01000000                 nop
F00716FC: b0102001                 mov     1, %i0
F0071700: 81c7e008                 ret
F0071704: 81e80000                 restore
