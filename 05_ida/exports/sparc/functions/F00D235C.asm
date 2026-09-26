F00D235C: 9de3bf88                 save    %sp, -0x78, %sp
F00D2360: c0274000                 clr     [%i5]
F00D2364: d04e21d0                 ldsb    [%i0+0x1D0], %o0
F00D2368: 80a22000                 cmp     %o0, 0
F00D236C: 22800031                 be,a    locret_F00D2430
F00D2370: b0103d3e                 mov     -0x2C2, %i0
F00D2374: d0062114                 ld      [%i0+0x114], %o0
F00D2378: 80a68008                 cmp     %i2, %o0
F00D237C: 1280002d                 bne     locret_F00D2430
F00D2380: b0103d3e                 mov     -0x2C2, %i0
F00D2384: 9010001b                 mov     %i3, %o0! name
F00D2388: 7fffc8a6                 call    _IOGetObjectForDeviceName
F00D238C: 9207bfec                 add     %fp, var_14, %o1
F00D2390: b0920000                 orcc    %o0, %g0, %i0
F00D2394: 02800017                 be      loc_F00D23F0
F00D2398: 133c0505                 sethi   -0xFEBEC00, %o1
F00D239C: 40007e5a                 call    _objc_getClass
F00D23A0: 9010001c                 mov     %i4, %o0! id
F00D23A4: 80a22000                 cmp     %o0, 0
F00D23A8: 02800022                 be      locret_F00D2430
F00D23AC: d027bfec                 st      %o0, [%fp+var_14]
F00D23B0: 133c0505                 sethi   %hi(paProbe_0), %o1
F00D23B4: f4026340                 ld      [%o1+%lo(paProbe_0)], %i2
F00D23B8: 133c0504                 sethi   %hi(paRespondsto), %o1
F00D23BC: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00D23C0: 40007d2c                 call    _objc_msgSend
F00D23C4: 9410001a                 mov     %i2, %o2
F00D23C8: 912a2018                 sll     %o0, 24, %o0
F00D23CC: 80a22000                 cmp     %o0, 0
F00D23D0: 02800018                 be      locret_F00D2430
F00D23D4: d007bfec                 ld      [%fp+var_14], %o0! id
F00D23D8: 40007d26                 call    _objc_msgSend
F00D23DC: 9210001a                 mov     %i2, %o1
F00D23E0: 80a22000                 cmp     %o0, 0
F00D23E4: 02800013                 be      locret_F00D2430
F00D23E8: d027bfec                 st      %o0, [%fp+var_14]
F00D23EC: 133c0505                 sethi   -0xFEBEC00, %o1
F00D23F0: f002635c                 ld      [%o1+0x35C], %i0
F00D23F4: d007bfec                 ld      [%fp+var_14], %o0! id
F00D23F8: 133c0504                 sethi   %hi(paRespondsto), %o1
F00D23FC: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00D2400: 40007d1c                 call    _objc_msgSend
F00D2404: 94100018                 mov     %i0, %o2
F00D2408: 912a2018                 sll     %o0, 24, %o0
F00D240C: 80a22000                 cmp     %o0, 0
F00D2410: 02800007                 be      loc_F00D242C
F00D2414: d007bfec                 ld      [%fp+var_14], %o0! id
F00D2418: 40007d16                 call    _objc_msgSend
F00D241C: 92100018                 mov     %i0, %o1
F00D2420: d0274000                 st      %o0, [%i5]
F00D2424: 10800003                 ba      locret_F00D2430
F00D2428: b0102000                 mov     0, %i0
F00D242C: b0103d3f                 mov     -0x2C1, %i0
F00D2430: 81c7e008                 ret
F00D2434: 81e80000                 restore
