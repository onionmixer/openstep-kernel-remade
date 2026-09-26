F00D829C: 9de3bf90                 save    %sp, -0x70, %sp
F00D82A0: 9210001a                 mov     %i2, %o1
F00D82A4: 94027fe2                 add     %o1, -0x1E, %o2
F00D82A8: 80a2a004                 cmp     %o2, 4! switch 5 cases
F00D82AC: 18800054                 bgu     def_F00D82C4! jumptable F00D82C4 default case
F00D82B0: 113c03f0                 sethi   -0xFF04000, %o0
F00D82B4: 113c0360901222cc         set     jpt_F00D82C4, %o0
F00D82BC: 932aa002                 sll     %o2, 2, %o1
F00D82C0: d0024008                 ld      [%o1+%o0], %o0
F00D82C4: 81c20000                 jmp     %o0! switch jump
F00D82C8: 01000000                 nop
F00D82E0: 90100018                 mov     %i0, %o0! jumptable F00D82C4 case 0
F00D82E4: d4022174                 ld      [%o0+0x174], %o2
F00D82E8: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D82EC: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D82F0: 40006560                 call    _objc_msgSend
F00D82F4: f62aa010                 stb     %i3, [%o2+0x10]
F00D82F8: 932ee018                 sll     %i3, 24, %o1
F00D82FC: 80a26000                 cmp     %o1, 0
F00D8300: 133c0506                 sethi   %hi(paSend), %o1
F00D8304: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00D8308: 0280003b                 be      loc_F00D83F4
F00D830C: 94102009                 mov     9, %o2
F00D8310: 10800039                 ba      loc_F00D83F4
F00D8314: 94102008                 mov     8, %o2
F00D8318: 90100018                 mov     %i0, %o0! jumptable F00D82C4 case 1
F00D831C: d4022174                 ld      [%o0+0x174], %o2
F00D8320: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D8324: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D8328: 40006552                 call    _objc_msgSend
F00D832C: f62aa011                 stb     %i3, [%o2+0x11]
F00D8330: 932ee018                 sll     %i3, 24, %o1
F00D8334: 80a26000                 cmp     %o1, 0
F00D8338: 133c0506                 sethi   %hi(paSend), %o1
F00D833C: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00D8340: 0280002d                 be      loc_F00D83F4
F00D8344: 9410200b                 mov     0xB, %o2
F00D8348: 1080002b                 ba      loc_F00D83F4
F00D834C: 9410200a                 mov     0xA, %o2
F00D8350: 90100018                 mov     %i0, %o0! jumptable F00D82C4 case 2
F00D8354: d4022174                 ld      [%o0+0x174], %o2
F00D8358: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D835C: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D8360: 40006544                 call    _objc_msgSend
F00D8364: f62aa012                 stb     %i3, [%o2+0x12]
F00D8368: 932ee018                 sll     %i3, 24, %o1
F00D836C: 80a26000                 cmp     %o1, 0
F00D8370: 133c0506                 sethi   %hi(paSend), %o1
F00D8374: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00D8378: 0280001f                 be      loc_F00D83F4
F00D837C: 9410200d                 mov     0xD, %o2
F00D8380: 1080001d                 ba      loc_F00D83F4
F00D8384: 9410200c                 mov     0xC, %o2
F00D8388: 90100018                 mov     %i0, %o0! jumptable F00D82C4 case 3
F00D838C: d4022174                 ld      [%o0+0x174], %o2
F00D8390: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D8394: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D8398: 40006536                 call    _objc_msgSend
F00D839C: f62aa013                 stb     %i3, [%o2+0x13]
F00D83A0: 932ee018                 sll     %i3, 24, %o1
F00D83A4: 80a26000                 cmp     %o1, 0
F00D83A8: 133c0506                 sethi   %hi(paSend), %o1
F00D83AC: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00D83B0: 02800011                 be      loc_F00D83F4
F00D83B4: 9410200f                 mov     0xF, %o2
F00D83B8: 1080000f                 ba      loc_F00D83F4
F00D83BC: 9410200e                 mov     0xE, %o2
F00D83C0: 90100018                 mov     %i0, %o0! jumptable F00D82C4 case 4
F00D83C4: d4022174                 ld      [%o0+0x174], %o2
F00D83C8: 133c0505                 sethi   %hi(paAudiocommand_0), %o1
F00D83CC: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1! SEL
F00D83D0: 40006528                 call    _objc_msgSend
F00D83D4: f62aa014                 stb     %i3, [%o2+0x14]
F00D83D8: 932ee018                 sll     %i3, 24, %o1
F00D83DC: 80a26000                 cmp     %o1, 0
F00D83E0: 133c0506                 sethi   %hi(paSend), %o1
F00D83E4: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00D83E8: 02800003                 be      loc_F00D83F4
F00D83EC: 94102011                 mov     0x11, %o2
F00D83F0: 94102010                 mov     0x10, %o2
F00D83F4: 4000651f                 call    _objc_msgSend
F00D83F8: 9e03e008                 inc     8, %o7
F00D83FC: 7fffb73e                 call    _IOLog! jumptable F00D82C4 default case
F00D8400: 90122190                 bset    0x190, %o0
F00D8404: 81c7e008                 ret
F00D8408: 81e80000                 restore
