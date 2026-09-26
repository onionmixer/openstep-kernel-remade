F0049E60: 9de3bf90                 save    %sp, -0x70, %sp
F0049E64: e4062050                 ld      [%i0+0x50], %l2
F0049E68: d004a070                 ld      [%l2+0x70], %o0
F0049E6C: d204a06c                 ld      [%l2+0x6C], %o1
F0049E70: 913e4008                 sra     %i1, %o0, %o0
F0049E74: 912a2002                 sll     %o0, 2, %o0
F0049E78: 90020012                 add     %o0, %l2, %o0
F0049E7C: 922e4009                 andn    %i1, %o1, %o1
F0049E80: d00222d8                 ld      [%o0+0x2D8], %o0
F0049E84: 932a6004                 sll     %o1, 4, %o1
F0049E88: 90020009                 add     %o0, %o1, %o0
F0049E8C: d0022008                 ld      [%o0+8], %o0
F0049E90: 80a22000                 cmp     %o0, 0
F0049E94: 32800004                 bne,a   loc_F0049EA4
F0049E98: d004a0bc                 ld      [%l2+0xBC], %o0
F0049E9C: 108000b5                 ba      locret_F004A170
F0049EA0: b0102000                 mov     0, %i0
F0049EA4: e2062040                 ld      [%i0+0x40], %l1
F0049EA8: 7ffef196                 call    _umul
F0049EAC: 92100019                 mov     %i1, %o1
F0049EB0: d404a018                 ld      [%l2+0x18], %o2
F0049EB4: a0100008                 mov     %o0, %l0
F0049EB8: d204a01c                 ld      [%l2+0x1C], %o1
F0049EBC: 9010000a                 mov     %o2, %o0
F0049EC0: 7ffef190                 call    _umul
F0049EC4: 922e4009                 andn    %i1, %o1, %o1
F0049EC8: 92100008                 mov     %o0, %o1
F0049ECC: d404a0a0                 ld      [%l2+0xA0], %o2
F0049ED0: 90100011                 mov     %l1, %o0
F0049ED4: d604a00c                 ld      [%l2+0xC], %o3
F0049ED8: a0040009                 add     %l0, %o1, %l0
F0049EDC: d204a064                 ld      [%l2+0x64], %o1
F0049EE0: a004000b                 add     %l0, %o3, %l0
F0049EE4: 7fff698f                 call    _bread
F0049EE8: 932c0009                 sll     %l0, %o1, %o1
F0049EEC: a6100008                 mov     %o0, %l3
F0049EF0: d004c000                 ld      [%l3], %o0
F0049EF4: 808a2004                 btst    4, %o0
F0049EF8: 1280000c                 bne     loc_F0049F28
F0049EFC: e204e020                 ld      [%l3+0x20], %l1
F0049F00: d20463d4                 ld      [%l1+0x3D4], %o1
F0049F04: 1100024090122255         set     0x90255, %o0
F0049F0C: 80a24008                 cmp     %o1, %o0
F0049F10: 12800006                 bne     loc_F0049F28
F0049F14: 01000000                 nop
F0049F18: d0046020                 ld      [%l1+0x20], %o0
F0049F1C: 80a22000                 cmp     %o0, 0
F0049F20: 12800008                 bne     loc_F0049F40
F0049F24: 01000000                 nop
F0049F28: 7fff6a50                 call    _brelse
F0049F2C: 90100013                 mov     %l3, %o0
F0049F30: 10800090                 ba      locret_F004A170
F0049F34: b0102000                 mov     0, %i0
F0049F38: 10800050                 ba      loc_F004A078
F0049F3C: f4246030                 st      %i2, [%l1+0x30]
F0049F40: 7fff2413                 call    _getthetime
F0049F44: 9007bff0                 add     %fp, var_10, %o0
F0049F48: d007bff0                 ld      [%fp+var_10], %o0
F0049F4C: 80a6a000                 cmp     %i2, 0
F0049F50: 02800011                 be      loc_F0049F94
F0049F54: d0246008                 st      %o0, [%l1+8]
F0049F58: d204a0b8                 ld      [%l2+0xB8], %o1
F0049F5C: 7ffef253                 call    _rem
F0049F60: 9010001a                 mov     %i2, %o0
F0049F64: b4920000                 orcc    %o0, %g0, %i2
F0049F68: 26800002                 bl,a    loc_F0049F70
F0049F6C: 9006a007                 add     %i2, 7, %o0
F0049F70: 913a2003                 sra     %o0, 3, %o0
F0049F74: 92020011                 add     %o0, %l1, %o1
F0049F78: d24a62d4                 ldsb    [%o1+0x2D4], %o1
F0049F7C: 912a2003                 sll     %o0, 3, %o0
F0049F80: 90268008                 sub     %i2, %o0, %o0
F0049F84: 933a4008                 sra     %o1, %o0, %o1
F0049F88: 808a6001                 btst    1, %o1
F0049F8C: 0280003c                 be      loc_F004A07C
F0049F90: 80a6a000                 cmp     %i2, 0
F0049F94: d2046030                 ld      [%l1+0x30], %o1
F0049F98: 80a26000                 cmp     %o1, 0
F0049F9C: 16800003                 bge     loc_F0049FA8
F0049FA0: 94100009                 mov     %o1, %o2
F0049FA4: 94026007                 add     %o1, 7, %o2
F0049FA8: d004a0b8                 ld      [%l2+0xB8], %o0
F0049FAC: 90220009                 sub     %o0, %o1, %o0
F0049FB0: 92822007                 addcc   %o0, 7, %o1
F0049FB4: 1c800003                 bpos    loc_F0049FC0
F0049FB8: b53aa003                 sra     %o2, 3, %i2
F0049FBC: 9202200e                 add     %o0, 0xE, %o1
F0049FC0: b13a6003                 sra     %o1, 3, %i0
F0049FC4: 901020ff                 mov     0xFF, %o0
F0049FC8: 92100018                 mov     %i0, %o1
F0049FCC: 9406a2d4                 add     %i2, 0x2D4, %o2
F0049FD0: 400019a2                 call    _skpc
F0049FD4: 9404400a                 add     %l1, %o2, %o2
F0049FD8: a0920000                 orcc    %o0, %g0, %l0
F0049FDC: 12800015                 bne     loc_F004A030
F0049FE0: 90068018                 add     %i2, %i0, %o0
F0049FE4: b006a001                 add     %i2, 1, %i0
F0049FE8: b4102000                 mov     0, %i2
F0049FEC: 901020ff                 mov     0xFF, %o0
F0049FF0: 92100018                 mov     %i0, %o1
F0049FF4: 40001999                 call    _skpc
F0049FF8: 940462d4                 add     %l1, 0x2D4, %o2
F0049FFC: a0920000                 orcc    %o0, %g0, %l0
F004A000: 3280000c                 bne,a   loc_F004A030
F004A004: 90068018                 add     %i2, %i0, %o0
F004A008: 113c0439901223b0         set     aCgSIrotorDFsS, %o0! "cg = %s, irotor = %d, fs = %s\n"
F004A010: 92100019                 mov     %i1, %o1
F004A014: d4046030                 ld      [%l1+0x30], %o2
F004A018: 7fff2990                 call    _printf
F004A01C: 9604a0d4                 add     %l2, 0xD4, %o3
F004A020: 113c0439                 sethi   %hi(aIalloccgMapCor), %o0! "ialloccg: map corrupted"
F004A024: 7fff2c53                 call    _panic
F004A028: 901223d0                 bset    %lo(aIalloccgMapCor), %o0! "ialloccg: map corrupted"
F004A02C: 90068018                 add     %i2, %i0, %o0
F004A030: 92220010                 sub     %o0, %l0, %o1
F004A034: 90044009                 add     %l1, %o1, %o0
F004A038: d04a22d4                 ldsb    [%o0+0x2D4], %o0
F004A03C: b52a6003                 sll     %o1, 3, %i2
F004A040: 92102001                 mov     1, %o1
F004A044: 808a0009                 btst    %o1, %o0
F004A048: 02bfffbc                 be      loc_F0049F38
F004A04C: 932a6001                 sll     %o1, 1, %o1
F004A050: 80a260ff                 cmp     %o1, 0xFF
F004A054: 04bffffc                 ble     loc_F004A044
F004A058: b406a001                 inc     %i2
F004A05C: 113c0439901223e8         set     aFsS, %o0! "fs = %s\n"
F004A064: 7fff297d                 call    _printf
F004A068: 9204a0d4                 add     %l2, 0xD4, %o1
F004A06C: 113c0439                 sethi   %hi(aIalloccgBlockN), %o0! "ialloccg: block not in map"
F004A070: 7fff2c40                 call    _panic
F004A074: 901223f8                 bset    %lo(aIalloccgBlockN), %o0! "ialloccg: block not in map"
F004A078: 80a6a000                 cmp     %i2, 0
F004A07C: 16800003                 bge     loc_F004A088
F004A080: 9410001a                 mov     %i2, %o2
F004A084: 9406a007                 add     %i2, 7, %o2
F004A088: 953aa003                 sra     %o2, 3, %o2
F004A08C: 96028011                 add     %o2, %l1, %o3
F004A090: 952aa003                 sll     %o2, 3, %o2
F004A094: 9426800a                 sub     %i2, %o2, %o2
F004A098: 90102001                 mov     1, %o0
F004A09C: d20ae2d4                 ldub    [%o3+0x2D4], %o1
F004A0A0: 912a000a                 sll     %o0, %o2, %o0
F004A0A4: 92124008                 bset    %o0, %o1
F004A0A8: d22ae2d4                 stb     %o1, [%o3+0x2D4]
F004A0AC: d0046020                 ld      [%l1+0x20], %o0
F004A0B0: 90023fff                 inc     -1, %o0
F004A0B4: d0246020                 st      %o0, [%l1+0x20]
F004A0B8: d204a0c8                 ld      [%l2+0xC8], %o1
F004A0BC: d004a070                 ld      [%l2+0x70], %o0
F004A0C0: 92027fff                 inc     -1, %o1
F004A0C4: d224a0c8                 st      %o1, [%l2+0xC8]
F004A0C8: 913e4008                 sra     %i1, %o0, %o0
F004A0CC: 912a2002                 sll     %o0, 2, %o0
F004A0D0: d204a06c                 ld      [%l2+0x6C], %o1
F004A0D4: 90020012                 add     %o0, %l2, %o0
F004A0D8: d40222d8                 ld      [%o0+0x2D8], %o2
F004A0DC: 922e4009                 andn    %i1, %o1, %o1
F004A0E0: 932a6004                 sll     %o1, 4, %o1
F004A0E4: 94028009                 add     %o2, %o1, %o2
F004A0E8: 1300003c                 sethi   0xF000, %o1
F004A0EC: d002a008                 ld      [%o2+8], %o0
F004A0F0: 920ec009                 and     %i3, %o1, %o1
F004A0F4: 90023fff                 inc     -1, %o0
F004A0F8: d022a008                 st      %o0, [%o2+8]
F004A0FC: 15000010                 sethi   0x4000, %o2
F004A100: d00ca0d0                 ldub    [%l2+0xD0], %o0
F004A104: 80a2400a                 cmp     %o1, %o2
F004A108: 90022001                 inc     %o0
F004A10C: 12800013                 bne     loc_F004A158
F004A110: d02ca0d0                 stb     %o0, [%l2+0xD0]
F004A114: d0046018                 ld      [%l1+0x18], %o0
F004A118: 90022001                 inc     %o0
F004A11C: d0246018                 st      %o0, [%l1+0x18]
F004A120: d204a0c0                 ld      [%l2+0xC0], %o1
F004A124: d004a070                 ld      [%l2+0x70], %o0
F004A128: 92026001                 inc     %o1
F004A12C: d224a0c0                 st      %o1, [%l2+0xC0]
F004A130: 913e4008                 sra     %i1, %o0, %o0
F004A134: 912a2002                 sll     %o0, 2, %o0
F004A138: d204a06c                 ld      [%l2+0x6C], %o1
F004A13C: 90020012                 add     %o0, %l2, %o0
F004A140: d40222d8                 ld      [%o0+0x2D8], %o2
F004A144: 922e4009                 andn    %i1, %o1, %o1
F004A148: 932a6004                 sll     %o1, 4, %o1
F004A14C: d0028009                 ld      [%o2+%o1], %o0
F004A150: 90022001                 inc     %o0
F004A154: d0228009                 st      %o0, [%o2+%o1]
F004A158: 7fff69ab                 call    _bdwrite
F004A15C: 90100013                 mov     %l3, %o0
F004A160: d204a0b8                 ld      [%l2+0xB8], %o1
F004A164: 7ffef0e7                 call    _umul
F004A168: 90100019                 mov     %i1, %o0
F004A16C: b002001a                 add     %o0, %i2, %i0
F004A170: 81c7e008                 ret
F004A174: 81e80000                 restore
