F00804F8: 9de3b788                 save    %sp, -0x878, %sp
F00804FC: d0062004                 ld      [%i0+4], %o0
F0080500: 80a22028                 cmp     %o0, 0x28 ! '('
F0080504: 12800011                 bne     loc_F0080548
F0080508: a0100019                 mov     %i1, %l0
F008050C: d0060000                 ld      [%i0], %o0
F0080510: 80a22000                 cmp     %o0, 0
F0080514: 0680000d                 bl      loc_F0080548
F0080518: 133c0445                 sethi   %hi(dword_F0111690), %o1
F008051C: d0062018                 ld      [%i0+0x18], %o0
F0080520: d2026290                 ld      [%o1+%lo(dword_F0111690)], %o1
F0080524: 80a20009                 cmp     %o0, %o1
F0080528: 12800009                 bne     loc_F008054C
F008052C: 90103ed0                 mov     -0x130, %o0
F0080530: d0062020                 ld      [%i0+0x20], %o0
F0080534: 133c0445                 sethi   %hi(dword_F0111694), %o1
F0080538: d2026294                 ld      [%o1+%lo(dword_F0111694)], %o1
F008053C: 80a20009                 cmp     %o0, %o1
F0080540: 02800005                 be      loc_F0080554
F0080544: a404202c                 add     %l0, 0x2C, %l2 ! ','
F0080548: 90103ed0                 mov     -0x130, %o0
F008054C: 10800062                 ba      locret_F00806D4
F0080550: d024201c                 st      %o0, [%l0+0x1C]
F0080554: e427b7f4                 st      %l2, [%fp+var_80C]
F0080558: 901020aa                 mov     0xAA, %o0
F008055C: d206201c                 ld      [%i0+0x1C], %o1
F0080560: 80a260aa                 cmp     %o1, 0xAA
F0080564: 1a800003                 bcc     loc_F0080570
F0080568: d027b7f0                 st      %o0, [%fp+var_810]
F008056C: d227b7f0                 st      %o1, [%fp+var_810]
F0080570: a607b7f8                 add     %fp, var_808, %l3
F0080574: e627b7ec                 st      %l3, [%fp+var_814]
F0080578: 90102100                 mov     0x100, %o0
F008057C: d2062024                 ld      [%i0+0x24], %o1
F0080580: 80a26100                 cmp     %o1, 0x100
F0080584: 1a800003                 bcc     loc_F0080590
F0080588: d027b7e8                 st      %o0, [%fp+__n]
F008058C: d227b7e8                 st      %o1, [%fp+__n]
F0080590: 7fff933f                 call    _convert_port_to_host
F0080594: d0062008                 ld      [%i0+8], %o0
F0080598: 9207b7f4                 add     %fp, var_80C, %o1
F008059C: 9407b7f0                 add     %fp, var_810, %o2
F00805A0: 9607b7ec                 add     %fp, var_814, %o3
F00805A4: 7fffe4e4                 call    _host_zone_free_space_info
F00805A8: 9807b7e8                 add     %fp, __n, %o4
F00805AC: 80a22000                 cmp     %o0, 0
F00805B0: 12800049                 bne     locret_F00806D4
F00805B4: d024201c                 st      %o0, [%l0+0x1C]
F00805B8: 133c0445                 sethi   %hi(dword_F0111698), %o1
F00805BC: d0026298                 ld      [%o1+%lo(dword_F0111698)], %o0
F00805C0: d0242020                 st      %o0, [%l0+0x20]
F00805C4: 92126298                 bset    %lo(dword_F0111698), %o1
F00805C8: d0026004                 ld      [%o1+4], %o0
F00805CC: a2102001                 mov     1, %l1
F00805D0: d407b7f4                 ld      [%fp+var_80C], %o2
F00805D4: d0242024                 st      %o0, [%l0+0x24]
F00805D8: d0026008                 ld      [%o1+8], %o0
F00805DC: 80a28012                 cmp     %o2, %l2
F00805E0: 02800008                 be      loc_F0080600
F00805E4: d0242028                 st      %o0, [%l0+0x28]
F00805E8: d424202c                 st      %o2, [%l0+0x2C]
F00805EC: d0042020                 ld      [%l0+0x20], %o0
F00805F0: a2102000                 mov     0, %l1
F00805F4: 900a3ff7                 and     %o0, -9, %o0
F00805F8: 90122002                 bset    2, %o0
F00805FC: d0242020                 st      %o0, [%l0+0x20]
F0080600: d007b7f0                 ld      [%fp+var_810], %o0
F0080604: 94102004                 mov     4, %o2
F0080608: 932a2001                 sll     %o0, 1, %o1
F008060C: 92024008                 add     %o1, %o0, %o1
F0080610: d0042020                 ld      [%l0+0x20], %o0
F0080614: 808a2008                 btst    8, %o0
F0080618: 02800003                 be      loc_F0080624
F008061C: d2242028                 st      %o1, [%l0+0x28]
F0080620: 952a6002                 sll     %o1, 2, %o2
F0080624: b002a038                 add     %o2, 0x38, %i0 ! '8'
F0080628: 113c0445                 sethi   %hi(dword_F01116A4), %o0
F008062C: d20222a4                 ld      [%o0+%lo(dword_F01116A4)], %o1
F0080630: 9404000a                 add     %l0, %o2, %o2
F0080634: d222a02c                 st      %o1, [%o2+0x2C]
F0080638: 901222a4                 bset    %lo(dword_F01116A4), %o0
F008063C: d2022004                 ld      [%o0+4], %o1
F0080640: a002b808                 add     %o2, -0x7F8, %l0
F0080644: d607b7ec                 ld      [%fp+var_814], %o3
F0080648: d222a030                 st      %o1, [%o2+0x30]
F008064C: d0022008                 ld      [%o0+8], %o0
F0080650: 80a2c013                 cmp     %o3, %l3
F0080654: 02800009                 be      loc_F0080678
F0080658: d022a034                 st      %o0, [%o2+0x34]
F008065C: d622a038                 st      %o3, [%o2+0x38]
F0080660: d002a02c                 ld      [%o2+0x2C], %o0
F0080664: a2102000                 mov     0, %l1
F0080668: 900a3ff7                 and     %o0, -9, %o0
F008066C: 90122002                 bset    2, %o0
F0080670: 10800007                 ba      loc_F008068C
F0080674: d022a02c                 st      %o0, [%o2+0x2C]
F0080678: 9002a038                 add     %o2, 0x38, %o0 ! '8'! __dst
F008067C: d407b7e8                 ld      [%fp+__n], %o2! __n
F0080680: 9210000b                 mov     %o3, %o1! __src
F0080684: 7ffe1b07                 call    _memcpy
F0080688: 952aa003                 sll     %o2, 3, %o2
F008068C: d407b7e8                 ld      [%fp+__n], %o2
F0080690: d2042824                 ld      [%l0+0x824], %o1
F0080694: 912aa001                 sll     %o2, 1, %o0
F0080698: 808a6008                 btst    8, %o1
F008069C: 02800005                 be      loc_F00806B0
F00806A0: d024282c                 st      %o0, [%l0+0x82C]
F00806A4: 912aa003                 sll     %o2, 3, %o0
F00806A8: 10800003                 ba      loc_F00806B4
F00806AC: b0060008                 add     %i0, %o0, %i0
F00806B0: b0062004                 inc     4, %i0
F00806B4: 80a46000                 cmp     %l1, 0
F00806B8: 12800006                 bne     loc_F00806D0
F00806BC: a0100019                 mov     %i1, %l0
F00806C0: d0040000                 ld      [%l0], %o0
F00806C4: 13200000                 sethi   0x80000000, %o1
F00806C8: 90120009                 bset    %o1, %o0
F00806CC: d0240000                 st      %o0, [%l0]
F00806D0: f0242004                 st      %i0, [%l0+4]
F00806D4: 81c7e008                 ret
F00806D8: 81e80000                 restore
