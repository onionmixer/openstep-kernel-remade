F0054060: 9de3bf50                 save    %sp, -0xB0, %sp
F0054064: 3b0007c0                 sethi   0x1F0000, %i5
F0054068: 39000040                 sethi   0x10000, %i4
F005406C: ae07bfb0                 add     %fp, var_50, %l7
F0054070: d0062010                 ld      [%i0+0x10], %o0
F0054074: 80a22000                 cmp     %o0, 0
F0054078: 02800012                 be      loc_F00540C0
F005407C: 90100018                 mov     %i0, %o0
F0054080: 40007315                 call    _assert_wait
F0054084: 92102000                 mov     0, %o1
F0054088: c0262008                 clr     [%i0+8]
F005408C: 400075ad                 call    _thread_block_with_continuation
F0054090: 90102000                 mov     0, %o0
F0054094: a0062008                 add     %i0, 8, %l0
F0054098: d0040000                 ld      [%l0], %o0
F005409C: 80a22000                 cmp     %o0, 0
F00540A0: 12bffffe                 bne     loc_F0054098
F00540A4: 01000000                 nop
F00540A8: 40010b80                 call    _simple_lock_try
F00540AC: 90100010                 mov     %l0, %o0
F00540B0: 80a22000                 cmp     %o0, 0
F00540B4: 02bffff9                 be      loc_F0054098
F00540B8: b0102000                 mov     0, %i0
F00540BC: 3080010f                 ba,a    locret_F00544F8
F00540C0: e206201c                 ld      [%i0+0x1C], %l1
F00540C4: ec062014                 ld      [%i0+0x14], %l6
F00540C8: ea044000                 ld      [%l1], %l5
F00540CC: b2047ffc                 add     %l1, -4, %i1
F00540D0: e8047ffc                 ld      [%l1-4], %l4
F00540D4: b4046004                 add     %l1, 4, %i2
F00540D8: 80a50015                 cmp     %l4, %l5
F00540DC: 12800005                 bne     loc_F00540F0
F00540E0: f6046004                 ld      [%l1+4], %i3
F00540E4: c0262008                 clr     [%i0+8]
F00540E8: 10800104                 ba      locret_F00544F8
F00540EC: b0102003                 mov     3, %i0
F00540F0: 90102001                 mov     1, %o0
F00540F4: d0262010                 st      %o0, [%i0+0x10]
F00540F8: c0262008                 clr     [%i0+8]
F00540FC: d2047ffc                 ld      [%l1-4], %o1
F0054100: 113c0447                 sethi   %hi(_page_size), %o0
F0054104: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F0054108: 932a6004                 sll     %o1, 4, %o1
F005410C: 80a24008                 cmp     %o1, %o0
F0054110: 2a800009                 bcs,a   loc_F0054134
F0054114: d0044000                 ld      [%l1], %o0
F0054118: 90100009                 mov     %o1, %o0
F005411C: d4044000                 ld      [%l1], %o2
F0054120: 92100016                 mov     %l6, %o1
F0054124: 40002afd                 call    _ipc_table_realloc
F0054128: 952aa004                 sll     %o2, 4, %o2
F005412C: 10800005                 ba      loc_F0054140
F0054130: a6100008                 mov     %o0, %l3
F0054134: 40002ae5                 call    _ipc_table_alloc
F0054138: 912a2004                 sll     %o0, 4, %o0
F005413C: a6100008                 mov     %o0, %l3
F0054140: a0062008                 add     %i0, 8, %l0
F0054144: d0040000                 ld      [%l0], %o0
F0054148: 80a22000                 cmp     %o0, 0
F005414C: 12bffffe                 bne     loc_F0054144
F0054150: 01000000                 nop
F0054154: 40010b55                 call    _simple_lock_try
F0054158: 90100010                 mov     %l0, %o0
F005415C: 80a22000                 cmp     %o0, 0
F0054160: 02bffff9                 be      loc_F0054144
F0054164: 80a4e000                 cmp     %l3, 0
F0054168: 12800009                 bne     loc_F005418C
F005416C: c0262010                 clr     [%i0+0x10]
F0054170: c0262008                 clr     [%i0+8]
F0054174: 90100018                 mov     %i0, %o0
F0054178: 92102000                 mov     0, %o1
F005417C: 400073a0                 call    _thread_wakeup_prim
F0054180: 94102000                 mov     0, %o2
F0054184: 108000dd                 ba      locret_F00544F8
F0054188: b0102006                 mov     6, %i0
F005418C: d006200c                 ld      [%i0+0xC], %o0
F0054190: 80a22000                 cmp     %o0, 0
F0054194: 32800016                 bne,a   loc_F00541EC
F0054198: e6262014                 st      %l3, [%i0+0x14]
F005419C: c0262008                 clr     [%i0+8]
F00541A0: 90100018                 mov     %i0, %o0
F00541A4: 92102000                 mov     0, %o1
F00541A8: 40007395                 call    _thread_wakeup_prim
F00541AC: 94102000                 mov     0, %o2! size_t
F00541B0: 92100013                 mov     %l3, %o1
F00541B4: d0044000                 ld      [%l1], %o0
F00541B8: a0062008                 add     %i0, 8, %l0
F00541BC: 40002ae5                 call    _ipc_table_free
F00541C0: 912a2004                 sll     %o0, 4, %o0
F00541C4: d0040000                 ld      [%l0], %o0
F00541C8: 80a22000                 cmp     %o0, 0
F00541CC: 12bffffe                 bne     loc_F00541C4
F00541D0: 01000000                 nop
F00541D4: 40010b35                 call    _simple_lock_try
F00541D8: 90100010                 mov     %l0, %o0
F00541DC: 80a22000                 cmp     %o0, 0
F00541E0: 02bffff9                 be      loc_F00541C4
F00541E4: b0102000                 mov     0, %i0
F00541E8: 308000c4                 ba,a    locret_F00544F8
F00541EC: ea262018                 st      %l5, [%i0+0x18]
F00541F0: f426201c                 st      %i2, [%i0+0x1C]
F00541F4: d0064000                 ld      [%i1], %o0
F00541F8: 133c0447                 sethi   %hi(_page_size), %o1
F00541FC: d202613c                 ld      [%o1+%lo(_page_size)], %o1
F0054200: 912a2004                 sll     %o0, 4, %o0
F0054204: 80a20009                 cmp     %o0, %o1
F0054208: 1a800005                 bcc     loc_F005421C
F005420C: 90100016                 mov     %l6, %o0! void *
F0054210: 92100013                 mov     %l3, %o1! void *
F0054214: 4001023f                 call    _bcopy
F0054218: 952d2004                 sll     %l4, 4, %o2
F005421C: a0102000                 mov     0, %l0
F0054220: 80a40014                 cmp     %l0, %l4
F0054224: 1a800007                 bcc     loc_F0054240
F0054228: 90100013                 mov     %l3, %o0
F005422C: c022200c                 clr     [%o0+0xC]
F0054230: a0042001                 inc     %l0
F0054234: 80a40014                 cmp     %l0, %l4
F0054238: 0abffffd                 bcs     loc_F005422C
F005423C: 90022010                 inc     0x10, %o0
F0054240: 912d2004                 sll     %l4, 4, %o0
F0054244: 9004c008                 add     %l3, %o0, %o0! void *
F0054248: 92254014                 sub     %l5, %l4, %o1! size_t
F005424C: 40010303                 call    _bzero
F0054250: 932a6004                 sll     %o1, 4, %o1
F0054254: a0102000                 mov     0, %l0
F0054258: 80a40014                 cmp     %l0, %l4
F005425C: 3a800012                 bcc,a   loc_F00542A4
F0054260: d0062038                 ld      [%i0+0x38], %o0
F0054264: a2100013                 mov     %l3, %l1
F0054268: d0044000                 ld      [%l1], %o0
F005426C: 900a001d                 and     %o0, %i5, %o0
F0054270: 80a2001c                 cmp     %o0, %i4
F0054274: 32800008                 bne,a   loc_F0054294
F0054278: a0042001                 inc     %l0
F005427C: 90100018                 mov     %i0, %o0
F0054280: d2046004                 ld      [%l1+4], %o1
F0054284: 94100010                 mov     %l0, %o2
F0054288: 40000188                 call    _ipc_hash_local_insert
F005428C: 96100011                 mov     %l1, %o3
F0054290: a0042001                 inc     %l0
F0054294: 80a40014                 cmp     %l0, %l4
F0054298: 0abffff4                 bcs     loc_F0054268
F005429C: a2046010                 inc     0x10, %l1
F00542A0: d0062038                 ld      [%i0+0x38], %o0
F00542A4: 80a22000                 cmp     %o0, 0
F00542A8: 0280005c                 be      loc_F0054418
F00542AC: 90062020                 add     %i0, 0x20, %o0 ! ' '
F00542B0: 932ee008                 sll     %i3, 8, %o1
F00542B4: 400028c3                 call    _ipc_splay_tree_split
F00542B8: 94100017                 mov     %l7, %o2
F00542BC: 90100017                 mov     %l7, %o0
F00542C0: 932d6008                 sll     %l5, 8, %o1
F00542C4: a007bfc8                 add     %fp, var_38, %l0
F00542C8: 400028be                 call    _ipc_splay_tree_split
F00542CC: 94100010                 mov     %l0, %o2
F00542D0: 90100010                 mov     %l0, %o0
F00542D4: 932d2008                 sll     %l4, 8, %o1
F00542D8: 400028ba                 call    _ipc_splay_tree_split
F00542DC: 9407bfe0                 add     %fp, var_20, %o2
F00542E0: 4000297c                 call    _ipc_splay_traverse_start
F00542E4: 90100010                 mov     %l0, %o0
F00542E8: 10800027                 ba      loc_F0054384
F00542EC: 96100008                 mov     %o0, %o3
F00542F0: a532a008                 srl     %o2, 8, %l2
F00542F4: 992ca004                 sll     %l2, 4, %o4
F00542F8: 912aa018                 sll     %o2, 24, %o0
F00542FC: d204c00c                 ld      [%l3+%o4], %o1
F0054300: 80a26000                 cmp     %o1, 0
F0054304: 02800007                 be      loc_F0054320
F0054308: a204c00c                 add     %l3, %o4, %l1
F005430C: 1b002000                 sethi   0x800000, %o5
F0054310: 9012400d                 or      %o1, %o5, %o0
F0054314: d024c00c                 st      %o0, [%l3+%o4]
F0054318: 10800018                 ba      loc_F0054378
F005431C: 92102000                 mov     0, %o1
F0054320: d202c000                 ld      [%o3], %o1
F0054324: 90124008                 bset    %o1, %o0
F0054328: d024c00c                 st      %o0, [%l3+%o4]
F005432C: e002e004                 ld      [%o3+4], %l0
F0054330: 900a401d                 and     %o1, %i5, %o0
F0054334: e0246004                 st      %l0, [%l1+4]
F0054338: d202e008                 ld      [%o3+8], %o1
F005433C: 80a2001c                 cmp     %o0, %i4
F0054340: 1280000a                 bne     loc_F0054368
F0054344: d2246008                 st      %o1, [%l1+8]
F0054348: 90100018                 mov     %i0, %o0
F005434C: 40000106                 call    _ipc_hash_global_delete
F0054350: 92100010                 mov     %l0, %o1
F0054354: 90100018                 mov     %i0, %o0
F0054358: 92100010                 mov     %l0, %o1
F005435C: 94100012                 mov     %l2, %o2
F0054360: 40000152                 call    _ipc_hash_local_insert
F0054364: 96100011                 mov     %l1, %o3
F0054368: d0062038                 ld      [%i0+0x38], %o0
F005436C: 92102001                 mov     1, %o1
F0054370: 90023fff                 inc     -1, %o0
F0054374: d0262038                 st      %o0, [%i0+0x38]
F0054378: 40002971                 call    _ipc_splay_traverse_next
F005437C: 9007bfc8                 add     %fp, var_38, %o0
F0054380: 96100008                 mov     %o0, %o3
F0054384: 80a2e000                 cmp     %o3, 0
F0054388: 32bfffda                 bne,a   loc_F00542F0
F005438C: d402e010                 ld      [%o3+0x10], %o2
F0054390: 400029e9                 call    _ipc_splay_traverse_finish
F0054394: 9007bfc8                 add     %fp, var_38, %o0
F0054398: a0102000                 mov     0, %l0
F005439C: a4102000                 mov     0, %l2
F00543A0: 4000294c                 call    _ipc_splay_traverse_start
F00543A4: 9007bfb0                 add     %fp, var_50, %o0
F00543A8: 1080000c                 ba      loc_F00543D8
F00543AC: 96100008                 mov     %o0, %o3
F00543B0: 91322008                 srl     %o0, 8, %o0
F00543B4: 80a20012                 cmp     %o0, %l2
F00543B8: 22800005                 be,a    loc_F00543CC
F00543BC: 9007bfb0                 add     %fp, var_50, %o0
F00543C0: a0042001                 inc     %l0
F00543C4: a4100008                 mov     %o0, %l2
F00543C8: 9007bfb0                 add     %fp, var_50, %o0
F00543CC: 4000295c                 call    _ipc_splay_traverse_next
F00543D0: 92102000                 mov     0, %o1
F00543D4: 96100008                 mov     %o0, %o3
F00543D8: 80a2e000                 cmp     %o3, 0
F00543DC: 32bffff5                 bne,a   loc_F00543B0
F00543E0: d002e010                 ld      [%o3+0x10], %o0
F00543E4: 400029d4                 call    _ipc_splay_traverse_finish
F00543E8: 90100017                 mov     %l7, %o0
F00543EC: e026203c                 st      %l0, [%i0+0x3C]
F00543F0: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00543F4: 90100010                 mov     %l0, %o0
F00543F8: 400028c1                 call    _ipc_splay_tree_join
F00543FC: 92100017                 mov     %l7, %o1
F0054400: 90100010                 mov     %l0, %o0
F0054404: 400028be                 call    _ipc_splay_tree_join
F0054408: 9207bfc8                 add     %fp, var_38, %o1
F005440C: 90100010                 mov     %l0, %o0
F0054410: 400028bb                 call    _ipc_splay_tree_join
F0054414: 9207bfe0                 add     %fp, var_20, %o1
F0054418: a0057fff                 add     %l5, -1, %l0
F005441C: 80a40014                 cmp     %l0, %l4
F0054420: 0a800010                 bcs     loc_F0054460
F0054424: d404e008                 ld      [%l3+8], %o2
F0054428: 173fc000                 sethi   -0x1000000, %o3
F005442C: 912c2004                 sll     %l0, 4, %o0
F0054430: 92020013                 add     %o0, %l3, %o1
F0054434: d0024000                 ld      [%o1], %o0
F0054438: 80a22000                 cmp     %o0, 0
F005443C: 32800006                 bne,a   loc_F0054454
F0054440: a0043fff                 inc     -1, %l0
F0054444: d6224000                 st      %o3, [%o1]
F0054448: d4226008                 st      %o2, [%o1+8]
F005444C: 94100010                 mov     %l0, %o2
F0054450: a0043fff                 inc     -1, %l0
F0054454: 80a40014                 cmp     %l0, %l4
F0054458: 1abffff7                 bcc     loc_F0054434
F005445C: 92027ff0                 inc     -0x10, %o1
F0054460: d424e008                 st      %o2, [%l3+8]
F0054464: c0262008                 clr     [%i0+8]
F0054468: 90100018                 mov     %i0, %o0
F005446C: 92102000                 mov     0, %o1
F0054470: 400072e3                 call    _thread_wakeup_prim
F0054474: 94102000                 mov     0, %o2
F0054478: 92100016                 mov     %l6, %o1
F005447C: d0064000                 ld      [%i1], %o0
F0054480: a0062008                 add     %i0, 8, %l0
F0054484: 40002a33                 call    _ipc_table_free
F0054488: 912a2004                 sll     %o0, 4, %o0
F005448C: d0040000                 ld      [%l0], %o0
F0054490: 80a22000                 cmp     %o0, 0
F0054494: 12bffffe                 bne     loc_F005448C
F0054498: 01000000                 nop
F005449C: 40010a83                 call    _simple_lock_try
F00544A0: 90100010                 mov     %l0, %o0
F00544A4: 80a22000                 cmp     %o0, 0
F00544A8: 02bffff9                 be      loc_F005448C
F00544AC: 01000000                 nop
F00544B0: d006200c                 ld      [%i0+0xC], %o0
F00544B4: 80a22000                 cmp     %o0, 0
F00544B8: 22800010                 be,a    locret_F00544F8
F00544BC: b0102000                 mov     0, %i0
F00544C0: d006201c                 ld      [%i0+0x1C], %o0
F00544C4: 80a2001a                 cmp     %o0, %i2
F00544C8: 3280000c                 bne,a   locret_F00544F8
F00544CC: b0102000                 mov     0, %i0
F00544D0: d206203c                 ld      [%i0+0x3C], %o1
F00544D4: 80a26000                 cmp     %o1, 0
F00544D8: 02800007                 be      loc_F00544F4
F00544DC: 9026c015                 sub     %i3, %l5, %o0
F00544E0: 912a2004                 sll     %o0, 4, %o0
F00544E4: 932a6005                 sll     %o1, 5, %o1
F00544E8: 80a20009                 cmp     %o0, %o1
F00544EC: 2abffee2                 bcs,a   loc_F0054074
F00544F0: d0062010                 ld      [%i0+0x10], %o0
F00544F4: b0102000                 mov     0, %i0
F00544F8: 81c7e008                 ret
F00544FC: 81e80000                 restore
