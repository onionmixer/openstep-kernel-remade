F00B973C: 9de3bf98                 save    %sp, -0x68, %sp
F00B9740: aa0e201f                 and     %i0, 0x1F, %l5
F00B9744: 912d6004                 sll     %l5, 4, %o0
F00B9748: 90020015                 add     %o0, %l5, %o0
F00B974C: 912a2003                 sll     %o0, 3, %o0
F00B9750: 133c04fb92126260         set     _zs_tty, %o1
F00B9758: a2020009                 add     %o0, %o1, %l1
F00B975C: d0046034                 ld      [%l1+0x34], %o0
F00B9760: 80a22000                 cmp     %o0, 0
F00B9764: 12800004                 bne     loc_F00B9774
F00B9768: a6100018                 mov     %i0, %l3
F00B976C: 108000b3                 ba      locret_F00B9A38
F00B9770: b0102006                 mov     6, %i0
F00B9774: 90102002                 mov     2, %o0
F00B9778: d02c6047                 stb     %o0, [%l1+0x47]
F00B977C: 113c02e8901222e0         set     _zsstart, %o0
F00B9784: d2146038                 lduh    [%l1+0x38], %o1
F00B9788: d0246024                 st      %o0, [%l1+0x24]
F00B978C: e0046034                 ld      [%l1+0x34], %l0
F00B9790: 920a601f                 and     %o1, 0x1F, %o1
F00B9794: 912a6003                 sll     %o1, 3, %o0
F00B9798: 90020009                 add     %o0, %o1, %o0
F00B979C: 912a2003                 sll     %o0, 3, %o0
F00B97A0: 90220009                 sub     %o0, %o1, %o0
F00B97A4: 912a2002                 sll     %o0, 2, %o0
F00B97A8: 133c04fc92126160         set     _zsaline, %o1
F00B97B0: 7fff74ef                 call    _splzs
F00B97B4: a8020009                 add     %o0, %o1, %l4
F00B97B8: a4100008                 mov     %o0, %l2
F00B97BC: e8242018                 st      %l4, [%l0+0x18]
F00B97C0: 90100010                 mov     %l0, %o0
F00B97C4: 133c047e                 sethi   %hi(_zsops_async), %o1
F00B97C8: 40000670                 call    _zsopinit
F00B97CC: 921262f0                 bset    %lo(_zsops_async), %o1
F00B97D0: 7fff7555                 call    _splx
F00B97D4: 90100012                 mov     %l2, %o0
F00B97D8: 133c047e                 sethi   %hi(dword_F011FB08), %o1
F00B97DC: d0026308                 ld      [%o1+%lo(dword_F011FB08)], %o0
F00B97E0: 80a22000                 cmp     %o0, 0
F00B97E4: 02800008                 be      loc_F00B9804
F00B97E8: 113c02ea                 sethi   %hi(_zspoll), %o0
F00B97EC: c0226308                 clr     [%o1+%lo(dword_F011FB08)]
F00B97F0: 133c047e                 sethi   %hi(_zsticks), %o1
F00B97F4: d40262ec                 ld      [%o1+%lo(_zsticks)], %o2
F00B97F8: 90122060                 bset    %lo(_zspoll), %o0! int
F00B97FC: 7ffd420b                 call    _timeout
F00B9800: 92102000                 mov     0, %o1
F00B9804: 113c0483                 sethi   %hi(_kbddev), %o0
F00B9808: 932e2010                 sll     %i0, 16, %o1
F00B980C: d0522224                 ldsh    [%o0+%lo(_kbddev)], %o0
F00B9810: 933a6010                 sra     %o1, 16, %o1
F00B9814: 80a24008                 cmp     %o1, %o0
F00B9818: 12800008                 bne     loc_F00B9838
F00B981C: 113c0483                 sethi   -0xFEDF400, %o0
F00B9820: 113c0483                 sethi   %hi(_kbddevopen), %o0
F00B9824: d0022228                 ld      [%o0+%lo(_kbddevopen)], %o0
F00B9828: 80a22000                 cmp     %o0, 0
F00B982C: 12800083                 bne     locret_F00B9A38
F00B9830: b0102000                 mov     0, %i0
F00B9834: 113c0483                 sethi   -0xFEDF400, %o0
F00B9838: 932ce010                 sll     %l3, 16, %o1
F00B983C: d0522224                 ldsh    [%o0+0x224], %o0
F00B9840: 933a6010                 sra     %o1, 16, %o1
F00B9844: 80a24008                 cmp     %o1, %o0
F00B9848: 12800003                 bne     loc_F00B9854
F00B984C: 90102014                 mov     0x14, %o0
F00B9850: d0352004                 sth     %o0, [%l4+4]
F00B9854: 7fff74d9                 call    _spltty
F00B9858: 01000000                 nop
F00B985C: a4100008                 mov     %o0, %l2
F00B9860: d0046040                 ld      [%l1+0x40], %o0
F00B9864: 90122002                 bset    2, %o0
F00B9868: 808a2004                 btst    4, %o0
F00B986C: 1280001f                 bne     loc_F00B98E8
F00B9870: d0246040                 st      %o0, [%l1+0x40]
F00B9874: c0352110                 clrh    [%l4+0x110]
F00B9878: c0352112                 clrh    [%l4+0x112]
F00B987C: c0352008                 clrh    [%l4+8]
F00B9880: 7ffd7413                 call    _ttychars
F00B9884: 90100011                 mov     %l1, %o0
F00B9888: 113c04fb                 sethi   %hi(_rconsdev), %o0
F00B988C: 932ce010                 sll     %l3, 16, %o1
F00B9890: d0522248                 ldsh    [%o0+%lo(_rconsdev)], %o0
F00B9894: 933a6010                 sra     %o1, 16, %o1
F00B9898: 80a24008                 cmp     %o1, %o0
F00B989C: 02800007                 be      loc_F00B98B8
F00B98A0: 01000000                 nop
F00B98A4: 113c0483                 sethi   %hi(_kbddev), %o0
F00B98A8: d0522224                 ldsh    [%o0+%lo(_kbddev)], %o0
F00B98AC: 80a24008                 cmp     %o1, %o0
F00B98B0: 32800006                 bne,a   loc_F00B98C8
F00B98B4: 9010200d                 mov     0xD, %o0
F00B98B8: 7fffff7c                 call    _zsgetspeed
F00B98BC: 90100009                 mov     %o1, %o0
F00B98C0: 10800003                 ba      loc_F00B98CC
F00B98C4: d02c6049                 stb     %o0, [%l1+0x49]
F00B98C8: d02c6049                 stb     %o0, [%l1+0x49]
F00B98CC: d02c604a                 stb     %o0, [%l1+0x4A]
F00B98D0: 901020d8                 mov     0xD8, %o0
F00B98D4: d024603c                 st      %o0, [%l1+0x3C]
F00B98D8: 400001b1                 call    _zsparam
F00B98DC: 90100011                 mov     %l1, %o0
F00B98E0: 1080001b                 ba      loc_F00B994C
F00B98E4: 90100011                 mov     %l1, %o0
F00B98E8: 808a2080                 btst    0x80, %o0
F00B98EC: 0280000c                 be      loc_F00B991C
F00B98F0: 113c04cf                 sethi   %hi(_active_u), %o0
F00B98F4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00B98F8: d002201c                 ld      [%o0+0x1C], %o0
F00B98FC: d0522002                 ldsh    [%o0+2], %o0
F00B9900: 80a22000                 cmp     %o0, 0
F00B9904: 02800007                 be      loc_F00B9920
F00B9908: 808ce080                 btst    0x80, %l3
F00B990C: 7fff7506                 call    _splx
F00B9910: 90100012                 mov     %l2, %o0
F00B9914: 10800049                 ba      locret_F00B9A38
F00B9918: b0102010                 mov     0x10, %i0
F00B991C: 808ce080                 btst    0x80, %l3
F00B9920: 0280000a                 be      loc_F00B9948
F00B9924: 11100000                 sethi   0x40000000, %o0
F00B9928: d2046040                 ld      [%l1+0x40], %o1
F00B992C: 808a4008                 btst    %o0, %o1
F00B9930: 12800007                 bne     loc_F00B994C
F00B9934: 90100011                 mov     %l1, %o0
F00B9938: 7fff74fb                 call    _splx
F00B993C: 90100012                 mov     %l2, %o0
F00B9940: 1080003e                 ba      locret_F00B9A38
F00B9944: b0102006                 mov     6, %i0
F00B9948: 90100011                 mov     %l1, %o0
F00B994C: 92102082                 mov     0x82, %o1
F00B9950: 400002db                 call    _zsmctl
F00B9954: 94102000                 mov     0, %o2
F00B9958: 808ce080                 btst    0x80, %l3
F00B995C: 02800006                 be      loc_F00B9974
F00B9960: 11100000                 sethi   0x40000000, %o0
F00B9964: d2046040                 ld      [%l1+0x40], %o1
F00B9968: 90122010                 bset    0x10, %o0
F00B996C: 92124008                 bset    %o0, %o1
F00B9970: d2246040                 st      %o1, [%l1+0x40]
F00B9974: 113c04fd901221d0         set     _zssoftCAR, %o0
F00B997C: d04d4008                 ldsb    [%l5+%o0], %o0
F00B9980: 80a22000                 cmp     %o0, 0
F00B9984: 3280000a                 bne,a   loc_F00B99AC
F00B9988: d0046040                 ld      [%l1+0x40], %o0
F00B998C: 90100011                 mov     %l1, %o0
F00B9990: 92102000                 mov     0, %o1
F00B9994: 400002ca                 call    _zsmctl
F00B9998: 94102003                 mov     3, %o2
F00B999C: 808a2008                 btst    8, %o0
F00B99A0: 02800006                 be      loc_F00B99B8
F00B99A4: 808e6004                 btst    4, %i1
F00B99A8: d0046040                 ld      [%l1+0x40], %o0
F00B99AC: 90122010                 bset    0x10, %o0
F00B99B0: d0246040                 st      %o0, [%l1+0x40]
F00B99B4: 808e6004                 btst    4, %i1
F00B99B8: 12800012                 bne     loc_F00B9A00
F00B99BC: 01000000                 nop
F00B99C0: d2046040                 ld      [%l1+0x40], %o1
F00B99C4: 808a6010                 btst    0x10, %o1
F00B99C8: 02800007                 be      loc_F00B99E4
F00B99CC: 11100000                 sethi   0x40000000, %o0
F00B99D0: 808a4008                 btst    %o0, %o1
F00B99D4: 0280000b                 be      loc_F00B9A00
F00B99D8: 808ce080                 btst    0x80, %l3
F00B99DC: 12800009                 bne     loc_F00B9A00
F00B99E0: 01000000                 nop
F00B99E4: 90126002                 or      %o1, 2, %o0
F00B99E8: d0246040                 st      %o0, [%l1+0x40]
F00B99EC: 90046040                 add     %l1, 0x40, %o0 ! '@'! unsigned int
F00B99F0: 7ffd6322                 call    _sleep
F00B99F4: 9210201c                 mov     0x1C, %o1
F00B99F8: 10bfff9b                 ba      loc_F00B9864
F00B99FC: d0046040                 ld      [%l1+0x40], %o0
F00B9A00: 7fff74c9                 call    _splx
F00B9A04: 90100012                 mov     %l2, %o0
F00B9A08: d24c6047                 ldsb    [%l1+0x47], %o1
F00B9A0C: 912ce010                 sll     %l3, 16, %o0
F00B9A10: 952a6001                 sll     %o1, 1, %o2
F00B9A14: 94028009                 add     %o2, %o1, %o2
F00B9A18: 952aa004                 sll     %o2, 4, %o2
F00B9A1C: 133c042e921260cc         set     _linesw, %o1
F00B9A24: d4028009                 ld      [%o2+%o1], %o2
F00B9A28: 913a2010                 sra     %o0, 16, %o0
F00B9A2C: 9fc28000                 call    %o2
F00B9A30: 92100011                 mov     %l1, %o1
F00B9A34: b0100008                 mov     %o0, %i0
F00B9A38: 81c7e008                 ret
F00B9A3C: 81e80000                 restore
