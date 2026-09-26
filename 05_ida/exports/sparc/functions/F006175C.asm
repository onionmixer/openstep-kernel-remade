F006175C: 9de3bf80                 save    %sp, -0x80, %sp! int
F0061760: 9410001a                 mov     %i2, %o2
F0061764: 9002a003                 add     %o2, 3, %o0
F0061768: 960a3ffc                 and     %o0, -4, %o3
F006176C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0061770: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0061774: d002200c                 ld      [%o0+0xC], %o0
F0061778: 9422800b                 sub     %o2, %o3, %o2
F006177C: e2022088                 ld      [%o0+0x88], %l1
F0061780: 13000008                 sethi   0x2000, %o1
F0061784: 80a2c009                 cmp     %o3, %o1
F0061788: 08800004                 bleu    loc_F0061798
F006178C: e402200c                 ld      [%o0+0xC], %l2
F0061790: 10800156                 ba      locret_F0061CE8
F0061794: b0103f93                 mov     -0x6D, %i0
F0061798: 90100018                 mov     %i0, %o0
F006179C: 9210000b                 mov     %o3, %o1
F00617A0: 7fffceab                 call    _ipc_kmsg_get
F00617A4: 9607bff4                 add     %fp, var_C, %o3
F00617A8: b4920000                 orcc    %o0, %g0, %i2
F00617AC: 22800007                 be,a    loc_F00617C8
F00617B0: d007bff4                 ld      [%fp+var_C], %o0
F00617B4: 3080014a                 ba,a    loc_F0061CDC
F00617B8: 40001a7a                 call    _kfree
F00617BC: 01000000                 nop
F00617C0: 10800147                 ba      loc_F0061CDC
F00617C4: 9010001a                 mov     %i2, %o0
F00617C8: 92100011                 mov     %l1, %o1
F00617CC: 7fffd6a0                 call    _ipc_kmsg_copyin_compat
F00617D0: 94100012                 mov     %l2, %o2
F00617D4: b4920000                 orcc    %o0, %g0, %i2
F00617D8: 0280000a                 be      loc_F0061800
F00617DC: d007bff4                 ld      [%fp+var_C], %o0
F00617E0: d2022008                 ld      [%o0+8], %o1
F00617E4: 80a26000                 cmp     %o1, 0
F00617E8: 14bffff4                 bg      loc_F00617B8
F00617EC: 01000000                 nop
F00617F0: 7fffce84                 call    _ipc_kmsg_free
F00617F4: 01000000                 nop
F00617F8: 10800139                 ba      loc_F0061CDC
F00617FC: 9010001a                 mov     %i2, %o0
F0061800: e0022020                 ld      [%o0+0x20], %l0
F0061804: 80a42000                 cmp     %l0, 0
F0061808: 0280005a                 be      loc_F0061970
F006180C: 80a43fff                 cmp     %l0, -1
F0061810: 02800059                 be      loc_F0061974
F0061814: 808e6002                 btst    2, %i1
F0061818: f402201c                 ld      [%o0+0x1C], %i2
F006181C: 7fffdf85                 call    _ipc_object_reference
F0061820: 90100010                 mov     %l0, %o0
F0061824: d0068000                 ld      [%i2], %o0
F0061828: 80a22000                 cmp     %o0, 0
F006182C: 12bffffe                 bne     loc_F0061824
F0061830: 01000000                 nop
F0061834: 4000d59d                 call    _simple_lock_try
F0061838: 9010001a                 mov     %i2, %o0
F006183C: 80a22000                 cmp     %o0, 0
F0061840: 02bffff9                 be      loc_F0061824
F0061844: 133c04ef                 sethi   %hi(_ipc_space_kernel), %o1
F0061848: d006a00c                 ld      [%i2+0xC], %o0
F006184C: d2026330                 ld      [%o1+%lo(_ipc_space_kernel)], %o1
F0061850: 80a20009                 cmp     %o0, %o1
F0061854: 12800046                 bne     loc_F006196C
F0061858: d007bff4                 ld      [%fp+var_C], %o0
F006185C: c0268000                 clr     [%i2]
F0061860: 40000f59                 call    _ipc_kobject_server
F0061864: 01000000                 nop
F0061868: 80a22000                 cmp     %o0, 0
F006186C: 0280008a                 be      loc_F0061A94
F0061870: d027bff4                 st      %o0, [%fp+var_C]
F0061874: d0040000                 ld      [%l0], %o0
F0061878: 80a22000                 cmp     %o0, 0
F006187C: 12bffffe                 bne     loc_F0061874
F0061880: 01000000                 nop
F0061884: 4000d589                 call    _simple_lock_try
F0061888: 90100010                 mov     %l0, %o0
F006188C: 80a22000                 cmp     %o0, 0
F0061890: 02bffff9                 be      loc_F0061874
F0061894: 01000000                 nop
F0061898: d0042008                 ld      [%l0+8], %o0
F006189C: 80a22000                 cmp     %o0, 0
F00618A0: 16800022                 bge     loc_F0061928
F00618A4: 01000000                 nop
F00618A8: d004200c                 ld      [%l0+0xC], %o0
F00618AC: 80a20011                 cmp     %o0, %l1
F00618B0: 1280001e                 bne     loc_F0061928
F00618B4: 01000000                 nop
F00618B8: d0042030                 ld      [%l0+0x30], %o0
F00618BC: 80a22000                 cmp     %o0, 0
F00618C0: 1280001a                 bne     loc_F0061928
F00618C4: d007bff4                 ld      [%fp+var_C], %o0
F00618C8: d2022018                 ld      [%o0+0x18], %o1
F00618CC: d0022010                 ld      [%o0+0x10], %o0
F00618D0: 92024008                 add     %o1, %o0, %o1
F00618D4: 80a6c009                 cmp     %i3, %o1
F00618D8: 0a800014                 bcs     loc_F0061928
F00618DC: b4042040                 add     %l0, 0x40, %i2 ! '@'
F00618E0: d0068000                 ld      [%i2], %o0
F00618E4: 80a22000                 cmp     %o0, 0
F00618E8: 12bffffe                 bne     loc_F00618E0
F00618EC: 01000000                 nop
F00618F0: 4000d56e                 call    _simple_lock_try
F00618F4: 9010001a                 mov     %i2, %o0
F00618F8: 80a22000                 cmp     %o0, 0
F00618FC: 02bffff9                 be      loc_F00618E0
F0061900: 01000000                 nop
F0061904: d006a008                 ld      [%i2+8], %o0
F0061908: 80a22000                 cmp     %o0, 0
F006190C: 12800006                 bne     loc_F0061924
F0061910: 01000000                 nop
F0061914: d006a004                 ld      [%i2+4], %o0
F0061918: 80a22000                 cmp     %o0, 0
F006191C: 2280000b                 be,a    loc_F0061948
F0061920: d0042034                 ld      [%l0+0x34], %o0
F0061924: c0268000                 clr     [%i2]
F0061928: c0240000                 clr     [%l0]
F006192C: d007bff4                 ld      [%fp+var_C], %o0
F0061930: 13000040                 sethi   0x10000, %o1
F0061934: 94102000                 mov     0, %o2
F0061938: 7fffdad1                 call    _ipc_mqueue_send
F006193C: 96102000                 mov     0, %o3
F0061940: 10800056                 ba      loc_F0061A98
F0061944: 80a42000                 cmp     %l0, 0
F0061948: 90022001                 inc     %o0
F006194C: d0242034                 st      %o0, [%l0+0x34]
F0061950: c0268000                 clr     [%i2]
F0061954: d0042004                 ld      [%l0+4], %o0
F0061958: 90023fff                 inc     -1, %o0
F006195C: d0242004                 st      %o0, [%l0+4]
F0061960: c0240000                 clr     [%l0]
F0061964: 108000d4                 ba      loc_F0061CB4
F0061968: 92100011                 mov     %l1, %o1
F006196C: c0268000                 clr     [%i2]
F0061970: 808e6002                 btst    2, %i1
F0061974: 0280002a                 be      loc_F0061A1C
F0061978: 808e6020                 btst    0x20, %i1 ! ' '
F006197C: 02800005                 be      loc_F0061990
F0061980: d407bff4                 ld      [%fp+var_C], %o2
F0061984: 11000080                 sethi   0x20000, %o0
F0061988: 10800003                 ba      loc_F0061994
F006198C: 92122010                 or      %o0, 0x10, %o1
F0061990: 92102010                 mov     0x10, %o1
F0061994: 9010000a                 mov     %o2, %o0
F0061998: 940e6001                 and     %i1, 1, %o2
F006199C: 9420000a                 neg     %o2
F00619A0: 940f000a                 and     %i4, %o2, %o2
F00619A4: 7fffdab6                 call    _ipc_mqueue_send
F00619A8: 96102000                 mov     0, %o3
F00619AC: b4100008                 mov     %o0, %i2
F00619B0: 1104000090122004         set     0x10000004, %o0
F00619B8: 80a68008                 cmp     %i2, %o0
F00619BC: 12800029                 bne     loc_F0061A60
F00619C0: 80a6a000                 cmp     %i2, 0
F00619C4: d607bff4                 ld      [%fp+var_C], %o3
F00619C8: 90100011                 mov     %l1, %o0
F00619CC: d202e01c                 ld      [%o3+0x1C], %o1
F00619D0: 94102000                 mov     0, %o2
F00619D4: 7fffd8f4                 call    _ipc_marequest_create
F00619D8: 9602e00c                 inc     0xC, %o3
F00619DC: b4920000                 orcc    %o0, %g0, %i2
F00619E0: 12800020                 bne     loc_F0061A60
F00619E4: d007bff4                 ld      [%fp+var_C], %o0
F00619E8: 13000040                 sethi   0x10000, %o1
F00619EC: 94102000                 mov     0, %o2
F00619F0: 7fffdaa3                 call    _ipc_mqueue_send
F00619F4: 96102000                 mov     0, %o3
F00619F8: 80a42000                 cmp     %l0, 0
F00619FC: 02800006                 be      loc_F0061A14
F0061A00: 80a43fff                 cmp     %l0, -1
F0061A04: 028000b9                 be      locret_F0061CE8
F0061A08: b0103f97                 mov     -0x69, %i0
F0061A0C: 7fffdf19                 call    _ipc_object_release
F0061A10: 90100010                 mov     %l0, %o0
F0061A14: 108000b5                 ba      locret_F0061CE8
F0061A18: b0103f97                 mov     -0x69, %i0
F0061A1C: 0280000a                 be      loc_F0061A44
F0061A20: 808e6001                 btst    1, %i1
F0061A24: 02800005                 be      loc_F0061A38
F0061A28: d407bff4                 ld      [%fp+var_C], %o2
F0061A2C: 11000080                 sethi   0x20000, %o0
F0061A30: 10800003                 ba      loc_F0061A3C
F0061A34: 92122010                 or      %o0, 0x10, %o1
F0061A38: 13000080                 sethi   0x20000, %o1
F0061A3C: 10800005                 ba      loc_F0061A50
F0061A40: 9010000a                 mov     %o2, %o0
F0061A44: d007bff4                 ld      [%fp+var_C], %o0
F0061A48: 920e6001                 and     %i1, 1, %o1
F0061A4C: 932a6004                 sll     %o1, 4, %o1
F0061A50: 9410001c                 mov     %i4, %o2
F0061A54: 7fffda8a                 call    _ipc_mqueue_send
F0061A58: 96102000                 mov     0, %o3
F0061A5C: b4920000                 orcc    %o0, %g0, %i2
F0061A60: 0280000e                 be      loc_F0061A98
F0061A64: 80a42000                 cmp     %l0, 0
F0061A68: 7fffccf0                 call    _ipc_kmsg_destroy
F0061A6C: d007bff4                 ld      [%fp+var_C], %o0
F0061A70: 80a42000                 cmp     %l0, 0
F0061A74: 02800006                 be      loc_F0061A8C
F0061A78: 80a43fff                 cmp     %l0, -1
F0061A7C: 02800098                 be      loc_F0061CDC
F0061A80: 9010001a                 mov     %i2, %o0
F0061A84: 7fffdefb                 call    _ipc_object_release
F0061A88: 90100010                 mov     %l0, %o0
F0061A8C: 10800094                 ba      loc_F0061CDC
F0061A90: 9010001a                 mov     %i2, %o0
F0061A94: 80a42000                 cmp     %l0, 0
F0061A98: 02800037                 be      loc_F0061B74
F0061A9C: 80a43fff                 cmp     %l0, -1
F0061AA0: 22800092                 be,a    locret_F0061CE8
F0061AA4: b0103f36                 mov     -0xCA, %i0
F0061AA8: d0040000                 ld      [%l0], %o0
F0061AAC: 80a22000                 cmp     %o0, 0
F0061AB0: 12bffffe                 bne     loc_F0061AA8
F0061AB4: 01000000                 nop
F0061AB8: 4000d4fc                 call    _simple_lock_try
F0061ABC: 90100010                 mov     %l0, %o0
F0061AC0: 80a22000                 cmp     %o0, 0
F0061AC4: 02bffff9                 be      loc_F0061AA8
F0061AC8: 01000000                 nop
F0061ACC: d004200c                 ld      [%l0+0xC], %o0
F0061AD0: 80a20011                 cmp     %o0, %l1
F0061AD4: 22800013                 be,a    loc_F0061B20
F0061AD8: f4042030                 ld      [%l0+0x30], %i2
F0061ADC: d0042004                 ld      [%l0+4], %o0
F0061AE0: 90023fff                 inc     -1, %o0
F0061AE4: d0242004                 st      %o0, [%l0+4]
F0061AE8: c0240000                 clr     [%l0]
F0061AEC: 80a22000                 cmp     %o0, 0
F0061AF0: 12800021                 bne     loc_F0061B74
F0061AF4: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F0061AF8: d0042008                 ld      [%l0+8], %o0
F0061AFC: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0061B00: 912a2001                 sll     %o0, 1, %o0
F0061B04: 91322011                 srl     %o0, 17, %o0
F0061B08: 912a2002                 sll     %o0, 2, %o0
F0061B0C: d0020009                 ld      [%o0+%o1], %o0
F0061B10: 40005db0                 call    _zfree
F0061B14: 92100010                 mov     %l0, %o1
F0061B18: 10800074                 ba      locret_F0061CE8
F0061B1C: b0103f36                 mov     -0xCA, %i0
F0061B20: 80a6a000                 cmp     %i2, 0
F0061B24: 22800027                 be,a    loc_F0061BC0
F0061B28: b4042040                 add     %l0, 0x40, %i2 ! '@'
F0061B2C: d0068000                 ld      [%i2], %o0
F0061B30: 80a22000                 cmp     %o0, 0
F0061B34: 12bffffe                 bne     loc_F0061B2C
F0061B38: 01000000                 nop
F0061B3C: 4000d4db                 call    _simple_lock_try
F0061B40: 9010001a                 mov     %i2, %o0
F0061B44: 80a22000                 cmp     %o0, 0
F0061B48: 02bffff9                 be      loc_F0061B2C
F0061B4C: 01000000                 nop
F0061B50: d006a008                 ld      [%i2+8], %o0
F0061B54: 80a22000                 cmp     %o0, 0
F0061B58: 16800009                 bge     loc_F0061B7C
F0061B5C: 9010001a                 mov     %i2, %o0
F0061B60: c0268000                 clr     [%i2]
F0061B64: d0042004                 ld      [%l0+4], %o0
F0061B68: 90023fff                 inc     -1, %o0
F0061B6C: d0242004                 st      %o0, [%l0+4]
F0061B70: c0240000                 clr     [%l0]
F0061B74: 1080005d                 ba      locret_F0061CE8
F0061B78: b0103f36                 mov     -0xCA, %i0
F0061B7C: 7fffe6f2                 call    _ipc_pset_remove
F0061B80: 92100010                 mov     %l0, %o1
F0061B84: d006a004                 ld      [%i2+4], %o0
F0061B88: c0268000                 clr     [%i2]
F0061B8C: 80a22000                 cmp     %o0, 0
F0061B90: 3280000c                 bne,a   loc_F0061BC0
F0061B94: b4042040                 add     %l0, 0x40, %i2 ! '@'
F0061B98: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F0061B9C: d006a008                 ld      [%i2+8], %o0
F0061BA0: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0061BA4: 912a2001                 sll     %o0, 1, %o0
F0061BA8: 91322011                 srl     %o0, 17, %o0
F0061BAC: 912a2002                 sll     %o0, 2, %o0
F0061BB0: d0020009                 ld      [%o0+%o1], %o0
F0061BB4: 40005d87                 call    _zfree
F0061BB8: 9210001a                 mov     %i2, %o1
F0061BBC: b4042040                 add     %l0, 0x40, %i2 ! '@'
F0061BC0: d0068000                 ld      [%i2], %o0
F0061BC4: 80a22000                 cmp     %o0, 0
F0061BC8: 12bffffe                 bne     loc_F0061BC0
F0061BCC: 01000000                 nop
F0061BD0: 4000d4b6                 call    _simple_lock_try
F0061BD4: 9010001a                 mov     %i2, %o0
F0061BD8: 80a22000                 cmp     %o0, 0
F0061BDC: 02bffff9                 be      loc_F0061BC0
F0061BE0: 01000000                 nop
F0061BE4: c0240000                 clr     [%l0]
F0061BE8: 11000004                 sethi   0x1000, %o0
F0061BEC: 808e4008                 btst    %o0, %i1
F0061BF0: 113c04d0                 sethi   %hi(_active_threads), %o0
F0061BF4: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0061BF8: 94103fff                 mov     -1, %o2
F0061BFC: 920e6100                 and     %i1, 0x100, %o1
F0061C00: f02220c4                 st      %i0, [%o0+0xC4]
F0061C04: f22220c8                 st      %i1, [%o0+0xC8]
F0061C08: f62220cc                 st      %i3, [%o0+0xCC]
F0061C0C: fa2220d0                 st      %i5, [%o0+0xD0]
F0061C10: e02220d8                 st      %l0, [%o0+0xD8]
F0061C14: 02800003                 be      loc_F0061C20
F0061C18: f42220dc                 st      %i2, [%o0+0xDC]
F0061C1C: 9410001b                 mov     %i3, %o2
F0061C20: 9007bff4                 add     %fp, var_C, %o0
F0061C24: d023a05c                 st      %o0, [%sp+0x80+var_24]
F0061C28: 9007bff0                 add     %fp, var_10, %o0
F0061C2C: d023a060                 st      %o0, [%sp+0x80+var_20]
F0061C30: 9010001a                 mov     %i2, %o0
F0061C34: 9610001d                 mov     %i5, %o3
F0061C38: 1b3c0187                 sethi   %hi(_msg_receive_continue), %o5
F0061C3C: 98102000                 mov     0, %o4! int
F0061C40: 7fffdb9e                 call    _ipc_mqueue_receive
F0061C44: 9a1360f0                 bset    %lo(_msg_receive_continue), %o5! int
F0061C48: b4100008                 mov     %o0, %i2
F0061C4C: 7fffde89                 call    _ipc_object_release
F0061C50: 90100010                 mov     %l0, %o0
F0061C54: 80a6a000                 cmp     %i2, 0
F0061C58: 0280000e                 be      loc_F0061C90
F0061C5C: 11040010                 sethi   0x10004000, %o0
F0061C60: 90122004                 bset    4, %o0
F0061C64: 80a68008                 cmp     %i2, %o0
F0061C68: 3280001d                 bne,a   loc_F0061CDC
F0061C6C: 9010001a                 mov     %i2, %o0
F0061C70: 9007bfec                 add     %fp, var_14, %o0! int
F0061C74: 92062004                 add     %i0, 4, %o1! int
F0061C78: d607bff4                 ld      [%fp+var_C], %o3! int
F0061C7C: 94102004                 mov     4, %o2! int
F0061C80: 4000d913                 call    _copyout
F0061C84: d627bfec                 st      %o3, [%fp+var_14]
F0061C88: 10800015                 ba      loc_F0061CDC
F0061C8C: 9010001a                 mov     %i2, %o0
F0061C90: d207bff4                 ld      [%fp+var_C], %o1
F0061C94: d0026018                 ld      [%o1+0x18], %o0
F0061C98: 80a2001b                 cmp     %o0, %i3
F0061C9C: 28800006                 bleu,a  loc_F0061CB4
F0061CA0: 92100011                 mov     %l1, %o1
F0061CA4: 7fffcc61                 call    _ipc_kmsg_destroy
F0061CA8: 90100009                 mov     %o1, %o0
F0061CAC: 1080000f                 ba      locret_F0061CE8
F0061CB0: b0103f34                 mov     -0xCC, %i0
F0061CB4: d007bff4                 ld      [%fp+var_C], %o0
F0061CB8: 7fffd715                 call    _ipc_kmsg_copyout_compat
F0061CBC: 94100012                 mov     %l2, %o2
F0061CC0: d207bff4                 ld      [%fp+var_C], %o1
F0061CC4: d4026018                 ld      [%o1+0x18], %o2
F0061CC8: d6026010                 ld      [%o1+0x10], %o3
F0061CCC: 90100018                 mov     %i0, %o0
F0061CD0: 9402800b                 add     %o2, %o3, %o2
F0061CD4: 7fffcdb3                 call    _ipc_kmsg_put
F0061CD8: d4226018                 st      %o2, [%o1+0x18]
F0061CDC: 7ffffd61                 call    _msg_return_translate
F0061CE0: 01000000                 nop
F0061CE4: b0100008                 mov     %o0, %i0
F0061CE8: 81c7e008                 ret
F0061CEC: 81e80000                 restore
