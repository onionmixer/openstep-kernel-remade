F00D36E0: 9de3bf90                 save    %sp, -0x70, %sp
F00D36E4: d0068000                 ld      [%i2], %o0! id
F00D36E8: 133c0504                 sethi   %hi(paRespondsto), %o1
F00D36EC: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00D36F0: 40007860                 call    _objc_msgSend
F00D36F4: d406a004                 ld      [%i2+4], %o2
F00D36F8: 912a2018                 sll     %o0, 24, %o0
F00D36FC: 80a22000                 cmp     %o0, 0
F00D3700: 0280000a                 be      loc_F00D3728
F00D3704: a610001a                 mov     %i2, %l3
F00D3708: d0068000                 ld      [%i2], %o0! id
F00D370C: 133c0504                 sethi   %hi(paPerformWith), %o1
F00D3710: d202601c                 ld      [%o1+%lo(paPerformWith)], %o1! SEL
F00D3714: d406a004                 ld      [%i2+4], %o2
F00D3718: 40007856                 call    _objc_msgSend
F00D371C: d606a008                 ld      [%i2+8], %o3
F00D3720: 10800014                 ba      locret_F00D3770
F00D3724: b0102000                 mov     0, %i0
F00D3728: 90100018                 mov     %i0, %o0! id
F00D372C: 133c0504                 sethi   %hi(paName), %o1
F00D3730: 213c03ef                 sethi   %hi(aSDoperforminio), %l0! "%s: _doPerformInIOThread: [%s] does not"...
F00D3734: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D3738: 4000784e                 call    _objc_msgSend
F00D373C: a0142278                 bset    %lo(aSDoperforminio), %l0! "%s: _doPerformInIOThread: [%s] does not"...
F00D3740: a4100008                 mov     %o0, %l2
F00D3744: 40006e91                 call    _object_getClassName
F00D3748: d004c000                 ld      [%l3], %o0! sel
F00D374C: a2100008                 mov     %o0, %l1
F00D3750: 40007fe3                 call    _sel_getName
F00D3754: d004e004                 ld      [%l3+4], %o0
F00D3758: 96100008                 mov     %o0, %o3
F00D375C: 90100010                 mov     %l0, %o0
F00D3760: 92100012                 mov     %l2, %o1
F00D3764: 7fffca64                 call    _IOLog
F00D3768: 94100011                 mov     %l1, %o2
F00D376C: b0103d41                 mov     -0x2BF, %i0
F00D3770: 81c7e008                 ret
F00D3774: 81e80000                 restore
