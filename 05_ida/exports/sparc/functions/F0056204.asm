F0056204: 9de3bf98                 save    %sp, -0x68, %sp
F0056208: f406201c                 ld      [%i0+0x1C], %i2
F005620C: 1500003f                 sethi   0xFC00, %o2
F0056210: e2062014                 ld      [%i0+0x14], %l1
F0056214: 9412a300                 bset    0x300, %o2
F0056218: e0062020                 ld      [%i0+0x20], %l0
F005621C: 9010001a                 mov     %i2, %o0
F0056220: a60c60ff                 and     %l1, 0xFF, %l3
F0056224: 92100013                 mov     %l3, %o1
F0056228: 940c400a                 and     %l1, %o2, %o2
F005622C: 40000e34                 call    _ipc_object_copyin_from_kernel
F0056230: a532a008                 srl     %o2, 8, %l2
F0056234: 80a42000                 cmp     %l0, 0
F0056238: 02800006                 be      loc_F0056250
F005623C: 80a43fff                 cmp     %l0, -1
F0056240: 02800004                 be      loc_F0056250
F0056244: 90100010                 mov     %l0, %o0
F0056248: 40000e2d                 call    _ipc_object_copyin_from_kernel
F005624C: 92100012                 mov     %l2, %o1
F0056250: 1120000090122013         set     -0x7FFFFFED, %o0
F0056258: 80a44008                 cmp     %l1, %o0
F005625C: 12800006                 bne     loc_F0056274
F0056260: 01000000                 nop
F0056264: 11200000a2122011         set     -0x7FFFFFEF, %l1
F005626C: 1080000f                 ba      loc_F00562A8
F0056270: e2262014                 st      %l1, [%i0+0x14]
F0056274: 40000dd2                 call    _ipc_object_copyin_type
F0056278: 90100013                 mov     %l3, %o0
F005627C: a0100008                 mov     %o0, %l0
F0056280: 40000dcf                 call    _ipc_object_copyin_type
F0056284: 90100012                 mov     %l2, %o0
F0056288: 133fffc0                 sethi   -0x10000, %o1
F005628C: 920c4009                 and     %l1, %o1, %o1
F0056290: 912a2008                 sll     %o0, 8, %o0
F0056294: a0140008                 bset    %o0, %l0
F0056298: a2124010                 or      %o1, %l0, %l1
F005629C: 80a46000                 cmp     %l1, 0
F00562A0: 1680005a                 bge     locret_F0056408
F00562A4: e2262014                 st      %l1, [%i0+0x14]
F00562A8: d0062018                 ld      [%i0+0x18], %o0
F00562AC: a206202c                 add     %i0, 0x2C, %l1 ! ','
F00562B0: 90022014                 inc     0x14, %o0
F00562B4: b2060008                 add     %i0, %o0, %i1
F00562B8: 80a44019                 cmp     %l1, %i1
F00562BC: 1a800053                 bcc     locret_F0056408
F00562C0: 37100000                 sethi   0x40000000, %i3
F00562C4: d0044000                 ld      [%l1], %o0
F00562C8: a6100011                 mov     %l1, %l3
F00562CC: a1322003                 srl     %o0, 3, %l0
F00562D0: a5322002                 srl     %o0, 2, %l2
F00562D4: a48ca001                 andcc   %l2, 1, %l2
F00562D8: 02800007                 be      loc_F00562F4
F00562DC: a00c2001                 and     %l0, 1, %l0
F00562E0: ec146004                 lduh    [%l1+4], %l6
F00562E4: d2146006                 lduh    [%l1+6], %o1
F00562E8: ea046008                 ld      [%l1+8], %l5
F00562EC: 10800008                 ba      loc_F005630C
F00562F0: a204600c                 inc     0xC, %l1
F00562F4: ec0c4000                 ldub    [%l1], %l6
F00562F8: 93322010                 srl     %o0, 16, %o1
F00562FC: 920a60ff                 and     %o1, 0xFF, %o1
F0056300: ab322004                 srl     %o0, 4, %l5
F0056304: aa0d6fff                 and     %l5, 0xFFF, %l5
F0056308: a2046004                 inc     4, %l1
F005630C: 7ffec07d                 call    _umul
F0056310: 90100015                 mov     %l5, %o0
F0056314: 9205bff0                 add     %l6, -0x10, %o1
F0056318: 80a26005                 cmp     %o1, 5
F005631C: 28800003                 bleu,a  loc_F0056328
F0056320: 92102001                 mov     1, %o1
F0056324: 92102000                 mov     0, %o1
F0056328: 80a42000                 cmp     %l0, 0
F005632C: 90022007                 inc     7, %o0
F0056330: 02800007                 be      loc_F005634C
F0056334: 91322003                 srl     %o0, 3, %o0
F0056338: a0100011                 mov     %l1, %l0
F005633C: 90022003                 inc     3, %o0
F0056340: 900a3ffc                 and     %o0, -4, %o0
F0056344: 10800004                 ba      loc_F0056354
F0056348: a2044008                 add     %l1, %o0, %l1
F005634C: e0044000                 ld      [%l1], %l0
F0056350: a2046004                 inc     4, %l1
F0056354: 80a26000                 cmp     %o1, 0
F0056358: 0280002a                 be      loc_F0056400
F005635C: 80a44019                 cmp     %l1, %i1
F0056360: 40000d97                 call    _ipc_object_copyin_type
F0056364: 90100016                 mov     %l6, %o0
F0056368: 80a4a000                 cmp     %l2, 0
F005636C: a8100008                 mov     %o0, %l4
F0056370: 02800004                 be      loc_F0056380
F0056374: ae100010                 mov     %l0, %l7
F0056378: 10800003                 ba      loc_F0056384
F005637C: e834e004                 sth     %l4, [%l3+4]
F0056380: e82cc000                 stb     %l4, [%l3]
F0056384: a4102000                 mov     0, %l2
F0056388: 80a48015                 cmp     %l2, %l5
F005638C: 1a80001d                 bcc     loc_F0056400
F0056390: 80a44019                 cmp     %l1, %i1
F0056394: a6102000                 mov     0, %l3
F0056398: e004c017                 ld      [%l3+%l7], %l0
F005639C: 80a42000                 cmp     %l0, 0
F00563A0: 22800014                 be,a    loc_F00563F0
F00563A4: a404a001                 inc     %l2
F00563A8: 80a43fff                 cmp     %l0, -1
F00563AC: 22800011                 be,a    loc_F00563F0
F00563B0: a404a001                 inc     %l2
F00563B4: 90100010                 mov     %l0, %o0
F00563B8: 40000dd1                 call    _ipc_object_copyin_from_kernel
F00563BC: 92100016                 mov     %l6, %o1
F00563C0: 80a52010                 cmp     %l4, 0x10
F00563C4: 3280000b                 bne,a   loc_F00563F0
F00563C8: a404a001                 inc     %l2
F00563CC: 90100010                 mov     %l0, %o0
F00563D0: 4000127d                 call    _ipc_port_check_circularity
F00563D4: 9210001a                 mov     %i2, %o1
F00563D8: 80a22000                 cmp     %o0, 0
F00563DC: 02800005                 be      loc_F00563F0
F00563E0: a404a001                 inc     %l2
F00563E4: d0062014                 ld      [%i0+0x14], %o0
F00563E8: 9012001b                 bset    %i3, %o0
F00563EC: d0262014                 st      %o0, [%i0+0x14]
F00563F0: 80a48015                 cmp     %l2, %l5
F00563F4: 0abfffe9                 bcs     loc_F0056398
F00563F8: a604e004                 inc     4, %l3
F00563FC: 80a44019                 cmp     %l1, %i1
F0056400: 2abfffb2                 bcs,a   loc_F00562C8
F0056404: d0044000                 ld      [%l1], %o0
F0056408: 81c7e008                 ret
F005640C: 81e80000                 restore
