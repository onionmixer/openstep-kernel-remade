F00D9F48: 9de3bf90                 save    %sp, -0x70, %sp
F00D9F4C: f027bff0                 st      %i0, [%fp+var_10]
F00D9F50: 133c0508                 sethi   %hi(stru_F014227C.super_class), %o1
F00D9F54: d4026280                 ld      [%o1+%lo(stru_F014227C.super_class)], %o2
F00D9F58: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D9F5C: 133c0504                 sethi   %hi(paInit), %o1
F00D9F60: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00D9F64: 40005e86                 call    _objc_msgSendSuper
F00D9F68: d427bff4                 st      %o2, [%fp+var_C]
F00D9F6C: f4262004                 st      %i2, [%i0+4]
F00D9F70: b410001b                 mov     %i3, %i2
F00D9F74: b72ee018                 sll     %i3, 24, %i3
F00D9F78: 80a6e000                 cmp     %i3, 0
F00D9F7C: 02800005                 be      loc_F00D9F90
F00D9F80: f42e2020                 stb     %i2, [%i0+0x20]
F00D9F84: 113c0506                 sethi   %hi(paInputstream), %o0
F00D9F88: 10800004                 ba      loc_F00D9F98
F00D9F8C: d00222dc                 ld      [%o0+%lo(paInputstream)], %o0
F00D9F90: 113c0506                 sethi   %hi(paOutputstream), %o0
F00D9F94: d00222d8                 ld      [%o0+%lo(paOutputstream)], %o0! id
F00D9F98: 133c0504                 sethi   %hi(paClass), %o1! SEL
F00D9F9C: 40005e35                 call    _objc_msgSend
F00D9FA0: d2026014                 ld      [%o1+%lo(paClass)], %o1! SEL
F00D9FA4: d0262008                 st      %o0, [%i0+8]
F00D9FA8: 113c0503                 sethi   %hi(paAlloc), %o0
F00D9FAC: e20223f0                 ld      [%o0+%lo(paAlloc)], %l1
F00D9FB0: c0262014                 clr     [%i0+0x14]
F00D9FB4: 113c0506                 sethi   %hi(paList), %o0
F00D9FB8: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F00D9FBC: 40005e2d                 call    _objc_msgSend
F00D9FC0: 92100011                 mov     %l1, %o1
F00D9FC4: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00D9FC8: e002602c                 ld      [%o1+%lo(paInit)], %l0
F00D9FCC: 40005e29                 call    _objc_msgSend
F00D9FD0: 92100010                 mov     %l0, %o1! SEL
F00D9FD4: d026200c                 st      %o0, [%i0+0xC]
F00D9FD8: 113c0506                 sethi   %hi(paNxlock), %o0
F00D9FDC: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00D9FE0: 40005e24                 call    _objc_msgSend
F00D9FE4: 92100011                 mov     %l1, %o1! SEL
F00D9FE8: 40005e22                 call    _objc_msgSend
F00D9FEC: 92100010                 mov     %l0, %o1
F00D9FF0: d0262010                 st      %o0, [%i0+0x10]
F00D9FF4: 90062024                 add     %i0, 0x24, %o0 ! '$'
F00D9FF8: d0262028                 st      %o0, [%i0+0x28]
F00D9FFC: d0262024                 st      %o0, [%i0+0x24]
F00DA000: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F00DA004: d0262030                 st      %o0, [%i0+0x30]
F00DA008: d026202c                 st      %o0, [%i0+0x2C]
F00DA00C: 90102001                 mov     1, %o0
F00DA010: d0262054                 st      %o0, [%i0+0x54]
F00DA014: 912ea018                 sll     %i2, 24, %o0
F00DA018: 80a22000                 cmp     %o0, 0
F00DA01C: 02800007                 be      loc_F00DA038
F00DA020: c026204c                 clr     [%i0+0x4C]
F00DA024: 113c04bb                 sethi   %hi(_AudioIn_dmaSize), %o0
F00DA028: d2022314                 ld      [%o0+%lo(_AudioIn_dmaSize)], %o1
F00DA02C: 113c04bb                 sethi   %hi(_AudioIn_dmaCount), %o0
F00DA030: 10800006                 ba      loc_F00DA048
F00DA034: d0022318                 ld      [%o0+%lo(_AudioIn_dmaCount)], %o0
F00DA038: 113c04bb                 sethi   %hi(_AudioOut_dmaSize), %o0
F00DA03C: d2022320                 ld      [%o0+%lo(_AudioOut_dmaSize)], %o1
F00DA040: 113c04bb                 sethi   %hi(_AudioOut_dmaCount), %o0
F00DA044: d0022324                 ld      [%o0+%lo(_AudioOut_dmaCount)], %o0
F00DA048: d2262038                 st      %o1, [%i0+0x38]
F00DA04C: d026203c                 st      %o0, [%i0+0x3C]
F00DA050: d206203c                 ld      [%i0+0x3C], %o1! SEL
F00DA054: d0062038                 ld      [%i0+0x38], %o0
F00DA058: 153c0505                 sethi   %hi(paSetdescriptors), %o2
F00DA05C: 7ffcb169                 call    _udiv
F00DA060: e002a0ac                 ld      [%o2+%lo(paSetdescriptors)], %l0
F00DA064: 94100008                 mov     %o0, %o2
F00DA068: 90100018                 mov     %i0, %o0! id
F00DA06C: 40005e01                 call    _objc_msgSend
F00DA070: 92100010                 mov     %l0, %o1
F00DA074: 81c7e008                 ret
F00DA078: 81e80000                 restore
