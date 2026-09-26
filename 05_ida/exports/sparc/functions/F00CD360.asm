F00CD360: 9de3bf90                 save    %sp, -0x70, %sp
F00CD364: d006222c                 ld      [%i0+0x22C], %o0! id
F00CD368: 133c0504                 sethi   %hi(paLock), %o1
F00CD36C: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00CD370: 40009140                 call    _objc_msgSend
F00CD374: e007a05c                 ld      [%fp+arg_5C], %l0
F00CD378: 113c0504                 sethi   %hi(paNumberoftarget), %o0! id
F00CD37C: d20221f0                 ld      [%o0+%lo(paNumberoftarget)], %o1! SEL
F00CD380: 4000913c                 call    _objc_msgSend
F00CD384: 90100018                 mov     %i0, %o0
F00CD388: 9210001b                 mov     %i3, %o1
F00CD38C: 80a24008                 cmp     %o1, %o0
F00CD390: 06800006                 bl      loc_F00CD3A8
F00CD394: 113c03ec                 sethi   %hi(aIoscsicontroll), %o0! "IOSCSIController releaseTarget: INVALID"...
F00CD398: 7fffe357                 call    _IOLog
F00CD39C: 90122238                 bset    %lo(aIoscsicontroll), %o0! "IOSCSIController releaseTarget: INVALID"...
F00CD3A0: 1080002f                 ba      loc_F00CD45C
F00CD3A4: d006222c                 ld      [%i0+0x22C], %o0
F00CD3A8: 90100018                 mov     %i0, %o0! id
F00CD3AC: 133c0506                 sethi   %hi(paSearchreserveq), %o1! SEL
F00CD3B0: 9410001a                 mov     %i2, %o2
F00CD3B4: 9610001b                 mov     %i3, %o3
F00CD3B8: 9810001c                 mov     %i4, %o4
F00CD3BC: 9a10001d                 mov     %i5, %o5
F00CD3C0: 4000912c                 call    _objc_msgSend
F00CD3C4: d2026000                 ld      [%o1+%lo(paSearchreserveq)], %o1
F00CD3C8: 96920000                 orcc    %o0, %g0, %o3
F00CD3CC: 32800007                 bne,a   loc_F00CD3E8
F00CD3D0: d002e010                 ld      [%o3+0x10], %o0
F00CD3D4: 113c03ec                 sethi   %hi(aIoscsicontroll_0), %o0! "IOSCSIController releaseTarget: NOT RES"...
F00CD3D8: 7fffe347                 call    _IOLog
F00CD3DC: 90122268                 bset    %lo(aIoscsicontroll_0), %o0! "IOSCSIController releaseTarget: NOT RES"...
F00CD3E0: 1080001f                 ba      loc_F00CD45C
F00CD3E4: d006222c                 ld      [%i0+0x22C], %o0
F00CD3E8: 80a20010                 cmp     %o0, %l0
F00CD3EC: 02800006                 be      loc_F00CD404
F00CD3F0: 113c03ec                 sethi   %hi(aIoscsicontroll_1), %o0! "IOSCSIController releaseTarget: INVALID"...
F00CD3F4: 7fffe340                 call    _IOLog
F00CD3F8: 90122298                 bset    %lo(aIoscsicontroll_1), %o0! "IOSCSIController releaseTarget: INVALID"...
F00CD3FC: 10800018                 ba      loc_F00CD45C
F00CD400: d006222c                 ld      [%i0+0x22C], %o0
F00CD404: d402e014                 ld      [%o3+0x14], %o2
F00CD408: 90062128                 add     %i0, 0x128, %o0
F00CD40C: 80a2000a                 cmp     %o0, %o2
F00CD410: 12800004                 bne     loc_F00CD420
F00CD414: d202e018                 ld      [%o3+0x18], %o1
F00CD418: 10800003                 ba      loc_F00CD424
F00CD41C: 9010000a                 mov     %o2, %o0
F00CD420: 9002a014                 add     %o2, 0x14, %o0
F00CD424: d2222004                 st      %o1, [%o0+4]
F00CD428: 90062128                 add     %i0, 0x128, %o0
F00CD42C: 80a20009                 cmp     %o0, %o1
F00CD430: 12800003                 bne     loc_F00CD43C
F00CD434: 90026014                 add     %o1, 0x14, %o0
F00CD438: 90100009                 mov     %o1, %o0
F00CD43C: d4220000                 st      %o2, [%o0]
F00CD440: 9010000b                 mov     %o3, %o0
F00CD444: 7fffe2c0                 call    _IOFree
F00CD448: 92102020                 mov     0x20, %o1 ! ' '
F00CD44C: d0062228                 ld      [%i0+0x228], %o0
F00CD450: 90023fff                 inc     -1, %o0
F00CD454: d0262228                 st      %o0, [%i0+0x228]
F00CD458: d006222c                 ld      [%i0+0x22C], %o0! id
F00CD45C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00CD460: 40009104                 call    _objc_msgSend
F00CD464: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00CD468: 81c7e008                 ret
F00CD46C: 81e80000                 restore
