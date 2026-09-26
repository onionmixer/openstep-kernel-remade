F00D5318: 9de3bf90                 save    %sp, -0x70, %sp
F00D531C: f627bff4                 st      %i3, [%fp+var_C]
F00D5320: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D5324: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D5328: 133c0505                 sethi   %hi(paInstance), %o1
F00D532C: d2026278                 ld      [%o1+%lo(paInstance)], %o1! SEL
F00D5330: 40007150                 call    _objc_msgSend
F00D5334: f6274000                 st      %i3, [%i5]
F00D5338: 80a22000                 cmp     %o0, 0
F00D533C: 12800004                 bne     loc_F00D534C
F00D5340: 133c0504                 sethi   -0xFEBF000, %o1
F00D5344: 1080000b                 ba      locret_F00D5370
F00D5348: b0103d27                 mov     -0x2D9, %i0
F00D534C: d20262c8                 ld      [%o1+0x2C8], %o1! SEL
F00D5350: 9410001c                 mov     %i4, %o2
F00D5354: 9610001a                 mov     %i2, %o3
F00D5358: 40007146                 call    _objc_msgSend
F00D535C: 9807bff4                 add     %fp, var_C, %o4
F00D5360: b0920000                 orcc    %o0, %g0, %i0
F00D5364: 12800003                 bne     locret_F00D5370
F00D5368: d007bff4                 ld      [%fp+var_C], %o0
F00D536C: d0274000                 st      %o0, [%i5]
F00D5370: 81c7e008                 ret
F00D5374: 81e80000                 restore
