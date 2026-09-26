F00ED1AC: 9de3bf98                 save    %sp, -0x68, %sp
F00ED1B0: d406e004                 ld      [%i3+4], %o2
F00ED1B4: 9010001b                 mov     %i3, %o0
F00ED1B8: 9fc28000                 call    %o2
F00ED1BC: 92102014                 mov     0x14, %o1! data
F00ED1C0: a2100008                 mov     %o0, %l1
F00ED1C4: 113c04bc                 sethi   %hi(dword_F012F080), %o0
F00ED1C8: d0022080                 ld      [%o0+%lo(dword_F012F080)], %o0
F00ED1CC: 80a22000                 cmp     %o0, 0
F00ED1D0: 32800005                 bne,a   loc_F00ED1E4
F00ED1D4: d0060000                 ld      [%i0], %o0
F00ED1D8: 7fffffc4                 call    sub_F00ED0E8
F00ED1DC: 01000000                 nop
F00ED1E0: d0060000                 ld      [%i0], %o0
F00ED1E4: 80a22000                 cmp     %o0, 0
F00ED1E8: 32800006                 bne,a   loc_F00ED200
F00ED1EC: d0062004                 ld      [%i0+4], %o0
F00ED1F0: 113c03b79012229c         set     _NXPtrHash, %o0
F00ED1F8: d0260000                 st      %o0, [%i0]
F00ED1FC: d0062004                 ld      [%i0+4], %o0
F00ED200: 80a22000                 cmp     %o0, 0
F00ED204: 32800006                 bne,a   loc_F00ED21C
F00ED208: d0062008                 ld      [%i0+8], %o0
F00ED20C: 113c03b790122328         set     _NXPtrIsEqual, %o0
F00ED214: d0262004                 st      %o0, [%i0+4]
F00ED218: d0062008                 ld      [%i0+8], %o0
F00ED21C: 80a22000                 cmp     %o0, 0
F00ED220: 32800006                 bne,a   loc_F00ED238
F00ED224: d006200c                 ld      [%i0+0xC], %o0
F00ED228: 113c03b7901223ac         set     _NXNoEffectFree, %o0
F00ED230: d0262008                 st      %o0, [%i0+8]
F00ED234: d006200c                 ld      [%i0+0xC], %o0
F00ED238: 80a22000                 cmp     %o0, 0
F00ED23C: 02800004                 be      loc_F00ED24C
F00ED240: 113c03f3                 sethi   %hi(aNxcreatehashta), %o0! "*** NXCreateHashTable: invalid style\n"
F00ED244: 1080001f                 ba      loc_F00ED2C0
F00ED248: 90122240                 bset    %lo(aNxcreatehashta), %o0! "*** NXCreateHashTable: invalid style\n"
F00ED24C: 253c04bc                 sethi   %hi(dword_F012F080), %l2
F00ED250: d004a080                 ld      [%l2+%lo(dword_F012F080)], %o0! table
F00ED254: 4000011a                 call    _NXHashGet
F00ED258: 92100018                 mov     %i0, %o1
F00ED25C: a0920000                 orcc    %o0, %g0, %l0
F00ED260: 3280001b                 bne,a   loc_F00ED2CC
F00ED264: e0244000                 st      %l0, [%l1]
F00ED268: 40000e39                 call    _NXDefaultMallocZone
F00ED26C: 01000000                 nop
F00ED270: 40000e37                 call    _NXDefaultMallocZone
F00ED274: a0100008                 mov     %o0, %l0
F00ED278: d4042004                 ld      [%l0+4], %o2! __len
F00ED27C: 9fc28000                 call    %o2
F00ED280: 92102010                 mov     0x10, %o1
F00ED284: a0100008                 mov     %o0, %l0
F00ED288: 92100018                 mov     %i0, %o1! data
F00ED28C: 7ffc6b51                 call    _memmove
F00ED290: 94102010                 mov     0x10, %o2
F00ED294: d004a080                 ld      [%l2+0x80], %o0! table
F00ED298: 40000178                 call    _NXHashInsert
F00ED29C: 92100010                 mov     %l0, %o1! data
F00ED2A0: d004a080                 ld      [%l2+0x80], %o0! table
F00ED2A4: 40000106                 call    _NXHashGet
F00ED2A8: 92100018                 mov     %i0, %o1
F00ED2AC: a0920000                 orcc    %o0, %g0, %l0
F00ED2B0: 32800007                 bne,a   loc_F00ED2CC
F00ED2B4: e0244000                 st      %l0, [%l1]
F00ED2B8: 113c03f390122268         set     aNxcreatehashta_0, %o0! "*** NXCreateHashTable: bug\n"
F00ED2C0: 40000da2                 call    __NXLogError
F00ED2C4: b0102000                 mov     0, %i0
F00ED2C8: 3080000e                 ba,a    locret_F00ED300
F00ED2CC: c0246004                 clr     [%l1+4]
F00ED2D0: f4246010                 st      %i2, [%l1+0x10]
F00ED2D4: 7fffff4f                 call    sub_F00ED010
F00ED2D8: 90100019                 mov     %i1, %o0
F00ED2DC: 7fffff56                 call    sub_F00ED034
F00ED2E0: 90022001                 inc     %o0
F00ED2E4: 92100008                 mov     %o0, %o1
F00ED2E8: d2246008                 st      %o1, [%l1+8]
F00ED2EC: 9010001b                 mov     %i3, %o0
F00ED2F0: 40000e22                 call    _NXZoneCalloc
F00ED2F4: 94102008                 mov     8, %o2
F00ED2F8: d024600c                 st      %o0, [%l1+0xC]
F00ED2FC: b0100011                 mov     %l1, %i0
F00ED300: 81c7e008                 ret
F00ED304: 81e80000                 restore
