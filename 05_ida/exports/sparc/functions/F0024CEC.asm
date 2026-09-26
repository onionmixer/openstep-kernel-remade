F0024CEC: 9de3bf98                 save    %sp, -0x68, %sp
F0024CF0: d0062014                 ld      [%i0+0x14], %o0
F0024CF4: 80a64008                 cmp     %i1, %o0
F0024CF8: 32800004                 bne,a   loc_F0024D08
F0024CFC: d2060000                 ld      [%i0], %o1
F0024D00: 10800085                 ba      locret_F0024F14
F0024D04: b0102001                 mov     1, %i0
F0024D08: 808a6200                 btst    0x200, %o1
F0024D0C: 02800006                 be      loc_F0024D24
F0024D10: 80a64008                 cmp     %i1, %o0
F0024D14: 7ffffe95                 call    _bwrite
F0024D18: 90100018                 mov     %i0, %o0
F0024D1C: 1080007e                 ba      locret_F0024F14
F0024D20: b0102000                 mov     0, %i0
F0024D24: 1680000a                 bge     loc_F0024D4C
F0024D28: 900a7ffd                 and     %o1, -3, %o0
F0024D2C: 11000080                 sethi   0x20000, %o0
F0024D30: 808a4008                 btst    %o0, %o1
F0024D34: 02800074                 be      loc_F0024F04
F0024D38: 113c042f                 sethi   %hi(aBrealloc), %o0! "brealloc"
F0024D3C: 7fffc10d                 call    _panic
F0024D40: 90122368                 bset    %lo(aBrealloc), %o0! "brealloc"
F0024D44: 10800071                 ba      loc_F0024F08
F0024D48: 90100018                 mov     %i0, %o0
F0024D4C: d4062040                 ld      [%i0+0x40], %o2
F0024D50: 80a2a000                 cmp     %o2, 0
F0024D54: 12800011                 bne     loc_F0024D98
F0024D58: d0260000                 st      %o0, [%i0]
F0024D5C: 1080006b                 ba      loc_F0024F08
F0024D60: 90100018                 mov     %i0, %o0
F0024D64: 90126040                 or      %o1, 0x40, %o0
F0024D68: d0240000                 st      %o0, [%l0]
F0024D6C: 90100010                 mov     %l0, %o0! unsigned int
F0024D70: 7fffb642                 call    _sleep
F0024D74: 92102015                 mov     0x15, %o1
F0024D78: 4001c7eb                 call    _splx
F0024D7C: 90100011                 mov     %l1, %o0
F0024D80: 10800024                 ba      loc_F0024E10
F0024D84: e004e004                 ld      [%l3+4], %l0
F0024D88: 7ffffe78                 call    _bwrite
F0024D8C: 90100010                 mov     %l0, %o0
F0024D90: 10800020                 ba      loc_F0024E10
F0024D94: e004e004                 ld      [%l3+4], %l0
F0024D98: d002a01c                 ld      [%o2+0x1C], %o0
F0024D9C: d2022080                 ld      [%o0+0x80], %o1
F0024DA0: 9fc24000                 call    %o1
F0024DA4: 9010000a                 mov     %o2, %o0
F0024DA8: a8920000                 orcc    %o0, %g0, %l4
F0024DAC: 36800006                 bge,a   loc_F0024DC4
F0024DB0: 90100019                 mov     %i1, %o0
F0024DB4: 113c042f                 sethi   %hi(aCouldnTDetermi), %o0! "Couldn't determine device blocksize!\n"
F0024DB8: 7fffc0ee                 call    _panic
F0024DBC: 90122378                 bset    %lo(aCouldnTDetermi), %o0! "Couldn't determine device blocksize!\n"
F0024DC0: 90100019                 mov     %i1, %o0! int
F0024DC4: 92100014                 mov     %l4, %o1! int
F0024DC8: 7fff8610                 call    _div
F0024DCC: e4062024                 ld      [%i0+0x24], %l2
F0024DD0: 92948000                 orcc    %l2, %g0, %o1
F0024DD4: 90048008                 add     %l2, %o0, %o0
F0024DD8: 16800003                 bge     loc_F0024DE4
F0024DDC: ac023fff                 add     %o0, -1, %l6
F0024DE0: 9204a007                 add     %l2, 7, %o1
F0024DE4: d0062040                 ld      [%i0+0x40], %o0
F0024DE8: 933a6003                 sra     %o1, 3, %o1
F0024DEC: 90020009                 add     %o0, %o1, %o0
F0024DF0: 900a200f                 and     %o0, 0xF, %o0
F0024DF4: 932a2001                 sll     %o0, 1, %o1
F0024DF8: 92024008                 add     %o1, %o0, %o1
F0024DFC: 932a6002                 sll     %o1, 2, %o1
F0024E00: 113c04cf90122300         set     _bufhash, %o0
F0024E08: a6024008                 add     %o1, %o0, %l3
F0024E0C: e004e004                 ld      [%l3+4], %l0
F0024E10: 80a40013                 cmp     %l0, %l3
F0024E14: 0280003d                 be      loc_F0024F08
F0024E18: 90100018                 mov     %i0, %o0
F0024E1C: 2b000040                 sethi   0x10000, %l5
F0024E20: 80a40018                 cmp     %l0, %i0
F0024E24: 22800035                 be,a    loc_F0024EF8
F0024E28: e0042004                 ld      [%l0+4], %l0
F0024E2C: d2042040                 ld      [%l0+0x40], %o1! int
F0024E30: d0062040                 ld      [%i0+0x40], %o0
F0024E34: 80a24008                 cmp     %o1, %o0
F0024E38: 32800030                 bne,a   loc_F0024EF8
F0024E3C: e0042004                 ld      [%l0+4], %l0
F0024E40: d0040000                 ld      [%l0], %o0
F0024E44: 808a0015                 btst    %l5, %o0
F0024E48: 3280002c                 bne,a   loc_F0024EF8
F0024E4C: e0042004                 ld      [%l0+4], %l0
F0024E50: d0042014                 ld      [%l0+0x14], %o0! int
F0024E54: 80a22000                 cmp     %o0, 0
F0024E58: 22800028                 be,a    loc_F0024EF8
F0024E5C: e0042004                 ld      [%l0+4], %l0
F0024E60: e2042024                 ld      [%l0+0x24], %l1
F0024E64: 80a44016                 cmp     %l1, %l6
F0024E68: 34800024                 bg,a    loc_F0024EF8
F0024E6C: e0042004                 ld      [%l0+4], %l0
F0024E70: 7fff85e6                 call    _div
F0024E74: 92100014                 mov     %l4, %o1
F0024E78: 90044008                 add     %l1, %o0, %o0
F0024E7C: 80a20012                 cmp     %o0, %l2
F0024E80: 2480001e                 ble,a   loc_F0024EF8
F0024E84: e0042004                 ld      [%l0+4], %l0
F0024E88: 4001c740                 call    _splusclock
F0024E8C: 01000000                 nop
F0024E90: d2040000                 ld      [%l0], %o1
F0024E94: 808a6008                 btst    8, %o1
F0024E98: 12bfffb3                 bne     loc_F0024D64
F0024E9C: a2100008                 mov     %o0, %l1
F0024EA0: 4001c7a1                 call    _splx
F0024EA4: 01000000                 nop
F0024EA8: 4001c744                 call    _spltty
F0024EAC: 01000000                 nop
F0024EB0: d4042010                 ld      [%l0+0x10], %o2
F0024EB4: d204200c                 ld      [%l0+0xC], %o1
F0024EB8: d222a00c                 st      %o1, [%o2+0xC]
F0024EBC: d404200c                 ld      [%l0+0xC], %o2
F0024EC0: d2042010                 ld      [%l0+0x10], %o1
F0024EC4: d222a010                 st      %o1, [%o2+0x10]
F0024EC8: d2040000                 ld      [%l0], %o1
F0024ECC: 92126008                 bset    8, %o1
F0024ED0: 4001c795                 call    _splx
F0024ED4: d2240000                 st      %o1, [%l0]
F0024ED8: d0040000                 ld      [%l0], %o0
F0024EDC: 808a2200                 btst    0x200, %o0
F0024EE0: 12bfffaa                 bne     loc_F0024D88
F0024EE4: 90120015                 bset    %l5, %o0
F0024EE8: d0240000                 st      %o0, [%l0]
F0024EEC: 7ffffe5f                 call    _brelse
F0024EF0: 90100010                 mov     %l0, %o0
F0024EF4: e0042004                 ld      [%l0+4], %l0
F0024EF8: 80a40013                 cmp     %l0, %l3
F0024EFC: 12bfffca                 bne     loc_F0024E24
F0024F00: 80a40018                 cmp     %l0, %i0
F0024F04: 90100018                 mov     %i0, %o0
F0024F08: 400214e7                 call    _allocbuf
F0024F0C: 92100019                 mov     %i1, %o1
F0024F10: b0100008                 mov     %o0, %i0
F0024F14: 81c7e008                 ret
F0024F18: 81e80000                 restore
