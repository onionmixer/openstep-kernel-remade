F00D90FC: 9de3bf90                 save    %sp, -0x70, %sp
F00D9100: 113c0505                 sethi   %hi(paInputchannel), %o0
F00D9104: d2022220                 ld      [%o0+%lo(paInputchannel)], %o1! SEL
F00D9108: a2102000                 mov     0, %l1
F00D910C: 113c0505                 sethi   %hi(paIsequal), %o0! id
F00D9110: e0022150                 ld      [%o0+%lo(paIsequal)], %l0
F00D9114: c026c000                 clr     [%i3]
F00D9118: 400061d6                 call    _objc_msgSend
F00D911C: 90100018                 mov     %i0, %o0
F00D9120: 94100008                 mov     %o0, %o2
F00D9124: 9010001c                 mov     %i4, %o0! id
F00D9128: 400061d2                 call    _objc_msgSend
F00D912C: 92100010                 mov     %l0, %o1
F00D9130: 912a2018                 sll     %o0, 24, %o0
F00D9134: 80a22000                 cmp     %o0, 0
F00D9138: 02800007                 be      loc_F00D9154
F00D913C: 113c0505                 sethi   -0xFEBEC00, %o0
F00D9140: 113c03e5a2122308         set     unk_F00F9708, %l1
F00D9148: 90102007                 mov     7, %o0! id
F00D914C: 10800038                 ba      loc_F00D922C
F00D9150: d026c000                 st      %o0, [%i3]
F00D9154: d2022218                 ld      [%o0+0x218], %o1! SEL
F00D9158: 400061c6                 call    _objc_msgSend
F00D915C: 90100018                 mov     %i0, %o0
F00D9160: 94100008                 mov     %o0, %o2
F00D9164: 9010001c                 mov     %i4, %o0! id
F00D9168: 400061c2                 call    _objc_msgSend
F00D916C: 92100010                 mov     %l0, %o1
F00D9170: 912a2018                 sll     %o0, 24, %o0
F00D9174: 80a22000                 cmp     %o0, 0
F00D9178: 02800006                 be      loc_F00D9190
F00D917C: 113c03e5                 sethi   %hi(unk_F00F96D0), %o0
F00D9180: a21222d0                 or      %o0, %lo(unk_F00F96D0), %l1
F00D9184: 9010200e                 mov     0xE, %o0
F00D9188: 10800029                 ba      loc_F00D922C
F00D918C: d026c000                 st      %o0, [%i3]
F00D9190: 133c0504                 sethi   %hi(paClass), %o1
F00D9194: f0026014                 ld      [%o1+%lo(paClass)], %i0
F00D9198: 133c0504                 sethi   %hi(paIskindof), %o1! SEL
F00D919C: e0026040                 ld      [%o1+%lo(paIskindof)], %l0
F00D91A0: 113c0506                 sethi   %hi(paInputstream), %o0
F00D91A4: d00222dc                 ld      [%o0+%lo(paInputstream)], %o0! id
F00D91A8: 400061b2                 call    _objc_msgSend
F00D91AC: 92100018                 mov     %i0, %o1! SEL
F00D91B0: 94100008                 mov     %o0, %o2
F00D91B4: 9010001c                 mov     %i4, %o0! id
F00D91B8: 400061ae                 call    _objc_msgSend
F00D91BC: 92100010                 mov     %l0, %o1! SEL
F00D91C0: 912a2018                 sll     %o0, 24, %o0
F00D91C4: 80a22000                 cmp     %o0, 0
F00D91C8: 02800006                 be      loc_F00D91E0
F00D91CC: 113c03e5                 sethi   %hi(unk_F00F974C), %o0
F00D91D0: a212234c                 or      %o0, %lo(unk_F00F974C), %l1
F00D91D4: 90102006                 mov     6, %o0
F00D91D8: 10800015                 ba      loc_F00D922C
F00D91DC: d026c000                 st      %o0, [%i3]
F00D91E0: 113c0506                 sethi   %hi(paOutputstream), %o0
F00D91E4: d00222d8                 ld      [%o0+%lo(paOutputstream)], %o0! id
F00D91E8: 400061a2                 call    _objc_msgSend
F00D91EC: 92100018                 mov     %i0, %o1! SEL
F00D91F0: 94100008                 mov     %o0, %o2
F00D91F4: 9010001c                 mov     %i4, %o0! id
F00D91F8: 4000619e                 call    _objc_msgSend
F00D91FC: 92100010                 mov     %l0, %o1
F00D9200: 912a2018                 sll     %o0, 24, %o0
F00D9204: 80a22000                 cmp     %o0, 0
F00D9208: 02800007                 be      loc_F00D9224
F00D920C: 113c03f0                 sethi   -0xFF04000, %o0
F00D9210: 113c03e5a2122324         set     unk_F00F9724, %l1
F00D9218: 9010200a                 mov     0xA, %o0
F00D921C: 10800004                 ba      loc_F00D922C
F00D9220: d026c000                 st      %o0, [%i3]
F00D9224: 7fffb3b4                 call    _IOLog
F00D9228: 901221e0                 bset    0x1E0, %o0
F00D922C: d006c000                 ld      [%i3], %o0
F00D9230: 94102000                 mov     0, %o2
F00D9234: 80a28008                 cmp     %o2, %o0
F00D9238: 1a800009                 bcc     locret_F00D925C
F00D923C: 92102000                 mov     0, %o1
F00D9240: d0024011                 ld      [%o1+%l1], %o0
F00D9244: 9402a001                 inc     %o2
F00D9248: d022401a                 st      %o0, [%o1+%i2]
F00D924C: d006c000                 ld      [%i3], %o0
F00D9250: 80a28008                 cmp     %o2, %o0
F00D9254: 0abffffb                 bcs     loc_F00D9240
F00D9258: 92026004                 inc     4, %o1
F00D925C: 81c7e008                 ret
F00D9260: 81e80000                 restore
