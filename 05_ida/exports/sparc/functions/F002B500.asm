F002B500: 9de3bf70                 save    %sp, -0x90, %sp
F002B504: 40000244                 call    _if_type
F002B508: 90100019                 mov     %i1, %o0! __s1
F002B50C: 133c0430                 sethi   %hi(a416mbTokenRing_0), %o1! "4/16Mb Token-Ring"
F002B510: 7fff7327                 call    _strcmp
F002B514: 92126280                 bset    %lo(a416mbTokenRing_0), %o1! "4/16Mb Token-Ring"
F002B518: 80a22000                 cmp     %o0, 0
F002B51C: 1280007d                 bne     locret_F002B710
F002B520: 01000000                 nop
F002B524: 40000234                 call    _if_unit
F002B528: 90100019                 mov     %i1, %o0
F002B52C: d2060000                 ld      [%i0], %o1
F002B530: a4100008                 mov     %o0, %l2
F002B534: 80a48009                 cmp     %l2, %o1
F002B538: 12800076                 bne     locret_F002B710
F002B53C: 01000000                 nop
F002B540: 40000231                 call    _if_name
F002B544: 90100019                 mov     %i1, %o0
F002B548: a6100008                 mov     %o0, %l3
F002B54C: 40000236                 call    _if_mtu
F002B550: 90100019                 mov     %i1, %o0
F002B554: d2062008                 ld      [%i0+8], %o1
F002B558: 80a26000                 cmp     %o1, 0
F002B55C: 02800004                 be      loc_F002B56C
F002B560: a0023ff8                 add     %o0, -8, %l0
F002B564: 10800004                 ba      loc_F002B574
F002B568: 90100009                 mov     %o1, %o0
F002B56C: 113c0430                 sethi   %hi(dword_F010C27C), %o0
F002B570: d002227c                 ld      [%o0+%lo(dword_F010C27C)], %o0
F002B574: 80a20010                 cmp     %o0, %l0
F002B578: 34800002                 bg,a    loc_F002B580
F002B57C: 90100010                 mov     %l0, %o0
F002B580: a0100008                 mov     %o0, %l0
F002B584: 4000f2bb                 call    _kalloc
F002B588: 90102020                 mov     0x20, %o0 ! ' '
F002B58C: e423a05c                 st      %l2, [%sp+0x90+var_34]
F002B590: 133c03d3921260a8         set     aInternetProtoc_1, %o1! "Internet Protocol"
F002B598: d223a060                 st      %o1, [%sp+0x90+var_30]
F002B59C: e023a064                 st      %l0, [%sp+0x90+var_2C]
F002B5A0: 92102002                 mov     2, %o1
F002B5A4: d223a068                 st      %o1, [%sp+0x90+var_28]
F002B5A8: 13000004                 sethi   0x1000, %o1
F002B5AC: d223a06c                 st      %o1, [%sp+0x90+var_24]
F002B5B0: 900a3ffc                 and     %o0, -4, %o0
F002B5B4: d023a070                 st      %o0, [%sp+0x90+var_20]
F002B5B8: 90102000                 mov     0, %o0
F002B5BC: 133c00ab92126198         set     dword_F002AD98, %o1
F002B5C4: 153c00aa9412a17c         set     sub_F002A97C, %o2
F002B5CC: 173c00ab                 sethi   %hi(sub_F002AD28), %o3
F002B5D0: 193c00aa                 sethi   %hi(sub_F002ABE4), %o4
F002B5D4: 9612e128                 bset    %lo(sub_F002AD28), %o3
F002B5D8: 981323e4                 bset    %lo(sub_F002ABE4), %o4
F002B5DC: 4000027e                 call    _if_attach
F002B5E0: 9a100013                 mov     %l3, %o5
F002B5E4: 40000200                 call    _if_private
F002B5E8: a2100008                 mov     %o0, %l1
F002B5EC: c0220000                 clr     [%o0]
F002B5F0: d0062004                 ld      [%i0+4], %o0
F002B5F4: 808a2001                 btst    1, %o0
F002B5F8: 0280001b                 be      loc_F002B664
F002B5FC: 01000000                 nop
F002B600: 400001f9                 call    _if_private
F002B604: 90100011                 mov     %l1, %o0
F002B608: 94100008                 mov     %o0, %o2
F002B60C: d2028000                 ld      [%o2], %o1
F002B610: 90100011                 mov     %l1, %o0
F002B614: 92126001                 bset    1, %o1
F002B618: 400001f3                 call    _if_private
F002B61C: d2228000                 st      %o1, [%o2]
F002B620: 173c03d3                 sethi   %hi(_SRTablePrototype), %o3
F002B624: d802e098                 ld      [%o3+%lo(_SRTablePrototype)], %o4
F002B628: a0100008                 mov     %o0, %l0
F002B62C: 9612e098                 bset    %lo(_SRTablePrototype), %o3
F002B630: da02e004                 ld      [%o3+4], %o5! info
F002B634: 9007bfe8                 add     %fp, var_18, %o0! prototype
F002B638: d827bfe8                 st      %o4, [%fp+var_18]
F002B63C: d802e008                 ld      [%o3+8], %o4! capacity
F002B640: 92102000                 mov     0, %o1
F002B644: da27bfec                 st      %o5, [%fp+var_14]
F002B648: d602e00c                 ld      [%o3+0xC], %o3
F002B64C: 94102000                 mov     0, %o2
F002B650: d827bff0                 st      %o4, [%fp+var_10]
F002B654: 400306c4                 call    _NXCreateHashTable
F002B658: d627bff4                 st      %o3, [%fp+var_C]
F002B65C: 10800007                 ba      loc_F002B678
F002B660: d0242004                 st      %o0, [%l0+4]
F002B664: 400001e0                 call    _if_private
F002B668: 90100011                 mov     %l1, %o0
F002B66C: d2020000                 ld      [%o0], %o1
F002B670: 920a7ffe                 and     %o1, -2, %o1
F002B674: d2220000                 st      %o1, [%o0]
F002B678: d006200c                 ld      [%i0+0xC], %o0
F002B67C: 80a22007                 cmp     %o0, 7
F002B680: 04800006                 ble     loc_F002B698
F002B684: b0100008                 mov     %o0, %i0
F002B688: 400001d7                 call    _if_private
F002B68C: 90100011                 mov     %l1, %o0
F002B690: 1080000a                 ba      loc_F002B6B8
F002B694: 92102010                 mov     0x10, %o1
F002B698: 900e20ff                 and     %i0, 0xFF, %o0
F002B69C: 80a22006                 cmp     %o0, 6
F002B6A0: 38800002                 bgu,a   loc_F002B6A8
F002B6A4: b0102006                 mov     6, %i0
F002B6A8: 400001cf                 call    _if_private
F002B6AC: 90100011                 mov     %l1, %o0
F002B6B0: 932e2005                 sll     %i0, 5, %o1
F002B6B4: 92126010                 bset    0x10, %o1
F002B6B8: d22a2018                 stb     %o1, [%o0+0x18]
F002B6BC: 400001ca                 call    _if_private
F002B6C0: 90100011                 mov     %l1, %o0
F002B6C4: f2222014                 st      %i1, [%o0+0x14]
F002B6C8: 90100011                 mov     %l1, %o0
F002B6CC: 213c03d3                 sethi   %hi(_IFCONTROL_GETADDR), %l0! "getaddr"
F002B6D0: 400001c5                 call    _if_private
F002B6D4: a01420e8                 bset    %lo(_IFCONTROL_GETADDR), %l0! "getaddr"
F002B6D8: 94022008                 add     %o0, 8, %o2
F002B6DC: 90100019                 mov     %i1, %o0
F002B6E0: 4000014e                 call    _if_control
F002B6E4: 92100010                 mov     %l0, %o1
F002B6E8: 113c043090122298         set     aIpProtocolEnab_0, %o0! "IP protocol enabled for interface %s%d"...
F002B6F0: 92100013                 mov     %l3, %o1
F002B6F4: 7fffa3d9                 call    _printf
F002B6F8: 94100012                 mov     %l2, %o2
F002B6FC: 113c0430901222c0         set     aIeee8022NullSa, %o0! "IEEE 802.2 Null Sap protocol enabled fo"...
F002B704: 92100013                 mov     %l3, %o1
F002B708: 7fffa3d4                 call    _printf
F002B70C: 94100012                 mov     %l2, %o2
F002B710: 81c7e008                 ret
F002B714: 81e80000                 restore
