F0090394: 9de3bf98                 save    %sp, -0x68, %sp
F0090398: 94100019                 mov     %i1, %o2
F009039C: 9610001a                 mov     %i2, %o3
F00903A0: 80a62000                 cmp     %i0, 0
F00903A4: 02800009                 be      loc_F00903C8
F00903A8: 9810001b                 mov     %i3, %o4
F00903AC: 113c0506                 sethi   %hi(paIodevice_0), %o0
F00903B0: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F00903B4: 133c0504                 sethi   %hi(paLookupbyobject_0), %o1! SEL
F00903B8: 4001852e                 call    _objc_msgSend
F00903BC: d2026140                 ld      [%o1+%lo(paLookupbyobject_0)], %o1
F00903C0: 10800003                 ba      locret_F00903CC
F00903C4: b0100008                 mov     %o0, %i0
F00903C8: b0103d3f                 mov     -0x2C1, %i0
F00903CC: 81c7e008                 ret
F00903D0: 81e80000                 restore
