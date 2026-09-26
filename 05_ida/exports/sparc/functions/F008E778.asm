F008E778: 9de3bf90                 save    %sp, -0x70, %sp
F008E77C: 113c0504                 sethi   %hi(paAcquire), %o0
F008E780: e0022098                 ld      [%o0+%lo(paAcquire)], %l0
F008E784: d0062008                 ld      [%i0+8], %o0! id
F008E788: 40018c3a                 call    _objc_msgSend
F008E78C: 92100010                 mov     %l0, %o1
F008E790: d0062004                 ld      [%i0+4], %o0
F008E794: 80a22000                 cmp     %o0, 0
F008E798: 02800005                 be      loc_F008E7AC
F008E79C: 133c0504                 sethi   %hi(paRelease), %o1
F008E7A0: d0062008                 ld      [%i0+8], %o0
F008E7A4: 1080002c                 ba      loc_F008E854
F008E7A8: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F008E7AC: 113c0504                 sethi   %hi(paRelease), %o0
F008E7B0: e202209c                 ld      [%o0+%lo(paRelease)], %l1
F008E7B4: f4262004                 st      %i2, [%i0+4]
F008E7B8: d0062008                 ld      [%i0+8], %o0! id
F008E7BC: 40018c2d                 call    _objc_msgSend
F008E7C0: 92100011                 mov     %l1, %o1
F008E7C4: 113c0504                 sethi   %hi(paSuspend), %o0! id
F008E7C8: d20220d4                 ld      [%o0+%lo(paSuspend)], %o1! SEL
F008E7CC: 40018c29                 call    _objc_msgSend
F008E7D0: 9010001a                 mov     %i2, %o0
F008E7D4: 9010001a                 mov     %i2, %o0! id
F008E7D8: 133c0504                 sethi   %hi(paAttachdevicein_0), %o1
F008E7DC: d20260a8                 ld      [%o1+%lo(paAttachdevicein_0)], %o1! SEL
F008E7E0: 40018c24                 call    _objc_msgSend
F008E7E4: 94100018                 mov     %i0, %o2
F008E7E8: 80a22000                 cmp     %o0, 0
F008E7EC: 02800011                 be      loc_F008E830
F008E7F0: 113c0504                 sethi   -0xFEBF000, %o0
F008E7F4: d0062008                 ld      [%i0+8], %o0! id
F008E7F8: 40018c1e                 call    _objc_msgSend
F008E7FC: 92100010                 mov     %l0, %o1! SEL
F008E800: 113c023b901220ec         set     _IOSendInterrupt, %o0
F008E808: d026200c                 st      %o0, [%i0+0xC]
F008E80C: f6262010                 st      %i3, [%i0+0x10]
F008E810: d0062008                 ld      [%i0+8], %o0! id
F008E814: 40018c17                 call    _objc_msgSend
F008E818: 92100011                 mov     %l1, %o1
F008E81C: 113c0504                 sethi   %hi(paResume), %o0! id
F008E820: d20220d8                 ld      [%o0+%lo(paResume)], %o1! SEL
F008E824: 40018c13                 call    _objc_msgSend
F008E828: 9010001a                 mov     %i2, %o0! id
F008E82C: 3080000c                 ba,a    locret_F008E85C
F008E830: d20220d8                 ld      [%o0+0xD8], %o1! SEL
F008E834: 40018c0f                 call    _objc_msgSend
F008E838: 9010001a                 mov     %i2, %o0
F008E83C: d0062008                 ld      [%i0+8], %o0! id
F008E840: 40018c0c                 call    _objc_msgSend
F008E844: 92100010                 mov     %l0, %o1
F008E848: c0262004                 clr     [%i0+4]
F008E84C: d0062008                 ld      [%i0+8], %o0! id
F008E850: 92100011                 mov     %l1, %o1! SEL
F008E854: 40018c07                 call    _objc_msgSend
F008E858: b0102000                 mov     0, %i0
F008E85C: 81c7e008                 ret
F008E860: 81e80000                 restore
