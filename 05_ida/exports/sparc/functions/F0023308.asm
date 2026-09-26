F0023308: 9de3bf80                 save    %sp, -0x80, %sp
F002330C: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0023310: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0023314: e4022024                 ld      [%o0+0x24], %l2
F0023318: c027bfe4                 clr     [%fp+var_1C]
F002331C: d004a008                 ld      [%l2+8], %o0
F0023320: 96102000                 mov     0, %o3
F0023324: 808a2010                 btst    0x10, %o0
F0023328: 12800003                 bne     loc_F0023334
F002332C: d204a004                 ld      [%l2+4], %o1
F0023330: 9607bfe4                 add     %fp, var_1C, %o3
F0023334: 90100009                 mov     %o1, %o0
F0023338: 92102000                 mov     0, %o1
F002333C: 94102001                 mov     1, %o2
F0023340: 40000da1                 call    _lookupname
F0023344: 9807bfe0                 add     %fp, __n, %o4
F0023348: d20421dc                 ld      [%l0+0x1DC], %o1
F002334C: d02a6038                 stb     %o0, [%o1+0x38]
F0023350: d00421dc                 ld      [%l0+0x1DC], %o0
F0023354: d04a2038                 ldsb    [%o0+0x38], %o0
F0023358: 80a22000                 cmp     %o0, 0
F002335C: 128001ad                 bne     locret_F0023A10
F0023360: d007bfe0                 ld      [%fp+__n], %o0
F0023364: 80a22000                 cmp     %o0, 0
F0023368: 0280004d                 be      loc_F002349C
F002336C: d007bfe4                 ld      [%fp+var_1C], %o0
F0023370: 80a22000                 cmp     %o0, 0
F0023374: 02800005                 be      loc_F0023388
F0023378: d207bfe0                 ld      [%fp+__n], %o1
F002337C: 400015fa                 call    _vn_rele
F0023380: 01000000                 nop
F0023384: d207bfe0                 ld      [%fp+__n], %o1
F0023388: d0026024                 ld      [%o1+0x24], %o0
F002338C: d002200c                 ld      [%o0+0xC], %o0
F0023390: 808a2020                 btst    0x20, %o0 ! ' '
F0023394: 12800054                 bne     loc_F00234E4
F0023398: 01000000                 nop
F002339C: 40000a3f                 call    _dnlc_purge
F00233A0: 01000000                 nop
F00233A4: d207bfe0                 ld      [%fp+__n], %o1
F00233A8: d0126006                 lduh    [%o1+6], %o0
F00233AC: 80a22001                 cmp     %o0, 1
F00233B0: 2280000a                 be,a    loc_F00233D8
F00233B4: d0026028                 ld      [%o1+0x28], %o0
F00233B8: d004a008                 ld      [%l2+8], %o0
F00233BC: 808a2010                 btst    0x10, %o0
F00233C0: 32800006                 bne,a   loc_F00233D8
F00233C4: d0026028                 ld      [%o1+0x28], %o0
F00233C8: 400015e7                 call    _vn_rele
F00233CC: 90100009                 mov     %o1, %o0
F00233D0: 10800017                 ba      loc_F002342C
F00233D4: d20421dc                 ld      [%l0+0x1DC], %o1
F00233D8: 80a22002                 cmp     %o0, 2
F00233DC: 22800009                 be,a    loc_F0023400
F00233E0: d0126004                 lduh    [%o1+4], %o0
F00233E4: 400015e0                 call    _vn_rele
F00233E8: 90100009                 mov     %o1, %o0
F00233EC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00233F0: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00233F4: 90102014                 mov     0x14, %o0
F00233F8: 10800186                 ba      locret_F0023A10
F00233FC: d02a6038                 stb     %o0, [%o1+0x38]
F0023400: 808a2001                 btst    1, %o0
F0023404: 2280000d                 be,a    loc_F0023438
F0023408: d207bfe0                 ld      [%fp+__n], %o1
F002340C: d004a008                 ld      [%l2+8], %o0
F0023410: 808a2010                 btst    0x10, %o0
F0023414: 32800009                 bne,a   loc_F0023438
F0023418: d207bfe0                 ld      [%fp+__n], %o1
F002341C: 400015d2                 call    _vn_rele
F0023420: 90100009                 mov     %o1, %o0
F0023424: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0023428: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F002342C: 90102010                 mov     0x10, %o0
F0023430: 10800178                 ba      locret_F0023A10
F0023434: d02a6038                 stb     %o0, [%o1+0x38]
F0023438: d0126004                 lduh    [%o1+4], %o0
F002343C: 808a2001                 btst    1, %o0
F0023440: 02800007                 be      loc_F002345C
F0023444: 193c04cf                 sethi   -0xFECC400, %o4
F0023448: d004a008                 ld      [%l2+8], %o0
F002344C: 808a2010                 btst    0x10, %o0
F0023450: 12800031                 bne     loc_F0023514
F0023454: 808a2014                 btst    0x14, %o0
F0023458: 193c04cf                 sethi   -0xFECC400, %o4
F002345C: d00321d8                 ld      [%o4+0x1D8], %o0
F0023460: d402201c                 ld      [%o0+0x1C], %o2
F0023464: 90100009                 mov     %o1, %o0
F0023468: d602201c                 ld      [%o0+0x1C], %o3
F002346C: a21321d8                 or      %o4, 0x1D8, %l1
F0023470: d602e01c                 ld      [%o3+0x1C], %o3
F0023474: 9fc2c000                 call    %o3
F0023478: 92102080                 mov     0x80, %o1
F002347C: a0920000                 orcc    %o0, %g0, %l0
F0023480: 22800024                 be,a    loc_F0023510
F0023484: d004a008                 ld      [%l2+8], %o0
F0023488: 400015b7                 call    _vn_rele
F002348C: d007bfe0                 ld      [%fp+__n], %o0
F0023490: d0046004                 ld      [%l1+4], %o0
F0023494: 1080015f                 ba      locret_F0023A10
F0023498: e02a2038                 stb     %l0, [%o0+0x38]
F002349C: d404a008                 ld      [%l2+8], %o2
F00234A0: 808aa010                 btst    0x10, %o2
F00234A4: 0280000a                 be      loc_F00234CC
F00234A8: 80a22000                 cmp     %o0, 0
F00234AC: 02800005                 be      loc_F00234C0
F00234B0: d20421dc                 ld      [%l0+0x1DC], %o1
F00234B4: 400015ac                 call    _vn_rele
F00234B8: 01000000                 nop
F00234BC: d20421dc                 ld      [%l0+0x1DC], %o1
F00234C0: 90102002                 mov     2, %o0
F00234C4: 10800153                 ba      locret_F0023A10
F00234C8: d02a6038                 stb     %o0, [%o1+0x38]
F00234CC: d207bfe4                 ld      [%fp+var_1C], %o1
F00234D0: d0026024                 ld      [%o1+0x24], %o0
F00234D4: d002200c                 ld      [%o0+0xC], %o0
F00234D8: 808a2020                 btst    0x20, %o0 ! ' '
F00234DC: 02800008                 be      loc_F00234FC
F00234E0: 11000020                 sethi   0x8000, %o0
F00234E4: 400015a0                 call    _vn_rele
F00234E8: 90100009                 mov     %o1, %o0
F00234EC: d20421dc                 ld      [%l0+0x1DC], %o1
F00234F0: 90102016                 mov     0x16, %o0
F00234F4: 10800147                 ba      locret_F0023A10
F00234F8: d02a6038                 stb     %o0, [%o1+0x38]
F00234FC: 90128008                 bset    %o2, %o0
F0023500: d024a008                 st      %o0, [%l2+8]
F0023504: d227bfe0                 st      %o1, [%fp+__n]
F0023508: c027bfe4                 clr     [%fp+var_1C]
F002350C: d004a008                 ld      [%l2+8], %o0
F0023510: 808a2014                 btst    0x14, %o0
F0023514: 02800033                 be      loc_F00235E0
F0023518: 92102000                 mov     0, %o1
F002351C: d0048000                 ld      [%l2], %o0
F0023520: 40000f66                 call    _pn_get
F0023524: 9407bfe8                 add     %fp, var_18, %o2
F0023528: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F002352C: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F0023530: d02a6038                 stb     %o0, [%o1+0x38]
F0023534: d002a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o0
F0023538: d04a2038                 ldsb    [%o0+0x38], %o0
F002353C: 80a22000                 cmp     %o0, 0
F0023540: 12800132                 bne     loc_F0023A08
F0023544: d007bfe0                 ld      [%fp+__n], %o0
F0023548: 133c042f                 sethi   %hi(_vfssw), %o1
F002354C: 153c0430                 sethi   %hi(_vfsNVFS), %o2
F0023550: d002a08c                 ld      [%o2+%lo(_vfsNVFS)], %o0
F0023554: a01263d8                 or      %o1, %lo(_vfssw), %l0
F0023558: 80a40008                 cmp     %l0, %o0
F002355C: 1a800011                 bcc     loc_F00235A0
F0023560: 113c0430                 sethi   -0xFEF4000, %o0
F0023564: a210000a                 mov     %o2, %l1
F0023568: d2040000                 ld      [%l0], %o1! __s2
F002356C: 80a26000                 cmp     %o1, 0
F0023570: 02800007                 be      loc_F002358C
F0023574: d004608c                 ld      [%l1+0x8C], %o0! __s1
F0023578: 7fff930d                 call    _strcmp
F002357C: d007bfec                 ld      [%fp+__src], %o0
F0023580: 80a22000                 cmp     %o0, 0
F0023584: 02800006                 be      loc_F002359C
F0023588: d004608c                 ld      [%l1+0x8C], %o0
F002358C: a0042008                 inc     8, %l0
F0023590: 80a40008                 cmp     %l0, %o0
F0023594: 2abffff6                 bcs,a   loc_F002356C
F0023598: d2040000                 ld      [%l0], %o1
F002359C: 113c0430                 sethi   -0xFEF4000, %o0
F00235A0: d002208c                 ld      [%o0+0x8C], %o0
F00235A4: 80a40008                 cmp     %l0, %o0
F00235A8: 1280000a                 bne     loc_F00235D0
F00235AC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00235B0: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00235B4: 90102013                 mov     0x13, %o0
F00235B8: d02a6038                 stb     %o0, [%o1+0x38]
F00235BC: 4000156a                 call    _vn_rele
F00235C0: d007bfe0                 ld      [%fp+__n], %o0
F00235C4: 40000fc9                 call    _pn_free
F00235C8: 9007bfe8                 add     %fp, var_18, %o0
F00235CC: 30800111                 ba,a    locret_F0023A10
F00235D0: 40000fc6                 call    _pn_free
F00235D4: 9007bfe8                 add     %fp, var_18, %o0
F00235D8: 10800016                 ba      loc_F0023630
F00235DC: d004a008                 ld      [%l2+8], %o0
F00235E0: d2048000                 ld      [%l2], %o1
F00235E4: 80a26004                 cmp     %o1, 4
F00235E8: 1880000d                 bgu     loc_F002361C
F00235EC: 113c042f                 sethi   %hi(unk_F010BDA8), %o0
F00235F0: 901221a8                 bset    %lo(unk_F010BDA8), %o0
F00235F4: 932a6002                 sll     %o1, 2, %o1
F00235F8: d2024008                 ld      [%o1+%o0], %o1
F00235FC: 932a6003                 sll     %o1, 3, %o1
F0023600: 113c042f901223d8         set     _vfssw, %o0
F0023608: a0024008                 add     %o1, %o0, %l0
F002360C: d0042004                 ld      [%l0+4], %o0
F0023610: 80a22000                 cmp     %o0, 0
F0023614: 32800007                 bne,a   loc_F0023630
F0023618: d004a008                 ld      [%l2+8], %o0
F002361C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0023620: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F0023624: 90102013                 mov     0x13, %o0
F0023628: 108000f7                 ba      loc_F0023A04
F002362C: d02a6038                 stb     %o0, [%o1+0x38]
F0023630: 808a2010                 btst    0x10, %o0
F0023634: 0280004e                 be      loc_F002376C
F0023638: aa102000                 mov     0, %l5
F002363C: 113c04d4                 sethi   %hi(_rootvfs), %o0
F0023640: e2022160                 ld      [%o0+%lo(_rootvfs)], %l1
F0023644: 80a46000                 cmp     %l1, 0
F0023648: 02800014                 be      loc_F0023698
F002364C: 01000000                 nop
F0023650: d207bfe0                 ld      [%fp+__n], %o1
F0023654: d4026024                 ld      [%o1+0x24], %o2
F0023658: 80a28011                 cmp     %o2, %l1
F002365C: 3280000b                 bne,a   loc_F0023688
F0023660: e2044000                 ld      [%l1], %l1
F0023664: d0126004                 lduh    [%o1+4], %o0
F0023668: 808a2001                 btst    1, %o0
F002366C: 22800007                 be,a    loc_F0023688
F0023670: e2044000                 ld      [%l1], %l1
F0023674: d002600c                 ld      [%o1+0xC], %o0
F0023678: 80a22000                 cmp     %o0, 0
F002367C: 02800007                 be      loc_F0023698
F0023680: 80a46000                 cmp     %l1, 0
F0023684: e2044000                 ld      [%l1], %l1
F0023688: 80a46000                 cmp     %l1, 0
F002368C: 12bffff4                 bne     loc_F002365C
F0023690: 80a28011                 cmp     %o2, %l1
F0023694: 80a46000                 cmp     %l1, 0
F0023698: 12800006                 bne     loc_F00236B0
F002369C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00236A0: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00236A4: 90102002                 mov     2, %o0
F00236A8: 108000d7                 ba      loc_F0023A04
F00236AC: d02a6038                 stb     %o0, [%o1+0x38]
F00236B0: 400002bd                 call    _vfs_lock
F00236B4: 90100011                 mov     %l1, %o0
F00236B8: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F00236BC: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F00236C0: d02a6038                 stb     %o0, [%o1+0x38]
F00236C4: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00236C8: d04a2038                 ldsb    [%o0+0x38], %o0
F00236CC: 80a22000                 cmp     %o0, 0
F00236D0: 128000ce                 bne     loc_F0023A08
F00236D4: d007bfe0                 ld      [%fp+__n], %o0
F00236D8: 92102000                 mov     0, %o1
F00236DC: a607bfe8                 add     %fp, var_18, %l3
F00236E0: d004a004                 ld      [%l2+4], %o0
F00236E4: 40000ef5                 call    _pn_get
F00236E8: 94100013                 mov     %l3, %o2
F00236EC: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F00236F0: d02a6038                 stb     %o0, [%o1+0x38]
F00236F4: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00236F8: d04a2038                 ldsb    [%o0+0x38], %o0
F00236FC: 80a22000                 cmp     %o0, 0
F0023700: 22800007                 be,a    loc_F002371C
F0023704: d004a008                 ld      [%l2+8], %o0
F0023708: 40001517                 call    _vn_rele
F002370C: d007bfe0                 ld      [%fp+__n], %o0
F0023710: 400002af                 call    _vfs_unlock
F0023714: 90100011                 mov     %l1, %o0
F0023718: 308000be                 ba,a    locret_F0023A10
F002371C: 808a2001                 btst    1, %o0
F0023720: 0280000e                 be      loc_F0023758
F0023724: 113c042f                 sethi   %hi(aMountCanTRemou), %o0! "mount: can't remount ro\n"
F0023728: 7fffc3cc                 call    _printf
F002372C: 901221c0                 bset    %lo(aMountCanTRemou), %o0! "mount: can't remount ro\n"
F0023730: 90100011                 mov     %l1, %o0
F0023734: d40421dc                 ld      [%l0+0x1DC], %o2
F0023738: 92102016                 mov     0x16, %o1
F002373C: 400002a4                 call    _vfs_unlock
F0023740: d22aa038                 stb     %o1, [%o2+0x38]
F0023744: 40001508                 call    _vn_rele
F0023748: d007bfe0                 ld      [%fp+__n], %o0
F002374C: 40000f67                 call    _pn_free
F0023750: 90100013                 mov     %l3, %o0
F0023754: 308000af                 ba,a    locret_F0023A10
F0023758: e804600c                 ld      [%l1+0xC], %l4
F002375C: 90152040                 or      %l4, 0x40, %o0
F0023760: 900a3ffe                 and     %o0, -2, %o0
F0023764: 10800068                 ba      loc_F0023904
F0023768: d024600c                 st      %o0, [%l1+0xC]
F002376C: 92102000                 mov     0, %o1
F0023770: d004a004                 ld      [%l2+4], %o0
F0023774: 40000ed1                 call    _pn_get
F0023778: 9407bfe8                 add     %fp, var_18, %o2
F002377C: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2! __n
F0023780: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F0023784: d02a6038                 stb     %o0, [%o1+0x38]
F0023788: d002a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o0
F002378C: a8102000                 mov     0, %l4
F0023790: d04a2038                 ldsb    [%o0+0x38], %o0
F0023794: 80a22000                 cmp     %o0, 0
F0023798: 1280009b                 bne     loc_F0023A04
F002379C: a612a1dc                 or      %o2, %lo(dword_F0133DDC), %l3
F00237A0: 40011234                 call    _kalloc
F00237A4: 9010212c                 mov     0x12C, %o0
F00237A8: a2100008                 mov     %o0, %l1
F00237AC: c0244000                 clr     [%l1]
F00237B0: d0042004                 ld      [%l0+4], %o0
F00237B4: d0246004                 st      %o0, [%l1+4]
F00237B8: c024600c                 clr     [%l1+0xC]
F00237BC: c024601c                 clr     [%l1+0x1C]
F00237C0: c0246128                 clr     [%l1+0x128]
F00237C4: c0246120                 clr     [%l1+0x120]
F00237C8: d004fffc                 ld      [%l3-4], %o0
F00237CC: d002201c                 ld      [%o0+0x1C], %o0
F00237D0: d0122002                 lduh    [%o0+2], %o0
F00237D4: d0346124                 sth     %o0, [%l1+0x124]
F00237D8: d204a008                 ld      [%l2+8], %o1! int
F00237DC: 11000020                 sethi   0x8000, %o0
F00237E0: 808a4008                 btst    %o0, %o1
F00237E4: 0280000f                 be      loc_F0023820
F00237E8: e007bfec                 ld      [%fp+__src], %l0
F00237EC: 90100010                 mov     %l0, %o0! char *
F00237F0: 7fff8696                 call    _index
F00237F4: 9210202f                 mov     0x2F, %o1 ! '/'
F00237F8: 80a22000                 cmp     %o0, 0
F00237FC: 22800004                 be,a    loc_F002380C
F0023800: 90046020                 add     %l1, 0x20, %o0 ! ' '! __dst
F0023804: 10bffffa                 ba      loc_F00237EC
F0023808: a0022001                 add     %o0, 1, %l0
F002380C: 92100010                 mov     %l0, %o1! __src
F0023810: 7fff9043                 call    _strncpy
F0023814: 941020ff                 mov     0xFF, %o2! __n
F0023818: 10800022                 ba      loc_F00238A0
F002381C: 90846020                 addcc   %l1, 0x20, %o0 ! ' '
F0023820: 90046020                 add     %l1, 0x20, %o0 ! ' '! __dst
F0023824: d207bfec                 ld      [%fp+__src], %o1! __src
F0023828: 7fff903d                 call    _strncpy
F002382C: 941020ff                 mov     0xFF, %o2
F0023830: d407bfe0                 ld      [%fp+__n], %o2
F0023834: 113c043c                 sethi   %hi(_ufs_vnodeops), %o0
F0023838: d202a01c                 ld      [%o2+0x1C], %o1
F002383C: 90122160                 bset    %lo(_ufs_vnodeops), %o0
F0023840: 80a24008                 cmp     %o1, %o0
F0023844: 12800017                 bne     loc_F00238A0
F0023848: 90846020                 addcc   %l1, 0x20, %o0 ! ' '
F002384C: 1080000a                 ba      loc_F0023874
F0023850: d002a030                 ld      [%o2+0x30], %o0
F0023854: d0126044                 lduh    [%o1+0x44], %o0
F0023858: 90122010                 bset    0x10, %o0
F002385C: d0326044                 sth     %o0, [%o1+0x44]
F0023860: d002a030                 ld      [%o2+0x30], %o0! unsigned int
F0023864: 7fffbb85                 call    _sleep
F0023868: 9210200a                 mov     0xA, %o1
F002386C: d407bfe0                 ld      [%fp+__n], %o2! __n
F0023870: d002a030                 ld      [%o2+0x30], %o0
F0023874: d0122044                 lduh    [%o0+0x44], %o0
F0023878: 808a2001                 btst    1, %o0
F002387C: 32bffff6                 bne,a   loc_F0023854
F0023880: d202a030                 ld      [%o2+0x30], %o1
F0023884: d007bfe0                 ld      [%fp+__n], %o0
F0023888: d2022030                 ld      [%o0+0x30], %o1
F002388C: d0126044                 lduh    [%o1+0x44], %o0
F0023890: aa102001                 mov     1, %l5
F0023894: 90122001                 bset    1, %o0
F0023898: d0326044                 sth     %o0, [%o1+0x44]
F002389C: 90846020                 addcc   %l1, 0x20, %o0 ! ' '! __s1
F00238A0: 0280000b                 be      loc_F00238CC
F00238A4: 133c042f                 sethi   %hi(aNetAppleshare), %o1! "/Net/AppleShare"
F00238A8: 921261e0                 bset    %lo(aNetAppleshare), %o1! "/Net/AppleShare"
F00238AC: 7fff930f                 call    _strncmp
F00238B0: 9410200f                 mov     0xF, %o2
F00238B4: 80a22000                 cmp     %o0, 0
F00238B8: 32800006                 bne,a   loc_F00238D0
F00238BC: d0546124                 ldsh    [%l1+0x124], %o0
F00238C0: d004600c                 ld      [%l1+0xC], %o0
F00238C4: 90122100                 bset    0x100, %o0
F00238C8: d024600c                 st      %o0, [%l1+0xC]
F00238CC: d0546124                 ldsh    [%l1+0x124], %o0
F00238D0: 80a22000                 cmp     %o0, 0
F00238D4: 02800006                 be      loc_F00238EC
F00238D8: d007bfe0                 ld      [%fp+__n], %o0
F00238DC: d004a008                 ld      [%l2+8], %o0
F00238E0: 90122002                 bset    2, %o0
F00238E4: d024a008                 st      %o0, [%l2+8]
F00238E8: d007bfe0                 ld      [%fp+__n], %o0
F00238EC: d404a008                 ld      [%l2+8], %o2
F00238F0: 400001a9                 call    _vfs_add
F00238F4: 92100011                 mov     %l1, %o1
F00238F8: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F00238FC: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0023900: d02a6038                 stb     %o0, [%o1+0x38]
F0023904: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0023908: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F002390C: d04a2038                 ldsb    [%o0+0x38], %o0
F0023910: 80a22000                 cmp     %o0, 0
F0023914: 1280000b                 bne     loc_F0023940
F0023918: 80a56000                 cmp     %l5, 0
F002391C: d0046004                 ld      [%l1+4], %o0
F0023920: d207bfec                 ld      [%fp+__src], %o1
F0023924: d6020000                 ld      [%o0], %o3
F0023928: d404a00c                 ld      [%l2+0xC], %o2
F002392C: 9fc2c000                 call    %o3
F0023930: 90100011                 mov     %l1, %o0
F0023934: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0023938: d02a6038                 stb     %o0, [%o1+0x38]
F002393C: 80a56000                 cmp     %l5, 0
F0023940: 02800012                 be      loc_F0023988
F0023944: d607bfe0                 ld      [%fp+__n], %o3
F0023948: d002e030                 ld      [%o3+0x30], %o0
F002394C: 1300003f                 sethi   0xFC00, %o1
F0023950: d4122044                 lduh    [%o0+0x44], %o2
F0023954: 921263fe                 bset    0x3FE, %o1
F0023958: 940a8009                 and     %o2, %o1, %o2
F002395C: d4322044                 sth     %o2, [%o0+0x44]
F0023960: d402e030                 ld      [%o3+0x30], %o2
F0023964: d212a044                 lduh    [%o2+0x44], %o1
F0023968: 808a6010                 btst    0x10, %o1
F002396C: 02800007                 be      loc_F0023988
F0023970: 1100003f                 sethi   0xFC00, %o0
F0023974: 901223ef                 bset    0x3EF, %o0
F0023978: 900a4008                 and     %o1, %o0, %o0
F002397C: d032a044                 sth     %o0, [%o2+0x44]
F0023980: 7fffbd1a                 call    _wakeup
F0023984: d002e030                 ld      [%o3+0x30], %o0
F0023988: 40000ed8                 call    _pn_free
F002398C: 9007bfe8                 add     %fp, var_18, %o0
F0023990: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0023994: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0023998: d04a2038                 ldsb    [%o0+0x38], %o0
F002399C: 80a22000                 cmp     %o0, 0
F00239A0: 3280000c                 bne,a   loc_F00239D0
F00239A4: d004a008                 ld      [%l2+8], %o0
F00239A8: 40000209                 call    _vfs_unlock
F00239AC: 90100011                 mov     %l1, %o0
F00239B0: d004a008                 ld      [%l2+8], %o0
F00239B4: 808a2010                 btst    0x10, %o0
F00239B8: 02800016                 be      locret_F0023A10
F00239BC: d007bfe0                 ld      [%fp+__n], %o0
F00239C0: d204600c                 ld      [%l1+0xC], %o1
F00239C4: 920a7fbf                 and     %o1, -0x41, %o1
F00239C8: 10800010                 ba      loc_F0023A08
F00239CC: d224600c                 st      %o1, [%l1+0xC]
F00239D0: 808a2010                 btst    0x10, %o0
F00239D4: 02800007                 be      loc_F00239F0
F00239D8: 01000000                 nop
F00239DC: e824600c                 st      %l4, [%l1+0xC]
F00239E0: 400001fb                 call    _vfs_unlock
F00239E4: 90100011                 mov     %l1, %o0
F00239E8: 10800008                 ba      loc_F0023A08
F00239EC: d007bfe0                 ld      [%fp+__n], %o0
F00239F0: 400001b4                 call    _vfs_remove
F00239F4: 90100011                 mov     %l1, %o0
F00239F8: 90100011                 mov     %l1, %o0
F00239FC: 400111e9                 call    _kfree
F0023A00: 9210212c                 mov     0x12C, %o1
F0023A04: d007bfe0                 ld      [%fp+__n], %o0
F0023A08: 40001457                 call    _vn_rele
F0023A0C: 01000000                 nop
F0023A10: 81c7e008                 ret
F0023A14: 81e80000                 restore
