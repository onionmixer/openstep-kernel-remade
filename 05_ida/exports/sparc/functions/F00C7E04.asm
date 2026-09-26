F00C7E04: 9de3bf90                 save    %sp, -0x70, %sp
F00C7E08: 90100018                 mov     %i0, %o0! id
F00C7E0C: 133c0506                 sethi   %hi(paPhysicaldisk_0), %o1
F00C7E10: d2026164                 ld      [%o1+%lo(paPhysicaldisk_0)], %o1! SEL
F00C7E14: 4000a697                 call    _objc_msgSend
F00C7E18: a2100018                 mov     %i0, %l1
F00C7E1C: d20461a4                 ld      [%l1+0x1A4], %o1
F00C7E20: 80a26000                 cmp     %o1, 0
F00C7E24: 0280000c                 be      loc_F00C7E54
F00C7E28: aa100008                 mov     %o0, %l5
F00C7E2C: 90100011                 mov     %l1, %o0! id
F00C7E30: 133c0504                 sethi   %hi(paName), %o1
F00C7E34: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C7E38: 213c03eb                 sethi   %hi(aSProbelabelOnP), %l0! "%s:  _probeLabel on partition != 0\n"
F00C7E3C: 4000a68d                 call    _objc_msgSend
F00C7E40: a0142248                 bset    %lo(aSProbelabelOnP), %l0! "%s:  _probeLabel on partition != 0\n"
F00C7E44: 92100008                 mov     %o0, %o1
F00C7E48: 7ffff8ab                 call    _IOLog
F00C7E4C: 90100010                 mov     %l0, %o0
F00C7E50: 30800037                 ba,a    locret_F00C7F2C
F00C7E54: 90100011                 mov     %l1, %o0! id
F00C7E58: 94102000                 mov     0, %o2
F00C7E5C: 9606a02c                 add     %i2, 0x2C, %o3 ! ','
F00C7E60: a4102001                 mov     1, %l2
F00C7E64: 133c0506                 sethi   %hi(paInitpartitionD), %o1
F00C7E68: d202613c                 ld      [%o1+%lo(paInitpartitionD)], %o1! SEL
F00C7E6C: 4000a681                 call    _objc_msgSend
F00C7E70: a61020f0                 mov     0xF0, %l3
F00C7E74: 113c0506                 sethi   %hi(paSetlogicaldisk), %o0
F00C7E78: e80221a4                 ld      [%o0+%lo(paSetlogicaldisk)], %l4
F00C7E7C: 90068013                 add     %i2, %l3, %o0
F00C7E80: d0022004                 ld      [%o0+4], %o0
F00C7E84: 80a22000                 cmp     %o0, 0
F00C7E88: 04800025                 ble     loc_F00C7F1C
F00C7E8C: 113c0506                 sethi   %hi(paIodiskpartitio_1), %o0
F00C7E90: d00222f4                 ld      [%o0+%lo(paIodiskpartitio_1)], %o0! id
F00C7E94: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00C7E98: 4000a676                 call    _objc_msgSend
F00C7E9C: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00C7EA0: a0100008                 mov     %o0, %l0
F00C7EA4: 133c0506                 sethi   %hi(paConnecttophysi), %o1
F00C7EA8: d2026188                 ld      [%o1+%lo(paConnecttophysi)], %o1! SEL
F00C7EAC: 4000a671                 call    _objc_msgSend
F00C7EB0: 94100015                 mov     %l5, %o2
F00C7EB4: 90100010                 mov     %l0, %o0! id
F00C7EB8: 94100012                 mov     %l2, %o2
F00C7EBC: 133c0506                 sethi   %hi(paInitpartitionD), %o1
F00C7EC0: d202613c                 ld      [%o1+%lo(paInitpartitionD)], %o1! SEL
F00C7EC4: 4000a66b                 call    _objc_msgSend
F00C7EC8: 9606a02c                 add     %i2, 0x2C, %o3 ! ','
F00C7ECC: 113c0504                 sethi   %hi(paInit), %o0! id
F00C7ED0: d202202c                 ld      [%o0+%lo(paInit)], %o1! SEL
F00C7ED4: 4000a667                 call    _objc_msgSend
F00C7ED8: 90100010                 mov     %l0, %o0
F00C7EDC: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00C7EE0: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00C7EE4: 4000a663                 call    _objc_msgSend
F00C7EE8: 90100010                 mov     %l0, %o0
F00C7EEC: 90100011                 mov     %l1, %o0! id
F00C7EF0: 92100014                 mov     %l4, %o1! SEL
F00C7EF4: 4000a65f                 call    _objc_msgSend
F00C7EF8: 94100010                 mov     %l0, %o2
F00C7EFC: 90100018                 mov     %i0, %o0! id
F00C7F00: 133c0506                 sethi   %hi(paPhysicaldisk_0), %o1
F00C7F04: d2026164                 ld      [%o1+%lo(paPhysicaldisk_0)], %o1! SEL
F00C7F08: 4000a65a                 call    _objc_msgSend
F00C7F0C: a2100010                 mov     %l0, %l1
F00C7F10: 92100014                 mov     %l4, %o1! SEL
F00C7F14: 4000a657                 call    _objc_msgSend
F00C7F18: 94100011                 mov     %l1, %o2
F00C7F1C: a404a001                 inc     %l2
F00C7F20: 80a4a006                 cmp     %l2, 6
F00C7F24: 04bfffd6                 ble     loc_F00C7E7C
F00C7F28: a604e030                 inc     0x30, %l3 ! '0'
F00C7F2C: 81c7e008                 ret
F00C7F30: 81e80000                 restore
