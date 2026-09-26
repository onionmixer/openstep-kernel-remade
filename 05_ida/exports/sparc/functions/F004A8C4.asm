F004A8C4: 9de3bf98                 save    %sp, -0x68, %sp
F004A8C8: 90968000                 orcc    %i2, %g0, %o0
F004A8CC: 02800008                 be      loc_F004A8EC
F004A8D0: a0100018                 mov     %i0, %l0
F004A8D4: 7ffeeff5                 call    _rem
F004A8D8: d20420bc                 ld      [%l0+0xBC], %o1
F004A8DC: 10800006                 ba      loc_F004A8F4
F004A8E0: 80a22000                 cmp     %o0, 0
F004A8E4: 10800079                 ba      locret_F004AAC8
F004A8E8: b006000b                 add     %i0, %o3, %i0
F004A8EC: d006602c                 ld      [%i1+0x2C], %o0
F004A8F0: 80a22000                 cmp     %o0, 0
F004A8F4: 26800002                 bl,a    loc_F004A8FC
F004A8F8: 90022007                 inc     7, %o0
F004A8FC: b13a2003                 sra     %o0, 3, %i0
F004A900: d20420bc                 ld      [%l0+0xBC], %o1
F004A904: 90826007                 addcc   %o1, 7, %o0
F004A908: 2c800002                 bneg,a  loc_F004A910
F004A90C: 9002600e                 add     %o1, 0xE, %o0
F004A910: 913a2003                 sra     %o0, 3, %o0
F004A914: a2220018                 sub     %o0, %i0, %l1
F004A918: 920623d8                 add     %i0, 0x3D8, %o1
F004A91C: 113c043ca6122068         set     _fragtbl, %l3
F004A924: d8042038                 ld      [%l0+0x38], %o4
F004A928: 92064009                 add     %i1, %o1, %o1
F004A92C: 9610000c                 mov     %o4, %o3
F004A930: 912b2002                 sll     %o4, 2, %o0
F004A934: 80a32000                 cmp     %o4, 0
F004A938: 16800003                 bge     loc_F004A944
F004A93C: d4020013                 ld      [%o0+%l3], %o2
F004A940: 96032007                 add     %o4, 7, %o3
F004A944: 90100011                 mov     %l1, %o0
F004A948: 960afff8                 and     %o3, -8, %o3
F004A94C: 9623000b                 sub     %o4, %o3, %o3
F004A950: 9602ffff                 inc     -1, %o3
F004A954: 9606c00b                 add     %i3, %o3, %o3
F004A958: a4102001                 mov     1, %l2
F004A95C: 40001729                 call    _scanc
F004A960: 972c800b                 sll     %l2, %o3, %o3
F004A964: b4920000                 orcc    %o0, %g0, %i2
F004A968: 12800020                 bne     loc_F004A9E8
F004A96C: 90060011                 add     %i0, %l1, %o0
F004A970: a2062001                 add     %i0, 1, %l1
F004A974: b0102000                 mov     0, %i0
F004A978: d8042038                 ld      [%l0+0x38], %o4
F004A97C: 920663d8                 add     %i1, 0x3D8, %o1
F004A980: 9610000c                 mov     %o4, %o3
F004A984: 912b2002                 sll     %o4, 2, %o0
F004A988: 80a32000                 cmp     %o4, 0
F004A98C: 16800003                 bge     loc_F004A998
F004A990: d4020013                 ld      [%o0+%l3], %o2
F004A994: 96032007                 add     %o4, 7, %o3
F004A998: 90100011                 mov     %l1, %o0
F004A99C: 960afff8                 and     %o3, -8, %o3
F004A9A0: 9623000b                 sub     %o4, %o3, %o3
F004A9A4: 9602ffff                 inc     -1, %o3
F004A9A8: 9606c00b                 add     %i3, %o3, %o3
F004A9AC: 40001715                 call    _scanc
F004A9B0: 972c800b                 sll     %l2, %o3, %o3
F004A9B4: b4920000                 orcc    %o0, %g0, %i2
F004A9B8: 3280000c                 bne,a   loc_F004A9E8
F004A9BC: 90060011                 add     %i0, %l1, %o0
F004A9C0: 113c043a90122178         set     aStartDLenDFsS, %o0! "start = %d, len = %d, fs = %s\n"
F004A9C8: 92102000                 mov     0, %o1
F004A9CC: 94100011                 mov     %l1, %o2
F004A9D0: 7fff2722                 call    _printf
F004A9D4: 960420d4                 add     %l0, 0xD4, %o3
F004A9D8: 113c043a                 sethi   %hi(aAlloccgMapCorr), %o0! "alloccg: map corrupted"
F004A9DC: 7fff29e5                 call    _panic
F004A9E0: 90122198                 bset    %lo(aAlloccgMapCorr), %o0! "alloccg: map corrupted"
F004A9E4: 90060011                 add     %i0, %l1, %o0
F004A9E8: 9022001a                 sub     %o0, %i2, %o0
F004A9EC: b12a2003                 sll     %o0, 3, %i0
F004A9F0: 86062008                 add     %i0, 8, %g3
F004A9F4: 80a60003                 cmp     %i0, %g3
F004A9F8: 1680002b                 bge     loc_F004AAA4
F004A9FC: f026602c                 st      %i0, [%i1+0x2C]
F004AA00: a6102008                 mov     8, %l3
F004AA04: a41020ff                 mov     0xFF, %l2
F004AA08: 113c043ba2122220         set     _around, %l1
F004AA10: 852ee002                 sll     %i3, 2, %g2
F004AA14: 113c043b9e122244         set     _inside, %o7
F004AA1C: 80a62000                 cmp     %i0, 0
F004AA20: 16800003                 bge     loc_F004AA2C
F004AA24: 90100018                 mov     %i0, %o0
F004AA28: 90062007                 add     %i0, 7, %o0
F004AA2C: 96102000                 mov     0, %o3
F004AA30: 913a2003                 sra     %o0, 3, %o0
F004AA34: da008011                 ld      [%g2+%l1], %o5
F004AA38: 92064008                 add     %i1, %o0, %o1
F004AA3C: d800800f                 ld      [%g2+%o7], %o4
F004AA40: 912a2003                 sll     %o0, 3, %o0
F004AA44: d20a63d8                 ldub    [%o1+0x3D8], %o1
F004AA48: 90260008                 sub     %i0, %o0, %o0
F004AA4C: d4042038                 ld      [%l0+0x38], %o2
F004AA50: 933a4008                 sra     %o1, %o0, %o1
F004AA54: 9024c00a                 sub     %l3, %o2, %o0
F004AA58: 913c8008                 sra     %l2, %o0, %o0
F004AA5C: 920a4008                 and     %o1, %o0, %o1
F004AA60: 9422801b                 sub     %o2, %i3, %o2
F004AA64: 80a2c00a                 cmp     %o3, %o2
F004AA68: 1480000a                 bg      loc_F004AA90
F004AA6C: 932a6001                 sll     %o1, 1, %o1
F004AA70: 900a400d                 and     %o1, %o5, %o0
F004AA74: 80a2000c                 cmp     %o0, %o4
F004AA78: 02bfff9b                 be      loc_F004A8E4
F004AA7C: 9b2b6001                 sll     %o5, 1, %o5
F004AA80: 9602e001                 inc     %o3
F004AA84: 80a2c00a                 cmp     %o3, %o2
F004AA88: 04bffffa                 ble     loc_F004AA70
F004AA8C: 992b2001                 sll     %o4, 1, %o4
F004AA90: d0042038                 ld      [%l0+0x38], %o0
F004AA94: b0060008                 add     %i0, %o0, %i0
F004AA98: 80a60003                 cmp     %i0, %g3
F004AA9C: 06bfffe1                 bl      loc_F004AA20
F004AAA0: 80a62000                 cmp     %i0, 0
F004AAA4: 113c043a901221b0         set     aBnoDFsS, %o0! "bno = %d, fs = %s\n"
F004AAAC: 92100018                 mov     %i0, %o1
F004AAB0: 7fff26ea                 call    _printf
F004AAB4: 940420d4                 add     %l0, 0xD4, %o2
F004AAB8: 113c043a                 sethi   %hi(aAlloccgBlockNo), %o0! "alloccg: block not in map"
F004AABC: 7fff29ad                 call    _panic
F004AAC0: 901221c8                 bset    %lo(aAlloccgBlockNo), %o0! "alloccg: block not in map"
F004AAC4: b0103fff                 mov     -1, %i0
F004AAC8: 81c7e008                 ret
F004AACC: 81e80000                 restore
