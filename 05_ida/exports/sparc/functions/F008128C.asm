F008128C: 9de3bf40                 save    %sp, -0xC0, %sp
F0081290: f027a044                 st      %i0, [%fp+arg_44]
F0081294: f227bfcc                 st      %i1, [%fp+var_34]
F0081298: f427bfc4                 st      %i2, [%fp+var_3C]
F008129C: f627bfbc                 st      %i3, [%fp+var_44]
F00812A0: 133c04f092126240         set     _vm_stat, %o1
F00812A8: d0026024                 ld      [%o1+0x24], %o0
F00812AC: f827bfb4                 st      %i4, [%fp+var_4C]
F00812B0: 90022001                 inc     %o0
F00812B4: d0226024                 st      %o0, [%o1+0x24]
F00812B8: 9007bfe8                 add     %fp, var_18, %o0
F00812BC: d023a05c                 st      %o0, [%sp+0xC0+var_64]
F00812C0: 9007bfe4                 add     %fp, var_1C, %o0
F00812C4: d023a060                 st      %o0, [%sp+0xC0+var_60]
F00812C8: 9007bfe0                 add     %fp, var_20, %o0
F00812CC: d023a064                 st      %o0, [%sp+0xC0+var_5C]
F00812D0: 9007a044                 add     %fp, arg_44, %o0
F00812D4: 9607bff4                 add     %fp, var_C, %o3
F00812D8: d207bfcc                 ld      [%fp+var_34], %o1
F00812DC: 9807bff0                 add     %fp, var_10, %o4
F00812E0: d407bfc4                 ld      [%fp+var_3C], %o2
F00812E4: 400012bc                 call    _vm_map_lookup
F00812E8: 9a07bfec                 add     %fp, var_14, %o5
F00812EC: b0920000                 orcc    %o0, %g0, %i0
F00812F0: 128006f4                 bne     locret_F0082EC0
F00812F4: d007bfe4                 ld      [%fp+var_1C], %o0
F00812F8: 80a22000                 cmp     %o0, 0
F00812FC: 02800004                 be      loc_F008130C
F0081300: b6102001                 mov     1, %i3
F0081304: c607bfe8                 ld      [%fp+var_18], %g3
F0081308: c627bfc4                 st      %g3, [%fp+var_3C]
F008130C: d007bff0                 ld      [%fp+var_10], %o0
F0081310: a6102000                 mov     0, %l3
F0081314: a0022010                 add     %o0, 0x10, %l0
F0081318: d0040000                 ld      [%l0], %o0
F008131C: 80a22000                 cmp     %o0, 0
F0081320: 12bffffe                 bne     loc_F0081318
F0081324: 01000000                 nop
F0081328: 400056e0                 call    _simple_lock_try
F008132C: 90100010                 mov     %l0, %o0
F0081330: 80a22000                 cmp     %o0, 0
F0081334: 02bffff9                 be      loc_F0081318
F0081338: 111fffff                 sethi   0x7FFFFC00, %o0
F008133C: ac1223ff                 or      %o0, 0x3FF, %l6
F0081340: 2f100000                 sethi   0x40000000, %l7
F0081344: 112fffffb41223ff         set     -0x40000001, %i2
F008134C: 2b3c04f0                 sethi   -0xFEC4000, %l5
F0081350: 113effffb81223ff         set     -0x4000001, %i4
F0081358: 113c04f0b2122240         set     _vm_stat, %i1
F0081360: e807bfec                 ld      [%fp+var_14], %l4
F0081364: 073c04f0                 sethi   %hi(_vm_page_queue_inactive), %g3
F0081368: d007bff0                 ld      [%fp+var_10], %o0
F008136C: ba10e228                 or      %g3, %lo(_vm_page_queue_inactive), %i5
F0081370: d2122018                 lduh    [%o0+0x18], %o1
F0081374: a4100008                 mov     %o0, %l2
F0081378: 92026001                 inc     %o1
F008137C: d014a044                 lduh    [%l2+0x44], %o0
F0081380: d234a018                 sth     %o1, [%l2+0x18]
F0081384: 90022001                 inc     %o0
F0081388: d034a044                 sth     %o0, [%l2+0x44]
F008138C: 90100012                 mov     %l2, %o0
F0081390: 40001f02                 call    _vm_page_lookup
F0081394: 92100014                 mov     %l4, %o1
F0081398: a2920000                 orcc    %o0, %g0, %l1
F008139C: 028001b6                 be      loc_F0081A74
F00813A0: 11008000                 sethi   0x2000000, %o0
F00813A4: d2046020                 ld      [%l1+0x20], %o1
F00813A8: 808a4008                 btst    %o0, %o1
F00813AC: 0280003f                 be      loc_F00814A8
F00813B0: 900a4016                 and     %o1, %l6, %o0
F00813B4: 808a0017                 btst    %l7, %o0
F00813B8: 02800008                 be      loc_F00813D8
F00813BC: d0246020                 st      %o0, [%l1+0x20]
F00813C0: 900a001a                 and     %o0, %i2, %o0
F00813C4: d0246020                 st      %o0, [%l1+0x20]
F00813C8: 90100011                 mov     %l1, %o0
F00813CC: 92102000                 mov     0, %o1
F00813D0: 7fffbf0b                 call    _thread_wakeup_prim
F00813D4: 94102000                 mov     0, %o2
F00813D8: a0156230                 or      %l5, 0x230, %l0
F00813DC: d0040000                 ld      [%l0], %o0
F00813E0: 80a22000                 cmp     %o0, 0
F00813E4: 12bffffe                 bne     loc_F00813DC
F00813E8: 01000000                 nop
F00813EC: 400056af                 call    _simple_lock_try
F00813F0: 90100010                 mov     %l0, %o0
F00813F4: 80a22000                 cmp     %o0, 0
F00813F8: 02bffff9                 be      loc_F00813DC
F00813FC: 01000000                 nop
F0081400: 40001fde                 call    _vm_page_free
F0081404: 90100011                 mov     %l1, %o0
F0081408: c0256230                 clr     [%l5+0x230]
F008140C: d014a044                 lduh    [%l2+0x44], %o0
F0081410: c024a010                 clr     [%l2+0x10]
F0081414: d207bff0                 ld      [%fp+var_10], %o1
F0081418: 90023fff                 inc     -1, %o0
F008141C: 80a48009                 cmp     %l2, %o1
F0081420: 02800268                 be      loc_F0081DC0
F0081424: d034a044                 sth     %o0, [%l2+0x44]
F0081428: a0026010                 add     %o1, 0x10, %l0
F008142C: d0040000                 ld      [%l0], %o0
F0081430: 80a22000                 cmp     %o0, 0
F0081434: 12bffffe                 bne     loc_F008142C
F0081438: 01000000                 nop
F008143C: 4000569b                 call    _simple_lock_try
F0081440: 90100010                 mov     %l0, %o0
F0081444: 80a22000                 cmp     %o0, 0
F0081448: 02bffff9                 be      loc_F008142C
F008144C: 01000000                 nop
F0081450: d004e020                 ld      [%l3+0x20], %o0
F0081454: 900a0016                 and     %o0, %l6, %o0
F0081458: 808a0017                 btst    %l7, %o0
F008145C: 02800008                 be      loc_F008147C
F0081460: d024e020                 st      %o0, [%l3+0x20]
F0081464: 900a001a                 and     %o0, %i2, %o0
F0081468: d024e020                 st      %o0, [%l3+0x20]
F008146C: 90100013                 mov     %l3, %o0
F0081470: 92102000                 mov     0, %o1
F0081474: 7fffbee2                 call    _thread_wakeup_prim
F0081478: 94102000                 mov     0, %o2
F008147C: a0156230                 or      %l5, 0x230, %l0
F0081480: d0040000                 ld      [%l0], %o0
F0081484: 80a22000                 cmp     %o0, 0
F0081488: 12bffffe                 bne     loc_F0081480
F008148C: 01000000                 nop
F0081490: 40005686                 call    _simple_lock_try
F0081494: 90100010                 mov     %l0, %o0
F0081498: 80a22000                 cmp     %o0, 0
F008149C: 02bffff9                 be      loc_F0081480
F00814A0: 01000000                 nop
F00814A4: 3080023f                 ba,a    loc_F0081DA0
F00814A8: 80a26000                 cmp     %o1, 0
F00814AC: 1680007c                 bge     loc_F008169C
F00814B0: 11010000                 sethi   0x4000000, %o0
F00814B4: 90124017                 or      %o1, %l7, %o0
F00814B8: d0246020                 st      %o0, [%l1+0x20]
F00814BC: c607bfbc                 ld      [%fp+var_44], %g3
F00814C0: 90100011                 mov     %l1, %o0
F00814C4: 80a00003                 cmp     %g0, %g3
F00814C8: 7fffbe03                 call    _assert_wait
F00814CC: 92603fff                 subc    %g0, -1, %o1
F00814D0: 80a6e000                 cmp     %i3, 0
F00814D4: 02800005                 be      loc_F00814E8
F00814D8: d007a044                 ld      [%fp+arg_44], %o0
F00814DC: d207bff4                 ld      [%fp+var_C], %o1
F00814E0: 400012e5                 call    _vm_map_lookup_done
F00814E4: b6102000                 mov     0, %i3
F00814E8: c024a010                 clr     [%l2+0x10]
F00814EC: 7fffc475                 call    _thread_block
F00814F0: 01000000                 nop
F00814F4: 9004a010                 add     %l2, 0x10, %o0
F00814F8: 133c04d0                 sethi   %hi(_active_threads), %o1
F00814FC: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0081500: a0100008                 mov     %o0, %l0
F0081504: e2026044                 ld      [%o1+0x44], %l1
F0081508: d0040000                 ld      [%l0], %o0
F008150C: 80a22000                 cmp     %o0, 0
F0081510: 12bffffe                 bne     loc_F0081508
F0081514: 01000000                 nop
F0081518: 40005664                 call    _simple_lock_try
F008151C: 90100010                 mov     %l0, %o0
F0081520: 80a22000                 cmp     %o0, 0
F0081524: 02bffff9                 be      loc_F0081508
F0081528: 80a46004                 cmp     %l1, 4
F008152C: 1280002e                 bne     loc_F00815E4
F0081530: 80a46000                 cmp     %l1, 0
F0081534: d014a044                 lduh    [%l2+0x44], %o0
F0081538: c024a010                 clr     [%l2+0x10]
F008153C: d207bff0                 ld      [%fp+var_10], %o1
F0081540: 90023fff                 inc     -1, %o0
F0081544: 80a48009                 cmp     %l2, %o1
F0081548: 028005d1                 be      loc_F0082C8C
F008154C: d034a044                 sth     %o0, [%l2+0x44]
F0081550: a0026010                 add     %o1, 0x10, %l0
F0081554: d0040000                 ld      [%l0], %o0
F0081558: 80a22000                 cmp     %o0, 0
F008155C: 12bffffe                 bne     loc_F0081554
F0081560: 01000000                 nop
F0081564: 40005651                 call    _simple_lock_try
F0081568: 90100010                 mov     %l0, %o0
F008156C: 80a22000                 cmp     %o0, 0
F0081570: 02bffff9                 be      loc_F0081554
F0081574: 01000000                 nop
F0081578: d004e020                 ld      [%l3+0x20], %o0
F008157C: 900a0016                 and     %o0, %l6, %o0
F0081580: 808a0017                 btst    %l7, %o0
F0081584: 02800008                 be      loc_F00815A4
F0081588: d024e020                 st      %o0, [%l3+0x20]
F008158C: 900a001a                 and     %o0, %i2, %o0
F0081590: d024e020                 st      %o0, [%l3+0x20]
F0081594: 90100013                 mov     %l3, %o0
F0081598: 92102000                 mov     0, %o1
F008159C: 7fffbe98                 call    _thread_wakeup_prim
F00815A0: 94102000                 mov     0, %o2
F00815A4: a0156230                 or      %l5, 0x230, %l0
F00815A8: d0040000                 ld      [%l0], %o0
F00815AC: 80a22000                 cmp     %o0, 0
F00815B0: 12bffffe                 bne     loc_F00815A8
F00815B4: 01000000                 nop
F00815B8: 4000563c                 call    _simple_lock_try
F00815BC: 90100010                 mov     %l0, %o0
F00815C0: 80a22000                 cmp     %o0, 0
F00815C4: 02bffff9                 be      loc_F00815A8
F00815C8: 01000000                 nop
F00815CC: 40001f6b                 call    _vm_page_free
F00815D0: 90100013                 mov     %l3, %o0
F00815D4: d207bff0                 ld      [%fp+var_10], %o1
F00815D8: c0256230                 clr     [%l5+0x230]
F00815DC: 108005a9                 ba      loc_F0082C80
F00815E0: d0126044                 lduh    [%o1+0x44], %o0
F00815E4: 02bfff6b                 be      loc_F0081390
F00815E8: 90100012                 mov     %l2, %o0
F00815EC: d014a044                 lduh    [%l2+0x44], %o0
F00815F0: c024a010                 clr     [%l2+0x10]
F00815F4: d207bff0                 ld      [%fp+var_10], %o1
F00815F8: 90023fff                 inc     -1, %o0
F00815FC: 80a48009                 cmp     %l2, %o1
F0081600: 02800628                 be      loc_F0082EA0
F0081604: d034a044                 sth     %o0, [%l2+0x44]
F0081608: a0026010                 add     %o1, 0x10, %l0
F008160C: d0040000                 ld      [%l0], %o0
F0081610: 80a22000                 cmp     %o0, 0
F0081614: 12bffffe                 bne     loc_F008160C
F0081618: 01000000                 nop
F008161C: 40005623                 call    _simple_lock_try
F0081620: 90100010                 mov     %l0, %o0
F0081624: 80a22000                 cmp     %o0, 0
F0081628: 02bffff9                 be      loc_F008160C
F008162C: 01000000                 nop
F0081630: d004e020                 ld      [%l3+0x20], %o0
F0081634: 900a0016                 and     %o0, %l6, %o0
F0081638: 808a0017                 btst    %l7, %o0
F008163C: 02800008                 be      loc_F008165C
F0081640: d024e020                 st      %o0, [%l3+0x20]
F0081644: 900a001a                 and     %o0, %i2, %o0
F0081648: d024e020                 st      %o0, [%l3+0x20]
F008164C: 90100013                 mov     %l3, %o0
F0081650: 92102000                 mov     0, %o1
F0081654: 7fffbe6a                 call    _thread_wakeup_prim
F0081658: 94102000                 mov     0, %o2
F008165C: a0156230                 or      %l5, 0x230, %l0
F0081660: d0040000                 ld      [%l0], %o0
F0081664: 80a22000                 cmp     %o0, 0
F0081668: 12bffffe                 bne     loc_F0081660
F008166C: 01000000                 nop
F0081670: 4000560e                 call    _simple_lock_try
F0081674: 90100010                 mov     %l0, %o0
F0081678: 80a22000                 cmp     %o0, 0
F008167C: 02bffff9                 be      loc_F0081660
F0081680: 01000000                 nop
F0081684: 40001f3d                 call    _vm_page_free
F0081688: 90100013                 mov     %l3, %o0
F008168C: d207bff0                 ld      [%fp+var_10], %o1
F0081690: c0256230                 clr     [%l5+0x230]
F0081694: 10800600                 ba      loc_F0082E94
F0081698: d0126044                 lduh    [%o1+0x44], %o0
F008169C: 808a4008                 btst    %o0, %o1
F00816A0: 2280006e                 be,a    loc_F0081858
F00816A4: d0046028                 ld      [%l1+0x28], %o0
F00816A8: d004a024                 ld      [%l2+0x24], %o0
F00816AC: f004a020                 ld      [%l2+0x20], %i0
F00816B0: 80a62000                 cmp     %i0, 0
F00816B4: 12800037                 bne     loc_F0081790
F00816B8: a8050008                 add     %l4, %o0, %l4
F00816BC: d007bff0                 ld      [%fp+var_10], %o0
F00816C0: 80a48008                 cmp     %l2, %o0
F00816C4: 02800029                 be      loc_F0081768
F00816C8: 900a401c                 and     %o1, %i4, %o0
F00816CC: 900a0016                 and     %o0, %l6, %o0
F00816D0: 808a0017                 btst    %l7, %o0
F00816D4: 02800008                 be      loc_F00816F4
F00816D8: d0246020                 st      %o0, [%l1+0x20]
F00816DC: 900a001a                 and     %o0, %i2, %o0
F00816E0: d0246020                 st      %o0, [%l1+0x20]
F00816E4: 90100011                 mov     %l1, %o0
F00816E8: 92102000                 mov     0, %o1
F00816EC: 7fffbe44                 call    _thread_wakeup_prim
F00816F0: 94102000                 mov     0, %o2
F00816F4: a0156230                 or      %l5, 0x230, %l0
F00816F8: d0040000                 ld      [%l0], %o0
F00816FC: 80a22000                 cmp     %o0, 0
F0081700: 12bffffe                 bne     loc_F00816F8
F0081704: 01000000                 nop
F0081708: 400055e8                 call    _simple_lock_try
F008170C: 90100010                 mov     %l0, %o0
F0081710: 80a22000                 cmp     %o0, 0
F0081714: 02bffff9                 be      loc_F00816F8
F0081718: 01000000                 nop
F008171C: 40001f17                 call    _vm_page_free
F0081720: 90100011                 mov     %l1, %o0
F0081724: c0256230                 clr     [%l5+0x230]
F0081728: d014a044                 lduh    [%l2+0x44], %o0
F008172C: c024a010                 clr     [%l2+0x10]
F0081730: 90023fff                 inc     -1, %o0
F0081734: d034a044                 sth     %o0, [%l2+0x44]
F0081738: e407bff0                 ld      [%fp+var_10], %l2
F008173C: a2100013                 mov     %l3, %l1
F0081740: a004a010                 add     %l2, 0x10, %l0
F0081744: d0040000                 ld      [%l0], %o0
F0081748: 80a22000                 cmp     %o0, 0
F008174C: 12bffffe                 bne     loc_F0081744
F0081750: 01000000                 nop
F0081754: 400055d5                 call    _simple_lock_try
F0081758: 90100010                 mov     %l0, %o0
F008175C: 80a22000                 cmp     %o0, 0
F0081760: 02bffff9                 be      loc_F0081744
F0081764: 01000000                 nop
F0081768: 4000206d                 call    _vm_page_zero_fill
F008176C: 90100011                 mov     %l1, %o0
F0081770: d0066014                 ld      [%i1+0x14], %o0
F0081774: 90022001                 inc     %o0
F0081778: d0266014                 st      %o0, [%i1+0x14]
F008177C: d0046020                 ld      [%l1+0x20], %o0
F0081780: a6102000                 mov     0, %l3
F0081784: 900a001c                 and     %o0, %i4, %o0
F0081788: 10800033                 ba      loc_F0081854
F008178C: d0246020                 st      %o0, [%l1+0x20]
F0081790: d007bff0                 ld      [%fp+var_10], %o0
F0081794: 80a48008                 cmp     %l2, %o0
F0081798: 2280001f                 be,a    loc_F0081814
F008179C: a6100011                 mov     %l1, %l3
F00817A0: d014a044                 lduh    [%l2+0x44], %o0
F00817A4: 90023fff                 inc     -1, %o0
F00817A8: d034a044                 sth     %o0, [%l2+0x44]
F00817AC: d0046020                 ld      [%l1+0x20], %o0
F00817B0: 900a0016                 and     %o0, %l6, %o0
F00817B4: 808a0017                 btst    %l7, %o0
F00817B8: 02800008                 be      loc_F00817D8
F00817BC: d0246020                 st      %o0, [%l1+0x20]
F00817C0: 900a001a                 and     %o0, %i2, %o0
F00817C4: d0246020                 st      %o0, [%l1+0x20]
F00817C8: 90100011                 mov     %l1, %o0
F00817CC: 92102000                 mov     0, %o1
F00817D0: 7fffbe0b                 call    _thread_wakeup_prim
F00817D4: 94102000                 mov     0, %o2
F00817D8: a0156230                 or      %l5, 0x230, %l0
F00817DC: d0040000                 ld      [%l0], %o0
F00817E0: 80a22000                 cmp     %o0, 0
F00817E4: 12bffffe                 bne     loc_F00817DC
F00817E8: 01000000                 nop
F00817EC: 400055af                 call    _simple_lock_try
F00817F0: 90100010                 mov     %l0, %o0
F00817F4: 80a22000                 cmp     %o0, 0
F00817F8: 02bffff9                 be      loc_F00817DC
F00817FC: 01000000                 nop
F0081800: 40001ede                 call    _vm_page_free
F0081804: 90100011                 mov     %l1, %o0
F0081808: c0256230                 clr     [%l5+0x230]
F008180C: 10800005                 ba      loc_F0081820
F0081810: a0062010                 add     %i0, 0x10, %l0
F0081814: 900a401c                 and     %o1, %i4, %o0
F0081818: d024e020                 st      %o0, [%l3+0x20]
F008181C: a0062010                 add     %i0, 0x10, %l0
F0081820: d0040000                 ld      [%l0], %o0
F0081824: 80a22000                 cmp     %o0, 0
F0081828: 12bffffe                 bne     loc_F0081820
F008182C: 01000000                 nop
F0081830: 4000559e                 call    _simple_lock_try
F0081834: 90100010                 mov     %l0, %o0
F0081838: 80a22000                 cmp     %o0, 0
F008183C: 02bffff9                 be      loc_F0081820
F0081840: 01000000                 nop
F0081844: c024a010                 clr     [%l2+0x10]
F0081848: a4100018                 mov     %i0, %l2
F008184C: 10bffece                 ba      loc_F0081384
F0081850: d014a044                 lduh    [%l2+0x44], %o0
F0081854: d0046028                 ld      [%l1+0x28], %o0
F0081858: c607bfc4                 ld      [%fp+var_3C], %g3
F008185C: 8088c008                 btst    %o0, %g3
F0081860: 02800032                 be      loc_F0081928
F0081864: a0156230                 or      %l5, 0x230, %l0
F0081868: d014a044                 lduh    [%l2+0x44], %o0
F008186C: c024a010                 clr     [%l2+0x10]
F0081870: d207bff0                 ld      [%fp+var_10], %o1
F0081874: 90023fff                 inc     -1, %o0
F0081878: 80a48009                 cmp     %l2, %o1
F008187C: 02800151                 be      loc_F0081DC0
F0081880: d034a044                 sth     %o0, [%l2+0x44]
F0081884: a0026010                 add     %o1, 0x10, %l0
F0081888: d0040000                 ld      [%l0], %o0
F008188C: 80a22000                 cmp     %o0, 0
F0081890: 12bffffe                 bne     loc_F0081888
F0081894: 01000000                 nop
F0081898: 40005584                 call    _simple_lock_try
F008189C: 90100010                 mov     %l0, %o0
F00818A0: 80a22000                 cmp     %o0, 0
F00818A4: 02bffff9                 be      loc_F0081888
F00818A8: 01000000                 nop
F00818AC: d004e020                 ld      [%l3+0x20], %o0
F00818B0: 900a0016                 and     %o0, %l6, %o0
F00818B4: 808a0017                 btst    %l7, %o0
F00818B8: 02800008                 be      loc_F00818D8
F00818BC: d024e020                 st      %o0, [%l3+0x20]
F00818C0: 900a001a                 and     %o0, %i2, %o0
F00818C4: d024e020                 st      %o0, [%l3+0x20]
F00818C8: 90100013                 mov     %l3, %o0
F00818CC: 92102000                 mov     0, %o1
F00818D0: 7fffbdcb                 call    _thread_wakeup_prim
F00818D4: 94102000                 mov     0, %o2
F00818D8: a0156230                 or      %l5, 0x230, %l0
F00818DC: d0040000                 ld      [%l0], %o0
F00818E0: 80a22000                 cmp     %o0, 0
F00818E4: 12bffffe                 bne     loc_F00818DC
F00818E8: 01000000                 nop
F00818EC: 4000556f                 call    _simple_lock_try
F00818F0: 90100010                 mov     %l0, %o0
F00818F4: 80a22000                 cmp     %o0, 0
F00818F8: 02bffff9                 be      loc_F00818DC
F00818FC: 01000000                 nop
F0081900: 30800128                 ba,a    loc_F0081DA0
F0081904: 073c04f0                 sethi   %hi(_vm_page_queue_inactive), %g3
F0081908: 1080001b                 ba      loc_F0081974
F008190C: d020e228                 st      %o0, [%g3+%lo(_vm_page_queue_inactive)]
F0081910: 073c04f3                 sethi   %hi(_vm_page_queue_active), %g3
F0081914: 10800032                 ba      loc_F00819DC
F0081918: d020e008                 st      %o0, [%g3+%lo(_vm_page_queue_active)]
F008191C: 073c04f3                 sethi   %hi(_vm_page_queue_free), %g3
F0081920: 10800045                 ba      loc_F0081A34
F0081924: d020e010                 st      %o0, [%g3+%lo(_vm_page_queue_free)]
F0081928: d0040000                 ld      [%l0], %o0
F008192C: 80a22000                 cmp     %o0, 0
F0081930: 12bffffe                 bne     loc_F0081928
F0081934: 01000000                 nop
F0081938: 4000555c                 call    _simple_lock_try
F008193C: 90100010                 mov     %l0, %o0
F0081940: 80a22000                 cmp     %o0, 0
F0081944: 02bffff9                 be      loc_F0081928
F0081948: 11000020                 sethi   0x8000, %o0
F008194C: d204601c                 ld      [%l1+0x1C], %o1
F0081950: 808a4008                 btst    %o0, %o1
F0081954: 02800015                 be      loc_F00819A8
F0081958: 11000010                 sethi   0x4000, %o0
F008195C: d0044000                 ld      [%l1], %o0
F0081960: d2046004                 ld      [%l1+4], %o1
F0081964: 80a2401d                 cmp     %o1, %i5
F0081968: 02bfffe7                 be      loc_F0081904
F008196C: d2222004                 st      %o1, [%o0+4]
F0081970: d0224000                 st      %o0, [%o1]
F0081974: 11000020                 sethi   0x8000, %o0
F0081978: d204601c                 ld      [%l1+0x1C], %o1
F008197C: 153c04f0                 sethi   %hi(_vm_page_inactive_count), %o2
F0081980: 902a4008                 andn    %o1, %o0, %o0
F0081984: d202a220                 ld      [%o2+%lo(_vm_page_inactive_count)], %o1
F0081988: d024601c                 st      %o0, [%l1+0x1C]
F008198C: d0066018                 ld      [%i1+0x18], %o0
F0081990: 92027fff                 inc     -1, %o1
F0081994: d222a220                 st      %o1, [%o2+%lo(_vm_page_inactive_count)]
F0081998: 90022001                 inc     %o0
F008199C: d0266018                 st      %o0, [%i1+0x18]
F00819A0: d204601c                 ld      [%l1+0x1C], %o1
F00819A4: 11000010                 sethi   0x4000, %o0
F00819A8: 808a4008                 btst    %o0, %o1
F00819AC: 22800015                 be,a    loc_F0081A00
F00819B0: d204601c                 ld      [%l1+0x1C], %o1
F00819B4: 073c04f3                 sethi   %hi(_vm_page_queue_active), %g3
F00819B8: d0044000                 ld      [%l1], %o0
F00819BC: 8610e008                 bset    %lo(_vm_page_queue_active), %g3
F00819C0: d2046004                 ld      [%l1+4], %o1
F00819C4: 073c04f38610e008         set     _vm_page_queue_active, %g3
F00819CC: 80a24003                 cmp     %o1, %g3
F00819D0: 02bfffd0                 be      loc_F0081910
F00819D4: d2222004                 st      %o1, [%o0+4]
F00819D8: d0224000                 st      %o0, [%o1]
F00819DC: 13000010                 sethi   0x4000, %o1
F00819E0: d004601c                 ld      [%l1+0x1C], %o0
F00819E4: 153c04f2                 sethi   %hi(_vm_page_active_count), %o2
F00819E8: 922a0009                 andn    %o0, %o1, %o1
F00819EC: d002a3f8                 ld      [%o2+%lo(_vm_page_active_count)], %o0
F00819F0: d224601c                 st      %o1, [%l1+0x1C]
F00819F4: 90023fff                 inc     -1, %o0
F00819F8: d022a3f8                 st      %o0, [%o2+%lo(_vm_page_active_count)]
F00819FC: d204601c                 ld      [%l1+0x1C], %o1
F0081A00: 11000004                 sethi   0x1000, %o0
F0081A04: 808a4008                 btst    %o0, %o1
F0081A08: 02800016                 be      loc_F0081A60
F0081A0C: 073c04f3                 sethi   %hi(_vm_page_queue_free), %g3
F0081A10: d0044000                 ld      [%l1], %o0
F0081A14: 8610e010                 bset    %lo(_vm_page_queue_free), %g3
F0081A18: d2046004                 ld      [%l1+4], %o1
F0081A1C: 073c04f38610e010         set     _vm_page_queue_free, %g3
F0081A24: 80a24003                 cmp     %o1, %g3
F0081A28: 02bfffbd                 be      loc_F008191C
F0081A2C: d2222004                 st      %o1, [%o0+4]
F0081A30: d0224000                 st      %o0, [%o1]
F0081A34: 11000004                 sethi   0x1000, %o0
F0081A38: d204601c                 ld      [%l1+0x1C], %o1
F0081A3C: 153c04f3                 sethi   %hi(_vm_page_free_count), %o2
F0081A40: 902a4008                 andn    %o1, %o0, %o0
F0081A44: d202a000                 ld      [%o2+%lo(_vm_page_free_count)], %o1
F0081A48: d024601c                 st      %o0, [%l1+0x1C]
F0081A4C: d0066018                 ld      [%i1+0x18], %o0
F0081A50: 92027fff                 inc     -1, %o1
F0081A54: d222a000                 st      %o1, [%o2+%lo(_vm_page_free_count)]
F0081A58: 90022001                 inc     %o0
F0081A5C: d0266018                 st      %o0, [%i1+0x18]
F0081A60: c0256230                 clr     [%l5+0x230]
F0081A64: d0046020                 ld      [%l1+0x20], %o0
F0081A68: 13200000                 sethi   0x80000000, %o1
F0081A6C: 10800124                 ba      loc_F0081EFC
F0081A70: 90120009                 bset    %o1, %o0
F0081A74: d004a028                 ld      [%l2+0x28], %o0
F0081A78: 80a22000                 cmp     %o0, 0
F0081A7C: 2280000a                 be,a    loc_F0081AA4
F0081A80: d007bff0                 ld      [%fp+var_10], %o0
F0081A84: c607bfbc                 ld      [%fp+var_44], %g3
F0081A88: 80a0e000                 cmp     %g3, 0
F0081A8C: 02800009                 be      loc_F0081AB0
F0081A90: d007bfe4                 ld      [%fp+var_1C], %o0
F0081A94: 80a22000                 cmp     %o0, 0
F0081A98: 12800007                 bne     loc_F0081AB4
F0081A9C: 90100012                 mov     %l2, %o0
F0081AA0: d007bff0                 ld      [%fp+var_10], %o0
F0081AA4: 80a48008                 cmp     %l2, %o0
F0081AA8: 3280004a                 bne,a   loc_F0081BD0
F0081AAC: d004a028                 ld      [%l2+0x28], %o0
F0081AB0: 90100012                 mov     %l2, %o0
F0081AB4: 92100014                 mov     %l4, %o1
F0081AB8: 40001d9d                 call    _vm_page_alloc_sequential
F0081ABC: 94102001                 mov     1, %o2
F0081AC0: a2920000                 orcc    %o0, %g0, %l1
F0081AC4: 32800043                 bne,a   loc_F0081BD0
F0081AC8: d004a028                 ld      [%l2+0x28], %o0
F0081ACC: d014a044                 lduh    [%l2+0x44], %o0
F0081AD0: c024a010                 clr     [%l2+0x10]
F0081AD4: d207bff0                 ld      [%fp+var_10], %o1
F0081AD8: 90023fff                 inc     -1, %o0
F0081ADC: 80a48009                 cmp     %l2, %o1
F0081AE0: 02800029                 be      loc_F0081B84
F0081AE4: d034a044                 sth     %o0, [%l2+0x44]
F0081AE8: a0026010                 add     %o1, 0x10, %l0
F0081AEC: d0040000                 ld      [%l0], %o0
F0081AF0: 80a22000                 cmp     %o0, 0
F0081AF4: 12bffffe                 bne     loc_F0081AEC
F0081AF8: 01000000                 nop
F0081AFC: 400054eb                 call    _simple_lock_try
F0081B00: 90100010                 mov     %l0, %o0
F0081B04: 80a22000                 cmp     %o0, 0
F0081B08: 02bffff9                 be      loc_F0081AEC
F0081B0C: 01000000                 nop
F0081B10: d004e020                 ld      [%l3+0x20], %o0
F0081B14: 900a0016                 and     %o0, %l6, %o0
F0081B18: 808a0017                 btst    %l7, %o0
F0081B1C: 02800008                 be      loc_F0081B3C
F0081B20: d024e020                 st      %o0, [%l3+0x20]
F0081B24: 900a001a                 and     %o0, %i2, %o0
F0081B28: d024e020                 st      %o0, [%l3+0x20]
F0081B2C: 90100013                 mov     %l3, %o0
F0081B30: 92102000                 mov     0, %o1
F0081B34: 7fffbd32                 call    _thread_wakeup_prim
F0081B38: 94102000                 mov     0, %o2
F0081B3C: a0156230                 or      %l5, 0x230, %l0
F0081B40: d0040000                 ld      [%l0], %o0
F0081B44: 80a22000                 cmp     %o0, 0
F0081B48: 12bffffe                 bne     loc_F0081B40
F0081B4C: 01000000                 nop
F0081B50: 400054d6                 call    _simple_lock_try
F0081B54: 90100010                 mov     %l0, %o0
F0081B58: 80a22000                 cmp     %o0, 0
F0081B5C: 02bffff9                 be      loc_F0081B40
F0081B60: 01000000                 nop
F0081B64: 40001e05                 call    _vm_page_free
F0081B68: 90100013                 mov     %l3, %o0
F0081B6C: d207bff0                 ld      [%fp+var_10], %o1
F0081B70: c0256230                 clr     [%l5+0x230]
F0081B74: d0126044                 lduh    [%o1+0x44], %o0
F0081B78: c0226010                 clr     [%o1+0x10]
F0081B7C: 90023fff                 inc     -1, %o0
F0081B80: d0326044                 sth     %o0, [%o1+0x44]
F0081B84: 80a6e000                 cmp     %i3, 0
F0081B88: 02800004                 be      loc_F0081B98
F0081B8C: d007a044                 ld      [%fp+arg_44], %o0
F0081B90: 40001139                 call    _vm_map_lookup_done
F0081B94: d207bff4                 ld      [%fp+var_C], %o1
F0081B98: 40001348                 call    _vm_object_deallocate
F0081B9C: d007bff0                 ld      [%fp+var_10], %o0
F0081BA0: 113c04f3a0122020         set     _vm_pages_needed_lock, %l0
F0081BA8: d0040000                 ld      [%l0], %o0
F0081BAC: 80a22000                 cmp     %o0, 0
F0081BB0: 12bffffe                 bne     loc_F0081BA8
F0081BB4: 01000000                 nop
F0081BB8: 400054bc                 call    _simple_lock_try
F0081BBC: 90100010                 mov     %l0, %o0
F0081BC0: 80a22000                 cmp     %o0, 0
F0081BC4: 02bffff9                 be      loc_F0081BA8
F0081BC8: 113c04f3                 sethi   -0xFEC3400, %o0
F0081BCC: 30800257                 ba,a    loc_F0082528
F0081BD0: 80a22000                 cmp     %o0, 0
F0081BD4: 028000a8                 be      loc_F0081E74
F0081BD8: c607bfbc                 ld      [%fp+var_44], %g3
F0081BDC: 80a0e000                 cmp     %g3, 0
F0081BE0: 02800005                 be      loc_F0081BF4
F0081BE4: d007bfe4                 ld      [%fp+var_1C], %o0
F0081BE8: 80a22000                 cmp     %o0, 0
F0081BEC: 028000a3                 be      loc_F0081E78
F0081BF0: d207bff0                 ld      [%fp+var_10], %o1
F0081BF4: c024a010                 clr     [%l2+0x10]
F0081BF8: 80a6e000                 cmp     %i3, 0
F0081BFC: 02800006                 be      loc_F0081C14
F0081C00: a004a010                 add     %l2, 0x10, %l0
F0081C04: d007a044                 ld      [%fp+arg_44], %o0
F0081C08: d207bff4                 ld      [%fp+var_C], %o1
F0081C0C: 4000111a                 call    _vm_map_lookup_done
F0081C10: b6102000                 mov     0, %i3
F0081C14: d004a028                 ld      [%l2+0x28], %o0
F0081C18: d407bfb4                 ld      [%fp+var_4C], %o2
F0081C1C: 4000196f                 call    _vm_pager_get
F0081C20: 92100011                 mov     %l1, %o1
F0081C24: 80a22000                 cmp     %o0, 0
F0081C28: 12800015                 bne     loc_F0081C7C
F0081C2C: 80a22002                 cmp     %o0, 2
F0081C30: d0040000                 ld      [%l0], %o0
F0081C34: 80a22000                 cmp     %o0, 0
F0081C38: 12bffffe                 bne     loc_F0081C30
F0081C3C: 01000000                 nop
F0081C40: 4000549a                 call    _simple_lock_try
F0081C44: 90100010                 mov     %l0, %o0
F0081C48: 80a22000                 cmp     %o0, 0
F0081C4C: 02bffff9                 be      loc_F0081C30
F0081C50: 90100012                 mov     %l2, %o0
F0081C54: 40001cd1                 call    _vm_page_lookup
F0081C58: 92100014                 mov     %l4, %o1
F0081C5C: d206601c                 ld      [%i1+0x1C], %o1
F0081C60: a2100008                 mov     %o0, %l1
F0081C64: 92026001                 inc     %o1
F0081C68: d226601c                 st      %o1, [%i1+0x1C]
F0081C6C: 40007611                 call    _pmap_clear_modify
F0081C70: d0046024                 ld      [%l1+0x24], %o0
F0081C74: 108000ba                 ba      loc_F0081F5C
F0081C78: d4046020                 ld      [%l1+0x20], %o2
F0081C7C: 1280005a                 bne     loc_F0081DE4
F0081C80: 01000000                 nop
F0081C84: d0040000                 ld      [%l0], %o0
F0081C88: 80a22000                 cmp     %o0, 0
F0081C8C: 12bffffe                 bne     loc_F0081C84
F0081C90: 01000000                 nop
F0081C94: 40005485                 call    _simple_lock_try
F0081C98: 90100010                 mov     %l0, %o0
F0081C9C: 80a22000                 cmp     %o0, 0
F0081CA0: 02bffff9                 be      loc_F0081C84
F0081CA4: 01000000                 nop
F0081CA8: d0046020                 ld      [%l1+0x20], %o0
F0081CAC: 900a0016                 and     %o0, %l6, %o0
F0081CB0: 808a0017                 btst    %l7, %o0
F0081CB4: 02800008                 be      loc_F0081CD4
F0081CB8: d0246020                 st      %o0, [%l1+0x20]
F0081CBC: 900a001a                 and     %o0, %i2, %o0
F0081CC0: d0246020                 st      %o0, [%l1+0x20]
F0081CC4: 90100011                 mov     %l1, %o0
F0081CC8: 92102000                 mov     0, %o1
F0081CCC: 7fffbccc                 call    _thread_wakeup_prim
F0081CD0: 94102000                 mov     0, %o2
F0081CD4: a0156230                 or      %l5, 0x230, %l0
F0081CD8: d0040000                 ld      [%l0], %o0
F0081CDC: 80a22000                 cmp     %o0, 0
F0081CE0: 12bffffe                 bne     loc_F0081CD8
F0081CE4: 01000000                 nop
F0081CE8: 40005470                 call    _simple_lock_try
F0081CEC: 90100010                 mov     %l0, %o0
F0081CF0: 80a22000                 cmp     %o0, 0
F0081CF4: 02bffff9                 be      loc_F0081CD8
F0081CF8: 01000000                 nop
F0081CFC: 40001d9f                 call    _vm_page_free
F0081D00: 90100011                 mov     %l1, %o0
F0081D04: c0256230                 clr     [%l5+0x230]
F0081D08: d014a044                 lduh    [%l2+0x44], %o0
F0081D0C: c024a010                 clr     [%l2+0x10]
F0081D10: d207bff0                 ld      [%fp+var_10], %o1
F0081D14: 90023fff                 inc     -1, %o0
F0081D18: 80a48009                 cmp     %l2, %o1
F0081D1C: 02800029                 be      loc_F0081DC0
F0081D20: d034a044                 sth     %o0, [%l2+0x44]
F0081D24: a0026010                 add     %o1, 0x10, %l0
F0081D28: d0040000                 ld      [%l0], %o0
F0081D2C: 80a22000                 cmp     %o0, 0
F0081D30: 12bffffe                 bne     loc_F0081D28
F0081D34: 01000000                 nop
F0081D38: 4000545c                 call    _simple_lock_try
F0081D3C: 90100010                 mov     %l0, %o0
F0081D40: 80a22000                 cmp     %o0, 0
F0081D44: 02bffff9                 be      loc_F0081D28
F0081D48: 01000000                 nop
F0081D4C: d004e020                 ld      [%l3+0x20], %o0
F0081D50: 900a0016                 and     %o0, %l6, %o0
F0081D54: 808a0017                 btst    %l7, %o0
F0081D58: 02800008                 be      loc_F0081D78
F0081D5C: d024e020                 st      %o0, [%l3+0x20]
F0081D60: 900a001a                 and     %o0, %i2, %o0
F0081D64: d024e020                 st      %o0, [%l3+0x20]
F0081D68: 90100013                 mov     %l3, %o0
F0081D6C: 92102000                 mov     0, %o1
F0081D70: 7fffbca3                 call    _thread_wakeup_prim
F0081D74: 94102000                 mov     0, %o2
F0081D78: a0156230                 or      %l5, 0x230, %l0
F0081D7C: d0040000                 ld      [%l0], %o0
F0081D80: 80a22000                 cmp     %o0, 0
F0081D84: 12bffffe                 bne     loc_F0081D7C
F0081D88: 01000000                 nop
F0081D8C: 40005447                 call    _simple_lock_try
F0081D90: 90100010                 mov     %l0, %o0
F0081D94: 80a22000                 cmp     %o0, 0
F0081D98: 02bffff9                 be      loc_F0081D7C
F0081D9C: 01000000                 nop
F0081DA0: 40001d76                 call    _vm_page_free
F0081DA4: 90100013                 mov     %l3, %o0
F0081DA8: d207bff0                 ld      [%fp+var_10], %o1
F0081DAC: c0256230                 clr     [%l5+0x230]
F0081DB0: d0126044                 lduh    [%o1+0x44], %o0
F0081DB4: c0226010                 clr     [%o1+0x10]
F0081DB8: 90023fff                 inc     -1, %o0
F0081DBC: d0326044                 sth     %o0, [%o1+0x44]
F0081DC0: 80a6e000                 cmp     %i3, 0
F0081DC4: 02800004                 be      loc_F0081DD4
F0081DC8: d007a044                 ld      [%fp+arg_44], %o0
F0081DCC: 400010aa                 call    _vm_map_lookup_done
F0081DD0: d207bff4                 ld      [%fp+var_C], %o1
F0081DD4: 400012b9                 call    _vm_object_deallocate
F0081DD8: d007bff0                 ld      [%fp+var_10], %o0
F0081DDC: 10800439                 ba      locret_F0082EC0
F0081DE0: b010200a                 mov     0xA, %i0
F0081DE4: d0040000                 ld      [%l0], %o0
F0081DE8: 80a22000                 cmp     %o0, 0
F0081DEC: 12bffffe                 bne     loc_F0081DE4
F0081DF0: 01000000                 nop
F0081DF4: 4000542d                 call    _simple_lock_try
F0081DF8: 90100010                 mov     %l0, %o0
F0081DFC: 80a22000                 cmp     %o0, 0
F0081E00: 02bffff9                 be      loc_F0081DE4
F0081E04: d007bff0                 ld      [%fp+var_10], %o0
F0081E08: 80a48008                 cmp     %l2, %o0
F0081E0C: 0280001b                 be      loc_F0081E78
F0081E10: d207bff0                 ld      [%fp+var_10], %o1
F0081E14: d0046020                 ld      [%l1+0x20], %o0
F0081E18: 900a0016                 and     %o0, %l6, %o0
F0081E1C: 808a0017                 btst    %l7, %o0
F0081E20: 02800008                 be      loc_F0081E40
F0081E24: d0246020                 st      %o0, [%l1+0x20]
F0081E28: 900a001a                 and     %o0, %i2, %o0
F0081E2C: d0246020                 st      %o0, [%l1+0x20]
F0081E30: 90100011                 mov     %l1, %o0
F0081E34: 92102000                 mov     0, %o1
F0081E38: 7fffbc71                 call    _thread_wakeup_prim
F0081E3C: 94102000                 mov     0, %o2
F0081E40: a0156230                 or      %l5, 0x230, %l0
F0081E44: d0040000                 ld      [%l0], %o0
F0081E48: 80a22000                 cmp     %o0, 0
F0081E4C: 12bffffe                 bne     loc_F0081E44
F0081E50: 01000000                 nop
F0081E54: 40005415                 call    _simple_lock_try
F0081E58: 90100010                 mov     %l0, %o0
F0081E5C: 80a22000                 cmp     %o0, 0
F0081E60: 02bffff9                 be      loc_F0081E44
F0081E64: 01000000                 nop
F0081E68: 40001d44                 call    _vm_page_free
F0081E6C: 90100011                 mov     %l1, %o0
F0081E70: c0256230                 clr     [%l5+0x230]
F0081E74: d207bff0                 ld      [%fp+var_10], %o1
F0081E78: 80a48009                 cmp     %l2, %o1
F0081E7C: 22800002                 be,a    loc_F0081E84
F0081E80: a6100011                 mov     %l1, %l3
F0081E84: d004a024                 ld      [%l2+0x24], %o0
F0081E88: f004a020                 ld      [%l2+0x20], %i0
F0081E8C: 80a62000                 cmp     %i0, 0
F0081E90: 1280001e                 bne     loc_F0081F08
F0081E94: a8050008                 add     %l4, %o0, %l4
F0081E98: 80a48009                 cmp     %l2, %o1
F0081E9C: 02800011                 be      loc_F0081EE0
F0081EA0: a0026010                 add     %o1, 0x10, %l0
F0081EA4: c024a010                 clr     [%l2+0x10]
F0081EA8: d014a044                 lduh    [%l2+0x44], %o0
F0081EAC: a2100013                 mov     %l3, %l1
F0081EB0: 90023fff                 inc     -1, %o0
F0081EB4: d034a044                 sth     %o0, [%l2+0x44]
F0081EB8: a4100009                 mov     %o1, %l2
F0081EBC: d0040000                 ld      [%l0], %o0
F0081EC0: 80a22000                 cmp     %o0, 0
F0081EC4: 12bffffe                 bne     loc_F0081EBC
F0081EC8: 01000000                 nop
F0081ECC: 400053f7                 call    _simple_lock_try
F0081ED0: 90100010                 mov     %l0, %o0
F0081ED4: 80a22000                 cmp     %o0, 0
F0081ED8: 02bffff9                 be      loc_F0081EBC
F0081EDC: 01000000                 nop
F0081EE0: 40001e8f                 call    _vm_page_zero_fill
F0081EE4: 90100011                 mov     %l1, %o0
F0081EE8: d0066014                 ld      [%i1+0x14], %o0
F0081EEC: 90022001                 inc     %o0
F0081EF0: d0266014                 st      %o0, [%i1+0x14]
F0081EF4: d0046020                 ld      [%l1+0x20], %o0
F0081EF8: a6102000                 mov     0, %l3
F0081EFC: 900a001c                 and     %o0, %i4, %o0
F0081F00: 10800016                 ba      loc_F0081F58
F0081F04: d0246020                 st      %o0, [%l1+0x20]
F0081F08: a0062010                 add     %i0, 0x10, %l0
F0081F0C: d0040000                 ld      [%l0], %o0
F0081F10: 80a22000                 cmp     %o0, 0
F0081F14: 12bffffe                 bne     loc_F0081F0C
F0081F18: 01000000                 nop
F0081F1C: 400053e3                 call    _simple_lock_try
F0081F20: 90100010                 mov     %l0, %o0
F0081F24: 80a22000                 cmp     %o0, 0
F0081F28: 02bffff9                 be      loc_F0081F0C
F0081F2C: d007bff0                 ld      [%fp+var_10], %o0
F0081F30: 80a48008                 cmp     %l2, %o0
F0081F34: 02800005                 be      loc_F0081F48
F0081F38: 01000000                 nop
F0081F3C: d014a044                 lduh    [%l2+0x44], %o0
F0081F40: 90023fff                 inc     -1, %o0
F0081F44: d034a044                 sth     %o0, [%l2+0x44]
F0081F48: c024a010                 clr     [%l2+0x10]
F0081F4C: a4100018                 mov     %i0, %l2
F0081F50: 10bffd0d                 ba      loc_F0081384
F0081F54: d014a044                 lduh    [%l2+0x44], %o0
F0081F58: d4046020                 ld      [%l1+0x20], %o2
F0081F5C: 11010000                 sethi   0x4000000, %o0
F0081F60: 808a8008                 btst    %o0, %o2
F0081F64: 1280000a                 bne     loc_F0081F8C
F0081F68: 113c0446                 sethi   -0xFEEE800, %o0
F0081F6C: d204601c                 ld      [%l1+0x1C], %o1
F0081F70: 11000030                 sethi   0xC000, %o0
F0081F74: 808a4008                 btst    %o0, %o1
F0081F78: 12800005                 bne     loc_F0081F8C
F0081F7C: 113c0446                 sethi   -0xFEEE800, %o0
F0081F80: 80a2a000                 cmp     %o2, 0
F0081F84: 26800005                 bl,a    loc_F0081F98
F0081F88: d007bff0                 ld      [%fp+var_10], %o0! char *
F0081F8C: 7ffe4c79                 call    _panic
F0081F90: 90122068                 bset    0x68, %o0 ! 'h'
F0081F94: d007bff0                 ld      [%fp+var_10], %o0
F0081F98: 80a48008                 cmp     %l2, %o0
F0081F9C: 02800054                 be      loc_F00820EC
F0081FA0: ae100011                 mov     %l1, %l7
F0081FA4: c607bfc4                 ld      [%fp+var_3C], %g3
F0081FA8: 8088e002                 btst    2, %g3
F0081FAC: 02800049                 be      loc_F00820D0
F0081FB0: 90100011                 mov     %l1, %o0
F0081FB4: 40001e5f                 call    _vm_page_copy
F0081FB8: 92100013                 mov     %l3, %o1
F0081FBC: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0081FC4: d204e020                 ld      [%l3+0x20], %o1
F0081FC8: 11010000                 sethi   0x4000000, %o0
F0081FCC: 902a4008                 andn    %o1, %o0, %o0
F0081FD0: d024e020                 st      %o0, [%l3+0x20]
F0081FD4: d0040000                 ld      [%l0], %o0
F0081FD8: 80a22000                 cmp     %o0, 0
F0081FDC: 12bffffe                 bne     loc_F0081FD4
F0081FE0: 01000000                 nop
F0081FE4: 400053b1                 call    _simple_lock_try
F0081FE8: 90100010                 mov     %l0, %o0
F0081FEC: 80a22000                 cmp     %o0, 0
F0081FF0: 02bffff9                 be      loc_F0081FD4
F0081FF4: 01000000                 nop
F0081FF8: 40001dfb                 call    _vm_page_activate
F0081FFC: 90100011                 mov     %l1, %o0
F0082000: 40001db7                 call    _vm_page_deactivate
F0082004: 90100011                 mov     %l1, %o0
F0082008: d007bfe0                 ld      [%fp+var_20], %o0
F008200C: 80a22000                 cmp     %o0, 0
F0082010: 12800005                 bne     loc_F0082024
F0082014: 113c04f0                 sethi   -0xFEC4000, %o0
F0082018: 40006df8                 call    _pmap_remove_all
F008201C: d0046024                 ld      [%l1+0x24], %o0
F0082020: 113c04f0                 sethi   -0xFEC4000, %o0
F0082024: c0222230                 clr     [%o0+0x230]
F0082028: d2046020                 ld      [%l1+0x20], %o1
F008202C: 11200000                 sethi   0x80000000, %o0
F0082030: 922a4008                 bclr    %o0, %o1
F0082034: 11100000                 sethi   0x40000000, %o0
F0082038: 808a4008                 btst    %o0, %o1
F008203C: 02800008                 be      loc_F008205C
F0082040: d2246020                 st      %o1, [%l1+0x20]
F0082044: 902a4008                 andn    %o1, %o0, %o0
F0082048: d0246020                 st      %o0, [%l1+0x20]
F008204C: 90100011                 mov     %l1, %o0
F0082050: 92102000                 mov     0, %o1
F0082054: 7fffbbea                 call    _thread_wakeup_prim
F0082058: 94102000                 mov     0, %o2
F008205C: c024a010                 clr     [%l2+0x10]
F0082060: 133c04f0                 sethi   %hi(_vm_stat), %o1
F0082064: d014a044                 lduh    [%l2+0x44], %o0
F0082068: 92126240                 bset    %lo(_vm_stat), %o1
F008206C: 90023fff                 inc     -1, %o0
F0082070: d034a044                 sth     %o0, [%l2+0x44]
F0082074: d0026028                 ld      [%o1+0x28], %o0
F0082078: a2100013                 mov     %l3, %l1
F008207C: e407bff0                 ld      [%fp+var_10], %l2
F0082080: 90022001                 inc     %o0
F0082084: d0226028                 st      %o0, [%o1+0x28]
F0082088: a004a010                 add     %l2, 0x10, %l0
F008208C: d0040000                 ld      [%l0], %o0
F0082090: 80a22000                 cmp     %o0, 0
F0082094: 12bffffe                 bne     loc_F008208C
F0082098: 01000000                 nop
F008209C: 40005383                 call    _simple_lock_try
F00820A0: 90100010                 mov     %l0, %o0
F00820A4: 80a22000                 cmp     %o0, 0
F00820A8: 02bffff9                 be      loc_F008208C
F00820AC: 90100012                 mov     %l2, %o0
F00820B0: d214a044                 lduh    [%l2+0x44], %o1
F00820B4: 92027fff                 inc     -1, %o1
F00820B8: 40001572                 call    _vm_object_collapse
F00820BC: d234a044                 sth     %o1, [%l2+0x44]
F00820C0: d014a044                 lduh    [%l2+0x44], %o0
F00820C4: 90022001                 inc     %o0
F00820C8: 10800009                 ba      loc_F00820EC
F00820CC: d034a044                 sth     %o0, [%l2+0x44]
F00820D0: d007bfe8                 ld      [%fp+var_18], %o0
F00820D4: 900a3ffd                 and     %o0, -3, %o0
F00820D8: d027bfe8                 st      %o0, [%fp+var_18]
F00820DC: d0046020                 ld      [%l1+0x20], %o0
F00820E0: 13000800                 sethi   0x200000, %o1
F00820E4: 90120009                 bset    %o1, %o0
F00820E8: d0246020                 st      %o0, [%l1+0x20]
F00820EC: d204601c                 ld      [%l1+0x1C], %o1
F00820F0: 11000030                 sethi   0xC000, %o0
F00820F4: 808a4008                 btst    %o0, %o1
F00820F8: 02800004                 be      loc_F0082108
F00820FC: 113c0446                 sethi   %hi(aVmFaultActiveO), %o0! "vm_fault: active or inactive before cop"...
F0082100: 7ffe4c1c                 call    _panic
F0082104: 901220b0                 bset    %lo(aVmFaultActiveO), %o0! "vm_fault: active or inactive before cop"...
F0082108: d007bff0                 ld      [%fp+var_10], %o0
F008210C: d002201c                 ld      [%o0+0x1C], %o0
F0082110: 80a22000                 cmp     %o0, 0
F0082114: 028001b6                 be      loc_F00827EC
F0082118: c607bfc4                 ld      [%fp+var_3C], %g3
F008211C: 8088e002                 btst    2, %g3
F0082120: 12800009                 bne     loc_F0082144
F0082124: a8100008                 mov     %o0, %l4
F0082128: d007bfe8                 ld      [%fp+var_18], %o0
F008212C: 900a3ffd                 and     %o0, -3, %o0
F0082130: d027bfe8                 st      %o0, [%fp+var_18]
F0082134: d0046020                 ld      [%l1+0x20], %o0
F0082138: 13000800                 sethi   0x200000, %o1
F008213C: 108001ab                 ba      loc_F00827E8
F0082140: 90120009                 bset    %o1, %o0
F0082144: 40005359                 call    _simple_lock_try
F0082148: 90052010                 add     %l4, 0x10, %o0
F008214C: 80a22000                 cmp     %o0, 0
F0082150: 3280000e                 bne,a   loc_F0082188
F0082154: d2152018                 lduh    [%l4+0x18], %o1
F0082158: c024a010                 clr     [%l2+0x10]
F008215C: a004a010                 add     %l2, 0x10, %l0
F0082160: d0040000                 ld      [%l0], %o0
F0082164: 80a22000                 cmp     %o0, 0
F0082168: 12bffffe                 bne     loc_F0082160
F008216C: 01000000                 nop
F0082170: 4000534e                 call    _simple_lock_try
F0082174: 90100010                 mov     %l0, %o0
F0082178: 80a22000                 cmp     %o0, 0
F008217C: 02bffff9                 be      loc_F0082160
F0082180: d007bff0                 ld      [%fp+var_10], %o0
F0082184: 30bfffe2                 ba,a    loc_F008210C
F0082188: d607bfec                 ld      [%fp+var_14], %o3
F008218C: 90100014                 mov     %l4, %o0
F0082190: d4052024                 ld      [%l4+0x24], %o2
F0082194: 92026001                 inc     %o1
F0082198: d2352018                 sth     %o1, [%l4+0x18]
F008219C: aa22c00a                 sub     %o3, %o2, %l5
F00821A0: 40001b7e                 call    _vm_page_lookup
F00821A4: 92100015                 mov     %l5, %o1
F00821A8: b0100008                 mov     %o0, %i0
F00821AC: 80a00018                 cmp     %g0, %i0
F00821B0: ac402000                 addc    %g0, 0, %l6
F00821B4: 80a5a000                 cmp     %l6, 0
F00821B8: 02800070                 be      loc_F0082378
F00821BC: 01000000                 nop
F00821C0: d0062020                 ld      [%i0+0x20], %o0
F00821C4: 80a22000                 cmp     %o0, 0
F00821C8: 1680006c                 bge     loc_F0082378
F00821CC: 80a5a000                 cmp     %l6, 0
F00821D0: 21100000                 sethi   0x40000000, %l0
F00821D4: 90120010                 bset    %l0, %o0
F00821D8: d0262020                 st      %o0, [%i0+0x20]
F00821DC: c607bfbc                 ld      [%fp+var_44], %g3
F00821E0: 90100018                 mov     %i0, %o0
F00821E4: 80a00003                 cmp     %g0, %g3
F00821E8: 7fffbabb                 call    _assert_wait
F00821EC: 92603fff                 subc    %g0, -1, %o1
F00821F0: d2046020                 ld      [%l1+0x20], %o1
F00821F4: 11200000                 sethi   0x80000000, %o0
F00821F8: 922a4008                 bclr    %o0, %o1
F00821FC: 808a4010                 btst    %l0, %o1
F0082200: 02800009                 be      loc_F0082224
F0082204: d2246020                 st      %o1, [%l1+0x20]
F0082208: 11100000                 sethi   0x40000000, %o0
F008220C: 902a4008                 andn    %o1, %o0, %o0
F0082210: d0246020                 st      %o0, [%l1+0x20]
F0082214: 90100011                 mov     %l1, %o0
F0082218: 92102000                 mov     0, %o1
F008221C: 7fffbb78                 call    _thread_wakeup_prim
F0082220: 94102000                 mov     0, %o2
F0082224: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F008222C: d0040000                 ld      [%l0], %o0
F0082230: 80a22000                 cmp     %o0, 0
F0082234: 12bffffe                 bne     loc_F008222C
F0082238: 01000000                 nop
F008223C: 4000531b                 call    _simple_lock_try
F0082240: 90100010                 mov     %l0, %o0
F0082244: 80a22000                 cmp     %o0, 0
F0082248: 02bffff9                 be      loc_F008222C
F008224C: 01000000                 nop
F0082250: 40001d65                 call    _vm_page_activate
F0082254: 90100011                 mov     %l1, %o0
F0082258: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F008225C: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082260: d0152018                 lduh    [%l4+0x18], %o0
F0082264: c0252010                 clr     [%l4+0x10]
F0082268: d207bff0                 ld      [%fp+var_10], %o1
F008226C: 90023fff                 inc     -1, %o0
F0082270: d0352018                 sth     %o0, [%l4+0x18]
F0082274: c024a010                 clr     [%l2+0x10]
F0082278: d014a044                 lduh    [%l2+0x44], %o0
F008227C: 80a48009                 cmp     %l2, %o1
F0082280: 90023fff                 inc     -1, %o0
F0082284: 0280002c                 be      loc_F0082334
F0082288: d034a044                 sth     %o0, [%l2+0x44]
F008228C: a0026010                 add     %o1, 0x10, %l0
F0082290: d0040000                 ld      [%l0], %o0
F0082294: 80a22000                 cmp     %o0, 0
F0082298: 12bffffe                 bne     loc_F0082290
F008229C: 01000000                 nop
F00822A0: 40005302                 call    _simple_lock_try
F00822A4: 90100010                 mov     %l0, %o0
F00822A8: 80a22000                 cmp     %o0, 0
F00822AC: 02bffff9                 be      loc_F0082290
F00822B0: 13200000                 sethi   0x80000000, %o1
F00822B4: d004e020                 ld      [%l3+0x20], %o0
F00822B8: 922a0009                 andn    %o0, %o1, %o1
F00822BC: 11100000                 sethi   0x40000000, %o0
F00822C0: 808a4008                 btst    %o0, %o1
F00822C4: 02800008                 be      loc_F00822E4
F00822C8: d224e020                 st      %o1, [%l3+0x20]
F00822CC: 902a4008                 andn    %o1, %o0, %o0
F00822D0: d024e020                 st      %o0, [%l3+0x20]
F00822D4: 90100013                 mov     %l3, %o0
F00822D8: 92102000                 mov     0, %o1
F00822DC: 7fffbb48                 call    _thread_wakeup_prim
F00822E0: 94102000                 mov     0, %o2
F00822E4: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F00822EC: d0040000                 ld      [%l0], %o0
F00822F0: 80a22000                 cmp     %o0, 0
F00822F4: 12bffffe                 bne     loc_F00822EC
F00822F8: 01000000                 nop
F00822FC: 400052eb                 call    _simple_lock_try
F0082300: 90100010                 mov     %l0, %o0
F0082304: 80a22000                 cmp     %o0, 0
F0082308: 02bffff9                 be      loc_F00822EC
F008230C: 01000000                 nop
F0082310: 40001c1a                 call    _vm_page_free
F0082314: 90100013                 mov     %l3, %o0
F0082318: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F008231C: d207bff0                 ld      [%fp+var_10], %o1
F0082320: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082324: d0126044                 lduh    [%o1+0x44], %o0
F0082328: c0226010                 clr     [%o1+0x10]
F008232C: 90023fff                 inc     -1, %o0
F0082330: d0326044                 sth     %o0, [%o1+0x44]
F0082334: 80a6e000                 cmp     %i3, 0
F0082338: 02800004                 be      loc_F0082348
F008233C: d007a044                 ld      [%fp+arg_44], %o0
F0082340: 40000f4d                 call    _vm_map_lookup_done
F0082344: d207bff4                 ld      [%fp+var_C], %o1
F0082348: 7fffc0de                 call    _thread_block
F008234C: 01000000                 nop
F0082350: 133c04d0                 sethi   %hi(_active_threads), %o1
F0082354: d2026260                 ld      [%o1+%lo(_active_threads)], %o1
F0082358: d007bff0                 ld      [%fp+var_10], %o0
F008235C: 40001157                 call    _vm_object_deallocate
F0082360: e0026044                 ld      [%o1+0x44], %l0
F0082364: 80a42000                 cmp     %l0, 0
F0082368: 02bffbd5                 be      loc_F00812BC
F008236C: 9007bfe8                 add     %fp, var_18, %o0
F0082370: 108002d4                 ba      locret_F0082EC0
F0082374: b0102000                 mov     0, %i0
F0082378: 128000eb                 bne     loc_F0082724
F008237C: 80a5a000                 cmp     %l6, 0
F0082380: 90100014                 mov     %l4, %o0
F0082384: 92100015                 mov     %l5, %o1
F0082388: 40001b69                 call    _vm_page_alloc_sequential
F008238C: 94102001                 mov     1, %o2
F0082390: b0920000                 orcc    %o0, %g0, %i0
F0082394: 32800071                 bne,a   loc_F0082558
F0082398: d0052028                 ld      [%l4+0x28], %o0
F008239C: d0046020                 ld      [%l1+0x20], %o0
F00823A0: 13200000                 sethi   0x80000000, %o1
F00823A4: 922a0009                 andn    %o0, %o1, %o1
F00823A8: 11100000                 sethi   0x40000000, %o0
F00823AC: 808a4008                 btst    %o0, %o1
F00823B0: 02800008                 be      loc_F00823D0
F00823B4: d2246020                 st      %o1, [%l1+0x20]
F00823B8: 902a4008                 andn    %o1, %o0, %o0
F00823BC: d0246020                 st      %o0, [%l1+0x20]
F00823C0: 90100011                 mov     %l1, %o0
F00823C4: 92102000                 mov     0, %o1
F00823C8: 7fffbb0d                 call    _thread_wakeup_prim
F00823CC: 94102000                 mov     0, %o2
F00823D0: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F00823D8: d0040000                 ld      [%l0], %o0
F00823DC: 80a22000                 cmp     %o0, 0
F00823E0: 12bffffe                 bne     loc_F00823D8
F00823E4: 01000000                 nop
F00823E8: 400052b0                 call    _simple_lock_try
F00823EC: 90100010                 mov     %l0, %o0
F00823F0: 80a22000                 cmp     %o0, 0
F00823F4: 02bffff9                 be      loc_F00823D8
F00823F8: 01000000                 nop
F00823FC: 40001cfa                 call    _vm_page_activate
F0082400: 90100011                 mov     %l1, %o0
F0082404: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0082408: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F008240C: d0152018                 lduh    [%l4+0x18], %o0
F0082410: c0252010                 clr     [%l4+0x10]
F0082414: d207bff0                 ld      [%fp+var_10], %o1
F0082418: 90023fff                 inc     -1, %o0
F008241C: d0352018                 sth     %o0, [%l4+0x18]
F0082420: c024a010                 clr     [%l2+0x10]
F0082424: d014a044                 lduh    [%l2+0x44], %o0
F0082428: 80a48009                 cmp     %l2, %o1
F008242C: 90023fff                 inc     -1, %o0
F0082430: 0280002c                 be      loc_F00824E0
F0082434: d034a044                 sth     %o0, [%l2+0x44]
F0082438: a0026010                 add     %o1, 0x10, %l0
F008243C: d0040000                 ld      [%l0], %o0
F0082440: 80a22000                 cmp     %o0, 0
F0082444: 12bffffe                 bne     loc_F008243C
F0082448: 01000000                 nop
F008244C: 40005297                 call    _simple_lock_try
F0082450: 90100010                 mov     %l0, %o0
F0082454: 80a22000                 cmp     %o0, 0
F0082458: 02bffff9                 be      loc_F008243C
F008245C: 13200000                 sethi   0x80000000, %o1
F0082460: d004e020                 ld      [%l3+0x20], %o0
F0082464: 922a0009                 andn    %o0, %o1, %o1
F0082468: 11100000                 sethi   0x40000000, %o0
F008246C: 808a4008                 btst    %o0, %o1
F0082470: 02800008                 be      loc_F0082490
F0082474: d224e020                 st      %o1, [%l3+0x20]
F0082478: 902a4008                 andn    %o1, %o0, %o0
F008247C: d024e020                 st      %o0, [%l3+0x20]
F0082480: 90100013                 mov     %l3, %o0
F0082484: 92102000                 mov     0, %o1
F0082488: 7fffbadd                 call    _thread_wakeup_prim
F008248C: 94102000                 mov     0, %o2
F0082490: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0082498: d0040000                 ld      [%l0], %o0
F008249C: 80a22000                 cmp     %o0, 0
F00824A0: 12bffffe                 bne     loc_F0082498
F00824A4: 01000000                 nop
F00824A8: 40005280                 call    _simple_lock_try
F00824AC: 90100010                 mov     %l0, %o0
F00824B0: 80a22000                 cmp     %o0, 0
F00824B4: 02bffff9                 be      loc_F0082498
F00824B8: 01000000                 nop
F00824BC: 40001baf                 call    _vm_page_free
F00824C0: 90100013                 mov     %l3, %o0
F00824C4: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F00824C8: d207bff0                 ld      [%fp+var_10], %o1
F00824CC: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F00824D0: d0126044                 lduh    [%o1+0x44], %o0
F00824D4: c0226010                 clr     [%o1+0x10]
F00824D8: 90023fff                 inc     -1, %o0
F00824DC: d0326044                 sth     %o0, [%o1+0x44]
F00824E0: 80a6e000                 cmp     %i3, 0
F00824E4: 02800004                 be      loc_F00824F4
F00824E8: d007a044                 ld      [%fp+arg_44], %o0
F00824EC: 40000ee2                 call    _vm_map_lookup_done
F00824F0: d207bff4                 ld      [%fp+var_C], %o1
F00824F4: 400010f1                 call    _vm_object_deallocate
F00824F8: d007bff0                 ld      [%fp+var_10], %o0
F00824FC: 113c04f3a0122020         set     _vm_pages_needed_lock, %l0
F0082504: d0040000                 ld      [%l0], %o0
F0082508: 80a22000                 cmp     %o0, 0
F008250C: 12bffffe                 bne     loc_F0082504
F0082510: 01000000                 nop
F0082514: 40005265                 call    _simple_lock_try
F0082518: 90100010                 mov     %l0, %o0
F008251C: 80a22000                 cmp     %o0, 0
F0082520: 02bffff9                 be      loc_F0082504
F0082524: 113c04f3                 sethi   -0xFEC3400, %o0
F0082528: 90122018                 bset    0x18, %o0
F008252C: 92102000                 mov     0, %o1
F0082530: 7fffbab3                 call    _thread_wakeup_prim
F0082534: 94102000                 mov     0, %o2
F0082538: 113c04f390122000         set     _vm_page_free_count, %o0
F0082540: 133c04f392126020         set     _vm_pages_needed_lock, %o1
F0082548: 7fffbb1d                 call    _thread_sleep
F008254C: 94102000                 mov     0, %o2
F0082550: 10bffb5b                 ba      loc_F00812BC
F0082554: 9007bfe8                 add     %fp, var_18, %o0
F0082558: 80a22000                 cmp     %o0, 0
F008255C: 02800072                 be      loc_F0082724
F0082560: 80a5a000                 cmp     %l6, 0
F0082564: c024a010                 clr     [%l2+0x10]
F0082568: c0252010                 clr     [%l4+0x10]
F008256C: 80a6e000                 cmp     %i3, 0
F0082570: 02800006                 be      loc_F0082588
F0082574: a0052010                 add     %l4, 0x10, %l0
F0082578: d007a044                 ld      [%fp+arg_44], %o0
F008257C: d207bff4                 ld      [%fp+var_C], %o1
F0082580: 40000ebd                 call    _vm_map_lookup_done
F0082584: b6102000                 mov     0, %i3
F0082588: d205202c                 ld      [%l4+0x2C], %o1
F008258C: d0052028                 ld      [%l4+0x28], %o0
F0082590: 40001750                 call    _vm_pager_has_page
F0082594: 92054009                 add     %l5, %o1, %o1
F0082598: ac100008                 mov     %o0, %l6
F008259C: d0040000                 ld      [%l0], %o0
F00825A0: 80a22000                 cmp     %o0, 0
F00825A4: 12bffffe                 bne     loc_F008259C
F00825A8: 01000000                 nop
F00825AC: 4000523f                 call    _simple_lock_try
F00825B0: 90100010                 mov     %l0, %o0
F00825B4: 80a22000                 cmp     %o0, 0
F00825B8: 02bffff9                 be      loc_F008259C
F00825BC: 01000000                 nop
F00825C0: d0052020                 ld      [%l4+0x20], %o0
F00825C4: 80a20012                 cmp     %o0, %l2
F00825C8: 32800007                 bne,a   loc_F00825E4
F00825CC: d0062020                 ld      [%i0+0x20], %o0
F00825D0: d0552018                 ldsh    [%l4+0x18], %o0
F00825D4: 80a22001                 cmp     %o0, 1
F00825D8: 3280002c                 bne,a   loc_F0082688
F00825DC: a004a010                 add     %l2, 0x10, %l0
F00825E0: d0062020                 ld      [%i0+0x20], %o0
F00825E4: 13200000                 sethi   0x80000000, %o1
F00825E8: 922a0009                 andn    %o0, %o1, %o1
F00825EC: 11100000                 sethi   0x40000000, %o0
F00825F0: 808a4008                 btst    %o0, %o1
F00825F4: 02800008                 be      loc_F0082614
F00825F8: d2262020                 st      %o1, [%i0+0x20]
F00825FC: 902a4008                 andn    %o1, %o0, %o0
F0082600: d0262020                 st      %o0, [%i0+0x20]
F0082604: 90100018                 mov     %i0, %o0
F0082608: 92102000                 mov     0, %o1
F008260C: 7fffba7c                 call    _thread_wakeup_prim
F0082610: 94102000                 mov     0, %o2
F0082614: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F008261C: d0040000                 ld      [%l0], %o0
F0082620: 80a22000                 cmp     %o0, 0
F0082624: 12bffffe                 bne     loc_F008261C
F0082628: 01000000                 nop
F008262C: 4000521f                 call    _simple_lock_try
F0082630: 90100010                 mov     %l0, %o0
F0082634: 80a22000                 cmp     %o0, 0
F0082638: 02bffff9                 be      loc_F008261C
F008263C: 01000000                 nop
F0082640: 40001b4e                 call    _vm_page_free
F0082644: 90100018                 mov     %i0, %o0
F0082648: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F008264C: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082650: c0252010                 clr     [%l4+0x10]
F0082654: 40001099                 call    _vm_object_deallocate
F0082658: 90100014                 mov     %l4, %o0
F008265C: a004a010                 add     %l2, 0x10, %l0
F0082660: d0040000                 ld      [%l0], %o0
F0082664: 80a22000                 cmp     %o0, 0
F0082668: 12bffffe                 bne     loc_F0082660
F008266C: 01000000                 nop
F0082670: 4000520e                 call    _simple_lock_try
F0082674: 90100010                 mov     %l0, %o0
F0082678: 80a22000                 cmp     %o0, 0
F008267C: 02bffff9                 be      loc_F0082660
F0082680: d007bff0                 ld      [%fp+var_10], %o0
F0082684: 30bffea2                 ba,a    loc_F008210C
F0082688: d0040000                 ld      [%l0], %o0
F008268C: 80a22000                 cmp     %o0, 0
F0082690: 12bffffe                 bne     loc_F0082688
F0082694: 01000000                 nop
F0082698: 40005204                 call    _simple_lock_try
F008269C: 90100010                 mov     %l0, %o0
F00826A0: 80a22000                 cmp     %o0, 0
F00826A4: 02bffff9                 be      loc_F0082688
F00826A8: 80a5a000                 cmp     %l6, 0
F00826AC: 0280001e                 be      loc_F0082724
F00826B0: 13200000                 sethi   0x80000000, %o1
F00826B4: d0062020                 ld      [%i0+0x20], %o0
F00826B8: 922a0009                 andn    %o0, %o1, %o1
F00826BC: 11100000                 sethi   0x40000000, %o0
F00826C0: 808a4008                 btst    %o0, %o1
F00826C4: 02800008                 be      loc_F00826E4
F00826C8: d2262020                 st      %o1, [%i0+0x20]
F00826CC: 902a4008                 andn    %o1, %o0, %o0
F00826D0: d0262020                 st      %o0, [%i0+0x20]
F00826D4: 90100018                 mov     %i0, %o0
F00826D8: 92102000                 mov     0, %o1
F00826DC: 7fffba48                 call    _thread_wakeup_prim
F00826E0: 94102000                 mov     0, %o2
F00826E4: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F00826EC: d0040000                 ld      [%l0], %o0
F00826F0: 80a22000                 cmp     %o0, 0
F00826F4: 12bffffe                 bne     loc_F00826EC
F00826F8: 01000000                 nop
F00826FC: 400051eb                 call    _simple_lock_try
F0082700: 90100010                 mov     %l0, %o0
F0082704: 80a22000                 cmp     %o0, 0
F0082708: 02bffff9                 be      loc_F00826EC
F008270C: 01000000                 nop
F0082710: 40001b1a                 call    _vm_page_free
F0082714: 90100018                 mov     %i0, %o0
F0082718: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F008271C: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082720: 80a5a000                 cmp     %l6, 0
F0082724: 3280002b                 bne,a   loc_F00827D0
F0082728: d0152018                 lduh    [%l4+0x18], %o0
F008272C: 90100011                 mov     %l1, %o0
F0082730: 40001c80                 call    _vm_page_copy
F0082734: 92100018                 mov     %i0, %o1
F0082738: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0082740: d2062020                 ld      [%i0+0x20], %o1
F0082744: 11010000                 sethi   0x4000000, %o0
F0082748: 902a4008                 andn    %o1, %o0, %o0
F008274C: d0262020                 st      %o0, [%i0+0x20]
F0082750: d0040000                 ld      [%l0], %o0
F0082754: 80a22000                 cmp     %o0, 0
F0082758: 12bffffe                 bne     loc_F0082750
F008275C: 01000000                 nop
F0082760: 400051d2                 call    _simple_lock_try
F0082764: 90100010                 mov     %l0, %o0
F0082768: 80a22000                 cmp     %o0, 0
F008276C: 02bffff9                 be      loc_F0082750
F0082770: 01000000                 nop
F0082774: 40006c21                 call    _pmap_remove_all
F0082778: d005e024                 ld      [%l7+0x24], %o0
F008277C: d206201c                 ld      [%i0+0x1C], %o1
F0082780: 90100018                 mov     %i0, %o0
F0082784: 920a7bff                 and     %o1, -0x401, %o1
F0082788: 40001c17                 call    _vm_page_activate
F008278C: d226201c                 st      %o1, [%i0+0x1C]
F0082790: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0082794: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082798: d2062020                 ld      [%i0+0x20], %o1
F008279C: 11200000                 sethi   0x80000000, %o0
F00827A0: 922a4008                 bclr    %o0, %o1
F00827A4: 11100000                 sethi   0x40000000, %o0
F00827A8: 808a4008                 btst    %o0, %o1
F00827AC: 02800008                 be      loc_F00827CC
F00827B0: d2262020                 st      %o1, [%i0+0x20]
F00827B4: 902a4008                 andn    %o1, %o0, %o0
F00827B8: d0262020                 st      %o0, [%i0+0x20]
F00827BC: 90100018                 mov     %i0, %o0
F00827C0: 92102000                 mov     0, %o1
F00827C4: 7fffba0e                 call    _thread_wakeup_prim
F00827C8: 94102000                 mov     0, %o2
F00827CC: d0152018                 lduh    [%l4+0x18], %o0
F00827D0: c0252010                 clr     [%l4+0x10]
F00827D4: 90023fff                 inc     -1, %o0
F00827D8: d0352018                 sth     %o0, [%l4+0x18]
F00827DC: d2046020                 ld      [%l1+0x20], %o1
F00827E0: 11000800                 sethi   0x200000, %o0
F00827E4: 902a4008                 andn    %o1, %o0, %o0
F00827E8: d0246020                 st      %o0, [%l1+0x20]
F00827EC: d204601c                 ld      [%l1+0x1C], %o1
F00827F0: 11000030                 sethi   0xC000, %o0
F00827F4: 808a4008                 btst    %o0, %o1
F00827F8: 02800006                 be      loc_F0082810
F00827FC: 80a6e000                 cmp     %i3, 0
F0082800: 113c0446                 sethi   %hi(aVmFaultActiveO_0), %o0! "vm_fault: active or inactive before ret"...
F0082804: 7ffe4a5b                 call    _panic
F0082808: 901220f0                 bset    %lo(aVmFaultActiveO_0), %o0! "vm_fault: active or inactive before ret"...
F008280C: 80a6e000                 cmp     %i3, 0
F0082810: 12800128                 bne     loc_F0082CB0
F0082814: d007bfe8                 ld      [%fp+var_18], %o0
F0082818: c024a010                 clr     [%l2+0x10]
F008281C: 9007bfd4                 add     %fp, var_2C, %o0
F0082820: d023a05c                 st      %o0, [%sp+0xC0+var_64]
F0082824: 9007bfe4                 add     %fp, var_1C, %o0
F0082828: d023a060                 st      %o0, [%sp+0xC0+var_60]
F008282C: 9007bfe0                 add     %fp, var_20, %o0
F0082830: d023a064                 st      %o0, [%sp+0xC0+var_5C]
F0082834: 9007a044                 add     %fp, arg_44, %o0
F0082838: 9607bff4                 add     %fp, var_C, %o3
F008283C: 9807bfdc                 add     %fp, var_24, %o4
F0082840: c607bfc4                 ld      [%fp+var_3C], %g3
F0082844: 9a07bfd8                 add     %fp, var_28, %o5
F0082848: d207bfcc                 ld      [%fp+var_34], %o1
F008284C: 40000d62                 call    _vm_map_lookup
F0082850: 9408fffd                 and     %g3, -3, %o2
F0082854: b0100008                 mov     %o0, %i0
F0082858: 9004a010                 add     %l2, 0x10, %o0
F008285C: a0100008                 mov     %o0, %l0
F0082860: d0040000                 ld      [%l0], %o0
F0082864: 80a22000                 cmp     %o0, 0
F0082868: 12bffffe                 bne     loc_F0082860
F008286C: 01000000                 nop
F0082870: 4000518e                 call    _simple_lock_try
F0082874: 90100010                 mov     %l0, %o0
F0082878: 80a22000                 cmp     %o0, 0
F008287C: 02bffff9                 be      loc_F0082860
F0082880: 80a62000                 cmp     %i0, 0
F0082884: 02800056                 be      loc_F00829DC
F0082888: 13200000                 sethi   0x80000000, %o1
F008288C: d0046020                 ld      [%l1+0x20], %o0
F0082890: 922a0009                 andn    %o0, %o1, %o1
F0082894: 11100000                 sethi   0x40000000, %o0
F0082898: 808a4008                 btst    %o0, %o1
F008289C: 02800008                 be      loc_F00828BC
F00828A0: d2246020                 st      %o1, [%l1+0x20]
F00828A4: 902a4008                 andn    %o1, %o0, %o0
F00828A8: d0246020                 st      %o0, [%l1+0x20]
F00828AC: 90100011                 mov     %l1, %o0
F00828B0: 92102000                 mov     0, %o1
F00828B4: 7fffb9d2                 call    _thread_wakeup_prim
F00828B8: 94102000                 mov     0, %o2
F00828BC: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F00828C4: d0040000                 ld      [%l0], %o0
F00828C8: 80a22000                 cmp     %o0, 0
F00828CC: 12bffffe                 bne     loc_F00828C4
F00828D0: 01000000                 nop
F00828D4: 40005175                 call    _simple_lock_try
F00828D8: 90100010                 mov     %l0, %o0
F00828DC: 80a22000                 cmp     %o0, 0
F00828E0: 02bffff9                 be      loc_F00828C4
F00828E4: 01000000                 nop
F00828E8: 40001bbf                 call    _vm_page_activate
F00828EC: 90100011                 mov     %l1, %o0
F00828F0: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F00828F4: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F00828F8: d014a044                 lduh    [%l2+0x44], %o0
F00828FC: c024a010                 clr     [%l2+0x10]
F0082900: d207bff0                 ld      [%fp+var_10], %o1
F0082904: 90023fff                 inc     -1, %o0
F0082908: 80a48009                 cmp     %l2, %o1
F008290C: 0280002c                 be      loc_F00829BC
F0082910: d034a044                 sth     %o0, [%l2+0x44]
F0082914: a0026010                 add     %o1, 0x10, %l0
F0082918: d0040000                 ld      [%l0], %o0
F008291C: 80a22000                 cmp     %o0, 0
F0082920: 12bffffe                 bne     loc_F0082918
F0082924: 01000000                 nop
F0082928: 40005160                 call    _simple_lock_try
F008292C: 90100010                 mov     %l0, %o0
F0082930: 80a22000                 cmp     %o0, 0
F0082934: 02bffff9                 be      loc_F0082918
F0082938: 13200000                 sethi   0x80000000, %o1
F008293C: d004e020                 ld      [%l3+0x20], %o0
F0082940: 922a0009                 andn    %o0, %o1, %o1
F0082944: 11100000                 sethi   0x40000000, %o0
F0082948: 808a4008                 btst    %o0, %o1
F008294C: 02800008                 be      loc_F008296C
F0082950: d224e020                 st      %o1, [%l3+0x20]
F0082954: 902a4008                 andn    %o1, %o0, %o0
F0082958: d024e020                 st      %o0, [%l3+0x20]
F008295C: 90100013                 mov     %l3, %o0
F0082960: 92102000                 mov     0, %o1
F0082964: 7fffb9a6                 call    _thread_wakeup_prim
F0082968: 94102000                 mov     0, %o2
F008296C: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0082974: d0040000                 ld      [%l0], %o0
F0082978: 80a22000                 cmp     %o0, 0
F008297C: 12bffffe                 bne     loc_F0082974
F0082980: 01000000                 nop
F0082984: 40005149                 call    _simple_lock_try
F0082988: 90100010                 mov     %l0, %o0
F008298C: 80a22000                 cmp     %o0, 0
F0082990: 02bffff9                 be      loc_F0082974
F0082994: 01000000                 nop
F0082998: 40001a78                 call    _vm_page_free
F008299C: 90100013                 mov     %l3, %o0
F00829A0: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F00829A4: d207bff0                 ld      [%fp+var_10], %o1
F00829A8: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F00829AC: d0126044                 lduh    [%o1+0x44], %o0
F00829B0: c0226010                 clr     [%o1+0x10]
F00829B4: 90023fff                 inc     -1, %o0
F00829B8: d0326044                 sth     %o0, [%o1+0x44]
F00829BC: 80a6e000                 cmp     %i3, 0
F00829C0: 02800004                 be      loc_F00829D0
F00829C4: d007a044                 ld      [%fp+arg_44], %o0
F00829C8: 40000dab                 call    _vm_map_lookup_done
F00829CC: d207bff4                 ld      [%fp+var_C], %o1
F00829D0: 40000fba                 call    _vm_object_deallocate
F00829D4: d007bff0                 ld      [%fp+var_10], %o0
F00829D8: 3080013a                 ba,a    locret_F0082EC0
F00829DC: d207bfdc                 ld      [%fp+var_24], %o1
F00829E0: d007bff0                 ld      [%fp+var_10], %o0
F00829E4: 80a24008                 cmp     %o1, %o0
F00829E8: 12800007                 bne     loc_F0082A04
F00829EC: b6102001                 mov     1, %i3
F00829F0: d207bfd8                 ld      [%fp+var_28], %o1
F00829F4: d007bfec                 ld      [%fp+var_14], %o0
F00829F8: 80a24008                 cmp     %o1, %o0
F00829FC: 02800047                 be      loc_F0082B18
F0082A00: d207bfe8                 ld      [%fp+var_18], %o1
F0082A04: d0046020                 ld      [%l1+0x20], %o0
F0082A08: 13200000                 sethi   0x80000000, %o1
F0082A0C: 922a0009                 andn    %o0, %o1, %o1
F0082A10: 11100000                 sethi   0x40000000, %o0
F0082A14: 808a4008                 btst    %o0, %o1
F0082A18: 02800008                 be      loc_F0082A38
F0082A1C: d2246020                 st      %o1, [%l1+0x20]
F0082A20: 902a4008                 andn    %o1, %o0, %o0
F0082A24: d0246020                 st      %o0, [%l1+0x20]
F0082A28: 90100011                 mov     %l1, %o0
F0082A2C: 92102000                 mov     0, %o1
F0082A30: 7fffb973                 call    _thread_wakeup_prim
F0082A34: 94102000                 mov     0, %o2
F0082A38: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0082A40: d0040000                 ld      [%l0], %o0
F0082A44: 80a22000                 cmp     %o0, 0
F0082A48: 12bffffe                 bne     loc_F0082A40
F0082A4C: 01000000                 nop
F0082A50: 40005116                 call    _simple_lock_try
F0082A54: 90100010                 mov     %l0, %o0
F0082A58: 80a22000                 cmp     %o0, 0
F0082A5C: 02bffff9                 be      loc_F0082A40
F0082A60: 01000000                 nop
F0082A64: 40001b60                 call    _vm_page_activate
F0082A68: 90100011                 mov     %l1, %o0
F0082A6C: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0082A70: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082A74: d014a044                 lduh    [%l2+0x44], %o0
F0082A78: c024a010                 clr     [%l2+0x10]
F0082A7C: d207bff0                 ld      [%fp+var_10], %o1
F0082A80: 90023fff                 inc     -1, %o0
F0082A84: 80a48009                 cmp     %l2, %o1
F0082A88: 02800081                 be      loc_F0082C8C
F0082A8C: d034a044                 sth     %o0, [%l2+0x44]
F0082A90: a0026010                 add     %o1, 0x10, %l0
F0082A94: d0040000                 ld      [%l0], %o0
F0082A98: 80a22000                 cmp     %o0, 0
F0082A9C: 12bffffe                 bne     loc_F0082A94
F0082AA0: 01000000                 nop
F0082AA4: 40005101                 call    _simple_lock_try
F0082AA8: 90100010                 mov     %l0, %o0
F0082AAC: 80a22000                 cmp     %o0, 0
F0082AB0: 02bffff9                 be      loc_F0082A94
F0082AB4: 13200000                 sethi   0x80000000, %o1
F0082AB8: d004e020                 ld      [%l3+0x20], %o0
F0082ABC: 922a0009                 andn    %o0, %o1, %o1
F0082AC0: 11100000                 sethi   0x40000000, %o0
F0082AC4: 808a4008                 btst    %o0, %o1
F0082AC8: 02800008                 be      loc_F0082AE8
F0082ACC: d224e020                 st      %o1, [%l3+0x20]
F0082AD0: 902a4008                 andn    %o1, %o0, %o0
F0082AD4: d024e020                 st      %o0, [%l3+0x20]
F0082AD8: 90100013                 mov     %l3, %o0
F0082ADC: 92102000                 mov     0, %o1
F0082AE0: 7fffb947                 call    _thread_wakeup_prim
F0082AE4: 94102000                 mov     0, %o2
F0082AE8: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0082AF0: d0040000                 ld      [%l0], %o0
F0082AF4: 80a22000                 cmp     %o0, 0
F0082AF8: 12bffffe                 bne     loc_F0082AF0
F0082AFC: 01000000                 nop
F0082B00: 400050ea                 call    _simple_lock_try
F0082B04: 90100010                 mov     %l0, %o0
F0082B08: 80a22000                 cmp     %o0, 0
F0082B0C: 02bffff9                 be      loc_F0082AF0
F0082B10: 01000000                 nop
F0082B14: 30800055                 ba,a    loc_F0082C68
F0082B18: d007bfd4                 ld      [%fp+var_2C], %o0
F0082B1C: 940a4008                 and     %o1, %o0, %o2
F0082B20: d427bfe8                 st      %o2, [%fp+var_18]
F0082B24: d2046020                 ld      [%l1+0x20], %o1
F0082B28: 11000800                 sethi   0x200000, %o0
F0082B2C: 808a4008                 btst    %o0, %o1
F0082B30: 02800003                 be      loc_F0082B3C
F0082B34: 900abffd                 and     %o2, -3, %o0
F0082B38: d027bfe8                 st      %o0, [%fp+var_18]
F0082B3C: d007bfe4                 ld      [%fp+var_1C], %o0
F0082B40: 80a22000                 cmp     %o0, 0
F0082B44: 0280005b                 be      loc_F0082CB0
F0082B48: d007bfe8                 ld      [%fp+var_18], %o0
F0082B4C: c607bfc4                 ld      [%fp+var_3C], %g3
F0082B50: 80a20003                 cmp     %o0, %g3
F0082B54: 02800057                 be      loc_F0082CB0
F0082B58: 13200000                 sethi   0x80000000, %o1
F0082B5C: d0046020                 ld      [%l1+0x20], %o0
F0082B60: 922a0009                 andn    %o0, %o1, %o1
F0082B64: 11100000                 sethi   0x40000000, %o0
F0082B68: 808a4008                 btst    %o0, %o1
F0082B6C: 02800008                 be      loc_F0082B8C
F0082B70: d2246020                 st      %o1, [%l1+0x20]
F0082B74: 902a4008                 andn    %o1, %o0, %o0
F0082B78: d0246020                 st      %o0, [%l1+0x20]
F0082B7C: 90100011                 mov     %l1, %o0
F0082B80: 92102000                 mov     0, %o1
F0082B84: 7fffb91e                 call    _thread_wakeup_prim
F0082B88: 94102000                 mov     0, %o2
F0082B8C: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0082B94: d0040000                 ld      [%l0], %o0
F0082B98: 80a22000                 cmp     %o0, 0
F0082B9C: 12bffffe                 bne     loc_F0082B94
F0082BA0: 01000000                 nop
F0082BA4: 400050c1                 call    _simple_lock_try
F0082BA8: 90100010                 mov     %l0, %o0
F0082BAC: 80a22000                 cmp     %o0, 0
F0082BB0: 02bffff9                 be      loc_F0082B94
F0082BB4: 01000000                 nop
F0082BB8: 40001b0b                 call    _vm_page_activate
F0082BBC: 90100011                 mov     %l1, %o0
F0082BC0: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0082BC4: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082BC8: d014a044                 lduh    [%l2+0x44], %o0
F0082BCC: c024a010                 clr     [%l2+0x10]
F0082BD0: d207bff0                 ld      [%fp+var_10], %o1
F0082BD4: 90023fff                 inc     -1, %o0
F0082BD8: 80a48009                 cmp     %l2, %o1
F0082BDC: 0280002c                 be      loc_F0082C8C
F0082BE0: d034a044                 sth     %o0, [%l2+0x44]
F0082BE4: a0026010                 add     %o1, 0x10, %l0
F0082BE8: d0040000                 ld      [%l0], %o0
F0082BEC: 80a22000                 cmp     %o0, 0
F0082BF0: 12bffffe                 bne     loc_F0082BE8
F0082BF4: 01000000                 nop
F0082BF8: 400050ac                 call    _simple_lock_try
F0082BFC: 90100010                 mov     %l0, %o0
F0082C00: 80a22000                 cmp     %o0, 0
F0082C04: 02bffff9                 be      loc_F0082BE8
F0082C08: 13200000                 sethi   0x80000000, %o1
F0082C0C: d004e020                 ld      [%l3+0x20], %o0
F0082C10: 922a0009                 andn    %o0, %o1, %o1
F0082C14: 11100000                 sethi   0x40000000, %o0
F0082C18: 808a4008                 btst    %o0, %o1
F0082C1C: 02800008                 be      loc_F0082C3C
F0082C20: d224e020                 st      %o1, [%l3+0x20]
F0082C24: 902a4008                 andn    %o1, %o0, %o0
F0082C28: d024e020                 st      %o0, [%l3+0x20]
F0082C2C: 90100013                 mov     %l3, %o0
F0082C30: 92102000                 mov     0, %o1
F0082C34: 7fffb8f2                 call    _thread_wakeup_prim
F0082C38: 94102000                 mov     0, %o2
F0082C3C: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0082C44: d0040000                 ld      [%l0], %o0
F0082C48: 80a22000                 cmp     %o0, 0
F0082C4C: 12bffffe                 bne     loc_F0082C44
F0082C50: 01000000                 nop
F0082C54: 40005095                 call    _simple_lock_try
F0082C58: 90100010                 mov     %l0, %o0
F0082C5C: 80a22000                 cmp     %o0, 0
F0082C60: 02bffff9                 be      loc_F0082C44
F0082C64: 01000000                 nop
F0082C68: 400019c4                 call    _vm_page_free
F0082C6C: 90100013                 mov     %l3, %o0
F0082C70: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0082C74: d207bff0                 ld      [%fp+var_10], %o1
F0082C78: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082C7C: d0126044                 lduh    [%o1+0x44], %o0
F0082C80: c0226010                 clr     [%o1+0x10]
F0082C84: 90023fff                 inc     -1, %o0
F0082C88: d0326044                 sth     %o0, [%o1+0x44]
F0082C8C: 80a6e000                 cmp     %i3, 0
F0082C90: 02800004                 be      loc_F0082CA0
F0082C94: d007a044                 ld      [%fp+arg_44], %o0
F0082C98: 40000cf7                 call    _vm_map_lookup_done
F0082C9C: d207bff4                 ld      [%fp+var_C], %o1
F0082CA0: 40000f06                 call    _vm_object_deallocate
F0082CA4: d007bff0                 ld      [%fp+var_10], %o0
F0082CA8: 10bff985                 ba      loc_F00812BC
F0082CAC: 9007bfe8                 add     %fp, var_18, %o0
F0082CB0: 808a2002                 btst    2, %o0
F0082CB4: 02800005                 be      loc_F0082CC8
F0082CB8: 11000800                 sethi   0x200000, %o0
F0082CBC: d2046020                 ld      [%l1+0x20], %o1
F0082CC0: 902a4008                 andn    %o1, %o0, %o0
F0082CC4: d0246020                 st      %o0, [%l1+0x20]
F0082CC8: d204601c                 ld      [%l1+0x1C], %o1
F0082CCC: 11000030                 sethi   0xC000, %o0
F0082CD0: 808a4008                 btst    %o0, %o1
F0082CD4: 02800004                 be      loc_F0082CE4
F0082CD8: 113c0446                 sethi   %hi(aVmFaultActiveO_1), %o0! "vm_fault: active or inactive before pma"...
F0082CDC: 7ffe4925                 call    _panic
F0082CE0: 90122128                 bset    %lo(aVmFaultActiveO_1), %o0! "vm_fault: active or inactive before pma"...
F0082CE4: c024a010                 clr     [%l2+0x10]
F0082CE8: d4046024                 ld      [%l1+0x24], %o2
F0082CEC: d807bfe4                 ld      [%fp+var_1C], %o4
F0082CF0: c407a044                 ld      [%fp+arg_44], %g2
F0082CF4: d207bfcc                 ld      [%fp+var_34], %o1
F0082CF8: da046028                 ld      [%l1+0x28], %o5
F0082CFC: 9004a010                 add     %l2, 0x10, %o0
F0082D00: d607bfe8                 ld      [%fp+var_18], %o3
F0082D04: a0100008                 mov     %o0, %l0
F0082D08: d000a024                 ld      [%g2+0x24], %o0
F0082D0C: 40006de8                 call    _pmap_enter
F0082D10: 962ac00d                 bclr    %o5, %o3
F0082D14: d0040000                 ld      [%l0], %o0
F0082D18: 80a22000                 cmp     %o0, 0
F0082D1C: 12bffffe                 bne     loc_F0082D14
F0082D20: 01000000                 nop
F0082D24: 40005061                 call    _simple_lock_try
F0082D28: 90100010                 mov     %l0, %o0
F0082D2C: 80a22000                 cmp     %o0, 0
F0082D30: 02bffff9                 be      loc_F0082D14
F0082D34: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0082D38: a0122230                 or      %o0, %lo(_vm_page_queue_lock), %l0
F0082D3C: d0040000                 ld      [%l0], %o0
F0082D40: 80a22000                 cmp     %o0, 0
F0082D44: 12bffffe                 bne     loc_F0082D3C
F0082D48: 01000000                 nop
F0082D4C: 40005057                 call    _simple_lock_try
F0082D50: 90100010                 mov     %l0, %o0
F0082D54: 80a22000                 cmp     %o0, 0
F0082D58: 02bffff9                 be      loc_F0082D3C
F0082D5C: c607bfbc                 ld      [%fp+var_44], %g3
F0082D60: 80a0e000                 cmp     %g3, 0
F0082D64: 0280000d                 be      loc_F0082D98
F0082D68: d007bfe4                 ld      [%fp+var_1C], %o0
F0082D6C: 80a22000                 cmp     %o0, 0
F0082D70: 02800006                 be      loc_F0082D88
F0082D74: 01000000                 nop
F0082D78: 400019e6                 call    _vm_page_wire
F0082D7C: 90100011                 mov     %l1, %o0
F0082D80: 10800009                 ba      loc_F0082DA4
F0082D84: 113c04f0                 sethi   -0xFEC4000, %o0
F0082D88: 40001a32                 call    _vm_page_unwire
F0082D8C: 90100011                 mov     %l1, %o0
F0082D90: 10800005                 ba      loc_F0082DA4
F0082D94: 113c04f0                 sethi   -0xFEC4000, %o0
F0082D98: 40001a93                 call    _vm_page_activate
F0082D9C: 90100011                 mov     %l1, %o0
F0082DA0: 113c04f0                 sethi   -0xFEC4000, %o0
F0082DA4: c0222230                 clr     [%o0+0x230]
F0082DA8: d2046020                 ld      [%l1+0x20], %o1
F0082DAC: 11200000                 sethi   0x80000000, %o0
F0082DB0: 922a4008                 bclr    %o0, %o1
F0082DB4: 11100000                 sethi   0x40000000, %o0
F0082DB8: 808a4008                 btst    %o0, %o1
F0082DBC: 02800008                 be      loc_F0082DDC
F0082DC0: d2246020                 st      %o1, [%l1+0x20]
F0082DC4: 902a4008                 andn    %o1, %o0, %o0
F0082DC8: d0246020                 st      %o0, [%l1+0x20]
F0082DCC: 90100011                 mov     %l1, %o0
F0082DD0: 92102000                 mov     0, %o1
F0082DD4: 7fffb88a                 call    _thread_wakeup_prim
F0082DD8: 94102000                 mov     0, %o2
F0082DDC: d014a044                 lduh    [%l2+0x44], %o0
F0082DE0: c024a010                 clr     [%l2+0x10]
F0082DE4: d207bff0                 ld      [%fp+var_10], %o1
F0082DE8: 90023fff                 inc     -1, %o0
F0082DEC: 80a48009                 cmp     %l2, %o1
F0082DF0: 0280002c                 be      loc_F0082EA0
F0082DF4: d034a044                 sth     %o0, [%l2+0x44]
F0082DF8: a0026010                 add     %o1, 0x10, %l0
F0082DFC: d0040000                 ld      [%l0], %o0
F0082E00: 80a22000                 cmp     %o0, 0
F0082E04: 12bffffe                 bne     loc_F0082DFC
F0082E08: 01000000                 nop
F0082E0C: 40005027                 call    _simple_lock_try
F0082E10: 90100010                 mov     %l0, %o0
F0082E14: 80a22000                 cmp     %o0, 0
F0082E18: 02bffff9                 be      loc_F0082DFC
F0082E1C: 13200000                 sethi   0x80000000, %o1
F0082E20: d004e020                 ld      [%l3+0x20], %o0
F0082E24: 922a0009                 andn    %o0, %o1, %o1
F0082E28: 11100000                 sethi   0x40000000, %o0
F0082E2C: 808a4008                 btst    %o0, %o1
F0082E30: 02800008                 be      loc_F0082E50
F0082E34: d224e020                 st      %o1, [%l3+0x20]
F0082E38: 902a4008                 andn    %o1, %o0, %o0
F0082E3C: d024e020                 st      %o0, [%l3+0x20]
F0082E40: 90100013                 mov     %l3, %o0
F0082E44: 92102000                 mov     0, %o1
F0082E48: 7fffb86d                 call    _thread_wakeup_prim
F0082E4C: 94102000                 mov     0, %o2
F0082E50: 113c04f0a0122230         set     _vm_page_queue_lock, %l0
F0082E58: d0040000                 ld      [%l0], %o0
F0082E5C: 80a22000                 cmp     %o0, 0
F0082E60: 12bffffe                 bne     loc_F0082E58
F0082E64: 01000000                 nop
F0082E68: 40005010                 call    _simple_lock_try
F0082E6C: 90100010                 mov     %l0, %o0
F0082E70: 80a22000                 cmp     %o0, 0
F0082E74: 02bffff9                 be      loc_F0082E58
F0082E78: 01000000                 nop
F0082E7C: 4000193f                 call    _vm_page_free
F0082E80: 90100013                 mov     %l3, %o0
F0082E84: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F0082E88: d207bff0                 ld      [%fp+var_10], %o1
F0082E8C: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F0082E90: d0126044                 lduh    [%o1+0x44], %o0
F0082E94: c0226010                 clr     [%o1+0x10]
F0082E98: 90023fff                 inc     -1, %o0
F0082E9C: d0326044                 sth     %o0, [%o1+0x44]
F0082EA0: 80a6e000                 cmp     %i3, 0
F0082EA4: 02800004                 be      loc_F0082EB4
F0082EA8: d007a044                 ld      [%fp+arg_44], %o0
F0082EAC: 40000c72                 call    _vm_map_lookup_done
F0082EB0: d207bff4                 ld      [%fp+var_C], %o1
F0082EB4: 40000e81                 call    _vm_object_deallocate
F0082EB8: d007bff0                 ld      [%fp+var_10], %o0
F0082EBC: b0102000                 mov     0, %i0
F0082EC0: 81c7e008                 ret
F0082EC4: 81e80000                 restore
