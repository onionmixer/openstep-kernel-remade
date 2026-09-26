F00E9CA0: 9de3bf90                 save    %sp, -0x70, %sp
F00E9CA4: 9010001b                 mov     %i3, %o0! __s1
F00E9CA8: 133c03f2                 sethi   %hi(aIoFramebufferU), %o1! "IO_Framebuffer_Unmap"
F00E9CAC: 7ffc7940                 call    _strcmp
F00E9CB0: 921263f8                 bset    %lo(aIoFramebufferU), %o1! "IO_Framebuffer_Unmap"
F00E9CB4: 80a22000                 cmp     %o0, 0
F00E9CB8: 12800008                 bne     loc_F00E9CD8
F00E9CBC: 9010001b                 mov     %i3, %o0
F00E9CC0: 113c0504                 sethi   %hi(paReverttovgamod), %o0! id
F00E9CC4: d202226c                 ld      [%o0+%lo(paReverttovgamod)], %o1! SEL
F00E9CC8: 40001eea                 call    _objc_msgSend
F00E9CCC: 90100018                 mov     %i0, %o0! __s1
F00E9CD0: 1080008f                 ba      locret_F00E9F0C
F00E9CD4: b0102000                 mov     0, %i0
F00E9CD8: 133c03f3                 sethi   %hi(aIoFramebufferU_0), %o1! "IO_Framebuffer_Unregister"
F00E9CDC: 7ffc7934                 call    _strcmp
F00E9CE0: 92126010                 bset    %lo(aIoFramebufferU_0), %o1! "IO_Framebuffer_Unregister"
F00E9CE4: 80a22000                 cmp     %o0, 0
F00E9CE8: 32800010                 bne,a   loc_F00E9D28
F00E9CEC: 9010001b                 mov     %i3, %o0
F00E9CF0: 80a72001                 cmp     %i4, 1
F00E9CF4: 12800086                 bne     locret_F00E9F0C
F00E9CF8: b0103d3e                 mov     -0x2C2, %i0
F00E9CFC: 113c0506                 sethi   %hi(paEventdriver_0), %o0
F00E9D00: d00222e0                 ld      [%o0+%lo(paEventdriver_0)], %o0! id
F00E9D04: 133c0505                 sethi   %hi(paInstance), %o1! SEL
F00E9D08: 40001eda                 call    _objc_msgSend
F00E9D0C: d2026278                 ld      [%o1+%lo(paInstance)], %o1
F00E9D10: 133c0504                 sethi   %hi(paUnregisterscre), %o1
F00E9D14: d20263b4                 ld      [%o1+%lo(paUnregisterscre)], %o1! SEL
F00E9D18: 40001ed6                 call    _objc_msgSend
F00E9D1C: d4068000                 ld      [%i2], %o2
F00E9D20: 1080007b                 ba      locret_F00E9F0C
F00E9D24: b0102000                 mov     0, %i0
F00E9D28: 133c03f3                 sethi   %hi(aIosettransfert), %o1! "IOSetTransferTable"
F00E9D2C: 7ffc7920                 call    _strcmp
F00E9D30: 92126030                 bset    %lo(aIosettransfert), %o1! "IOSetTransferTable"
F00E9D34: 80a22000                 cmp     %o0, 0
F00E9D38: 32800026                 bne,a   loc_F00E9DD0
F00E9D3C: 9010001b                 mov     %i3, %o0
F00E9D40: 113c0504                 sethi   %hi(paDisplayinfo), %o0! id
F00E9D44: d20223ac                 ld      [%o0+%lo(paDisplayinfo)], %o1! SEL
F00E9D48: 40001eca                 call    _objc_msgSend
F00E9D4C: 90100018                 mov     %i0, %o0
F00E9D50: d2022018                 ld      [%o0+0x18], %o1
F00E9D54: 80a26004                 cmp     %o1, 4! switch 5 cases
F00E9D58: 18800015                 bgu     def_F00E9D6C! jumptable F00E9D6C default case
F00E9D5C: 113c03a7                 sethi   %hi(jpt_F00E9D6C), %o0
F00E9D60: 90122174                 bset    %lo(jpt_F00E9D6C), %o0
F00E9D64: 932a6002                 sll     %o1, 2, %o1
F00E9D68: d0024008                 ld      [%o1+%o0], %o0
F00E9D6C: 81c20000                 jmp     %o0! switch jump
F00E9D70: 01000000                 nop
F00E9D88: 10800007                 ba      loc_F00E9DA4! jumptable F00E9D6C case 0
F00E9D8C: 80a72004                 cmp     %i4, 4
F00E9D90: 10800005                 ba      loc_F00E9DA4! jumptable F00E9D6C case 2
F00E9D94: 80a72010                 cmp     %i4, 0x10
F00E9D98: 10800003                 ba      loc_F00E9DA4! jumptable F00E9D6C case 3
F00E9D9C: 80a72020                 cmp     %i4, 0x20 ! ' '
F00E9DA0: 80a72100                 cmp     %i4, 0x100! jumptable F00E9D6C cases 1,4
F00E9DA4: 02800004                 be      loc_F00E9DB4
F00E9DA8: 90100018                 mov     %i0, %o0! id
F00E9DAC: 10800058                 ba      locret_F00E9F0C! jumptable F00E9D6C default case
F00E9DB0: b0103d3e                 mov     -0x2C2, %i0
F00E9DB4: 133c0504                 sethi   %hi(paSettransfertab), %o1
F00E9DB8: d202639c                 ld      [%o1+%lo(paSettransfertab)], %o1! SEL
F00E9DBC: 9410001a                 mov     %i2, %o2
F00E9DC0: 40001eac                 call    _objc_msgSend
F00E9DC4: 9610001c                 mov     %i4, %o3
F00E9DC8: 10800051                 ba      locret_F00E9F0C
F00E9DCC: b0102000                 mov     0, %i0
F00E9DD0: 133c03f3                 sethi   %hi(aIoBm256ToBm38M), %o1! "IO_BM256_to_BM38_map"
F00E9DD4: 7ffc78f6                 call    _strcmp
F00E9DD8: 92126048                 bset    %lo(aIoBm256ToBm38M), %o1! "IO_BM256_to_BM38_map"
F00E9DDC: 80a22000                 cmp     %o0, 0
F00E9DE0: 32800017                 bne,a   loc_F00E9E3C
F00E9DE4: 9010001b                 mov     %i3, %o0
F00E9DE8: 80a72100                 cmp     %i4, 0x100
F00E9DEC: 32800048                 bne,a   locret_F00E9F0C
F00E9DF0: b0103d3e                 mov     -0x2C2, %i0
F00E9DF4: d0062208                 ld      [%i0+0x208], %o0
F00E9DF8: 80a22000                 cmp     %o0, 0
F00E9DFC: 12800006                 bne     loc_F00E9E14
F00E9E00: 96102000                 mov     0, %o3
F00E9E04: 7fff704b                 call    _IOMalloc
F00E9E08: 90102400                 mov     0x400, %o0
F00E9E0C: d0262208                 st      %o0, [%i0+0x208]
F00E9E10: 96102000                 mov     0, %o3
F00E9E14: 94102000                 mov     0, %o2
F00E9E18: d2062208                 ld      [%i0+0x208], %o1
F00E9E1C: 9602e001                 inc     %o3
F00E9E20: d002801a                 ld      [%o2+%i2], %o0! __s1
F00E9E24: 80a2c01c                 cmp     %o3, %i4
F00E9E28: d022400a                 st      %o0, [%o1+%o2]
F00E9E2C: 0abffffb                 bcs     loc_F00E9E18
F00E9E30: 9402a004                 inc     4, %o2
F00E9E34: 10800036                 ba      locret_F00E9F0C
F00E9E38: b0102000                 mov     0, %i0
F00E9E3C: 133c03f3                 sethi   %hi(aIoBm38ToBm256M), %o1! "IO_BM38_to_BM256_map"
F00E9E40: 7ffc78db                 call    _strcmp
F00E9E44: 92126060                 bset    %lo(aIoBm38ToBm256M), %o1! "IO_BM38_to_BM256_map"
F00E9E48: 80a22000                 cmp     %o0, 0
F00E9E4C: 32800017                 bne,a   loc_F00E9EA8
F00E9E50: 9010001b                 mov     %i3, %o0
F00E9E54: 80a72100                 cmp     %i4, 0x100
F00E9E58: 3280002d                 bne,a   locret_F00E9F0C
F00E9E5C: b0103d3e                 mov     -0x2C2, %i0
F00E9E60: d006220c                 ld      [%i0+0x20C], %o0
F00E9E64: 80a22000                 cmp     %o0, 0
F00E9E68: 12800006                 bne     loc_F00E9E80
F00E9E6C: 96102000                 mov     0, %o3
F00E9E70: 7fff7030                 call    _IOMalloc
F00E9E74: 90102400                 mov     0x400, %o0
F00E9E78: d026220c                 st      %o0, [%i0+0x20C]
F00E9E7C: 96102000                 mov     0, %o3
F00E9E80: 94102000                 mov     0, %o2
F00E9E84: d206220c                 ld      [%i0+0x20C], %o1
F00E9E88: 9602e001                 inc     %o3
F00E9E8C: d002801a                 ld      [%o2+%i2], %o0! __s1
F00E9E90: 80a2c01c                 cmp     %o3, %i4
F00E9E94: d022400a                 st      %o0, [%o1+%o2]
F00E9E98: 0abffffb                 bcs     loc_F00E9E84
F00E9E9C: 9402a004                 inc     4, %o2
F00E9EA0: 1080001b                 ba      locret_F00E9F0C
F00E9EA4: b0102000                 mov     0, %i0
F00E9EA8: 133c03f3                 sethi   %hi(aSparcfbconfigu), %o1! "SPARCFBConfigure"
F00E9EAC: 7ffc78c0                 call    _strcmp
F00E9EB0: 92126078                 bset    %lo(aSparcfbconfigu), %o1! "SPARCFBConfigure"
F00E9EB4: 80a22000                 cmp     %o0, 0
F00E9EB8: 02bfff86                 be      loc_F00E9CD0
F00E9EBC: 9010001b                 mov     %i3, %o0! __s1
F00E9EC0: 133c03f3                 sethi   %hi(aIodisplaydobli), %o1! "IODisplayDoBlit"
F00E9EC4: 7ffc78ba                 call    _strcmp
F00E9EC8: 92126090                 bset    %lo(aIodisplaydobli), %o1! "IODisplayDoBlit"
F00E9ECC: 80a22000                 cmp     %o0, 0
F00E9ED0: 0280000e                 be      loc_F00E9F08
F00E9ED4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00E9ED8: f027bff0                 st      %i0, [%fp+var_10]
F00E9EDC: 9410001a                 mov     %i2, %o2
F00E9EE0: 133c0508                 sethi   %hi(stru_F014236C.super_class), %o1
F00E9EE4: d8026370                 ld      [%o1+%lo(stru_F014236C.super_class)], %o4
F00E9EE8: 9610001b                 mov     %i3, %o3
F00E9EEC: 133c0504                 sethi   %hi(paSetintvaluesFo_0), %o1
F00E9EF0: d827bff4                 st      %o4, [%fp+var_C]
F00E9EF4: d2026280                 ld      [%o1+%lo(paSetintvaluesFo_0)], %o1! SEL
F00E9EF8: 40001ea1                 call    _objc_msgSendSuper
F00E9EFC: 9810001c                 mov     %i4, %o4
F00E9F00: 10800003                 ba      locret_F00E9F0C
F00E9F04: b0100008                 mov     %o0, %i0
F00E9F08: b0103d42                 mov     -0x2BE, %i0
F00E9F0C: 81c7e008                 ret
F00E9F10: 81e80000                 restore
