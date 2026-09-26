F008E864: 9de3bf90                 save    %sp, -0x70, %sp
F008E868: 113c0504                 sethi   %hi(paAcquire), %o0
F008E86C: e0022098                 ld      [%o0+%lo(paAcquire)], %l0
F008E870: d0062008                 ld      [%i0+8], %o0! id
F008E874: 40018bff                 call    _objc_msgSend
F008E878: 92100010                 mov     %l0, %o1
F008E87C: d0062004                 ld      [%i0+4], %o0
F008E880: 80a22000                 cmp     %o0, 0
F008E884: 02800005                 be      loc_F008E898
F008E888: 133c0504                 sethi   %hi(paRelease), %o1
F008E88C: d0062008                 ld      [%i0+8], %o0
F008E890: 1080002b                 ba      loc_F008E93C
F008E894: d202609c                 ld      [%o1+%lo(paRelease)], %o1! SEL
F008E898: 113c0504                 sethi   %hi(paRelease), %o0
F008E89C: e202209c                 ld      [%o0+%lo(paRelease)], %l1
F008E8A0: f4262004                 st      %i2, [%i0+4]
F008E8A4: d0062008                 ld      [%i0+8], %o0! id
F008E8A8: 40018bf2                 call    _objc_msgSend
F008E8AC: 92100011                 mov     %l1, %o1
F008E8B0: 113c0504                 sethi   %hi(paSuspend), %o0! id
F008E8B4: d20220d4                 ld      [%o0+%lo(paSuspend)], %o1! SEL
F008E8B8: 40018bee                 call    _objc_msgSend
F008E8BC: 9010001a                 mov     %i2, %o0
F008E8C0: 133c0504                 sethi   %hi(paAttachdevicein), %o1
F008E8C4: d0062004                 ld      [%i0+4], %o0! id
F008E8C8: 94100018                 mov     %i0, %o2
F008E8CC: d20260dc                 ld      [%o1+%lo(paAttachdevicein)], %o1! SEL
F008E8D0: 40018be8                 call    _objc_msgSend
F008E8D4: 9610001d                 mov     %i5, %o3
F008E8D8: 80a22000                 cmp     %o0, 0
F008E8DC: 0280000f                 be      loc_F008E918
F008E8E0: 113c0504                 sethi   -0xFEBF000, %o0
F008E8E4: d0062008                 ld      [%i0+8], %o0! id
F008E8E8: 40018be2                 call    _objc_msgSend
F008E8EC: 92100010                 mov     %l0, %o1! SEL
F008E8F0: f626200c                 st      %i3, [%i0+0xC]
F008E8F4: f8262010                 st      %i4, [%i0+0x10]
F008E8F8: d0062008                 ld      [%i0+8], %o0! id
F008E8FC: 40018bdd                 call    _objc_msgSend
F008E900: 92100011                 mov     %l1, %o1
F008E904: 113c0504                 sethi   %hi(paResume), %o0! id
F008E908: d20220d8                 ld      [%o0+%lo(paResume)], %o1! SEL
F008E90C: 40018bd9                 call    _objc_msgSend
F008E910: 9010001a                 mov     %i2, %o0! id
F008E914: 3080000c                 ba,a    locret_F008E944
F008E918: d20220d8                 ld      [%o0+0xD8], %o1! SEL
F008E91C: 40018bd5                 call    _objc_msgSend
F008E920: 9010001a                 mov     %i2, %o0
F008E924: d0062008                 ld      [%i0+8], %o0! id
F008E928: 40018bd2                 call    _objc_msgSend
F008E92C: 92100010                 mov     %l0, %o1
F008E930: c0262004                 clr     [%i0+4]
F008E934: d0062008                 ld      [%i0+8], %o0! id
F008E938: 92100011                 mov     %l1, %o1! SEL
F008E93C: 40018bcd                 call    _objc_msgSend
F008E940: b0102000                 mov     0, %i0
F008E944: 81c7e008                 ret
F008E948: 81e80000                 restore
