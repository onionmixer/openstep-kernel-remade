F00AE27C: 9de3bf98                 save    %sp, -0x68, %sp
F00AE280: c026201c                 clr     [%i0+0x1C]
F00AE284: 80a66000                 cmp     %i1, 0
F00AE288: 12800005                 bne     loc_F00AE29C
F00AE28C: c0262020                 clr     [%i0+0x20]
F00AE290: c0260000                 clr     [%i0]
F00AE294: 10800013                 ba      locret_F00AE2E0
F00AE298: c0262004                 clr     [%i0+4]
F00AE29C: 9136601f                 srl     %i1, 31, %o0
F00AE2A0: d0260000                 st      %o0, [%i0]
F00AE2A4: 90102001                 mov     1, %o0
F00AE2A8: d0262004                 st      %o0, [%i0+4]
F00AE2AC: 9010201f                 mov     0x1F, %o0
F00AE2B0: 80a66000                 cmp     %i1, 0
F00AE2B4: 16800003                 bge     loc_F00AE2C0
F00AE2B8: d0262008                 st      %o0, [%i0+8]
F00AE2BC: b2200019                 neg     %i1
F00AE2C0: 9136600f                 srl     %i1, 15, %o0
F00AE2C4: d026200c                 st      %o0, [%i0+0xC]
F00AE2C8: 912e6011                 sll     %i1, 17, %o0
F00AE2CC: d0262010                 st      %o0, [%i0+0x10]
F00AE2D0: c0262014                 clr     [%i0+0x14]
F00AE2D4: c0262018                 clr     [%i0+0x18]
F00AE2D8: 40000140                 call    _fpu_normalize
F00AE2DC: 90100018                 mov     %i0, %o0
F00AE2E0: 81c7e008                 ret
F00AE2E4: 81e80000                 restore
