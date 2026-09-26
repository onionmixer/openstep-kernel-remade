F00904F8: 9de3bf98                 save    %sp, -0x68, %sp
F00904FC: 98100019                 mov     %i1, %o4
F0090500: 9610001a                 mov     %i2, %o3
F0090504: 9410001b                 mov     %i3, %o2
F0090508: 80a62000                 cmp     %i0, 0
F009050C: 02800009                 be      loc_F0090530
F0090510: 9a10001c                 mov     %i4, %o5
F0090514: 113c0506                 sethi   %hi(paIodevice_0), %o0
F0090518: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F009051C: 133c0504                 sethi   %hi(paSetcharvaluesF), %o1! SEL
F0090520: 400184d4                 call    _objc_msgSend
F0090524: d2026154                 ld      [%o1+%lo(paSetcharvaluesF)], %o1
F0090528: 10800003                 ba      locret_F0090534
F009052C: b0100008                 mov     %o0, %i0
F0090530: b0103d3f                 mov     -0x2C1, %i0
F0090534: 81c7e008                 ret
F0090538: 81e80000                 restore
