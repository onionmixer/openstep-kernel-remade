F00D7E6C: 9de3bf90                 save    %sp, -0x70, %sp
F00D7E70: 113c0505                 sethi   %hi(paLocalchannel), %o0
F00D7E74: d20221a8                 ld      [%o0+%lo(paLocalchannel)], %o1! SEL
F00D7E78: 113c0505                 sethi   %hi(paStopdmaforchan), %o0! id
F00D7E7C: e4022184                 ld      [%o0+%lo(paStopdmaforchan)], %l2
F00D7E80: 4000667c                 call    _objc_msgSend
F00D7E84: 9010001a                 mov     %i2, %o0
F00D7E88: a0100008                 mov     %o0, %l0
F00D7E8C: 113c0505                 sethi   %hi(paIsread), %o0
F00D7E90: e2022214                 ld      [%o0+%lo(paIsread)], %l1
F00D7E94: 9010001a                 mov     %i2, %o0! id
F00D7E98: 40006676                 call    _objc_msgSend
F00D7E9C: 92100011                 mov     %l1, %o1
F00D7EA0: 972a2018                 sll     %o0, 24, %o3
F00D7EA4: 90100018                 mov     %i0, %o0! id
F00D7EA8: 92100012                 mov     %l2, %o1! SEL
F00D7EAC: 94100010                 mov     %l0, %o2
F00D7EB0: 40006670                 call    _objc_msgSend
F00D7EB4: 973ae018                 sra     %o3, 24, %o3
F00D7EB8: 113c0505                 sethi   %hi(paFreedescriptor), %o0! id
F00D7EBC: d2022180                 ld      [%o0+%lo(paFreedescriptor)], %o1! SEL
F00D7EC0: 4000666c                 call    _objc_msgSend
F00D7EC4: 9010001a                 mov     %i2, %o0
F00D7EC8: 9010001a                 mov     %i2, %o0! id
F00D7ECC: 40006669                 call    _objc_msgSend
F00D7ED0: 92100011                 mov     %l1, %o1
F00D7ED4: 912a2018                 sll     %o0, 24, %o0
F00D7ED8: 80a22000                 cmp     %o0, 0
F00D7EDC: 02800005                 be      loc_F00D7EF0
F00D7EE0: 133c0505                 sethi   %hi(paSetinputactive), %o1
F00D7EE4: 90100018                 mov     %i0, %o0
F00D7EE8: 10800005                 ba      loc_F00D7EFC
F00D7EEC: d2026198                 ld      [%o1+%lo(paSetinputactive)], %o1
F00D7EF0: 90100018                 mov     %i0, %o0! id
F00D7EF4: 133c0505                 sethi   %hi(paSetoutputactiv), %o1
F00D7EF8: d2026194                 ld      [%o1+%lo(paSetoutputactiv)], %o1! SEL
F00D7EFC: 4000665d                 call    _objc_msgSend
F00D7F00: 94102000                 mov     0, %o2
F00D7F04: 113c0505                 sethi   %hi(paIsinputactive_0), %o0! id
F00D7F08: d2022210                 ld      [%o0+%lo(paIsinputactive_0)], %o1! SEL
F00D7F0C: 40006659                 call    _objc_msgSend
F00D7F10: 90100018                 mov     %i0, %o0
F00D7F14: 912a2018                 sll     %o0, 24, %o0
F00D7F18: 80a22000                 cmp     %o0, 0
F00D7F1C: 1280000d                 bne     locret_F00D7F50
F00D7F20: 113c0505                 sethi   %hi(paIsoutputactive_0), %o0! id
F00D7F24: d202220c                 ld      [%o0+%lo(paIsoutputactive_0)], %o1! SEL
F00D7F28: 40006652                 call    _objc_msgSend
F00D7F2C: 90100018                 mov     %i0, %o0
F00D7F30: 912a2018                 sll     %o0, 24, %o0
F00D7F34: 80a22000                 cmp     %o0, 0
F00D7F38: 12800006                 bne     locret_F00D7F50
F00D7F3C: 90100018                 mov     %i0, %o0! id
F00D7F40: 133c0505                 sethi   %hi(paSettimeout), %o1
F00D7F44: d202618c                 ld      [%o1+%lo(paSettimeout)], %o1! SEL
F00D7F48: 4000664a                 call    _objc_msgSend
F00D7F4C: 94103fff                 mov     -1, %o2
F00D7F50: 81c7e008                 ret
F00D7F54: 81e80000                 restore
