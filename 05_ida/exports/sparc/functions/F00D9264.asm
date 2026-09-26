F00D9264: 9de3bf90                 save    %sp, -0x70, %sp
F00D9268: 113c0505                 sethi   %hi(paInputchannel), %o0
F00D926C: d2022220                 ld      [%o0+%lo(paInputchannel)], %o1! SEL
F00D9270: a4102001                 mov     1, %l2
F00D9274: 113c0505                 sethi   %hi(paIsequal), %o0! id
F00D9278: e0022150                 ld      [%o0+%lo(paIsequal)], %l0
F00D927C: c026c000                 clr     [%i3]
F00D9280: 4000617c                 call    _objc_msgSend
F00D9284: 90100018                 mov     %i0, %o0
F00D9288: 94100008                 mov     %o0, %o2
F00D928C: 9010001d                 mov     %i5, %o0! id
F00D9290: 40006178                 call    _objc_msgSend
F00D9294: 92100010                 mov     %l0, %o1
F00D9298: 912a2018                 sll     %o0, 24, %o0
F00D929C: 80a22000                 cmp     %o0, 0
F00D92A0: 0280000b                 be      loc_F00D92CC
F00D92A4: 80a7200e                 cmp     %i4, 0xE
F00D92A8: 32800053                 bne,a   loc_F00D93F4
F00D92AC: a4103fd2                 mov     -0x2E, %l2
F00D92B0: 90102002                 mov     2, %o0
F00D92B4: d026c000                 st      %o0, [%i3]
F00D92B8: 901020c8                 mov     0xC8, %o0
F00D92BC: d0268000                 st      %o0, [%i2]
F00D92C0: 901020c9                 mov     0xC9, %o0
F00D92C4: 1080004c                 ba      loc_F00D93F4
F00D92C8: d026a004                 st      %o0, [%i2+4]
F00D92CC: 113c0505                 sethi   %hi(paOutputchannel), %o0! id
F00D92D0: d2022218                 ld      [%o0+%lo(paOutputchannel)], %o1! SEL
F00D92D4: 40006167                 call    _objc_msgSend
F00D92D8: 90100018                 mov     %i0, %o0
F00D92DC: 94100008                 mov     %o0, %o2
F00D92E0: 9010001d                 mov     %i5, %o0! id
F00D92E4: 40006163                 call    _objc_msgSend
F00D92E8: 92100010                 mov     %l0, %o1
F00D92EC: 912a2018                 sll     %o0, 24, %o0
F00D92F0: 80a22000                 cmp     %o0, 0
F00D92F4: 32800040                 bne,a   loc_F00D93F4
F00D92F8: a4102000                 mov     0, %l2
F00D92FC: 133c0504                 sethi   %hi(paClass), %o1
F00D9300: e0026014                 ld      [%o1+%lo(paClass)], %l0
F00D9304: 133c0504                 sethi   %hi(paIskindof), %o1! SEL
F00D9308: e2026040                 ld      [%o1+%lo(paIskindof)], %l1
F00D930C: 113c0506                 sethi   %hi(paInputstream), %o0
F00D9310: d00222dc                 ld      [%o0+%lo(paInputstream)], %o0! id
F00D9314: 40006157                 call    _objc_msgSend
F00D9318: 92100010                 mov     %l0, %o1! SEL
F00D931C: 94100008                 mov     %o0, %o2
F00D9320: 9010001d                 mov     %i5, %o0! id
F00D9324: 40006153                 call    _objc_msgSend
F00D9328: 92100011                 mov     %l1, %o1! SEL
F00D932C: 912a2018                 sll     %o0, 24, %o0
F00D9330: 80a22000                 cmp     %o0, 0
F00D9334: 0280000b                 be      loc_F00D9360
F00D9338: 80a72190                 cmp     %i4, 0x190
F00D933C: 0280001b                 be      loc_F00D93A8
F00D9340: 80a72195                 cmp     %i4, 0x195
F00D9344: 3280002c                 bne,a   loc_F00D93F4
F00D9348: a4102000                 mov     0, %l2
F00D934C: 90102001                 mov     1, %o0
F00D9350: d026c000                 st      %o0, [%i3]
F00D9354: 9010225d                 mov     0x25D, %o0
F00D9358: 10800027                 ba      loc_F00D93F4
F00D935C: d0268000                 st      %o0, [%i2]
F00D9360: 113c0506                 sethi   %hi(paOutputstream), %o0
F00D9364: d00222d8                 ld      [%o0+%lo(paOutputstream)], %o0! id
F00D9368: 40006142                 call    _objc_msgSend
F00D936C: 92100010                 mov     %l0, %o1! SEL
F00D9370: 94100008                 mov     %o0, %o2
F00D9374: 9010001d                 mov     %i5, %o0! id
F00D9378: 4000613e                 call    _objc_msgSend
F00D937C: 92100011                 mov     %l1, %o1
F00D9380: 912a2018                 sll     %o0, 24, %o0
F00D9384: 80a22000                 cmp     %o0, 0
F00D9388: 02800017                 be      loc_F00D93E4
F00D938C: 80a72190                 cmp     %i4, 0x190
F00D9390: 02800006                 be      loc_F00D93A8
F00D9394: 80a72196                 cmp     %i4, 0x196
F00D9398: 0280000f                 be      loc_F00D93D4
F00D939C: 90102001                 mov     1, %o0
F00D93A0: 10800015                 ba      loc_F00D93F4
F00D93A4: a4102000                 mov     0, %l2
F00D93A8: 90102004                 mov     4, %o0
F00D93AC: d026c000                 st      %o0, [%i3]
F00D93B0: 90102258                 mov     0x258, %o0
F00D93B4: d0268000                 st      %o0, [%i2]
F00D93B8: 90102259                 mov     0x259, %o0
F00D93BC: d026a004                 st      %o0, [%i2+4]
F00D93C0: 9010225a                 mov     0x25A, %o0
F00D93C4: d026a008                 st      %o0, [%i2+8]
F00D93C8: 9010225b                 mov     0x25B, %o0
F00D93CC: 1080000a                 ba      loc_F00D93F4
F00D93D0: d026a00c                 st      %o0, [%i2+0xC]
F00D93D4: d026c000                 st      %o0, [%i3]
F00D93D8: 9010225f                 mov     0x25F, %o0
F00D93DC: 10800006                 ba      loc_F00D93F4
F00D93E0: d0268000                 st      %o0, [%i2]
F00D93E4: 113c03f0                 sethi   %hi(aAudioUnknownPa), %o0! "Audio: unknown parameter object\n"
F00D93E8: 7fffb343                 call    _IOLog
F00D93EC: 901221e0                 bset    %lo(aAudioUnknownPa), %o0! "Audio: unknown parameter object\n"
F00D93F0: a4102000                 mov     0, %l2
F00D93F4: b12ca018                 sll     %l2, 24, %i0
F00D93F8: b13e2018                 sra     %i0, 24, %i0
F00D93FC: 81c7e008                 ret
F00D9400: 81e80000                 restore
