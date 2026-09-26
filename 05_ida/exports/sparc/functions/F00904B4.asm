F00904B4: 9de3bf98                 save    %sp, -0x68, %sp
F00904B8: 98100019                 mov     %i1, %o4
F00904BC: 9610001a                 mov     %i2, %o3
F00904C0: 9410001b                 mov     %i3, %o2
F00904C4: 80a62000                 cmp     %i0, 0
F00904C8: 02800009                 be      loc_F00904EC
F00904CC: 9a10001c                 mov     %i4, %o5
F00904D0: 113c0506                 sethi   %hi(paIodevice_0), %o0
F00904D4: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F00904D8: 133c0504                 sethi   %hi(paSetintvaluesFo), %o1! SEL
F00904DC: 400184e5                 call    _objc_msgSend
F00904E0: d2026150                 ld      [%o1+%lo(paSetintvaluesFo)], %o1
F00904E4: 10800003                 ba      locret_F00904F0
F00904E8: b0100008                 mov     %o0, %i0
F00904EC: b0103d3f                 mov     -0x2C1, %i0
F00904F0: 81c7e008                 ret
F00904F4: 81e80000                 restore
