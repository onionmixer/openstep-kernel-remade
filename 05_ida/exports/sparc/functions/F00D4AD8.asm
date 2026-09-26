F00D4AD8: 9de3bf80                 save    %sp, -0x80, %sp
F00D4ADC: 9007bfe0                 add     %fp, var_20, %o0! void *
F00D4AE0: e007a05c                 ld      [%fp+arg_5C], %l0
F00D4AE4: e207a060                 ld      [%fp+arg_60], %l1
F00D4AE8: 7fff00dc                 call    _bzero
F00D4AEC: 9210200c                 mov     0xC, %o1
F00D4AF0: 932c2008                 sll     %l0, 8, %o1
F00D4AF4: 91346018                 srl     %l1, 24, %o0
F00D4AF8: 96124008                 or      %o1, %o0, %o3
F00D4AFC: 95342018                 srl     %l0, 24, %o2
F00D4B00: d0062110                 ld      [%i0+0x110], %o0! id
F00D4B04: 133c0504                 sethi   %hi(paLock), %o1
F00D4B08: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00D4B0C: 40007359                 call    _objc_msgSend
F00D4B10: a210000b                 mov     %o3, %l1
F00D4B14: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D4B18: 80a22000                 cmp     %o0, 0
F00D4B1C: 12800007                 bne     loc_F00D4B38
F00D4B20: a0103fff                 mov     -1, %l0
F00D4B24: d0062110                 ld      [%i0+0x110], %o0! id
F00D4B28: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D4B2C: 40007351                 call    _objc_msgSend
F00D4B30: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D4B34: 3080007c                 ba,a    locret_F00D4D24
F00D4B38: d4062168                 ld      [%i0+0x168], %o2
F00D4B3C: 113fe03f                 sethi   -0x7F0400, %o0
F00D4B40: d202a00c                 ld      [%o2+0xC], %o1
F00D4B44: 90122380                 bset    0x380, %o0
F00D4B48: 920a4008                 and     %o1, %o0, %o1
F00D4B4C: 11001fc09012207f         set     0x7F007F, %o0
F00D4B54: 900ec008                 and     %i3, %o0, %o0
F00D4B58: 92124008                 bset    %o0, %o1
F00D4B5C: d222a00c                 st      %o1, [%o2+0xC]
F00D4B60: d04e21d3                 ldsb    [%i0+0x1D3], %o0
F00D4B64: 80a22001                 cmp     %o0, 1
F00D4B68: 12800008                 bne     loc_F00D4B88
F00D4B6C: 80a6a00a                 cmp     %i2, 0xA
F00D4B70: 90100018                 mov     %i0, %o0! id
F00D4B74: 133c0505                 sethi   %hi(paForceautodimst), %o1
F00D4B78: d2026350                 ld      [%o1+%lo(paForceautodimst)], %o1! SEL
F00D4B7C: 4000733d                 call    _objc_msgSend
F00D4B80: 94102000                 mov     0, %o2
F00D4B84: 80a6a00a                 cmp     %i2, 0xA
F00D4B88: 3280005a                 bne,a   loc_F00D4CF0
F00D4B8C: d0062110                 ld      [%i0+0x110], %o0
F00D4B90: 80a76006                 cmp     %i5, 6! switch 7 cases
F00D4B94: 18800056                 bgu     def_F00D4BA8! jumptable F00D4BA8 default case, cases 4,5
F00D4B98: 113c0352                 sethi   %hi(jpt_F00D4BA8), %o0
F00D4B9C: 901223b0                 bset    %lo(jpt_F00D4BA8), %o0
F00D4BA0: 932f6002                 sll     %i5, 2, %o1
F00D4BA4: d0024008                 ld      [%o1+%o0], %o0
F00D4BA8: 81c20000                 jmp     %o0! switch jump
F00D4BAC: 01000000                 nop
F00D4BCC: 11000700                 sethi   0x1C0000, %o0! jumptable F00D4BA8 case 0
F00D4BD0: 808ec008                 btst    %o0, %i3
F00D4BD4: 1280000c                 bne     loc_F00D4C04
F00D4BD8: 113c0505                 sethi   %hi(paAudiovolume), %o0
F00D4BDC: d202227c                 ld      [%o0+%lo(paAudiovolume)], %o1! SEL
F00D4BE0: 113c0505                 sethi   %hi(paSetaudiovolume), %o0! id
F00D4BE4: e0022298                 ld      [%o0+%lo(paSetaudiovolume)], %l0
F00D4BE8: 40007322                 call    _objc_msgSend
F00D4BEC: 90100018                 mov     %i0, %o0
F00D4BF0: 94022001                 add     %o0, 1, %o2
F00D4BF4: 90100018                 mov     %i0, %o0! id
F00D4BF8: 4000731e                 call    _objc_msgSend
F00D4BFC: 92100010                 mov     %l0, %o1
F00D4C00: 113c0505                 sethi   -0xFEBEC00, %o0
F00D4C04: 1080002c                 ba      loc_F00D4CB4
F00D4C08: d202227c                 ld      [%o0+0x27C], %o1
F00D4C0C: 11000700                 sethi   0x1C0000, %o0! jumptable F00D4BA8 case 1
F00D4C10: 808ec008                 btst    %o0, %i3
F00D4C14: 1280000c                 bne     loc_F00D4C44
F00D4C18: 113c0505                 sethi   %hi(paAudiovolume), %o0
F00D4C1C: d202227c                 ld      [%o0+%lo(paAudiovolume)], %o1! SEL
F00D4C20: 113c0505                 sethi   %hi(paSetaudiovolume), %o0! id
F00D4C24: e0022298                 ld      [%o0+%lo(paSetaudiovolume)], %l0
F00D4C28: 40007312                 call    _objc_msgSend
F00D4C2C: 90100018                 mov     %i0, %o0
F00D4C30: 94023fff                 add     %o0, -1, %o2
F00D4C34: 90100018                 mov     %i0, %o0! id
F00D4C38: 4000730e                 call    _objc_msgSend
F00D4C3C: 92100010                 mov     %l0, %o1
F00D4C40: 113c0505                 sethi   -0xFEBEC00, %o0
F00D4C44: 1080001c                 ba      loc_F00D4CB4
F00D4C48: d202227c                 ld      [%o0+0x27C], %o1
F00D4C4C: 11000700                 sethi   0x1C0000, %o0! jumptable F00D4BA8 case 2
F00D4C50: 808ec008                 btst    %o0, %i3
F00D4C54: 12800017                 bne     loc_F00D4CB0
F00D4C58: 113c0505                 sethi   %hi(paBrightness), %o0
F00D4C5C: d202233c                 ld      [%o0+%lo(paBrightness)], %o1! SEL
F00D4C60: 113c0505                 sethi   %hi(paSetbrightness), %o0! id
F00D4C64: e0022328                 ld      [%o0+%lo(paSetbrightness)], %l0
F00D4C68: 40007302                 call    _objc_msgSend
F00D4C6C: 90100018                 mov     %i0, %o0
F00D4C70: 1080000c                 ba      loc_F00D4CA0
F00D4C74: 94022001                 add     %o0, 1, %o2
F00D4C78: 11000700                 sethi   0x1C0000, %o0! jumptable F00D4BA8 case 3
F00D4C7C: 808ec008                 btst    %o0, %i3
F00D4C80: 1280000c                 bne     loc_F00D4CB0
F00D4C84: 113c0505                 sethi   %hi(paBrightness), %o0
F00D4C88: d202233c                 ld      [%o0+%lo(paBrightness)], %o1! SEL
F00D4C8C: 113c0505                 sethi   %hi(paSetbrightness), %o0! id
F00D4C90: e0022328                 ld      [%o0+%lo(paSetbrightness)], %l0
F00D4C94: 400072f7                 call    _objc_msgSend
F00D4C98: 90100018                 mov     %i0, %o0
F00D4C9C: 94023fff                 add     %o0, -1, %o2
F00D4CA0: 90100018                 mov     %i0, %o0! id
F00D4CA4: 400072f3                 call    _objc_msgSend
F00D4CA8: 92100010                 mov     %l0, %o1
F00D4CAC: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D4CB0: d202233c                 ld      [%o0+0x33C], %o1! SEL
F00D4CB4: 400072ef                 call    _objc_msgSend
F00D4CB8: 90100018                 mov     %i0, %o0
F00D4CBC: 1080000c                 ba      def_F00D4BA8! jumptable F00D4BA8 default case, cases 4,5
F00D4CC0: a0100008                 mov     %o0, %l0
F00D4CC4: 90102001                 mov     1, %o0! jumptable F00D4BA8 case 6
F00D4CC8: d037bfe2                 sth     %o0, [%fp+var_1E]
F00D4CCC: 90100018                 mov     %i0, %o0! id
F00D4CD0: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D4CD4: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D4CD8: 9410200e                 mov     0xE, %o2
F00D4CDC: 960621a8                 add     %i0, 0x1A8, %o3
F00D4CE0: 98100011                 mov     %l1, %o4
F00D4CE4: 400072e3                 call    _objc_msgSend
F00D4CE8: 9a07bfe0                 add     %fp, var_20, %o5
F00D4CEC: d0062110                 ld      [%i0+0x110], %o0! jumptable F00D4BA8 default case, cases 4,5
F00D4CF0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D4CF4: 400072df                 call    _objc_msgSend
F00D4CF8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D4CFC: 80a43fff                 cmp     %l0, -1
F00D4D00: 02800009                 be      locret_F00D4D24
F00D4D04: 90100018                 mov     %i0, %o0! id
F00D4D08: 133c0505                 sethi   %hi(paEvspecialkeyms), %o1
F00D4D0C: d2026294                 ld      [%o1+%lo(paEvspecialkeyms)], %o1! SEL
F00D4D10: 9410001d                 mov     %i5, %o2
F00D4D14: 9610001a                 mov     %i2, %o3
F00D4D18: 9810001b                 mov     %i3, %o4
F00D4D1C: 400072d5                 call    _objc_msgSend
F00D4D20: 9a100010                 mov     %l0, %o5
F00D4D24: 81c7e008                 ret
F00D4D28: 81e80000                 restore
