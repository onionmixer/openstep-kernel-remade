F00C1AF0: 9de3bf90                 save    %sp, -0x70, %sp
F00C1AF4: 113c0503                 sethi   %hi(paAlloc), %o0! id
F00C1AF8: d20223f0                 ld      [%o0+%lo(paAlloc)], %o1! SEL
F00C1AFC: 4000bf5d                 call    _objc_msgSend
F00C1B00: 90100018                 mov     %i0, %o0! id
F00C1B04: 133c0504                 sethi   %hi(paInitfromdevice), %o1
F00C1B08: d20262fc                 ld      [%o1+%lo(paInitfromdevice)], %o1! SEL
F00C1B0C: 4000bf59                 call    _objc_msgSend
F00C1B10: 9410001a                 mov     %i2, %o2
F00C1B14: b0100008                 mov     %o0, %i0
F00C1B18: 133c0504                 sethi   %hi(paSetunit), %o1
F00C1B1C: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00C1B20: 4000bf54                 call    _objc_msgSend
F00C1B24: 94102000                 mov     0, %o2
F00C1B28: 90100018                 mov     %i0, %o0! id
F00C1B2C: 133c0504                 sethi   %hi(paSetname), %o1
F00C1B30: 153c0484                 sethi   %hi(aType5keyboard0_1), %o2! "TYPE5Keyboard0"
F00C1B34: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00C1B38: 4000bf4e                 call    _objc_msgSend
F00C1B3C: 9412a030                 bset    %lo(aType5keyboard0_1), %o2! "TYPE5Keyboard0"
F00C1B40: 90100018                 mov     %i0, %o0! id
F00C1B44: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00C1B48: 153c0484                 sethi   %hi(aType5keyboard_1), %o2! "TYPE5Keyboard"
F00C1B4C: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00C1B50: 4000bf48                 call    _objc_msgSend
F00C1B54: 9412a040                 bset    %lo(aType5keyboard_1), %o2! "TYPE5Keyboard"
F00C1B58: 90100018                 mov     %i0, %o0! id
F00C1B5C: 133c0504                 sethi   %hi(paKbdinit), %o1
F00C1B60: d2026318                 ld      [%o1+%lo(paKbdinit)], %o1! SEL
F00C1B64: 4000bf43                 call    _objc_msgSend
F00C1B68: 9410001a                 mov     %i2, %o2
F00C1B6C: 912a2018                 sll     %o0, 24, %o0
F00C1B70: 80a22000                 cmp     %o0, 0
F00C1B74: 0280000a                 be      loc_F00C1B9C
F00C1B78: 113c0484                 sethi   -0xFEDF000, %o0
F00C1B7C: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00C1B80: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00C1B84: 4000bf3b                 call    _objc_msgSend
F00C1B88: 90100018                 mov     %i0, %o0
F00C1B8C: 113c04cb                 sethi   %hi(dword_F0132F98), %o0
F00C1B90: f0222398                 st      %i0, [%o0+%lo(dword_F0132F98)]
F00C1B94: 10800009                 ba      locret_F00C1BB8
F00C1B98: b0102001                 mov     1, %i0
F00C1B9C: 40001156                 call    _IOLog
F00C1BA0: 90122050                 bset    0x50, %o0 ! 'P'
F00C1BA4: 113c0503                 sethi   %hi(paFree), %o0! id
F00C1BA8: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00C1BAC: 4000bf31                 call    _objc_msgSend
F00C1BB0: 90100018                 mov     %i0, %o0
F00C1BB4: b0102000                 mov     0, %i0
F00C1BB8: 81c7e008                 ret
F00C1BBC: 81e80000                 restore
