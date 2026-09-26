F00BC380: 9de3bf78                 save    %sp, -0x88, %sp
F00BC384: 133c04c8                 sethi   %hi(dword_F0132074), %o1
F00BC388: d0026074                 ld      [%o1+%lo(dword_F0132074)], %o0
F00BC38C: 80a22000                 cmp     %o0, 0
F00BC390: 32800007                 bne,a   loc_F00BC3AC
F00BC394: 113c0503                 sethi   -0xFEBF400, %o0
F00BC398: 113c04c8                 sethi   %hi(dword_F0132070), %o0
F00BC39C: c0222070                 clr     [%o0+%lo(dword_F0132070)]
F00BC3A0: 90102001                 mov     1, %o0
F00BC3A4: d0226074                 st      %o0, [%o1+%lo(dword_F0132074)]
F00BC3A8: 113c0503                 sethi   -0xFEBF400, %o0! id
F00BC3AC: d20223f0                 ld      [%o0+0x3F0], %o1! SEL
F00BC3B0: 4000d530                 call    _objc_msgSend
F00BC3B4: 90100018                 mov     %i0, %o0
F00BC3B8: b0100008                 mov     %o0, %i0
F00BC3BC: 113c0506                 sethi   %hi(paNxlock), %o0
F00BC3C0: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00BC3C4: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00BC3C8: 4000d52a                 call    _objc_msgSend
F00BC3CC: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00BC3D0: 133c0504                 sethi   %hi(paMethodfor), %o1
F00BC3D4: e0026240                 ld      [%o1+%lo(paMethodfor)], %l0
F00BC3D8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00BC3DC: d4026000                 ld      [%o1+%lo(paLock)], %o2
F00BC3E0: d0262108                 st      %o0, [%i0+0x108]
F00BC3E4: 4000d523                 call    _objc_msgSend
F00BC3E8: 92100010                 mov     %l0, %o1
F00BC3EC: 133c04c8                 sethi   %hi(dword_F0132068), %o1
F00BC3F0: d0226068                 st      %o0, [%o1+%lo(dword_F0132068)]
F00BC3F4: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00BC3F8: d4026244                 ld      [%o1+%lo(paUnlock)], %o2
F00BC3FC: d0062108                 ld      [%i0+0x108], %o0! id
F00BC400: 4000d51c                 call    _objc_msgSend
F00BC404: 92100010                 mov     %l0, %o1
F00BC408: 133c04c8                 sethi   %hi(dword_F013206C), %o1
F00BC40C: d022606c                 st      %o0, [%o1+%lo(dword_F013206C)]
F00BC410: c0262120                 clr     [%i0+0x120]
F00BC414: 90062004                 add     %i0, 4, %o0
F00BC418: 92100018                 mov     %i0, %o1
F00BC41C: c022210c                 clr     [%o0+0x10C]
F00BC420: 90023ffc                 inc     -4, %o0
F00BC424: 80a20009                 cmp     %o0, %o1
F00BC428: 36bffffe                 bge,a   loc_F00BC420
F00BC42C: c022210c                 clr     [%o0+0x10C]
F00BC430: 253c04c8                 sethi   %hi(dword_F0132060), %l2
F00BC434: d404a060                 ld      [%l2+%lo(dword_F0132060)], %o2
F00BC438: 80a2a000                 cmp     %o2, 0
F00BC43C: 12800004                 bne     loc_F00BC44C
F00BC440: 133c04fd                 sethi   -0xFEC0C00, %o1
F00BC444: 113c04fd                 sethi   %hi(_kmId), %o0
F00BC448: f0222240                 st      %i0, [%o0+%lo(_kmId)]
F00BC44C: d6026228                 ld      [%o1+0x228], %o3
F00BC450: 213c04fd                 sethi   %hi(_kmId), %l0
F00BC454: d0042240                 ld      [%l0+%lo(_kmId)], %o0! id
F00BC458: 133c0504                 sethi   %hi(paSetunit), %o1
F00BC45C: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00BC460: 4000d504                 call    _objc_msgSend
F00BC464: d626210c                 st      %o3, [%i0+0x10C]
F00BC468: a207bfd8                 add     %fp, var_28, %l1
F00BC46C: 90100011                 mov     %l1, %o0! char *
F00BC470: 133c047f                 sethi   %hi(aKmdeviceD), %o1! "kmDevice%d"
F00BC474: d404a060                 ld      [%l2+0x60], %o2
F00BC478: 921262c0                 bset    %lo(aKmdeviceD), %o1! "kmDevice%d"
F00BC47C: 9602a001                 add     %o2, 1, %o3
F00BC480: 7ffd60ba                 call    _sprintf
F00BC484: d624a060                 st      %o3, [%l2+0x60]
F00BC488: d0042240                 ld      [%l0+%lo(_kmId)], %o0! id
F00BC48C: 133c0504                 sethi   %hi(paSetname), %o1
F00BC490: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00BC494: 4000d4f7                 call    _objc_msgSend
F00BC498: 94100011                 mov     %l1, %o2
F00BC49C: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00BC4A0: d0042240                 ld      [%l0+0x240], %o0! id
F00BC4A4: 153c047f                 sethi   %hi(aKmdevice_0), %o2! "kmDevice"
F00BC4A8: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00BC4AC: 4000d4f1                 call    _objc_msgSend
F00BC4B0: 9412a2d0                 bset    %lo(aKmdevice_0), %o2! "kmDevice"
F00BC4B4: d0042240                 ld      [%l0+0x240], %o0! id
F00BC4B8: 133c0504                 sethi   %hi(paSetlocation), %o1
F00BC4BC: d2026254                 ld      [%o1+%lo(paSetlocation)], %o1! SEL
F00BC4C0: 4000d4ec                 call    _objc_msgSend
F00BC4C4: 94102000                 mov     0, %o2
F00BC4C8: 81c7e008                 ret
F00BC4CC: 81e80000                 restore
