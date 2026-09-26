F00655C4: 9de3bf98                 save    %sp, -0x68, %sp
F00655C8: a2100018                 mov     %i0, %l1
F00655CC: 40000aa9                 call    _kalloc
F00655D0: 90102800                 mov     0x800, %o0
F00655D4: b0920000                 orcc    %o0, %g0, %i0
F00655D8: 12800007                 bne     loc_F00655F4
F00655DC: a0102800                 mov     0x800, %l0
F00655E0: 113c043e                 sethi   %hi(aIpcKobjectServ), %o0! "ipc_kobject_server: dropping request\n"
F00655E4: 7ffebc1d                 call    _printf
F00655E8: 90122160                 bset    %lo(aIpcKobjectServ), %o0! "ipc_kobject_server: dropping request\n"
F00655EC: 10800089                 ba      loc_F0065810
F00655F0: 90100011                 mov     %l1, %o0
F00655F4: e0262008                 st      %l0, [%i0+8]
F00655F8: c026200c                 clr     [%i0+0xC]
F00655FC: c0262010                 clr     [%i0+0x10]
F0065600: d2046014                 ld      [%l1+0x14], %o1
F0065604: 1100003f90122300         set     0xFF00, %o0
F006560C: 920a4008                 and     %o1, %o0, %o1
F0065610: 93326008                 srl     %o1, 8, %o1
F0065614: d2262014                 st      %o1, [%i0+0x14]
F0065618: 90102020                 mov     0x20, %o0 ! ' '
F006561C: d0262018                 st      %o0, [%i0+0x18]
F0065620: d0046020                 ld      [%l1+0x20], %o0
F0065624: d026201c                 st      %o0, [%i0+0x1C]
F0065628: c0262020                 clr     [%i0+0x20]
F006562C: c0262024                 clr     [%i0+0x24]
F0065630: d0046028                 ld      [%l1+0x28], %o0
F0065634: 90022064                 inc     0x64, %o0 ! 'd'
F0065638: d0262028                 st      %o0, [%i0+0x28]
F006563C: 113c043e                 sethi   %hi(dword_F010F988), %o0
F0065640: d2022188                 ld      [%o0+%lo(dword_F010F988)], %o1
F0065644: 90100011                 mov     %l1, %o0
F0065648: 40001899                 call    _netipc_msg_send
F006564C: d226202c                 st      %o1, [%i0+0x2C]
F0065650: 80a22000                 cmp     %o0, 0
F0065654: 12800027                 bne     loc_F00656F0
F0065658: 90103ecf                 mov     -0x131, %o0
F006565C: a0046014                 add     %l1, 0x14, %l0
F0065660: 40006b1c                 call    _mach_server_routine
F0065664: 90100010                 mov     %l0, %o0
F0065668: 94920000                 orcc    %o0, %g0, %o2
F006566C: 12800016                 bne     loc_F00656C4
F0065670: 90046014                 add     %l1, 0x14, %o0
F0065674: 400062aa                 call    _mach_port_server_routine
F0065678: 90100010                 mov     %l0, %o0
F006567C: 94920000                 orcc    %o0, %g0, %o2
F0065680: 12800011                 bne     loc_F00656C4
F0065684: 90046014                 add     %l1, 0x14, %o0
F0065688: 40005f64                 call    _mach_host_server_routine
F006568C: 90100010                 mov     %l0, %o0
F0065690: 94920000                 orcc    %o0, %g0, %o2
F0065694: 1280000c                 bne     loc_F00656C4
F0065698: 90046014                 add     %l1, 0x14, %o0
F006569C: 40006df5                 call    _mach_debug_server_routine
F00656A0: 90100010                 mov     %l0, %o0
F00656A4: 94920000                 orcc    %o0, %g0, %o2
F00656A8: 12800007                 bne     loc_F00656C4
F00656AC: 90046014                 add     %l1, 0x14, %o0
F00656B0: 4000b216                 call    _driverServer_server_routine
F00656B4: 90100010                 mov     %l0, %o0
F00656B8: 94920000                 orcc    %o0, %g0, %o2
F00656BC: 02800006                 be      loc_F00656D4
F00656C0: 90046014                 add     %l1, 0x14, %o0
F00656C4: 9fc28000                 call    %o2
F00656C8: 92062014                 add     %i0, 0x14, %o1
F00656CC: 1080000b                 ba      loc_F00656F8
F00656D0: d00c6017                 ldub    [%l1+0x17], %o0
F00656D4: 90100010                 mov     %l0, %o0
F00656D8: 40000080                 call    _ipc_kobject_notify
F00656DC: 92062014                 add     %i0, 0x14, %o1
F00656E0: 80a22000                 cmp     %o0, 0
F00656E4: 32800005                 bne,a   loc_F00656F8
F00656E8: d00c6017                 ldub    [%l1+0x17], %o0
F00656EC: 90103ed1                 mov     -0x12F, %o0
F00656F0: d0262030                 st      %o0, [%i0+0x30]
F00656F4: d00c6017                 ldub    [%l1+0x17], %o0
F00656F8: 80a22011                 cmp     %o0, 0x11
F00656FC: 02800006                 be      loc_F0065714
F0065700: a004601c                 add     %l1, 0x1C, %l0
F0065704: 80a22012                 cmp     %o0, 0x12
F0065708: 02800007                 be      loc_F0065724
F006570C: 113c043e                 sethi   -0xFEF0800, %o0
F0065710: 30800009                 ba,a    loc_F0065734
F0065714: 7fffd682                 call    _ipc_port_release_send
F0065718: d004601c                 ld      [%l1+0x1C], %o0
F006571C: 10800009                 ba      loc_F0065740
F0065720: c0240000                 clr     [%l0]
F0065724: 7fffd6c3                 call    _ipc_port_release_sonce
F0065728: d004601c                 ld      [%l1+0x1C], %o0! char *
F006572C: 10800005                 ba      loc_F0065740
F0065730: c0240000                 clr     [%l0]
F0065734: 7ffebe8f                 call    _panic
F0065738: 90122190                 bset    0x190, %o0
F006573C: c0240000                 clr     [%l0]
F0065740: e0062030                 ld      [%i0+0x30], %l0
F0065744: 80a42000                 cmp     %l0, 0
F0065748: 02800004                 be      loc_F0065758
F006574C: 80a43ecf                 cmp     %l0, -0x131
F0065750: 3280001d                 bne,a   loc_F00657C4
F0065754: c0246020                 clr     [%l1+0x20]
F0065758: c0246010                 clr     [%l1+0x10]
F006575C: d0046008                 ld      [%l1+8], %o0
F0065760: 80a22100                 cmp     %o0, 0x100
F0065764: 32800009                 bne,a   loc_F0065788
F0065768: d2046008                 ld      [%l1+8], %o1
F006576C: 133c04ef                 sethi   %hi(_ipc_kmsg_cache), %o1
F0065770: d0026348                 ld      [%o1+%lo(_ipc_kmsg_cache)], %o0
F0065774: 80a22000                 cmp     %o0, 0
F0065778: 32800004                 bne,a   loc_F0065788
F006577C: d2046008                 ld      [%l1+8], %o1
F0065780: 10800013                 ba      loc_F00657CC
F0065784: e2226348                 st      %l1, [%o1+%lo(_ipc_kmsg_cache)]
F0065788: 80a26000                 cmp     %o1, 0
F006578C: 14800006                 bg      loc_F00657A4
F0065790: 01000000                 nop
F0065794: 7fffbe9b                 call    _ipc_kmsg_free
F0065798: 90100011                 mov     %l1, %o0
F006579C: 1080000d                 ba      loc_F00657D0
F00657A0: 80a43ecf                 cmp     %l0, -0x131
F00657A4: 40000a7f                 call    _kfree
F00657A8: 90100011                 mov     %l1, %o0
F00657AC: 10800009                 ba      loc_F00657D0
F00657B0: 80a43ecf                 cmp     %l0, -0x131
F00657B4: 40000a7b                 call    _kfree
F00657B8: 90100018                 mov     %i0, %o0
F00657BC: 10800017                 ba      locret_F0065818
F00657C0: b0102000                 mov     0, %i0
F00657C4: 7fffbd99                 call    _ipc_kmsg_destroy
F00657C8: 90100011                 mov     %l1, %o0
F00657CC: 80a43ecf                 cmp     %l0, -0x131
F00657D0: 3280000a                 bne,a   loc_F00657F8
F00657D4: d006201c                 ld      [%i0+0x1C], %o0
F00657D8: d2062008                 ld      [%i0+8], %o1
F00657DC: 80a26000                 cmp     %o1, 0
F00657E0: 14bffff5                 bg      loc_F00657B4
F00657E4: 01000000                 nop
F00657E8: 7fffbe86                 call    _ipc_kmsg_free
F00657EC: 90100018                 mov     %i0, %o0
F00657F0: 1080000a                 ba      locret_F0065818
F00657F4: b0102000                 mov     0, %i0
F00657F8: 80a22000                 cmp     %o0, 0
F00657FC: 02800004                 be      loc_F006580C
F0065800: 80a23fff                 cmp     %o0, -1
F0065804: 12800005                 bne     locret_F0065818
F0065808: 01000000                 nop
F006580C: 90100018                 mov     %i0, %o0
F0065810: 7fffbd86                 call    _ipc_kmsg_destroy
F0065814: b0102000                 mov     0, %i0
F0065818: 81c7e008                 ret
F006581C: 81e80000                 restore
