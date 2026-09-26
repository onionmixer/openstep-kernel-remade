F0065FDC: 9de3bf88                 save    %sp, -0x78, %sp
F0065FE0: d4062004                 ld      [%i0+4], %o2
F0065FE4: 113c04d0                 sethi   %hi(_active_threads), %o0
F0065FE8: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0065FEC: 9202a003                 add     %o2, 3, %o1
F0065FF0: 960a7ffc                 and     %o1, -4, %o3
F0065FF4: d202200c                 ld      [%o0+0xC], %o1
F0065FF8: 9422800b                 sub     %o2, %o3, %o2
F0065FFC: ea026088                 ld      [%o1+0x88], %l5
F0066000: 11000008                 sethi   0x2000, %o0
F0066004: 80a2c008                 cmp     %o3, %o0
F0066008: 08800004                 bleu    loc_F0066018
F006600C: ee02600c                 ld      [%o1+0xC], %l7
F0066010: 10800158                 ba      locret_F0066570
F0066014: b0103f93                 mov     -0x6D, %i0
F0066018: 90100018                 mov     %i0, %o0
F006601C: 9210000b                 mov     %o3, %o1
F0066020: 7fffbcca                 call    _ipc_kmsg_get_from_kernel
F0066024: 9607bff4                 add     %fp, var_C, %o3
F0066028: a4920000                 orcc    %o0, %g0, %l2
F006602C: 22800007                 be,a    loc_F0066048
F0066030: d007bff4                 ld      [%fp+var_C], %o0
F0066034: 3080014c                 ba,a    loc_F0066564
F0066038: 4000085a                 call    _kfree
F006603C: 01000000                 nop
F0066040: 10800149                 ba      loc_F0066564
F0066044: 90100012                 mov     %l2, %o0
F0066048: 92100015                 mov     %l5, %o1
F006604C: 7fffc480                 call    _ipc_kmsg_copyin_compat
F0066050: 94100017                 mov     %l7, %o2
F0066054: a4920000                 orcc    %o0, %g0, %l2
F0066058: 0280000a                 be      loc_F0066080
F006605C: d007bff4                 ld      [%fp+var_C], %o0
F0066060: d2022008                 ld      [%o0+8], %o1
F0066064: 80a26000                 cmp     %o1, 0
F0066068: 14bffff4                 bg      loc_F0066038
F006606C: 01000000                 nop
F0066070: 7fffbc64                 call    _ipc_kmsg_free
F0066074: 01000000                 nop
F0066078: 1080013b                 ba      loc_F0066564
F006607C: 90100012                 mov     %l2, %o0
F0066080: e2022020                 ld      [%o0+0x20], %l1
F0066084: 80a46000                 cmp     %l1, 0
F0066088: 0280005a                 be      loc_F00661F0
F006608C: 80a47fff                 cmp     %l1, -1
F0066090: 02800059                 be      loc_F00661F4
F0066094: 808e6002                 btst    2, %i1
F0066098: e002201c                 ld      [%o0+0x1C], %l0
F006609C: 7fffcd65                 call    _ipc_object_reference
F00660A0: 90100011                 mov     %l1, %o0
F00660A4: d0040000                 ld      [%l0], %o0
F00660A8: 80a22000                 cmp     %o0, 0
F00660AC: 12bffffe                 bne     loc_F00660A4
F00660B0: 01000000                 nop
F00660B4: 4000c37d                 call    _simple_lock_try
F00660B8: 90100010                 mov     %l0, %o0
F00660BC: 80a22000                 cmp     %o0, 0
F00660C0: 02bffff9                 be      loc_F00660A4
F00660C4: 133c04ef                 sethi   %hi(_ipc_space_kernel), %o1
F00660C8: d004200c                 ld      [%l0+0xC], %o0
F00660CC: d2026330                 ld      [%o1+%lo(_ipc_space_kernel)], %o1
F00660D0: 80a20009                 cmp     %o0, %o1
F00660D4: 12800046                 bne     loc_F00661EC
F00660D8: d007bff4                 ld      [%fp+var_C], %o0
F00660DC: c0240000                 clr     [%l0]
F00660E0: 7ffffd39                 call    _ipc_kobject_server
F00660E4: 01000000                 nop
F00660E8: 80a22000                 cmp     %o0, 0
F00660EC: 0280007d                 be      loc_F00662E0
F00660F0: d027bff4                 st      %o0, [%fp+var_C]
F00660F4: d0044000                 ld      [%l1], %o0
F00660F8: 80a22000                 cmp     %o0, 0
F00660FC: 12bffffe                 bne     loc_F00660F4
F0066100: 01000000                 nop
F0066104: 4000c369                 call    _simple_lock_try
F0066108: 90100011                 mov     %l1, %o0
F006610C: 80a22000                 cmp     %o0, 0
F0066110: 02bffff9                 be      loc_F00660F4
F0066114: 01000000                 nop
F0066118: d0046008                 ld      [%l1+8], %o0
F006611C: 80a22000                 cmp     %o0, 0
F0066120: 16800022                 bge     loc_F00661A8
F0066124: 01000000                 nop
F0066128: d004600c                 ld      [%l1+0xC], %o0
F006612C: 80a20015                 cmp     %o0, %l5
F0066130: 1280001e                 bne     loc_F00661A8
F0066134: 01000000                 nop
F0066138: d0046030                 ld      [%l1+0x30], %o0
F006613C: 80a22000                 cmp     %o0, 0
F0066140: 1280001a                 bne     loc_F00661A8
F0066144: d007bff4                 ld      [%fp+var_C], %o0
F0066148: d2022018                 ld      [%o0+0x18], %o1
F006614C: d0022010                 ld      [%o0+0x10], %o0
F0066150: 92024008                 add     %o1, %o0, %o1
F0066154: 80a68009                 cmp     %i2, %o1
F0066158: 0a800014                 bcs     loc_F00661A8
F006615C: b6046040                 add     %l1, 0x40, %i3 ! '@'
F0066160: d006c000                 ld      [%i3], %o0
F0066164: 80a22000                 cmp     %o0, 0
F0066168: 12bffffe                 bne     loc_F0066160
F006616C: 01000000                 nop
F0066170: 4000c34e                 call    _simple_lock_try
F0066174: 9010001b                 mov     %i3, %o0
F0066178: 80a22000                 cmp     %o0, 0
F006617C: 02bffff9                 be      loc_F0066160
F0066180: 01000000                 nop
F0066184: d006e008                 ld      [%i3+8], %o0
F0066188: 80a22000                 cmp     %o0, 0
F006618C: 12800006                 bne     loc_F00661A4
F0066190: 01000000                 nop
F0066194: d006e004                 ld      [%i3+4], %o0
F0066198: 80a22000                 cmp     %o0, 0
F006619C: 2280000b                 be,a    loc_F00661C8
F00661A0: d0046034                 ld      [%l1+0x34], %o0
F00661A4: c026c000                 clr     [%i3]
F00661A8: c0244000                 clr     [%l1]
F00661AC: d007bff4                 ld      [%fp+var_C], %o0
F00661B0: 13000040                 sethi   0x10000, %o1
F00661B4: 94102000                 mov     0, %o2
F00661B8: 7fffc8b1                 call    _ipc_mqueue_send
F00661BC: 96102000                 mov     0, %o3
F00661C0: 10800049                 ba      loc_F00662E4
F00661C4: 80a46000                 cmp     %l1, 0
F00661C8: 90022001                 inc     %o0
F00661CC: d0246034                 st      %o0, [%l1+0x34]
F00661D0: c026c000                 clr     [%i3]
F00661D4: d0046004                 ld      [%l1+4], %o0
F00661D8: 90023fff                 inc     -1, %o0
F00661DC: d0246004                 st      %o0, [%l1+4]
F00661E0: c0244000                 clr     [%l1]
F00661E4: 108000d4                 ba      loc_F0066534
F00661E8: 92100015                 mov     %l5, %o1
F00661EC: c0240000                 clr     [%l0]
F00661F0: 808e6002                 btst    2, %i1
F00661F4: 02800006                 be      loc_F006620C
F00661F8: 113c043e                 sethi   %hi(aMsgRpcNotify), %o0! "msg_rpc notify"
F00661FC: 7ffebbdd                 call    _panic
F0066200: 90122218                 bset    %lo(aMsgRpcNotify), %o0! "msg_rpc notify"
F0066204: 1080002a                 ba      loc_F00662AC
F0066208: 80a4a000                 cmp     %l2, 0
F006620C: 2d000080                 sethi   0x20000, %l6
F0066210: 900e6001                 and     %i1, 1, %o0
F0066214: a8200008                 neg     %o0, %l4
F0066218: 11040000a6122007         set     0x10000007, %l3
F0066220: 808e6020                 btst    0x20, %i1 ! ' '
F0066224: 02800007                 be      loc_F0066240
F0066228: 808e6001                 btst    1, %i1
F006622C: d007bff4                 ld      [%fp+var_C], %o0
F0066230: 02800006                 be      loc_F0066248
F0066234: 13000080                 sethi   0x20000, %o1
F0066238: 10800004                 ba      loc_F0066248
F006623C: 9215a010                 or      %l6, 0x10, %o1
F0066240: d007bff4                 ld      [%fp+var_C], %o0
F0066244: 920d2010                 and     %l4, 0x10, %o1
F0066248: 9410001b                 mov     %i3, %o2
F006624C: 7fffc88c                 call    _ipc_mqueue_send
F0066250: 96102000                 mov     0, %o3
F0066254: a4100008                 mov     %o0, %l2
F0066258: 80a48013                 cmp     %l2, %l3
F006625C: 12800011                 bne     loc_F00662A0
F0066260: 133c04d0                 sethi   %hi(_active_threads), %o1
F0066264: d0026260                 ld      [%o1+%lo(_active_threads)], %o0
F0066268: d002218c                 ld      [%o0+0x18C], %o0
F006626C: 808a2003                 btst    3, %o0
F0066270: 0280000a                 be      loc_F0066298
F0066274: 808e6004                 btst    4, %i1
F0066278: a0100009                 mov     %o1, %l0
F006627C: 40003b51                 call    _thread_halt_self_with_continuation
F0066280: 90102000                 mov     0, %o0
F0066284: d0042260                 ld      [%l0+0x260], %o0
F0066288: d002218c                 ld      [%o0+0x18C], %o0
F006628C: 808a2003                 btst    3, %o0
F0066290: 12bffffb                 bne     loc_F006627C
F0066294: 808e6004                 btst    4, %i1
F0066298: 12800004                 bne     loc_F00662A8
F006629C: 80a48013                 cmp     %l2, %l3
F00662A0: 02bfffe1                 be      loc_F0066224
F00662A4: 808e6020                 btst    0x20, %i1 ! ' '
F00662A8: 80a4a000                 cmp     %l2, 0
F00662AC: 0280000e                 be      loc_F00662E4
F00662B0: 80a46000                 cmp     %l1, 0
F00662B4: 7fffbadd                 call    _ipc_kmsg_destroy
F00662B8: d007bff4                 ld      [%fp+var_C], %o0
F00662BC: 80a46000                 cmp     %l1, 0
F00662C0: 028000a8                 be      loc_F0066560
F00662C4: 80a47fff                 cmp     %l1, -1
F00662C8: 028000a7                 be      loc_F0066564
F00662CC: 90100012                 mov     %l2, %o0
F00662D0: 7fffcce8                 call    _ipc_object_release
F00662D4: 90100011                 mov     %l1, %o0
F00662D8: 108000a3                 ba      loc_F0066564
F00662DC: 90100012                 mov     %l2, %o0
F00662E0: 80a46000                 cmp     %l1, 0
F00662E4: 02800037                 be      loc_F00663C0
F00662E8: 80a47fff                 cmp     %l1, -1
F00662EC: 228000a1                 be,a    locret_F0066570
F00662F0: b0103f36                 mov     -0xCA, %i0
F00662F4: d0044000                 ld      [%l1], %o0
F00662F8: 80a22000                 cmp     %o0, 0
F00662FC: 12bffffe                 bne     loc_F00662F4
F0066300: 01000000                 nop
F0066304: 4000c2e9                 call    _simple_lock_try
F0066308: 90100011                 mov     %l1, %o0
F006630C: 80a22000                 cmp     %o0, 0
F0066310: 02bffff9                 be      loc_F00662F4
F0066314: 01000000                 nop
F0066318: d004600c                 ld      [%l1+0xC], %o0
F006631C: 80a20015                 cmp     %o0, %l5
F0066320: 22800013                 be,a    loc_F006636C
F0066324: f6046030                 ld      [%l1+0x30], %i3
F0066328: d0046004                 ld      [%l1+4], %o0
F006632C: 90023fff                 inc     -1, %o0
F0066330: d0246004                 st      %o0, [%l1+4]
F0066334: c0244000                 clr     [%l1]
F0066338: 80a22000                 cmp     %o0, 0
F006633C: 12800021                 bne     loc_F00663C0
F0066340: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F0066344: d0046008                 ld      [%l1+8], %o0
F0066348: 92126300                 bset    %lo(_ipc_object_zones), %o1
F006634C: 912a2001                 sll     %o0, 1, %o0
F0066350: 91322011                 srl     %o0, 17, %o0
F0066354: 912a2002                 sll     %o0, 2, %o0
F0066358: d0020009                 ld      [%o0+%o1], %o0
F006635C: 40004b9d                 call    _zfree
F0066360: 92100011                 mov     %l1, %o1
F0066364: 10800083                 ba      locret_F0066570
F0066368: b0103f36                 mov     -0xCA, %i0
F006636C: 80a6e000                 cmp     %i3, 0
F0066370: 02800027                 be      loc_F006640C
F0066374: a0046040                 add     %l1, 0x40, %l0 ! '@'
F0066378: d006c000                 ld      [%i3], %o0
F006637C: 80a22000                 cmp     %o0, 0
F0066380: 12bffffe                 bne     loc_F0066378
F0066384: 01000000                 nop
F0066388: 4000c2c8                 call    _simple_lock_try
F006638C: 9010001b                 mov     %i3, %o0
F0066390: 80a22000                 cmp     %o0, 0
F0066394: 02bffff9                 be      loc_F0066378
F0066398: 01000000                 nop
F006639C: d006e008                 ld      [%i3+8], %o0
F00663A0: 80a22000                 cmp     %o0, 0
F00663A4: 16800009                 bge     loc_F00663C8
F00663A8: 9010001b                 mov     %i3, %o0
F00663AC: c026c000                 clr     [%i3]
F00663B0: d0046004                 ld      [%l1+4], %o0
F00663B4: 90023fff                 inc     -1, %o0
F00663B8: d0246004                 st      %o0, [%l1+4]
F00663BC: c0244000                 clr     [%l1]
F00663C0: 1080006c                 ba      locret_F0066570
F00663C4: b0103f36                 mov     -0xCA, %i0
F00663C8: 7fffd4df                 call    _ipc_pset_remove
F00663CC: 92100011                 mov     %l1, %o1
F00663D0: d006e004                 ld      [%i3+4], %o0
F00663D4: c026c000                 clr     [%i3]
F00663D8: 80a22000                 cmp     %o0, 0
F00663DC: 1280000c                 bne     loc_F006640C
F00663E0: a0046040                 add     %l1, 0x40, %l0 ! '@'
F00663E4: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F00663E8: d006e008                 ld      [%i3+8], %o0
F00663EC: 92126300                 bset    %lo(_ipc_object_zones), %o1
F00663F0: 912a2001                 sll     %o0, 1, %o0
F00663F4: 91322011                 srl     %o0, 17, %o0
F00663F8: 912a2002                 sll     %o0, 2, %o0
F00663FC: d0020009                 ld      [%o0+%o1], %o0
F0066400: 40004b74                 call    _zfree
F0066404: 9210001b                 mov     %i3, %o1
F0066408: a0046040                 add     %l1, 0x40, %l0 ! '@'
F006640C: d0040000                 ld      [%l0], %o0
F0066410: 80a22000                 cmp     %o0, 0
F0066414: 12bffffe                 bne     loc_F006640C
F0066418: 01000000                 nop
F006641C: 4000c2a3                 call    _simple_lock_try
F0066420: 90100010                 mov     %l0, %o0
F0066424: 80a22000                 cmp     %o0, 0
F0066428: 02bffff9                 be      loc_F006640C
F006642C: 01000000                 nop
F0066430: c0244000                 clr     [%l1]
F0066434: 11000004                 sethi   0x1000, %o0
F0066438: 808e4008                 btst    %o0, %i1
F006643C: 94103fff                 mov     -1, %o2
F0066440: 02800003                 be      loc_F006644C
F0066444: 920e6100                 and     %i1, 0x100, %o1
F0066448: 9410001a                 mov     %i2, %o2
F006644C: 9007bff4                 add     %fp, var_C, %o0
F0066450: d023a05c                 st      %o0, [%sp+0x78+var_1C]
F0066454: 9007bff0                 add     %fp, var_10, %o0
F0066458: d023a060                 st      %o0, [%sp+0x78+var_18]
F006645C: 90100010                 mov     %l0, %o0
F0066460: 9610001c                 mov     %i4, %o3
F0066464: 98102000                 mov     0, %o4
F0066468: 7fffc994                 call    _ipc_mqueue_receive
F006646C: 9a102000                 mov     0, %o5
F0066470: a4100008                 mov     %o0, %l2
F0066474: 7fffcc7f                 call    _ipc_object_release
F0066478: 90100011                 mov     %l1, %o0
F006647C: 80a4a000                 cmp     %l2, 0
F0066480: 02800023                 be      loc_F006650C
F0066484: 11040010                 sethi   0x10004000, %o0
F0066488: 90122005                 bset    5, %o0
F006648C: 80a48008                 cmp     %l2, %o0
F0066490: 12800018                 bne     loc_F00664F0
F0066494: 11040010                 sethi   0x10004000, %o0
F0066498: 133c04d0                 sethi   %hi(_active_threads), %o1
F006649C: d0026260                 ld      [%o1+%lo(_active_threads)], %o0
F00664A0: d002218c                 ld      [%o0+0x18C], %o0
F00664A4: 808a2003                 btst    3, %o0
F00664A8: 0280000a                 be      loc_F00664D0
F00664AC: 808e6400                 btst    0x400, %i1
F00664B0: a0100009                 mov     %o1, %l0
F00664B4: 40003ac3                 call    _thread_halt_self_with_continuation
F00664B8: 90102000                 mov     0, %o0
F00664BC: d0042260                 ld      [%l0+0x260], %o0
F00664C0: d002218c                 ld      [%o0+0x18C], %o0
F00664C4: 808a2003                 btst    3, %o0
F00664C8: 12bffffb                 bne     loc_F00664B4
F00664CC: 808e6400                 btst    0x400, %i1
F00664D0: 12800024                 bne     loc_F0066560
F00664D4: f4262004                 st      %i2, [%i0+4]
F00664D8: 90100018                 mov     %i0, %o0
F00664DC: 92100019                 mov     %i1, %o1
F00664E0: 7ffffe5f                 call    _msg_receive
F00664E4: 9410001c                 mov     %i4, %o2
F00664E8: 10800022                 ba      locret_F0066570
F00664EC: b0100008                 mov     %o0, %i0
F00664F0: 90122004                 bset    4, %o0
F00664F4: 80a48008                 cmp     %l2, %o0
F00664F8: 1280001b                 bne     loc_F0066564
F00664FC: 90100012                 mov     %l2, %o0
F0066500: d007bff4                 ld      [%fp+var_C], %o0
F0066504: 10800017                 ba      loc_F0066560
F0066508: d0262004                 st      %o0, [%i0+4]
F006650C: d207bff4                 ld      [%fp+var_C], %o1
F0066510: d0026018                 ld      [%o1+0x18], %o0
F0066514: 80a2001a                 cmp     %o0, %i2
F0066518: 28800007                 bleu,a  loc_F0066534
F006651C: 92100015                 mov     %l5, %o1
F0066520: 7fffba42                 call    _ipc_kmsg_destroy
F0066524: 90100009                 mov     %o1, %o0
F0066528: 11040010                 sethi   0x10004000, %o0
F006652C: 1080000e                 ba      loc_F0066564
F0066530: 90122004                 bset    4, %o0
F0066534: d007bff4                 ld      [%fp+var_C], %o0
F0066538: 7fffc4f5                 call    _ipc_kmsg_copyout_compat
F006653C: 94100017                 mov     %l7, %o2
F0066540: d207bff4                 ld      [%fp+var_C], %o1
F0066544: d4026018                 ld      [%o1+0x18], %o2
F0066548: a4100008                 mov     %o0, %l2
F006654C: d6026010                 ld      [%o1+0x10], %o3
F0066550: 90100018                 mov     %i0, %o0
F0066554: 9402800b                 add     %o2, %o3, %o2
F0066558: 7fffbbb3                 call    _ipc_kmsg_put_to_kernel
F006655C: d4226018                 st      %o2, [%o1+0x18]
F0066560: 90100012                 mov     %l2, %o0
F0066564: 7fffeb3f                 call    _msg_return_translate
F0066568: 01000000                 nop
F006656C: b0100008                 mov     %o0, %i0
F0066570: 81c7e008                 ret
F0066574: 81e80000                 restore
