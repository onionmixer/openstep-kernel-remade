F00CEB88: 9de3bf18                 save    %sp, -0xE8, %sp
F00CEB8C: 9410203c                 mov     0x3C, %o2 ! '<'
F00CEB90: 133c0504                 sethi   %hi(paAllocatebuffer), %o1
F00CEB94: a007bf90                 add     %fp, var_70, %l0
F00CEB98: a407bf94                 add     %fp, var_6C, %l2
F00CEB9C: d0062184                 ld      [%i0+0x184], %o0! id
F00CEBA0: 9607bf7c                 add     %fp, var_84, %o3
F00CEBA4: d2026184                 ld      [%o1+%lo(paAllocatebuffer)], %o1! SEL
F00CEBA8: 40008b32                 call    _objc_msgSend
F00CEBAC: 9807bf78                 add     %fp, var_88, %o4
F00CEBB0: a6100008                 mov     %o0, %l3
F00CEBB4: 90100010                 mov     %l0, %o0! void *
F00CEBB8: 7fff18a8                 call    _bzero
F00CEBBC: 92102060                 mov     0x60, %o1 ! '`'
F00CEBC0: d00e2188                 ldub    [%i0+0x188], %o0
F00CEBC4: d02fbf90                 stb     %o0, [%fp+var_70]
F00CEBC8: d40e2189                 ldub    [%i0+0x189], %o2
F00CEBCC: 113c0504                 sethi   %hi(paGetdmaalignmen), %o0
F00CEBD0: d2022180                 ld      [%o0+%lo(paGetdmaalignmen)], %o1! SEL
F00CEBD4: d42fbf91                 stb     %o2, [%fp+var_6F]
F00CEBD8: 90102001                 mov     1, %o0
F00CEBDC: d02fbfa0                 stb     %o0, [%fp+var_60]
F00CEBE0: d0062184                 ld      [%i0+0x184], %o0! id
F00CEBE4: 40008b23                 call    _objc_msgSend
F00CEBE8: 9407bf80                 add     %fp, var_80, %o2
F00CEBEC: d207bf88                 ld      [%fp+var_78], %o1
F00CEBF0: 80a26001                 cmp     %o1, 1
F00CEBF4: 08800005                 bleu    loc_F00CEC08
F00CEBF8: 9002603b                 add     %o1, 0x3B, %o0 ! ';'
F00CEBFC: 92200009                 neg     %o1
F00CEC00: 10800003                 ba      loc_F00CEC0C
F00CEC04: 900a0009                 and     %o0, %o1, %o0
F00CEC08: 9010203c                 mov     0x3C, %o0 ! '<'
F00CEC0C: d027bfa4                 st      %o0, [%fp+var_5C]
F00CEC10: 90102014                 mov     0x14, %o0
F00CEC14: d027bfa8                 st      %o0, [%fp+var_58]
F00CEC18: 90100018                 mov     %i0, %o0! id
F00CEC1C: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CEC20: 94102000                 mov     0, %o2
F00CEC24: d607bfac                 ld      [%fp+var_54], %o3
F00CEC28: 23200000                 sethi   0x80000000, %l1
F00CEC2C: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CEC30: 9612c011                 bset    %l1, %o3
F00CEC34: 40008b0f                 call    _objc_msgSend
F00CEC38: d627bfac                 st      %o3, [%fp+var_54]
F00CEC3C: a0100008                 mov     %o0, %l0
F00CEC40: 90102002                 mov     2, %o0
F00CEC44: d0240000                 st      %o0, [%l0]
F00CEC48: 9007bf90                 add     %fp, var_70, %o0
F00CEC4C: d0242014                 st      %o0, [%l0+0x14]
F00CEC50: 7fffed7c                 call    _IOVmTaskSelf
F00CEC54: e624200c                 st      %l3, [%l0+0xC]
F00CEC58: d0242010                 st      %o0, [%l0+0x10]
F00CEC5C: 9010201a                 mov     0x1A, %o0
F00CEC60: d02c8000                 stb     %o0, [%l2]
F00CEC64: 90100018                 mov     %i0, %o0! id
F00CEC68: 94100010                 mov     %l0, %o2! __n
F00CEC6C: d8048000                 ld      [%l2], %o4
F00CEC70: 17003800                 sethi   0xE00000, %o3
F00CEC74: d20a2189                 ldub    [%o0+0x189], %o1
F00CEC78: 962b000b                 andn    %o4, %o3, %o3
F00CEC7C: 920a6007                 and     %o1, 7, %o1
F00CEC80: 932a6015                 sll     %o1, 21, %o1
F00CEC84: 9612c009                 bset    %o1, %o3
F00CEC88: d6248000                 st      %o3, [%l2]
F00CEC8C: 9210203c                 mov     0x3C, %o1 ! '<'
F00CEC90: d22ca004                 stb     %o1, [%l2+4]
F00CEC94: d602a020                 ld      [%o2+0x20], %o3
F00CEC98: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CEC9C: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CECA0: 9612c011                 bset    %l1, %o3
F00CECA4: 40008af3                 call    _objc_msgSend
F00CECA8: d622a020                 st      %o3, [%o2+0x20]
F00CECAC: f007bfb0                 ld      [%fp+var_50], %i0
F00CECB0: 80a62000                 cmp     %i0, 0
F00CECB4: 12800008                 bne     loc_F00CECD4
F00CECB8: d007bf7c                 ld      [%fp+var_84], %o0
F00CECBC: 9010001a                 mov     %i2, %o0! __dst
F00CECC0: 92100013                 mov     %l3, %o1! __src
F00CECC4: 7ffce177                 call    _memcpy
F00CECC8: 9410203c                 mov     0x3C, %o2 ! '<'
F00CECCC: f007bfb0                 ld      [%fp+var_50], %i0
F00CECD0: d007bf7c                 ld      [%fp+var_84], %o0
F00CECD4: 7fffdc9c                 call    _IOFree
F00CECD8: d207bf78                 ld      [%fp+var_88], %o1
F00CECDC: 81c7e008                 ret
F00CECE0: 81e80000                 restore
