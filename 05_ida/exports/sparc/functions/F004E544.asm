F004E544: 9de3bf98                 save    %sp, -0x68, %sp
F004E548: d0162044                 lduh    [%i0+0x44], %o0
F004E54C: 808a204e                 btst    0x4E, %o0 ! 'N'
F004E550: 02800069                 be      locret_F004E6F4
F004E554: e8062050                 ld      [%i0+0x50], %l4
F004E558: d04d20d2                 ldsb    [%l4+0xD2], %o0
F004E55C: 80a22000                 cmp     %o0, 0
F004E560: 12800065                 bne     locret_F004E6F4
F004E564: 01000000                 nop
F004E568: e4062048                 ld      [%i0+0x48], %l2
F004E56C: e60520b8                 ld      [%l4+0xB8], %l3
F004E570: 90100012                 mov     %l2, %o0
F004E574: 7ffee023                 call    _udiv
F004E578: 92100013                 mov     %l3, %o1
F004E57C: a2100008                 mov     %o0, %l1
F004E580: d00520bc                 ld      [%l4+0xBC], %o0
F004E584: 7ffedfdf                 call    _umul
F004E588: 92100011                 mov     %l1, %o1
F004E58C: d4052018                 ld      [%l4+0x18], %o2
F004E590: a0100008                 mov     %o0, %l0
F004E594: d205201c                 ld      [%l4+0x1C], %o1
F004E598: 9010000a                 mov     %o2, %o0
F004E59C: 7ffedfd9                 call    _umul
F004E5A0: 922c4009                 andn    %l1, %o1, %o1
F004E5A4: 96100008                 mov     %o0, %o3
F004E5A8: 90100012                 mov     %l2, %o0
F004E5AC: 92100013                 mov     %l3, %o1
F004E5B0: d4052010                 ld      [%l4+0x10], %o2
F004E5B4: a004000b                 add     %l0, %o3, %l0
F004E5B8: 7ffee0ba                 call    _urem
F004E5BC: a004000a                 add     %l0, %o2, %l0
F004E5C0: 7ffee010                 call    _udiv
F004E5C4: d2052078                 ld      [%l4+0x78], %o1
F004E5C8: d2062040                 ld      [%i0+0x40], %o1
F004E5CC: d8052060                 ld      [%l4+0x60], %o4
F004E5D0: 96100008                 mov     %o0, %o3
F004E5D4: d4052030                 ld      [%l4+0x30], %o2
F004E5D8: 90100009                 mov     %o1, %o0
F004E5DC: 972ac00c                 sll     %o3, %o4, %o3
F004E5E0: d2052064                 ld      [%l4+0x64], %o1
F004E5E4: a004000b                 add     %l0, %o3, %l0
F004E5E8: 7fff57ce                 call    _bread
F004E5EC: 932c0009                 sll     %l0, %o1, %o1
F004E5F0: a2100008                 mov     %o0, %l1
F004E5F4: d0044000                 ld      [%l1], %o0
F004E5F8: 808a2004                 btst    4, %o0
F004E5FC: 22800005                 be,a    loc_F004E610
F004E600: d0162044                 lduh    [%i0+0x44], %o0
F004E604: 7fff5899                 call    _brelse
F004E608: 90100011                 mov     %l1, %o0
F004E60C: 3080003a                 ba,a    locret_F004E6F4
F004E610: 808a2046                 btst    0x46, %o0 ! 'F'
F004E614: 02800015                 be      loc_F004E668
F004E618: 213c04d4                 sethi   %hi(_iuniqtime), %l0
F004E61C: 40007fed                 call    _microtime
F004E620: 90142148                 or      %l0, %lo(_iuniqtime), %o0
F004E624: d0162044                 lduh    [%i0+0x44], %o0
F004E628: 808a2004                 btst    4, %o0
F004E62C: 02800003                 be      loc_F004E638
F004E630: d0042148                 ld      [%l0+%lo(_iuniqtime)], %o0
F004E634: d0262074                 st      %o0, [%i0+0x74]
F004E638: d0162044                 lduh    [%i0+0x44], %o0
F004E63C: 808a2002                 btst    2, %o0
F004E640: 02800003                 be      loc_F004E64C
F004E644: d0042148                 ld      [%l0+0x148], %o0
F004E648: d026207c                 st      %o0, [%i0+0x7C]
F004E64C: d0162044                 lduh    [%i0+0x44], %o0
F004E650: 808a2040                 btst    0x40, %o0 ! '@'
F004E654: 22800006                 be,a    loc_F004E66C
F004E658: 1100003f                 sethi   0xFC00, %o0
F004E65C: c026204c                 clr     [%i0+0x4C]
F004E660: d0042148                 ld      [%l0+0x148], %o0
F004E664: d0262084                 st      %o0, [%i0+0x84]
F004E668: 1100003f                 sethi   0xFC00, %o0
F004E66C: e0162044                 lduh    [%i0+0x44], %l0
F004E670: 901223b1                 bset    0x3B1, %o0
F004E674: a00c0008                 and     %l0, %o0, %l0
F004E678: d0062048                 ld      [%i0+0x48], %o0
F004E67C: e0362044                 sth     %l0, [%i0+0x44]
F004E680: 7ffee088                 call    _urem
F004E684: d2052078                 ld      [%l4+0x78], %o1
F004E688: 92062064                 add     %i0, 0x64, %o1 ! 'd'! __src
F004E68C: 94102080                 mov     0x80, %o2! __n
F004E690: 1700003f9612e1ff         set     0xFDFF, %o3
F004E698: a00c000b                 and     %l0, %o3, %l0
F004E69C: d8046020                 ld      [%l1+0x20], %o4
F004E6A0: 912a2007                 sll     %o0, 7, %o0! __dst
F004E6A4: e0362044                 sth     %l0, [%i0+0x44]
F004E6A8: a0030008                 add     %o4, %o0, %l0
F004E6AC: 7ffee2fd                 call    _memcpy
F004E6B0: 90100010                 mov     %l0, %o0
F004E6B4: d0062030                 ld      [%i0+0x30], %o0
F004E6B8: d0522124                 ldsh    [%o0+0x124], %o0
F004E6BC: 80a22000                 cmp     %o0, 0
F004E6C0: 02800006                 be      loc_F004E6D8
F004E6C4: 80a66000                 cmp     %i1, 0
F004E6C8: d01620e4                 lduh    [%i0+0xE4], %o0
F004E6CC: d0342004                 sth     %o0, [%l0+4]
F004E6D0: d01620e6                 lduh    [%i0+0xE6], %o0
F004E6D4: d0342006                 sth     %o0, [%l0+6]
F004E6D8: 02800005                 be      loc_F004E6EC
F004E6DC: 01000000                 nop
F004E6E0: 7fff5822                 call    _bwrite
F004E6E4: 90100011                 mov     %l1, %o0
F004E6E8: 30800003                 ba,a    locret_F004E6F4
F004E6EC: 7fff5846                 call    _bdwrite
F004E6F0: 90100011                 mov     %l1, %o0
F004E6F4: 81c7e008                 ret
F004E6F8: 81e80000                 restore
