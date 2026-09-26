F00DE708: 9de3bf98                 save    %sp, -0x68, %sp
F00DE70C: 80a62000                 cmp     %i0, 0
F00DE710: 12800004                 bne     loc_F00DE720
F00DE714: 94100019                 mov     %i1, %o2
F00DE718: 10800020                 ba      locret_F00DE798
F00DE71C: b01020ca                 mov     0xCA, %i0
F00DE720: 133c0505                 sethi   %hi(paCheckowner), %o1
F00DE724: d2026018                 ld      [%o1+%lo(paCheckowner)], %o1! SEL
F00DE728: 40004c52                 call    _objc_msgSend
F00DE72C: 90100018                 mov     %i0, %o0
F00DE730: 912a2018                 sll     %o0, 24, %o0
F00DE734: 80a22000                 cmp     %o0, 0
F00DE738: 02800017                 be      loc_F00DE794
F00DE73C: 113c0505                 sethi   %hi(paAudiodevice), %o0
F00DE740: e2022224                 ld      [%o0+%lo(paAudiodevice)], %l1
F00DE744: 90100018                 mov     %i0, %o0! id
F00DE748: 40004c4a                 call    _objc_msgSend
F00DE74C: 92100011                 mov     %l1, %o1
F00DE750: 9410200c                 mov     0xC, %o2
F00DE754: 9610001a                 mov     %i2, %o3
F00DE758: 133c0505                 sethi   %hi(paSetparameterTo), %o1! SEL
F00DE75C: e00260fc                 ld      [%o1+%lo(paSetparameterTo)], %l0
F00DE760: 98100018                 mov     %i0, %o4
F00DE764: 40004c43                 call    _objc_msgSend
F00DE768: 92100010                 mov     %l0, %o1! SEL
F00DE76C: 90100018                 mov     %i0, %o0! id
F00DE770: 40004c40                 call    _objc_msgSend
F00DE774: 92100011                 mov     %l1, %o1
F00DE778: 92100010                 mov     %l0, %o1! SEL
F00DE77C: 9410200d                 mov     0xD, %o2
F00DE780: 9610001b                 mov     %i3, %o3
F00DE784: 40004c3b                 call    _objc_msgSend
F00DE788: 98100018                 mov     %i0, %o4
F00DE78C: 10800003                 ba      locret_F00DE798
F00DE790: b0102000                 mov     0, %i0
F00DE794: b01020c8                 mov     0xC8, %i0
F00DE798: 81c7e008                 ret
F00DE79C: 81e80000                 restore
