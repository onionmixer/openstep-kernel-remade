F00903D4: 9de3bf98                 save    %sp, -0x68, %sp
F00903D8: 94100019                 mov     %i1, %o2
F00903DC: 9610001a                 mov     %i2, %o3
F00903E0: 80a62000                 cmp     %i0, 0
F00903E4: 02800009                 be      loc_F0090408
F00903E8: 9810001b                 mov     %i3, %o4
F00903EC: 113c0506                 sethi   %hi(paIodevice_0), %o0
F00903F0: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F00903F4: 133c0504                 sethi   %hi(paLookupbydevice), %o1! SEL
F00903F8: 4001851e                 call    _objc_msgSend
F00903FC: d2026144                 ld      [%o1+%lo(paLookupbydevice)], %o1
F0090400: 10800003                 ba      locret_F009040C
F0090404: b0100008                 mov     %o0, %i0
F0090408: b0103d3f                 mov     -0x2C1, %i0
F009040C: 81c7e008                 ret
F0090410: 81e80000                 restore
