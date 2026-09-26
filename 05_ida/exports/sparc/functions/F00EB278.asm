F00EB278: 9de3bf90                 save    %sp, -0x70, %sp
F00EB27C: d0062008                 ld      [%i0+8], %o0
F00EB280: 80a68008                 cmp     %i2, %o0
F00EB284: 0a800010                 bcs     loc_F00EB2C4
F00EB288: 213c0506                 sethi   %hi(paZone), %l0
F00EB28C: 90100018                 mov     %i0, %o0! id
F00EB290: 40001978                 call    _objc_msgSend
F00EB294: d2042254                 ld      [%l0+%lo(paZone)], %o1! SEL
F00EB298: a2100008                 mov     %o0, %l1
F00EB29C: 90100018                 mov     %i0, %o0! id
F00EB2A0: 40001974                 call    _objc_msgSend
F00EB2A4: d2042254                 ld      [%l0+%lo(paZone)], %o1
F00EB2A8: d6044000                 ld      [%l1], %o3
F00EB2AC: d2062004                 ld      [%i0+4], %o1
F00EB2B0: 9fc2c000                 call    %o3
F00EB2B4: 952ea002                 sll     %i2, 2, %o2
F00EB2B8: d0262004                 st      %o0, [%i0+4]
F00EB2BC: 10800003                 ba      locret_F00EB2C8
F00EB2C0: f426200c                 st      %i2, [%i0+0xC]
F00EB2C4: b0102000                 mov     0, %i0
F00EB2C8: 81c7e008                 ret
F00EB2CC: 81e80000                 restore
