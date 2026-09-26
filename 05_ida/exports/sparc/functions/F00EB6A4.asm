F00EB6A4: 9de3bf90                 save    %sp, -0x70, %sp
F00EB6A8: a0102000                 mov     0, %l0
F00EB6AC: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F00EB6B0: 9010001a                 mov     %i2, %o0! id
F00EB6B4: 4000186f                 call    _objc_msgSend
F00EB6B8: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F00EB6BC: a2100008                 mov     %o0, %l1
F00EB6C0: 80a40011                 cmp     %l0, %l1
F00EB6C4: 1a80000f                 bcc     locret_F00EB700
F00EB6C8: 273c0504                 sethi   -0xFEBF000, %l3
F00EB6CC: 253c0504                 sethi   -0xFEBF000, %l2
F00EB6D0: 9010001a                 mov     %i2, %o0! id
F00EB6D4: d204a0c8                 ld      [%l2+0xC8], %o1! SEL
F00EB6D8: 40001866                 call    _objc_msgSend
F00EB6DC: 94100010                 mov     %l0, %o2
F00EB6E0: 94100008                 mov     %o0, %o2
F00EB6E4: 90100018                 mov     %i0, %o0! id
F00EB6E8: 40001862                 call    _objc_msgSend
F00EB6EC: d204e0a4                 ld      [%l3+0xA4], %o1
F00EB6F0: a0042001                 inc     %l0
F00EB6F4: 80a40011                 cmp     %l0, %l1
F00EB6F8: 0abffff7                 bcs     loc_F00EB6D4
F00EB6FC: 9010001a                 mov     %i2, %o0
F00EB700: 81c7e008                 ret
F00EB704: 81e80000                 restore
