F009E53C: 9de3bf98                 save    %sp, -0x68, %sp
F009E540: 133c04f792126270         set     _pmap_info, %o1
F009E548: d0026068                 ld      [%o1+0x68], %o0
F009E54C: 90022001                 inc     %o0
F009E550: d0226068                 st      %o0, [%o1+0x68]
F009E554: 113c04d0                 sethi   %hi(_page_mask), %o0
F009E558: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F009E55C: b406401a                 add     %i1, %i2, %i2
F009E560: b4068008                 add     %i2, %o0, %i2
F009E564: b42e8008                 bclr    %o0, %i2
F009E568: 80a6401a                 cmp     %i1, %i2
F009E56C: 1a800011                 bcc     locret_F009E5B0
F009E570: 233c04f0                 sethi   -0xFEC4000, %l1
F009E574: 213c0447                 sethi   -0xFEEE400, %l0
F009E578: d0046100                 ld      [%l1+0x100], %o0
F009E57C: 40000242                 call    _pmap_resident_extract
F009E580: 9210001b                 mov     %i3, %o1
F009E584: 94100008                 mov     %o0, %o2
F009E588: 90100018                 mov     %i0, %o0
F009E58C: 92100019                 mov     %i1, %o1
F009E590: 96102003                 mov     3, %o3
F009E594: 7fffffc6                 call    _pmap_enter
F009E598: 98102001                 mov     1, %o4
F009E59C: d004213c                 ld      [%l0+0x13C], %o0
F009E5A0: b2064008                 add     %i1, %o0, %i1
F009E5A4: 80a6401a                 cmp     %i1, %i2
F009E5A8: 0abffff4                 bcs     loc_F009E578
F009E5AC: b606c008                 add     %i3, %o0, %i3
F009E5B0: 81c7e008                 ret
F009E5B4: 81e80000                 restore
