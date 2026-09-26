F00D5378: 9de3bf90                 save    %sp, -0x70, %sp
F00D537C: f627bff4                 st      %i3, [%fp+var_C]
F00D5380: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00D5384: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00D5388: 133c0505                 sethi   %hi(paInstance), %o1
F00D538C: d2026278                 ld      [%o1+%lo(paInstance)], %o1! SEL
F00D5390: 40007138                 call    _objc_msgSend
F00D5394: f6274000                 st      %i3, [%i5]
F00D5398: 80a22000                 cmp     %o0, 0
F00D539C: 12800004                 bne     loc_F00D53AC
F00D53A0: 133c0504                 sethi   -0xFEBF000, %o1
F00D53A4: 1080000b                 ba      locret_F00D53D0
F00D53A8: b0103d27                 mov     -0x2D9, %i0
F00D53AC: d20262d0                 ld      [%o1+0x2D0], %o1! SEL
F00D53B0: 9410001c                 mov     %i4, %o2
F00D53B4: 9610001a                 mov     %i2, %o3
F00D53B8: 4000712e                 call    _objc_msgSend
F00D53BC: 9807bff4                 add     %fp, var_C, %o4
F00D53C0: b0920000                 orcc    %o0, %g0, %i0
F00D53C4: 12800003                 bne     locret_F00D53D0
F00D53C8: d007bff4                 ld      [%fp+var_C], %o0
F00D53CC: d0274000                 st      %o0, [%i5]
F00D53D0: 81c7e008                 ret
F00D53D4: 81e80000                 restore
