F0056410: 9de3bf88                 save    %sp, -0x78, %sp
F0056414: a6100018                 mov     %i0, %l3
F0056418: e804c000                 ld      [%l3], %l4
F005641C: 80a6a000                 cmp     %i2, 0
F0056420: 128000d8                 bne     loc_F0056780
F0056424: e204e008                 ld      [%l3+8], %l1
F0056428: 1100003f901223ff         set     0xFFFF, %o0
F0056430: 920d0008                 and     %l4, %o0, %o1
F0056434: 80a26012                 cmp     %o1, 0x12
F0056438: 028000a4                 be      loc_F00566C8
F005643C: 01000000                 nop
F0056440: 18800006                 bgu     loc_F0056458
F0056444: 80a26011                 cmp     %o1, 0x11
F0056448: 0280000b                 be      loc_F0056474
F005644C: 01000000                 nop
F0056450: 108000cd                 ba      loc_F0056784
F0056454: e004e00c                 ld      [%l3+0xC], %l0
F0056458: 1100000490122211         set     0x1211, %o0
F0056460: 80a24008                 cmp     %o1, %o0
F0056464: 02800032                 be      loc_F005652C
F0056468: e004e00c                 ld      [%l3+0xC], %l0
F005646C: 108000c7                 ba      loc_F0056788
F0056470: ac0d20ff                 and     %l4, 0xFF, %l6
F0056474: d0044000                 ld      [%l1], %o0
F0056478: 80a22000                 cmp     %o0, 0
F005647C: 12bffffe                 bne     loc_F0056474
F0056480: 01000000                 nop
F0056484: 40010289                 call    _simple_lock_try
F0056488: 90100011                 mov     %l1, %o0
F005648C: 80a22000                 cmp     %o0, 0
F0056490: 02bffff9                 be      loc_F0056474
F0056494: 01000000                 nop
F0056498: d0046008                 ld      [%l1+8], %o0
F005649C: 80a22000                 cmp     %o0, 0
F00564A0: 16800097                 bge     loc_F00566FC
F00564A4: 01000000                 nop
F00564A8: d0046004                 ld      [%l1+4], %o0
F00564AC: 90023fff                 inc     -1, %o0
F00564B0: d0246004                 st      %o0, [%l1+4]
F00564B4: d004600c                 ld      [%l1+0xC], %o0
F00564B8: 80a20019                 cmp     %o0, %i1
F00564BC: 12800003                 bne     loc_F00564C8
F00564C0: a0102000                 mov     0, %l0
F00564C4: e0046010                 ld      [%l1+0x10], %l0
F00564C8: d004601c                 ld      [%l1+0x1C], %o0
F00564CC: 90023fff                 inc     -1, %o0
F00564D0: 80a22000                 cmp     %o0, 0
F00564D4: 1280000d                 bne     loc_F0056508
F00564D8: d024601c                 st      %o0, [%l1+0x1C]
F00564DC: d0046024                 ld      [%l1+0x24], %o0
F00564E0: 80a22000                 cmp     %o0, 0
F00564E4: 02800009                 be      loc_F0056508
F00564E8: 01000000                 nop
F00564EC: c0246024                 clr     [%l1+0x24]
F00564F0: d2046018                 ld      [%l1+0x18], %o1
F00564F4: c0244000                 clr     [%l1]
F00564F8: 40000b43                 call    _ipc_notify_no_senders
F00564FC: 01000000                 nop
F0056500: 10800004                 ba      loc_F0056510
F0056504: 133fffc0                 sethi   -0x10000, %o1
F0056508: c0244000                 clr     [%l1]
F005650C: 133fffc0                 sethi   -0x10000, %o1
F0056510: 920d0009                 and     %l4, %o1, %o1
F0056514: 1100000490122100         set     0x1100, %o0
F005651C: 92124008                 bset    %o0, %o1
F0056520: d224c000                 st      %o1, [%l3]
F0056524: 10800091                 ba      loc_F0056768
F0056528: e024e00c                 st      %l0, [%l3+0xC]
F005652C: 80a42000                 cmp     %l0, 0
F0056530: 02800094                 be      loc_F0056780
F0056534: 80a43fff                 cmp     %l0, -1
F0056538: 02800092                 be      loc_F0056780
F005653C: b0066008                 add     %i1, 8, %i0
F0056540: d0060000                 ld      [%i0], %o0
F0056544: 80a22000                 cmp     %o0, 0
F0056548: 12bffffe                 bne     loc_F0056540
F005654C: 01000000                 nop
F0056550: 40010256                 call    _simple_lock_try
F0056554: 90100018                 mov     %i0, %o0
F0056558: 80a22000                 cmp     %o0, 0
F005655C: 02bffff9                 be      loc_F0056540
F0056560: 01000000                 nop
F0056564: d006600c                 ld      [%i1+0xC], %o0
F0056568: 80a22000                 cmp     %o0, 0
F005656C: 0280001f                 be      loc_F00565E8
F0056570: 01000000                 nop
F0056574: f0066014                 ld      [%i1+0x14], %i0
F0056578: e4062008                 ld      [%i0+8], %l2
F005657C: 80a4a000                 cmp     %l2, 0
F0056580: 0280001a                 be      loc_F00565E8
F0056584: 01000000                 nop
F0056588: d0044000                 ld      [%l1], %o0
F005658C: 80a22000                 cmp     %o0, 0
F0056590: 12bffffe                 bne     loc_F0056588
F0056594: 01000000                 nop
F0056598: 40010244                 call    _simple_lock_try
F005659C: 90100011                 mov     %l1, %o0
F00565A0: 80a22000                 cmp     %o0, 0
F00565A4: 02bffff9                 be      loc_F0056588
F00565A8: 01000000                 nop
F00565AC: d0046008                 ld      [%l1+8], %o0
F00565B0: 80a22000                 cmp     %o0, 0
F00565B4: 1680000c                 bge     loc_F00565E4
F00565B8: 01000000                 nop
F00565BC: 4001023b                 call    _simple_lock_try
F00565C0: 90100010                 mov     %l0, %o0
F00565C4: 80a22000                 cmp     %o0, 0
F00565C8: 02800007                 be      loc_F00565E4
F00565CC: 01000000                 nop
F00565D0: d0042008                 ld      [%l0+8], %o0
F00565D4: 80a22000                 cmp     %o0, 0
F00565D8: 06800007                 bl      loc_F00565F4
F00565DC: 01000000                 nop
F00565E0: c0240000                 clr     [%l0]
F00565E4: c0244000                 clr     [%l1]
F00565E8: c0266008                 clr     [%i1+8]
F00565EC: 10800066                 ba      loc_F0056784
F00565F0: e004e00c                 ld      [%l3+0xC], %l0
F00565F4: c0240000                 clr     [%l0]
F00565F8: 952ca004                 sll     %l2, 4, %o2
F00565FC: 9606000a                 add     %i0, %o2, %o3
F0056600: d002e008                 ld      [%o3+8], %o0
F0056604: d0262008                 st      %o0, [%i0+8]
F0056608: c022e008                 clr     [%o3+8]
F005660C: d206000a                 ld      [%i0+%o2], %o1
F0056610: 11004000                 sethi   0x1000000, %o0
F0056614: 92024008                 add     %o1, %o0, %o1
F0056618: 1100010090122001         set     0x40001, %o0
F0056620: 90124008                 bset    %o1, %o0
F0056624: d026000a                 st      %o0, [%i0+%o2]
F0056628: e022e004                 st      %l0, [%o3+4]
F005662C: c0266008                 clr     [%i1+8]
F0056630: 912ca008                 sll     %l2, 8, %o0
F0056634: 93326018                 srl     %o1, 24, %o1
F0056638: a4120009                 or      %o0, %o1, %l2
F005663C: d0046004                 ld      [%l1+4], %o0
F0056640: 90023fff                 inc     -1, %o0
F0056644: d0246004                 st      %o0, [%l1+4]
F0056648: d004600c                 ld      [%l1+0xC], %o0
F005664C: 80a20019                 cmp     %o0, %i1
F0056650: 12800003                 bne     loc_F005665C
F0056654: a0102000                 mov     0, %l0
F0056658: e0046010                 ld      [%l1+0x10], %l0
F005665C: d004601c                 ld      [%l1+0x1C], %o0
F0056660: 90023fff                 inc     -1, %o0
F0056664: 80a22000                 cmp     %o0, 0
F0056668: 1280000d                 bne     loc_F005669C
F005666C: d024601c                 st      %o0, [%l1+0x1C]
F0056670: d0046024                 ld      [%l1+0x24], %o0
F0056674: 80a22000                 cmp     %o0, 0
F0056678: 02800009                 be      loc_F005669C
F005667C: 01000000                 nop
F0056680: c0246024                 clr     [%l1+0x24]
F0056684: d2046018                 ld      [%l1+0x18], %o1
F0056688: c0244000                 clr     [%l1]
F005668C: 40000ade                 call    _ipc_notify_no_senders
F0056690: 01000000                 nop
F0056694: 10800004                 ba      loc_F00566A4
F0056698: 133fffc0                 sethi   -0x10000, %o1
F005669C: c0244000                 clr     [%l1]
F00566A0: 133fffc0                 sethi   -0x10000, %o1
F00566A4: 920d0009                 and     %l4, %o1, %o1
F00566A8: 1100000490122112         set     0x1112, %o0
F00566B0: 92124008                 bset    %o0, %o1
F00566B4: d224c000                 st      %o1, [%l3]
F00566B8: e024e00c                 st      %l0, [%l3+0xC]
F00566BC: e424e008                 st      %l2, [%l3+8]
F00566C0: 10800172                 ba      locret_F0056C88
F00566C4: b0102000                 mov     0, %i0
F00566C8: d0044000                 ld      [%l1], %o0
F00566CC: 80a22000                 cmp     %o0, 0
F00566D0: 12bffffe                 bne     loc_F00566C8
F00566D4: 01000000                 nop
F00566D8: 400101f4                 call    _simple_lock_try
F00566DC: 90100011                 mov     %l1, %o0
F00566E0: 80a22000                 cmp     %o0, 0
F00566E4: 02bffff9                 be      loc_F00566C8
F00566E8: 01000000                 nop
F00566EC: d0046008                 ld      [%l1+8], %o0
F00566F0: 80a22000                 cmp     %o0, 0
F00566F4: 26800005                 bl,a    loc_F0056708
F00566F8: d004600c                 ld      [%l1+0xC], %o0
F00566FC: c0244000                 clr     [%l1]
F0056700: 10800021                 ba      loc_F0056784
F0056704: e004e00c                 ld      [%l3+0xC], %l0
F0056708: 80a20019                 cmp     %o0, %i1
F005670C: 1280000c                 bne     loc_F005673C
F0056710: 01000000                 nop
F0056714: d0046004                 ld      [%l1+4], %o0
F0056718: 90023fff                 inc     -1, %o0
F005671C: d0246004                 st      %o0, [%l1+4]
F0056720: d0046020                 ld      [%l1+0x20], %o0
F0056724: 90023fff                 inc     -1, %o0
F0056728: d0246020                 st      %o0, [%l1+0x20]
F005672C: d4046010                 ld      [%l1+0x10], %o2
F0056730: c0244000                 clr     [%l1]
F0056734: 10800007                 ba      loc_F0056750
F0056738: 133fffc0                 sethi   -0x10000, %o1
F005673C: c0244000                 clr     [%l1]
F0056740: 40000add                 call    _ipc_notify_send_once
F0056744: 90100011                 mov     %l1, %o0
F0056748: 94102000                 mov     0, %o2
F005674C: 133fffc0                 sethi   -0x10000, %o1
F0056750: 920d0009                 and     %l4, %o1, %o1
F0056754: 1100000490122200         set     0x1200, %o0
F005675C: 92124008                 bset    %o0, %o1
F0056760: d224c000                 st      %o1, [%l3]
F0056764: d424e00c                 st      %o2, [%l3+0xC]
F0056768: c024e008                 clr     [%l3+8]
F005676C: 10800147                 ba      locret_F0056C88
F0056770: b0102000                 mov     0, %i0
F0056774: d007bff0                 ld      [%fp+var_10], %o0
F0056778: 108000b0                 ba      loc_F0056A38
F005677C: e0222004                 st      %l0, [%o0+4]
F0056780: e004e00c                 ld      [%l3+0xC], %l0
F0056784: ac0d20ff                 and     %l4, 0xFF, %l6
F0056788: 1100003f90122300         set     0xFF00, %o0
F0056790: 900d0008                 and     %l4, %o0, %o0
F0056794: 80a42000                 cmp     %l0, 0
F0056798: 028000c3                 be      loc_F0056AA4
F005679C: ab322008                 srl     %o0, 8, %l5
F00567A0: 80a43fff                 cmp     %l0, -1
F00567A4: 028000c0                 be      loc_F0056AA4
F00567A8: b0066008                 add     %i1, 8, %i0
F00567AC: d0060000                 ld      [%i0], %o0
F00567B0: 80a22000                 cmp     %o0, 0
F00567B4: 12bffffe                 bne     loc_F00567AC
F00567B8: 01000000                 nop
F00567BC: 400101bb                 call    _simple_lock_try
F00567C0: 90100018                 mov     %i0, %o0
F00567C4: 80a22000                 cmp     %o0, 0
F00567C8: 02bffff9                 be      loc_F00567AC
F00567CC: 113c04ef                 sethi   %hi(_ipc_object_zones), %o0
F00567D0: a4122300                 or      %o0, %lo(_ipc_object_zones), %l2
F00567D4: d006600c                 ld      [%i1+0xC], %o0
F00567D8: 80a22000                 cmp     %o0, 0
F00567DC: 02800111                 be      loc_F0056C20
F00567E0: 80a6a000                 cmp     %i2, 0
F00567E4: 02800008                 be      loc_F0056804
F00567E8: 90100019                 mov     %i1, %o0
F00567EC: 400011df                 call    _ipc_port_lookup_notify
F00567F0: 9210001a                 mov     %i2, %o1
F00567F4: b0920000                 orcc    %o0, %g0, %i0
F00567F8: 12800005                 bne     loc_F005680C
F00567FC: 80a56012                 cmp     %l5, 0x12
F0056800: 308000c3                 ba,a    loc_F0056B0C
F0056804: b0102000                 mov     0, %i0
F0056808: 80a56012                 cmp     %l5, 0x12
F005680C: 02800009                 be      loc_F0056830
F0056810: 90100019                 mov     %i1, %o0
F0056814: 92100010                 mov     %l0, %o1
F0056818: 9407bff4                 add     %fp, var_C, %o2
F005681C: 400014b6                 call    _ipc_right_reverse
F0056820: 9607bff0                 add     %fp, var_10, %o3
F0056824: 80a22000                 cmp     %o0, 0
F0056828: 32800085                 bne,a   loc_F0056A3C
F005682C: d0042004                 ld      [%l0+4], %o0
F0056830: d0040000                 ld      [%l0], %o0
F0056834: 80a22000                 cmp     %o0, 0
F0056838: 12bffffe                 bne     loc_F0056830
F005683C: 01000000                 nop
F0056840: 4001019a                 call    _simple_lock_try
F0056844: 90100010                 mov     %l0, %o0
F0056848: 80a22000                 cmp     %o0, 0
F005684C: 02bffff9                 be      loc_F0056830
F0056850: 01000000                 nop
F0056854: d0042008                 ld      [%l0+8], %o0
F0056858: 80a22000                 cmp     %o0, 0
F005685C: 06800021                 bl      loc_F00568E0
F0056860: 90100019                 mov     %i1, %o0
F0056864: d0042004                 ld      [%l0+4], %o0
F0056868: 90023fff                 inc     -1, %o0
F005686C: d0242004                 st      %o0, [%l0+4]
F0056870: c0240000                 clr     [%l0]
F0056874: 80a22000                 cmp     %o0, 0
F0056878: 1280000a                 bne     loc_F00568A0
F005687C: 80a62000                 cmp     %i0, 0
F0056880: d0042008                 ld      [%l0+8], %o0
F0056884: 912a2001                 sll     %o0, 1, %o0
F0056888: 91322011                 srl     %o0, 17, %o0
F005688C: 912a2002                 sll     %o0, 2, %o0
F0056890: d0020012                 ld      [%o0+%l2], %o0
F0056894: 40008a4f                 call    _zfree
F0056898: 92100010                 mov     %l0, %o1
F005689C: 80a62000                 cmp     %i0, 0
F00568A0: 02800004                 be      loc_F00568B0
F00568A4: 01000000                 nop
F00568A8: 40001262                 call    _ipc_port_release_sonce
F00568AC: 90100018                 mov     %i0, %o0
F00568B0: d0044000                 ld      [%l1], %o0
F00568B4: 80a22000                 cmp     %o0, 0
F00568B8: 12bffffe                 bne     loc_F00568B0
F00568BC: 01000000                 nop
F00568C0: 4001017a                 call    _simple_lock_try
F00568C4: 90100011                 mov     %l1, %o0
F00568C8: 80a22000                 cmp     %o0, 0
F00568CC: 02bffff9                 be      loc_F00568B0
F00568D0: 01000000                 nop
F00568D4: c0266008                 clr     [%i1+8]
F00568D8: 1080009b                 ba      loc_F0056B44
F00568DC: a0103fff                 mov     -1, %l0
F00568E0: 9207bff4                 add     %fp, var_C, %o1
F00568E4: 7ffff477                 call    _ipc_entry_get
F00568E8: 9407bff0                 add     %fp, var_10, %o2
F00568EC: 80a22000                 cmp     %o0, 0
F00568F0: 02800012                 be      loc_F0056938
F00568F4: 80a62000                 cmp     %i0, 0
F00568F8: c0240000                 clr     [%l0]
F00568FC: 80a62000                 cmp     %i0, 0
F0056900: 02800004                 be      loc_F0056910
F0056904: 01000000                 nop
F0056908: 4000124a                 call    _ipc_port_release_sonce
F005690C: 90100018                 mov     %i0, %o0
F0056910: 7ffff5d4                 call    _ipc_entry_grow_table
F0056914: 90100019                 mov     %i1, %o0
F0056918: 80a22000                 cmp     %o0, 0
F005691C: 22bfffaf                 be,a    loc_F00567D8
F0056920: d006600c                 ld      [%i1+0xC], %o0
F0056924: 80a22006                 cmp     %o0, 6
F0056928: 228000c2                 be,a    loc_F0056C30
F005692C: 31040012                 sethi   0x10004800, %i0
F0056930: 108000be                 ba      loc_F0056C28
F0056934: 31040018                 sethi   0x10006000, %i0
F0056938: 02bfff8f                 be      loc_F0056774
F005693C: 90100010                 mov     %l0, %o0
F0056940: d207bff4                 ld      [%fp+var_C], %o1
F0056944: 94100018                 mov     %i0, %o2
F0056948: 40000ef1                 call    _ipc_port_dnrequest
F005694C: 9607bfec                 add     %fp, var_14, %o3
F0056950: 80a22000                 cmp     %o0, 0
F0056954: 02800035                 be      loc_F0056A28
F0056958: d207bff0                 ld      [%fp+var_10], %o1
F005695C: c0240000                 clr     [%l0]
F0056960: 40001234                 call    _ipc_port_release_sonce
F0056964: 90100018                 mov     %i0, %o0
F0056968: d207bff4                 ld      [%fp+var_C], %o1
F005696C: d407bff0                 ld      [%fp+var_10], %o2
F0056970: 7ffff542                 call    _ipc_entry_dealloc
F0056974: 90100019                 mov     %i1, %o0
F0056978: c0266008                 clr     [%i1+8]
F005697C: d0040000                 ld      [%l0], %o0
F0056980: 80a22000                 cmp     %o0, 0
F0056984: 12bffffe                 bne     loc_F005697C
F0056988: 01000000                 nop
F005698C: 40010147                 call    _simple_lock_try
F0056990: 90100010                 mov     %l0, %o0
F0056994: 80a22000                 cmp     %o0, 0
F0056998: 02bffff9                 be      loc_F005697C
F005699C: 01000000                 nop
F00569A0: d0042008                 ld      [%l0+8], %o0
F00569A4: 80a22000                 cmp     %o0, 0
F00569A8: 0680000f                 bl      loc_F00569E4
F00569AC: 01000000                 nop
F00569B0: c0240000                 clr     [%l0]
F00569B4: b0066008                 add     %i1, 8, %i0
F00569B8: d0060000                 ld      [%i0], %o0
F00569BC: 80a22000                 cmp     %o0, 0
F00569C0: 12bffffe                 bne     loc_F00569B8
F00569C4: 01000000                 nop
F00569C8: 40010138                 call    _simple_lock_try
F00569CC: 90100018                 mov     %i0, %o0
F00569D0: 80a22000                 cmp     %o0, 0
F00569D4: 02bffff9                 be      loc_F00569B8
F00569D8: 01000000                 nop
F00569DC: 10bfff7f                 ba      loc_F00567D8
F00569E0: d006600c                 ld      [%i1+0xC], %o0
F00569E4: 40000ede                 call    _ipc_port_dngrow
F00569E8: 90100010                 mov     %l0, %o0
F00569EC: 80a22000                 cmp     %o0, 0
F00569F0: 12800090                 bne     loc_F0056C30
F00569F4: 31040012                 sethi   0x10004800, %i0
F00569F8: b0066008                 add     %i1, 8, %i0
F00569FC: d0060000                 ld      [%i0], %o0
F0056A00: 80a22000                 cmp     %o0, 0
F0056A04: 12bffffe                 bne     loc_F00569FC
F0056A08: 01000000                 nop
F0056A0C: 40010127                 call    _simple_lock_try
F0056A10: 90100018                 mov     %i0, %o0
F0056A14: 80a22000                 cmp     %o0, 0
F0056A18: 02bffff9                 be      loc_F00569FC
F0056A1C: 01000000                 nop
F0056A20: 10bfff6e                 ba      loc_F00567D8
F0056A24: d006600c                 ld      [%i1+0xC], %o0
F0056A28: b0102000                 mov     0, %i0
F0056A2C: d007bfec                 ld      [%fp+var_14], %o0
F0056A30: e0226004                 st      %l0, [%o1+4]
F0056A34: d0226008                 st      %o0, [%o1+8]
F0056A38: d0042004                 ld      [%l0+4], %o0
F0056A3C: 90022001                 inc     %o0
F0056A40: d0242004                 st      %o0, [%l0+4]
F0056A44: 90100019                 mov     %i1, %o0
F0056A48: 96100015                 mov     %l5, %o3
F0056A4C: d207bff4                 ld      [%fp+var_C], %o1
F0056A50: 98102001                 mov     1, %o4
F0056A54: d407bff0                 ld      [%fp+var_10], %o2
F0056A58: 40001aaa                 call    _ipc_right_copyout
F0056A5C: 9a100010                 mov     %l0, %o5
F0056A60: 80a62000                 cmp     %i0, 0
F0056A64: 02800004                 be      loc_F0056A74
F0056A68: 01000000                 nop
F0056A6C: 400011f1                 call    _ipc_port_release_sonce
F0056A70: 90100018                 mov     %i0, %o0
F0056A74: d0044000                 ld      [%l1], %o0
F0056A78: 80a22000                 cmp     %o0, 0
F0056A7C: 12bffffe                 bne     loc_F0056A74
F0056A80: 01000000                 nop
F0056A84: 40010109                 call    _simple_lock_try
F0056A88: 90100011                 mov     %l1, %o0
F0056A8C: 80a22000                 cmp     %o0, 0
F0056A90: 02bffff9                 be      loc_F0056A74
F0056A94: 01000000                 nop
F0056A98: c0266008                 clr     [%i1+8]
F0056A9C: 1080002c                 ba      loc_F0056B4C
F0056AA0: d0046008                 ld      [%l1+8], %o0
F0056AA4: b0066008                 add     %i1, 8, %i0
F0056AA8: d0060000                 ld      [%i0], %o0
F0056AAC: 80a22000                 cmp     %o0, 0
F0056AB0: 12bffffe                 bne     loc_F0056AA8
F0056AB4: 01000000                 nop
F0056AB8: 400100fc                 call    _simple_lock_try
F0056ABC: 90100018                 mov     %i0, %o0
F0056AC0: 80a22000                 cmp     %o0, 0
F0056AC4: 02bffff9                 be      loc_F0056AA8
F0056AC8: 01000000                 nop
F0056ACC: d006600c                 ld      [%i1+0xC], %o0
F0056AD0: 80a22000                 cmp     %o0, 0
F0056AD4: 02800053                 be      loc_F0056C20
F0056AD8: 80a6a000                 cmp     %i2, 0
F0056ADC: 02800010                 be      loc_F0056B1C
F0056AE0: 90100019                 mov     %i1, %o0
F0056AE4: 7ffff3d6                 call    _ipc_entry_lookup
F0056AE8: 9210001a                 mov     %i2, %o1
F0056AEC: 80a22000                 cmp     %o0, 0
F0056AF0: 02800007                 be      loc_F0056B0C
F0056AF4: 01000000                 nop
F0056AF8: d2020000                 ld      [%o0], %o1
F0056AFC: 11000080                 sethi   0x20000, %o0
F0056B00: 808a4008                 btst    %o0, %o1
F0056B04: 12800006                 bne     loc_F0056B1C
F0056B08: 01000000                 nop
F0056B0C: c0266008                 clr     [%i1+8]
F0056B10: 31040010                 sethi   0x10004000, %i0
F0056B14: 1080005d                 ba      locret_F0056C88
F0056B18: b0162007                 bset    7, %i0
F0056B1C: d0044000                 ld      [%l1], %o0
F0056B20: 80a22000                 cmp     %o0, 0
F0056B24: 12bffffe                 bne     loc_F0056B1C
F0056B28: 01000000                 nop
F0056B2C: 400100df                 call    _simple_lock_try
F0056B30: 90100011                 mov     %l1, %o0
F0056B34: 80a22000                 cmp     %o0, 0
F0056B38: 02bffff9                 be      loc_F0056B1C
F0056B3C: 01000000                 nop
F0056B40: c0266008                 clr     [%i1+8]
F0056B44: e027bff4                 st      %l0, [%fp+var_C]
F0056B48: d0046008                 ld      [%l1+8], %o0
F0056B4C: 80a22000                 cmp     %o0, 0
F0056B50: 36800009                 bge,a   loc_F0056B74
F0056B54: e404600c                 ld      [%l1+0xC], %l2
F0056B58: 90100019                 mov     %i1, %o0
F0056B5C: 92100011                 mov     %l1, %o1
F0056B60: 94100016                 mov     %l6, %o2
F0056B64: 40000cfc                 call    _ipc_object_copyout_dest
F0056B68: 9607bfe8                 add     %fp, var_18, %o3
F0056B6C: 10800036                 ba      loc_F0056C44
F0056B70: 80a42000                 cmp     %l0, 0
F0056B74: d0046004                 ld      [%l1+4], %o0
F0056B78: 90023fff                 inc     -1, %o0
F0056B7C: d0246004                 st      %o0, [%l1+4]
F0056B80: c0244000                 clr     [%l1]
F0056B84: 80a22000                 cmp     %o0, 0
F0056B88: 1280000c                 bne     loc_F0056BB8
F0056B8C: 80a42000                 cmp     %l0, 0
F0056B90: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F0056B94: d0046008                 ld      [%l1+8], %o0
F0056B98: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0056B9C: 912a2001                 sll     %o0, 1, %o0
F0056BA0: 91322011                 srl     %o0, 17, %o0
F0056BA4: 912a2002                 sll     %o0, 2, %o0
F0056BA8: d0020009                 ld      [%o0+%o1], %o0
F0056BAC: 40008989                 call    _zfree
F0056BB0: 92100011                 mov     %l1, %o1
F0056BB4: 80a42000                 cmp     %l0, 0
F0056BB8: 02800020                 be      loc_F0056C38
F0056BBC: 80a43fff                 cmp     %l0, -1
F0056BC0: 0280001f                 be      loc_F0056C3C
F0056BC4: 90103fff                 mov     -1, %o0
F0056BC8: d0040000                 ld      [%l0], %o0
F0056BCC: 80a22000                 cmp     %o0, 0
F0056BD0: 12bffffe                 bne     loc_F0056BC8
F0056BD4: 01000000                 nop
F0056BD8: 400100b4                 call    _simple_lock_try
F0056BDC: 90100010                 mov     %l0, %o0
F0056BE0: 80a22000                 cmp     %o0, 0
F0056BE4: 02bffff9                 be      loc_F0056BC8
F0056BE8: 01000000                 nop
F0056BEC: d0042008                 ld      [%l0+8], %o0
F0056BF0: 80a22000                 cmp     %o0, 0
F0056BF4: 06800007                 bl      loc_F0056C10
F0056BF8: 90103fff                 mov     -1, %o0
F0056BFC: d004200c                 ld      [%l0+0xC], %o0
F0056C00: 80a48008                 cmp     %l2, %o0
F0056C04: 3c800004                 bpos,a  loc_F0056C14
F0056C08: c027bfe8                 clr     [%fp+var_18]
F0056C0C: 90103fff                 mov     -1, %o0
F0056C10: d027bfe8                 st      %o0, [%fp+var_18]
F0056C14: c0240000                 clr     [%l0]
F0056C18: 1080000b                 ba      loc_F0056C44
F0056C1C: 80a42000                 cmp     %l0, 0
F0056C20: c0266008                 clr     [%i1+8]
F0056C24: 31040018                 sethi   0x10006000, %i0
F0056C28: 10800018                 ba      locret_F0056C88
F0056C2C: b016200b                 bset    0xB, %i0
F0056C30: 10800016                 ba      locret_F0056C88
F0056C34: b016200b                 bset    0xB, %i0
F0056C38: 90103fff                 mov     -1, %o0
F0056C3C: d027bfe8                 st      %o0, [%fp+var_18]
F0056C40: 80a42000                 cmp     %l0, 0
F0056C44: 02800006                 be      loc_F0056C5C
F0056C48: 80a43fff                 cmp     %l0, -1
F0056C4C: 02800005                 be      loc_F0056C60
F0056C50: 133fffc0                 sethi   -0x10000, %o1
F0056C54: 40000a87                 call    _ipc_object_release
F0056C58: 90100010                 mov     %l0, %o0
F0056C5C: 133fffc0                 sethi   -0x10000, %o1
F0056C60: 920d0009                 and     %l4, %o1, %o1
F0056C64: 912da008                 sll     %l6, 8, %o0
F0056C68: 90154008                 bset    %l5, %o0
F0056C6C: 92124008                 bset    %o0, %o1
F0056C70: d224c000                 st      %o1, [%l3]
F0056C74: d207bfe8                 ld      [%fp+var_18], %o1
F0056C78: b0102000                 mov     0, %i0
F0056C7C: d007bff4                 ld      [%fp+var_C], %o0
F0056C80: d224e00c                 st      %o1, [%l3+0xC]
F0056C84: d024e008                 st      %o0, [%l3+8]
F0056C88: 81c7e008                 ret
F0056C8C: 81e80000                 restore
