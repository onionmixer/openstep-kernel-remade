F004C32C: 9de3bf98                 save    %sp, -0x68, %sp
F004C330: d4066004                 ld      [%i1+4], %o2
F004C334: d0064000                 ld      [%i1], %o0
F004C338: d2066008                 ld      [%i1+8], %o1
F004C33C: 80a22000                 cmp     %o0, 0
F004C340: 1280002e                 bne     loc_F004C3F8
F004C344: a0028009                 add     %o2, %o1, %l0
F004C348: 808aa3ff                 btst    0x3FF, %o2
F004C34C: 02800004                 be      loc_F004C35C
F004C350: 113c043a                 sethi   %hi(aDirprepareentr), %o0! "dirprepareentry: new block"
F004C354: 7fff2387                 call    _panic
F004C358: 90122270                 bset    %lo(aDirprepareentr), %o0! "dirprepareentry: new block"
F004C35C: d0062050                 ld      [%i0+0x50], %o0
F004C360: d0022034                 ld      [%o0+0x34], %o0
F004C364: 80a223ff                 cmp     %o0, 0x3FF
F004C368: 34800006                 bg,a    loc_F004C380
F004C36C: d6062050                 ld      [%i0+0x50], %o3
F004C370: 113c043a                 sethi   %hi(aDirblksizFsize), %o0! "DIRBLKSIZ > fsize"
F004C374: 7fff237f                 call    _panic
F004C378: 90122290                 bset    %lo(aDirblksizFsize), %o0! "DIRBLKSIZ > fsize"
F004C37C: d6062050                 ld      [%i0+0x50], %o3
F004C380: d8066004                 ld      [%i1+4], %o4
F004C384: 90100018                 mov     %i0, %o0
F004C388: d202e050                 ld      [%o3+0x50], %o1
F004C38C: 94102000                 mov     0, %o2
F004C390: d602e048                 ld      [%o3+0x48], %o3
F004C394: 93330009                 srl     %o4, %o1, %o1
F004C398: 962b000b                 andn    %o4, %o3, %o3
F004C39C: 9602e400                 inc     0x400, %o3
F004C3A0: 7ffff9d5                 call    _bmap
F004C3A4: 98102000                 mov     0, %o4
F004C3A8: 80a22000                 cmp     %o0, 0
F004C3AC: 04800007                 ble     loc_F004C3C8
F004C3B0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004C3B4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004C3B8: d04a2038                 ldsb    [%o0+0x38], %o0
F004C3BC: 80a22000                 cmp     %o0, 0
F004C3C0: 2280000a                 be,a    loc_F004C3E8
F004C3C4: d0162044                 lduh    [%i0+0x44], %o0
F004C3C8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004C3CC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004C3D0: d04a2038                 ldsb    [%o0+0x38], %o0
F004C3D4: 80a22000                 cmp     %o0, 0
F004C3D8: 02800059                 be      locret_F004C53C
F004C3DC: b010201c                 mov     0x1C, %i0
F004C3E0: 10800057                 ba      locret_F004C53C
F004C3E4: b0100008                 mov     %o0, %i0
F004C3E8: e0262070                 st      %l0, [%i0+0x70]
F004C3EC: 90122042                 bset    0x42, %o0 ! 'B'
F004C3F0: 1080000b                 ba      loc_F004C41C
F004C3F4: d0362044                 sth     %o0, [%i0+0x44]
F004C3F8: d0062070                 ld      [%i0+0x70], %o0
F004C3FC: 80a40008                 cmp     %l0, %o0
F004C400: 08800007                 bleu    loc_F004C41C
F004C404: 900423ff                 add     %l0, 0x3FF, %o0
F004C408: 900a3c00                 and     %o0, -0x400, %o0
F004C40C: d2162044                 lduh    [%i0+0x44], %o1
F004C410: d0262070                 st      %o0, [%i0+0x70]
F004C414: 92126042                 bset    0x42, %o1 ! 'B'
F004C418: d2362044                 sth     %o1, [%i0+0x44]
F004C41C: 90100018                 mov     %i0, %o0
F004C420: d2066004                 ld      [%i1+4], %o1! size_t
F004C424: 400001f1                 call    _blkatoff
F004C428: 94066010                 add     %i1, 0x10, %o2
F004C42C: 80a22000                 cmp     %o0, 0
F004C430: 12800006                 bne     loc_F004C448
F004C434: d026600c                 st      %o0, [%i1+0xC]
F004C438: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004C43C: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004C440: 1080003f                 ba      locret_F004C53C
F004C444: f04a2038                 ldsb    [%o0+0x38], %i0
F004C448: d0064000                 ld      [%i1], %o0
F004C44C: 80a22000                 cmp     %o0, 0
F004C450: 12800008                 bne     loc_F004C470
F004C454: e0066010                 ld      [%i1+0x10], %l0
F004C458: 90100010                 mov     %l0, %o0! void *
F004C45C: 4001227f                 call    _bzero
F004C460: 92102400                 mov     0x400, %o1
F004C464: 90102400                 mov     0x400, %o0
F004C468: 10800033                 ba      loc_F004C534
F004C46C: d0342004                 sth     %o0, [%l0+4]
F004C470: 80a22002                 cmp     %o0, 2
F004C474: 1880002d                 bgu     loc_F004C528
F004C478: a6100010                 mov     %l0, %l3
F004C47C: d0142006                 lduh    [%l0+6], %o0
F004C480: d2142004                 lduh    [%l0+4], %o1
F004C484: 90022004                 inc     4, %o0
F004C488: 900a3ffc                 and     %o0, -4, %o0
F004C48C: b0022008                 add     %o0, 8, %i0
F004C490: d0066008                 ld      [%i1+8], %o0
F004C494: a2100009                 mov     %o1, %l1
F004C498: 80a44008                 cmp     %l1, %o0
F004C49C: 16800019                 bge     loc_F004C500
F004C4A0: a4224018                 sub     %o1, %i0, %l2
F004C4A4: d0040000                 ld      [%l0], %o0
F004C4A8: 80a22000                 cmp     %o0, 0
F004C4AC: 02800005                 be      loc_F004C4C0
F004C4B0: 9004c011                 add     %l3, %l1, %o0! void *
F004C4B4: f0342004                 sth     %i0, [%l0+4]
F004C4B8: 10800003                 ba      loc_F004C4C4
F004C4BC: a0040018                 add     %l0, %i0, %l0
F004C4C0: a4048018                 add     %l2, %i0, %l2
F004C4C4: d4122006                 lduh    [%o0+6], %o2
F004C4C8: 92100010                 mov     %l0, %o1! void *
F004C4CC: d6122004                 lduh    [%o0+4], %o3
F004C4D0: 9402a004                 inc     4, %o2
F004C4D4: 940abffc                 and     %o2, -4, %o2
F004C4D8: b002a008                 add     %o2, 8, %i0
F004C4DC: 9422c018                 sub     %o3, %i0, %o2! size_t
F004C4E0: a404800a                 add     %l2, %o2, %l2
F004C4E4: a204400b                 add     %l1, %o3, %l1
F004C4E8: 4001218a                 call    _bcopy
F004C4EC: 94100018                 mov     %i0, %o2
F004C4F0: d0066008                 ld      [%i1+8], %o0
F004C4F4: 80a44008                 cmp     %l1, %o0
F004C4F8: 26bfffec                 bl,a    loc_F004C4A8
F004C4FC: d0040000                 ld      [%l0], %o0
F004C500: d0040000                 ld      [%l0], %o0
F004C504: 80a22000                 cmp     %o0, 0
F004C508: 32800005                 bne,a   loc_F004C51C
F004C50C: f0342004                 sth     %i0, [%l0+4]
F004C510: 90048018                 add     %l2, %i0, %o0
F004C514: 10800008                 ba      loc_F004C534
F004C518: d0342004                 sth     %o0, [%l0+4]
F004C51C: a0040018                 add     %l0, %i0, %l0
F004C520: 10800005                 ba      loc_F004C534
F004C524: e4342004                 sth     %l2, [%l0+4]
F004C528: 113c043a                 sethi   %hi(aDirprepareentr_0), %o0! "dirprepareentry: invalid slot status"
F004C52C: 7fff2311                 call    _panic
F004C530: 901222a8                 bset    %lo(aDirprepareentr_0), %o0! "dirprepareentry: invalid slot status"
F004C534: e0266010                 st      %l0, [%i1+0x10]
F004C538: b0102000                 mov     0, %i0
F004C53C: 81c7e008                 ret
F004C540: 81e80000                 restore
