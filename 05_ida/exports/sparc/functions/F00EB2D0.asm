F00EB2D0: 9de3bf90                 save    %sp, -0x70, %sp
F00EB2D4: 80a6a000                 cmp     %i2, 0
F00EB2D8: 2280002f                 be,a    locret_F00EB394
F00EB2DC: b0102000                 mov     0, %i0
F00EB2E0: d0062008                 ld      [%i0+8], %o0
F00EB2E4: 80a6c008                 cmp     %i3, %o0
F00EB2E8: 08800004                 bleu    loc_F00EB2F8
F00EB2EC: 90022001                 inc     %o0
F00EB2F0: 10800029                 ba      locret_F00EB394
F00EB2F4: b0102000                 mov     0, %i0
F00EB2F8: d206200c                 ld      [%i0+0xC], %o1! SEL
F00EB2FC: 80a20009                 cmp     %o0, %o1
F00EB300: 08800012                 bleu    loc_F00EB348
F00EB304: 90026001                 add     %o1, 1, %o0
F00EB308: 90020009                 add     %o0, %o1, %o0
F00EB30C: d026200c                 st      %o0, [%i0+0xC]
F00EB310: 213c0506                 sethi   %hi(paZone), %l0
F00EB314: 90100018                 mov     %i0, %o0! id
F00EB318: 40001956                 call    _objc_msgSend
F00EB31C: d2042254                 ld      [%l0+%lo(paZone)], %o1! SEL
F00EB320: a2100008                 mov     %o0, %l1
F00EB324: 90100018                 mov     %i0, %o0! id
F00EB328: 40001952                 call    _objc_msgSend
F00EB32C: d2042254                 ld      [%l0+%lo(paZone)], %o1
F00EB330: d406200c                 ld      [%i0+0xC], %o2
F00EB334: d6044000                 ld      [%l1], %o3
F00EB338: d2062004                 ld      [%i0+4], %o1
F00EB33C: 9fc2c000                 call    %o3
F00EB340: 952aa002                 sll     %o2, 2, %o2
F00EB344: d0262004                 st      %o0, [%i0+4]
F00EB348: d0062008                 ld      [%i0+8], %o0
F00EB34C: 912a2002                 sll     %o0, 2, %o0
F00EB350: d2062004                 ld      [%i0+4], %o1
F00EB354: 94020009                 add     %o0, %o1, %o2
F00EB358: 912ee002                 sll     %i3, 2, %o0
F00EB35C: 92020009                 add     %o0, %o1, %o1
F00EB360: 80a28009                 cmp     %o2, %o1
F00EB364: 08800008                 bleu    loc_F00EB384
F00EB368: 9602bffc                 add     %o2, -4, %o3
F00EB36C: d002c000                 ld      [%o3], %o0
F00EB370: d0228000                 st      %o0, [%o2]
F00EB374: 9402bffc                 inc     -4, %o2
F00EB378: 80a28009                 cmp     %o2, %o1
F00EB37C: 18bffffc                 bgu     loc_F00EB36C
F00EB380: 9602fffc                 inc     -4, %o3
F00EB384: f4224000                 st      %i2, [%o1]
F00EB388: d0062008                 ld      [%i0+8], %o0
F00EB38C: 90022001                 inc     %o0
F00EB390: d0262008                 st      %o0, [%i0+8]
F00EB394: 81c7e008                 ret
F00EB398: 81e80000                 restore
