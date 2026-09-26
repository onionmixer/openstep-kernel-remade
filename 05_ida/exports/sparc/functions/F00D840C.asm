F00D840C: 9de3bf90                 save    %sp, -0x70, %sp
F00D8410: 9210001a                 mov     %i2, %o1
F00D8414: 94027fe7                 add     %o1, -0x19, %o2
F00D8418: 80a2a004                 cmp     %o2, 4! switch 5 cases
F00D841C: 18800054                 bgu     def_F00D8434! jumptable F00D8434 default case
F00D8420: 113c03f0                 sethi   -0xFF04000, %o0
F00D8424: 113c03619012203c         set     jpt_F00D8434, %o0
F00D842C: 932aa002                 sll     %o2, 2, %o1
F00D8430: d0024008                 ld      [%o1+%o0], %o0
F00D8434: 81c20000                 jmp     %o0! switch jump
F00D8438: 01000000                 nop
F00D8450: 90100018                 mov     %i0, %o0! jumptable F00D8434 case 1
F00D8454: d4022174                 ld      [%o0+0x174], %o2
F00D8458: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D845C: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D8460: 40006504                 call    _objc_msgSend
F00D8464: f62aa015                 stb     %i3, [%o2+0x15]
F00D8468: 932ee018                 sll     %i3, 24, %o1
F00D846C: 80a26000                 cmp     %o1, 0
F00D8470: 133c0506                 sethi   %hi(paSend), %o1
F00D8474: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00D8478: 0280003b                 be      loc_F00D8564
F00D847C: 94102015                 mov     0x15, %o2
F00D8480: 10800039                 ba      loc_F00D8564
F00D8484: 94102014                 mov     0x14, %o2
F00D8488: 90100018                 mov     %i0, %o0! jumptable F00D8434 case 0
F00D848C: d4022174                 ld      [%o0+0x174], %o2
F00D8490: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D8494: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D8498: 400064f6                 call    _objc_msgSend
F00D849C: f62aa016                 stb     %i3, [%o2+0x16]
F00D84A0: 932ee018                 sll     %i3, 24, %o1
F00D84A4: 80a26000                 cmp     %o1, 0
F00D84A8: 133c0506                 sethi   %hi(paSend), %o1
F00D84AC: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00D84B0: 0280002d                 be      loc_F00D8564
F00D84B4: 94102013                 mov     0x13, %o2
F00D84B8: 1080002b                 ba      loc_F00D8564
F00D84BC: 94102012                 mov     0x12, %o2
F00D84C0: 90100018                 mov     %i0, %o0! jumptable F00D8434 case 2
F00D84C4: d4022174                 ld      [%o0+0x174], %o2
F00D84C8: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D84CC: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D84D0: 400064e8                 call    _objc_msgSend
F00D84D4: f62aa017                 stb     %i3, [%o2+0x17]
F00D84D8: 932ee018                 sll     %i3, 24, %o1
F00D84DC: 80a26000                 cmp     %o1, 0
F00D84E0: 133c0506                 sethi   %hi(paSend), %o1
F00D84E4: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00D84E8: 0280001f                 be      loc_F00D8564
F00D84EC: 94102017                 mov     0x17, %o2
F00D84F0: 1080001d                 ba      loc_F00D8564
F00D84F4: 94102016                 mov     0x16, %o2
F00D84F8: 90100018                 mov     %i0, %o0! jumptable F00D8434 case 3
F00D84FC: d4022174                 ld      [%o0+0x174], %o2
F00D8500: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D8504: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D8508: 400064da                 call    _objc_msgSend
F00D850C: f62aa018                 stb     %i3, [%o2+0x18]
F00D8510: 932ee018                 sll     %i3, 24, %o1
F00D8514: 80a26000                 cmp     %o1, 0
F00D8518: 133c0506                 sethi   %hi(paSend), %o1
F00D851C: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00D8520: 02800011                 be      loc_F00D8564
F00D8524: 94102019                 mov     0x19, %o2
F00D8528: 1080000f                 ba      loc_F00D8564
F00D852C: 94102018                 mov     0x18, %o2
F00D8530: 90100018                 mov     %i0, %o0! jumptable F00D8434 case 4
F00D8534: d4022174                 ld      [%o0+0x174], %o2
F00D8538: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D853C: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D8540: 400064cc                 call    _objc_msgSend
F00D8544: f62aa019                 stb     %i3, [%o2+0x19]
F00D8548: 932ee018                 sll     %i3, 24, %o1
F00D854C: 80a26000                 cmp     %o1, 0
F00D8550: 133c0506                 sethi   %hi(paSend), %o1
F00D8554: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00D8558: 02800003                 be      loc_F00D8564
F00D855C: 9410201b                 mov     0x1B, %o2
F00D8560: 9410201a                 mov     0x1A, %o2
F00D8564: 400064c3                 call    _objc_msgSend
F00D8568: 9e03e008                 inc     8, %o7
F00D856C: 7fffb6e2                 call    _IOLog! jumptable F00D8434 default case
F00D8570: 901221b8                 bset    0x1B8, %o0
F00D8574: 81c7e008                 ret
F00D8578: 81e80000                 restore
