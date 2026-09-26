F00BB24C: 9de3bf98                 save    %sp, -0x68, %sp
F00BB250: 90100018                 mov     %i0, %o0
F00BB254: 133c047e                 sethi   %hi(_zsops_null), %o1
F00BB258: 7fffffcc                 call    _zsopinit
F00BB25C: 921263cc                 bset    %lo(_zsops_null), %o1
F00BB260: d0562014                 ldsh    [%i0+0x14], %o0
F00BB264: 80a22000                 cmp     %o0, 0
F00BB268: 1280000e                 bne     loc_F00BB2A0
F00BB26C: a0102000                 mov     0, %l0
F00BB270: 113c04fd                 sethi   %hi(_zsinfo), %o0
F00BB274: d00221f8                 ld      [%o0+%lo(_zsinfo)], %o0
F00BB278: 133c047e                 sethi   %hi(aPortARtsDtrOff), %o1! "port-a-rts-dtr-off"
F00BB27C: d0020000                 ld      [%o0], %o0
F00BB280: 921263e8                 bset    %lo(aPortARtsDtrOff), %o1! "port-a-rts-dtr-off"
F00BB284: d0022028                 ld      [%o0+0x28], %o0
F00BB288: 7fffd789                 call    _getprop
F00BB28C: 94102000                 mov     0, %o2
F00BB290: 80a22000                 cmp     %o0, 0
F00BB294: 32800012                 bne,a   loc_F00BB2DC
F00BB298: a0102001                 mov     1, %l0
F00BB29C: d0562014                 ldsh    [%i0+0x14], %o0
F00BB2A0: 80a22001                 cmp     %o0, 1
F00BB2A4: 1280000f                 bne     loc_F00BB2E0
F00BB2A8: 90102046                 mov     0x46, %o0 ! 'F'
F00BB2AC: 113c04fd                 sethi   %hi(_zsinfo), %o0
F00BB2B0: d00221f8                 ld      [%o0+%lo(_zsinfo)], %o0
F00BB2B4: 133c047f                 sethi   %hi(aPortBRtsDtrOff), %o1! "port-b-rts-dtr-off"
F00BB2B8: d0022004                 ld      [%o0+4], %o0
F00BB2BC: 92126000                 bset    %lo(aPortBRtsDtrOff), %o1! "port-b-rts-dtr-off"
F00BB2C0: d0022028                 ld      [%o0+0x28], %o0
F00BB2C4: 7fffd77a                 call    _getprop
F00BB2C8: 94102000                 mov     0, %o2
F00BB2CC: 80a22000                 cmp     %o0, 0
F00BB2D0: 02800004                 be      loc_F00BB2E0
F00BB2D4: 90102046                 mov     0x46, %o0 ! 'F'
F00BB2D8: a0102001                 mov     1, %l0
F00BB2DC: 90102046                 mov     0x46, %o0 ! 'F'
F00BB2E0: d02e2024                 stb     %o0, [%i0+0x24]
F00BB2E4: 92102004                 mov     4, %o1
F00BB2E8: d0062010                 ld      [%i0+0x10], %o0
F00BB2EC: 4000009e                 call    _zszwrite
F00BB2F0: 94102046                 mov     0x46, %o2 ! 'F'
F00BB2F4: 901020c0                 mov     0xC0, %o0
F00BB2F8: d02e2023                 stb     %o0, [%i0+0x23]
F00BB2FC: 92102003                 mov     3, %o1
F00BB300: d0062010                 ld      [%i0+0x10], %o0
F00BB304: 40000098                 call    _zszwrite
F00BB308: 941020c0                 mov     0xC0, %o2
F00BB30C: 90102050                 mov     0x50, %o0 ! 'P'
F00BB310: d02e202b                 stb     %o0, [%i0+0x2B]
F00BB314: 9210200b                 mov     0xB, %o1
F00BB318: d0062010                 ld      [%i0+0x10], %o0
F00BB31C: 40000092                 call    _zszwrite
F00BB320: 94102050                 mov     0x50, %o2 ! 'P'
F00BB324: 94100019                 mov     %i1, %o2
F00BB328: d42e202c                 stb     %o2, [%i0+0x2C]
F00BB32C: 9210200c                 mov     0xC, %o1
F00BB330: d0062010                 ld      [%i0+0x10], %o0
F00BB334: 4000008c                 call    _zszwrite
F00BB338: 940aa0ff                 and     %o2, 0xFF, %o2
F00BB33C: 95366008                 srl     %i1, 8, %o2
F00BB340: d42e202d                 stb     %o2, [%i0+0x2D]
F00BB344: 9210200d                 mov     0xD, %o1
F00BB348: d0062010                 ld      [%i0+0x10], %o0
F00BB34C: 40000086                 call    _zszwrite
F00BB350: 940aa0ff                 and     %o2, 0xFF, %o2
F00BB354: 90102002                 mov     2, %o0
F00BB358: d02e202e                 stb     %o0, [%i0+0x2E]
F00BB35C: 9210200e                 mov     0xE, %o1
F00BB360: d0062010                 ld      [%i0+0x10], %o0
F00BB364: 40000080                 call    _zszwrite
F00BB368: 94102002                 mov     2, %o2
F00BB36C: 901020c1                 mov     0xC1, %o0
F00BB370: d02e2023                 stb     %o0, [%i0+0x23]
F00BB374: 92102003                 mov     3, %o1
F00BB378: d0062010                 ld      [%i0+0x10], %o0
F00BB37C: 4000007a                 call    _zszwrite
F00BB380: 941020c1                 mov     0xC1, %o2
F00BB384: 80a42000                 cmp     %l0, 0
F00BB388: 02800007                 be      loc_F00BB3A4
F00BB38C: 90102068                 mov     0x68, %o0 ! 'h'
F00BB390: d02e2025                 stb     %o0, [%i0+0x25]
F00BB394: 92102005                 mov     5, %o1
F00BB398: d0062010                 ld      [%i0+0x10], %o0
F00BB39C: 10800007                 ba      loc_F00BB3B8
F00BB3A0: 94102068                 mov     0x68, %o2 ! 'h'
F00BB3A4: 901020ea                 mov     0xEA, %o0
F00BB3A8: d02e2025                 stb     %o0, [%i0+0x25]
F00BB3AC: 92102005                 mov     5, %o1
F00BB3B0: d0062010                 ld      [%i0+0x10], %o0
F00BB3B4: 941020ea                 mov     0xEA, %o2
F00BB3B8: 4000006b                 call    _zszwrite
F00BB3BC: 01000000                 nop
F00BB3C0: 90102003                 mov     3, %o0
F00BB3C4: d02e202e                 stb     %o0, [%i0+0x2E]
F00BB3C8: 9210200e                 mov     0xE, %o1
F00BB3CC: d0062010                 ld      [%i0+0x10], %o0
F00BB3D0: 40000065                 call    _zszwrite
F00BB3D4: 94102003                 mov     3, %o2
F00BB3D8: d0162014                 lduh    [%i0+0x14], %o0
F00BB3DC: 90023ffe                 inc     -2, %o0
F00BB3E0: 912a2010                 sll     %o0, 16, %o0
F00BB3E4: 91322010                 srl     %o0, 16, %o0
F00BB3E8: 80a22001                 cmp     %o0, 1
F00BB3EC: 18800007                 bgu     loc_F00BB408
F00BB3F0: 901020e8                 mov     0xE8, %o0
F00BB3F4: d02e202f                 stb     %o0, [%i0+0x2F]
F00BB3F8: 9210200f                 mov     0xF, %o1
F00BB3FC: d0062010                 ld      [%i0+0x10], %o0
F00BB400: 40000059                 call    _zszwrite
F00BB404: 941020e8                 mov     0xE8, %o2
F00BB408: d2062010                 ld      [%i0+0x10], %o1
F00BB40C: 90102040                 mov     0x40, %o0 ! '@'
F00BB410: d02a4000                 stb     %o0, [%o1]
F00BB414: 81c7e008                 ret
F00BB418: 81e80000                 restore
