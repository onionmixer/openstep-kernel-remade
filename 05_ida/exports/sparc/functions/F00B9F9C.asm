F00B9F9C: 9de3bf98                 save    %sp, -0x68, %sp
F00B9FA0: d0562038                 ldsh    [%i0+0x38], %o0
F00B9FA4: 133c04fb                 sethi   %hi(_rconsdev), %o1
F00B9FA8: d2526248                 ldsh    [%o1+%lo(_rconsdev)], %o1
F00B9FAC: 80a20009                 cmp     %o0, %o1
F00B9FB0: 12800008                 bne     loc_F00B9FD0
F00B9FB4: e0062034                 ld      [%i0+0x34], %l0
F00B9FB8: d206203c                 ld      [%i0+0x3C], %o1
F00B9FBC: 900a60c0                 and     %o1, 0xC0, %o0
F00B9FC0: 80a220c0                 cmp     %o0, 0xC0
F00B9FC4: 02800003                 be      loc_F00B9FD0
F00B9FC8: 901260c0                 or      %o1, 0xC0, %o0
F00B9FCC: d026203c                 st      %o0, [%i0+0x3C]
F00B9FD0: d24e2049                 ldsb    [%i0+0x49], %o1
F00B9FD4: 80a26000                 cmp     %o1, 0
F00B9FD8: 12800007                 bne     loc_F00B9FF4
F00B9FDC: ac102013                 mov     0x13, %l6
F00B9FE0: 90100018                 mov     %i0, %o0
F00B9FE4: 92102000                 mov     0, %o1
F00B9FE8: 40000135                 call    _zsmctl
F00B9FEC: 94102000                 mov     0, %o2
F00B9FF0: 308000ba                 ba,a    locret_F00BA2D8
F00B9FF4: a8102001                 mov     1, %l4
F00B9FF8: a6102040                 mov     0x40, %l3 ! '@'
F00B9FFC: d00c2025                 ldub    [%l0+0x25], %o0
F00BA000: 80a26004                 cmp     %o1, 4
F00BA004: 900a2082                 and     %o0, 0x82, %o0
F00BA008: 12800007                 bne     loc_F00BA024
F00BA00C: a4122008                 or      %o0, 8, %l2
F00BA010: ac102017                 mov     0x17, %l6
F00BA014: a8102081                 mov     0x81, %l4
F00BA018: a6102043                 mov     0x43, %l3 ! 'C'
F00BA01C: 10800023                 ba      loc_F00BA0A8
F00BA020: a414a040                 bset    0x40, %l2 ! '@'
F00BA024: d206203c                 ld      [%i0+0x3C], %o1
F00BA028: 1100080090122020         set     0x200020, %o0
F00BA030: 808a4008                 btst    %o0, %o1
F00BA034: 32800013                 bne,a   loc_F00BA080
F00BA038: a81020c1                 mov     0xC1, %l4
F00BA03C: 900a60c0                 and     %o1, 0xC0, %o0
F00BA040: 80a22040                 cmp     %o0, 0x40 ! '@'
F00BA044: 22800013                 be,a    loc_F00BA090
F00BA048: ac102017                 mov     0x17, %l6
F00BA04C: 14800007                 bg      loc_F00BA068
F00BA050: 80a22080                 cmp     %o0, 0x80
F00BA054: 80a22000                 cmp     %o0, 0
F00BA058: 2280000a                 be,a    loc_F00BA080
F00BA05C: a81020c1                 mov     0xC1, %l4
F00BA060: 10800013                 ba      loc_F00BA0AC
F00BA064: d04e2049                 ldsb    [%i0+0x49], %o0
F00BA068: 02800008                 be      loc_F00BA088
F00BA06C: 80a220c0                 cmp     %o0, 0xC0
F00BA070: 2280000c                 be,a    loc_F00BA0A0
F00BA074: a8102041                 mov     0x41, %l4 ! 'A'
F00BA078: 1080000d                 ba      loc_F00BA0AC
F00BA07C: d04e2049                 ldsb    [%i0+0x49], %o0
F00BA080: 1080000a                 ba      loc_F00BA0A8
F00BA084: a414a060                 bset    0x60, %l2 ! '`'
F00BA088: 10800005                 ba      loc_F00BA09C
F00BA08C: ac102017                 mov     0x17, %l6
F00BA090: a8102041                 mov     0x41, %l4 ! 'A'
F00BA094: 10800004                 ba      loc_F00BA0A4
F00BA098: a6102041                 mov     0x41, %l3 ! 'A'
F00BA09C: a8102041                 mov     0x41, %l4 ! 'A'
F00BA0A0: a6102043                 mov     0x43, %l3 ! 'C'
F00BA0A4: a414a020                 bset    0x20, %l2 ! ' '
F00BA0A8: d04e2049                 ldsb    [%i0+0x49], %o0
F00BA0AC: 80a22003                 cmp     %o0, 3
F00BA0B0: 12800004                 bne     loc_F00BA0C0
F00BA0B4: 80a22004                 cmp     %o0, 4
F00BA0B8: 10800005                 ba      loc_F00BA0CC
F00BA0BC: a614e00c                 bset    0xC, %l3
F00BA0C0: 32800003                 bne,a   loc_F00BA0CC
F00BA0C4: a614e004                 bset    4, %l3
F00BA0C8: a614e008                 bset    8, %l3
F00BA0CC: d00c202d                 ldub    [%l0+0x2D], %o0
F00BA0D0: d40c202c                 ldub    [%l0+0x2C], %o2
F00BA0D4: d20c2021                 ldub    [%l0+0x21], %o1
F00BA0D8: 912a2008                 sll     %o0, 8, %o0
F00BA0DC: 80a58009                 cmp     %l6, %o1
F00BA0E0: 12800017                 bne     loc_F00BA13C
F00BA0E4: a2028008                 add     %o2, %o0, %l1
F00BA0E8: d00c2023                 ldub    [%l0+0x23], %o0
F00BA0EC: 80a50008                 cmp     %l4, %o0
F00BA0F0: 12800014                 bne     loc_F00BA140
F00BA0F4: 90100018                 mov     %i0, %o0
F00BA0F8: d00c2024                 ldub    [%l0+0x24], %o0
F00BA0FC: 80a4c008                 cmp     %l3, %o0
F00BA100: 12800010                 bne     loc_F00BA140
F00BA104: 90100018                 mov     %i0, %o0
F00BA108: d00c2025                 ldub    [%l0+0x25], %o0
F00BA10C: 80a48008                 cmp     %l2, %o0
F00BA110: 1280000c                 bne     loc_F00BA140
F00BA114: 90100018                 mov     %i0, %o0
F00BA118: 133c047e                 sethi   %hi(_zs_speeds), %o1
F00BA11C: d00e2049                 ldub    [%i0+0x49], %o0
F00BA120: 921262cc                 bset    %lo(_zs_speeds), %o1
F00BA124: 900a200f                 and     %o0, 0xF, %o0
F00BA128: 912a2001                 sll     %o0, 1, %o0
F00BA12C: d0120009                 lduh    [%o0+%o1], %o0
F00BA130: 80a44008                 cmp     %l1, %o0
F00BA134: 02800069                 be      locret_F00BA2D8
F00BA138: 01000000                 nop
F00BA13C: 90100018                 mov     %i0, %o0
F00BA140: 92102000                 mov     0, %o1
F00BA144: d4062040                 ld      [%i0+0x40], %o2
F00BA148: a21023e8                 mov     0x3E8, %l1
F00BA14C: 9412a008                 bset    8, %o2
F00BA150: 400000c6                 call    _zsstop
F00BA154: d4262040                 st      %o2, [%i0+0x40]
F00BA158: 7fff7285                 call    _splzs
F00BA15C: 01000000                 nop
F00BA160: aa100008                 mov     %o0, %l5
F00BA164: d0042010                 ld      [%l0+0x10], %o0
F00BA168: 400004fc                 call    _zszread
F00BA16C: 92102001                 mov     1, %o1
F00BA170: 808a2001                 btst    1, %o0
F00BA174: 1280000a                 bne     loc_F00BA19C
F00BA178: a2047fff                 inc     -1, %l1
F00BA17C: 80a46000                 cmp     %l1, 0
F00BA180: 24800008                 ble,a   loc_F00BA1A0
F00BA184: c02c2023                 clrb    [%l0+0x23]
F00BA188: 7fff72e7                 call    _splx
F00BA18C: 90100015                 mov     %l5, %o0
F00BA190: 7fff75b4                 call    _us_spin
F00BA194: 90102064                 mov     0x64, %o0 ! 'd'
F00BA198: 30bffff0                 ba,a    loc_F00BA158
F00BA19C: c02c2023                 clrb    [%l0+0x23]
F00BA1A0: 92102003                 mov     3, %o1
F00BA1A4: d0042010                 ld      [%l0+0x10], %o0
F00BA1A8: 400004ef                 call    _zszwrite
F00BA1AC: 94102000                 mov     0, %o2
F00BA1B0: d2042010                 ld      [%l0+0x10], %o1
F00BA1B4: 90102010                 mov     0x10, %o0
F00BA1B8: d02a4000                 stb     %o0, [%o1]
F00BA1BC: d2042010                 ld      [%l0+0x10], %o1
F00BA1C0: 90102030                 mov     0x30, %o0 ! '0'
F00BA1C4: d02a4000                 stb     %o0, [%o1]
F00BA1C8: d0042010                 ld      [%l0+0x10], %o0
F00BA1CC: d80a2002                 ldub    [%o0+2], %o4
F00BA1D0: 96100016                 mov     %l6, %o3
F00BA1D4: d80a2002                 ldub    [%o0+2], %o4
F00BA1D8: 9410000b                 mov     %o3, %o2
F00BA1DC: d80a2002                 ldub    [%o0+2], %o4
F00BA1E0: 92102001                 mov     1, %o1
F00BA1E4: 400004e0                 call    _zszwrite
F00BA1E8: d62c2021                 stb     %o3, [%l0+0x21]
F00BA1EC: 94100013                 mov     %l3, %o2
F00BA1F0: d42c2024                 stb     %o2, [%l0+0x24]
F00BA1F4: 92102004                 mov     4, %o1
F00BA1F8: d0042010                 ld      [%l0+0x10], %o0
F00BA1FC: 400004da                 call    _zszwrite
F00BA200: 940aa0ff                 and     %o2, 0xFF, %o2
F00BA204: 94100014                 mov     %l4, %o2
F00BA208: d42c2023                 stb     %o2, [%l0+0x23]
F00BA20C: 92102003                 mov     3, %o1
F00BA210: 400004d5                 call    _zszwrite
F00BA214: d0042010                 ld      [%l0+0x10], %o0
F00BA218: 94100012                 mov     %l2, %o2
F00BA21C: d42c2025                 stb     %o2, [%l0+0x25]
F00BA220: 92102005                 mov     5, %o1
F00BA224: d0042010                 ld      [%l0+0x10], %o0
F00BA228: 400004cf                 call    _zszwrite
F00BA22C: 940aa0ff                 and     %o2, 0xFF, %o2
F00BA230: 9210200b                 mov     0xB, %o1
F00BA234: 173c047e                 sethi   %hi(_zs_speeds), %o3
F00BA238: d80e2049                 ldub    [%i0+0x49], %o4
F00BA23C: 9612e2cc                 bset    %lo(_zs_speeds), %o3
F00BA240: 980b200f                 and     %o4, 0xF, %o4
F00BA244: 992b2001                 sll     %o4, 1, %o4
F00BA248: e213000b                 lduh    [%o4+%o3], %l1
F00BA24C: 94102050                 mov     0x50, %o2 ! 'P'
F00BA250: d0042010                 ld      [%l0+0x10], %o0
F00BA254: 96102050                 mov     0x50, %o3 ! 'P'
F00BA258: 400004c3                 call    _zszwrite
F00BA25C: d62c202b                 stb     %o3, [%l0+0x2B]
F00BA260: 90102002                 mov     2, %o0
F00BA264: d02c202e                 stb     %o0, [%l0+0x2E]
F00BA268: 9210200e                 mov     0xE, %o1
F00BA26C: d0042010                 ld      [%l0+0x10], %o0
F00BA270: 400004bd                 call    _zszwrite
F00BA274: 94102002                 mov     2, %o2
F00BA278: 94100011                 mov     %l1, %o2
F00BA27C: d42c202c                 stb     %o2, [%l0+0x2C]
F00BA280: 9210200c                 mov     0xC, %o1
F00BA284: d0042010                 ld      [%l0+0x10], %o0
F00BA288: 400004b7                 call    _zszwrite
F00BA28C: 940aa0ff                 and     %o2, 0xFF, %o2
F00BA290: 95346008                 srl     %l1, 8, %o2
F00BA294: d42c202d                 stb     %o2, [%l0+0x2D]
F00BA298: 9210200d                 mov     0xD, %o1
F00BA29C: 400004b2                 call    _zszwrite
F00BA2A0: d0042010                 ld      [%l0+0x10], %o0
F00BA2A4: 90102003                 mov     3, %o0
F00BA2A8: d02c202e                 stb     %o0, [%l0+0x2E]
F00BA2AC: 9210200e                 mov     0xE, %o1
F00BA2B0: d0042010                 ld      [%l0+0x10], %o0
F00BA2B4: 400004ac                 call    _zszwrite
F00BA2B8: 94102003                 mov     3, %o2
F00BA2BC: 7fff729a                 call    _splx
F00BA2C0: 90100015                 mov     %l5, %o0
F00BA2C4: d2062040                 ld      [%i0+0x40], %o1
F00BA2C8: 90100018                 mov     %i0, %o0
F00BA2CC: 920a7ff7                 and     %o1, -9, %o1
F00BA2D0: 40000004                 call    _zsstart
F00BA2D4: d2222040                 st      %o1, [%o0+0x40]
F00BA2D8: 81c7e008                 ret
F00BA2DC: 81e80000                 restore
