F00D02BC: 9de3bf90                 save    %sp, -0x70, %sp
F00D02C0: 113c0506                 sethi   %hi(paDirectdevice), %o0! id
F00D02C4: d2022190                 ld      [%o0+%lo(paDirectdevice)], %o1! SEL
F00D02C8: 4000856a                 call    _objc_msgSend
F00D02CC: 9010001a                 mov     %i2, %o0! id
F00D02D0: 133c0506                 sethi   %hi(paUnit_0), %o1! SEL
F00D02D4: a2100008                 mov     %o0, %l1
F00D02D8: 40008566                 call    _objc_msgSend
F00D02DC: d2026138                 ld      [%o1+%lo(paUnit_0)], %o1
F00D02E0: 80a22000                 cmp     %o0, 0
F00D02E4: 02800004                 be      loc_F00D02F4
F00D02E8: b4102000                 mov     0, %i2
F00D02EC: 10800015                 ba      locret_F00D0340
F00D02F0: b0102000                 mov     0, %i0
F00D02F4: 293c0503                 sethi   %hi(paAlloc), %l4
F00D02F8: 113c04f6a61221c0         set     _sgIdMap, %l3
F00D0300: 253c0505                 sethi   -0xFEBEC00, %l2
F00D0304: a0102000                 mov     0, %l0
F00D0308: d20523f0                 ld      [%l4+%lo(paAlloc)], %o1! SEL
F00D030C: 40008559                 call    _objc_msgSend
F00D0310: 90100018                 mov     %i0, %o0! id
F00D0314: d0240013                 st      %o0, [%l0+%l3]
F00D0318: a0042004                 inc     4, %l0
F00D031C: 9410001a                 mov     %i2, %o2
F00D0320: b406a001                 inc     %i2
F00D0324: d204a36c                 ld      [%l2+0x36C], %o1! SEL
F00D0328: 40008552                 call    _objc_msgSend
F00D032C: 96100011                 mov     %l1, %o3
F00D0330: 80a6a003                 cmp     %i2, 3
F00D0334: 04bffff6                 ble     loc_F00D030C
F00D0338: d20523f0                 ld      [%l4+0x3F0], %o1
F00D033C: b0102001                 mov     1, %i0
F00D0340: 81c7e008                 ret
F00D0344: 81e80000                 restore
