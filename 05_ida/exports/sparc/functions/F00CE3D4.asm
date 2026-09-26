F00CE3D4: 9de3be88                 save    %sp, -0x178, %sp
F00CE3D8: fa262184                 st      %i5, [%i0+0x184]
F00CE3DC: f62e2188                 stb     %i3, [%i0+0x188]
F00CE3E0: f82e2189                 stb     %i4, [%i0+0x189]
F00CE3E4: 90100018                 mov     %i0, %o0! id
F00CE3E8: 133c0504                 sethi   %hi(paSetunit), %o1
F00CE3EC: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00CE3F0: 40008d20                 call    _objc_msgSend
F00CE3F4: 9410001a                 mov     %i2, %o2
F00CE3F8: a007bf38                 add     %fp, var_C8, %l0
F00CE3FC: 90100010                 mov     %l0, %o0! char *
F00CE400: 133c03ec92126370         set     aSdD, %o1! "sd%d"
F00CE408: 7ffd18d8                 call    _sprintf
F00CE40C: 9410001a                 mov     %i2, %o2
F00CE410: 90100018                 mov     %i0, %o0! id
F00CE414: 133c0504                 sethi   %hi(paSetname), %o1
F00CE418: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00CE41C: 40008d15                 call    _objc_msgSend
F00CE420: 94100010                 mov     %l0, %o2
F00CE424: a007bfa8                 add     %fp, var_58, %l0
F00CE428: 90100010                 mov     %l0, %o0! void *
F00CE42C: 7fff1a8b                 call    _bzero
F00CE430: 92102041                 mov     0x41, %o1 ! 'A'
F00CE434: 90100018                 mov     %i0, %o0! id
F00CE438: 133c0505                 sethi   %hi(paSdinquiry), %o1
F00CE43C: d20263b8                 ld      [%o1+%lo(paSdinquiry)], %o1! SEL
F00CE440: 40008d0c                 call    _objc_msgSend
F00CE444: 94100010                 mov     %l0, %o2
F00CE448: 80a22000                 cmp     %o0, 0
F00CE44C: 02800006                 be      loc_F00CE464
F00CE450: 80a22001                 cmp     %o0, 1
F00CE454: 128000ba                 bne     locret_F00CE73C
F00CE458: b0102003                 mov     3, %i0
F00CE45C: 108000b8                 ba      locret_F00CE73C
F00CE460: b0102002                 mov     2, %i0
F00CE464: d00fbfa8                 ldub    [%fp+var_58], %o0
F00CE468: 808a20e0                 btst    0xE0, %o0
F00CE46C: 328000b4                 bne,a   locret_F00CE73C
F00CE470: b0102001                 mov     1, %i0
F00CE474: 900a201f                 and     %o0, 0x1F, %o0
F00CE478: 80a22005                 cmp     %o0, 5
F00CE47C: 14800006                 bg      loc_F00CE494
F00CE480: 80a22007                 cmp     %o0, 7
F00CE484: 80a22004                 cmp     %o0, 4
F00CE488: 36800007                 bge,a   loc_F00CE4A4
F00CE48C: d00fbfa8                 ldub    [%fp+var_58], %o0
F00CE490: 80a22000                 cmp     %o0, 0
F00CE494: 02800004                 be      loc_F00CE4A4
F00CE498: d00fbfa8                 ldub    [%fp+var_58], %o0
F00CE49C: 108000a8                 ba      locret_F00CE73C
F00CE4A0: b0102001                 mov     1, %i0
F00CE4A4: 900a201f                 and     %o0, 0x1F, %o0
F00CE4A8: d02e21bc                 stb     %o0, [%i0+0x1BC]
F00CE4AC: d00fbfa9                 ldub    [%fp+var_57], %o0
F00CE4B0: 808a2080                 btst    0x80, %o0
F00CE4B4: 02800006                 be      loc_F00CE4CC
F00CE4B8: 90100018                 mov     %i0, %o0! id
F00CE4BC: 133c0506                 sethi   %hi(paSetremovable), %o1
F00CE4C0: d20261b0                 ld      [%o1+%lo(paSetremovable)], %o1! SEL
F00CE4C4: 40008ceb                 call    _objc_msgSend
F00CE4C8: 94102001                 mov     1, %o2
F00CE4CC: ae07bfb0                 add     %fp, var_50, %l7
F00CE4D0: 90100017                 mov     %l7, %o0
F00CE4D4: b407bf58                 add     %fp, var_A8, %i2
F00CE4D8: 9210001a                 mov     %i2, %o1
F00CE4DC: 94102008                 mov     8, %o2
F00CE4E0: ac102050                 mov     0x50, %l6 ! 'P'
F00CE4E4: 7fffff63                 call    sub_F00CE270
F00CE4E8: 96100016                 mov     %l6, %o3
F00CE4EC: 92100008                 mov     %o0, %o1
F00CE4F0: a0068009                 add     %i2, %o1, %l0
F00CE4F4: d04c3fff                 ldsb    [%l0-1], %o0
F00CE4F8: 80a22020                 cmp     %o0, 0x20 ! ' '
F00CE4FC: 02800004                 be      loc_F00CE50C
F00CE500: 90102020                 mov     0x20, %o0 ! ' '
F00CE504: d02e8009                 stb     %o0, [%i2+%o1]
F00CE508: a0042001                 inc     %l0
F00CE50C: aa07bfb8                 add     %fp, var_48, %l5
F00CE510: 90100015                 mov     %l5, %o0
F00CE514: 92100010                 mov     %l0, %o1
F00CE518: 94102010                 mov     0x10, %o2
F00CE51C: 96043fb0                 add     %l0, -0x50, %o3
F00CE520: 7fffff54                 call    sub_F00CE270
F00CE524: 9626800b                 sub     %i2, %o3, %o3
F00CE528: a0040008                 add     %l0, %o0, %l0
F00CE52C: d04c3fff                 ldsb    [%l0-1], %o0
F00CE530: 80a22020                 cmp     %o0, 0x20 ! ' '
F00CE534: 02800005                 be      loc_F00CE548
F00CE538: a807bfc8                 add     %fp, var_38, %l4
F00CE53C: 90102020                 mov     0x20, %o0 ! ' '
F00CE540: d02c0000                 stb     %o0, [%l0]
F00CE544: a0042001                 inc     %l0
F00CE548: 90100014                 mov     %l4, %o0
F00CE54C: 92100010                 mov     %l0, %o1
F00CE550: 94102004                 mov     4, %o2
F00CE554: 96043fb0                 add     %l0, -0x50, %o3
F00CE558: 7fffff46                 call    sub_F00CE270
F00CE55C: 9626800b                 sub     %i2, %o3, %o3
F00CE560: c02c0008                 clrb    [%l0+%o0]
F00CE564: 90100018                 mov     %i0, %o0! id
F00CE568: 133c0506                 sethi   %hi(paSetdrivename), %o1! SEL
F00CE56C: e4026184                 ld      [%o1+%lo(paSetdrivename)], %l2
F00CE570: 9410001a                 mov     %i2, %o2
F00CE574: 40008cbf                 call    _objc_msgSend
F00CE578: 92100012                 mov     %l2, %o1! SEL
F00CE57C: 113c0504                 sethi   %hi(paName), %o0
F00CE580: b607bee8                 add     %fp, var_118, %i3
F00CE584: e6022008                 ld      [%o0+%lo(paName)], %l3
F00CE588: 153c03ec                 sethi   %hi(aTargetDLunDAtS), %o2! "Target %d LUN %d at %s"
F00CE58C: e20e2188                 ldub    [%i0+0x188], %l1
F00CE590: b212a378                 or      %o2, %lo(aTargetDLunDAtS), %i1! "Target %d LUN %d at %s"
F00CE594: e00e2189                 ldub    [%i0+0x189], %l0
F00CE598: 9010001d                 mov     %i5, %o0! id
F00CE59C: 40008cb5                 call    _objc_msgSend
F00CE5A0: 92100013                 mov     %l3, %o1
F00CE5A4: 98100008                 mov     %o0, %o4
F00CE5A8: 9010001b                 mov     %i3, %o0! char *
F00CE5AC: 92100019                 mov     %i1, %o1! char *
F00CE5B0: 94100011                 mov     %l1, %o2
F00CE5B4: 7ffd186d                 call    _sprintf
F00CE5B8: 96100010                 mov     %l0, %o3
F00CE5BC: 90100018                 mov     %i0, %o0! id
F00CE5C0: 133c0504                 sethi   %hi(paSetlocation), %o1! SEL
F00CE5C4: f8026254                 ld      [%o1+%lo(paSetlocation)], %i4
F00CE5C8: 9410001b                 mov     %i3, %o2
F00CE5CC: 40008ca9                 call    _objc_msgSend
F00CE5D0: 9210001c                 mov     %i4, %o1
F00CE5D4: 113c03ec90122390         set     aSS, %o0! "%s: %s\n"
F00CE5DC: 9207bf38                 add     %fp, var_C8, %o1
F00CE5E0: 7fffdec5                 call    _IOLog
F00CE5E4: 9410001a                 mov     %i2, %o2
F00CE5E8: 113c0506                 sethi   %hi(paUpdatereadysta), %o0! id
F00CE5EC: d20221c8                 ld      [%o0+%lo(paUpdatereadysta)], %o1! SEL
F00CE5F0: 40008ca0                 call    _objc_msgSend
F00CE5F4: 90100018                 mov     %i0, %o0
F00CE5F8: 90100018                 mov     %i0, %o0! id
F00CE5FC: 94102000                 mov     0, %o2
F00CE600: 133c0505                 sethi   %hi(paScsistartstopI), %o1
F00CE604: d20263c8                 ld      [%o1+%lo(paScsistartstopI)], %o1! SEL
F00CE608: 40008c9a                 call    _objc_msgSend
F00CE60C: 96102001                 mov     1, %o3
F00CE610: 90100018                 mov     %i0, %o0! id
F00CE614: 133c0506                 sethi   %hi(paSetformattedin), %o1
F00CE618: d20261ac                 ld      [%o1+%lo(paSetformattedin)], %o1! SEL
F00CE61C: 40008c95                 call    _objc_msgSend
F00CE620: 94102000                 mov     0, %o2
F00CE624: 113c0504                 sethi   %hi(paUpdatephysical), %o0! id
F00CE628: d20221c4                 ld      [%o0+%lo(paUpdatephysical)], %o1! SEL
F00CE62C: 40008c91                 call    _objc_msgSend
F00CE630: 90100018                 mov     %i0, %o0
F00CE634: 9010001a                 mov     %i2, %o0! void *
F00CE638: 7fff1a08                 call    _bzero
F00CE63C: 92102050                 mov     0x50, %o1 ! 'P'
F00CE640: 90100017                 mov     %l7, %o0
F00CE644: 9210001a                 mov     %i2, %o1
F00CE648: 94102008                 mov     8, %o2
F00CE64C: 7fffff09                 call    sub_F00CE270
F00CE650: 96100016                 mov     %l6, %o3
F00CE654: 92100008                 mov     %o0, %o1
F00CE658: a0068009                 add     %i2, %o1, %l0
F00CE65C: d04c3fff                 ldsb    [%l0-1], %o0
F00CE660: 80a22020                 cmp     %o0, 0x20 ! ' '
F00CE664: 02800004                 be      loc_F00CE674
F00CE668: 90102020                 mov     0x20, %o0 ! ' '
F00CE66C: d02e8009                 stb     %o0, [%i2+%o1]
F00CE670: a0042001                 inc     %l0
F00CE674: 90100015                 mov     %l5, %o0
F00CE678: 92100010                 mov     %l0, %o1
F00CE67C: 94102010                 mov     0x10, %o2
F00CE680: 96043fb0                 add     %l0, -0x50, %o3
F00CE684: 7ffffefb                 call    sub_F00CE270
F00CE688: 9626800b                 sub     %i2, %o3, %o3
F00CE68C: a0040008                 add     %l0, %o0, %l0
F00CE690: d04c3fff                 ldsb    [%l0-1], %o0
F00CE694: 80a22020                 cmp     %o0, 0x20 ! ' '
F00CE698: 22800006                 be,a    loc_F00CE6B0
F00CE69C: 90100014                 mov     %l4, %o0
F00CE6A0: 90102020                 mov     0x20, %o0 ! ' '
F00CE6A4: d02c0000                 stb     %o0, [%l0]
F00CE6A8: a0042001                 inc     %l0
F00CE6AC: 90100014                 mov     %l4, %o0
F00CE6B0: 92100010                 mov     %l0, %o1
F00CE6B4: 94102020                 mov     0x20, %o2 ! ' '
F00CE6B8: 96043fb0                 add     %l0, -0x50, %o3
F00CE6BC: 7ffffeed                 call    sub_F00CE270
F00CE6C0: 9626800b                 sub     %i2, %o3, %o3
F00CE6C4: c02c0008                 clrb    [%l0+%o0]
F00CE6C8: 90100018                 mov     %i0, %o0! id
F00CE6CC: 92100012                 mov     %l2, %o1! SEL
F00CE6D0: 40008c68                 call    _objc_msgSend
F00CE6D4: 9410001a                 mov     %i2, %o2
F00CE6D8: e20e2188                 ldub    [%i0+0x188], %l1
F00CE6DC: 9010001d                 mov     %i5, %o0! id
F00CE6E0: e00e2189                 ldub    [%i0+0x189], %l0
F00CE6E4: 40008c63                 call    _objc_msgSend
F00CE6E8: 92100013                 mov     %l3, %o1
F00CE6EC: 98100008                 mov     %o0, %o4
F00CE6F0: 9010001b                 mov     %i3, %o0! char *
F00CE6F4: 92100019                 mov     %i1, %o1! char *
F00CE6F8: 94100011                 mov     %l1, %o2
F00CE6FC: 7ffd181b                 call    _sprintf
F00CE700: 96100010                 mov     %l0, %o3
F00CE704: 90100018                 mov     %i0, %o0! id
F00CE708: 9210001c                 mov     %i4, %o1! SEL
F00CE70C: 40008c59                 call    _objc_msgSend
F00CE710: 9410001b                 mov     %i3, %o2
F00CE714: f027bff0                 st      %i0, [%fp+var_10]
F00CE718: 113c03ec                 sethi   %hi(aIodisk), %o0! "IODisk"
F00CE71C: 400083d0                 call    _objc_getOrigClass
F00CE720: 90122398                 bset    %lo(aIodisk), %o0! "IODisk"
F00CE724: d027bff4                 st      %o0, [%fp+var_C]
F00CE728: 113c0504                 sethi   %hi(paInit), %o0! objc_super *
F00CE72C: d202202c                 ld      [%o0+%lo(paInit)], %o1! SEL
F00CE730: 40008c93                 call    _objc_msgSendSuper
F00CE734: 9007bff0                 add     %fp, var_10, %o0
F00CE738: b0102000                 mov     0, %i0
F00CE73C: 81c7e008                 ret
F00CE740: 81e80000                 restore
