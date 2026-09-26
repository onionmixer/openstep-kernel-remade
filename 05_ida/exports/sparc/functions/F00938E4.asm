F00938E4: 9de3bf98                 save    %sp, -0x68, %sp
F00938E8: 213c04c4                 sethi   %hi(unk_F0131251), %l0
F00938EC: d04c2251                 ldsb    [%l0+%lo(unk_F0131251)], %o0
F00938F0: e607a05c                 ld      [%fp+arg_5C], %l3
F00938F4: 80a22000                 cmp     %o0, 0
F00938F8: 12800008                 bne     loc_F0093918
F00938FC: e407a060                 ld      [%fp+arg_60], %l2
F0093900: 113c04c490122254         set     unk_F0131254, %o0
F0093908: 7fff5500                 call    _lock_init
F009390C: 92102001                 mov     1, %o1! __src
F0093910: 90102001                 mov     1, %o0
F0093914: d02c2251                 stb     %o0, [%l0+%lo(unk_F0131251)]
F0093918: 233c0449                 sethi   %hi(dword_F0112510), %l1
F009391C: d0046110                 ld      [%l1+%lo(dword_F0112510)], %o0
F0093920: 80a22000                 cmp     %o0, 0
F0093924: 12800026                 bne     loc_F00939BC
F0093928: 80a62000                 cmp     %i0, 0
F009392C: 7fff51d1                 call    _kalloc
F0093930: 90102064                 mov     0x64, %o0 ! 'd'
F0093934: a0100008                 mov     %o0, %l0
F0093938: f0242008                 st      %i0, [%l0+8]
F009393C: f234200c                 sth     %i1, [%l0+0xC]
F0093940: f434200e                 sth     %i2, [%l0+0xE]
F0093944: f6242010                 st      %i3, [%l0+0x10]
F0093948: f8242014                 st      %i4, [%l0+0x14]
F009394C: e4242060                 st      %l2, [%l0+0x60]
F0093950: 90042018                 add     %l0, 0x18, %o0! __dst
F0093954: 7ffdcef5                 call    _strcpy
F0093958: 9210001d                 mov     %i5, %o1! __src
F009395C: 90042058                 add     %l0, 0x58, %o0 ! 'X'! __dst
F0093960: 7ffdcef2                 call    _strcpy
F0093964: 92100013                 mov     %l3, %o1
F0093968: 113c04c4                 sethi   %hi(unk_F0131254), %o0
F009396C: 7fff5516                 call    _lock_write
F0093970: 90122254                 bset    %lo(unk_F0131254), %o0
F0093974: 113c0449                 sethi   %hi(off_F0112524), %o0
F0093978: d2022124                 ld      [%o0+%lo(off_F0112524)], %o1
F009397C: 94122124                 or      %o0, %lo(off_F0112524), %o2! __n
F0093980: 9002bffc                 add     %o2, -4, %o0
F0093984: 80a24008                 cmp     %o1, %o0
F0093988: 32800003                 bne,a   loc_F0093994
F009398C: e0224000                 st      %l0, [%o1]
F0093990: e022bffc                 st      %l0, [%o2-4]
F0093994: d2242004                 st      %o1, [%l0+4]
F0093998: 113c044990122120         set     off_F0112520, %o0
F00939A0: d0240000                 st      %o0, [%l0]
F00939A4: e0222004                 st      %l0, [%o0+4]
F00939A8: 113c04c4                 sethi   %hi(unk_F0131254), %o0
F00939AC: 7fff55a2                 call    _lock_done
F00939B0: 90122254                 bset    %lo(unk_F0131254), %o0
F00939B4: 10800034                 ba      locret_F0093A84
F00939B8: b0102000                 mov     0, %i0
F00939BC: 12800032                 bne     locret_F0093A84
F00939C0: b0102004                 mov     4, %i0
F00939C4: 7fff51ab                 call    _kalloc
F00939C8: 90102084                 mov     0x84, %o0! __dst
F00939CC: a0100008                 mov     %o0, %l0
F00939D0: 133c044992126134         set     unk_F0112534, %o1! __src
F00939D8: 7ffdce32                 call    _memcpy
F00939DC: 94102070                 mov     0x70, %o2 ! 'p'
F00939E0: 90102001                 mov     1, %o0
F00939E4: d02c2003                 stb     %o0, [%l0+3]
F00939E8: 90102084                 mov     0x84, %o0
F00939EC: d0242004                 st      %o0, [%l0+4]
F00939F0: f824201c                 st      %i4, [%l0+0x1C]
F00939F4: c0242020                 clr     [%l0+0x20]
F00939F8: e4242028                 st      %l2, [%l0+0x28]
F00939FC: 90042030                 add     %l0, 0x30, %o0 ! '0'! __dst
F0093A00: d4046110                 ld      [%l1+0x110], %o2
F0093A04: 9210001d                 mov     %i5, %o1! __src
F0093A08: 7ffdcec8                 call    _strcpy
F0093A0C: d4242010                 st      %o2, [%l0+0x10]
F0093A10: 90102002                 mov     2, %o0
F0093A14: d02c2070                 stb     %o0, [%l0+0x70]
F0093A18: 90102020                 mov     0x20, %o0 ! ' '
F0093A1C: d02c2071                 stb     %o0, [%l0+0x71]
F0093A20: f2342074                 sth     %i1, [%l0+0x74]
F0093A24: f4342076                 sth     %i2, [%l0+0x76]
F0093A28: 90102008                 mov     8, %o0
F0093A2C: d02c2078                 stb     %o0, [%l0+0x78]
F0093A30: d02c2079                 stb     %o0, [%l0+0x79]
F0093A34: 9004207c                 add     %l0, 0x7C, %o0 ! '|'! __dst
F0093A38: 92100013                 mov     %l3, %o1! __src
F0093A3C: 193fffc0                 sethi   -0x10000, %o4
F0093A40: d6042070                 ld      [%l0+0x70], %o3
F0093A44: 9813200f                 bset    0xF, %o4
F0093A48: d4042078                 ld      [%l0+0x78], %o2
F0093A4C: 960ac00c                 and     %o3, %o4, %o3
F0093A50: 9612e028                 bset    0x28, %o3 ! '('
F0093A54: 960afff9                 and     %o3, -7, %o3
F0093A58: d6242070                 st      %o3, [%l0+0x70]
F0093A5C: 940a800c                 and     %o2, %o4, %o2
F0093A60: 9412a068                 bset    0x68, %o2 ! 'h'
F0093A64: 940abff9                 and     %o2, -7, %o2
F0093A68: 7ffdceb0                 call    _strcpy
F0093A6C: d4242078                 st      %o2, [%l0+0x78]
F0093A70: 90100010                 mov     %l0, %o0
F0093A74: 92102001                 mov     1, %o1
F0093A78: 7fff486d                 call    _msg_send_from_kernel
F0093A7C: 94102000                 mov     0, %o2
F0093A80: b0100008                 mov     %o0, %i0
F0093A84: 81c7e008                 ret
F0093A88: 81e80000                 restore
