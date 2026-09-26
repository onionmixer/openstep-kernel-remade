F00DE2AC: 9de3bf98                 save    %sp, -0x68, %sp
F00DE2B0: 80a62000                 cmp     %i0, 0
F00DE2B4: 0280000f                 be      loc_F00DE2F0
F00DE2B8: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00DE2BC: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00DE2C0: 40004d6c                 call    _objc_msgSend
F00DE2C4: 90100018                 mov     %i0, %o0! id
F00DE2C8: 133c0505                 sethi   %hi(paIntvalueforpar), %o1
F00DE2CC: 94102002                 mov     2, %o2
F00DE2D0: d20260f8                 ld      [%o1+%lo(paIntvalueforpar)], %o1! SEL
F00DE2D4: 40004d67                 call    _objc_msgSend
F00DE2D8: 96100018                 mov     %i0, %o3
F00DE2DC: d0264000                 st      %o0, [%i1]
F00DE2E0: 90102001                 mov     1, %o0
F00DE2E4: d0268000                 st      %o0, [%i2]
F00DE2E8: 10800003                 ba      locret_F00DE2F4
F00DE2EC: b0102000                 mov     0, %i0
F00DE2F0: b01020ca                 mov     0xCA, %i0
F00DE2F4: 81c7e008                 ret
F00DE2F8: 81e80000                 restore
