F00412EC: 9de3bf90                 save    %sp, -0x70, %sp
F00412F0: 113c04d0                 sethi   %hi(_active_threads), %o0
F00412F4: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F00412F8: 113c04d1                 sethi   %hi(_pageoutThread), %o0
F00412FC: d0022388                 ld      [%o0+%lo(_pageoutThread)], %o0
F0041300: aa102000                 mov     0, %l5
F0041304: 80a24008                 cmp     %o1, %o0
F0041308: 1280000b                 bne     loc_F0041334
F004130C: e4062030                 ld      [%i0+0x30], %l2
F0041310: d014a060                 lduh    [%l2+0x60], %o0
F0041314: 808a2001                 btst    1, %o0
F0041318: 02800008                 be      loc_F0041338
F004131C: 90100012                 mov     %l2, %o0
F0041320: d004a068                 ld      [%l2+0x68], %o0
F0041324: d0022198                 ld      [%o0+0x198], %o0
F0041328: 80a22000                 cmp     %o0, 0
F004132C: 328000bf                 bne,a   locret_F0041628
F0041330: b0102002                 mov     2, %i0
F0041334: 90100012                 mov     %l2, %o0
F0041338: 7ffff101                 call    _rlock_timeout
F004133C: 92102005                 mov     5, %o1
F0041340: 80a22001                 cmp     %o0, 1
F0041344: 228000b9                 be,a    locret_F0041628
F0041348: b0102002                 mov     2, %i0
F004134C: d0060000                 ld      [%i0], %o0
F0041350: e0022030                 ld      [%o0+0x30], %l0
F0041354: d0062024                 ld      [%i0+0x24], %o0
F0041358: d0022128                 ld      [%o0+0x128], %o0
F004135C: 80a42000                 cmp     %l0, 0
F0041360: 12800013                 bne     loc_F00413AC
F0041364: e8022024                 ld      [%o0+0x24], %l4
F0041368: 113c04d0                 sethi   %hi(_active_threads), %o0
F004136C: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0041370: d002200c                 ld      [%o0+0xC], %o0
F0041374: d002203c                 ld      [%o0+0x3C], %o0
F0041378: 80a22000                 cmp     %o0, 0
F004137C: 1280000a                 bne     loc_F00413A4
F0041380: 113c04cf                 sethi   -0xFECC400, %o0
F0041384: 113c0435                 sethi   %hi(aNfsFailureOnPa_0), %o0! "NFS failure on pageout: no credentials"...
F0041388: 7fff4cb4                 call    _printf
F004138C: 901223c8                 bset    %lo(aNfsFailureOnPa_0), %o0! "NFS failure on pageout: no credentials"...
F0041390: 3080007f                 ba,a    loc_F004158C
F0041394: 113c0436                 sethi   %hi(aNfsMappingErro), %o0! "NFS mapping error on pageout\n"
F0041398: 7fff4cb0                 call    _printf
F004139C: 90122080                 bset    %lo(aNfsMappingErro), %o0! "NFS mapping error on pageout\n"
F00413A0: 3080007b                 ba,a    loc_F004158C
F00413A4: d00221d8                 ld      [%o0+0x1D8], %o0
F00413A8: e002201c                 ld      [%o0+0x1C], %l0
F00413AC: d0140000                 lduh    [%l0], %o0
F00413B0: 90022001                 inc     %o0
F00413B4: d0340000                 sth     %o0, [%l0]
F00413B8: d004a070                 ld      [%l2+0x70], %o0
F00413BC: 80a22000                 cmp     %o0, 0
F00413C0: 22800005                 be,a    loc_F00413D4
F00413C4: e024a070                 st      %l0, [%l2+0x70]
F00413C8: 7fff3994                 call    _crfree
F00413CC: 01000000                 nop
F00413D0: e024a070                 st      %l0, [%l2+0x70]
F00413D4: 2d3c04d0                 sethi   -0xFECC000, %l6
F00413D8: 2f3c04cf                 sethi   -0xFECC400, %l7
F00413DC: 9010001b                 mov     %i3, %o0
F00413E0: 7fff1488                 call    _udiv
F00413E4: 92100014                 mov     %l4, %o1
F00413E8: 94100008                 mov     %o0, %o2
F00413EC: 9010001b                 mov     %i3, %o0
F00413F0: 92100014                 mov     %l4, %o1
F00413F4: 7fff152b                 call    _urem
F00413F8: a210000a                 mov     %o2, %l1
F00413FC: a6100008                 mov     %o0, %l3
F0041400: 90250013                 sub     %l4, %l3, %o0
F0041404: 80a2001a                 cmp     %o0, %i2
F0041408: 1a800003                 bcc     loc_F0041414
F004140C: a010001a                 mov     %i2, %l0
F0041410: a0100008                 mov     %o0, %l0
F0041414: 90100018                 mov     %i0, %o0
F0041418: d606201c                 ld      [%i0+0x1C], %o3
F004141C: 92100011                 mov     %l1, %o1
F0041420: d802e050                 ld      [%o3+0x50], %o4
F0041424: 9407bff4                 add     %fp, var_C, %o2
F0041428: 9fc30000                 call    %o4
F004142C: 9607bff0                 add     %fp, var_10, %o3
F0041430: d254a062                 ldsh    [%l2+0x62], %o1
F0041434: 80a26000                 cmp     %o1, 0
F0041438: 22800026                 be,a    loc_F00414D0
F004143C: d207bff0                 ld      [%fp+var_10], %o1
F0041440: d0060000                 ld      [%i0], %o0
F0041444: d2222034                 st      %o1, [%o0+0x34]
F0041448: d0060000                 ld      [%i0], %o0
F004144C: d0522004                 ldsh    [%o0+4], %o0
F0041450: 80a22000                 cmp     %o0, 0
F0041454: 1280004e                 bne     loc_F004158C
F0041458: d005a260                 ld      [%l6+0x260], %o0
F004145C: d002200c                 ld      [%o0+0xC], %o0
F0041460: d002203c                 ld      [%o0+0x3C], %o0
F0041464: 80a22000                 cmp     %o0, 0
F0041468: 02800008                 be      loc_F0041488
F004146C: d205e1d8                 ld      [%l7+0x1D8], %o1
F0041470: 113c0435                 sethi   %hi(aSD_2), %o0! "%s[%d]: "
F0041474: d4024000                 ld      [%o1], %o2
F0041478: 901223f0                 bset    %lo(aSD_2), %o0! "%s[%d]: "
F004147C: d452a030                 ldsh    [%o2+0x30], %o2
F0041480: 7fff4c76                 call    _printf
F0041484: 92026008                 inc     8, %o1
F0041488: d254a062                 ldsh    [%l2+0x62], %o1
F004148C: 80a2601c                 cmp     %o1, 0x1C
F0041490: 12800007                 bne     loc_F00414AC
F0041494: 80a26046                 cmp     %o1, 0x46 ! 'F'
F0041498: 113c0436                 sethi   %hi(aNfsWriteErrorO_0), %o0! "NFS write error on pageout: device full"...
F004149C: 7fff4c6f                 call    _printf
F00414A0: 90122000                 bset    %lo(aNfsWriteErrorO_0), %o0! "NFS write error on pageout: device full"...
F00414A4: 1080003a                 ba      loc_F004158C
F00414A8: c034a062                 clrh    [%l2+0x62]
F00414AC: 12800006                 bne     loc_F00414C4
F00414B0: 113c0436                 sethi   -0xFEF2800, %o0
F00414B4: 113c0436                 sethi   %hi(aNfsWriteErrorO_1), %o0! "NFS write error on pageout: stale file "...
F00414B8: 7fff4c68                 call    _printf
F00414BC: 90122030                 bset    %lo(aNfsWriteErrorO_1), %o0! "NFS write error on pageout: stale file "...
F00414C0: 30800033                 ba,a    loc_F004158C
F00414C4: 7fff4c65                 call    _printf
F00414C8: 90122060                 bset    0x60, %o0 ! '`'
F00414CC: 30800030                 ba,a    loc_F004158C
F00414D0: 80a26000                 cmp     %o1, 0
F00414D4: 06bfffb0                 bl      loc_F0041394
F00414D8: 80a40014                 cmp     %l0, %l4
F00414DC: 12800006                 bne     loc_F00414F4
F00414E0: d007bff4                 ld      [%fp+var_C], %o0
F00414E4: 7fff8d61                 call    _getblk
F00414E8: 94100010                 mov     %l0, %o2
F00414EC: 10800005                 ba      loc_F0041500
F00414F0: a2100008                 mov     %o0, %l1
F00414F4: 7fff8c0b                 call    _bread
F00414F8: 94100014                 mov     %l4, %o2
F00414FC: a2100008                 mov     %o0, %l1
F0041500: d0044000                 ld      [%l1], %o0
F0041504: 808a2004                 btst    4, %o0
F0041508: 02800025                 be      loc_F004159C
F004150C: 90064015                 add     %i1, %l5, %o0
F0041510: d2060000                 ld      [%i0], %o1
F0041514: d054601c                 ldsh    [%l1+0x1C], %o0
F0041518: d0226034                 st      %o0, [%o1+0x34]
F004151C: d0060000                 ld      [%i0], %o0
F0041520: d0522004                 ldsh    [%o0+4], %o0
F0041524: 80a22000                 cmp     %o0, 0
F0041528: 12800017                 bne     loc_F0041584
F004152C: d005a260                 ld      [%l6+0x260], %o0
F0041530: d002200c                 ld      [%o0+0xC], %o0
F0041534: d002203c                 ld      [%o0+0x3C], %o0
F0041538: 80a22000                 cmp     %o0, 0
F004153C: 02800008                 be      loc_F004155C
F0041540: d205e1d8                 ld      [%l7+0x1D8], %o1
F0041544: 113c0436                 sethi   %hi(aSD_3), %o0! "%s[%d]: "
F0041548: d4024000                 ld      [%o1], %o2
F004154C: 901220a0                 bset    %lo(aSD_3), %o0! "%s[%d]: "
F0041550: d452a030                 ldsh    [%o2+0x30], %o2
F0041554: 7fff4c41                 call    _printf
F0041558: 92026008                 inc     8, %o1
F004155C: d254601c                 ldsh    [%l1+0x1C], %o1
F0041560: 80a26046                 cmp     %o1, 0x46 ! 'F'
F0041564: 12800006                 bne     loc_F004157C
F0041568: 113c0436                 sethi   -0xFEF2800, %o0
F004156C: 113c0436                 sethi   %hi(aNfsReadErrorOn_0), %o0! "NFS read error on pageout: stale file h"...
F0041570: 7fff4c3a                 call    _printf
F0041574: 901220b0                 bset    %lo(aNfsReadErrorOn_0), %o0! "NFS read error on pageout: stale file h"...
F0041578: 30800003                 ba,a    loc_F0041584
F004157C: 7fff4c37                 call    _printf
F0041580: 901220e0                 bset    0xE0, %o0
F0041584: 7fff8cb9                 call    _brelse
F0041588: 90100011                 mov     %l1, %o0
F004158C: 7ffff044                 call    _runlock
F0041590: 90100012                 mov     %l2, %o0
F0041594: 10800025                 ba      locret_F0041628
F0041598: b0102002                 mov     2, %i0
F004159C: d2046020                 ld      [%l1+0x20], %o1
F00415A0: 94100010                 mov     %l0, %o2
F00415A4: 4001792e                 call    _copy_from_phys
F00415A8: 92024013                 add     %o1, %l3, %o1
F00415AC: d004a098                 ld      [%l2+0x98], %o0
F00415B0: b606c010                 add     %i3, %l0, %i3
F00415B4: 80a6c008                 cmp     %i3, %o0
F00415B8: 38800002                 bgu,a   loc_F00415C0
F00415BC: f624a098                 st      %i3, [%l2+0x98]
F00415C0: b4268010                 sub     %i2, %l0, %i2
F00415C4: aa054010                 add     %l5, %l0, %l5
F00415C8: d214a060                 lduh    [%l2+0x60], %o1
F00415CC: 90040013                 add     %l0, %l3, %o0
F00415D0: 80a20014                 cmp     %o0, %l4
F00415D4: 92126010                 bset    0x10, %o1
F00415D8: 1280000a                 bne     loc_F0041600
F00415DC: d234a060                 sth     %o1, [%l2+0x60]
F00415E0: 90100011                 mov     %l1, %o0
F00415E4: d2020000                 ld      [%o0], %o1
F00415E8: 15001000                 sethi   0x400000, %o2
F00415EC: 9212400a                 bset    %o2, %o1
F00415F0: 7fff8c96                 call    _bawrite
F00415F4: d2220000                 st      %o1, [%o0]
F00415F8: 10800005                 ba      loc_F004160C
F00415FC: 80a6a000                 cmp     %i2, 0
F0041600: 7fff8c81                 call    _bdwrite
F0041604: 90100011                 mov     %l1, %o0
F0041608: 80a6a000                 cmp     %i2, 0
F004160C: 02800004                 be      loc_F004161C
F0041610: 80a42000                 cmp     %l0, 0
F0041614: 12bfff73                 bne     loc_F00413E0
F0041618: 9010001b                 mov     %i3, %o0
F004161C: 7ffff020                 call    _runlock
F0041620: 90100012                 mov     %l2, %o0
F0041624: b0102000                 mov     0, %i0
F0041628: 81c7e008                 ret
F004162C: 81e80000                 restore
